#include <stdio.h>
/*
	地址		值
	0x100		0xFF
	0x108		0xAB
	0x110		0x13
	0x118		0x11

	寄存器		值
	%rax		0x100
	%rcx		0x1
	%rdx		0x3
*/
int demo() {
	// addq		%rcx,(%rax)
	// 0x100, 0xFF + 1 = 0x100

	// subq		%rdx, 8(%rax)
	// 0xAB - 0x3 = 0x108,	0xA8

	// imulq	$16, (%rax, %rdx, 8)
	// 0x100 + 0x3 * 8 = 0x118, 0x11 * 16 = 272 = 0x110

	// incq		16(%rax)
	// 0xFF + 16 + 1= 0x110,  -> 0x14

	// decq		%rcx
	// %rcx,	0

	// subq		%rdx, %rax
	// %rax, 0xFD
}