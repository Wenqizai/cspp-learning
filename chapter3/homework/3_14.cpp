#include <stdio.h>

typedef data_t;

int test(data_t a) {
	//return a TEST 0;
}

/*
	comp函数产生的汇编代码如下, 请确定data_t的数据类型和TEST类型: a & b

	A.
		testq	%rdi, %rdi
		setge	%al

		data_t的数据类型是 64bit  long
		TEST类型: 无符号

	B.
		testw	%di, %di
		sete	%al

		data_t的数据类型是 16bit  short, unsigned short
		TEST类型: 无符号, 有符号

	C.
		testb	%dil, %dil
		seta	%al

		data_t的数据类型是 8bit  unsigned char
		TEST类型: 无符号

	D. 
		testl	%edi, %edi
		setne	%al

		data_t的数据类型是 32bit  int, unsigned int 
		TEST类型: 无符号, 有符号

*/