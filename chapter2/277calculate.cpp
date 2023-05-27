#include <stdio.h>

int main() {
	int x;
	// A  (17 = 16 + 1)
	(x << 4) + x;

	// B (-7 = 1 - 8)
	x - (x << 3);
	 
	// C (60 = 64 - 4)
	x << 6 - x << 2;

	// D (-112 = 16 - 128)
	x << 4 - x << 7;

	return 0;
}