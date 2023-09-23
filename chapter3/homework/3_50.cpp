#include <stdio.h>


/*
	函数生成的汇编代码如下:

	double fcvt2(int* ip, float* fp, double* dp, long l) 
	ip in %rdi, fp in %rsi, dp in %rdx, l in %rcx
	result returned in %xmm0

	fcvt2:
		movl		(%rdi), %eax
		vmovss		(%rsi), %xmm0
		vcvttsd2si	(%rdx), %r8d
		movl		%r8d, (%rdi)
		vcvtsi2sdq	%rcx, %xmm1, %xmm1
		vmovsd		%xmm1, (%rdx)
		vunpcklps	%xmm0, %xmm0, %xmm0
		vcvtps2pd	%xmm0, %xmm0
		ret

*/
double fcvt2(int* ip, float* fp, double* dp, long l) {
	int i = *ip;
	float f = *fp;
	double d = *dp;

	// *ip = (int)val1;
	*ip = (int) d;
	// *fp = (float)val2;
	*fp = (float) i;
	// *dp = (double)val3;
	*dp = (double) l;
	// return (double)val4;
	return (double) f;
}
