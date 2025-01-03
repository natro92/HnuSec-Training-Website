#include <stdio.h>

void func1()
{
	__asm
	{
		lea eax,lab1;
		jmp eax
		_emit 0x90;
lab1:
	}
	// 0x90 NOP
	printf("func1\n");
}

void func2()
{
	__asm
	{
		cmp eax,ecx;
		jnz lab2;
		jz  lab2;
		_emit 0xB8;
lab2:
	}
	// 0xB8 mov eax,
	printf("func2\n");
}

int main()
{
	func1();
	func2();
	return 0;
}
