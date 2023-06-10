#include <stdio.h>

/* Access bit-level representation floating-point number */
typedef unsigned float_bits;

/* Compute 2 * f. if f is NaN, then return f. */
float_bits float_twice(float_bits f) {
	/* Decompose bit representaion into parts */
	unsigned sign = f >> 31;
	unsigned exp = f >> 23 & 0xFF;
	unsigned frac = f & 0x7FFFFF;
	if (exp = 0xff && frac != 0) {
		return f;
	}

	if (exp == 0) {
		// 非规则化值, E 还是0, 小数位放大了2倍
		frac <<= 1;
	}
	else if (exp + 1 == 0xFF) {
		// 溢出, 变成∞
		exp = 0xFF;
		frac = 0;
	}
	else {
		// 规则化值
		exp += 1;
	}
	/* Reassenble bits */
	return (sign << 31) | (exp << 23) | frac;
}