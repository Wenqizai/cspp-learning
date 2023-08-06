#include <stdio.h>

/*
	如题, 补充指令执行的过程

	标号 |	PC	| 指令	| %rdi | %rsi | %rax  | %rsp | *%rsp | 描述
	M1 | 0x400560 | callq | 10 | - | - | 0x7ffffffe820 | - | 调用first(10)
	F1 | 0x400548 | lea | 10 | - | - | 0x7ffffffe818 | 0x400565 | first 的入口
	F2 | 0x40054C | sub | 10 | 11 | - | 0x7ffffffe818 | 0x400565 | 
	F3 | 0x400550 | callq | 9 | 11 | - | 0x7ffffffe818 | 0x400565 | 调用 last(9,11)
	L1 | 0x400540 | mov | 9 | 11 | - | 0x7ffffffe810 | 0x400565 | last 的入口
	L2 | 0x400543 | imul | 9 | 11 | 9 | 0x7ffffffe810 | 0x400555 | 
	L3 | 0x400547 | retq | 9 | 11 | 99 | 0x7ffffffe810 | 0x400555 | 从 last 返回 99
	F4 | 0x400555 | retz repq | 9 | 11 | 99 | 0x7ffffffe818 | 0x400565 | 从 first 返回 99
	M2 | 0x400565 | mov | 9 | 11 | 99 | 0x7ffffffe820 | - | 继续执行main
	
*/