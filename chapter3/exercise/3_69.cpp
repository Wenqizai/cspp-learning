#include <stdio.h>




/*
	void test(long i, b_struct* bp)
	i in %rdi, bp in %rsi

	0000000000000000 <test>:
		0:	8b 8e 20 01 00 00		mov		Ox120(%rsi), %ecx
		6:	03 Oe					add		(%rsi),%ecx
		8:	48 8d 04 bf				lea		(%rdi,%rdi,4),%rax
		c:	48 8d 04 c6				lea		(%rsi,%rax,8),%rax
		10: 48 8b 50 O8				mov		Ox8(%rax),%rdx
		14:	48 63 c9				movslq	%ecx,%rcx
		17: 48 89 4c dO 10			mov		%rcx, 0x10(%rax, %rdx,8)
		le: c3						retq


		0x120 = 288

	A. 运用逆向技术, 求 CNT 的值
		7

	B. 结构 a_struct 的完整声明, 假设这个结构中只有字段 idx 和 x, 
	   并且这两个字段保存的都是有符号值.

*/

#define CNT 

typedef struct {
	long idx;
	long x[4];
} a_struct;

typedef struct {
	int first;
	a_struct a[CNT];
	int last;
} b_struct;



void test(long i, b_struct* bp) {
	int n = bp->first + bp->last;
	a_struct* ap = &bp->a[i];
	ap->x[ap->idx] = n;
}