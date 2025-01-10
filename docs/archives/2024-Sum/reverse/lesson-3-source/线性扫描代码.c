#include <stdio.h>  
#include <stdint.h>  
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include<minwindef.h>
// dispatcher
int input[200];
int memory[500];
typedef  __int32 _DWORD;
typedef char _BYTE;
unsigned char opcode[] =
{
  0x00, 0x03, 0x02, 0x00, 0x03, 0x00, 0x02, 0x03, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x02, 0x01, 0x00, 0x00, 0x03, 0x02, 0x32,
  0x03, 0x00, 0x02, 0x03, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00,
  0x01, 0x00, 0x00, 0x03, 0x02, 0x64, 0x03, 0x00, 0x02, 0x03,
  0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x01, 0x00, 0x00, 0x03,
  0x00, 0x08, 0x00, 0x02, 0x02, 0x01, 0x03, 0x04, 0x01, 0x00,
  0x03, 0x05, 0x02, 0x00, 0x03, 0x00, 0x01, 0x02, 0x00, 0x02,
  0x00, 0x01, 0x01, 0x00, 0x00, 0x03, 0x00, 0x01, 0x03, 0x00,
  0x03, 0x00, 0x00, 0x02, 0x00, 0x03, 0x00, 0x03, 0x01, 0x28,
  0x04, 0x06, 0x5F, 0x05, 0x00, 0x00, 0x03, 0x03, 0x00, 0x02,
  0x01, 0x00, 0x03, 0x02, 0x96, 0x03, 0x00, 0x02, 0x03, 0x00,
  0x00, 0x00, 0x00, 0x04, 0x07, 0x88, 0x00, 0x03, 0x00, 0x01,
  0x03, 0x00, 0x03, 0x00, 0x00, 0x02, 0x00, 0x03, 0x00, 0x03,
  0x01, 0x28, 0x04, 0x07, 0x63, 0xFF, 0xFF, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

__int64 __fastcall pop(_DWORD* a1)
{
    __int64 result; // rax
    unsigned __int8 v2; // [rsp+0h] [rbp-18h]

    v2 = opcode[a1[6] + 1];
    if (v2)
    {
        switch (v2)
        {
        case 1u:
            //a1[1] = memory[a1[7]--];
            printf("push reg[1]\n");
            break;
        case 2u:
            //a1[2] = memory[a1[7]--];
            printf("push reg[2]\n");
            break;
        case 3u:
            //a1[3] = memory[a1[7]--];
            printf("push reg[3]\n");
            break;
        }
    }
    else
    {
        //*a1 = memory[a1[7]--];
        printf("push reg[0]\n");
    }
    result = (unsigned int)(a1[6] + 2);
    a1[6] = result;
    return result;
}
__int64 __fastcall push(_DWORD* reg)
{
    __int64 result; // rax
    unsigned __int8 v2; // [rsp+0h] [rbp-18h]

    v2 = opcode[reg[6] + 1];
    if (v2)
    {
        switch (v2)
        {
        case 1u:
            printf("pop reg[1]\n");
            break;
        case 2u:
            printf("pop reg[2]\n");
            break;
        case 3u:
            printf("pop reg[3]\n");
            break;
        }
    }
    else
    {
        printf("pop reg[0]\n");
    }
    result = (unsigned int)(reg[6] + 2);
    reg[6] = result;
    return result;
}
__int64 __fastcall mov(_DWORD* reg)
{
    __int64 result; // rax
    unsigned __int8 v2; // [rsp+0h] [rbp-18h]

    v2 = opcode[reg[6] + 1];                      // 指令参数
    if (v2)
    {
        switch (v2)
        {
        case 1u:
            //input[reg[2]] = *reg;
            printf("mov reg[2],input[reg[2]]\n");
            break;
        case 2u:
            //reg[opcode[reg[6] + 2]] = reg[opcode[reg[6] + 3]];
            printf("mov reg[%d],reg[%d]\n", opcode[reg[6] + 2], opcode[reg[6] + 3]);
            break;
        case 3u:
            //reg[opcode[reg[6] + 2]] = opcode[reg[6] + 3];
            printf("mov reg[%d],%d\n", opcode[reg[6] + 2], opcode[reg[6] + 3]);
            break;
        }
    }
    else
    {
        //*reg = input[reg[2]];
        printf("mov reg[0],input[reg[2]]\n");
    }
    result = (unsigned int)(reg[6] + 4);
    reg[6] = result;
    return result;
}
__int64 __fastcall cmp(__int64 a1)
{
    __int64 result; // rax
    printf("cmp reg[0],reg[1]\n");
    /*if (*(_DWORD*)a1 == *(_DWORD*)(a1 + 4))
        *(_BYTE*)(a1 + 32) = 0;
    if (*(_DWORD*)a1 != *(_DWORD*)(a1 + 4))
        *(_BYTE*)(a1 + 32) = 1;*/
    result = (unsigned int)(*(_DWORD*)(a1 + 24) + 1);
    *(_DWORD*)(a1 + 24) = result;
    return result;
}
__int64 __fastcall op(__int64 reg)
{
    __int64 result; // rax

    switch (opcode[*(_DWORD*)(reg + 24) + 1])
    {
    case 0u:
        /**(_DWORD*)(reg + 4i64 * opcode[*(_DWORD*)(reg + 24) + 2]) += *(_DWORD*)(reg
            + 4i64
            * opcode[*(_DWORD*)(reg + 24) + 3]);*/
        printf("add reg[%d] reg[%d]\n",opcode[*(_DWORD*)(reg + 24) + 2],opcode[*(_DWORD*)(reg + 24) + 3]);
        break;
    case 1u:
        /**(_DWORD*)(reg + 4i64 * opcode[*(_DWORD*)(reg + 24) + 2]) -= *(_DWORD*)(reg
            + 4i64
            * opcode[*(_DWORD*)(reg + 24) + 3]);*/
        printf("sub reg[%d] reg[%d]\n", opcode[*(_DWORD*)(reg + 24) + 2], opcode[*(_DWORD*)(reg + 24) + 3]);
        break;
    case 2u:
        /**(_DWORD*)(reg + 4i64 * opcode[*(_DWORD*)(reg + 24) + 2]) *= *(_DWORD*)(reg
            + 4i64
            * opcode[*(_DWORD*)(reg + 24) + 3]);*/
        printf("mul reg[%d] reg[%d]\n", opcode[*(_DWORD*)(reg + 24) + 2], opcode[*(_DWORD*)(reg + 24) + 3]);
        break;
    case 3u:

        printf("xor reg[%d] reg[%d]\n", opcode[*(_DWORD*)(reg + 24) + 2], opcode[*(_DWORD*)(reg + 24) + 3]);
        break;
    case 4u:
        printf("shl reg[%d] reg[%d]\n", opcode[*(_DWORD*)(reg + 24) + 2], opcode[*(_DWORD*)(reg + 24) + 3]);
        break;
    case 5u:

        printf("shr reg[%d] reg[%d]\n", opcode[*(_DWORD*)(reg + 24) + 2], opcode[*(_DWORD*)(reg + 24) + 3]);
        break;
    default:
        break;
    }
    result = (unsigned int)(*(_DWORD*)(reg + 24) + 4);
    *(_DWORD*)(reg + 24) = result;
    return result;
}
__int64 __fastcall jmp(__int64 a1)
{
    __int64 result; // rax
    printf("jmp %d\n", opcode[*(_DWORD*)(a1 + 24) + 1]);

    result = *(_DWORD*)(a1 + 24) += 2;
    return result;
}
__int64 __fastcall jne(__int64 a1)
{
    __int64 result; // rax
    printf("jne %d\n", opcode[*(_DWORD*)(a1 + 24) + 1]);

    result= (*(_DWORD*)(a1 + 24) +=2) ;
    return result;
}
__int64 __fastcall je(__int64 a1)
{
    __int64 result; // rax
    printf("je %d\n", opcode[*(_DWORD*)(a1 + 24) + 1]);
    result = (unsigned int)(*(_DWORD*)(a1 + 24) + 2);

    *(_DWORD*)(a1 + 24) = result;
    return result;
}
__int64 __fastcall dispatcher(_DWORD* reg)
{
    //printf("running\n");
    __int64 result; // rax
    printf("%d ", reg[6]);
    result = opcode[reg[6]];
    switch (opcode[reg[6]])                     
    {                                             
    case 0u:
        result = mov(reg);
        break;
    case 1u:
        result = push(reg);
        break;
    case 2u:
        result = pop(reg);
        break;
    case 3u:
        result = op((__int64)reg);
        break;
    case 4u:
        result = cmp((__int64)reg);
        break;
    case 5u:
        result = jmp((__int64)reg);
        break;
    case 6u:
        result = je((__int64)reg);
        break;
    case 7u:
        result = jne((__int64)reg);
        break;
    default:
        return result;
    }
    return result;
}

int main() {
	char reg[40]; memset(reg, 0, 40); //reg[24] = 0, reg[28] = 0, reg[32] = 0;
    while (opcode[*(unsigned int*)(reg + 24)] != 255)   dispatcher((_DWORD*)reg);




}