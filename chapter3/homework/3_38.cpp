#include <stdio.h>

/*
	GCC产生如下汇编代码, 请确定 M 和 N的值

	long sum_element(long i, long j)
	i in %rdi, j in %rsi

	sum_element:
		leaq	0(, %rdi, 8), %rdx
		subq	%rdi, %rdx
		addq	%rsi, %rdx
		leaq	(%rsi, %rsi, 4), %rax
		addq	%rax, %rdi
		movq	Q(, %rdi, 8), %rax
		addq	P(, %rdx, 8), %rax
		ret
*/



//long P[M][N]; 
//long Q[N][M];

// M = 5, N = 7

long P[5][7];
long Q[7][5];


long sum_element(long i, long j) {
	return P[i][j] + Q[j][i];
}
