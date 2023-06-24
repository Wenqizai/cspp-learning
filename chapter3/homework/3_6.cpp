#include <stdio.h>

int demo() {
	// 假设: x in %rax, y in %rcx

	// 1. leaq 6(%rax), %rdx		=> 6 + x

	// 2. leaq (%rax, %rcx), %rdx	=> x + y 

	// 3. leaq (%rax, %rcx, 4), %rdx	=> x + 4y

	// 4. leaq 7(%rax, %rax, 8), %rdx	=> 7 + 9x

	// 5. leaq 0xA(, %rcx, 4), %rdx		=> 10 + 4y

	// 6. leaq 9(%rax, %rcx, 2), %rdx	=>9 + x + 2y

}