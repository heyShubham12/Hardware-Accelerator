// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vaddx_standalone_test.h for the primary calling header

#include "Vaddx_standalone_test__pch.h"
#include "Vaddx_standalone_test__Syms.h"
#include "Vaddx_standalone_test___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vaddx_standalone_test___024root___dump_triggers__act(Vaddx_standalone_test___024root* vlSelf);
#endif  // VL_DEBUG

void Vaddx_standalone_test___024root___eval_triggers__act(Vaddx_standalone_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaddx_standalone_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddx_standalone_test___024root___eval_triggers__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.set(0U, (((IData)(vlSelfRef.addx_standalone_test__DOT__clk_i) 
                                        & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__addx_standalone_test__DOT__clk_i__0))) 
                                       | ((~ (IData)(vlSelfRef.addx_standalone_test__DOT__rst_ni)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__addx_standalone_test__DOT__rst_ni__0))));
    vlSelfRef.__VactTriggered.set(1U, ((IData)(vlSelfRef.addx_standalone_test__DOT__clk_i) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__addx_standalone_test__DOT__clk_i__0))));
    vlSelfRef.__VactTriggered.set(2U, vlSelfRef.__VdlySched.awaitingCurrentTime());
    vlSelfRef.__Vtrigprevexpr___TOP__addx_standalone_test__DOT__clk_i__0 
        = vlSelfRef.addx_standalone_test__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__addx_standalone_test__DOT__rst_ni__0 
        = vlSelfRef.addx_standalone_test__DOT__rst_ni;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vaddx_standalone_test___024root___dump_triggers__act(vlSelf);
    }
#endif
}
