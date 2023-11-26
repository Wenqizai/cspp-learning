#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

/*
	long aframe(long n, long idx, long *q)
	n in %rdi,	idx in %rsi, q in %rdx

	aframe: 
		pushq	%rbp
		movq	%rsp, %rbp
		subq	%16, %rsp 	# allocate space for i (%rsp = s1)
		leaq	30(, $rdi, 8), %rax
		andq	%-16, %rax
		subq	%rax, %rsp	# allocate space for array p (%rsp = s2)
		leaq	15(%rsp), %r8
		andq	$-16, %r8	# set %r8 to &p[0]

	注: x &  0xffffff0 代表向下取整 16


	A. 用数学语言解析计算 s2 的逻辑.
	
		s2 = s1 - (8n + 30) & 0xffffff0

		1. 当 n = 奇数时, (8n + 30) & 0xffffff0 = 8n + 24, 因为奇数所以多出了 8, 
		而 8n + 30 = 8 * (n - 1) + 38, 38 向下取整 16 为 32, 即 8n + 24

		2. 当 n = 偶数时, (8n + 30) & 0xffffff0 = 8n + 16

	B. 用数学语言解析结算 p 的逻辑.

		p = (s2 + 15) & 0xfffffff0

	C. 确定使 e1 的值最少和最大的 n 和 s1 的值.

		不懂...

	D. 这段代码为 s2 和 p 的值保证了怎样的对齐属性?
		
		也不懂...

	
*/
long aframe(long n, long idx, long* q) {
	long i;
	long** p = (long**)_malloca(n * sizeof(long*));
	p[0] = &i;
	for (i = 1; i < n; i++) {
		p[i] = q;
	}
	return *p[idx];
}


