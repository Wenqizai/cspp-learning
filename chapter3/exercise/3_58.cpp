#include <stdio.h>

/*
	GCC 产生如下汇编代码, 补充完整 c 代码:

	long decode2(long x, long y, long z)
	x in %rdi, y in %rsi, z in %rdx

	decode2:
		subq	%rdx, %rsi
		imulq	%rsi, %rdi
		movq	%rsi, %rax
		salq	$63, %rax
		sarq	$63, %rax
		xorq	%rdi, %rax
		ret


*/
long decode2(long x, long y, long z) {
	long a = y - z;
	long b = x * a;
	a << 63 >> 63;
	return a | b;
}