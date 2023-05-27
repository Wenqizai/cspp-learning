#include <stdio.h>

/*
	Divide by power of 2. Assume 0 <= k < w - 1
	x / (2 ^ k)
*/

int divide_power2(int x, int k) {
	return (x < 0 ? x + (1 << k) - 1 : x) >> k;
}