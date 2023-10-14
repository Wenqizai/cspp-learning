#include <stdio.h>

/*
	long loop(long x, int n)
	x in %rdi, n in %esi

	loop:
		movl	%esi, %ecx
		movl	$1, %edx
		movl	$0, %eax
		jmp		.L2
	.L3:
		movq	%rdi, %r8
		andq	%rdx, %r8
		orq		%r8, %rax
		salq	%cl, %rdx
	.L2:
		testq	%rdx, %rdx
		jne		.L3
		rep;ret

	A. 哪个寄存器保存着程序值x, n, result 和 mask?
		x in %rdi	n in %esi	result in %rax		mask in %rdx

	B. result 和 mask 的初始值是什么?
		result = 0; mask = 1

	C. mask 的测试条件是什么?
		mask != 0;

	D. mask 是如何被修改的?
		mask << n;

	E. result 是如何被修改的?
		result |= (x & mask);

	F. 填写这段 C 代码中所有确实的部分
*/
long loop(long x, int n) {
	long result = 0;
	long mask;
	for (mask = 1; mask != 0; mask << n) {
		result |= (x & mask);
	}
	return result;
}
