#include <stdio.h>

int int_shifts_are_arithmetic(void);

int main() { printf("%d\n", int_shifts_are_arithmetic()); }

int int_shifts_are_arithmetic(void) {
  // int的所有位都为1
  int x = -1;
  // 1. 算术右移: (x >> 1 & (~x)) == 0
  // 2. 逻辑右移: (x >> 1 & (~x)) != 0
  // c语言默认使用算术右移, 没有指定算术右移或逻辑右移的表达式
  return (x >> 1 & (~x)) == 0;
}