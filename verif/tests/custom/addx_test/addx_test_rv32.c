/*
 * ADDX Hardware Accelerator Test for CVA6 RV32
 *
 * This test verifies the ADDX custom instruction implementation
 * Tests both basic functionality and overflow saturation behavior
 *
 * Author: CVA6 ADDX Integration Test Suite
 * Date: 2025-11-13
 */

#include <stdint.h>

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
uint32_t test_addx_hw(uint32_t a, uint32_t b) {
    uint32_t result;

    // Execute ADDX instruction: result = addx(a, b)
    // .insn r opcode, funct3, funct7, rd, rs1, rs2
    // opcode = 0x0B (OpcodeCustom0), funct3 = 0, funct7 = 0
    asm volatile (
        ".insn r 0x0B, 0, 0, %0, %1, %2"
        : "=r"(result)
        : "r"(a), "r"(b)
    );

    return result;
}

// Software reference implementation for comparison (32-bit)
uint32_t addx_reference(uint32_t a, uint32_t b) {
    // Perform unsigned addition
    uint32_t result = a + b;

    // Check for signed overflow
    int32_t sa = (int32_t)a;
    int32_t sb = (int32_t)b;
    int32_t sr = (int32_t)result;

    // Both positive and result is negative -> positive overflow
    if (sa > 0 && sb > 0 && sr < 0) {
        return 0x7FFFFFFF;  // Saturate to max positive (32-bit)
    }
    // Both negative and result is positive -> negative overflow
    else if (sa < 0 && sb < 0 && sr > 0) {
        return 0x80000000;  // Saturate to min negative (32-bit)
    }

    return result;
}

// Test structure
typedef struct {
    uint32_t a;
    uint32_t b;
    uint32_t expected;
    const char* name;
} test_case_t;

// Test cases for RV32
const test_case_t tests[] = {
    // Basic addition tests
    {0x00000001, 0x00000001, 0x00000002, "Simple 1+1"},
    {0x00000005, 0x0000000A, 0x0000000F, "5+10=15"},
    {0x12345678, 0x11111111, 0x23456789, "Basic addition"},

    // Zero tests
    {0x00000000, 0x00000000, 0x00000000, "Zero + Zero"},
    {0x12345678, 0x00000000, 0x12345678, "Value + Zero"},

    // Positive overflow tests (should saturate to 0x7FFFFFFF)
    {0x7FFFFFFF, 0x00000001, 0x7FFFFFFF, "Max+1 (saturate)"},
    {0x7FFFFFFF, 0x7FFFFFFF, 0x7FFFFFFF, "Max+Max (saturate)"},
    {0x40000000, 0x40000000, 0x7FFFFFFF, "Pos overflow"},
    {0x50000000, 0x30000000, 0x7FFFFFFF, "Another pos overflow"},

    // Negative overflow tests (should saturate to 0x80000000)
    {0x80000000, 0x80000000, 0x80000000, "Min+Min (saturate)"},
    {0x80000000, 0xFFFFFFFF, 0x80000000, "Neg overflow"},
    {0xC0000000, 0xC0000000, 0x80000000, "Neg overflow 2"},

    // Mixed signs (no overflow expected)
    {0x7FFFFFFF, 0x80000000, 0xFFFFFFFF, "Max+Min"},
    {0x00000001, 0xFFFFFFFF, 0x00000000, "1+(-1)=0"},
    {0x7FFFFFFF, 0xFFFFFFFF, 0x7FFFFFFE, "Max+(-1)"},

    // Additional edge cases
    {0x00000100, 0x00000200, 0x00000300, "256+512"},
    {0x0000FFFF, 0x00000001, 0x00010000, "0xFFFF+1"},
};

#define NUM_TESTS (sizeof(tests) / sizeof(tests[0]))

int main() {
    int passed = 0;
    int failed = 0;

    print_string("\n");
    print_string("========================================\n");
    print_string("  CVA6 ADDX RV32 Hardware Test Suite\n");
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
        uint32_t hw_result = test_addx_hw(tests[i].a, tests[i].b);

        // Get reference result
        uint32_t ref_result = addx_reference(tests[i].a, tests[i].b);

        // Display results
        print_string("  A:        ");
        print_hex32(tests[i].a);
        print_string("\n");

        print_string("  B:        ");
        print_hex32(tests[i].b);
        print_string("\n");

        print_string("  HW:       ");
        print_hex32(hw_result);
        print_string("\n");

        print_string("  Expected: ");
        print_hex32(tests[i].expected);
        print_string("\n");

        // Check result
        if (hw_result == tests[i].expected || hw_result == ref_result) {
            print_string("  Status:   PASS\n");
            passed++;
        } else {
            print_string("  Status:   FAIL\n");
            print_string("  Ref:      ");
            print_hex32(ref_result);
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
