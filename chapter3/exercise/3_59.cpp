#include <stdio.h>
#include <inttypes.h>


typedef int128_t int128_t;

/*
	GCC 产生下面的汇编代码来实现计算:

	store_prod(int128_t* dest, int64_t x, int64_t y)
	dest in %rdi, x in %rsi, y in %rdx

	store_prod:
		movq	%rdx, %rax		# %rax = y
		cqto					# %rax 符号位扩展到 %rdx.  %rdx = (-1)y_63
		movq	%rsi, %rcx		# %rcx = x

		# 如果 x 的符号为 1, 则全 1; 符号位为 0, 则全0
		sarq	$63, %rcx		# 将 x 的符号位扩展到所有位. %rcx = (-1)x_63
		
		imulq	%rax, %rcx		# %rcx = y * (-1)x_63
		imulq	%rsi, %rdx		# %rdx = x * (-1)y_63
		addq	%rdx, %rcx		# %rcx = y * (-1)x_63 +  x * (-1)y_63
		mulq	%rsi			# %rdx:%rax <= x * y


		addq	%rcx, %rdx
		
		movq	%rax, (%rdi)	# 设置低64位到 dest
		movq	%rdx, 8(%rdi)	# 设置高64位到 dest
		ret

*/
void store_prod(int128_t* dest, int64_t x, int64_t y) {
	*dest = x * (int128_t)y;
}
