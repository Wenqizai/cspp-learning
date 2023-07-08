#include <stdio.h>

int test() {
	/*
		A. 补充完整je指令

		4003fa: 74 02	je		4003fe
		4003fc  ff d0	callq	*%rax


		B. 补充完整je指令

		40042f: 74 f4	je		400425
		400431:	5d		pop		%rbp
		

		C. ja和pop指令地址是多少?

		400543: 77 02	ja		400547
		400545: 5d		pop		%rbp

		D. 

		4005e8: e9 73 ff ff ff		jmpq	400560
		4005ed: 90					nop
	*/
}