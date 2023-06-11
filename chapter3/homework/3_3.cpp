#include <stdio.h>

int main() {
	// 1. movb	$0xF, (%ebx)	
	// => false %ebx不能用来保存其他寄存器的地址 (can not use %ebx as address register)

	// 2. movl	%rax, (%rsp)	
	// => false 应该使用movq  (mismatch between instruction suffix and register id)

	// 3. movw	(%rax), 4(%rsp) 
	// => false 不能直接操作内存 (cannot have both source and destination be memory references)

	// 4. movb	%al, %sl		
	// => false %sl不是寄存器 (No register named %sl)

	// 5. movq	%rax, $0x123	
	// => false 目标地址不能是直接数 (Cannot have immediate as destination)

	// 6. mov1	%eax, %rdx		
	// => false	%rdx作为目标寄存器位数必须等于l (Destination operand incorrect size)

	// 7. movb	%si, 8(%rbp)	
	// => false 应该使用movw (mismatch between instruction suffix and register id)

}