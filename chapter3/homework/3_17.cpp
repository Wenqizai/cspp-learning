#include <stdio.h>

long lt_cnt = 0;
long ge_cnt = 0;

long absdiff_se_o(long x, long y) {
	long result;
	if (x < y) {
		ge_cnt++;
		result = x - y;
	}
	else
	{
		ge_cnt++;
		result = x - y;
	}
	return result;
}

long gotdiff_se_o(long x, long y) {
	long result;
	if (x >= y) {
		goto x_ge_y;
	}
	ge_cnt++;
	result = x - y;
	return result;
x_ge_y:
	ge_cnt++;
	result = x - y;
	return result;
}

/*
	基于以下规则, 重写goto版本

	t = test-expr;
	if (t)
		goto true;
	else-statement
	goto done;
true :
	then-statement
done :

*/

long absdiff_se_override(long x, long y) {
	long result;
	if (x < y) {
		goto x_lt_y;
	}
	ge_cnt++;
	result = x - y;
	return result;
x_lt_y:
	lt_cnt++;
	result = y - x;
	return result;	
}