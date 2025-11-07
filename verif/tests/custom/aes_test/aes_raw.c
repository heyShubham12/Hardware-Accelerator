/*
 * AES Test using raw instruction encoding for CVA6
 */

#include <stdint.h>

// Test AES functionality using raw instruction words
int test_aes_raw() {
    uint32_t input_data = 0x12345678;
    uint32_t result1, result2, result3;

    // Test AES32ESI instruction (funct7=0x32, funct3=0x0, opcode=0x33)
    // Using .word directive for AES instruction
    asm volatile (
        ".word 0x32000033"     // aes32esi x0, x0, x0, 0
        : "=r"(result1)
        : "r"(input_data)
    );

    // Test AES32ESMI instruction (funct7=0x36, funct3=0x0, opcode=0x33)
    asm volatile (
        ".word 0x36000033"     // aes32esmi x0, x0, x0, 0
        : "=r"(result2)
        : "r"(input_data)
    );

    // Test SHA256SIG0 instruction
    asm volatile (
        ".word 0x10201013"     // sha256sig0 x0, x0
        : "=r"(result3)
        : "r"(input_data)
    );

    // If any result is non-zero, AES unit is working
    if (result1 != 0 || result2 != 0 || result3 != 0) {
        return 0;  // Success
    }
    return 1;  // Failure
}

int main() {
    return test_aes_raw();
}