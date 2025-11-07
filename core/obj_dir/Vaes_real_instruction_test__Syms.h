// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VAES_REAL_INSTRUCTION_TEST__SYMS_H_
#define VERILATED_VAES_REAL_INSTRUCTION_TEST__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vaes_real_instruction_test.h"

// INCLUDE MODULE CLASSES
#include "Vaes_real_instruction_test___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vaes_real_instruction_test__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vaes_real_instruction_test* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vaes_real_instruction_test___024root TOP;

    // CONSTRUCTORS
    Vaes_real_instruction_test__Syms(VerilatedContext* contextp, const char* namep, Vaes_real_instruction_test* modelp);
    ~Vaes_real_instruction_test__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
