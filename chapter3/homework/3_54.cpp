#include <stdio.h>


/*
	GCC 生成如下汇编代码, 补充完整 c 代码

	double funct2(double w, int x, float y, long z)
	w in %xmm0, x in %edi, y in %xmm1, z in %rsi

	funct2: 
		vcvtsi2ss		%edi, %xmm2, %xmm2
		vmulss			%xmm1, %xmm2, %xmm1
		vunpcklps		%xmm1, %xmm1, %xmm1
		vcvtps2pd		%xmm1, %xmm2
		vcvtsi2sdq		%rsi, %xmm1, %xmm1
		vdivsd			%xmm1, %xmm0, %xmm0
		vsubsd			%xmmm0, %xmm2, %xmm0
		ret

*/
double funct2(double w, int x, float y, long z) {
	float mul =	(float)x * y;
	double div = w / (double) z;
	return div - mul;
}