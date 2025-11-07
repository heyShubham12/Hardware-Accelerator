// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vaddx_real_instruction_test.h for the primary calling header

#include "Vaddx_real_instruction_test__pch.h"
#include "Vaddx_real_instruction_test___024root.h"

VL_ATTR_COLD void Vaddx_real_instruction_test___024root___eval_static(Vaddx_real_instruction_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaddx_real_instruction_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddx_real_instruction_test___024root___eval_static\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vaddx_real_instruction_test___024root___eval_final(Vaddx_real_instruction_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaddx_real_instruction_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddx_real_instruction_test___024root___eval_final\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vaddx_real_instruction_test___024root___dump_triggers__stl(Vaddx_real_instruction_test___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vaddx_real_instruction_test___024root___eval_phase__stl(Vaddx_real_instruction_test___024root* vlSelf);

VL_ATTR_COLD void Vaddx_real_instruction_test___024root___eval_settle(Vaddx_real_instruction_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaddx_real_instruction_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddx_real_instruction_test___024root___eval_settle\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vaddx_real_instruction_test___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("addx_real_instruction_test.sv", 8, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vaddx_real_instruction_test___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vaddx_real_instruction_test___024root___dump_triggers__stl(Vaddx_real_instruction_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaddx_real_instruction_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddx_real_instruction_test___024root___dump_triggers__stl\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void Vaddx_real_instruction_test___024root___act_sequent__TOP__0(Vaddx_real_instruction_test___024root* vlSelf);

VL_ATTR_COLD void Vaddx_real_instruction_test___024root___eval_stl(Vaddx_real_instruction_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaddx_real_instruction_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddx_real_instruction_test___024root___eval_stl\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vaddx_real_instruction_test___024root___act_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vaddx_real_instruction_test___024root___eval_triggers__stl(Vaddx_real_instruction_test___024root* vlSelf);

VL_ATTR_COLD bool Vaddx_real_instruction_test___024root___eval_phase__stl(Vaddx_real_instruction_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaddx_real_instruction_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddx_real_instruction_test___024root___eval_phase__stl\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vaddx_real_instruction_test___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vaddx_real_instruction_test___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vaddx_real_instruction_test___024root___dump_triggers__act(Vaddx_real_instruction_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaddx_real_instruction_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddx_real_instruction_test___024root___dump_triggers__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge addx_real_instruction_test.clk_i or negedge addx_real_instruction_test.rst_ni)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge addx_real_instruction_test.clk_i)\n");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vaddx_real_instruction_test___024root___dump_triggers__nba(Vaddx_real_instruction_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaddx_real_instruction_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddx_real_instruction_test___024root___dump_triggers__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge addx_real_instruction_test.clk_i or negedge addx_real_instruction_test.rst_ni)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge addx_real_instruction_test.clk_i)\n");
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vaddx_real_instruction_test___024root___ctor_var_reset(Vaddx_real_instruction_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaddx_real_instruction_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddx_real_instruction_test___024root___ctor_var_reset\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->addx_real_instruction_test__DOT__clk_i = VL_RAND_RESET_I(1);
    vlSelf->addx_real_instruction_test__DOT__rst_ni = VL_RAND_RESET_I(1);
    vlSelf->addx_real_instruction_test__DOT__rs1 = VL_RAND_RESET_Q(64);
    vlSelf->addx_real_instruction_test__DOT__rs2 = VL_RAND_RESET_Q(64);
    vlSelf->addx_real_instruction_test__DOT__rd = VL_RAND_RESET_Q(64);
    vlSelf->addx_real_instruction_test__DOT__valid = VL_RAND_RESET_I(1);
    vlSelf->addx_real_instruction_test__DOT__cycle_counter = VL_RAND_RESET_Q(64);
    vlSelf->addx_real_instruction_test__DOT__saturation_occurred = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__addx_real_instruction_test__DOT__cycle_counter = VL_RAND_RESET_Q(64);
    vlSelf->__Vtrigprevexpr___TOP__addx_real_instruction_test__DOT__clk_i__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__addx_real_instruction_test__DOT__rst_ni__0 = VL_RAND_RESET_I(1);
}
