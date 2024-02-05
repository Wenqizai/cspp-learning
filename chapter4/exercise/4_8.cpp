#include <stdio.h>

/*
	.text
	.global poptest
	poptest:
		movq	%rsp, %rdi		-- save stack pointer
		pushq	$0xabcd			-- push test value
		popq	%rsp			-- pop to stack pointer
		movq	%rsp, %rax		-- set popped value as return value
		movq	%rdi, %rsp		-- restore stack pointer
		ret

	函数总是返回 0xabcd,表示 pushq %rsp 的行为是怎样的?

	从栈帧上 pop 一个值 0xabcd 赋值给 %rsp, 等价于 mrmovq (%rsp), %rsp.



*/