#include <stdio.h>

/*
	GCC 产生如下汇编代码:
		
	void switcher(long a, long b, long c, long* dest)
	a in %rdi, b in %rsi, c in %rdx, dest in %rcx

	switcher:
		cmpq	$7, %rdi
		ja		.L2
		jmp		*.L4(, %rdi, 8)
		.section	.rodata
	.L7:
		xorq	%15, %rsi
		movq	%rsi, %rdx
	.L3:
		leaq	112(%rdx), %rdi
		jmp		.L6
	.L5
		leaq	(%rdx, %rsi), %rdi
		salq	$2, %rdi
		jmp		.L6
	.L2
		movq	%rsi, %rdi
	.L6
		movq	%rdi, (%rcx)
		ret

	

	.L4
		.quad	.L3
		.quad	.L2
		.quad	.L5
		.quad	.L2
		.quad	.L6
		.quad	.L7
		.quad	.L2
		.quad	.L5
		
*/
void switcher(long a, long b, long c, long* dest) {
	long val;
	switch (a) {
	case 5:			// case A
		c = b ^ 15;
		// Fall through
	case 0:			// case B
		val = c + 112;
		break;
	case 2:			// case C
	case 7:			// case D
		val = (c + b) << 2;
		break;
	case 4:			// case E
		val = a;
		break;
	default:
		val = b;
	}
	*dest = val;
}