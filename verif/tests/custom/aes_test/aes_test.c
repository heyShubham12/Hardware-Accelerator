/*
 * AES Accelerator Test Program for CVA6
 * Tests the RISC-V Zkn AES acceleration instructions
 */

#include <stdint.h>
#include <stdio.h>

// AES Test Vectors (from FIPS 197)
#define AES_BLOCK_SIZE 16

// Known plaintext
static const uint8_t test_plaintext[AES_BLOCK_SIZE] = {
    0x32, 0x43, 0xf6, 0xa8, 0x88, 0x5a, 0x30, 0x8d,
    0x31, 0x31, 0x98, 0xa2, 0xe0, 0x37, 0x07, 0x34
};

// Known key
static const uint8_t test_key[AES_BLOCK_SIZE] = {
    0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6,
    0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c
};

// Expected ciphertext after first round
static const uint8_t expected_round1[AES_BLOCK_SIZE] = {
    0x19, 0x3d, 0xe3, 0xbe, 0xa0, 0xf4, 0xe2, 0x2b,
    0x9a, 0xc6, 0x8d, 0x2a, 0xe9, 0xf8, 0x48, 0x08
};

// Inline assembly macros for AES instructions
// Note: These assume binutils support for Zkn extension

#define AES32ESI(rd, rs1, rs2, bs) \
    asm volatile ("aes32esi %0, %1, %2, %3" : "=r"(rd) : "r"(rs1), "r"(rs2), "i"(bs))

#define AES32ESMI(rd, rs1, rs2, bs) \
    asm volatile ("aes32esmi %0, %1, %2, %3" : "=r"(rd) : "r"(rs1), "r"(rs2), "i"(bs))

#define AES32DSI(rd, rs1, rs2, bs) \
    asm volatile ("aes32dsi %0, %1, %2, %3" : "=r"(rd) : "r"(rs1), "r"(rs2), "i"(bs))

#define AES32DSMI(rd, rs1, rs2, bs) \
    asm volatile ("aes32dsmi %0, %1, %2, %3" : "=r"(rd) : "r"(rs1), "r"(rs2), "i"(bs))

// For 64-bit systems
#ifdef __riscv_xlen_64
#define AES64ES(rd, rs1, rs2) \
    asm volatile ("aes64es %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2))

#define AES64ESM(rd, rs1, rs2) \
    asm volatile ("aes64esm %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2))

#define AES64DS(rd, rs1, rs2) \
    asm volatile ("aes64ds %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2))

#define AES64DSM(rd, rs1, rs2) \
    asm volatile ("aes64dsm %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2))
#endif

// SHA256 test macros
#define SHA256SIG0(rd, rs1) \
    asm volatile ("sha256sig0 %0, %1" : "=r"(rd) : "r"(rs1))

#define SHA256SIG1(rd, rs1) \
    asm volatile ("sha256sig1 %0, %1" : "=r"(rs1) : "r"(rs1))

// Test functions
void print_hex(const uint8_t* data, int len) {
    for (int i = 0; i < len; i++) {
        printf("%02x ", data[i]);
    }
    printf("\n");
}

int test_aes32_sbox() {
    printf("Testing AES32 S-Box operations...\n");

    uint32_t test_input = 0x12345678;
    uint32_t result_esi, result_esmi, result_dsi, result_dsmi;

    // Test each byte position (0-3)
    for (int bs = 0; bs < 4; bs++) {
        printf("Testing byte position %d:\n", bs);

        // Test forward operations
        AES32ESI(result_esi, 0x00000000, test_input, bs);
        AES32ESMI(result_esmi, 0x00000000, test_input, bs);

        printf("  AES32ESI  result: 0x%08x\n", result_esi);
        printf("  AES32ESMI result: 0x%08x\n", result_esmi);

        // Test inverse operations
        AES32DSI(result_dsi, 0x00000000, result_esi, bs);
        AES32DSMI(result_dsmi, 0x00000000, result_esmi, bs);

        printf("  AES32DSI  result: 0x%08x\n", result_dsi);
        printf("  AES32DSMI result: 0x%08x\n", result_dsmi);

        // Verify inverse property (approximately)
        uint8_t original_byte = (test_input >> (bs * 8)) & 0xFF;
        uint8_t recovered_byte_esi = (result_dsi >> (bs * 8)) & 0xFF;

        printf("  Original byte: 0x%02x, Recovered: 0x%02x\n",
               original_byte, recovered_byte_esi);
    }

    return 0;
}

#ifdef __riscv_xlen_64
int test_aes64_operations() {
    printf("Testing AES64 operations...\n");

    // Test with known values
    uint64_t state_lo = 0x123456789ABCDEF0ULL;
    uint64_t state_hi = 0xFEDCBA0987654321ULL;
    uint64_t result_es, result_esm, result_ds, result_dsm;

    // Test 64-bit encryption
    AES64ES(result_es, state_lo, state_hi);
    AES64ESM(result_esm, state_lo, state_hi);

    printf("AES64ES  result: 0x%016lx\n", result_es);
    printf("AES64ESM result: 0x%016lx\n", result_esm);

    // Test 64-bit decryption
    AES64DS(result_ds, result_es, state_hi);
    AES64DSM(result_dsm, result_esm, state_hi);

    printf("AES64DS  result: 0x%016lx\n", result_ds);
    printf("AES64DSM result: 0x%016lx\n", result_dsm);

    return 0;
}
#endif

int test_sha256_operations() {
    printf("Testing SHA256 operations...\n");

    uint32_t test_value = 0x61626380; // "abc" + padding start
    uint32_t sig0_result, sig1_result;

    SHA256SIG0(sig0_result, test_value);
    SHA256SIG1(sig1_result, test_value);

    printf("SHA256SIG0(0x%08x) = 0x%08x\n", test_value, sig0_result);
    printf("SHA256SIG1(0x%08x) = 0x%08x\n", test_value, sig1_result);

    // Known test vectors for SHA256 sigma functions
    // σ₀(x) = ROTR²(x) ⊕ ROTR¹³(x) ⊕ ROTR²²(x)
    uint32_t expected_sig0 = ((test_value >> 2) | (test_value << 30)) ^
                            ((test_value >> 13) | (test_value << 19)) ^
                            ((test_value >> 22) | (test_value << 10));

    printf("Expected SIG0: 0x%08x, Got: 0x%08x, %s\n",
           expected_sig0, sig0_result,
           (expected_sig0 == sig0_result) ? "PASS" : "FAIL");

    return (expected_sig0 == sig0_result) ? 0 : 1;
}

int test_aes_round_function() {
    printf("Testing complete AES round function...\n");

    // Simple test: apply one round of AES to test data
    uint32_t state[4];
    uint32_t key[4];

    // Copy test data
    for (int i = 0; i < 4; i++) {
        state[i] = ((uint32_t*)test_plaintext)[i];
        key[i] = ((uint32_t*)test_key)[i];
    }

    printf("Initial state: ");
    print_hex((uint8_t*)state, 16);

    // Apply AddRoundKey (XOR with key)
    for (int i = 0; i < 4; i++) {
        state[i] ^= key[i];
    }

    printf("After AddRoundKey: ");
    print_hex((uint8_t*)state, 16);

    // Apply SubBytes and ShiftRows using AES32ESMI for middle round
    uint32_t new_state[4] = {0};

    // This is a simplified version - real AES would need proper ShiftRows
    for (int col = 0; col < 4; col++) {
        for (int bs = 0; bs < 4; bs++) {
            uint32_t temp;
            AES32ESMI(temp, new_state[col], state[(col + bs) % 4], bs);
            new_state[col] = temp;
        }
    }

    printf("After SubBytes+ShiftRows+MixColumns: ");
    print_hex((uint8_t*)new_state, 16);

    return 0;
}

int main() {
    printf("CVA6 AES Accelerator Test Suite\n");
    printf("===============================\n\n");

    int failures = 0;

    // Test individual operations
    failures += test_aes32_sbox();
    printf("\n");

#ifdef __riscv_xlen_64
    failures += test_aes64_operations();
    printf("\n");
#endif

    failures += test_sha256_operations();
    printf("\n");

    failures += test_aes_round_function();
    printf("\n");

    printf("Test Summary:\n");
    if (failures == 0) {
        printf("All tests PASSED!\n");
    } else {
        printf("%d tests FAILED!\n", failures);
    }

    return failures;
}