// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vaddx_real_instruction_test.h for the primary calling header

#include "Vaddx_real_instruction_test__pch.h"
#include "Vaddx_real_instruction_test__Syms.h"
#include "Vaddx_real_instruction_test___024root.h"

void Vaddx_real_instruction_test___024root___ctor_var_reset(Vaddx_real_instruction_test___024root* vlSelf);

Vaddx_real_instruction_test___024root::Vaddx_real_instruction_test___024root(Vaddx_real_instruction_test__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vaddx_real_instruction_test___024root___ctor_var_reset(this);
}

void Vaddx_real_instruction_test___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vaddx_real_instruction_test___024root::~Vaddx_real_instruction_test___024root() {
}
