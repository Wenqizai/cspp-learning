#include <stdio.h>

typedef unsigned char *byte_pointer;
/**
 * 1. 先找到要移动的位数:  i << 3
 * 2. 替换的数字要移动的位数: ((unsigned)b) << (i << 3)
 * 3. 用掩码对替换数字的地方置0: (x & (~mask))
 * 4. 置0后的数字与替换的数字做与运行
 */
unsigned replace_byte(unsigned x, int i, unsigned char b)
{
    size_t mask = ((unsigned)0xff) << (i << 3);
    return (x & (~mask)) | (((unsigned)b) << (i << 3));
}

int main()
{
    // printf("%x \n", replace_byte(0x12345678, 0, 0xab));
    printf("%x \n", replace_byte(0x12345678, 2, 0xab));
}