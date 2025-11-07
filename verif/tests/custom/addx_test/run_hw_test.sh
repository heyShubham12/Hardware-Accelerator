#!/bin/bash

# Run ADDX Hardware Test on CVA6 Verilator Simulator

set -e  # Exit on error

# Colors for output
GREEN='\033[0;32m'
BLUE='\033[0;34m'
YELLOW='\033[1;33m'
RED='\033[0;31m'
NC='\033[0m' # No Color

echo ""
echo "╔════════════════════════════════════════════════╗"
echo "║  CVA6 ADDX Hardware Accelerator Test          ║"
echo "║  Running on Verilator                          ║"
echo "╚════════════════════════════════════════════════╝"
echo ""

# Setup environment
export RISCV=/opt/riscv
export PATH=$RISCV/bin:$PATH
export DV_SIMULATORS=veri-testharness

# Configuration
BINARY="./build/addx_hw_test.elf"
SIM_DIR="../../../sim"
LOG_DIR="./logs"
TIMESTAMP=$(date +%Y%m%d_%H%M%S)
LOG_FILE="${LOG_DIR}/addx_hw_test_${TIMESTAMP}.log"

# Step 1: Check/Compile Binary
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo "  Step 1: Checking Binary"
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo ""

if [ ! -f "${BINARY}" ]; then
    echo "Binary not found. Compiling..."
    ./compile_hw_test.sh
else
    echo -e "${GREEN}✓ Binary found: ${BINARY}${NC}"
fi
echo ""

# Verify binary exists
if [ ! -f "${BINARY}" ]; then
    echo -e "${RED}✗ Error: Binary not found after compilation!${NC}"
    exit 1
fi

# Create logs directory
mkdir -p "${LOG_DIR}"

# Get absolute path to binary
BINARY_ABS=$(readlink -f "${BINARY}")

# Step 2: Run on CVA6 Verilator
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo "  Step 2: Running on CVA6 Verilator Simulator"
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo ""
echo "Configuration:"
echo "  Target:    cv64a6_imafdc_sv39 (64-bit RISC-V)"
echo "  Simulator: Verilator (veri-testharness)"
echo "  Binary:    ${BINARY_ABS}"
echo "  Log:       ${LOG_FILE}"
echo ""
echo "Starting simulation..."
echo "(This may take a few minutes)"
echo ""

# Change to sim directory and run
cd ${SIM_DIR}

# Run the simulation
python3 cva6.py \
  --target cv64a6_imafdc_sv39 \
  --iss=veri-testharness \
  --elf_tests "${BINARY_ABS}" \
  2>&1 | tee "${BINARY_ABS%/*}/../logs/addx_hw_test_${TIMESTAMP}.log"

RESULT=$?

# Return to test directory
cd - > /dev/null

echo ""
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo "  Step 3: Analyzing Results"
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo ""

# Find the simulation output
SIM_OUTPUT=$(find ${SIM_DIR}/out_* -name "*.log" -o -name "uart" 2>/dev/null | grep -E "veri-testharness|uart" | head -1)

if [ -z "${SIM_OUTPUT}" ]; then
    # Try to find trace or other output
    SIM_OUTPUT=$(find ${SIM_DIR}/out_* -type f -name "*.log" 2>/dev/null | head -1)
fi

if [ -n "${SIM_OUTPUT}" ] && [ -f "${SIM_OUTPUT}" ]; then
    echo -e "${GREEN}✓ Found simulation output: ${SIM_OUTPUT}${NC}"
    echo ""
    echo "╔════════════════════════════════════════════════╗"
    echo "║           TEST OUTPUT FROM CVA6                ║"
    echo "╚════════════════════════════════════════════════╝"
    echo ""

    # Display the test output
    cat "${SIM_OUTPUT}"

    echo ""
    echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"

    # Check for test success
    if grep -q "ALL TESTS PASSED" "${SIM_OUTPUT}"; then
        echo -e "${GREEN}"
        echo "╔════════════════════════════════════════════════╗"
        echo "║              ✓ ALL TESTS PASSED!               ║"
        echo "╚════════════════════════════════════════════════╝"
        echo -e "${NC}"
    elif grep -q "FAILED" "${SIM_OUTPUT}"; then
        echo -e "${RED}"
        echo "╔════════════════════════════════════════════════╗"
        echo "║              ✗ SOME TESTS FAILED               ║"
        echo "╚════════════════════════════════════════════════╝"
        echo -e "${NC}"
    else
        echo -e "${YELLOW}⚠ Test completion status unclear${NC}"
    fi
else
    echo -e "${YELLOW}⚠ Could not find simulation output log${NC}"
    echo "Check the simulation directory manually:"
    echo "  ls -la ${SIM_DIR}/out_*/veri-testharness_sim/"
fi

echo ""
echo "Log file: ${LOG_FILE}"
echo ""

if [ $RESULT -eq 0 ]; then
    echo -e "${GREEN}✓ Simulation completed successfully${NC}"
else
    echo -e "${YELLOW}⚠ Simulation exited with code: $RESULT${NC}"
fi

echo ""
