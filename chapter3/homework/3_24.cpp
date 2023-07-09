#include <stdio.h>

/*
	GCC -Og输出的汇编代码如下, 请补充完整C表达式: 

	long loop_while(long a, long b)
	a in %rdi, b in %rsi

	loop_while:
		movl	$1, %eax
		jmp		.L2
	.L3
		leaq	(%rdi, %rsi), %rdx
		imulq	%rdx, %rax
		addq	$1, %rdi
	.L2 
		cmpq	%rsi, %rdi
		jl		.L3
		rep; ret



*/
long loop_while(long a, long b) {
	long result = 1;
	while (a < b) {
		result = result * (a + b);
		a = a + 1;
	}
	return result;
}