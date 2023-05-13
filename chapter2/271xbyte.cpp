#include <stdio.h>

typedef unsigned packed_t;

// 1. 当取出的字节为负数时，由于原操作“粗暴”的将高位置零，会返回一个错误的正值。
// 2. 题目: 取出指定字节位的最高有效位, 注意算数右移带符号情况 ->
int xbyte(packed_t word, int bytenum) {
	int max_bytenum = 3;
	return (int)word << ((max_bytenum - bytenum) << 3) >> (max_bytenum << 3);
}