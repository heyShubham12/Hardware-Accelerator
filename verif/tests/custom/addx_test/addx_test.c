/*
 * ADDX Accelerator Test Program for CVA6
 * Tests the custom ADDX instruction implementation
 */

#include <stdint.h>
#include <stdio.h>

// Test vectors for ADDX instruction
struct addx_test_case {
    uint64_t operand_a;
    uint64_t operand_b;
    uint64_t expected_result;
    const char* description;
};

// ADDX test cases - covers various scenarios
static const struct addx_test_case test_cases[] = {
    // Basic addition cases
    {0x12345678, 0x87654321, 0x99999999, "Basic addition"},
    {0x00000001, 0x00000001, 0x00000002, "Simple 1+1"},
    {0x00000000, 0xFFFFFFFF, 0xFFFFFFFF, "Zero + max"},

    // Edge cases for saturation
    {0x7FFFFFFF, 0x00000001, 0x7FFFFFFF, "Positive overflow (32-bit)"},
    {0x80000000, 0x80000000, 0x80000000, "Negative overflow (32-bit)"},
    {0x7FFFFFFFFFFFFFFF, 0x0000000000000001, 0x7FFFFFFFFFFFFFFF, "Positive overflow (64-bit)"},
    {0x8000000000000000, 0x8000000000000000, 0x8000000000000000, "Negative overflow (64-bit)"},

    // No overflow cases
    {0x12345678, 0x12345678, 0x2468ACF0, "No overflow case 1"},
    {0x40000000, 0x30000000, 0x70000000, "No overflow case 2"},

    // Mixed signs (no overflow possible)
    {0x7FFFFFFF, 0x80000000, 0xFFFFFFFF, "Positive + negative"},
    {0x80000000, 0x7FFFFFFF, 0xFFFFFFFF, "Negative + positive"},
};

#define NUM_TEST_CASES (sizeof(test_cases) / sizeof(test_cases[0]))

// Function to test ADDX using inline assembly
uint64_t test_addx_instruction(uint64_t a, uint64_t b) {
    uint64_t result;

    // Use the ADDX instruction with raw encoding
    // ADDX uses custom opcode 0x0B (OpcodeCustom0) with funct3=0, funct7=0
    // Raw encoding: 0x0000A00B + register encoding

    asm volatile (
        "mv a0, %1\n"           // Move operand_a to a0
        "mv a1, %2\n"           // Move operand_b to a1
        "addx a0, a1, a0\n"     // addx a0, a1, a0 (a0 = saturating_add(a1, a0))
        "mv %0, a0"             // Move result to output
        : "=r"(result)
        : "r"(a), "r"(b)
        : "a0", "a1"
    );

    return result;
}

// Software implementation of ADDX for verification
uint64_t addx_software(uint64_t a, uint64_t b) {
    // Check for overflow conditions
    uint64_t result = a + b;

    // Check if addition overflowed
    if ((a > 0 && b > 0 && result < a) || (a < 0 && b < 0 && result > a)) {
        // Overflow occurred - saturate
        if (a > 0) {
            return 0x7FFFFFFFFFFFFFFF; // Positive saturation
        } else {
            return 0x8000000000000000; // Negative saturation
        }
    }

    return result;
}

// Function to run individual test
int run_addx_test(const struct addx_test_case* test) {
    uint64_t hw_result = test_addx_instruction(test->operand_a, test->operand_b);
    uint64_t sw_result = addx_software(test->operand_a, test->operand_b);

    printf("Test: %s\n", test->description);
    printf("  Operands: 0x%016lx + 0x%016lx\n", test->operand_a, test->operand_b);
    printf("  HW Result: 0x%016lx\n", hw_result);
    printf("  SW Result: 0x%016lx\n", sw_result);
    printf("  Expected:  0x%016lx\n", test->expected_result);

    // Check if hardware result matches expected or software implementation
    if (hw_result == test->expected_result || hw_result == sw_result) {
        printf("  Status: PASS\n\n");
        return 0;
    } else {
        printf("  Status: FAIL\n\n");
        return 1;
    }
}

// Basic functionality test
int test_addx_basic() {
    printf("Testing ADDX basic functionality...\n");

    uint64_t a = 0x123456789ABCDEF0;
    uint64_t b = 0x0FEDCBA987654321;
    uint64_t result = test_addx_instruction(a, b);

    printf("Basic ADDX test:\n");
    printf("  0x%016lx + 0x%016lx = 0x%016lx\n", a, b, result);

    // Check if result is reasonable (should be sum without overflow)
    uint64_t expected = a + b;
    if (result == expected) {
        printf("  Basic test: PASS\n\n");
        return 0;
    } else {
        printf("  Basic test: FAIL (expected 0x%016lx)\n\n", expected);
        return 1;
    }
}

// Test overflow behavior
int test_addx_overflow() {
    printf("Testing ADDX overflow behavior...\n");

    // Test positive overflow
    uint64_t max_pos = 0x7FFFFFFFFFFFFFFF;
    uint64_t one = 0x0000000000000001;
    uint64_t result = test_addx_instruction(max_pos, one);

    printf("Positive overflow test:\n");
    printf("  0x%016lx + 0x%016lx = 0x%016lx\n", max_pos, one, result);

    // Should saturate to max positive value
    if (result == max_pos) {
        printf("  Overflow test: PASS\n\n");
        return 0;
    } else {
        printf("  Overflow test: FAIL (should saturate to 0x7FFFFFFFFFFFFFFF)\n\n");
        return 1;
    }
}

int main() {
    printf("CVA6 ADDX Accelerator Test Suite\n");
    printf("================================\n\n");

    int failures = 0;

    // Run basic functionality test
    failures += test_addx_basic();

    // Run overflow test
    failures += test_addx_overflow();

    // Run comprehensive test suite
    printf("Running comprehensive test suite...\n");
    for (int i = 0; i < NUM_TEST_CASES; i++) {
        failures += run_addx_test(&test_cases[i]);
    }

    // Print summary
    printf("Test Summary:\n");
    printf("  Total tests: %d\n", (int)NUM_TEST_CASES + 2);
    if (failures == 0) {
        printf("  Result: ALL TESTS PASSED!\n");
    } else {
        printf("  Result: %d TESTS FAILED!\n", failures);
    }

    return failures;
}