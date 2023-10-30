#include <stdio.h>

/*
	GCC 产生如下代码: 


	strB process(strA s)
	process: 
		movq	%rdi, %rax
		movq	24(%rsp), %rdx
		movq	(%rdx), %rdx
		movq	16(%rsp), %rcx
		movq	%rcx, (%rdi)
		movq	8(%rsp), %rcx
		movq	%rcx, 8(%rdi)
		movq	%rdx, 16(%rdi)
		ret

	long eval(long x, long y, long z)
	x in %rdi, y in %rsi, z in %rdx
	eval:
		subq	$104, %rsp
		movq	%rdx, 24(%rsp)
		leaq	24(%rsp), %rax
		movq	%rdi, (%rsp)
		movq	%rsi, 8(%rsp)
		movq	%rax, 16(%rsp)
		leaq	64(%rsp), %rdi
		call	process

		movq	72(%rsp), %rax
		addq	64(%rsp), %rax
		addq	80(%rsp), %rax
		addq	$104, %rsp
		ret


	A. 从 eval 函数的第 2 行我们可以看到，它在栈上分配了104 个字节。画出eval 的栈帧，
	给出它在调用 process 前存储在栈上的值。


	| ------ | ---- |
	|        | 104  |
	| s.p    | 80   |
	| s.a[1] | 72   |
	| s.a[0] | 64   | <-- %rdi
	|        | 32   |
	| z	     | 24   |
	| &z     | 16   |
	| y      | 8    |
	| x      | 0    |
	| ------ | ---- | <-- %rsp
	
	B. eval 调用 process 时传递了什么值？

		%rdi, 即 s.a[0]的地址, %rsp + 64
	
	C. process 的代码是如何访问结构参数 s 的元素的？
		
		通过访问 %rdi 的偏移量


	D. process 的代码是如何设置结果结构 r 的字段的？

		| ------ | ---- |
		| r.u[0] | 16   |
		| r.u[1] | 8    |
		| r.1    | 0    |
		| ------ | ---- | %rsp

	E. 完成 eval 的栈帧图，给出在从 process 返回后 eval 是如何访问结构 r 的元素的。

		通过 %rsp + 64,  %rsp + 72,  %rsp + 80

	F. 就如何传递作为函数参数的结构以及如何返回作为函数结果的结构值，你可以看出什么通用的原则？

		传递地址, 通过地址偏移量访问, 访问函数之前需要先保存参数到栈帧上


*/

typedef struct {
	long a[2];
	long* p;
} strA;

typedef struct {
	long u[2];
	long q;
} strB;

strB process(strA s) {
	strB r;
	r.u[0] = s.a[1];
	r.u[1] = s.a[0];
	r.q = *s.p;
	return r;
}

long eval(long x, long y, long z) {
	strA s;
	s.a[0] = x;
	s.a[1] = y;
	s.p = &z;
	strB r = process(s);
	return r.u[0] + r.u[1] + r.q;
}

