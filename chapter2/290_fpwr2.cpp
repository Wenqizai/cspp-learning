#include <stdio.h>
#include <limits.h>
#include <math.h>


float u2f(unsigned x) {
	return *(float*)&x;
}

float fpwr2(int x) {
	/* Result exponent and fraction */
	unsigned exp, frac;
	unsigned u;

	if (x < 2 - pow(2, 7) - 23) {
		/* Too small. Return 0.0 */
		exp = 0;
		frac = 0;
	}
	else if (x < 2 - pow(2, 7) ){
		/* Denormalized result 非规格化值 */
		exp = 0;
		frac = 1 << (unsigned)(x - (2 - pow(2, 7) - 23));
	}
	else if (x < pow(2, 7) - 1 + 1) {
		/* Nomalized result */ 
		exp = pow(2, 7) - 1 + x;
		frac = 0;
	}
	else {
		/* too big, return +∞ */
		exp = 0xff;
		frac = 0;
	}
	
	/* Pack exp and frac into 32 bits */
	u = exp << 23 | frac;
	/* return as frac */
	return *(float*) &u;
}