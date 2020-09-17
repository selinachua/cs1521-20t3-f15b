/**
 * Consider the following C program:

#include <stdio.h>

int main(void)
{
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 0; i < 10; i++) {
        printf("%d\n", nums[i]);
    }
    return 0;
}

 * This program uses a for loop to print each element in the array
 * Rewrite this program using a recursive function
 */

#include <stdio.h>


void print_array(int *nums, int i) {
    // TODO: Fill this function.
}

int main(void) {
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    print_array(nums, 0);
    return 0;
}