#include <stdio.h>

/*
	GCC 产生的汇编代码如下
	long dw_loop(long x)
	x initially in %rdi

	dw_loop:
		movq	%rdi, %rax			// copy x to %rax
		movq	%rdi, %rcx			
		imulq	%rdi, %rcx			// compute y = x * x
		leaq	(%rdi,%rdi), %rdx	// compute n = 2 * x
	.L2								// loop
		leaq	1(%rcx,%rax), %rax	// compute x += y + 1
		subq	$1, %rdx			// decrement n
		testq	%rdx, %rdx			// test n
		jg		.L2					// if n > 0, goto loop
		rep; ret					// return

*/
long dw_loop(long x) {
	long y = x * x;
	long* p = &x;
	long n = 2 * x;
	do {
		x += y;
		(*p)++;
		n--;
	} while(n > 0);
	return x;
}

/*

	A. 哪些寄存器用来存放程序值 x 、y 和 n?
		
		x in %rax, y in %rcx, n in %rdx
	
	B. 编译器如何消除对指针变量 p 和表达式 (*p)++ 隐含的指针间接引用的需求？

	
	编译器认为指针 p 总是指向 X, 因此表达式 (*p) + + 就能够实现 x 加 一 。
	代码通过第 7 行的 leaq指令，把这个加 一 和加 y 组合起来。



	C. 对汇编代码添加一些注释，描述程序的操作，类似于图3-19c 中所示的那样。


*/