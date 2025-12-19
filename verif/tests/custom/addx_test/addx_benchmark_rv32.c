/*
 * ADDX Performance Benchmark for CVA6 RV32
 *
 * This benchmark compares the performance of:
 * 1. ADDX hardware accelerator (single custom instruction)
 * 2. Software-based saturating addition (multiple standard instructions)
 *
 * Measures: cycle count, instruction count, speedup
 *
 * Author: CVA6 ADDX Performance Analysis
 * Date: 2025-11-18
 */

#include <stdint.h>

// Print functions for bare metal
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

void print_dec(uint32_t val) {
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

// Read cycle counter (mcycle CSR)
static inline uint32_t read_cycles(void) {
    uint32_t cycles;
    asm volatile ("csrr %0, mcycle" : "=r"(cycles));
    return cycles;
}

// Read instructions retired counter (minstret CSR)
static inline uint32_t read_instret(void) {
    uint32_t instret;
    asm volatile ("csrr %0, minstret" : "=r"(instret));
    return instret;
}

// Hardware ADDX instruction
static inline uint32_t addx_hw(uint32_t a, uint32_t b) {
    uint32_t result;
    asm volatile (
        ".insn r 0x0B, 0, 0, %0, %1, %2"
        : "=r"(result)
        : "r"(a), "r"(b)
    );
    return result;
}

// Software saturating addition (multiple instructions)
static inline uint32_t addx_sw(uint32_t a, uint32_t b) {
    uint32_t result = a + b;
    int32_t sa = (int32_t)a;
    int32_t sb = (int32_t)b;
    int32_t sr = (int32_t)result;

    // Both positive and result is negative -> positive overflow
    if (sa > 0 && sb > 0 && sr < 0) {
        return 0x7FFFFFFF;
    }
    // Both negative and result is positive -> negative overflow
    else if (sa < 0 && sb < 0 && sr > 0) {
        return 0x80000000;
    }

    return result;
}

// Test data arrays
#define BENCHMARK_SIZE 1000

uint32_t test_data_a[BENCHMARK_SIZE];
uint32_t test_data_b[BENCHMARK_SIZE];
uint32_t results_hw[BENCHMARK_SIZE];
uint32_t results_sw[BENCHMARK_SIZE];

// Initialize test data with diverse values
void init_test_data(void) {
    for (int i = 0; i < BENCHMARK_SIZE; i++) {
        // Create diverse test patterns
        uint32_t seed = i * 1103515245 + 12345;
        test_data_a[i] = seed;
        test_data_b[i] = (seed >> 16) | (seed << 16);

        // Mix in some overflow cases
        if (i % 10 == 0) {
            test_data_a[i] = 0x7FFFFFFF;  // Max positive
            test_data_b[i] = 0x00000001;  // Will overflow
        } else if (i % 10 == 5) {
            test_data_a[i] = 0x80000000;  // Min negative
            test_data_b[i] = 0x80000000;  // Will underflow
        }
    }
}

int main() {
    uint32_t hw_cycles_start, hw_cycles_end, hw_cycles;
    uint32_t hw_instret_start, hw_instret_end, hw_instret;
    uint32_t sw_cycles_start, sw_cycles_end, sw_cycles;
    uint32_t sw_instret_start, sw_instret_end, sw_instret;

    print_string("\n");
    print_string("========================================\n");
    print_string("  ADDX Performance Benchmark (RV32)\n");
    print_string("========================================\n");
    print_string("\n");

    // Initialize test data
    print_string("Initializing test data...\n");
    init_test_data();
    print_string("Test data size: ");
    print_dec(BENCHMARK_SIZE);
    print_string(" operations\n\n");

    // ==========================================
    // Benchmark 1: Hardware ADDX Accelerator
    // ==========================================
    print_string("Running Hardware ADDX Benchmark...\n");

    hw_cycles_start = read_cycles();
    hw_instret_start = read_instret();

    // Perform BENCHMARK_SIZE ADDX operations using hardware
    for (int i = 0; i < BENCHMARK_SIZE; i++) {
        results_hw[i] = addx_hw(test_data_a[i], test_data_b[i]);
    }

    hw_cycles_end = read_cycles();
    hw_instret_end = read_instret();

    hw_cycles = hw_cycles_end - hw_cycles_start;
    hw_instret = hw_instret_end - hw_instret_start;

    print_string("  Cycles:       ");
    print_dec(hw_cycles);
    print_string("\n");
    print_string("  Instructions: ");
    print_dec(hw_instret);
    print_string("\n\n");

    // ==========================================
    // Benchmark 2: Software Implementation
    // ==========================================
    print_string("Running Software Implementation Benchmark...\n");

    sw_cycles_start = read_cycles();
    sw_instret_start = read_instret();

    // Perform BENCHMARK_SIZE saturating additions using software
    for (int i = 0; i < BENCHMARK_SIZE; i++) {
        results_sw[i] = addx_sw(test_data_a[i], test_data_b[i]);
    }

    sw_cycles_end = read_cycles();
    sw_instret_end = read_instret();

    sw_cycles = sw_cycles_end - sw_cycles_start;
    sw_instret = sw_instret_end - sw_instret_start;

    print_string("  Cycles:       ");
    print_dec(sw_cycles);
    print_string("\n");
    print_string("  Instructions: ");
    print_dec(sw_instret);
    print_string("\n\n");

    // ==========================================
    // Verify Correctness
    // ==========================================
    print_string("Verifying correctness...\n");
    int mismatches = 0;
    for (int i = 0; i < BENCHMARK_SIZE; i++) {
        if (results_hw[i] != results_sw[i]) {
            mismatches++;
        }
    }

    if (mismatches == 0) {
        print_string("  Result: ALL OUTPUTS MATCH!\n\n");
    } else {
        print_string("  Result: ");
        print_dec(mismatches);
        print_string(" MISMATCHES FOUND!\n\n");
    }

    // ==========================================
    // Calculate and Display Speedup
    // ==========================================
    print_string("========================================\n");
    print_string("  Performance Analysis\n");
    print_string("========================================\n");
    print_string("\n");

    // Cycles per operation
    print_string("Cycles per operation:\n");
    print_string("  Hardware: ");
    print_dec(hw_cycles / BENCHMARK_SIZE);
    print_string(".");
    print_dec((hw_cycles * 100 / BENCHMARK_SIZE) % 100);
    print_string("\n");

    print_string("  Software: ");
    print_dec(sw_cycles / BENCHMARK_SIZE);
    print_string(".");
    print_dec((sw_cycles * 100 / BENCHMARK_SIZE) % 100);
    print_string("\n\n");

    // Instructions per operation
    print_string("Instructions per operation:\n");
    print_string("  Hardware: ");
    print_dec(hw_instret / BENCHMARK_SIZE);
    print_string(".");
    print_dec((hw_instret * 100 / BENCHMARK_SIZE) % 100);
    print_string("\n");

    print_string("  Software: ");
    print_dec(sw_instret / BENCHMARK_SIZE);
    print_string(".");
    print_dec((sw_instret * 100 / BENCHMARK_SIZE) % 100);
    print_string("\n\n");

    // Speedup calculation (software_time / hardware_time)
    uint32_t cycle_speedup_int = sw_cycles / hw_cycles;
    uint32_t cycle_speedup_frac = ((sw_cycles * 100) / hw_cycles) % 100;

    uint32_t instr_reduction = ((sw_instret - hw_instret) * 100) / sw_instret;

    print_string("Speedup Metrics:\n");
    print_string("  Cycle Speedup:        ");
    print_dec(cycle_speedup_int);
    print_string(".");
    print_dec(cycle_speedup_frac);
    print_string("x\n");

    print_string("  Instruction Reduction: ");
    print_dec(instr_reduction);
    print_string("%\n");

    print_string("\n");

    // Detailed breakdown
    print_string("========================================\n");
    print_string("  Detailed Results\n");
    print_string("========================================\n");
    print_string("\n");

    print_string("Hardware ADDX Accelerator:\n");
    print_string("  Total Cycles:       ");
    print_dec(hw_cycles);
    print_string("\n");
    print_string("  Total Instructions: ");
    print_dec(hw_instret);
    print_string("\n");
    print_string("  CPI:                ");
    print_dec(hw_cycles / hw_instret);
    print_string(".");
    print_dec((hw_cycles * 100 / hw_instret) % 100);
    print_string("\n\n");

    print_string("Software Implementation:\n");
    print_string("  Total Cycles:       ");
    print_dec(sw_cycles);
    print_string("\n");
    print_string("  Total Instructions: ");
    print_dec(sw_instret);
    print_string("\n");
    print_string("  CPI:                ");
    print_dec(sw_cycles / sw_instret);
    print_string(".");
    print_dec((sw_cycles * 100 / sw_instret) % 100);
    print_string("\n\n");

    print_string("Performance Improvement:\n");
    print_string("  Cycles Saved:       ");
    print_dec(sw_cycles - hw_cycles);
    print_string("\n");
    print_string("  Instructions Saved: ");
    print_dec(sw_instret - hw_instret);
    print_string("\n\n");

    print_string("========================================\n");
    print_string("  Benchmark Complete!\n");
    print_string("========================================\n");
    print_string("\n");

    return (mismatches == 0) ? 0 : 1;
}
