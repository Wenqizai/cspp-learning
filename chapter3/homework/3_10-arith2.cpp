#include <stdio.h>

/*
	汇编代码如下, 请补充完整c语言表达式

	long artith2(long x, long y, long z)
	x in %rdi, y in %rsi, y in %rdx

	arith2:
		orq	%rsi,%rdi
		sarq	$3,%rdi
		notq	%rdi
		movq	%rdx,%rax
		subq	%rdi,%rax
		ret

*/
long artith2(long x, long y, long z) {
	long t1 = y | x;
	long t2 = t1 >> 3;
	long t3 = ~t2;
	long t4 = z - t3;
	return t4;
}