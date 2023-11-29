#include <complex.h>

/*
	编译时, GCC 为这些函数产生如下代码: 

	double c_imag(double complex x)
	c_imag:
		movapd		%xmm1, %xmm0
		ret

	double c_rel(double complex x)
	c_real:
		rep; ret

	double complex c_sub(double complex x, double complex y)
	c_sub:
		subsd	%xmm2, %xmm0
		subsd	%xmme3 %xmm1
		ret

	根据这些例子, 
	A. 如何向函数传递复数参数?
		参数位置		实数部分		虚数部分
		1				%xmm0			%xmm1
		2				%xmm2			%xmm3
		3				%xmm4			%xmm5

	B. 如何从函数返回复数值?
		%xmm0 存放复数的实数部分
		%xmm1 存放复数的虚数部分	

*/
double c_imag(double complex x) {
	return cimag(x);
}

double c_real(double complex x) {
	return creal(x);
}

double complex c_sub(double complex x, double complex y) {
	return x - y;
}