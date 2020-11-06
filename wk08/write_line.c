/*
Write a C program, write_line.c, which is given one command-line argument, 
the name of a file, and which reads a line from stdin, and writes it to the 
specified file; if the file exists, it should be overwritten.
*/


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *stream = fopen(argv[1], "w");
    if (stream == NULL) {
        fprintf(stderr, "Failed to open %s.\n", argv[1]);
        exit(1);
    }

    char ch;
    while ((ch = fgetc(stdin)) != '\n') {
        fputc(ch, stream);
    }

    fclose(stream);

    return 0;
}