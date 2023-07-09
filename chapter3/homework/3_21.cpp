#include <stdio.h>

/*
	GCC产生如下汇编代码, 补充完整C表达式

	long test(long x, long y)
	x in %rdi, y in %rsi

	test:
		leaq	0(,%rdi,8), %rax
		testq	%rsi, %rsi
		jle		.L2
		movq	%rsi, %rax
		subq	%rdi, %rax
		movq	%rdi, %rdx
		andq	%rsi, %rdx
		cmpq	%rsi, %rdi
		comvge	%rdx, %rax
		ret
	.L2:
		andq	%rsi, %rdi
		cmpq	$-2, %rsi
		cmovle	%rdi, %rax
		ret

*/
long test(long x, long y) {
	long val = x * 8;
	if (y > 0) {
		if (x < y) {
			val = y - x;
		}
		else {
			val = x & y;
		}
	}
	else if (y <= -2) {
		val = x + y;
	}
	return val;
}