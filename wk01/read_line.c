/**
 * Write a C program that reads lines of input until you press Ctrl-D. 
 * After each line is read, it should print out the number of characters 
 * (including new lines) in the line just read in.
 * 
 * You can assume that lines are no longer than 4096 characters.
 * 
 * abc
 * 4
 * a
 * 2
 * CTRL-D
 */

#include <stdio.h>
#include <string.h>

#define MAX_CHARS   4096

int main(void) {

    // TODO: Fill this function.
    char line[MAX_CHARS] = {0};
    while (fgets(line, MAX_CHARS, stdin) != NULL) {
        printf("%lu\n", strlen(line));
    }
    
    return 0;
}