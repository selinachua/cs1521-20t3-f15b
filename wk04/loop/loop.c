#include <stdio.h>

int main(void) {
    for (int x = 24; x < 42; x += 3) {
        printf("%d\n",x);
    }
    return 0;
}

int main(void) {
    int x = 24;
    // if x >= 42, then branch to end_loop
    while (x < 42) {

        printf("%d\n", x);

        x += 3;
    }

    return 0;
}


int i = 0;
while (condition) {
    int j = 0;
    while (condition) {
        ....
        j++;
    }
    i++;
}