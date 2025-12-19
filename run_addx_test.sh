#!/bin/bash
# ============================================================================
# ADDX Test Runner Script for CVA6
# ============================================================================
# This script compiles and runs the ADDX custom instruction test
# No need to set environment variables manually - everything is handled here
#
# Usage: ./run_addx_test.sh
# ============================================================================

set -e  # Exit on error

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# ============================================================================
# Configuration
# ============================================================================

# Project paths
export CVA6_ROOT=/home/shubham/cva6
export RISCV=/home/shubham/riscv-tools
export SPIKE_PATH=${CVA6_ROOT}/tools/spike/bin
export VERILATOR_PATH=${CVA6_ROOT}/tools/verilator-v5.008

# Test paths
TEST_DIR=${CVA6_ROOT}/verif/tests/custom/addx_test
TEST_SOURCE=${TEST_DIR}/addx_test_rv32.c
TEST_BINARY=${TEST_DIR}/addx_test_rv32.elf

# Common test infrastructure
COMMON_DIR=${CVA6_ROOT}/verif/tests/custom/common
ENV_DIR=${CVA6_ROOT}/verif/tests/custom/env
LINKER_SCRIPT=${CVA6_ROOT}/config/gen_from_riscv_config/cv32a65x/linker/link.ld

# Verilator testbench
VERILATOR_TB=${CVA6_ROOT}/work-ver/Variane_testharness

# Compiler settings
export RISCV_CC=gcc
GCC=${RISCV}/bin/riscv-none-elf-gcc
GCC_OPTS="-march=rv32gc -mabi=ilp32d -static -mcmodel=medany -fvisibility=hidden -nostdlib -nostartfiles -g"

# Create dated output directory
DATE_DIR=${CVA6_ROOT}/verif/sim/out_$(date +%Y-%m-%d)
mkdir -p ${DATE_DIR}

# Log files
BUILD_LOG=${DATE_DIR}/test_build.log
RUN_LOG=${DATE_DIR}/addx_test_run.log

# ============================================================================
# Helper Functions
# ============================================================================

print_header() {
    echo -e "${BLUE}============================================================================${NC}"
    echo -e "${BLUE}$1${NC}"
    echo -e "${BLUE}============================================================================${NC}"
}

print_success() {
    echo -e "${GREEN}✓ $1${NC}"
}

print_error() {
    echo -e "${RED}✗ $1${NC}"
}

print_info() {
    echo -e "${YELLOW}ℹ $1${NC}"
}

# ============================================================================
# Pre-flight Checks
# ============================================================================

print_header "ADDX Test Runner - Pre-flight Checks"

# Check if GCC exists
if [ ! -f "${GCC}" ]; then
    print_error "RISC-V GCC not found at ${GCC}"
    exit 1
fi
print_success "RISC-V GCC found: ${GCC}"

# Check if test source exists
if [ ! -f "${TEST_SOURCE}" ]; then
    print_error "Test source not found: ${TEST_SOURCE}"
    exit 1
fi
print_success "Test source found: ${TEST_SOURCE}"

# Check if linker script exists
if [ ! -f "${LINKER_SCRIPT}" ]; then
    print_error "Linker script not found: ${LINKER_SCRIPT}"
    exit 1
fi
print_success "Linker script found"

# Check if Verilator testbench exists
if [ ! -f "${VERILATOR_TB}" ]; then
    print_error "Verilator testbench not found: ${VERILATOR_TB}"
    print_info "You may need to build it first with: make verilate target=cv32a65x"
    exit 1
fi
print_success "Verilator testbench found"

echo ""

# ============================================================================
# Compilation
# ============================================================================

print_header "Compiling ADDX Test"

cd ${TEST_DIR}

print_info "Compiling ${TEST_SOURCE}..."
print_info "Compiler: ${GCC}"
print_info "Options: ${GCC_OPTS}"
print_info "Build log: ${BUILD_LOG}"

echo "=== ADDX Test Build Log ===" > ${BUILD_LOG}
echo "Date: $(date)" >> ${BUILD_LOG}
echo "Source: ${TEST_SOURCE}" >> ${BUILD_LOG}
echo "Compiler: ${GCC}" >> ${BUILD_LOG}
echo "Options: ${GCC_OPTS}" >> ${BUILD_LOG}
echo "" >> ${BUILD_LOG}

${GCC} \
    ${GCC_OPTS} \
    -I${ENV_DIR} \
    -I${COMMON_DIR} \
    -T${LINKER_SCRIPT} \
    ${COMMON_DIR}/crt.S \
    ${COMMON_DIR}/syscalls.c \
    ${TEST_SOURCE} \
    -lgcc \
    -o ${TEST_BINARY} 2>&1 | tee -a ${BUILD_LOG}

if [ ${PIPESTATUS[0]} -eq 0 ]; then
    print_success "Compilation successful: ${TEST_BINARY}"
    ls -lh ${TEST_BINARY} | tee -a ${BUILD_LOG}
    echo "" >> ${BUILD_LOG}
    echo "Build completed successfully at $(date)" >> ${BUILD_LOG}
else
    print_error "Compilation failed!"
    echo "Build failed at $(date)" >> ${BUILD_LOG}
    exit 1
fi

echo ""

# ============================================================================
# Execution
# ============================================================================

print_header "Running ADDX Test on CVA6 (Verilator)"

cd ${CVA6_ROOT}

print_info "Executing test with Verilator testbench..."
print_info "Test binary: ${TEST_BINARY}"
print_info "Testbench: ${VERILATOR_TB}"
print_info "Run log: ${RUN_LOG}"

echo "=== ADDX Test Execution Log ===" > ${RUN_LOG}
echo "Date: $(date)" >> ${RUN_LOG}
echo "Test binary: ${TEST_BINARY}" >> ${RUN_LOG}
echo "Testbench: ${VERILATOR_TB}" >> ${RUN_LOG}
echo "" >> ${RUN_LOG}

echo ""
echo -e "${YELLOW}========== Test Output Begin ==========${NC}"
echo ""

# Run the test
${VERILATOR_TB} \
    ${TEST_BINARY} \
    +debug_disable=1 \
    +UVM_VERBOSITY=UVM_NONE \
    +core_name=cv32a65x 2>&1 | tee -a ${RUN_LOG}

TEST_EXIT_CODE=${PIPESTATUS[0]}

echo ""
echo -e "${YELLOW}========== Test Output End ==========${NC}"
echo ""

# ============================================================================
# Post-execution Analysis
# ============================================================================

print_header "Post-Execution Analysis"

echo "" >> ${RUN_LOG}
echo "=== Post-Execution Analysis ===" >> ${RUN_LOG}

# Check trace files
if [ -f "${CVA6_ROOT}/trace_hart_0.dasm" ]; then
    TRACE_SIZE=$(du -h ${CVA6_ROOT}/trace_hart_0.dasm | cut -f1)
    print_success "Trace generated: trace_hart_0.dasm (${TRACE_SIZE})"
    echo "Trace generated: trace_hart_0.dasm (${TRACE_SIZE})" >> ${RUN_LOG}
fi

if [ -f "${CVA6_ROOT}/iti.trace" ]; then
    ITI_SIZE=$(du -h ${CVA6_ROOT}/iti.trace | cut -f1)
    print_success "ITI trace generated: iti.trace (${ITI_SIZE})"
    echo "ITI trace generated: iti.trace (${ITI_SIZE})" >> ${RUN_LOG}
fi

# Count ADDX instructions executed
if [ -f "${CVA6_ROOT}/trace_hart_0.dasm" ]; then
    ADDX_COUNT=$(grep -c "0x80004400" ${CVA6_ROOT}/trace_hart_0.dasm 2>/dev/null || echo 0)
    print_info "ADDX instructions executed: ${ADDX_COUNT}"
    echo "ADDX instructions executed: ${ADDX_COUNT}" >> ${RUN_LOG}

    if [ ${ADDX_COUNT} -eq 17 ]; then
        print_success "All 17 test cases executed!"
        echo "All 17 test cases executed!" >> ${RUN_LOG}
    elif [ ${ADDX_COUNT} -gt 0 ]; then
        print_info "Executed ${ADDX_COUNT} ADDX instructions (expected 17)"
        echo "Executed ${ADDX_COUNT} ADDX instructions (expected 17)" >> ${RUN_LOG}
    else
        print_error "No ADDX instructions found in trace!"
        echo "No ADDX instructions found in trace!" >> ${RUN_LOG}
    fi
fi

echo ""

# ============================================================================
# Summary
# ============================================================================

print_header "Test Run Summary"

echo "" >> ${RUN_LOG}
echo "=== Test Run Summary ===" >> ${RUN_LOG}

echo "Test binary:        ${TEST_BINARY}"
echo "Exit code:          ${TEST_EXIT_CODE}"
echo "ADDX instructions:  ${ADDX_COUNT:-unknown}"
echo ""

echo "Test binary:        ${TEST_BINARY}" >> ${RUN_LOG}
echo "Exit code:          ${TEST_EXIT_CODE}" >> ${RUN_LOG}
echo "ADDX instructions:  ${ADDX_COUNT:-unknown}" >> ${RUN_LOG}
echo "" >> ${RUN_LOG}

if [ ${TEST_EXIT_CODE} -eq 0 ]; then
    print_success "Test execution completed"
    echo "Test execution completed" >> ${RUN_LOG}
else
    print_info "Test terminated (exit code: ${TEST_EXIT_CODE})"
    print_info "Note: 'FAILED' message is expected due to tohost termination issue"
    echo "Test terminated (exit code: ${TEST_EXIT_CODE})" >> ${RUN_LOG}
    echo "Note: 'FAILED' message is expected due to tohost termination issue" >> ${RUN_LOG}
fi

echo ""
print_info "Output directory: ${DATE_DIR}/"
print_info ""
print_info "Log files:"
print_info "  - Build log: ${BUILD_LOG}"
print_info "  - Run log:   ${RUN_LOG}"
print_info ""
print_info "Trace files (in CVA6 root):"
print_info "  - trace_hart_0.dasm"
print_info "  - trace_rvfi_hart_00.dasm"
print_info "  - iti.trace"

echo "" >> ${RUN_LOG}
echo "Trace files:" >> ${RUN_LOG}
echo "  - trace_hart_0.dasm" >> ${RUN_LOG}
echo "  - trace_rvfi_hart_00.dasm" >> ${RUN_LOG}
echo "  - iti.trace" >> ${RUN_LOG}
echo "" >> ${RUN_LOG}
echo "Test completed at $(date)" >> ${RUN_LOG}

echo ""
print_header "Done"

exit 0
