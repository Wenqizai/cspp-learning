#include <stdio.h>

/* Access bit-level representation floating-point number */
typedef unsigned float_bits;

/* Compute 0.5 * f. if f is NaN, then return f. */
float_bits float_half(float_bits f) {
	/* Decompose bit representaion into parts */
	unsigned sign = f >> 31;
	unsigned exp = f >> 23 & 0xFF;
	unsigned frac = f & 0x7FFFFF;
	unsigned rest = f & 0x7FFFFFFF; // 除符号位外的其他位
	if (exp == 0xff && frac != 0) {
		return f;
	}
	// 需要考虑四舍五入问题,即 round to even, 规则如下:
	/*
	 * Round to even: check last 2 bits of frac
	 *
	 * 00 => 0 (just >> 1) 
	 * 01 => 0 (round to even, just >> 1)
	 * 10 => 1 (just >> 1)
	 * 11 => 1 + 1 (round to even, just >> 1 and plus 1) 进1
	 */

	int addition = (frac & 0x3) == 0x3;

	if (exp == 0) {
		/* Denormalized */
		frac >>= 1;
		frac += addition;
	}
	else if (exp - 1 == 0) {
		/* Normalized to denormalized */
		// 规格化值转非规格化值, 需要位数移位, 与规格化大有不同
		rest >>= 1;
		rest += addition;
		exp = rest >> 23;
		frac = rest & 0x7FFFFF;
	}
	else {
		/* Normalized */
		exp -= 1;                       // Decrease the exponent by 1
	}
	
	/* Reassenble bits */
	return (sign << 31) | (exp << 23) | frac;
}