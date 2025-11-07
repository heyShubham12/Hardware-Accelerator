/*
 * ADDX Hardware Accelerator Test for CVA6
 *
 * This test verifies the ADDX custom instruction implementation
 * Tests both basic functionality and overflow saturation behavior
 *
 * Author: Test Suite for CVA6 ADDX Extension
 * Date: 2025-10-30
 */

#include <stdint.h>

// ADDX instruction encoding (from encoding.h)
#define MATCH_ADDX 0xb
#define MASK_ADDX  0xfe00707f

// Helper macro for ADDX instruction
#define ADDX_INST(rd, rs1, rs2) \
    asm volatile (".word 0x%0" :: "i"(MATCH_ADDX | ((rd) << 7) | ((rs1) << 15) | ((rs2) << 20)))

// Print functions for bare metal (using UART)
void print_char(char c) {
    volatile char* uart = (volatile char*)0x10000000;
    *uart = c;
}

void print_string(const char* s) {
    while (*s) {
        print_char(*s++);
    }
}

void print_hex64(uint64_t val) {
    print_string("0x");
    for (int i = 60; i >= 0; i -= 4) {
        int digit = (val >> i) & 0xF;
        print_char(digit < 10 ? '0' + digit : 'A' + digit - 10);
    }
}

void print_hex32(uint32_t val) {
    print_string("0x");
    for (int i = 28; i >= 0; i -= 4) {
        int digit = (val >> i) & 0xF;
        print_char(digit < 10 ? '0' + digit : 'A' + digit - 10);
    }
}

void print_dec(int val) {
    if (val < 0) {
        print_char('-');
        val = -val;
    }

    if (val == 0) {
        print_char('0');
        return;
    }

    char buf[12];
    int i = 0;
    while (val > 0) {
        buf[i++] = '0' + (val % 10);
        val /= 10;
    }
    while (i > 0) {
        print_char(buf[--i]);
    }
}

// Test ADDX instruction using inline assembly
uint64_t test_addx_hw(uint64_t a, uint64_t b) {
    uint64_t result;

    // Execute ADDX instruction: result = addx(a, b)
    asm volatile (
        ".insn r 0x0B, 0, 0, %0, %1, %2"
        : "=r"(result)
        : "r"(a), "r"(b)
    );

    return result;
}

// Software reference implementation for comparison
uint64_t addx_reference(uint64_t a, uint64_t b) {
    // Perform unsigned addition and check for overflow
    uint64_t result = a + b;

    // Check for signed overflow
    int64_t sa = (int64_t)a;
    int64_t sb = (int64_t)b;
    int64_t sr = (int64_t)result;

    // Both positive and result is negative -> positive overflow
    if (sa > 0 && sb > 0 && sr < 0) {
        return 0x7FFFFFFFFFFFFFFF;  // Saturate to max positive
    }
    // Both negative and result is positive -> negative overflow
    else if (sa < 0 && sb < 0 && sr > 0) {
        return 0x8000000000000000;  // Saturate to min negative
    }

    return result;
}

// Test structure
typedef struct {
    uint64_t a;
    uint64_t b;
    uint64_t expected;
    const char* name;
} test_case_t;

// Test cases
const test_case_t tests[] = {
    // Basic addition tests
    {0x0000000000000001, 0x0000000000000001, 0x0000000000000002, "Simple 1+1"},
    {0x0000000000000005, 0x000000000000000A, 0x000000000000000F, "5+10=15"},
    {0x0000000012345678, 0x0000000087654321, 0x0000000099999999, "Basic addition"},

    // Zero tests
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000, "Zero + Zero"},
    {0x123456789ABCDEF0, 0x0000000000000000, 0x123456789ABCDEF0, "Value + Zero"},

    // Positive overflow tests (should saturate)
    {0x7FFFFFFFFFFFFFFF, 0x0000000000000001, 0x7FFFFFFFFFFFFFFF, "Max+1 (saturate)"},
    {0x7FFFFFFFFFFFFFFF, 0x7FFFFFFFFFFFFFFF, 0x7FFFFFFFFFFFFFFF, "Max+Max (saturate)"},
    {0x4000000000000000, 0x4000000000000000, 0x7FFFFFFFFFFFFFFF, "Pos overflow"},

    // Negative overflow tests (should saturate)
    {0x8000000000000000, 0x8000000000000000, 0x8000000000000000, "Min+Min (saturate)"},
    {0x8000000000000000, 0xFFFFFFFFFFFFFFFF, 0x8000000000000000, "Neg overflow"},

    // Mixed signs (no overflow)
    {0x7FFFFFFFFFFFFFFF, 0x8000000000000000, 0xFFFFFFFFFFFFFFFF, "Max+Min"},
    {0x0000000000000001, 0xFFFFFFFFFFFFFFFF, 0x0000000000000000, "1+(-1)=0"},
};

#define NUM_TESTS (sizeof(tests) / sizeof(tests[0]))

int main() {
    int passed = 0;
    int failed = 0;

    print_string("\n");
    print_string("========================================\n");
    print_string("  CVA6 ADDX Hardware Test Suite\n");
    print_string("========================================\n");
    print_string("\n");

    // Run all test cases
    for (int i = 0; i < NUM_TESTS; i++) {
        print_string("Test ");
        print_dec(i + 1);
        print_string("/");
        print_dec(NUM_TESTS);
        print_string(": ");
        print_string(tests[i].name);
        print_string("\n");

        // Execute ADDX in hardware
        uint64_t hw_result = test_addx_hw(tests[i].a, tests[i].b);

        // Get reference result
        uint64_t ref_result = addx_reference(tests[i].a, tests[i].b);

        // Display results
        print_string("  A:        ");
        print_hex64(tests[i].a);
        print_string("\n");

        print_string("  B:        ");
        print_hex64(tests[i].b);
        print_string("\n");

        print_string("  HW:       ");
        print_hex64(hw_result);
        print_string("\n");

        print_string("  Expected: ");
        print_hex64(tests[i].expected);
        print_string("\n");

        // Check result
        if (hw_result == tests[i].expected || hw_result == ref_result) {
            print_string("  Status:   PASS\n");
            passed++;
        } else {
            print_string("  Status:   FAIL\n");
            print_string("  Ref:      ");
            print_hex64(ref_result);
            print_string("\n");
            failed++;
        }

        print_string("\n");
    }

    // Print summary
    print_string("========================================\n");
    print_string("  Test Summary\n");
    print_string("========================================\n");
    print_string("  Total:  ");
    print_dec(NUM_TESTS);
    print_string("\n");
    print_string("  Passed: ");
    print_dec(passed);
    print_string("\n");
    print_string("  Failed: ");
    print_dec(failed);
    print_string("\n");
    print_string("\n");

    if (failed == 0) {
        print_string("  Result: ALL TESTS PASSED!\n");
    } else {
        print_string("  Result: SOME TESTS FAILED!\n");
    }
    print_string("========================================\n");
    print_string("\n");

    // Return number of failures
    return failed;
}
