#!/bin/bash
set -e

echo "================================================"
echo "  Compile CVA6 Program (Clean Exit)"
echo "================================================"
echo ""

# Setup environment
export RISCV=/opt/riscv
export RISCV_CC=riscv-none-elf-gcc

# Configuration
TEST_FILE="../tests/custom/my_first_test/my_first_program.c"
OUTPUT_DIR="./out_$(date +%Y-%m-%d)"
OUTPUT_NAME="my_first_program"

echo "Configuration:"
echo "  Test File = $TEST_FILE"
echo "  Output    = $OUTPUT_DIR/compiled/$OUTPUT_NAME.elf"
echo "  GCC       = $(which riscv-none-elf-gcc)"
echo ""

# Create output directory
mkdir -p $OUTPUT_DIR/compiled

# Compile
echo "Compiling..."
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
echo "  First 30 instructions of main():"
echo "================================================"
riscv-none-elf-objdump -d $OUTPUT_DIR/compiled/$OUTPUT_NAME.elf | grep -A 35 "<main>:"
echo ""

echo "================================================"
echo "  Success!"
echo "================================================"
echo ""
echo "View full disassembly:"
echo "  riscv-none-elf-objdump -d $OUTPUT_DIR/compiled/$OUTPUT_NAME.elf | less"
echo ""
echo "View with source code:"
echo "  riscv-none-elf-objdump -S $OUTPUT_DIR/compiled/$OUTPUT_NAME.elf | less"
echo ""
