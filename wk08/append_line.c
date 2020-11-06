
#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *stream = fopen(argv[1], "a");
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