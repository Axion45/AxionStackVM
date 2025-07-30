#include "utility.h"



size_t utility_fileReader(const char *filename , char **input_buffer)
{
    FILE *f = fopen(filename, "rb");
    unsigned int file_size = 0;

    if (!f) return -1;   //failed to opne the file

    //fetch the size of the file
    fseek(f, 0, SEEK_END);
    file_size = ftell(f);
    rewind(f);

    //read file contents into the buffer
    *input_buffer= malloc(file_size + 1);
    fread(*input_buffer, 1, file_size, f);
    (*input_buffer)[file_size] = '\0';  // Sentinel
    fclose(f);

    return file_size;

}
