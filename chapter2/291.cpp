#include <stdio.h>

/* Access bit-level representation floating-point number */
typedef unsigned float_bits;
/* If f is denorm, return 0. Otherwise, return f */
float_bits float_denorm_zero(float_bits f) {
	/* Decompose bit representaion into parts */
	unsigned sign = f >> 31;
	unsigned exp = f >> 23 & 0xFF;
	unsigned frac = f & 0x7FFFFF;
	if (exp == 0) {
		/* Denormalized. Set fraction to 0 */
		frac = 0;
		exp = 0;
	}
	/* Reassenble bits */
	return (sign << 31) | (exp << 23) | frac;
}


int main() {
	// A. 0x40490FDB
	// 0 10000000 10010010000111111011011


	// B. 22 / 7
	// 3.1428571428571428571428571428571
	// 11.001001001001001001001001001001001001001001001001001
	// 1.1001001001001001001001001001001001001001001001001001

	// A.100100100 00111111011011
	// B.100100100 10010010010010 

	// c. 9th
}