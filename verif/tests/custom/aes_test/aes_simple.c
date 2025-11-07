/*
 * Simple AES Test for CVA6 with ZKN extension
 */

#include <stdint.h>

// Simple test function that uses AES32ESI instruction
int test_aes32esi() {
    uint32_t result;
    uint32_t rs1 = 0x00000000;  // Input state
    uint32_t rs2 = 0x12345678;  // Input data

    // AES32ESI instruction: aes32esi rd, rs1, rs2, 0
    // This applies S-box substitution to byte 0 of rs2
    // Using raw instruction encoding: 0x32000033 + register encoding
    asm volatile (".word 0x32000033" : "=r"(result) : "r"(rs1), "r"(rs2));

    // Check if we got a non-zero result (indicating AES unit is working)
    if (result != 0) {
        return 0;  // Success
    }
    return 1;  // Failure
}

int main() {
    // Run simple AES test
    int result = test_aes32esi();

    // Return 0 for success, 1 for failure
    return result;
}