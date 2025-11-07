#!/bin/bash

# Compilation script for ADDX Cycle Count Test
# Compiles addx_cycle_test.c with RISC-V toolchain

set -e  # Exit on error

# Colors for output
GREEN='\033[0;32m'
BLUE='\033[0;34m'
YELLOW='\033[1;33m'
RED='\033[0;31m'
NC='\033[0m' # No Color

# Configuration
TEST_NAME="addx_cycle_test"
TEST_DIR="../tests/custom/addx_test"
SOURCE_FILE="${TEST_DIR}/${TEST_NAME}.c"
OUTPUT_DIR="./out_$(date +%Y-%m-%d)/compiled"
OUTPUT_FILE="${OUTPUT_DIR}/${TEST_NAME}.elf"
RISCV_GCC="/opt/riscv/bin/riscv-none-elf-gcc"
RISCV_OBJDUMP="/opt/riscv/bin/riscv-none-elf-objdump"

echo "================================================"
echo "  Compiling ADDX Cycle Count Test"
echo "================================================"
echo ""

# Create output directory
mkdir -p "${OUTPUT_DIR}"

# Verify source file exists
if [ ! -f "${SOURCE_FILE}" ]; then
    echo -e "${RED}Error: Source file not found: ${SOURCE_FILE}${NC}"
    exit 1
fi

# Verify GCC exists
if [ ! -f "${RISCV_GCC}" ]; then
    echo -e "${RED}Error: RISC-V GCC not found: ${RISCV_GCC}${NC}"
    exit 1
fi

echo "Configuration:"
echo "  Test File = ${SOURCE_FILE}"
echo "  Output    = ${OUTPUT_FILE}"
echo "  GCC       = ${RISCV_GCC}"
echo ""

echo "Compiling ADDX cycle count test..."

# Compile with RISC-V GCC
${RISCV_GCC} \
    -march=rv32imc_zba_zbb_zbs_zbc_zicsr_zifencei \
    -mabi=ilp32 \
    -static \
    -mcmodel=medany \
    -fvisibility=hidden \
    -nostdlib \
    -nostartfiles \
    -g \
    -Os \
    -I../tests/custom/env \
    -I../tests/custom/common \
    -T../../config/gen_from_riscv_config/linker/link.ld \
    -o "${OUTPUT_FILE}" \
    "${SOURCE_FILE}" \
    ../tests/custom/common/crt.S \
    ../tests/custom/common/syscalls.c \
    -lgcc

if [ $? -eq 0 ]; then
    echo -e "${GREEN}✓ Compilation successful!${NC}"
    echo ""
else
    echo -e "${RED}✗ Compilation failed!${NC}"
    exit 1
fi

echo "================================================"
echo "  Results"
echo "================================================"
echo ""

# Show binary information
echo "Binary info:"
file "${OUTPUT_FILE}"
echo ""
ls -lh "${OUTPUT_FILE}"
echo ""

# Show size breakdown
echo "Size breakdown:"
riscv-none-elf-size "${OUTPUT_FILE}"
echo ""

echo "================================================"
echo "  ADDX Instruction Analysis"
echo "================================================"
echo ""

# Look for ADDX instruction in the binary
echo "Looking for ADDX instructions in binary..."
if ${RISCV_OBJDUMP} -d "${OUTPUT_FILE}" | grep -q "addx"; then
    echo -e "${GREEN}✓ ADDX instruction(s) found!${NC}"
    echo ""
    echo "ADDX instructions in test_addx_with_cycles:"
    ${RISCV_OBJDUMP} -d "${OUTPUT_FILE}" | grep -A 20 "<test_addx_with_cycles>:" | grep --color=always "addx"
    echo ""
    echo "ADDX instructions in test_addx_isolated:"
    ${RISCV_OBJDUMP} -d "${OUTPUT_FILE}" | grep -A 15 "<test_addx_isolated>:" | grep --color=always "addx"
    echo ""
else
    echo -e "${YELLOW}⚠ No ADDX instructions found - check encoding${NC}"
fi

echo "================================================"
echo "  Cycle Counter CSR Access"
echo "================================================"
echo ""

# Look for CSR instructions
echo "Checking for cycle counter CSR reads..."
if ${RISCV_OBJDUMP} -d "${OUTPUT_FILE}" | grep -q "csrr.*cycle"; then
    echo -e "${GREEN}✓ Cycle counter reads found${NC}"
    CSR_COUNT=$(${RISCV_OBJDUMP} -d "${OUTPUT_FILE}" | grep -c "csrr.*cycle" || true)
    echo "  Found ${CSR_COUNT} cycle counter read instructions"
else
    echo -e "${YELLOW}⚠ No cycle counter reads found${NC}"
fi
echo ""

echo "================================================"
echo "  View Commands"
echo "================================================"
echo ""
echo "View full disassembly:"
echo "  ${RISCV_OBJDUMP} -d ${OUTPUT_FILE} | less"
echo ""
echo "View disassembly with source:"
echo "  ${RISCV_OBJDUMP} -S ${OUTPUT_FILE} | less"
echo ""
echo "Search for ADDX instructions:"
echo "  ${RISCV_OBJDUMP} -d ${OUTPUT_FILE} | grep -C5 'addx'"
echo ""
echo "View cycle counter code:"
echo "  ${RISCV_OBJDUMP} -d ${OUTPUT_FILE} | grep -C10 'read_cycles'"
echo ""

echo "================================================"
echo "  Success!"
echo "================================================"
echo ""
echo -e "${GREEN}ADDX cycle count test compiled successfully!${NC}"
echo ""
echo "Output: ${OUTPUT_FILE}"
echo ""
