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

	absSum:
		irmovq	$8, %r8		# constant 8
		irmovq	$1, %r9		# constant 1
		xorq	%rax, %rax	# sum = 0
		andq	%rsi, %rsi	# set condition code
		jmp		test
	
	loop: 
		mrmovq	(%rdi), %r10	# x = *start
		xorq	%r11, %r11		# constant 0
		subq	%r10, %r11		# -x
		jle		pos				# skip if -x <= 0
		rrmovq	%r11, %r10		# x = -x

	pos: 
		addq	%r10, %rax		# add to sum
		addq	%r8, %rdi		# start ++
		subq	%r9, %rsi		# count --

	test:
		jne		loop		# stop when 
		ret



	搞不懂


*/
long rsum(long* start, long count) {
	if (count <= 0) {
		return 0;
	}
	return *start + rsum(start + 1, count - 1);
}