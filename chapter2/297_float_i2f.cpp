#include <stdio.h>
#include <math.h>
#include <limits.h>

/* Access bit-level representation floating-point number */
typedef unsigned float_bits;

/*
 * Assume i > 0
 * calculate i's bit length
 *
 * e.g.
 * 0x3 => 2
 * 0xFF => 8
 * 0x80 => 8
 */
int bits_length(int i) {
	if ((i & INT_MIN) != 0) {
		return 32;
	}
	unsigned u = (unsigned)i; // 防止负数算数右移
	int count = 0;
	while (u != 0)
	{
		u >>= 1;
		count++;
	}
	return count;
}

/*
 * generate mask
 * 00000...(32-l) 11111....(l)
 *
 * e.g.
 * 3  => 0x00000007
 * 16 => 0x0000FFFF
 */
unsigned bits_mask(int l) {
	return (unsigned)-1 >> (32 - l);
}

/*
	Compute (float) i
	If conversion causes overflow or f is NaN, return 0x80000000
*/
float_bits float_i2f(int i) {
	/* Decompose bit representaion into parts */
	unsigned sign, exp_sig /* except sig */, round_part;
	unsigned bias = 0x7F;
	unsigned bits, fbits;

	unsigned exp;
	unsigned frac;
	unsigned rest;

	if (i == 0) {
		return 0;
	}

	if (i == INT_MIN) {
		sign = 1;
		exp = bias + 31;
		frac = 0;
		return sign << 31 | exp << 23 | frac;
	}

	sign = 0;
	/* 2's complatation */
	if (i < 0) {
		sign = 1;
		i = -i;
	}

	rest = i & bits_mask(fbits);
	if (fbits <= 23) {
		// 小数位少于23位直接移位
		frac = rest << (23 - fbits);
		exp_sig = exp << 23 | frac;
	}
	else {
		// 小数位大于23位, 需要考虑舍入问题
		// 不懂
		int offset = fbits - 23;
		int round_mid = 1 << (offset - 1);

		round_part = rest & bits_mask(offset);
		frac = rest >> offset;
		exp_sig = exp << 23 | frac;

		/* round to even */
		if (round_part < round_mid) {
			/* nothing */
		}
		else if (round_part > round_mid) {
			exp_sig += 1;
		}
		else {
			/* round_part == round_mid */
			if ((frac & 0x1) == 1) {
				/* round to even */
				exp_sig += 1;
			}
		}
	}

	return sign << 31 | exp_sig;
}