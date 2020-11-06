/*
Write a C program, write_line.c, which is given one command-line argument, 
the name of a file, and which reads a line from stdin, and writes it to the 
specified file; if the file exists, it should be overwritten.
*/

#include <stdio.h>

int main(int argc, char **argv) {
    FILE *fp = fopen("text.txt", "w");
    if (fp == NULL) {
        perror("text.txt");
    }
    int c;
    while ((c = fgetc(stdin)) != '\n') {
        fputc(c, fp);
    }
    fclose(fp);

    return 0;
}