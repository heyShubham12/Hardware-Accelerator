#!/bin/bash
set -e

echo "================================================"
echo "  Running My First CVA6 Program (Best Method)"
echo "================================================"
echo ""

# Setup environment
export RISCV=/opt/riscv
export RISCV_CC=riscv-none-elf-gcc
export DV_SIMULATORS=veri-testharness

# Source setup if available
[ -f ./setup-env.sh ] && source ./setup-env.sh

echo "Configuration:"
echo "  RISCV     = $RISCV"
echo "  GCC       = $(which riscv-none-elf-gcc)"
echo "  Target    = cv32a60x (32-bit RISC-V)"
echo "  Simulator = Verilator only"
echo "  Test      = my_first_program.c"
echo ""

# Run compilation step only (skip Spike checks)
echo "Step 1: Compiling with RISC-V GCC..."
python3 cva6.py \
  --target cv32a60x \
  --steps gcc_compile \
  --c_tests ../tests/custom/my_first_test/my_first_program.c \
  --linker=../../config/gen_from_riscv_config/linker/link.ld \
  --gcc_opts="-static -mcmodel=medany -fvisibility=hidden -nostdlib \
              -nostartfiles -g ../tests/custom/common/syscalls.c \
              ../tests/custom/common/crt.S -lgcc \
              -I../tests/custom/env -I../tests/custom/common"

echo ""
echo "✓ Step 1 Complete: Binary compiled"
echo ""

# Check if binary was created
if [ ! -f out_*/directed_tests/my_first_program.o ]; then
    echo "✗ Error: Binary not found!"
    exit 1
fi

echo "================================================"
echo "  Compilation Results"
echo "================================================"
echo ""

# Show binary info
echo "Binary Information:"
file out_*/directed_tests/my_first_program.o
echo ""
ls -lh out_*/directed_tests/my_first_program.o
echo ""

# Show size breakdown
echo "Size Breakdown:"
riscv-none-elf-size out_*/directed_tests/my_first_program.o
echo ""

# Show entry point
echo "Entry Point:"
riscv-none-elf-objdump -f out_*/directed_tests/my_first_program.o
echo ""

# Show first few instructions from main
echo "================================================"
echo "  First Instructions of main():"
echo "================================================"
riscv-none-elf-objdump -d out_*/directed_tests/my_first_program.o | \
  grep -A 20 "<main>:" | head -25
echo ""

echo "================================================"
echo "  Success!"
echo "================================================"
echo ""
echo "Your program has been compiled successfully!"
echo ""
echo "View full disassembly:"
echo "  riscv-none-elf-objdump -d out_*/directed_tests/my_first_program.o | less"
echo ""
echo "View with source code:"
echo "  riscv-none-elf-objdump -S out_*/directed_tests/my_first_program.o | less"
echo ""
echo "View symbols:"
echo "  riscv-none-elf-nm out_*/directed_tests/my_first_program.o"
echo ""
echo "Next: To run on Verilator simulator, use:"
echo "  python3 cva6.py --target cv32a60x --iss=veri-testharness \\"
echo "    --elf_tests out_*/directed_tests/my_first_program.o"
