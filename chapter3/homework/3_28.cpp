#include <stdio.h>

/*
	GCC产生如下汇编代码, 请补充完整C表达式

	long fun_b(unsigned long x)
	x in %rdi

	fun_b:
		movl	$64, %edx
		movl	$0, %eax
	.L10:
		movq	%rdi, %rcx
		andl	$1, %ecx
		addq	%rax, %rax
		orq		%rcx, %rax
		shrq	%rdi		// shift right by 1
		subq	$1, %rdx
		jne		.L10
		rep; ret


		A. 根据汇编代码版本填写 C 代码中缺失的部分。

		B. 解释循环前为什么没有初始测试也没有初始跳转到循环内部的测试部分。

		   这段代码是用 guarded-do 变换生成的，但是编译器发现因为 i 初始化成了64, 所以一定会满足测试i != 0, 因此初始的测试是没必要的。

		C. 用自然语言描述这个函数是计算什么的。

		   这段代码把 x 中的位反过来，创造一个镜像。实现的方法是：将 x 的位从左往右移，然后再填入这些位，就像是把 val 从右往左移
。
*/
long fun_b(unsigned long x) {
	long val = 0;
	long i;
	for (i = 64; i != 0; i--) {
		x = x & 0x1;
		val << 1;
		val = val | x;
		x >>= 1;		
	}
	return val;
}