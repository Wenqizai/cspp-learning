#include <stdio.h>

// x / (2 ^ k)
int divide_power2(int x, int k) {
	return (x < 0 ? x + (1 << k) - 1 : x) >> k;
}

// 3x / 4
int mul3div4(int x) {
	if (x < 0) {
		return 3 * x >> 2 + 3 >> 2;
	}
	return 3 * (x >> 2);
}


int mul3div4_2(int x) {
	int mul3 = x << 1 + x;
	return divide_power2(mul3, 2);
}