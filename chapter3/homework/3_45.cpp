#include <stdio.h>

struct {
	char* a;
	short b;
	double c;
	char d;
	float e;
	char f;
	long g;
	int h;
} rec;

/*
	A. 这个结构中所有字段的字节偏移量是多少?

		8 + 2 + 8 + 1 + 4 + 1 + 8 + 4 = 36

	B. 这个结构总的大小是多少?

		8 + 8 + 8 + 4 + 4 + 4 + 8 + 4 = 48

	C. 重新排列这个结构中的字段, 以最少化浪费的空间, 然后给出重排过的结构的字节偏移量和总的大小.

		8 + 8 + 8 + 8 + 4 + 4 + 2 + 1

*/

struct {
	char* a;
	double c;
	float e;
	long g;
	int h;
	short b;
	char d;
	char f;
} rec2;