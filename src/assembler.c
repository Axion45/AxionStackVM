#include "assembler.h"

#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <stddef.h>

#include "utility.h"

#define INT_STRING "0123456789"
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
    lex.lineNumber = 0;
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

static void readMnemonic(char *buffer , char c)
{
    int k = 0;
    while(c != '\n' && c = ' ' && c != EOF )
    {
        (buffer)[k] =c ;
        c = getChar();
        k++
    }

    REWIND_LEXER(lex)

    buffer[k] = '\0';
}

static int charToInt(const char *dig , char c)
{
    char *p;
    p = strchr(dig , c);
    return p ? p -dig : -1 ;
}

static int readInt(char c)
{
    int k , val = 0 , neg = 0;
    if(c == '-')
    {
        neg = 1;
        c = getChar();
    }

    if(!isdigit(c))
    {
        fprintf(stderr, "ASVM: line %ud:Expected a digit after the negative sign\n" ,lex.lineNumber);
        exit(1);
    }

    k = charToInt(INT_STRING ,c);

    while(k >= 0)
    {
        val = val*10 + k ;
        c = getChar();        
        k = charToInt(INT_STRING ,c);
    }

    REWIND_LEXER(lex);
    return neg ? -1 * val : val;

}

static char skipSpaces(char c)
{
    while(isspace(c))
    {
        if(c == '\n') lex.lineNumber +=1 ;
        c = getChar();
    }

    return c ;
}


void assemble(char *filename)
{
    initLexer(filename);


}
