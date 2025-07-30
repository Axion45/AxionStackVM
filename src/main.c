#include <stdio.h>
#include <stdlib.h>
#include "utility.h"

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

    char *file = NULL;

    utility_fileReader(argv[1] , &file);
    printf("%s\n", file);

    return 0;
}
