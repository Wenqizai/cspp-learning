#include <stdio.h>
#include <string.h>

/*
	copy integer into buffer if space is available
	buggy method:
	sizeof 运算符返回的是 size_t 类型的值，它是一个无符号整数类型。
	当 maxbytes 的值很小且小于 sizeof(val) 时，maxbytes - sizeof(val) 的结果会被强制转换为无符号整数，导致结果仍然为正数。
*/
void buggy_copy_int(int val, void* buf, int maxbytes) {
	if (maxbytes - sizeof(val) >= 0)
		memcpy(buf, (void *) &val, sizeof(val));
}

/*
	right method: 比较大小, 避免上述问题
*/
void copy_int(int val, void* buf, int maxbytes) {
	if (maxbytes >= sizeof(val))
		memcpy(buf, (void *) &val, sizeof(val));
}