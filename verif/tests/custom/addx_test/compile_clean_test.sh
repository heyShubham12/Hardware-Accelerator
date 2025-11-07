#!/bin/bash
################################################################################
# Clean ADDX Test Compilation Script (Minimal Output)
################################################################################

set -e

# Configuration
TEST_FILE="addx_hw_accel_clean.c"
TEST_DIR="/home/shubham/cva6/verif/tests/custom/addx_test"
OUTPUT_DIR="${TEST_DIR}/build"
OUTPUT_NAME="addx_hw_accel_clean"

# Navigate to test directory
cd ${TEST_DIR}
mkdir -p ${OUTPUT_DIR}

# Detect compiler
if command -v riscv64-unknown-elf-gcc &> /dev/null; then
    RISCV_GCC=riscv64-unknown-elf-gcc
    RISCV_OBJDUMP=riscv64-unknown-elf-objdump
    ARCH_FLAG="-march=rv64imc_zba_zbb_zbs_zbc_zicsr_zifencei"
    ABI_FLAG="-mabi=lp64"
elif command -v riscv-none-elf-gcc &> /dev/null; then
    RISCV_GCC=riscv-none-elf-gcc
    RISCV_OBJDUMP=riscv-none-elf-objdump
    ARCH_FLAG="-march=rv32imc_zba_zbb_zbs_zbc_zicsr_zifencei"
    ABI_FLAG="-mabi=ilp32"
else
    echo "ERROR: RISC-V GCC not found!"
    exit 1
fi

echo "Compiling ADDX test..."

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
    -lgcc 2>&1 | grep -v "warning: .* has a LOAD segment with RWX permissions" || true

if [ ${PIPESTATUS[0]} -eq 0 ]; then
    echo "✓ Compilation successful"

    # Count ADDX instructions
    ADDX_COUNT=$(${RISCV_OBJDUMP} -d ${OUTPUT_DIR}/${OUTPUT_NAME}.elf 2>/dev/null | grep -c "addx" || echo "0")
    echo "✓ Found ${ADDX_COUNT} ADDX instruction(s)"

    echo "✓ Binary: ${OUTPUT_DIR}/${OUTPUT_NAME}.elf"
    echo ""
    echo "To run in simulation:"
    echo "  cd /home/shubham/cva6/core/obj_dir"
    echo "  ./addx_test"
else
    echo "✗ Compilation failed"
    exit 1
fi
