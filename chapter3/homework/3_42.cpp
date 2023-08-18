#include <stdio.h>

struct ELE {
	long v;
	struct ELE* p;
};

/*
	当编译 fun 代码时, GCC 产生如下汇编代码:

	
	long fun(struct ELE* ptr)
	ptr in %rdi
	fun:
		movl	$0, %eax
		jmp		.L2
	.L3
		addq	(%rdi), %rax
		movq	8(%rdi), %rdi
	.L2
		testq	%rdi, %rdi
		jne		.L3
		rep; ret

*/
long fun(struct ELE* ptr) {
	int result = 0;
	while (ptr) {
		result += ptr->v;
		ptr = ptr->p;
	}
	return result;
}