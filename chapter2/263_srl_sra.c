#include <stdio.h>
/* 
	将下面的 C 函数代码补充完整。
    
    1. 函数 srl 用算术右移（由值 xsra 给出）来完成逻辑右移，后面的其他操作不包括右移或者除法。
    
    2. 函数 sra 用逻辑右移（由值 xsrl 给出）来完成算术右移，后面的其他操作不包括右移或者除法。
    
    可以通过计算 8*sizeof(int) 来确定数据类型int 中的位数 w 。位移量 k 的取值范围为 0 ~ w-1 。
*/


/*
 * 使用算术右移实现逻辑右移
 * k: 右移位数，k的取值范围为0~w-1，其中w为int类型的位数
 * xsra: 用于生成算术右移的值
 */
unsigned srl(unsigned x, int k) {
    /* 将x转换为无符号类型 */
    unsigned xsra = (int)x >> k;
    int w = sizeof(int) << 3;  /* 计算int类型的位数 */

    /* 构造掩码，掩码的前k位为0，其余位为1 */
    unsigned mask = ~(~0 << (w - k));

    /* 对xsra和掩码进行按位与运算，得到逻辑右移的结果 */
    return xsra & mask;
}

/*
 * 使用逻辑右移实现算术右移
 * k: 右移位数，k的取值范围为0~w-1，其中w为int类型的位数
 * xsrl: 用于生成逻辑右移的值
 */
int sra(int x, int k) {
    /* 将x转换为无符号类型 */
    unsigned xsrl = (unsigned)x >> k;
    int w = sizeof(int) << 3;  /* 计算int类型的位数 */

    /* 构造掩码，掩码的前k位为1，其余位为0 */
    int mask = (1 << (w - k)) - 1;

    /* 判断x的符号位是否为1 */
    int sign = (x & (1 << (w - 1))) != 0;

    /* 如果x为负数，则将掩码的前k位全部置为1 */
    if (sign) {
        mask <<= k;
    }

    /* 对xsrl和掩码进行按位与运算，得到算术右移的结果 */
    return xsrl | mask;
}

int main() {
    unsigned x = 0x12;
    int k = 4;
    unsigned y = srl(x, k);
    printf("srl(0x%X, %d) = 0x%X\n", x, k, y);

    int z = -0x12;
    int w = sra(z, k);
    printf("sra(0x%X, %d) = 0x%X\n", z, k, w);

    return 0;
}