#include <stdio.h>

/*
	汇编代码

	void uremdiv(unsigned long x, unsigned long y, unsigned long* qp, unsigned long* rp)
	x in %rdi, y in %rsi, qp in %rdx, rp in %rcx

	remdiv: 
		movq	%rdx,%r8
		movq	%rdi,%rax
		xorq	%rdx,%rdx
		divq	%rsi
		movq	%rax,(%r8)
		movq	%rdx,(rcx)
		ret
*/
void uremdiv(unsigned long x, unsigned long y, unsigned long* qp, unsigned long* rp) {
	unsigned long q = x / y;
	unsigned long r = x % y;
	*qp = q;
	*rp = r;
}

int main() {
	int a = 9;
	int b = -2;
	int div = a / b;
	int rem = a % b;
	printf("%d \n", div);
	// 注意 rem 的符号位与除数a的符号位一直
	// 当进行指令 a / b 时, 会先执行汇编指令 cqto, 将 %rax (也就是a) 的符号位扩展到 %rdx 中
	printf("%d \n", rem);
	return 0;
}