#include <stdio.h>

typedef arg1_t;
typedef arg2_t;
typedef arg3_t;
typedef arg4_t;

/*
	GCC 编译时产生如下代码:

	double funct1(arg1_t p, arg2_t q, arg3_t r, arg4_t s)
	funct1:
		vcvtsi2ssq		%rsi, %xmm2, %xmm2
		vaddss			%xmm0, %xmm2, %xmm0
		vcvtsi2ss		%edi, %xmm2, %xmm2
		vdivss			%xmm0, %xmm2, %xmm0
		vunpcklps		%xmm0, %xmm0, %xmm0
		vcvtps2pd		%xmm0, %xmm0
		vsubsd			%xmm1, %xmm0, %xmm0
		ret

	确定 arg1_t, arg2_t, arg3_t, arg4_t 的参数类型
*/


// p in %edi int,q in %rsi long, r in %xmm0 float, s in %xmm1 double, 
double funct1(arg1_t p, arg2_t q, arg3_t r, arg4_t s) {
	return p / (q + r) - s;
}