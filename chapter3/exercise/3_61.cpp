#include <stdio.h>

/*
	long cread(long* xp)
	xp in #rdi

	cread:
		movq	(%rdi), %rax
		testq	%rdi, %rdi
		movl	$0, %edx
		cmove	%rdx, %rax
		ret
*/
long cread(long* xp) {
	return (xp ? *xp : 0);
}

/*
	cread_alt:
		movl	$0, %eax
		testq	%rdi, %rdi
		cmove	(%rdi), %rax
		ret
*/
long cread_alt(long* xp) {
	return (!xp ? 0 : *xp);
}