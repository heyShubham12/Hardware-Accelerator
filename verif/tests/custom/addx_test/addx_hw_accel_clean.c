/*
 * ADDX Hardware Accelerator Clean Test
 * Minimal output version - shows only essential test results
 *
 * Tests the ADDX custom instruction implementation in CVA6
 * ADDX performs saturating addition: rd = saturate(rs1 + rs2)
 *
 * Instruction Encoding: Opcode 0x0B (custom-0)
 */

#include <stdio.h>
#include <stdint.h>

// Test result tracking
static int tests_passed = 0;
static int tests_failed = 0;
static int test_number = 0;

// ADDX instruction wrapper
static inline uint64_t addx(uint64_t a, uint64_t b) {
    uint64_t result;
    asm volatile (
        ".insn r 0x0B, 0, 0, %0, %1, %2"
        : "=r"(result)
        : "r"(a), "r"(b)
    );
    return result;
}

// Simplified test function
void run_test(const char* name, uint64_t a, uint64_t b, uint64_t expected) {
    test_number++;
    uint64_t result = addx(a, b);

    if (result == expected) {
        printf("✓ Test %d: %s - PASS\n", test_number, name);
        tests_passed++;
    } else {
        printf("✗ Test %d: %s - FAIL (got 0x%llx, expected 0x%llx)\n",
               test_number, name, result, expected);
        tests_failed++;
    }
}

int main(void) {
    printf("\n");
    printf("ADDX Hardware Accelerator Test Suite\n");
    printf("=====================================\n\n");

    // Test cases
    run_test("Basic Addition", 100, 200, 300);
    run_test("Large Numbers", 0x1111111111111111ULL, 0x2222222222222222ULL, 0x3333333333333333ULL);
    run_test("Zero + Zero", 0, 0, 0);
    run_test("Value + Zero", 0x123456789ABCDEF0ULL, 0, 0x123456789ABCDEF0ULL);
    run_test("MAX_INT + 0", 0x7FFFFFFFFFFFFFFFULL, 0, 0x7FFFFFFFFFFFFFFFULL);
    run_test("Positive Overflow", 0x7FFFFFFFFFFFFFFFULL, 1, 0x7FFFFFFFFFFFFFFFULL);

    int64_t neg100 = -100, neg200 = -200;
    run_test("Negative Addition", (uint64_t)neg100, (uint64_t)neg200, (uint64_t)(-300));

    run_test("Negative Overflow", 0x8000000000000000ULL, 0xFFFFFFFFFFFFFFFFULL, 0x8000000000000000ULL);
    run_test("Mixed Signs +", 500, (uint64_t)(-200), 300);
    run_test("Mixed Signs -", 200, (uint64_t)(-500), (uint64_t)(-300));
    run_test("MAX + MIN", 0x7FFFFFFFFFFFFFFFULL, 0x8000000000000000ULL, 0xFFFFFFFFFFFFFFFFULL);
    run_test("Power of Two", 256, 256, 512);
    run_test("Address Calc", 0x0000000080000000ULL, 0x0000000000001000ULL, 0x0000000080001000ULL);
    run_test("Alternating Bits", 0xAAAAAAAAAAAAAAAAULL, 0x5555555555555555ULL, 0xFFFFFFFFFFFFFFFFULL);

    // Sequential test
    test_number++;
    uint64_t seq_result = 0;
    seq_result = addx(seq_result, 10);
    seq_result = addx(seq_result, 20);
    seq_result = addx(seq_result, 30);
    seq_result = addx(seq_result, 40);

    if (seq_result == 100) {
        printf("✓ Test %d: Sequential Additions - PASS\n", test_number);
        tests_passed++;
    } else {
        printf("✗ Test %d: Sequential Additions - FAIL\n", test_number);
        tests_failed++;
    }

    // Summary
    printf("\n");
    printf("Test Summary\n");
    printf("============\n");
    printf("Total:  %d\n", test_number);
    printf("Passed: %d\n", tests_passed);
    printf("Failed: %d\n\n", tests_failed);

    if (tests_failed == 0) {
        printf("✓✓✓ ALL TESTS PASSED ✓✓✓\n\n");
        return 0;
    } else {
        printf("✗✗✗ SOME TESTS FAILED ✗✗✗\n\n");
        return 1;
    }
}
