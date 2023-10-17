#include <stdio.h>

#define R 7
#define S 5
#define T 13

long A[R][S][T];

/*

	GCC 产生如下代码:

	long store_ele(long i, long j, long k, long* dest)
	i in %rdi, j in %rsi, k in %rdx, dest in %rcx

	store_ele:
		leaq	(%rsi, %rsi, 2), %rax
		leaq	(%rsi, %rax, 4), %rax
		movq	%rdi, %rsi
		salq	$6, %rsi
		addq	%rsi, %rdi
		addq	%rax, %rdi
		addq	%rdi, %rdx
		movq	A(, %rdx, 8), %rax
		movq	%rax, (%rcx)
		movl	$3640, %eax
		ret


		A. 将等式 3.1 从二维扩展到三维, 提供数组元素 A[i][j][k] 的位置的公式.

			s = k + (2^6 + 1) * i + 13j;
			  = 65i + 13j  + k


		B. 运用你的逆向工程技术, 根据汇编代买, 确定 R, S, T的值.

			由上述公式可知:
					65i 相当于 65个  i * k
					1个k 等于 13
				那么: i * k = 65
					  k = 13
					  8 * i * j * k = 3640
			
			
			R = 7
			S = 5
			T = 13
*/
long store_ele(long i, long j, long k, long* dest) {
	*dest = A[i][j][k];
	return sizeof(A);
}
