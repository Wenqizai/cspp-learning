#include <stdio.h>

typedef union {
	struct
	{
		long u;
		short v;
		char w;
	} t1;

	struct
	{
		int a[2];
		char* p;
	} t2;
} u_type;

void get(u_type* up, type* dest) {
	*dest = expr;
}


// 假设 up 和 dest 分别被加载到寄存器 %rdi 和 %rsi 中

expr				type				代码
up->t1.u			long			movq	(%rdi), %rax
									movq	%rax, (%rsi)

up->t1.v			short			movw	8(%rdi), %ax
									movw	%ax, (%rsi)


&up->t1.w			char*			addq	$12, %rdi
									movq	%rdi, (%rsi)


up->t2.a			int*			movq	%rdi, %eax

up->t2.a[up -> t1.u] int			movq	(%rdi), %rax
									movl	(%rdi, %rax, 4), %eax
									movl	%eax, (%rsi)



*up->t2.p			char			movq	8(%rdi), %rax
									movb	(%rax), %al
									movb	%al, (%rsi)








