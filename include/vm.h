#pragma once 

#include <cstdint>
#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

#define MEMORY_SIZE 1024

typedef enum 
{
	ALLOC , 
	ADD,
	SUB, 
	PUSH ,
	HALT,
	MUL,
	DIV,
	MOD,
    BRANCHTO,
	BEQ,
	BLT,
	BLE,
	BGT,
    LABEL,
    JUMP, 
	BGE,
	NOT,
	MOV,
    IPRINT,
	NOP
} opcode ;


typedef struct Register 
{
	uint32_t pc ;    //instruction register 
    uint32_t sp ;
    uint32_t hp ;

} Registers;



typedef struct 
{
	opcode *memory;   
	Registers reg ;
} vm ;


uint8_t vmInit(vm *);
uint8_t opcodeIntoMemory(vm * , opcode);
uint8_t operandIntoMemory(vm * , int);
