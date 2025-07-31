#include <stdio.h>
#include <stdlib.h>
#include "utility.h"
#include "assembler.h"

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

    assemble(argv[1]);
    


    return 0;
}
