// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VADDX_REAL_INSTRUCTION_TEST__SYMS_H_
#define VERILATED_VADDX_REAL_INSTRUCTION_TEST__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vaddx_real_instruction_test.h"

// INCLUDE MODULE CLASSES
#include "Vaddx_real_instruction_test___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vaddx_real_instruction_test__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vaddx_real_instruction_test* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vaddx_real_instruction_test___024root TOP;

    // CONSTRUCTORS
    Vaddx_real_instruction_test__Syms(VerilatedContext* contextp, const char* namep, Vaddx_real_instruction_test* modelp);
    ~Vaddx_real_instruction_test__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
