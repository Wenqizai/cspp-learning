#include <stdio.h>

/*
	GCC 编译时产生如下汇编代码:

	void switch2(long x, long* dest)
	x in %rdi

	switch2:
		addq	$1, %rdi
		cmpq	$8, %rdi
		ja		.L2
		jmp		*.L4(, %rdi, 8)


	.L4
		.quad	.L9
		.quad	.L5
		.quad	.L6
		.quad	.L7
		.quad	.L2
		.quad	.L7
		.quad	.L8
		.quad	.L2
		.quad	.L5


	A. switch语句内情况标号的值分别是多少?

	-1, 0, 1, 2, 4, 5, 7
		

	B. C代码中那些情况有多个标号?
		缺省3和6, 因为其下标均跳转到 .L2

*/
void switch2(long x, long* dest) {
	long val = 0;
	switch (x)
	{
		// 补充完整body
	default:
		break;
	}
	*dest = val;
}