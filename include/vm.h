#pragma once 

#include <stdio.h>

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
