/**
 * Program that checks if a number is odd using bitwise operations.
 */

#include <stdio.h>

int is_odd(int num);

int main(void) {
    printf("Please enter a number: ");
    int num = 0;
    scanf("%d", &num);

    if (is_odd(num)) {
        printf("ODD\n");
    } else {
        printf("EVEN\n");
    }

    return 0;
}

/**
 * Function that checks if an int is odd or even using bit masking.
 * 
 * 0101 ... 0100
 * 0000 ... 0001 & -> mask
 * ----------------
 * 0000 ... 0000
 * 0000 ... 0001
 * 
 * 0001
 * 0100 &
 * -------
 * 0000
 */
int is_odd(int num) {
    // TODO: Fill in this function.
    int mask = 1; // mask = 0000 ... 0001
    int masked_value = num & mask;
    
    // last bit is 1 -> num is ODD
    if (masked_value != 0) {
        return 1;
    }
    return 0;
}