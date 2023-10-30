#include <stdio.h>

#define A 9
#define B 5

/*
	GCC 为 setVal 产生如下代码:

	void setVal(str1 *p, str2 *q)
	p in %rdi, q in %rsi

	setVal:
		movslq	8(%rsi), %rax
		addq	32(%rsi), %rax

		movq	%rax, 184(%rdi)
		ret


	A,B 的值是多少? 答案唯一


	q -> t : array[B] 占用8位, 考虑空白对齐, 4 < B * 1 <= 8
	q -> u : array[B]  + t + short s[A] = 32, 24 < 12 + A * 2 <= 32 = 6 < 6 <= 10

	p -> y :  x[A][B] 占用 184 位 (8 位对齐), 176  < A * B * 4 <= 184, 44 < A * B <= 46


	A 9 , B 5




*/
typedef struct {
	int x[A][B]; /* Unknown constants A AND B */
	long y;
} str1;

typedef struct {
	char array[B];
	int t;
	short s[A];
	long u;
} str2;


void setVal(str1* p, str2* q) {
	long v1 = q->t;
	long v2 = q->u;
	p->y = v1 + v2;
}
