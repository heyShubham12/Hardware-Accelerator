#!/bin/bash
# CVA6 ADDX Test Runner Script
# Usage: source setup_cva6_env.sh && ./run.sh

# Color codes for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

echo -e "${GREEN}========================================${NC}"
echo -e "${GREEN}  CVA6 ADDX Test Runner${NC}"
echo -e "${GREEN}========================================${NC}"
echo ""

# Check if we're in the correct directory
if [ ! -f "cva6.py" ]; then
    echo -e "${RED}Error: cva6.py not found in current directory${NC}"
    echo -e "${YELLOW}Please run this script from /home/shubham/cva6/verif/sim${NC}"
    exit 1
fi

# Check if environment is set up
if [ -z "$RISCV" ]; then
    echo -e "${YELLOW}Warning: RISCV environment variable not set${NC}"
    echo -e "${YELLOW}Please run: source setup_cva6_env.sh${NC}"
    echo ""
fi

# Optional: Clean previous build (uncomment if you want to always rebuild)
# echo -e "${YELLOW}Cleaning previous build...${NC}"
#uncomment the below line if want to rebuild from scratch
# rm -rf /home/shubham/cva6/work-ver

echo -e "${GREEN}Running ADDX tests with Spike and Verilator...${NC}"
echo ""

# Run the test
python3 cva6.py \
    --target=cv32a65x \
    --elf_tests=../tests/custom/addx_test/addx_test_rv32.o \
    --iss=spike,veri-testharness \
    --iss_yaml=cva6.yaml

# Check the result
if [ $? -eq 0 ]; then
    echo ""
    echo -e "${GREEN}========================================${NC}"
    echo -e "${GREEN}  Test completed successfully!${NC}"
    echo -e "${GREEN}========================================${NC}"
else
    echo ""
    echo -e "${RED}========================================${NC}"
    echo -e "${RED}  Test failed!${NC}"
    echo -e "${RED}========================================${NC}"
    exit 1
fi
