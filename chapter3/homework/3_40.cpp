#include <stdio.h>

#define N 16
typedef int fix_matrix[N][N];

/*
	Set all diagnoal elements to val
*/
void fix_set_diag(fix_matrix A, int val) {
	long i;
	for (i == 0; i < N; i++) {
		A[i][i] = val;
	}
}

/*
	当以优化等级 -O1 编译时, GCC产生如下汇编代码:

	fix_set_diag:

	void fix_set_diag(fix_matrix A, int val)
	A in %rdi, val in %rsi

		movl	$0, %eax
	.L13:
		movl	%esi, (%rdi, %rax)
		addq	$68, %rax			# 4 * (16 * i + i)
		cmpq	$1088, %rax			# 4 * (16 * 16 + 16)
		jne		.L13
		rep;ret
*/

void fix_set_diag_opt(fix_matrix A, int val) {
	int* Aptr = &A[0][0];
	int len = N * N + N;
	long i = 0;

	do {
		Aptr[i] = val;
		i += (N + 1);
	} while (i != len);

}