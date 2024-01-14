#include <stdio.h>

/*
	在 Y86 体系中，不能用直接数来操作寄存器，比如 add, sub, mul, div 一个数，比如如下操作：

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


	假如现在增加一个指令, 可以操作直接数，请重写上述 Y86-64 code 

	字节
						0	1	 2	9	
	iaddq	v, rB	=>	c 0 F rB {V}


	long sum(long* start, long count)
	start in %rdi, count in %rsi

	sum:
		xorq	%rax, %rax	# sum = 0
		andq	%rsi, %rsi	# set CC
		jmp		test		# goto test

	loop:
		mrmovq	(%rdi), %r10	# get *start
		addq	%r10, %rax		# add to sum
		iaddq	$8, %rdi		# start++
		iaddq	$-1, %rsi		# count--, set cc

	test:
		jne		loop	# stop when 0
		ret				# return



dd 



*/
long sum(long* start, long count) {
	long sum = 0;
	while (count){
		sum += *start;
		start++;
		count--;
	}
	return sum;
}