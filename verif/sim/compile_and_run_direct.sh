#!/bin/bash
set -e

echo "================================================"
echo "  Direct Compilation Method (No Version Checks)"
echo "================================================"
echo ""

# Setup
export RISCV=/opt/riscv
TEST_DIR="../tests/custom/my_first_test"
OUTPUT_DIR="./out_$(date +%Y-%m-%d)"
mkdir -p $OUTPUT_DIR/compiled

# Compile
echo "Step 1: Compiling my_first_program.c..."
riscv-none-elf-gcc \
  -march=rv32imc \
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
  -o $OUTPUT_DIR/compiled/my_first_program.elf \
  $TEST_DIR/my_first_program.c \
  ../tests/custom/common/crt.S \
  ../tests/custom/common/syscalls.c \
  -lgcc

echo "✓ Compilation successful!"
echo ""

# Verify
echo "Step 2: Verifying binary..."
file $OUTPUT_DIR/compiled/my_first_program.elf
riscv-none-elf-size $OUTPUT_DIR/compiled/my_first_program.elf
echo ""

# Disassemble (first few instructions)
echo "Step 3: First 50 instructions:"
riscv-none-elf-objdump -d $OUTPUT_DIR/compiled/my_first_program.elf | head -60
echo ""

echo "================================================"
echo "  Binary Ready!"
echo "================================================"
echo "Location: $OUTPUT_DIR/compiled/my_first_program.elf"
echo ""
echo "View full disassembly:"
echo "  riscv-none-elf-objdump -d $OUTPUT_DIR/compiled/my_first_program.elf | less"
echo ""
echo "View source with addresses:"
echo "  riscv-none-elf-objdump -S $OUTPUT_DIR/compiled/my_first_program.elf | less"
echo ""
echo "To run on simulator, you would need to set up Verilator testbench."
echo "The binary is ready and can be loaded into any RISC-V simulator/hardware."
