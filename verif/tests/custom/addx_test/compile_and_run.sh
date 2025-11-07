#!/bin/bash
# Simple script to compile and run ADDX assembly test
# Author: Shubham Mishra

echo "========================================"
echo " ADDX Test - Compile and Run"
echo "========================================"
echo ""

# Setup environment
export RISCV=/opt/riscv
export PATH=/opt/riscv/bin:$PATH

# Create output directory
OUTPUT_DIR="/tmp/addx_output"
mkdir -p ${OUTPUT_DIR}

echo "Step 1: Assembling the program..."
echo "----------------------------------"

# Assemble the standalone assembly file
riscv-none-elf-as \
    -march=rv64gc \
    -o ${OUTPUT_DIR}/addx_test.o \
    /home/shubham/cva6/verif/tests/custom/addx_test/addx_standalone.s

if [ $? -ne 0 ]; then
    echo "✗ Assembly failed!"
    exit 1
fi
echo "✓ Assembly successful!"
echo ""

echo "Step 2: Linking..."
echo "----------------------------------"

# Link the object file
riscv-none-elf-ld \
    -m elf64lriscv \
    -o ${OUTPUT_DIR}/addx_test.elf \
    ${OUTPUT_DIR}/addx_test.o

if [ $? -ne 0 ]; then
    echo "✗ Linking failed!"
    exit 1
fi
echo "✓ Linking successful!"
echo ""

echo "Step 3: Checking binary..."
echo "----------------------------------"
file ${OUTPUT_DIR}/addx_test.elf
ls -lh ${OUTPUT_DIR}/addx_test.elf
echo ""

echo "Step 4: Disassembly (showing ADDX instructions)..."
echo "---------------------------------------------------"
riscv-none-elf-objdump -d ${OUTPUT_DIR}/addx_test.elf | grep -A 1 "\.word.*0x0"
echo ""

echo "========================================"
echo " Compilation Complete!"
echo "========================================"
echo ""
echo "Binary location: ${OUTPUT_DIR}/addx_test.elf"
echo ""
echo "To run with Spike ISS:"
echo "  spike --isa=rv64gc ${OUTPUT_DIR}/addx_test.elf"
echo ""
echo "To run with CVA6:"
echo "  cd /home/shubham/cva6/verif/sim"
echo "  python3 cva6.py --target cv64a6_imafdc_sv39 \\"
echo "    --iss=spike \\"
echo "    --elf_tests ${OUTPUT_DIR}/addx_test.elf"
echo ""
