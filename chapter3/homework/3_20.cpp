#include <stdio.h>

long op(long x, int y) {
	/*
		A. OP 进行的是什么操作 ？
		B. 给代码添加注释，解释它是如何工作的。
	*/
	int z = x + 7;
	if (z >= 0) {
		return z = x;
	}
	return z >> 3;
}
/*
	编译时, GCC产生如下汇编代码

	long arith(long x)
	x in %rdi

	arith:
		leap	7(%rdi), %rax
		testq	%rdi, %rdi
		cmovns	%rdi, %rax
		sarq	%3, %rax
		ret
*/
long arith(long x) {
	return op(x, 8);
}