#include <stdio.h>

/*
	x in %xmm0

	A.  
		vmovsd	.LC1(%rip), %xmm1
		vandpd	%xmm1, %xmm0, %xmm0
	.LC1:
		.long	4294967295		# 0xFFFF FFFF
		.long	2147483647		# 0x7FFF FFFF
		.long	0
		.long	0
	
	B.
		vxorpd	%xmm0, %xmm0, %xmm0

	C.
		vmovsd	.LC2(%rip), %xmm0
		vxorpd	%xmm1, %xmm0, %xmm0
	.LC2:
		.long	0
		.long	-2147483647	 #  0x8000 0000
		.long	0
		.long	0

*/
double simplefun(double x) {
	// return EXPR(x);

	// A. (1.999 * 2^1024) & x -> 清除 x 的符号位, 相当于得到 x 的绝对值, abs(x)

	// B. return x | x; ->  置0, 相当于设置 %xmm0 为 0.0

	// C. return -∞ | x; -> 改变 x 的符号位, 相当于 -x
}