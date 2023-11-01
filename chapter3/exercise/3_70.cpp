#include <stdio.h>

/*
	A.下列字段的偏移量是多少? 以字节为单位
		e1.p	0
		e1.y	8
		e2.x	0
		e2.next 8

	B. 这个结构总共需要多少字节?
		
		16
	C. 编译器为 proc 产生下面的汇编代码:

		void proc(union ele* up)
		up in %rdi
		proc:
			movq	8(%rdi), %rax
			movq	(%rax), %rdx
			movq	(%rdx), %rdx
			subq	8(%rax), %rdx
			movq	%rdx, (%rdi)
			ret

		补充 proc 缺失部分代码.



*/
union ele {
	struct {
		long* p;
		long y;
	} e1;

	struct {
		long x;
		union ele* next;
	} e2;
};

void proc(union ele* up) {
	up->e2.x = *(up->e2.next)->e1.p - up->e2.next->e1.y;
}