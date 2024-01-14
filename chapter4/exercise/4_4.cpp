#include <stdio.h>

/*

	在 x86 机器编译下述代码，并根据 x86 指令来写出相应的 Y86 指令。

	x86 =>

	long rsum(long* start, long count)
	start in %rdi, count in %rsi

	rsum: 
		movl	$0, %eax
		testq	%rsi, %rsi
		jle		.L9
		pushq	%rbx 
		movq	(%rdi), %rbx
		subq	$1, %rsi
		addq	%8, %rdi
		call	rsum
		addq	%rbx, %rax
		popq	%rbx
	.L9:
		rep; ret


	Y86 =>

	long rsum(long* start, long count)
	start in %rdi, count in %rsi

	rsum:
		xorq	%rax, %rax
		andq	%rsi, %rsi
		jle		.L9
		pushq	%rbx
		mrmovq	(%rdi), %rbx
		irmovq	$-1, %r10
		subq	%r10, %rsi	# count --
		irmovq  $8, %r10
		addq	%r10, %rdi	# start ++
		call	rsum
		addq	%rbx, %rax
		popq	%rbx
	.L9:
		rep; ret

*/
long rsum(long* start, long count) {
	if (count <= 0) {
		return 0;
	}
	return *start + rsum(start + 1, count - 1);
}