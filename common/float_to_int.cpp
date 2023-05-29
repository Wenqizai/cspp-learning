#include <stdio.h>
#include <limits.h>

/*
    float转为int:
    1. 用float的存储二进制
    2. 计算符号位sign, 指数位E, 小数位M
    3. 小数位M加上隐含的1, 如 M = 0110, 加上隐含1之后, M = 10110
    4. 判断指数位的值是否为 0 / 1, 用来判断非规格化值+0/-0, 无穷大, NaN等情况
    5. 小数M移动相应位数k得到转化后的int的值 (23为存储小数位的位数, 64为对应的为52)
        5.1 actualE >= 0 ,右移, k = (23 - (E - 127), result = M >> k
        5.2 actualE < 0 , 左移, k = (-(E - 127), result = M << k
*/
int floatToInt(float f) {
    // 将浮点数 f 的位表示转换为无符号整数
    unsigned int u = *((unsigned int*)&f);

    // 提取符号位
    int sign = (u >> 31) & 0x1;

    // 提取指数位
    int exponent = (u >> 23) & 0xFF;

    // 提取尾数位
    int mantissa = u & 0x7FFFFF;

    // 将浮点数按照 IEEE 754 标准进行分类讨论
    if (exponent == 0xFF) {
        // 特殊情况：NaN（不是一个数字）或无穷大
        return 0;  // 返回0或者其他合适的值，根据需求而定
    }
    else if (exponent == 0) {
        // 特殊情况：非规范化数或零
        return 0;  // 返回0或者其他合适的值，根据需求而定
    }
    else {
        // 规范化数
        // 将尾数位加上隐含的1，形成 1.x 的形式
        mantissa = mantissa | 0x800000;

        // 计算浮点数的指数偏移量（127）以获得实际指数
        int actualExponent = exponent - 127;

        // 判断实际指数的正负，并根据指数大小将尾数右移或左移
        if (actualExponent >= 0) {
            // 实际指数大于等于0，需要右移尾数位
            mantissa = mantissa >> (23 - actualExponent);
        }
        else {
            // 实际指数小于0，需要左移尾数位
            mantissa = mantissa << (-actualExponent);
        }

        // 判断浮点数的符号，并返回最终的整数值
        if (sign == 1) {
            // 负数
            return -mantissa;
        }
        else {
            // 非负数
            return mantissa;
        }
    }


}

int main() {
    // 测试用例1：正数
    float f1 = 3.14f;
    int result1 = floatToInt(f1);
    printf("Result 1: %d\n", result1);

    // 测试用例2：负数
    float f2 = -2.718f;
    int result2 = floatToInt(f2);
    printf("Result 2: %d\n", result2);

    // 测试用例3：非规范化数或零
    float f3 = 0.0f;
    int result3 = floatToInt(f3);
    printf("Result 3: %d\n", result3);

    // 测试用例4：NaN（不是一个数字）或无穷大
    float f4 =  0xff800000;  // 无穷大
    int result4 = floatToInt(f4);
    printf("Result 4: %d\n", result4);

    return 0;
}