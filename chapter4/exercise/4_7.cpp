#include <stdio.h>

/*
	.text
	.global pushtest
	pushtest:
		movq	%rsp, %rax		-- copy stack pointer
		pushq	%rsp			-- push stack pointer
		popq	%rdx			-- pop it back
		subq	%rdx, %rax		-- return 0 or 8
		ret

	当函数 pushtest 总是返回 0, 表示 pushq %rsp 指令保存了 %rdx = %rsp 的值
	因此指令执行 subq %rdx, %rax 的返回值是 0.
*/
