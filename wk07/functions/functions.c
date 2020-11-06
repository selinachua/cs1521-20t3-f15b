#include <stdio.h>

int add(int x, int y);

int main(void) {
    int i = 0;
    int x;
    int y;
    scanf("%d", &x);
    scanf("%d", &y);

    int sum = add(x, y);
    printf("%d\n", sum);

    return 0;
}

int add(int x, int y) {
    int i = 10;
    int sum = x + y;
    return sum;
}