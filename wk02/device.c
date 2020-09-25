/**
 * Tutorial Q4
 * Bit Masking
 */

#define READING   0x01 // 0000 0001
#define WRITING   0x02 // 0000 0010
#define AS_BYTES  0x04 // 0000 0100
#define AS_BLOCKS 0x08 // 0000 1000
#define LOCKED    0x10 // 0001 0000

/**
 * We have this device and we want to change the settings of the device
 * using bitwise operations.
 * 
 * char -> 1 byte -> 8 bits
 * 
 * BITWISE OR | -> set bits 
 */
// 0000 0000
// 0000 0111
unsigned char device; 

// mark the device as locked for reading bytes
// device = 0000 0010
// device = 0001 0101
device = LOCKED | READING | AS_BYTES;

// mark the device as locked for writing blocks

// set the device as locked, leaving other flags unchanged
// num = num + 1
// device = 0000 0010
//          0001 0000 |
//         -------------
//          0001 0010
device = device | LOCKED;

// remove the lock on a device, leaving other flags unchanged

// swap a device between reading and writing, leaving other flags unchanged
