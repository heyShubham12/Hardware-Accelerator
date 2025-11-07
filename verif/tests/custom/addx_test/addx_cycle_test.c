/*
 * ADDX Instruction Cycle Count Test
 * Tests the custom ADDX instruction with cycle counting
 * Prints operands, results, and cycle counts
 */

#include <stdint.h>
#include <stdio.h>

// Read cycle counter (RISC-V CSR)
static inline uint64_t read_cycles(void) {
    uint64_t cycles;
    #ifdef __riscv_xlen
        #if __riscv_xlen == 32
            uint32_t cycles_lo, cycles_hi, cycles_hi_check;
            // Read 64-bit cycle counter on 32-bit system
            do {
                asm volatile ("csrr %0, cycleh" : "=r"(cycles_hi));
                asm volatile ("csrr %0, cycle" : "=r"(cycles_lo));
                asm volatile ("csrr %0, cycleh" : "=r"(cycles_hi_check));
            } while (cycles_hi != cycles_hi_check);
            cycles = ((uint64_t)cycles_hi << 32) | cycles_lo;
        #else
            // 64-bit system
            asm volatile ("csrr %0, cycle" : "=r"(cycles));
        #endif
    #else
        // Fallback: assume 32-bit
        uint32_t cycles_lo, cycles_hi, cycles_hi_check;
        do {
            asm volatile ("csrr %0, cycleh" : "=r"(cycles_hi));
            asm volatile ("csrr %0, cycle" : "=r"(cycles_lo));
            asm volatile ("csrr %0, cycleh" : "=r"(cycles_hi_check));
        } while (cycles_hi != cycles_hi_check);
        cycles = ((uint64_t)cycles_hi << 32) | cycles_lo;
    #endif
    return cycles;
}

// Read instruction counter (RISC-V CSR)
static inline uint64_t read_instret(void) {
    uint64_t instret;
    #ifdef __riscv_xlen
        #if __riscv_xlen == 32
            uint32_t instret_lo, instret_hi, instret_hi_check;
            do {
                asm volatile ("csrr %0, instreth" : "=r"(instret_hi));
                asm volatile ("csrr %0, instret" : "=r"(instret_lo));
                asm volatile ("csrr %0, instreth" : "=r"(instret_hi_check));
            } while (instret_hi != instret_hi_check);
            instret = ((uint64_t)instret_hi << 32) | instret_lo;
        #else
            asm volatile ("csrr %0, instret" : "=r"(instret));
        #endif
    #else
        // Fallback: assume 32-bit
        uint32_t instret_lo, instret_hi, instret_hi_check;
        do {
            asm volatile ("csrr %0, instreth" : "=r"(instret_hi));
            asm volatile ("csrr %0, instret" : "=r"(instret_lo));
            asm volatile ("csrr %0, instreth" : "=r"(instret_hi_check));
        } while (instret_hi != instret_hi_check);
        instret = ((uint64_t)instret_hi << 32) | instret_lo;
    #endif
    return instret;
}

// Test ADDX instruction and measure cycles
void test_addx_with_cycles(uint64_t a, uint64_t b, const char* description) {
    uint64_t result;
    uint64_t start_cycles, end_cycles, cycle_count;
    uint64_t start_instret, end_instret, inst_count;

    printf("========================================\n");
    printf("Test: %s\n", description);
    printf("----------------------------------------\n");
    printf("Operand A: 0x%016lx (%ld)\n", a, (int64_t)a);
    printf("Operand B: 0x%016lx (%ld)\n", b, (int64_t)b);

    // Read start counters
    start_cycles = read_cycles();
    start_instret = read_instret();

    // Execute ADDX instruction
    asm volatile (
        "mv a0, %1\n"           // Move operand_a to a0
        "mv a1, %2\n"           // Move operand_b to a1
        "addx a0, a1, a0\n"     // ADDX: a0 = saturating_add(a1, a0)
        "mv %0, a0"             // Move result to output
        : "=r"(result)
        : "r"(a), "r"(b)
        : "a0", "a1"
    );

    // Read end counters
    end_cycles = read_cycles();
    end_instret = read_instret();

    // Calculate counts
    cycle_count = end_cycles - start_cycles;
    inst_count = end_instret - start_instret;

    // Print results
    printf("Result:    0x%016lx (%ld)\n", result, (int64_t)result);
    printf("----------------------------------------\n");
    printf("Cycles:        %lu\n", cycle_count);
    printf("Instructions:  %lu\n", inst_count);
    printf("CPI:           %.2f\n", (float)cycle_count / (float)inst_count);
    printf("========================================\n\n");
}

// Test ADDX with minimal overhead (isolated instruction)
void test_addx_isolated(uint64_t a, uint64_t b) {
    uint64_t result;
    uint64_t start_cycles, end_cycles;

    printf("========================================\n");
    printf("ISOLATED ADDX TEST (Minimal Overhead)\n");
    printf("----------------------------------------\n");
    printf("Operands: 0x%lx + 0x%lx\n", a, b);

    // Warm up
    asm volatile (
        "addx %0, %1, %2\n"
        : "=r"(result)
        : "r"(a), "r"(b)
    );

    // Measure
    start_cycles = read_cycles();
    asm volatile (
        "addx %0, %1, %2\n"
        : "=r"(result)
        : "r"(a), "r"(b)
    );
    end_cycles = read_cycles();

    printf("Result:   0x%lx\n", result);
    printf("Cycles:   %lu (including measurement overhead)\n", end_cycles - start_cycles);
    printf("========================================\n\n");
}

int main() {
    printf("\n");
    printf("╔════════════════════════════════════════╗\n");
    printf("║  CVA6 ADDX CYCLE COUNT TEST SUITE     ║\n");
    printf("╚════════════════════════════════════════╝\n");
    printf("\n");

    // Test 1: Simple addition (no overflow)
    test_addx_with_cycles(0x0000000000000010, 0x0000000000000020,
                          "Simple Addition (16 + 32)");

    // Test 2: Larger values (no overflow)
    test_addx_with_cycles(0x0000000012345678, 0x0000000087654321,
                          "Large Addition (no overflow)");

    // Test 3: Positive overflow (should saturate)
    test_addx_with_cycles(0x7FFFFFFFFFFFFFFF, 0x0000000000000001,
                          "Positive Overflow (saturate to max)");

    // Test 4: Negative overflow (should saturate)
    test_addx_with_cycles(0x8000000000000000, 0x8000000000000000,
                          "Negative Overflow (saturate to min)");

    // Test 5: Mixed signs (no overflow)
    test_addx_with_cycles(0x7FFFFFFFFFFFFFFF, 0x8000000000000000,
                          "Mixed Signs (no overflow)");

    // Test 6: Zero addition
    test_addx_with_cycles(0x0000000000000000, 0x0000000000000000,
                          "Zero Addition");

    // Test 7: Small positive values
    test_addx_with_cycles(0x0000000000000001, 0x0000000000000001,
                          "Small Values (1 + 1)");

    // Test 8: Edge case - max positive + negative
    test_addx_with_cycles(0x7FFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF,
                          "Max Positive + (-1)");

    // Isolated test
    test_addx_isolated(0x0000000000000100, 0x0000000000000200);

    // Performance comparison summary
    printf("╔════════════════════════════════════════╗\n");
    printf("║          PERFORMANCE SUMMARY           ║\n");
    printf("╚════════════════════════════════════════╝\n");
    printf("\n");
    printf("ADDX Instruction Performance:\n");
    printf("  - Expected latency: 1-2 cycles\n");
    printf("  - Saturating addition with overflow detection\n");
    printf("  - Custom opcode: 0x0B (OpcodeCustom0)\n");
    printf("  - Encoding: R-type format\n");
    printf("\n");
    printf("Note: Cycle counts include measurement overhead\n");
    printf("      (CSR reads, register moves, etc.)\n");
    printf("\n");

    // Calibration test
    printf("========================================\n");
    printf("CALIBRATION: Measure overhead\n");
    printf("----------------------------------------\n");
    uint64_t cal_start = read_cycles();
    uint64_t cal_end = read_cycles();
    printf("Cycle counter read overhead: %lu cycles\n", cal_end - cal_start);
    printf("========================================\n");
    printf("\n");

    printf("╔════════════════════════════════════════╗\n");
    printf("║         ALL TESTS COMPLETED!           ║\n");
    printf("╚════════════════════════════════════════╝\n");

    return 0;
}
