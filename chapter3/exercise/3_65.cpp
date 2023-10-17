#include <stdio.h>


#define M 10

/*
	优化等级 -o1 编译, GCC 产生如下内循环代码:

	.L6:
		movq	(%rdx), %rcx
		movq	(%rax), %rsi
		movq	%rsi, (%rdx)
		movq	%rcx, (%rax)
		addq	$8, %rdx
		addq	$120, %rax
		compq	%rdi, %rax
		jne		.L6

		我们可以看到 GCC 把数组索引转换成了指针代码


	A. 哪个寄存器保存着指向数组A[i][j]的指针代码? 
		%rdx

	B. 哪个寄存器保存着指向数组A[j][i]的指针代码? 
		%rax

	C. M 值是多少?
	   15

*/
void transpose(long A[M][M]) {
	long i, j;
	for (i = 0; i < M; i++) {
		for (j = 0; j < i; j++) {
			long t = A[i][j];
			A[i][j] = A[j][i];
			A[j][i] = t;
		}
	}
}