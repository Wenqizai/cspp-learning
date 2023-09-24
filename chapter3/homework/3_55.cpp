#include <stdio.h>

/*
	生成汇编代码如下, 请解析 .LC3 代码含义

	double cel2fahr(double temp)
	temp in %xmm0

	cel2fahr: 
		vmulsd		.LC2(%rip), %xmm0, %xmm0	# Multiply by 1.8
		vaddsd		.LC3(%rip), %xmm0, %xmm0	# Add 32.0
	.LC2
		.long	3435973837 
		.long	1073532108
	.LC3
		.long	0
		.long	1077936128

	注: 小端存储

	.LC2 的解析
		.long : 代表有 32 位整数
		3435973837 : 16 进制表示形式 -> Oxcccccccd
		1073532108 : 16 进制表示形式 -> 0x3ffccccc

		符号位(1位): 0
		指数位(11位): 0x3ff -> 011 1111 1111 -> 1023
		小数位(23位): Oxccccccccccccd -> 1100 1100 1100 1100 1100 1100 1100 1100 1100 1100 1100 1100 1101 -> 计算十进制值:  0.1100 1100 1100 1100 1100 1100 1100 1100 1100 1100 1100 1100 1101  = 2^-1 + 2^-2 + 2^-5 + 2^-6 ... 约等于 0.7999 = 0.8
		指数非0, 规格值, 则为 1023 - 1023 = 0
		小数位(隐含1): 0.8 + 1 = 1.8

		最终值: 1.8 * 2 ^0 = 1.8


	.LC3 的解析
		.long : 代表有 32 位整数
		0 : 16 进制表示形式 -> 0
		1077936128 : 16 进制表示形式 -> 0x40400000 -> 0100 0000 0100 0000 0000 0000 0000 0000

		符号位(1位): 0
		指数位(11位): 100 0000 0100 -> 1028
		小数位(23位): 0 -> 0

		指数非0, 规格值, 则为 1028 - 1023 = 5
		小数位(隐含1): 0.0 + 1 = 1.0


		最终值: 1.0 * 2 ^ 5 = 32.0

*/
double cel2fahr(double temp) {
	return 1.8 * temp + 32.0;
}
