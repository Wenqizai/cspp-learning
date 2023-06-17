#include <stdio.h>

/*
	xp in %rdi, yp in %rsi, zp in %rdx

	汇编信息如下, 请写出对应的c代码: 
	
	decode:
		movq (%rdi), %r8
		movq (%rsi), %rcx
		movq (%rdx), %rax
		movq %r8, (%rsi)
		movq %rcx, (%rdx)
		movq %rax, (%rdi)
		ret
*/
void decode(long *xp, long *yp, long *zp) {
	long x = *xp;
	long y = *yp;
	long z = *zp;

	*xp = z;
	*yp = x;
	*zp = y;
}