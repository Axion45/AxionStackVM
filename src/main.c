#include <stdio.h>
#include <stdlib.h>
#include "utility.h"
#include "assembler.h"
#include "vm.h"

void printUsage(char *filename)
{
    fprintf(stderr , "usage: <%s> <srcfile.txt> ]\n" , filename);
    return;
}

int main(int argc , char *argv[])
{
    if(argc < 2 )
    {
        printUsage(argv[0]);
        return 1;
    }
    vm proc;
    vmInit(&proc);
    assemble(argv[1] , proc);
    
    return 0;
}
