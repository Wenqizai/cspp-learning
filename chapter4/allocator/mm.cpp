#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include "memlib.cpp"
/*
	这是隐式空闲链表的实现, 同时采用立即边界标记合并方式, 块同时包含头部和脚步

	相关文档: https://gls.show/p/2c54864f/

*/

/* Basic constants and macros */
#define WSIZE 4	/* Word and header/footer size (bytes) */
#define DSIZE 8 /* Double word size (bytes) */
#define CHUNKSIZE (1 << 12) /* Extend heap by this amount (bytes) 初始空闲块的大小和扩展堆时默认大小 */

#define MAX(x, y)((x) > (y) ? (x) : (y))

/* Pack a size and allocated bit into a word */
#define PACK(size, alloc) ((size) | (alloc)) // 将大小和已分配位结合起来并返回一个值, 可以把他存放在头部或者脚部 

/* Read and write a word at address p */
#define GET(P) (*(unsigned int *) (p))	// 读取和返回参数p引用的字, 这里重要作用时强转类型,参数 p 是一个 (viod*)指针, 不可直接进行间接引用
#define PUT(p, val) (*(unsigned int *)(p) = (val))	// 将 val 存放在参数 p 执行的字中

/* Read the size and allocated fields from address p */
/* 从地址 p 处的头部或者脚部分别返回大小和已分配位, 头/脚步的信息: 块大小/已分配位 */
#define GET_SIZE(p) (GET(p) & ~0x7)	 
#define GET_ALLOC(p) (GET(p) & 0x1)

/* Given block ptr bp, compute address of its header and footer */
/* 给定块指针 bp, 返回指向这个块的头部和脚部的指针, 其中头部指针包含的块大小是包括头部, 有效载荷和所有的填充 */
#define HDRP(bp) ((char *)(bp) - WSIZE)	// 头部指针 =  块指针 - 头/脚部 size
#define FTRP(bp) ((char *)(bp) + GET_SIZE(HDRP(bp)) - DSIZE)	// 脚步指针 = 块指针 + 头部指针中保存的块大小 - 双字 

/* Given block ptr bp, compute address of next and previous blocks */
/* 给定块指针, 计算下一个和前一个块指针 */
#define NEXT_BLKP(bp) ((char *)(bp) + GET_SIZE((char*)(bp) - WSIZE))	// 下一块指针 = 块指针 + 头部指针中保存的块大小
#define PREV_BLKP(bp) ((char *)(bp) - GET_SIZE((char*)(bp) - DSIZE))	// 上一块指针 = 块指针 - (上一个块脚本指针保存的块大小)


int mm_init(void) {
	/* Create the initial empty heap */
	if ((heap_listp = mem_sbrk(4 * WSIZE)) == (void*)-1) {
		// 分配失败
		return -1;
	}
	PUT(heap_listp, 0);	/* Alignment padding */
	PUT(heap_listp + (1 * WSIZE), PACK(DSIZE, 1));	/* Prologue header 序言块 头部 8/1 */
	PUT(heap_listp + (2 * WSIZE), PACK(DSIZE, 1));	/* Prologue footer 序言块 脚部 8/1 */
	PUT(heap_listp + (3 * WSIZE), PACK(0, 1));  	/* Epilogue header 尾声块 头部 8/1 */
	heap_listp += (2 * WSIZE);

	/* Extend the empty heap with a free block of CHUNKSIZE bytes */
	if (extend_heap(CHUNKSIZE / WSIZE) == NULL) {
		return -1;
	}

	return 0;
}

static void* extend_heap(size_t words) {
	char* bp;
	size_t size;

	/* 
		为了8字节对齐，传入的words应该是2的整数倍，比如2,4,8 以满足8字节倍数的要求 
		Allocate an even number of words to maintain alignment 
	*/
	size = (words % 2) ? (words + 1) * WSIZE : words * WSIZE;
	
	// 调用mem_sbrk 申请size字节的内存，如果失败，返回NULL，bp是指向新申请的内存的底部的指针
	if ((long)(bp = mem_sbrk(size)) == -1) {
		return NULL;
	}

	/* Initialize free block header/footer and the epilogue header */
	/* 这里bp被当做指向块的指针，put宏将会覆盖尾声块*/
	/* 给新开辟的空间设置头部和脚部，并标记为未分配状态*/
	PUT(HDRP(bp), PACK(size, 0));         /* Free block header */
	PUT(FTRP(bp), PACK(size, 0));         /* Free block footer */


	/* 由于尾声块被覆盖，这里将尾声块放到新开辟空间的后面，作为结束标志*/
	PUT(HDRP(NEXT_BLKP(bp)), PACK(0, 1)); /* New epilogue header*/


	/* 这里分配了一个新的块，假设前一个块是未分配状态，那么前后两个块需要进行合并 */
	/* coalesce函数返回合并后的空闲块的指针*/
	return coalesce(bp);
}


/*
 * mm_free - Freeing a block does nothing.
 */
void mm_free(void* ptr){   
	/*获取ptr指向的块的大小*/
	size_t size = GET_SIZE(HDRP(ptr));

	/*将块的头脚部的标志位都改为0，也即标记为未分配*/
	PUT(HDRP(ptr), PACK(size, 0));
	PUT(FTRP(ptr), PACK(size, 0));

	/*free操作伴随着四种合并的可能*/
	coalesce(ptr);
}


/* 块的合并操作 */
static void* coalesce(void* ptr) {
	size_t prev_alloc = GET_ALLOC(FTRP(PREV_BLKP(ptr)));//获取前一个块的分配状态
	size_t next_alloc = GET_ALLOC(HDRP(NEXT_BLKP(ptr)));// 获取后一个块的分配状态
	size_t size = GET_SIZE(HDRP(ptr));//获取当前块的大小

	// 根据前后块的分配状态，进行四种合并操作
	// 1.前后块都已分配
	if (prev_alloc && next_alloc) {
		return ptr;
	}
	// 2.前块已分配，后块未分配
	else if (prev_alloc && !next_alloc) {
		size += GET_SIZE(HDRP(NEXT_BLKP(ptr)));// 当前块的大小+后块的大小
		PUT(HDRP(ptr), PACK(size, 0));
		PUT(FTRP(ptr), PACK(size, 0));
	}
	// 3.前块未分配，后块已分配
	else if (!prev_alloc && next_alloc) {
		size += GET_SIZE(HDRP(PREV_BLKP(ptr)));// 当前块的大小+前块的大小
		PUT(FTRP(ptr), PACK(size, 0));        // 合并当前块+前块，更新当前块的头部、脚部、分配状态
		PUT(HDRP(PREV_BLKP(ptr)), PACK(size, 0));
		ptr = PREV_BLKP(ptr);
	}
	// 4.前后块都未分配
	else {
		size += GET_SIZE(HDRP(PREV_BLKP(ptr))) + GET_SIZE(FTRP(NEXT_BLKP(ptr)));
		PUT(HDRP(PREV_BLKP(ptr)), PACK(size, 0));
		PUT(FTRP(NEXT_BLKP(ptr)), PACK(size, 0));
		ptr = PREV_BLKP(ptr);
	}
	return ptr;//返回合并后的块的指针
}

/*
 * mm_malloc - Allocate a block by incrementing the brk pointer.
 *     Always allocate a block whose size is a multiple of the alignment.
 */
void* mm_malloc(size_t size)
{
	size_t asize; /* Adjust block size */  // 调整后的块大小
	size_t extendsize; /* Amount to extend heap if no fit */  // 如果没有合适的块，则需要扩展堆的大小
	char* ptr;

	/* Ignore spurious requests */
	if (size == 0) {  // 如果请求的大小为0，则返回NULL
		return NULL;
	}

	/* Adjust block size to include overhead and alignment reqs. */
	// 块大小最少是 16 字节,并要求满足 8 字节对齐要求 
	if (size <= DSIZE) {  // 如果请求的大小小于等于DSIZE，则将块大小设置为2 * DSIZE
		asize = 2 * DSIZE;
	}
	else {  // 否则，将块大小设置为DSIZE的倍数，满足对齐要求
		asize = DSIZE * ((size + (DSIZE)+(DSIZE - 1)) / DSIZE);
	}

	/* Search the free list for a fit */
	if ((ptr = find_fit(asize)) != NULL) {  // 在空闲链表中查找合适大小的空闲块
		place(ptr, asize);  // 将空闲块分配给请求
		return ptr;  // 返回指向分配的空间的指针
	}

	/* No fit found. Get more memory and place the block */
	extendsize = MAX(asize, CHUNKSIZE);  // 如果没有找到合适大小的空闲块，则需要扩展堆的大小，扩展的大小为请求大小和一个默认的 CHUNKSIZE 中的较大值
	if ((ptr = extend_heap(extendsize / WSIZE)) == NULL) {  // 扩展堆的大小，并将新分配的空间划分为一个新的空闲块
		return NULL;  // 如果扩展失败，则返回NULL
	}
	place(ptr, asize);  // 将新分配的空间分配给请求
	return ptr;  // 返回指向分配的空间的指针
}

/*
	遍历堆空间, 找到一个大小合适的空闲块, 并返回指向该空间的指针, 如果找不到就返回 null
*/
static void* find_fit(size_t asize) {
	void* bp;

	/* 遍历空闲链表，寻找合适大小的空闲块 */
	for (bp = heap_listp; GET_SIZE(HDRP(bp)) > 0; bp = NEXT_BLKP(bp)) {
		/* 如果找到合适大小的空闲块，则返回指向该空闲块的指针 */
		if (!GET_ALLOC(HDRP(bp)) && (asize <= GET_SIZE(HDRP(bp)))) {
			return bp;
		}
	}

	return NULL; /* No fit */
}

/* 给定空闲块的指针和需要分配的堆空间的大小 */
static void place(void* bp, size_t asize){
	size_t csize = GET_SIZE(HDRP(bp));  // 获取空闲块的大小
	/* 如果空闲块的大小大于请求的大小，则将空闲块分割为两部分，一部分分配给请求，另一部分仍然是空闲块 */
	if ((csize - asize) >= (2 * DSIZE)) {
		/* 将空闲块分割为两部分，一部分分配给请求，另一部分仍然是空闲块 */
		PUT(HDRP(bp), PACK(asize, 1));  // 设置分配块的头部
		PUT(FTRP(bp), PACK(asize, 1));  // 设置分配块的脚部
		bp = NEXT_BLKP(bp);  // 将指针指向剩余的空闲块
		PUT(HDRP(bp), PACK(csize - asize, 0));  // 设置剩余空闲块的头部
		PUT(FTRP(bp), PACK(csize - asize, 0));  // 设置剩余空闲块的脚部
	}
	else {  // 否则，将整个空闲块分配给请求
		PUT(HDRP(bp), PACK(csize, 1));  // 设置分配块的头部
		PUT(FTRP(bp), PACK(csize, 1));  // 设置分配块的脚部
	}
}
