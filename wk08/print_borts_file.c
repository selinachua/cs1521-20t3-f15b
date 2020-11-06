// Print contents of a file containing unsigned two-byte big-endian integers

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void print_borts_file(char *pathname);
int get_bort(FILE *f);

int main(int argc, char *argv[]) {
    for (int arg = 1; arg < argc; arg++) {
        print_borts_file(argv[arg]);
    }
    return 0;
}

void print_borts_file(char *pathname) {
    FILE *stream = fopen(pathname, "r");
    if (stream == NULL) {
        perror(pathname);
        exit(1);
    }

    size_t n_borts_read = 0;
    int bort;
    while ((bort = get_bort(stream)) != EOF) {
        printf("bort %4ld: %d\n", n_borts_read, bort);
        n_borts_read++;
    }

    fclose(stream);
}

// read an unsigned two-byte big-endian integers from stream f
// return integer or EOF

// 10101010 01010101
//    A        B
// ret = 00000000 00000000 10101010 01010101

// byte0 = 10101010
// byte1 = 01010101
int get_bort(FILE *f) {
    // Reading byte A
    int byte0 = fgetc(f);
    if (byte0 == EOF) {
        return EOF;
    }
    // Reading byte B
    int byte1 = fgetc(f);
    if (byte1 == EOF) {
        return EOF;
    }
    return (byte0 << 8) | byte1;
}