
#include <stdlib.h>
#include <stdio.h>

#include "vm.h"


int  vmInit(vm *vm)
{
    vm->memory = calloc(MEMORY_SIZE , sizeof(int));

    if(!vm->memory)
    {
        fprintf(stderr ,"ASMV~Unable to initialize memory for the vm");
        return -1;
    }

    vm->reg.pc = 0;
    vm->reg.sp = 0;
    vm->reg.sp = 0;
}

int opcodeIntoMemory(vm *vm, opcode p)
{
    if(vm->reg.pc >= MEMORY_SIZE)
    {
        fprintf(stderr , "ASMV~ Memory full");
        exit(1);
    }
    vm->memory[vm->reg.pc++] = p;
}

int operandIntoMemory(vm *vm,, int k)
{ 
    if(vm->reg.pc >= MEMORY_SIZE)
    {
        fprintf(stderr , "ASMV~ Memory full");
        exit(1);
    }
    vm->memory[vm->reg.pc++] = k;
}







