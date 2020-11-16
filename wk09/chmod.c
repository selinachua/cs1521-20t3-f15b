// remove public write from specified as command line arguments if needed

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

void chmod_if_needed(char *pathname);

int main(int argc, char *argv[]) {
    for (int arg = 1; arg < argc; arg++) {
        chmod_if_needed(argv[arg]);
    }
    return 0;
}

// chmod a file if publically-writeable

void chmod_if_needed(char *pathname) {
    // if OTHER can write to a file:
    //      chmod() so that OTHER cannot write to the file

    // 1. Use the stat function to get information about the file
    struct stat s;
    if (stat(pathname, &s) != 0) {
        perror(pathname);
        exit(1);
    }

    // 2. Check if OTHER can write to the file by looking at the st_mode
    mode_t mode = s.st_mode;
    // S_IWOTH -> bit for OTHER writing 
    if ((mode & S_IWOTH) != 0) {
        // OTHER CAN write to the file
        // 000 000 010 -> 000 000 000
        // 3. if OTHER can write, we want to chmod()
        mode_t new_mode = mode & ~S_IWOTH;
        chmod(pathname, new_mode);
    }
}