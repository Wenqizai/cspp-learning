#include <stdio.h>

/*
	该函数产生的汇编代码如下:

	void cond(long a, long *p)
	a in %rdi, p in %rsi

	cond: 
		testq	%rsi, %rsi
		je		.L1
		cmpq	%rdi, (%rsi)
		jge		.L1
		movq	%rdi, (%rsi)
	.L1:
		rep; ret	
	
*/
void cond(long a, long* p) {
	if (p && a > *p) {
		*p = a;
	}
}


/*
	上面函数goto版本
*/
void goto_cond(long a, long* p) {
	if (p == 0) {
		goto done;
	}

	if (*p >= a) {
		goto done;
	}

	*p = a;
done:
	return;
}