#include <stdio.h>

// 3/4x
int threefourths(int x) {
	int k = 2;
	int bias = (1 << k) - 1;
	int div = (x < 0 ? x + bias : x) >> k;
	return x << 1 + x;
}