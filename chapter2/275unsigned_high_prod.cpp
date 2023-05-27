#include <stdio.h>
#include <inttypes.h>

int signed_high_prod(int x, int y) {
	int64_t mul = (int64_t)x * y;
	return mul >> 32;
}

// 用64位保存, 防止被截断
unsigned unsigned_high_prod_01(unsigned x, unsigned y) {
	int64_t mul = (int64_t)x * y;
	return mul >> 32;
}

unsigned unsigned_high_prod_02(unsigned x, unsigned y) {
	int x_sign = x >> 31;
	int y_sign = y >> 31;
	// 无符号的高位 = 有符号截取的高位 + 负数的乘数大小
	int signed_prod = signed_high_prod(x, y);
	return signed_prod + x * y_sign + y * x_sign;
}