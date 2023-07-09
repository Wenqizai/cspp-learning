#include <stdio.h>

/*
	Example of for loop containing a continue statement 
	sum even numbers between 0 and 9
*/
void test_for() {
	long sum = 0;
	long i;
	for (i = 0; i < 10; i++) {
		if (i & 1) {
			continue;
		}
		sum += i;
	}
}

/*
	A. 如果我们简单地直接应用将 for 循环翻译到 while 循环的规则，会得到什么呢？产生的代码会有什么错误呢？

	B. 如何用 goto 语句来替代 continue 语句，保证 while 循环的行为同 for 循环的行为完全一样？
*/

void test_while() {
	long i = 0;
	long sum = 0;
	while (i < 10) {
		if (i & 1)
		{	
			i++; // 这里需要加上, 否则进入死循环
			continue;
		}
		sum += i;
		i++;
	}
}

void test_while_goto() {
	long i = 0;
	long sum = 0;
	while (i < 10) {
		if (i & 1) {
			goto update_i;
		}
		sum += i;
	update_i:
		i++;
	}
}