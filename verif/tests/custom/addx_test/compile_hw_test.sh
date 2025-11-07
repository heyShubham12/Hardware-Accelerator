#!/bin/bash
set -e

echo "================================================"
echo "  Compiling ADDX Hardware Test"
echo "================================================"
echo ""

# Setup environment
export RISCV=/opt/riscv
export PATH=$RISCV/bin:$PATH

# Configuration
TEST_FILE="addx_hw_test.c"
OUTPUT_DIR="./build"
OUTPUT_NAME="addx_hw_test"

echo "Configuration:"
echo "  Test File = $TEST_FILE"
echo "  Output    = $OUTPUT_DIR/$OUTPUT_NAME.elf"
echo "  GCC       = $(which riscv-none-elf-gcc 2>/dev/null || echo 'NOT FOUND')"
echo ""

# Create output directory
mkdir -p $OUTPUT_DIR

# Compile
echo "Compiling ADDX hardware test..."
riscv-none-elf-gcc \
  -march=rv64gc \
  -mabi=lp64d \
  -static \
  -mcmodel=medany \
  -fvisibility=hidden \
  -nostdlib \
  -nostartfiles \
  -O2 \
  -g \
  -T../../../../config/gen_from_riscv_config/linker/link.ld \
  -I../env \
  -I../common \
  -o $OUTPUT_DIR/$OUTPUT_NAME.elf \
  $TEST_FILE \
  ../common/crt.S \
  ../common/syscalls.c

if [ $? -eq 0 ]; then
    echo "✓ Compilation successful!"
else
    echo "✗ Compilation failed!"
    exit 1
fi

echo ""

# Show results
echo "================================================"
echo "  Build Results"
echo "================================================"
echo ""
echo "Binary info:"
file $OUTPUT_DIR/$OUTPUT_NAME.elf
echo ""
ls -lh $OUTPUT_DIR/$OUTPUT_NAME.elf
echo ""

echo "Size breakdown:"
riscv-none-elf-size $OUTPUT_DIR/$OUTPUT_NAME.elf
echo ""

echo "================================================"
echo "  ADDX Instruction Verification"
echo "================================================"
echo ""
echo "Looking for ADDX instruction (.insn) in disassembly..."
riscv-none-elf-objdump -d $OUTPUT_DIR/$OUTPUT_NAME.elf | grep -B2 -A2 "\.insn\|0x0000000b" | head -20
echo ""

echo "================================================"
echo "  Compilation Complete!"
echo "================================================"
echo ""
echo "Binary location: $OUTPUT_DIR/$OUTPUT_NAME.elf"
echo ""
echo "Next steps:"
echo "  1. Run on Verilator: ./run_hw_test.sh"
echo "  2. View disassembly: riscv-none-elf-objdump -d $OUTPUT_DIR/$OUTPUT_NAME.elf | less"
echo ""
