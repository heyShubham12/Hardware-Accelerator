#!/bin/bash

# Run ADDX Cycle Count Test on CVA6 Simulator
# This script compiles and executes the ADDX test, showing the output

set -e  # Exit on error

# Colors for output
GREEN='\033[0;32m'
BLUE='\033[0;34m'
YELLOW='\033[1;33m'
RED='\033[0;31m'
NC='\033[0m' # No Color

echo ""
echo "╔════════════════════════════════════════════════╗"
echo "║  CVA6 ADDX Cycle Count Test - Runner          ║"
echo "╚════════════════════════════════════════════════╝"
echo ""

# Setup environment
export RISCV=/opt/riscv
export RISCV_CC=riscv-none-elf-gcc
export DV_SIMULATORS=veri-testharness

# Configuration
BINARY="./out_$(date +%Y-%m-%d)/compiled/addx_cycle_test.elf"
LOG_DIR="./logs"
LOG_FILE="${LOG_DIR}/addx_cycle_test_$(date +%Y%m%d_%H%M%S).log"

# Step 1: Compile if needed
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo "  Step 1: Checking/Compiling Binary"
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo ""

if [ ! -f "${BINARY}" ]; then
    echo "Binary not found. Compiling..."
    ./compile_addx_cycle_test.sh
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

# Step 2: Run on CVA6 Simulator
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo "  Step 2: Running on CVA6 Verilator Simulator"
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo ""
echo "Configuration:"
echo "  Target:    cv32a60x (32-bit RISC-V)"
echo "  Simulator: Verilator (veri-testharness)"
echo "  Binary:    ${BINARY}"
echo "  Log:       ${LOG_FILE}"
echo ""
echo "Starting simulation..."
echo "(This may take a few minutes)"
echo ""

# Run the simulation
python3 cva6.py \
  --target cv32a60x \
  --iss=veri-testharness \
  --elf_tests "${BINARY}" \
  2>&1 | tee "${LOG_FILE}"

echo ""
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo "  Step 3: Extracting Test Output"
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo ""

# Find the simulation output log
SIM_LOG=$(find out_*/veri-testharness_sim -name "*.log" 2>/dev/null | head -1)

if [ -z "${SIM_LOG}" ]; then
    echo -e "${YELLOW}⚠ Could not find simulation log${NC}"
    echo "Checking alternative locations..."

    # Try to find UART output or trace
    UART_LOG=$(find out_* -name "uart*" -o -name "trace*" 2>/dev/null | head -1)
    if [ -n "${UART_LOG}" ]; then
        SIM_LOG="${UART_LOG}"
    fi
fi

if [ -n "${SIM_LOG}" ] && [ -f "${SIM_LOG}" ]; then
    echo -e "${GREEN}✓ Found simulation output: ${SIM_LOG}${NC}"
    echo ""
    echo "╔════════════════════════════════════════════════╗"
    echo "║           TEST OUTPUT FROM CVA6                ║"
    echo "╚════════════════════════════════════════════════╝"
    echo ""

    # Display the test output
    cat "${SIM_LOG}" | grep -v "^#" | grep -v "^\s*$" || cat "${SIM_LOG}"

    echo ""
    echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"

    # Save clean output
    CLEAN_OUTPUT="${LOG_DIR}/addx_cycle_test_output.txt"
    cat "${SIM_LOG}" > "${CLEAN_OUTPUT}"
    echo ""
    echo "Output saved to: ${CLEAN_OUTPUT}"
else
    echo -e "${YELLOW}⚠ Simulation completed but output log not found${NC}"
    echo "Check the simulation directory manually:"
    echo "  ls -la out_*/veri-testharness_sim/"
fi

echo ""
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo "  Results Summary"
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo ""

# Check for test completion
if grep -q "ALL TESTS COMPLETED" "${LOG_FILE}" 2>/dev/null || \
   grep -q "ALL TESTS COMPLETED" "${SIM_LOG}" 2>/dev/null; then
    echo -e "${GREEN}✓ Test completed successfully!${NC}"
else
    echo -e "${YELLOW}⚠ Test status uncertain - check logs${NC}"
fi

echo ""
echo "Log locations:"
echo "  Full log:        ${LOG_FILE}"
[ -n "${SIM_LOG}" ] && echo "  Simulation log:  ${SIM_LOG}"
[ -n "${CLEAN_OUTPUT}" ] && echo "  Clean output:    ${CLEAN_OUTPUT}"
echo ""

echo "╔════════════════════════════════════════════════╗"
echo "║              SIMULATION COMPLETE               ║"
echo "╚════════════════════════════════════════════════╝"
echo ""
