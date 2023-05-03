#include <stdio.h>
#include <assert.h>

int lower_one_mask(int n) {
	//  n > 32 时 编译不通过, 考虑其他写法
	int x = 1 << n;
	int mask = ~(0xFFFFFFFF << n);
	return ~x & mask;
}

int main() {
	assert(lower_one_mask(6) == 0x3F);
	assert(lower_one_mask(17) == 0x1FFFF);
	//assert(lower_one_mask(32) == 0xFFFFFFFF);
	return 0;
}