#!/bin/bash
################################################################################
# ADDX Hardware Accelerator Test Runner
#
# This script runs the addx_hw_accel.c test using the official CVA6 simulation
# framework (cva6.py) with Verilator testharness.
#
# Usage: ./run_addx_hw_accel_test.sh
#
# Author: CVA6 ADDX Integration Test
# Date: 2025-11-06
################################################################################

set -e  # Exit on error

# Color codes
GREEN='\033[0;32m'
BLUE='\033[0;34m'
CYAN='\033[0;36m'
RED='\033[0;31m'
NC='\033[0m' # No Color

echo -e "${CYAN}╔════════════════════════════════════════════════════════════════════╗${NC}"
echo -e "${CYAN}║                                                                    ║${NC}"
echo -e "${CYAN}║         ADDX Hardware Accelerator Test - Official Method          ║${NC}"
echo -e "${CYAN}║                                                                    ║${NC}"
echo -e "${CYAN}╚════════════════════════════════════════════════════════════════════╝${NC}"
echo ""

# Navigate to CVA6 root
cd /home/shubham/cva6
echo -e "${BLUE}[INFO]${NC} Working directory: $(pwd)"

# Source environment setup
echo -e "${BLUE}[INFO]${NC} Sourcing environment setup script..."
source verif/sim/setup-env.sh

# Set the NUM_JOBS variable to increase the number of parallel make jobs (optional)
# export NUM_JOBS=4

# Set simulator
export DV_SIMULATORS=veri-testharness
echo -e "${GREEN}[OK]${NC} Simulator set to: ${DV_SIMULATORS}"

# Navigate to simulation directory
cd ./verif/sim
echo -e "${BLUE}[INFO]${NC} Changed to simulation directory: $(pwd)"

# Display test configuration
echo ""
echo -e "${CYAN}═══════════════════════════════════════════════════════════════════${NC}"
echo -e "${CYAN} Test Configuration${NC}"
echo -e "${CYAN}═══════════════════════════════════════════════════════════════════${NC}"
echo -e "  Target:       cv32a60x"
echo -e "  Simulator:    ${DV_SIMULATORS}"
echo -e "  Test File:    ../tests/custom/addx_test/addx_hw_accel.c"
echo -e "  Linker:       ../../config/gen_from_riscv_config/linker/link.ld"
echo -e "${CYAN}═══════════════════════════════════════════════════════════════════${NC}"
echo ""

# Run the simulation
echo -e "${BLUE}[INFO]${NC} Starting CVA6 simulation with ADDX test..."
echo -e "${BLUE}[INFO]${NC} This may take a few minutes..."
echo ""

python3 cva6.py \
    --target cv32a60x \
    --iss=$DV_SIMULATORS \
    --iss_yaml=cva6.yaml \
    --c_tests ../tests/custom/addx_test/addx_hw_accel.c \
    --linker=../../config/gen_from_riscv_config/linker/link.ld \
    --gcc_opts="-static -mcmodel=medany -fvisibility=hidden -nostdlib \
-nostartfiles -g ../tests/custom/common/syscalls.c \
../tests/custom/common/crt.S -lgcc \
-I../tests/custom/env -I../tests/custom/common"

EXIT_CODE=$?

echo ""
echo -e "${CYAN}═══════════════════════════════════════════════════════════════════${NC}"
if [ $EXIT_CODE -eq 0 ]; then
    echo -e "${GREEN}[SUCCESS]${NC} Simulation completed successfully!"
    echo -e "${GREEN}[SUCCESS]${NC} Exit code: ${EXIT_CODE}"
else
    echo -e "${RED}[WARNING]${NC} Simulation completed with exit code: ${EXIT_CODE}"
fi
echo -e "${CYAN}═══════════════════════════════════════════════════════════════════${NC}"
echo ""

# Find the latest output directory
LATEST_OUT=$(ls -dt out_* 2>/dev/null | head -n1)
if [ -n "$LATEST_OUT" ]; then
    echo -e "${BLUE}[INFO]${NC} Output directory: ${LATEST_OUT}"
    echo -e "${BLUE}[INFO]${NC} Simulation logs can be found in: ${LATEST_OUT}/"

    # Check for simulation logs
    if [ -d "${LATEST_OUT}/veri-testharness_sim" ]; then
        echo ""
        echo -e "${CYAN}═══════════════════════════════════════════════════════════════════${NC}"
        echo -e "${CYAN} Checking for ADDX Execution Traces${NC}"
        echo -e "${CYAN}═══════════════════════════════════════════════════════════════════${NC}"

        # Look for ADDX accelerator debug output
        if find "${LATEST_OUT}" -type f -name "*.log" -exec grep -l "ADDX ACCELERATOR" {} \; 2>/dev/null | head -1; then
            echo -e "${GREEN}[OK]${NC} Found ADDX accelerator execution traces in logs!"

            # Show some ADDX traces
            echo ""
            echo -e "${BLUE}[INFO]${NC} Sample ADDX execution traces:"
            echo -e "${CYAN}───────────────────────────────────────────────────────────────────${NC}"
            find "${LATEST_OUT}" -type f -name "*.log" -exec grep -A 8 "ADDX ACCELERATOR" {} \; 2>/dev/null | head -50
        else
            echo -e "${BLUE}[INFO]${NC} No ADDX accelerator debug traces found (may be disabled in this simulation mode)"
        fi

        # Check for test output
        echo ""
        echo -e "${CYAN}═══════════════════════════════════════════════════════════════════${NC}"
        echo -e "${CYAN} Test Output Summary${NC}"
        echo -e "${CYAN}═══════════════════════════════════════════════════════════════════${NC}"

        # Look for test results in logs
        if find "${LATEST_OUT}" -type f -name "*.log" -exec grep -l "TEST SUMMARY\|TESTS PASSED\|ALL TESTS" {} \; 2>/dev/null | head -1; then
            echo ""
            find "${LATEST_OUT}" -type f -name "*.log" -exec grep -B 5 -A 10 "TEST SUMMARY" {} \; 2>/dev/null | head -30
        fi
    fi

    # Show ELF file info if available
    echo ""
    echo -e "${CYAN}═══════════════════════════════════════════════════════════════════${NC}"
    echo -e "${CYAN} Binary Information${NC}"
    echo -e "${CYAN}═══════════════════════════════════════════════════════════════════${NC}"

    ELF_FILE=$(find "${LATEST_OUT}" -name "addx_hw_accel*.elf" 2>/dev/null | head -1)
    if [ -n "$ELF_FILE" ]; then
        echo -e "${BLUE}[INFO]${NC} Found compiled binary: ${ELF_FILE}"

        # Check for ADDX instructions in disassembly
        if command -v riscv64-unknown-elf-objdump &> /dev/null; then
            OBJDUMP=riscv64-unknown-elf-objdump
        elif command -v riscv-none-elf-objdump &> /dev/null; then
            OBJDUMP=riscv-none-elf-objdump
        else
            OBJDUMP=""
        fi

        if [ -n "$OBJDUMP" ]; then
            echo ""
            echo -e "${BLUE}[INFO]${NC} Checking for ADDX instructions in binary..."
            echo -e "${CYAN}───────────────────────────────────────────────────────────────────${NC}"

            # Look for ADDX instructions (opcode ending in 0x0b)
            ADDX_COUNT=$($OBJDUMP -d "$ELF_FILE" 2>/dev/null | grep -c "\.insn.*0x0b\|0x.*0b$" || echo "0")
            echo -e "${GREEN}[OK]${NC} Found ${ADDX_COUNT} ADDX instruction(s) in binary"

            if [ "$ADDX_COUNT" -gt 0 ]; then
                echo ""
                echo -e "${BLUE}[INFO]${NC} Sample ADDX instructions:"
                $OBJDUMP -d "$ELF_FILE" 2>/dev/null | grep -B 2 -A 0 "\.insn.*0x0b\|0x.*0b$" | head -20
            fi
        fi
    fi
fi

echo ""
echo -e "${CYAN}╔════════════════════════════════════════════════════════════════════╗${NC}"
echo -e "${CYAN}║                       Test Run Complete                            ║${NC}"
echo -e "${CYAN}╚════════════════════════════════════════════════════════════════════╝${NC}"
echo ""

exit $EXIT_CODE
