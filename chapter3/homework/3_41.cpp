#include <stdio.h>

/*
	A. 下面字段的偏移量是多少? 以字节为单位

	p: 8  
	s.x: 4
	s.y: 4
	next: 8


	B. 这个结构体需要多少字节?

	24 字节

*/
struct prob {
	int* p;
	struct {
		int x;
		int y;
	} s;
	struct prob *next;
};

/*
	汇编代码如下, 补充完成下面 C 表达式


	void sp_init(struct prob* sp)
	sp in %rdi

	sp_init:
		movl	12(%rdi), %eax
		movl	%eax, 8(%rdi)
		leaq	8(%rdi), %rax
		movq	%rax, (%rdi)
		movq	%rdi, 16(%rdi)
		ret

*/
void sp_init(struct prob* sp) {
	sp->s.x = sp->s.y;
	sp->p = &(sp->s.x);
	sp->next = sp;
}