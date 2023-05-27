#include <stdio.h>

int expression(int j, int k) {
	// A
	int x = -1 << k;

	// B
	int y = ~(-1 << k) << j;
}