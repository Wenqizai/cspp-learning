#include <stdio.h>

/*
	先把fact_for转换成while循环, 再进行 guarded_do 变换fact_for的 goto 代码
*/
long fact_for(long n) {
	long i;
	long result = 1;
	for (i = 2; i <= n; i++) {
		result *= i;
	}
	return result;
}

long fact_for_while(long n) {
	long i = 2;
	long result = 1;
	while (i <= n)
	{
		result *= i;
		i++;
	}
	return result;
}

long fact_for_while_goto(long n) {
	long i = 2;
	long result = 1;
	if (n <= 1) {
		goto done;
	}

loop:
	result *= i;
	i++;
	if (i <= n) {
		goto loop;
	}
done:
	return result;
}