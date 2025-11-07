#!/bin/bash
################################################################################
# Direct Compilation and Test for ADDX Hardware Accelerator
#
# This script compiles addx_hw_accel.c directly without using cva6.py framework
# to avoid Spike version check issues.
#
# Usage: ./compile_and_run_addx_hw_accel.sh
################################################################################

set -e

# Colors
GREEN='\033[0;32m'
BLUE='\033[0;34m'
CYAN='\033[0;36m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
NC='\033[0m'

echo -e "${CYAN}╔════════════════════════════════════════════════════════════════════╗${NC}"
echo -e "${CYAN}║                                                                    ║${NC}"
echo -e "${CYAN}║     ADDX Hardware Accelerator Test - Direct Compilation           ║${NC}"
echo -e "${CYAN}║                                                                    ║${NC}"
echo -e "${CYAN}╚════════════════════════════════════════════════════════════════════╝${NC}"
echo ""

# Configuration
export RISCV=/opt/riscv
TEST_FILE="addx_hw_accel.c"
TEST_DIR="/home/shubham/cva6/verif/tests/custom/addx_test"
OUTPUT_DIR="${TEST_DIR}/build"
OUTPUT_NAME="addx_hw_accel"
TIMESTAMP=$(date +%Y%m%d_%H%M%S)

echo -e "${BLUE}[INFO]${NC} Test Configuration:"
echo -e "  Test File:   ${TEST_FILE}"
echo -e "  Output Dir:  ${OUTPUT_DIR}"
echo -e "  Timestamp:   ${TIMESTAMP}"
echo ""

# Create output directory
mkdir -p ${OUTPUT_DIR}
mkdir -p ${TEST_DIR}/logs

# Navigate to test directory
cd ${TEST_DIR}

echo -e "${BLUE}[INFO]${NC} Compiling ADDX hardware accelerator test..."
echo ""

# Compile the test
if command -v riscv64-unknown-elf-gcc &> /dev/null; then
    RISCV_GCC=riscv64-unknown-elf-gcc
    RISCV_OBJDUMP=riscv64-unknown-elf-objdump
    RISCV_SIZE=riscv64-unknown-elf-size
    ARCH_FLAG="-march=rv64imc_zba_zbb_zbs_zbc_zicsr_zifencei"
    ABI_FLAG="-mabi=lp64"
elif command -v riscv-none-elf-gcc &> /dev/null; then
    RISCV_GCC=riscv-none-elf-gcc
    RISCV_OBJDUMP=riscv-none-elf-objdump
    RISCV_SIZE=riscv-none-elf-size
    ARCH_FLAG="-march=rv32imc_zba_zbb_zbs_zbc_zicsr_zifencei"
    ABI_FLAG="-mabi=ilp32"
else
    echo -e "${RED}[ERROR]${NC} RISC-V GCC not found!"
    exit 1
fi

echo -e "${GREEN}[OK]${NC} Using compiler: ${RISCV_GCC}"
echo -e "${GREEN}[OK]${NC} Architecture: ${ARCH_FLAG}"
echo ""

# Compile
${RISCV_GCC} \
    ${ARCH_FLAG} \
    ${ABI_FLAG} \
    -static \
    -mcmodel=medany \
    -fvisibility=hidden \
    -nostdlib \
    -nostartfiles \
    -g \
    -T../../../../config/gen_from_riscv_config/linker/link.ld \
    -I../env \
    -I../common \
    -o ${OUTPUT_DIR}/${OUTPUT_NAME}.elf \
    ${TEST_FILE} \
    ../common/crt.S \
    ../common/syscalls.c \
    -lgcc

COMPILE_STATUS=$?

if [ $COMPILE_STATUS -eq 0 ]; then
    echo -e "${GREEN}[SUCCESS]${NC} Compilation successful!"
else
    echo -e "${RED}[ERROR]${NC} Compilation failed with exit code: ${COMPILE_STATUS}"
    exit $COMPILE_STATUS
fi

echo ""
echo -e "${CYAN}═══════════════════════════════════════════════════════════════════${NC}"
echo -e "${CYAN} Binary Information${NC}"
echo -e "${CYAN}═══════════════════════════════════════════════════════════════════${NC}"

# Show binary info
echo ""
file ${OUTPUT_DIR}/${OUTPUT_NAME}.elf
echo ""
ls -lh ${OUTPUT_DIR}/${OUTPUT_NAME}.elf
echo ""

# Show size
echo -e "${BLUE}[INFO]${NC} Binary size breakdown:"
${RISCV_SIZE} ${OUTPUT_DIR}/${OUTPUT_NAME}.elf
echo ""

# Analyze ADDX instructions
echo -e "${CYAN}═══════════════════════════════════════════════════════════════════${NC}"
echo -e "${CYAN} ADDX Instruction Analysis${NC}"
echo -e "${CYAN}═══════════════════════════════════════════════════════════════════${NC}"
echo ""

echo -e "${BLUE}[INFO]${NC} Searching for ADDX instructions in binary..."
ADDX_COUNT=$(${RISCV_OBJDUMP} -d ${OUTPUT_DIR}/${OUTPUT_NAME}.elf | grep -c "\.insn.*0x0b" || echo "0")
echo -e "${GREEN}[OK]${NC} Found ${ADDX_COUNT} ADDX instruction(s)"
echo ""

if [ "$ADDX_COUNT" -gt 0 ]; then
    echo -e "${BLUE}[INFO]${NC} Sample ADDX instructions from disassembly:"
    echo -e "${CYAN}───────────────────────────────────────────────────────────────────${NC}"
    ${RISCV_OBJDUMP} -d ${OUTPUT_DIR}/${OUTPUT_NAME}.elf | grep -B 2 -A 0 "\.insn.*0x0b" | head -30
    echo ""
fi

# Show test functions
echo -e "${CYAN}═══════════════════════════════════════════════════════════════════${NC}"
echo -e "${CYAN} Test Functions${NC}"
echo -e "${CYAN}═══════════════════════════════════════════════════════════════════${NC}"
echo ""

echo -e "${BLUE}[INFO]${NC} Main test functions:"
${RISCV_OBJDUMP} -t ${OUTPUT_DIR}/${OUTPUT_NAME}.elf | grep -E "test_|main|addx" | head -20
echo ""

# Generate disassembly
echo -e "${BLUE}[INFO]${NC} Generating full disassembly..."
${RISCV_OBJDUMP} -d ${OUTPUT_DIR}/${OUTPUT_NAME}.elf > ${OUTPUT_DIR}/${OUTPUT_NAME}.dis
echo -e "${GREEN}[OK]${NC} Disassembly saved to: ${OUTPUT_DIR}/${OUTPUT_NAME}.dis"
echo ""

echo -e "${CYAN}╔════════════════════════════════════════════════════════════════════╗${NC}"
echo -e "${CYAN}║                    Compilation Complete!                           ║${NC}"
echo -e "${CYAN}╚════════════════════════════════════════════════════════════════════╝${NC}"
echo ""

echo -e "${YELLOW}[NOTE]${NC} To run this test in simulation:"
echo -e "  1. Use the Verilator testbench in the CVA6 core"
echo -e "  2. Or run the pre-built Verilator tests:"
echo -e "     cd /home/shubham/cva6/core/obj_dir"
echo -e "     ./addx_test"
echo -e "     ./addx_real_test"
echo ""
echo -e "${GREEN}[OK]${NC} Binary ready: ${OUTPUT_DIR}/${OUTPUT_NAME}.elf"
echo ""

exit 0
