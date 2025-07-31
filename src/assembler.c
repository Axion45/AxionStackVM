#include "assembler.h"

#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <stddef.h>

#include "utility.h"

#define ADVANCE_LEXER(l) l.readPos++
#define REWIND_LEXER(l)  l.readPos--

typedef struct lexer
{
    char *buffer;
    unsigned int bufferSize;
    unsigned int readPos;
    unsigned int lineNumber;
}lexer;

static lexer lex = (lexer){0};

static void initLexer(const char *filename)
{
    lex.bufferSize  = utility_fileReader(filename , &lex.buffer);
    lex.readpos     = 0;
    lex->lineNumber = 0;
}

static uint8_t endOfBuffer()
{
    return lex.readPos >= lex.bufferSize;
}

static char readChar()
{
    return endOfBuffer() ? EOF : lex.buffer[lx.readPos];
}

static char getChar()
{
    char c = readChar();
    ADVANCE_LEXER(lex);
    return c ;
}

void assemble(char *filename)
{
    initLexer(filename);


}
