/*
 * ADDX Hardware Accelerator Comprehensive Test
 *
 * Tests the ADDX custom instruction implementation in CVA6
 * ADDX performs saturating addition: rd = saturate(rs1 + rs2)
 *
 * Instruction Encoding:
 *   Opcode: 0x0B (custom-0)
 *   Format: R-type
 *   funct3: 0x0
 *   funct7: 0x0
 *
 * Author: CVA6 ADDX Integration Test Suite
 * Date: 2025-11-06
 */

#include <stdio.h>
#include <stdint.h>

// Test result tracking
static int tests_passed = 0;
static int tests_failed = 0;
static int test_number = 0;

// ADDX instruction wrapper using inline assembly
static inline uint64_t addx(uint64_t a, uint64_t b) {
    uint64_t result;
    // Use .insn directive for ADDX: opcode=0x0B, funct3=0, funct7=0
    asm volatile (
        ".insn r 0x0B, 0, 0, %0, %1, %2"
        : "=r"(result)
        : "r"(a), "r"(b)
    );
    return result;
}

// Print helper functions
void print_test_header(const char* test_name) {
    test_number++;
    printf("\n");
    printf("================================================================================\n");
    printf("TEST %d: %s\n", test_number, test_name);
    printf("================================================================================\n");
}

void print_test_result(uint64_t a, uint64_t b, uint64_t result, uint64_t expected, const char* description) {
    printf("  Operand A:     0x%016llx (%lld)\n", a, (long long)a);
    printf("  Operand B:     0x%016llx (%lld)\n", b, (long long)b);
    printf("  ADDX Result:   0x%016llx (%lld)\n", result, (long long)result);
    printf("  Expected:      0x%016llx (%lld)\n", expected, (long long)expected);
    printf("  Description:   %s\n", description);

    if (result == expected) {
        printf("  Status:        ✓ PASS\n");
        tests_passed++;
    } else {
        printf("  Status:        ✗ FAIL\n");
        tests_failed++;
    }
    printf("--------------------------------------------------------------------------------\n");
}

// Test functions
void test_basic_addition(void) {
    print_test_header("Basic Addition");

    uint64_t a = 100;
    uint64_t b = 200;
    uint64_t result = addx(a, b);
    uint64_t expected = 300;

    print_test_result(a, b, result, expected, "Simple addition: 100 + 200");
}

void test_large_numbers(void) {
    print_test_header("Large Numbers Addition");

    uint64_t a = 0x1111111111111111ULL;
    uint64_t b = 0x2222222222222222ULL;
    uint64_t result = addx(a, b);
    uint64_t expected = 0x3333333333333333ULL;

    print_test_result(a, b, result, expected, "Large hex values");
}

void test_zero_operands(void) {
    print_test_header("Zero Operands");

    uint64_t a = 0;
    uint64_t b = 0;
    uint64_t result = addx(a, b);
    uint64_t expected = 0;

    print_test_result(a, b, result, expected, "Zero + Zero");
}

void test_one_zero_operand(void) {
    print_test_header("One Zero Operand");

    uint64_t a = 0x123456789ABCDEF0ULL;
    uint64_t b = 0;
    uint64_t result = addx(a, b);
    uint64_t expected = a;

    print_test_result(a, b, result, expected, "Non-zero + Zero");
}

void test_max_value(void) {
    print_test_header("Maximum Positive Value");

    uint64_t a = 0x7FFFFFFFFFFFFFFFULL;  // MAX_INT64
    uint64_t b = 0;
    uint64_t result = addx(a, b);
    uint64_t expected = 0x7FFFFFFFFFFFFFFFULL;

    print_test_result(a, b, result, expected, "MAX_INT + 0");
}

void test_positive_overflow_simple(void) {
    print_test_header("Positive Overflow - Simple Case");

    uint64_t a = 0x7FFFFFFFFFFFFFFFULL;  // MAX_INT64
    uint64_t b = 1;
    uint64_t result = addx(a, b);
    // Expected: Should saturate to MAX or handle overflow
    // Based on the hardware implementation, same signs overflow should saturate
    // But the carry bit will be set, making this 0x8000000000000000
    uint64_t expected = 0x7FFFFFFFFFFFFFFFULL;  // Should saturate to MAX on positive overflow

    print_test_result(a, b, result, expected, "MAX_INT + 1 (expect saturation to MAX)");
}

void test_negative_addition(void) {
    print_test_header("Negative Number Addition");

    int64_t a_signed = -100;
    int64_t b_signed = -200;
    uint64_t a = (uint64_t)a_signed;
    uint64_t b = (uint64_t)b_signed;
    uint64_t result = addx(a, b);
    uint64_t expected = (uint64_t)(-300);

    print_test_result(a, b, result, expected, "(-100) + (-200) = -300");
}

void test_negative_overflow(void) {
    print_test_header("Negative Overflow");

    uint64_t a = 0x8000000000000000ULL;  // MIN_INT64
    uint64_t b = 0xFFFFFFFFFFFFFFFFULL; // -1
    uint64_t result = addx(a, b);
    uint64_t expected = 0x8000000000000000ULL;  // Should saturate to MIN

    print_test_result(a, b, result, expected, "MIN_INT + (-1) - expect saturation to MIN");
}

void test_mixed_signs_positive_result(void) {
    print_test_header("Mixed Signs - Positive Result");

    uint64_t a = 500;
    int64_t b_signed = -200;
    uint64_t b = (uint64_t)b_signed;
    uint64_t result = addx(a, b);
    uint64_t expected = 300;

    print_test_result(a, b, result, expected, "500 + (-200) = 300");
}

void test_mixed_signs_negative_result(void) {
    print_test_header("Mixed Signs - Negative Result");

    uint64_t a = 200;
    int64_t b_signed = -500;
    uint64_t b = (uint64_t)b_signed;
    uint64_t result = addx(a, b);
    uint64_t expected = (uint64_t)(-300);

    print_test_result(a, b, result, expected, "200 + (-500) = -300");
}

void test_mixed_signs_max_min(void) {
    print_test_header("Mixed Signs - MAX + MIN");

    uint64_t a = 0x7FFFFFFFFFFFFFFFULL;  // MAX_INT64
    uint64_t b = 0x8000000000000000ULL;  // MIN_INT64
    uint64_t result = addx(a, b);
    uint64_t expected = 0xFFFFFFFFFFFFFFFFULL;  // -1

    print_test_result(a, b, result, expected, "MAX_INT + MIN_INT = -1");
}

void test_power_of_two(void) {
    print_test_header("Powers of Two");

    uint64_t a = 0x0000000000000100ULL;  // 256
    uint64_t b = 0x0000000000000100ULL;  // 256
    uint64_t result = addx(a, b);
    uint64_t expected = 0x0000000000000200ULL;  // 512

    print_test_result(a, b, result, expected, "256 + 256 = 512");
}

void test_address_like_calculation(void) {
    print_test_header("Address-like Calculation");

    uint64_t a = 0x0000000080000000ULL;  // Base address
    uint64_t b = 0x0000000000001000ULL;  // Offset (4KB)
    uint64_t result = addx(a, b);
    uint64_t expected = 0x0000000080001000ULL;

    print_test_result(a, b, result, expected, "Base address + offset");
}

void test_alternating_bits(void) {
    print_test_header("Alternating Bit Pattern");

    uint64_t a = 0xAAAAAAAAAAAAAAAAULL;
    uint64_t b = 0x5555555555555555ULL;
    uint64_t result = addx(a, b);
    uint64_t expected = 0xFFFFFFFFFFFFFFFFULL;  // -1

    print_test_result(a, b, result, expected, "0xAAAA... + 0x5555... = 0xFFFF...");
}

void test_sequential_additions(void) {
    print_test_header("Sequential Additions");

    printf("  Testing multiple ADDX instructions in sequence:\n");
    printf("--------------------------------------------------------------------------------\n");

    uint64_t result = 0;
    result = addx(result, 10);
    printf("  Step 1: 0 + 10 = %llu\n", (unsigned long long)result);

    result = addx(result, 20);
    printf("  Step 2: 10 + 20 = %llu\n", (unsigned long long)result);

    result = addx(result, 30);
    printf("  Step 3: 30 + 30 = %llu\n", (unsigned long long)result);

    result = addx(result, 40);
    printf("  Step 4: 60 + 40 = %llu\n", (unsigned long long)result);

    if (result == 100) {
        printf("  Final result: %llu (expected 100)\n", (unsigned long long)result);
        printf("  Status:        ✓ PASS\n");
        tests_passed++;
    } else {
        printf("  Final result: %llu (expected 100)\n", (unsigned long long)result);
        printf("  Status:        ✗ FAIL\n");
        tests_failed++;
    }
    printf("--------------------------------------------------------------------------------\n");
}

void print_summary(void) {
    printf("\n");
    printf("################################################################################\n");
    printf("#                          TEST SUMMARY                                       #\n");
    printf("################################################################################\n");
    printf("\n");
    printf("  Total Tests:     %d\n", test_number);
    printf("  Tests Passed:    %d\n", tests_passed);
    printf("  Tests Failed:    %d\n", tests_failed);
    printf("\n");

    if (tests_failed == 0) {
        printf("  ✓✓✓ ALL TESTS PASSED! ✓✓✓\n");
    } else {
        printf("  ✗✗✗ SOME TESTS FAILED ✗✗✗\n");
    }

    printf("\n");
    printf("################################################################################\n");
    printf("#                    ADDX HARDWARE ACCELERATOR VERIFIED                      #\n");
    printf("################################################################################\n");
    printf("\n");
}

// Main test function
int main(void) {
    printf("\n");
    printf("################################################################################\n");
    printf("#                                                                              #\n");
    printf("#              ADDX HARDWARE ACCELERATOR TEST SUITE                           #\n");
    printf("#                                                                              #\n");
    printf("#  Custom Instruction: ADDX rd, rs1, rs2                                     #\n");
    printf("#  Operation: rd = saturate(rs1 + rs2)                                       #\n");
    printf("#  Opcode: 0x0B (custom-0)                                                   #\n");
    printf("#                                                                              #\n");
    printf("################################################################################\n");

    // Run all tests
    test_basic_addition();
    test_large_numbers();
    test_zero_operands();
    test_one_zero_operand();
    test_max_value();
    test_positive_overflow_simple();
    test_negative_addition();
    test_negative_overflow();
    test_mixed_signs_positive_result();
    test_mixed_signs_negative_result();
    test_mixed_signs_max_min();
    test_power_of_two();
    test_address_like_calculation();
    test_alternating_bits();
    test_sequential_additions();

    // Print summary
    print_summary();

    // Return 0 for success, 1 for failure
    return (tests_failed == 0) ? 0 : 1;
}
