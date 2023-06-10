#include <stdio.h>

/* Access bit-level representation floating-point number */
typedef unsigned float_bits;

/* Compute -f. if f is NaN, then return f. */
float_bits float_denorm_negate(float_bits f) {
	/* Decompose bit representaion into parts */
	unsigned sign = f >> 31;
	unsigned exp = f >> 23 & 0xFF;
	unsigned frac = f & 0x7FFFFF;
	if (exp == 0xff && frac != 0) {
		return f;
	}
	/* Reassenble bits */
	return (sign << 31) | (exp << 23) | frac;
}