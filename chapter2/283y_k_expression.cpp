#include <stdio.h>

int A(int n, int k, int Y) {
	/*
		n = 0.yyyyy... 左移 k 位 -> y.yyyyy... (无限串)
		其中 Y = y
	*/
	// n << k = Y + n;
	// n << k - n = Y
	// n * 2^k - n = Y
	// n * (2^k - 1) = Y
	// n = Y / (2^k - 1)
}

int B() {
	// a
	int Y = 5;
	int k = 3;
	int a = 5 / 7;
	// b 
	Y = 6;
	k = 4;
	int b = 6 / 15;

	// c
	Y = 19;
	k = 6;
	int c = 19 / 63;


	int n = Y / (2 ^ k - 1);
}