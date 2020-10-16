#include <stdio.h>

int main(void) {
    int i;
    int numbers[10];
    
    i = 0;
    while (i < 10) {
        int scanned;
        scanf("%d", &scanned);
        numbers[i] = scanned;
        i++;
    }

    i = 0;
    while (i < 10) {
        int num = numbers[i];
        printf("%d\n", num);
        i++;
    }
    
    return 0;
}