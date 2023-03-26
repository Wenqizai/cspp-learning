#include <stdio.h>

// 利用位运算和掩码结合字节

int main()
{
    size_t x = 0x89ABCDEF;
    size_t y = 0x76543210;
    size_t num = 0xFF;

    size_t result = (x & num | (y & ~num));
    printf("%#x \n", result);
    return 1;
}
