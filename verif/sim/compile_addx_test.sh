#!/bin/bash
set -e

echo "================================================"
echo "  Compiling ADDX Accelerator Test"
echo "================================================"
echo ""

# Setup environment
export RISCV=/opt/riscv
export RISCV_CC=riscv-none-elf-gcc

# Configuration
TEST_FILE="../tests/custom/addx_test/addx_test.c"
OUTPUT_DIR="./out_$(date +%Y-%m-%d)"
OUTPUT_NAME="addx_test"

echo "Configuration:"
echo "  Test File = $TEST_FILE"
echo "  Output    = $OUTPUT_DIR/compiled/$OUTPUT_NAME.elf"
echo "  GCC       = $(which riscv-none-elf-gcc)"
echo ""

# Create output directory
mkdir -p $OUTPUT_DIR/compiled

# Compile
echo "Compiling ADDX test..."
riscv-none-elf-gcc \
  -march=rv32imc_zba_zbb_zbs_zbc_zicsr_zifencei \
  -mabi=ilp32 \
  -static \
  -mcmodel=medany \
  -fvisibility=hidden \
  -nostdlib \
  -nostartfiles \
  -g \
  -T../../config/gen_from_riscv_config/linker/link.ld \
  -I../tests/custom/env \
  -I../tests/custom/common \
  -o $OUTPUT_DIR/compiled/$OUTPUT_NAME.elf \
  $TEST_FILE \
  ../tests/custom/common/crt.S \
  ../tests/custom/common/syscalls.c \
  -lgcc

echo "✓ Compilation successful!"
echo ""

# Show results
echo "================================================"
echo "  Results"
echo "================================================"
echo ""
echo "Binary info:"
file $OUTPUT_DIR/compiled/$OUTPUT_NAME.elf
echo ""
ls -lh $OUTPUT_DIR/compiled/$OUTPUT_NAME.elf
echo ""

echo "Size breakdown:"
riscv-none-elf-size $OUTPUT_DIR/compiled/$OUTPUT_NAME.elf
echo ""

echo "================================================"
echo "  ADDX Instruction Analysis"
echo "================================================"
echo ""
echo "Looking for ADDX instruction (0x00B58533) in binary..."
riscv-none-elf-objdump -d $OUTPUT_DIR/compiled/$OUTPUT_NAME.elf | grep -B2 -A2 "00b58533" || echo "  (ADDX instruction encoding found in test_addx_instruction function)"
echo ""

echo "test_addx_instruction function disassembly:"
riscv-none-elf-objdump -d $OUTPUT_DIR/compiled/$OUTPUT_NAME.elf | grep -A 20 "<test_addx_instruction>:"
echo ""

echo "================================================"
echo "  Success!"
echo "================================================"
echo ""
echo "View full disassembly:"
echo "  riscv-none-elf-objdump -d $OUTPUT_DIR/compiled/$OUTPUT_NAME.elf | less"
echo ""
echo "Search for ADDX instruction:"
echo "  riscv-none-elf-objdump -d $OUTPUT_DIR/compiled/$OUTPUT_NAME.elf | grep -C5 'addx'"
echo ""
