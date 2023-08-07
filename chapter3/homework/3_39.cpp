#include <stdio.h>


#define N 16
typedef int fix_matrix[N][N];

/*
	根据表达式: &D[i][j] = xd + L(C * i + j), 其中C为j数组的size, L为j数组的类型大小
	解析以下表达式:

	&A[i][0] = xa + 4 * (16 * i + 0) = xa + 64i
	
	&B[0][k] = xb + 4 * (16 * 0 + k) = xb + 4k

	&A[N][k] = xa + 4 * (16 * 16 + k) = xa + 1024 + 4k

*/
int fix_prod_ele(fix_matrix A, fix_matrix B, long i, long k) {
	int* Aptr = &A[i][0];
	int* Bptr = &B[0][k];
	int* Bend = &A[N][k];
}