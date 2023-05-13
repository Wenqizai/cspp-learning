#include <stdio.h>

/*
 * Do rotating left shift Assume O <= n < w
 * Examples when x = Ox12345678 and w = 32:
 * n=4 -> Ox23456781, n=20 -> Ox67812345
 */
unsigned rotate_left(unsigned x, int n) {
	if (n == 0) {
		return x;
	}
	unsigned w = sizeof(unsigned) << 3;
	unsigned l = x << n;
	unsigned r = x >> (w - n);
	return l | r;
}

int main() {
	int a = 0x12345678;
	printf("%d", rotate_left(a, 4));
	return 0;
}