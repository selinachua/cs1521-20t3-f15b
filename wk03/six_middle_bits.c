/**
 * We have 32 bits, and we want to get the middle 6 bits.
 * 
 * 0101 ... 111100 ... 0111
 * >> 13
 */
uint32_t six_middle_bits(uint32_t u) {
    uint32_t shifted = u >> 13;
    uint32_t mask = 0x3F; // 0011 1111
    return shifted & mask;
}



struct float_components_t {
    uint32_t sign; // 0 or 1
    uint32_t exponent;
    uint32_t fraction;
};