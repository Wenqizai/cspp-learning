#include <stdio.h>

/*

	写出信号 xor 的 HCL 表达式, xor 就是异或, 输入为 a 与 b. 信号 xor 和上面定义的 eq 有什么关系呢?

	其中: bool eq = (a && b) || (!a && !b)


	bool xor = (a || b) && (!a || !b)

	另一种解法: bool xor = (!a && b) || (a && !b)


	通常, 信号 eq 和 xor 是互补的, 也就是一个等于 1, 另一个就等于 0. 










*/
int test() {

}