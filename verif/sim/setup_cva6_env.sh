#!/bin/bash
# ============================================================================
# CVA6 Environment Setup Script (Silent Mode)
# ============================================================================
# This script sets up all necessary environment variables for CVA6 development
# and testing (RISC-V toolchain, Verilator, Spike, etc.)
#
# Usage: source setup_cva6_env.sh
#        OR
#        . setup_cva6_env.sh
#
# DO NOT execute directly (./setup_cva6_env.sh) - it must be sourced!
# ============================================================================

# Check if script is being sourced (not executed)
if [ "${BASH_SOURCE[0]}" = "${0}" ]; then
    echo "ERROR: This script must be sourced, not executed!"
    echo "Usage: source setup_cva6_env.sh"
    echo "   OR: . setup_cva6_env.sh"
    exit 1
fi

# ============================================================================
# Detect CVA6 Project Root
# ============================================================================

if [ -n "$BASH_SOURCE" ]; then
    SCRIPT_PATH="$BASH_SOURCE[0]"
elif [ -n "$ZSH_VERSION" ]; then
    SCRIPT_PATH="${(%):-%N}"
else
    return 1
fi

export CVA6_ROOT=$(readlink -f $(dirname "${SCRIPT_PATH}")/../..)
export ROOT_PROJECT=${CVA6_ROOT}

# ============================================================================
# RISC-V Toolchain Configuration
# ============================================================================

# Auto-detect RISC-V toolchain if not already set
if [ -z "$RISCV" ]; then
    # Common installation locations
    if [ -d "/home/shubham/riscv-tools" ]; then
        export RISCV=/home/shubham/riscv-tools
    elif [ -d "$HOME/riscv-tools" ]; then
        export RISCV=$HOME/riscv-tools
    elif [ -d "/opt/riscv" ]; then
        export RISCV=/opt/riscv
    else
        return 1
    fi
fi

# Check if toolchain actually exists
if [ ! -d "$RISCV" ]; then
    return 1
fi

# Set toolchain-related environment variables
export LIBRARY_PATH="$RISCV/lib"
export LD_LIBRARY_PATH="$RISCV/lib:$LD_LIBRARY_PATH"
export C_INCLUDE_PATH="$RISCV/include"
export CPLUS_INCLUDE_PATH="$RISCV/include"

# Auto-detect RISC-V tool prefix
if [ -z "$CV_SW_PREFIX" ]; then
    # Look for riscv*-gcc in bin directory
    FIRST_GCC=$(ls -1 $RISCV/bin/riscv*-gcc 2>/dev/null | head -n 1)
    if [ -n "$FIRST_GCC" ]; then
        CV_SW_PREFIX=$(basename "$FIRST_GCC" | sed 's/-gcc$//')-
        export CV_SW_PREFIX
    else
        return 1
    fi
fi

# Set compiler and tools
export RISCV_CC="$RISCV/bin/${CV_SW_PREFIX}gcc"
export RISCV_OBJCOPY="$RISCV/bin/${CV_SW_PREFIX}objcopy"
export RISCV_OBJDUMP="$RISCV/bin/${CV_SW_PREFIX}objdump"
export RISCV_READELF="$RISCV/bin/${CV_SW_PREFIX}readelf"

# Verify GCC exists
if [ ! -f "$RISCV_CC" ]; then
    return 1
fi

# ============================================================================
# CVA6 Project Paths
# ============================================================================

export RTL_PATH="$CVA6_ROOT/"
export TB_PATH="$CVA6_ROOT/verif/tb/core"
export TESTS_PATH="$CVA6_ROOT/verif/tests"

# RISCV-DV & COREV-DV
export RISCV_DV_ROOT="$CVA6_ROOT/verif/sim/dv"
export CVA6_DV_ROOT="$CVA6_ROOT/verif/env/corev-dv"

# ============================================================================
# Verilator Configuration
# ============================================================================

# Auto-detect Verilator installation
if [ -z "$VERILATOR_INSTALL_DIR" ]; then
    # Check common locations
    if [ -d "$CVA6_ROOT/tools/verilator-v5.008" ]; then
        export VERILATOR_INSTALL_DIR="$CVA6_ROOT/tools/verilator-v5.008"
    elif [ -d "$CVA6_ROOT/tools/verilator" ]; then
        export VERILATOR_INSTALL_DIR="$CVA6_ROOT/tools/verilator"
    else
        # Try system verilator
        if command -v verilator &> /dev/null; then
            VERILATOR_BIN=$(command -v verilator)
            export VERILATOR_INSTALL_DIR=$(dirname $(dirname "$VERILATOR_BIN"))
        fi
    fi
fi

# ============================================================================
# Spike ISS Configuration
# ============================================================================

# Auto-detect Spike installation
if [ -z "$SPIKE_INSTALL_DIR" ] || [ "$SPIKE_INSTALL_DIR" = "__local__" ]; then
    if [ -d "$CVA6_ROOT/tools/spike" ]; then
        export SPIKE_INSTALL_DIR="$CVA6_ROOT/tools/spike"
    fi
fi

if [ -z "$SPIKE_SRC_DIR" ] || [ "$SPIKE_SRC_DIR" = "__local__" ]; then
    if [ -d "$CVA6_ROOT/verif/core-v-verif/vendor/riscv/riscv-isa-sim" ]; then
        export SPIKE_SRC_DIR="$CVA6_ROOT/verif/core-v-verif/vendor/riscv/riscv-isa-sim"
    fi
fi

if [ -n "$SPIKE_INSTALL_DIR" ] && [ -d "$SPIKE_INSTALL_DIR" ]; then
    export SPIKE_PATH="$SPIKE_INSTALL_DIR/bin"
fi

# ============================================================================
# Update PATH
# ============================================================================

# Build new PATH with all tools
NEW_PATH=""

# Add Verilator to PATH
if [ -n "$VERILATOR_INSTALL_DIR" ] && [ -d "$VERILATOR_INSTALL_DIR/bin" ]; then
    NEW_PATH="$VERILATOR_INSTALL_DIR/bin"
fi

# Add RISC-V toolchain to PATH
if [ -d "$RISCV/bin" ]; then
    if [ -n "$NEW_PATH" ]; then
        NEW_PATH="$NEW_PATH:$RISCV/bin"
    else
        NEW_PATH="$RISCV/bin"
    fi
fi

# Add Spike to PATH
if [ -n "$SPIKE_PATH" ] && [ -d "$SPIKE_PATH" ]; then
    if [ -n "$NEW_PATH" ]; then
        NEW_PATH="$NEW_PATH:$SPIKE_PATH"
    else
        NEW_PATH="$SPIKE_PATH"
    fi
fi

# Update PATH
if [ -n "$NEW_PATH" ]; then
    export PATH="$NEW_PATH:$PATH"
fi

# ============================================================================
# Additional Tool Configurations
# ============================================================================

# DTC (Device Tree Compiler) - if available
if command -v dtc &> /dev/null; then
    export DTC=$(command -v dtc)
fi

return 0
