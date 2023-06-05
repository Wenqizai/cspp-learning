#include <stdio.h>

int main() {
	/*
		结论: 假设int是32位

		1. 从 int 转换成 float, 数字不会溢出，但是可能被舍入。
		2. 从 int 或 float 转换成 double, 因为 double 有更大的范围（也就是可表示值的范围），
		   也有更高的精度（也就是有效位数），所以能够保留精确的数值。
		3. 从 double 转换成 float, 因为范围要小一些，所以值可能溢出成 +∞ 或 -∞。
		   另外，由于精确度较小，它还可能被舍入。
		4. 从 float 或者 double 转换成 int, 值将会向零舍入。例如, 1.999 将被转换成 1,而 -1.999 将被转换成 -1 。
		   进一步来说，值可能会溢出。 C 语言标准没有对这种情况指定固定的结果。
		   与 Intel 兼容的微处理器指定位模式 [10 ... 00] (字长为 w 时的TMinw) 为整数不确定 (integer indefinite) 值。 
		   一 个从浮点数到整数的转换，如果不能为该浮点数找到一个合理的整数近似值，就会产生这样一个值。
		   因此，表达式(int) +lelO 会得到 -21483648, 即从一个正值变成了一个负值。
	*/


	// A. (float) x == (float) dx
	// true


	// B. dx - dy == (double) (x - y)
	// false, 右边会正溢出, 如y = INT_MIN时

	// C. (dx + dy) + dz == dx + (dy + dz)
	// true
	
	// D. (dx * dy) * dz == dx * (dy * dz)
	// false

	// E. dx / dx == dz / dz
	// false, dx != 0 && dz == 0
}