#include <stdio.h>

typedef enum {NEG, ZERO, POS, OTHER} range_t;

/*
	用汇编代码写出函数 find_range 行为的函数。
	你的代码必须只包含一个浮点比较指令，并用条件分支指令来生成正确的结果。
	在 2^32 种可能的参数值上测试你的代码。网络旁注 ASM:EASM 描述了如何在 C 程序中嵌入汇编代码。

	range_t find_range(float x)
	x in %xmm0

		vxorps		%xmm1, %xmm1, %xmm1
		vucomiss	%xmm1, %xmm0	# x comp 0
		jp			.P
		ja			.A
		jb			.B
		je			.E
	.A:
		movl		$2, %eax	# range_t 的下标, POS
		jmp			.Done
	.B:
		movl		$0, %eax	# range_t 的下标, NEG
		jmp			.Done
	.E:
		movl		$1, %eax	# range_t 的下标, ZEROS
		jmp			.Done
	.P:
		movl		$3, %eax	# range_t 的下标, OTHER
	.Done
		rep; ret


*/
range_t find_range(float x) {
	int result;
	if (x < 0) {
		result = NEG;
	}
	else if (x == 0) {
		result = ZERO;
	}
	else if (x > 0) {
		result = POS;
	}
	else {
		result = OTHER;
	}
	return (range_t) result;
}


