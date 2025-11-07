#!/bin/bash
# Script to compile and run ADDX test on CVA6
# Author: Shubham Mishra
# Date: October 22, 2025

echo "========================================"
echo "  ADDX Accelerator Test Runner"
echo "========================================"
echo ""

# Set up environment
export RISCV=/opt/riscv
export PATH=/opt/riscv/bin:$PATH

# Define paths
TEST_DIR="/home/shubham/cva6/verif/tests/custom/addx_test"
COMMON_DIR="/home/shubham/cva6/verif/tests/custom/common"
LINKER_SCRIPT="/home/shubham/cva6/config/gen_from_riscv_config/linker/link.ld"
OUTPUT_DIR="/tmp/addx_test_output"

# Create output directory
mkdir -p ${OUTPUT_DIR}

echo "Step 1: Compiling assembly test..."
echo "-----------------------------------"

# Compile the assembly file
riscv-none-elf-gcc \
    ${TEST_DIR}/addx_simple_run.s \
    ${COMMON_DIR}/crt.S \
    ${COMMON_DIR}/syscalls.c \
    -march=rv64gc \
    -mabi=lp64d \
    -static \
    -mcmodel=medany \
    -fvisibility=hidden \
    -nostdlib \
    -nostartfiles \
    -T${LINKER_SCRIPT} \
    -I${COMMON_DIR} \
    -I/home/shubham/cva6/verif/tests/custom/env \
    -o ${OUTPUT_DIR}/addx_test.elf

if [ $? -eq 0 ]; then
    echo "✓ Compilation successful!"
    echo ""
else
    echo "✗ Compilation failed!"
    exit 1
fi

echo "Step 2: Checking generated binary..."
echo "-------------------------------------"
file ${OUTPUT_DIR}/addx_test.elf
echo ""

echo "Step 3: Disassembling to verify ADDX instructions..."
echo "----------------------------------------------------"
riscv-none-elf-objdump -d ${OUTPUT_DIR}/addx_test.elf | grep -A 2 -B 2 "\.word.*0x00b"
echo ""

echo "Step 4: Binary information..."
echo "-----------------------------"
ls -lh ${OUTPUT_DIR}/addx_test.elf
echo ""

echo "========================================"
echo "  Compilation Complete!"
echo "========================================"
echo ""
echo "Output file: ${OUTPUT_DIR}/addx_test.elf"
echo ""
echo "To run with CVA6 simulator, use:"
echo "cd /home/shubham/cva6/verif/sim"
echo "python3 cva6.py --target cv64a6_imafdc_sv39 --iss=spike --elf_tests ${OUTPUT_DIR}/addx_test.elf"
echo ""
echo "Or to see detailed execution with Spike:"
echo "spike --isa=rv64gc ${OUTPUT_DIR}/addx_test.elf"
echo ""
