#include <stdio.h>
#include <assert.h>

typedef unsigned int Word;

/**
 * e.g. 1010 -reverseBits()-> 0101
 * 
 * 1. extract each bit
 * 2. check if each bit is 1 or 0
 * 3. set the bit in return value
 * 
 * RET = 0000
 * 
 * step by step:
 * extract the rightmost bit:
 * 1010
 * 0001 &
 * -------
 * 0000 == 0 -> rightmost bit = 0
 * 
 * setting the leftmost bit:
 * 
 * 
 * 
 * 
 * extracting bit:
 * 1010
 * 0010 &
 * -------
 * 0010 != 0 -> second rightmost bit = 1
 * 
 * setting the bit in ret:
 * 0000
 * 0100 |
 * -------
 * 0100
 * 
 * 1010
 * 0100 &
 * -------
 * 0000 == 0 -> third rightmost bit = 0
 * 
 * 1010
 * 1000 &
 * ------
 * 1000 != 0 -> leftmost bit = 1
 * 
 * setting the bit in ret:
 * 0100
 * 0001 |
 * -------
 * 0101 -> final binary
 * 
 * 
 * pseudocode:
 * ret = 0
 * for each bit inside the binary {
 *      extract the bit using bitwise AND
 *      if (result != 0) {
 *          set the bit in the return value using bitwise OR 
 *      }
 * }
 * return ret;
 * 
 */
Word reverseBits(Word w) {
    // int ret = 0;
    Word ret = 0;

    for (int i = 0; i < 32; i++) {
        // Extract the bit using bitwise AND 
        // in the first iteration:  0000 ... 0001
        // in the second iteration: 0000 ... 0010
        // in the third iteration:  0000 ... 0100
        int mask = 1 << i;
        int masked_value = w & mask;
        if (masked_value != 0) {
            // set the bit in the return value using bitwise OR
            // in the first iteration:  1000 ... 0000 = 1 << 31
            // in the second iteration: 0100 ... 0000 = 1 << 31 - 1
            // in the third iteration:  0010 ... 0000 = 1 << 31 - 2
            // in the fourth iteration: 0001 ... 0000 = 1 << 31 - 3
            int set_mask = 1 << (31 - i);
            ret = ret | set_mask;
        }
    }

    return ret;
}

// testing
int main(void) {
    Word w1 = 0x01234567;
    // 0000 => 0000 = 0
    // 0001 => 1000 = 8
    // 0010 => 0100 = 4
    // 0011 => 1100 = C
    // 0100 => 0010 = 2
    // 0101 => 1010 = A
    // 0110 => 0110 = 6
    // 0111 => 1110 = E
    assert(reverseBits(w1) == 0xE6A2C480);
    puts("All tests passed!");
    return 0;
}