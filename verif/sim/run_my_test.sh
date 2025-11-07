#!/bin/bash
set -e

echo "================================================"
echo "  Running My First CVA6 RISC-V Program"
echo "================================================"
echo ""

# Setup environment
export RISCV=/opt/riscv
export RISCV_CC=riscv-none-elf-gcc
export DV_SIMULATORS=veri-testharness

# Check toolchain
if ! which riscv-none-elf-gcc > /dev/null; then
    echo "ERROR: RISC-V toolchain not found!"
    echo "Please ensure $RISCV/bin is in your PATH"
    exit 1
fi

# Source setup script if it exists
if [ -f ./setup-env.sh ]; then
    source ./setup-env.sh
fi

echo "Environment:"
echo "  RISCV = $RISCV"
echo "  GCC   = $(which riscv-none-elf-gcc)"
echo "  Target = cv32a60x (32-bit RISC-V)"
echo ""

# Run the simulation
echo "Compiling and running..."
echo ""

python3 cva6.py \
  --target cv32a60x \
  --iss=$DV_SIMULATORS \
  --iss_yaml=cva6.yaml \
  --c_tests ../tests/custom/my_first_test/my_first_program.c \
  --linker=../../config/gen_from_riscv_config/linker/link.ld \
  --gcc_opts="-static -mcmodel=medany -fvisibility=hidden -nostdlib \
              -nostartfiles -g ../tests/custom/common/syscalls.c \
              ../tests/custom/common/crt.S -lgcc \
              -I../tests/custom/env -I../tests/custom/common"

# Check results
echo ""
echo "================================================"
echo "  Compilation Results"
echo "================================================"

if [ -f out_*/directed_tests/my_first_program.o ]; then
    echo "✓ Binary compiled successfully!"
    echo ""
    echo "Binary info:"
    file out_*/directed_tests/my_first_program.o
    echo ""
    ls -lh out_*/directed_tests/my_first_program.o
    echo ""
    echo "You can view the disassembly with:"
    echo "  riscv-none-elf-objdump -d out_*/directed_tests/my_first_program.o | less"
else
    echo "✗ Compilation failed!"
    exit 1
fi

echo ""
echo "================================================"
echo "  Done! Check the output directory for logs."
echo "================================================"
