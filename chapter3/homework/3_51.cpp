#include <stdio.h>

typedef dest_t;
typedef src_t;

/*
	x in %xmm0, %rdi, %edi
	返回值 in %xmm0, %rax

	完成以下的类型转换

	Tx		Ty			指令
	long	double		vcvtsi2sdq	%rdi, %xmm0

	double	int			vcvttsd2si	%xmm0,%eax

	double	float		vmovddup	%xmm0,%xmm0
						vcvtpd2psx	%xmm0,%xmm0

	long	float		vcvtsi2ssq	%rdi, %xmm0

	float	long		vcvttss2siq	%xmm0, %rax

*/
dest_t cvt(src_t x) {
	dest_t y = (dest_t)x;
	return y;
}