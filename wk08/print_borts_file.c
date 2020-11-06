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
int get_bort(FILE *f) {
    // TODO
}