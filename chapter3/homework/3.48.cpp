#include <stdio.h>
#include "string.h"

// 计算表示一个整数所需要的十进制数字的个数。
int len(char* s) {
	return strlen(s);
}

void iptoa(char* s, long* p) {
	long val = *p;
	sprintf(s, "%ld", val);
}

/*
	不带栈保护

	int intlen(long x)
	x in %rdi

	intlen: 
		subq	$40, %rsp
		movq	%rdi, 24(%rsp)
		leaq	24(%rsp), %rsi
		movq	%rsp, %rdi
		call	iptoa

	带栈保护

	int intlen(long x)
	x in %rdi

	intlen:
		subq	$56, %rsp
		movq	%fs:40, %rax
		movq	%rax, 40(%rsp)
		xorl	%eax, %eax
		movq	%rdi, 8(%rsp)
		leaq	8(%rsp), %rsi
		leaq	16(%rsp), %rdi
		call	iptoa

*/
int intlen(long x) {
	long v;
	char buf[12];
	v = x;
	iptoa(buf, &v);
	return len(buf);
}

/*
	A. 对于两个版本： buf 、 v 和金丝雀值（如果有的话）分别在栈帧中的什么位置？

	1. 不带栈保护

		buf: %rsp, v: 24(%rsp), 金丝雀: 无

	2. 带栈保护		

		buf: 16(%rsp) v: 8(%rsp), 金丝雀: 40(%rsp)


	B. 在有保护的代码中，对局部变量重新排列如何提供更好的安全性来对抗缓冲区越界攻击？

	当v的长度超过 buf 长度时, 金丝雀值会被破坏, 可以缓冲区溢出攻击被识别出来.
	与此同时 v 靠经栈顶不会被缓冲区溢出破坏.

*/