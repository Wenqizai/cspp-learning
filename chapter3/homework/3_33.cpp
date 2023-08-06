#include <stdio.h>

/*
	procprob 函数:
		*u += a;
		*v += b;
		return sizeof(a) + sizeof(b);

	编译后如下

	procprob:
		movslq	%edi, %rdi;
		addq	%rdi, (%rdx);
		addb	%sil, (%rcx);
		movl	$6, %eax
		ret

*/

// a in %edi,  u in  %rdx, v in %rcx, b in %sil
int procprob(int a, short b, long* u, char* v) {

}