// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vaes_real_instruction_test.h for the primary calling header

#include "Vaes_real_instruction_test__pch.h"
#include "Vaes_real_instruction_test__Syms.h"
#include "Vaes_real_instruction_test___024root.h"

void Vaes_real_instruction_test___024root___ctor_var_reset(Vaes_real_instruction_test___024root* vlSelf);

Vaes_real_instruction_test___024root::Vaes_real_instruction_test___024root(Vaes_real_instruction_test__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vaes_real_instruction_test___024root___ctor_var_reset(this);
}

void Vaes_real_instruction_test___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vaes_real_instruction_test___024root::~Vaes_real_instruction_test___024root() {
}
