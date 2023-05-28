#include <stdio.h>

int arbitrary(int x, int y, unsigned ux, unsigned uy) {
	// A 
	// -> 
	// FALSE when x is min_int (eg: x 1000  -x 1000)
	// when y is 1001 (negative) and -y is 0111 (positive)
	(x < y) == (-x > -y);

	// B
	// ->
	// TRUE, ((x + y) << 4) + y - x = x << 4 - x + y << 4 + y
	// 我猜是编译器优化了公式
	((x + y) << 4) + y - x == 17 * y + 15 * x;

	// C
	// ->
	// FALSE
	// ~x + ~y + 1 = ~x + 1 + ~y + 1 - 1 = -x + -y - 1 
	// = - (x + y ) - 1 = ~ (x + y)

	~x + ~y + 1 == ~(x + y);
	
	// D
	// TRUE
	// 
	(ux - uy) == -(unsigned)(y - x);

	// E
	// -> 
	// TRUE
	// (ux - uy) == -(unsigned) (y - x)
	// =>
	// -(ux - uy) == (unsigned) (y - x)
	// =>
	// (ux - uy) == (unsigned) (x - y)
	((x >> 2) << 2) <= x;
 }