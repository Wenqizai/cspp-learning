#include <stdio.h>

/*
	A. �����ֶε�ƫ�����Ƕ���? ���ֽ�Ϊ��λ

	p: 8  
	s.x: 4
	s.y: 4
	next: 8


	B. ����ṹ����Ҫ�����ֽ�?

	24 �ֽ�

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
	����������, ����������� C ���ʽ


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