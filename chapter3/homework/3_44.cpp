#include <stdio.h>

// 对下面每个结构声明确定每个字段的偏移量、 结构总的大小，以及在 x86-64 下它的对齐要求：

/*
	4 + 4 + 4 + 4 = 16
	4对齐
*/
struct  P1
{
	int i;
	char c;
	int j;
	char d;
};

/*
	4 + 1 + 3 + 8
	8对齐
*/
struct  P2
{
	int i;
	char c;
	char d;
	long j;
};

/*
	2 + 2 + 2 = 6
	1 + 1 + 1 = 3 补1
	总共10 , 2 对齐
*/
struct  P3
{
	short w[3];
	char c[3];
};

/*
	2 + 2 + 2 + 2 + 2 = 10
	8 + 8 + 8  = 24 补6
	总共40, 8对齐

*/
struct  P4
{
	short w[5];
	char* c[3];
};

/*
	1. 8 * 3 = 24
	2. 16

	总共40, 8对齐
*/
struct  P5
{
	struct P3 a[3]; // 数组内放的是指针
	struct P2 t;	// 对象放的是内存
};