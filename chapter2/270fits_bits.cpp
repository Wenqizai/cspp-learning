#include <stdio.h>
#include <assert.h>

//Return 1 when x can be represented as an n - bit, 2's-complement
//number; 0 otherwise
//Assume 1 <= n <= w
// 判断给定的整数 x 是否可以用 n 位的二进制表示，并且采用补码表示法。
int fits_bits(int x, int n) {
	int w = sizeof(int) << 3;
	return (x << (w - n) >> (w - n)) == x;
}

int main(int argc, char* argv[]) {
	assert(!fits_bits(0xFF, 8));
	assert(!fits_bits(~0xFF, 8));

	assert(fits_bits(0b0010, 3));
	assert(!fits_bits(0b1010, 3));
	assert(!fits_bits(0b0110, 3));

	assert(fits_bits(~0b11, 3));
	assert(!fits_bits(~0b01000011, 3));
	assert(!fits_bits(~0b111, 3));
	return 0;
}


