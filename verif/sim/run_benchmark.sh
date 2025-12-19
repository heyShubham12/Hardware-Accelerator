#!/bin/bash
# CVA6 ADDX Performance Benchmark Runner
# Usage: ./run_benchmark.sh

# Color codes for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

echo -e "${GREEN}========================================${NC}"
echo -e "${GREEN}  CVA6 ADDX Performance Benchmark${NC}"
echo -e "${GREEN}========================================${NC}"
echo ""

# Check if we're in the correct directory
if [ ! -f "cva6.py" ]; then
    echo -e "${RED}Error: cva6.py not found in current directory${NC}"
    echo -e "${YELLOW}Please run this script from /home/shubham/cva6/verif/sim${NC}"
    exit 1
fi

# Source environment
source ./setup_cva6_env.sh

echo -e "${BLUE}Running benchmark on Spike ISS...${NC}"
echo ""

# Run the benchmark directly with Spike (since it reads performance counters)
echo -e "${YELLOW}Running Spike simulation directly...${NC}"
/home/shubham/cva6/tools/spike/bin/spike --isa=rv32imc_zicsr \
    ../tests/custom/addx_test/addx_benchmark_rv32.elf

# Check the result
if [ $? -eq 0 ]; then
    echo ""
    echo -e "${GREEN}========================================${NC}"
    echo -e "${GREEN}  Benchmark completed successfully!${NC}"
    echo -e "${GREEN}========================================${NC}"
    echo ""
    echo -e "${YELLOW}Check the output above for performance metrics${NC}"
else
    echo ""
    echo -e "${RED}========================================${NC}"
    echo -e "${RED}  Benchmark failed!${NC}"
    echo -e "${RED}========================================${NC}"
    exit 1
fi
