#include <stdio.h>

/*
	GCC -O1产生的汇编代码, 请补充完整下面的C表达式:

	long loop_while2(long a, long b)
	a in %rdi, b in %rsi

	loop_while2:
		testq	%rsi, %rsi
		jle		.L8
		movq	%rsi, %rax
	.L7:
		imulq	%rdi, %rax
		subq	%rdi, %rsi
		testq	%rsi, %rsi
		jg		.L7
		rep; ret
	.L8:
		movq %rsi, %rax
		ret

*/
long loop_while2(long a, long b) {
	long result = b;
	while (b > 0) {
		result = result * a;
		b = b - a;
	}
	return result;
}