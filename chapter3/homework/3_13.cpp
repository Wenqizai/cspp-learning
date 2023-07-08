#include <stdio.h>

typedef data_t;

int comp(data_t a, data_t b) {
	// return a COMP b;
}

/*
	comp函数产生的汇编代码如下, 请确定data_t的数据类型和比较的类型: a - b
	其中: a in %rdi		b in %rsi

	A. 
		compl	%esi, %edi
		setl	%al

		data_t的数据类型是 32bit  int
		比较类型是有符号比较 a < b

	B.
		compw	%si, %di
		setge	%al

		data_t的数据类型是 16bit  short
		比较类型是有符号比较 a >= b

	C.
		comb	%sil, %dil
		setbe	%al

		data_t的数据类型是 8bit  unsigned char
		比较类型是无符号比较 a <= b

	D. 
		comq	%rsi, %rdi
		setne	%a

		data_t的数据类型是 64bit  long, unsigned long
		比较类型是有符号/无符号比较 a != b

*/