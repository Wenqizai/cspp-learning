#include <stdio.h>

/*
	GCC 产生如下汇编代码, 补充完成 C 表达式

	double funct3(int* ap, double b, long c, float* dp)
	ap in %rdi, b in %xmm0, c in %rsi, dp in %rdx

	funct3: 
		vmovss		(%rdx), %xmm1
		vcvtsi2sd	(%rdi), %xmm2, %xmm2
		vucomisd	%xmm2, %xmm0
		jbe			.L8
		vcvtsi2ssq	%rsi, %xmm0, %xmm0
		vmulss		%xmm1, %xmm0, %xmm1
		vunpcklps	%xmm1, %xmm1, %xmm1
		vcvtps2pd	%xmm1, %xmm0
		ret
	.L8
		vaddss		%xmm1, %xmm1, %xmm1
		vcvtsi2ssq	%rsi, %xmm0, %xmm0
		vaddss		%xmm1, %xmm0, %xmm0
		vunpcklps	%xmm0, %xmm0, %xmm0
		vctps2pd	%xmm0, %xmm0
		ret



*/
double funct3(int* ap, double b, long c, float* dp) {
	float d = (float)*dp; // %xmm1
	double a = (double) *ap; // %xmm2


	if (b <= a){
		return c + b * 2;
	}
	else {
		return b * c;
	}
}