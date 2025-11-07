// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VADDX_STANDALONE_TEST__SYMS_H_
#define VERILATED_VADDX_STANDALONE_TEST__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vaddx_standalone_test.h"

// INCLUDE MODULE CLASSES
#include "Vaddx_standalone_test___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vaddx_standalone_test__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vaddx_standalone_test* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vaddx_standalone_test___024root TOP;

    // CONSTRUCTORS
    Vaddx_standalone_test__Syms(VerilatedContext* contextp, const char* namep, Vaddx_standalone_test* modelp);
    ~Vaddx_standalone_test__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
