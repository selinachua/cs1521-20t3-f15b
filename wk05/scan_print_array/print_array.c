#include <stdio.h>

int main(void) {
    int i;
    int numbers[10] = {0,1,2,3,4,5,6,7,8,9};

    i = 0;
    while (i < 10) {
        int num = numbers[i];
        printf("%d\n", num);
        i++;
    }
    
    return 0;
}