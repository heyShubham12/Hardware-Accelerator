// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vaes_real_instruction_test.h for the primary calling header

#include "Vaes_real_instruction_test__pch.h"
#include "Vaes_real_instruction_test__Syms.h"
#include "Vaes_real_instruction_test___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vaes_real_instruction_test___024root___dump_triggers__stl(Vaes_real_instruction_test___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vaes_real_instruction_test___024root___eval_triggers__stl(Vaes_real_instruction_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaes_real_instruction_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaes_real_instruction_test___024root___eval_triggers__stl\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.set(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vaes_real_instruction_test___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
