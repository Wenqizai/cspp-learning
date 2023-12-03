#include <stdio.h>

/*
	确定下面的 Y86-64 指令序列的字节编码


	.pos 0x100	# start code at address 0x100
		irmovq		$15, %rbx
		rrmovq		%rbx, %rcx

	.loop:
		rmmovq		%rcx, -3(%rbx)
		addq		%rbx, %rcx
		jmp			loop

							
	0x100		.pos					| .pos 0x100
	0x100		30f30f00000000000000	| irmovq		$15, %rbx
	0x10a		2031					| rrmovq		%rbx, %rcx
	0x10c								| .loop:
	0x10c		4013fdffffffffffffff	| %rcx, -3(%rbx)
	0x116		6231					| addq		%rbx, %rcx
	0x118		70c010000000000000		| jmp			loop






*/