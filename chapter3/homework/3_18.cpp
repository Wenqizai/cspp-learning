#include <stdio.h>

/*
	GCC产生如下的汇编代码, 请补充完整C表达式

	long test(long x, long y, long z)
	x in %rdi, y in %rsi, z in %rdx

	test:
		leaq	(%rdi,%rsi), %rax
		addq	%rdx, %rax
		cmpq	$-3, %rdi
		jge		.L2
		cmpq	%rdx, %rsi
		jge		.L3
		movq	%rdi, %rax
		imulq	%rsi, %rax
		ret
	.L3:
		movq	%rsi, %rax
		imulq	%rdx, %rax
		ret
	.L2
		cmpq	$2, %rdi
		jle		.L4
		movq	%rdi, %rax
		imulq	%rdx, %rax
	.L4
		rep; ret


*/
long test(long x, long y, long z) {
	long val = x + y + z;
	if (x < -3) {
		if (y >= z) {
			val = y * z;
		}
		else {
			val = x * y;
		}
	}
	else if (x > 2) {
		val = x * z;
	}
	return val;
}