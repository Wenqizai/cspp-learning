#include <stdio.h>

/*
	确定下列每个字节序列所编码的 Y86-64 指令序列. 如果序列中有不合法字节,
	指出指令序列中不合法值出现的位置.每个序列都先给出了起始位置, 冒号, 然后是字节序列.

	A. Ox100: 30f3fcffffffffffffff40630008000000000000
	B. Ox200: a06f800c020000000000000030f30a0000000000000090
	C. Ox300: 5054070000000000000010f0b01f
	D. Ox400: 611373000400000000000000
	E. Ox500: 6362a0f0


	A.  0x100: 30 f3 fc ff ff ff ff ff ff ff	|	irmovq	$-4, %rbx
		0x10a: 40 63 00 08 00 00 00 00 00 00	|	rmmovq	%rsi,0x800(%rbx)

	
	B. 0x200: a0 6f							|	pushq
	   0x202: 80 0c 02 00 00 00 00 00 00	|	call	proc
	   0x20b: 00							|	halt
	   0x20c:								| proc:
	   0x20c: 30 f3 0a 00 00 00 00 00 00 00	|	irmovq	$10, %rbx
	   0x216: 90							|	ret


	C. 0x300: 50 54 07 00 00 00 00 00 00 00	|	mrmovq	7(%rsp), %rbp
	   0x30a: 10							|	nop
	   0x30b: f0							|	不合法指令
	   0x30c: b0 1f							|	popq %rcx
	   

	D. 0x400:								| loop:
	   0x400: 61 13							|	subq  %rcx, %rbx
	   0x402: 73 00 04 00 00 00 00 00 00	|	je	  loop	
	   0x40c: 00							|	halt

	E. 0x500: 63 62							| xorq	%rsi, %rdx
	   0x502: a0 f0							| a0 不存在寄存器 f



*/