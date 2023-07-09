#include <stdio.h>

/*
	GCC 产生的汇编代码如下:

	A. 确定这段代码使用的循环翻译方法。
	B. 根据汇编代码版本填写 C 代码中缺失的部分。
	C. 用自然语言描述这个函数是计算什么的。


	long fun_a(unsigned long x)
	x in %rdi

	fun_a:
		movl	$0, %eax
		jmp		.L5
	.L6
		xorq	%rdi, %rax
		shrq	%rdi			shift right by 1
	.L5
		testq	%rdi, %rdi
		jne		.L6
		andl	$1, %eax
		ret	

*/
long fun_a(unsigned long x) {
	long val = 0;
	// 计算x的奇偶性, x中有奇数个1则返回1, 有偶数个1则返回0
	while (x != 0) {
		val = val ^ x;
		x = x >> 1;
	}
	return val & 0x1;
}