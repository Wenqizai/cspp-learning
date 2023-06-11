#include <stdio.h>
#include <math.h>

/* Access bit-level representation floating-point number */
typedef unsigned float_bits;

/*
	Compute (int) f
	If conversion causes overflow or f is NaN, return 0x80000000
*/
int float_f2i(float_bits f) {
	/* Decompose bit representaion into parts */
	unsigned sign = f >> 31;
	unsigned exp = f >> 23 & 0xFF;
	unsigned frac = f & 0x7FFFFF;
	unsigned bias = 0x7F;

	int num;

	/*
	 * consider positive numbers
	 *
	 * 0 00000000 00000000000000000000000
	 *   ===>
	 * 0 01111111 00000000000000000000000
	 *   0 <= f < 1
	 * get integer 0
	 *
	 * 0 01111111 00000000000000000000000
	 *   ===>
	 * 0 (01111111+31) 00000000000000000000000
	 *   1 <= f < 2^31
	 * integer round to 0
	 *
	 * 0 (01111111+31) 00000000000000000000000
	 *   ===>
	 * greater
	 *   2^31 <= f < oo
	 * return 0x80000000
	 */
	if (exp >= 0 && exp <= 0 + bias) {
		/* number less than 1 */
		num = 0;
	}
	else if (exp >= 31 + bias) { // int 最多32位数, 其中符号位占1位
		/* number overflow */
		/* or f < 0 and (int) f == INT_MIN */
		return 0x80000000;
	}
	else {
		unsigned E = exp - bias;
		unsigned M = frac | 0x8000000; // 位数frac+1位
		if (E <= 23) {
			// 获取整数部分, 小数位舍去
			 /* whether sig is 1 or 0, round to zero */
			num = frac >> (23 - E);
		}
		else {
			// M最多可以左移位数是 23 + 23 位, 左移高于23位, 相当于舍去 E - 23位
			num = M << (E - 23);
		}
	}

	return sign ? -num : num;
}