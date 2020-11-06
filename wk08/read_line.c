/* 
Write a C program, first_line.c, which is given one command-line argument, 
the name of a file, and which prints the first line of that file to stdout. 
If given an incorrect number of arguments, or if there was an error opening 
the file, it should print a suitable error message.
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // 1. Open the file
    // int * -> int pointer
    // FILE * -> file pointer 
    FILE *stream = fopen(argv[1], "r");
    if (stream == NULL) {
        fprintf(stderr, "Failed to open %s.\n", argv[1]);
        exit(1);
    }

    // 2. Read from the file 
    // fgetc, fputc
    char ch;
    while ((ch = fgetc(stream)) != '\n') {
        // 3. Print what we read from the file 
        fputc(ch, stdout);
    }

    // 4. Close the file
    fclose(stream);

    return 0;
}