#include <stdio.h>
#include <stdlib.h>

/*

	Y86-64 code

	long sum(long* start, long count)
	start in %rdi, count in %rsi

	sum:
		irmovq	$8, %r8		# Constant 8
		irmovq	$1, %r9		# Constant 1
		xorq	%rax, %rax	# sum = 0
		andq	%rsi, %rsi	# set CC
		jmp		test		# goto test

	loop:
		mrmovq	(%rdi), %r10	# get *start
		addq	%r10, %rax		# add to sum
		addq	%r8, %rdi		# start++
		subq	%r9, %rsi		# count--, set cc

	test:
		jne		loop	# stop when 0
		ret				# return
*/
long sum(long* start, long count) {
	long sum = 0;
	while (count) {
		sum += *start;
		start++;
		count--;
	}
	return sum;
}


/*


	修改 Y86-64 代码, 实现函数 absSum,它计算一个数组的绝对值的和。在内循环中使用
	条件跳转指令。

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
		jne		loop		# stop when 0
		ret
*/
long absSum(long* start, long count) {
	long sum = 0;
	while (count) {
		sum += abs(*start);
		start++;
		count--;
	}
	return sum;
}