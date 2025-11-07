#!/bin/bash
################################################################################
# Quick ADDX Test Runner (Minimal Output)
################################################################################

clear
echo ""
echo "═══════════════════════════════════════════════════════"
echo "  ADDX Hardware Accelerator - Quick Test"
echo "═══════════════════════════════════════════════════════"
echo ""

# Run pre-built Verilator test
if [ -f "/home/shubham/cva6/core/obj_dir/addx_test" ]; then
    echo "Running pre-built hardware test..."
    echo ""
    /home/shubham/cva6/core/obj_dir/addx_test 2>&1 | grep -E "Test [0-9]+:|All Tests Complete|PASS|FAIL" || /home/shubham/cva6/core/obj_dir/addx_test
    echo ""
else
    echo "Pre-built test not found. Compiling new test..."
    cd /home/shubham/cva6/verif/tests/custom/addx_test
    ./compile_clean_test.sh
    echo ""
fi

echo "═══════════════════════════════════════════════════════"
echo "  Test Complete"
echo "═══════════════════════════════════════════════════════"
echo ""
