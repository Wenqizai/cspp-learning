#include <stdio.h>

/*
	移位量可以是一个立即数，或者放在单字节寄存器 %cl 中。
	(这些指令很特别，因为只允许以这个特定的寄存器作为操作数。)
*/
long shift_left4_rightn(long x, long n) {
	x <<= 4;
	// 要记住只有最低位的那个字节才指示着移位量
	x >>= n;
	return x;
}
/*
	补充完整汇编代码: 

	long shift_left4_rightn(long x, long n)
	x in %rdi, n in %rsi

	shift_left4_rightn:
		movq	%rdi, %rax		get x
		salq	$4,	%rax		x <<= 4
		movl	%esi, %ecx		get n (4 bytes)
		sarq	%cl, %rax		x >>= n
*/