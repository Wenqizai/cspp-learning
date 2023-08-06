#include <stdio.h>

/*
	long P(long x)
	x in %rdi

	P: 
		pushq	%r15
		pushq	%r14
		pushq	%r13
		pushq	%r12
		pushq	%rbp
		pushq	%rbx
		subq	$24, %rsp
		movq	%rdi, %rbx
		leaq	1(%rdi), %r15
		leaq	2(%rdi), %r14
		leaq	3(%rdi), %r13
		leaq	4(%rdi), %r12
		leaq	5(%rdi), %rbp
		leaq	6(%rdi), %rax
		movq	%rax, (%rsp)
		leaq	7(%rdi), %rdx
		movq	%rdx, 8(%rsp)
		movl	$0, %eax
		call	Q


	A. 确定哪些局部值存储在被调用者保存寄存器中

	x + 1, x + 2, x + 3, x + 4, x + 5
	%r15, %r14, %r13, %r12, %rbp

	B. 确定哪些局部变量存储在栈上

	x + 6, x + 7
	(%rsp), 8(%rsp)

	C. 解析为什么不能把所有的局部值都存储在被调用者保存寄存器中

	当调用 Q 时, 需要将寄存器 %rax 和 %rdx 上的值存储起来, 避免被 Q 函数改写


*/


// 该函数P生成名为 a0 ~ a7 的局部变量, 然后调用函数Q
long P(long x) {

}