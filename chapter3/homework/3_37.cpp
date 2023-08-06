#include <stdio.h>

/*

	假设 short 类型的数组 S 的地址 xs 和整数索引 i 分别存放在存储器 %rdx 和 %rcx 中, 完善下列表格:


	表达式			|	类型	|		值		|			汇编代码
	S + 1				short*		xs + 2			leal	2(%rdx), %rax
	S[3]				short		M[xs + 6]		movw    6(%rdx), %ax
	&S[i]				short*		xs + 2i			leal	(%rdx, %rcx, 2), %rax
	S[4 * i + 1]		short		M[xs + 8i + 2]	movw	2(%rdx, %rcx, 8), %ax 
	S + i - 5			short*		xs + 2i - 10	leaw	-10(%rdx, %rcx, 2), %rax
	
**/