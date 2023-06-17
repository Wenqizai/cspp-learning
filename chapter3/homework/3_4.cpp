#include <stdio.h>

int main() {
	//		src_t		dest_t			指令					注释

	// 1.	long		long		movq(%rdi),%rax			读8字节
	//								movq %rax,(%rsi)		写8字节


	// 2.	char		int			movsbl (%rdi), %eax		char转为int
	//								movl	%eax, (%rsi)	写4字节

	// 3.	char		unsigned	movsbq	(%rdi),%eax		char转为int
	//								movl	%eax, (%rsi)	写4字节

	// 4.   unsigned char	long	movzbq	(%rdi),%rax		读一个字节并且零扩展
	//								movq	%rax,(%rsi)		写8字节

	// 5.  int			char		movl	(%rdx),%eax		读4字节
	//								movb	%al, (%rdi)		写低位1字节

	// 6. unsigned		unsigned char	movl (%rdx),%eax	读四字节
	//									movb %al,(%rsi)		写低位1字节

	// 7. char			short		movsbw	(%rdx),%ax		读1字节并符号扩展
	//								movw	%ax, (%rsi)		写2字节
}