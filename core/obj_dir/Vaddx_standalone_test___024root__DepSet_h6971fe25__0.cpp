// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vaddx_standalone_test.h for the primary calling header

#include "Vaddx_standalone_test__pch.h"
#include "Vaddx_standalone_test___024root.h"

VlCoroutine Vaddx_standalone_test___024root___eval_initial__TOP__Vtiming__0(Vaddx_standalone_test___024root* vlSelf);
VlCoroutine Vaddx_standalone_test___024root___eval_initial__TOP__Vtiming__1(Vaddx_standalone_test___024root* vlSelf);
VlCoroutine Vaddx_standalone_test___024root___eval_initial__TOP__Vtiming__2(Vaddx_standalone_test___024root* vlSelf);

void Vaddx_standalone_test___024root___eval_initial(Vaddx_standalone_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaddx_standalone_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddx_standalone_test___024root___eval_initial\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vaddx_standalone_test___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vaddx_standalone_test___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    Vaddx_standalone_test___024root___eval_initial__TOP__Vtiming__2(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__addx_standalone_test__DOT__clk_i__0 
        = vlSelfRef.addx_standalone_test__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__addx_standalone_test__DOT__rst_ni__0 
        = vlSelfRef.addx_standalone_test__DOT__rst_ni;
}

VL_INLINE_OPT VlCoroutine Vaddx_standalone_test___024root___eval_initial__TOP__Vtiming__0(Vaddx_standalone_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaddx_standalone_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddx_standalone_test___024root___eval_initial__TOP__Vtiming__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.addx_standalone_test__DOT__clk_i = 0U;
    while (1U) {
        co_await vlSelfRef.__VdlySched.delay(0x1388ULL, 
                                             nullptr, 
                                             "addx_standalone_test.sv", 
                                             19);
        vlSelfRef.addx_standalone_test__DOT__clk_i 
            = (1U & (~ (IData)(vlSelfRef.addx_standalone_test__DOT__clk_i)));
    }
}

VL_INLINE_OPT VlCoroutine Vaddx_standalone_test___024root___eval_initial__TOP__Vtiming__1(Vaddx_standalone_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaddx_standalone_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddx_standalone_test___024root___eval_initial__TOP__Vtiming__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_WRITEF_NX("\n\n========================================\n     ADDX Accelerator Test\n========================================\n\n",0);
    vlSelfRef.addx_standalone_test__DOT__rst_ni = 0U;
    vlSelfRef.addx_standalone_test__DOT__valid = 0U;
    vlSelfRef.addx_standalone_test__DOT__operand_a = 0ULL;
    vlSelfRef.addx_standalone_test__DOT__operand_b = 0ULL;
    co_await vlSelfRef.__VtrigSched_h431d7217__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_standalone_test.clk_i)", 
                                                         "addx_standalone_test.sv", 
                                                         107);
    co_await vlSelfRef.__VtrigSched_h431d7217__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_standalone_test.clk_i)", 
                                                         "addx_standalone_test.sv", 
                                                         107);
    vlSelfRef.addx_standalone_test__DOT__rst_ni = 1U;
    co_await vlSelfRef.__VtrigSched_h431d7217__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_standalone_test.clk_i)", 
                                                         "addx_standalone_test.sv", 
                                                         109);
    co_await vlSelfRef.__VtrigSched_h431d7217__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_standalone_test.clk_i)", 
                                                         "addx_standalone_test.sv", 
                                                         109);
    VL_WRITEF_NX("\nTest 1: Normal Addition\n----------------------------------------\n",0);
    vlSelfRef.addx_standalone_test__DOT__operand_a = 0x1111111111111111ULL;
    vlSelfRef.addx_standalone_test__DOT__operand_b = 0x2222222222222222ULL;
    vlSelfRef.addx_standalone_test__DOT__valid = 1U;
    co_await vlSelfRef.__VtrigSched_h431d7217__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_standalone_test.clk_i)", 
                                                         "addx_standalone_test.sv", 
                                                         117);
    vlSelfRef.addx_standalone_test__DOT__valid = 0U;
    co_await vlSelfRef.__VtrigSched_h431d7217__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_standalone_test.clk_i)", 
                                                         "addx_standalone_test.sv", 
                                                         119);
    co_await vlSelfRef.__VtrigSched_h431d7217__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_standalone_test.clk_i)", 
                                                         "addx_standalone_test.sv", 
                                                         119);
    VL_WRITEF_NX("\nTest 2: Positive Overflow (Saturation)\n----------------------------------------\n",0);
    vlSelfRef.addx_standalone_test__DOT__operand_a = 0x7fffffffffffffffULL;
    vlSelfRef.addx_standalone_test__DOT__operand_b = 1ULL;
    vlSelfRef.addx_standalone_test__DOT__valid = 1U;
    co_await vlSelfRef.__VtrigSched_h431d7217__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_standalone_test.clk_i)", 
                                                         "addx_standalone_test.sv", 
                                                         127);
    vlSelfRef.addx_standalone_test__DOT__valid = 0U;
    co_await vlSelfRef.__VtrigSched_h431d7217__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_standalone_test.clk_i)", 
                                                         "addx_standalone_test.sv", 
                                                         129);
    co_await vlSelfRef.__VtrigSched_h431d7217__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_standalone_test.clk_i)", 
                                                         "addx_standalone_test.sv", 
                                                         129);
    VL_WRITEF_NX("\nTest 3: Negative Overflow (Saturation)\n----------------------------------------\n",0);
    vlSelfRef.addx_standalone_test__DOT__operand_a = 0x8000000000000000ULL;
    vlSelfRef.addx_standalone_test__DOT__operand_b = 0xffffffffffffffffULL;
    vlSelfRef.addx_standalone_test__DOT__valid = 1U;
    co_await vlSelfRef.__VtrigSched_h431d7217__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_standalone_test.clk_i)", 
                                                         "addx_standalone_test.sv", 
                                                         137);
    vlSelfRef.addx_standalone_test__DOT__valid = 0U;
    co_await vlSelfRef.__VtrigSched_h431d7217__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_standalone_test.clk_i)", 
                                                         "addx_standalone_test.sv", 
                                                         139);
    co_await vlSelfRef.__VtrigSched_h431d7217__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_standalone_test.clk_i)", 
                                                         "addx_standalone_test.sv", 
                                                         139);
    VL_WRITEF_NX("\nTest 4: Mixed Signs (No Overflow)\n----------------------------------------\n",0);
    vlSelfRef.addx_standalone_test__DOT__operand_a = 0x7fffffffffffffffULL;
    vlSelfRef.addx_standalone_test__DOT__operand_b = 0x8000000000000000ULL;
    vlSelfRef.addx_standalone_test__DOT__valid = 1U;
    co_await vlSelfRef.__VtrigSched_h431d7217__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_standalone_test.clk_i)", 
                                                         "addx_standalone_test.sv", 
                                                         147);
    vlSelfRef.addx_standalone_test__DOT__valid = 0U;
    co_await vlSelfRef.__VtrigSched_h431d7217__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_standalone_test.clk_i)", 
                                                         "addx_standalone_test.sv", 
                                                         149);
    co_await vlSelfRef.__VtrigSched_h431d7217__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_standalone_test.clk_i)", 
                                                         "addx_standalone_test.sv", 
                                                         149);
    VL_WRITEF_NX("\nTest 5: Values from addx_raw.c\n----------------------------------------\n",0);
    vlSelfRef.addx_standalone_test__DOT__operand_a = 0x123456789abcdef0ULL;
    vlSelfRef.addx_standalone_test__DOT__operand_b = 0xfedcba987654321ULL;
    vlSelfRef.addx_standalone_test__DOT__valid = 1U;
    co_await vlSelfRef.__VtrigSched_h431d7217__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_standalone_test.clk_i)", 
                                                         "addx_standalone_test.sv", 
                                                         157);
    vlSelfRef.addx_standalone_test__DOT__valid = 0U;
    co_await vlSelfRef.__VtrigSched_h431d7217__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_standalone_test.clk_i)", 
                                                         "addx_standalone_test.sv", 
                                                         159);
    co_await vlSelfRef.__VtrigSched_h431d7217__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_standalone_test.clk_i)", 
                                                         "addx_standalone_test.sv", 
                                                         159);
    VL_WRITEF_NX("\n========================================\n     All Tests Complete!\n========================================\n\n",0);
    co_await vlSelfRef.__VtrigSched_h431d7217__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_standalone_test.clk_i)", 
                                                         "addx_standalone_test.sv", 
                                                         165);
    co_await vlSelfRef.__VtrigSched_h431d7217__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_standalone_test.clk_i)", 
                                                         "addx_standalone_test.sv", 
                                                         165);
    co_await vlSelfRef.__VtrigSched_h431d7217__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_standalone_test.clk_i)", 
                                                         "addx_standalone_test.sv", 
                                                         165);
    co_await vlSelfRef.__VtrigSched_h431d7217__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_standalone_test.clk_i)", 
                                                         "addx_standalone_test.sv", 
                                                         165);
    co_await vlSelfRef.__VtrigSched_h431d7217__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_standalone_test.clk_i)", 
                                                         "addx_standalone_test.sv", 
                                                         165);
    VL_FINISH_MT("addx_standalone_test.sv", 166, "");
}

VL_INLINE_OPT VlCoroutine Vaddx_standalone_test___024root___eval_initial__TOP__Vtiming__2(Vaddx_standalone_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaddx_standalone_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddx_standalone_test___024root___eval_initial__TOP__Vtiming__2\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x989680ULL, 
                                         nullptr, "addx_standalone_test.sv", 
                                         171);
    VL_WRITEF_NX("ERROR: Simulation timeout!\n",0);
    VL_FINISH_MT("addx_standalone_test.sv", 173, "");
}

void Vaddx_standalone_test___024root___act_sequent__TOP__0(Vaddx_standalone_test___024root* vlSelf);

void Vaddx_standalone_test___024root___eval_act(Vaddx_standalone_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaddx_standalone_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddx_standalone_test___024root___eval_act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vaddx_standalone_test___024root___act_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vaddx_standalone_test___024root___act_sequent__TOP__0(Vaddx_standalone_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaddx_standalone_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddx_standalone_test___024root___act_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<3>/*95:0*/ __Vtemp_2;
    VlWide<3>/*95:0*/ __Vtemp_3;
    VlWide<3>/*95:0*/ __Vtemp_4;
    // Body
    __Vtemp_2[0U] = (IData)(vlSelfRef.addx_standalone_test__DOT__operand_a);
    __Vtemp_2[1U] = (IData)((vlSelfRef.addx_standalone_test__DOT__operand_a 
                             >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = (IData)(vlSelfRef.addx_standalone_test__DOT__operand_b);
    __Vtemp_3[1U] = (IData)((vlSelfRef.addx_standalone_test__DOT__operand_b 
                             >> 0x20U));
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.addx_standalone_test__DOT__extended_result[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.addx_standalone_test__DOT__extended_result[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.addx_standalone_test__DOT__extended_result[2U] 
        = (1U & __Vtemp_4[2U]);
    vlSelfRef.addx_standalone_test__DOT__addx_result 
        = ((1U & vlSelfRef.addx_standalone_test__DOT__extended_result[2U])
            ? (((1U & (IData)((vlSelfRef.addx_standalone_test__DOT__operand_a 
                               >> 0x3fU))) == (1U & (IData)(
                                                            (vlSelfRef.addx_standalone_test__DOT__operand_b 
                                                             >> 0x3fU))))
                ? ((1U & (IData)((vlSelfRef.addx_standalone_test__DOT__operand_a 
                                  >> 0x3fU))) ? 0x8000000000000000ULL
                    : 0x7fffffffffffffffULL) : (((QData)((IData)(
                                                                 vlSelfRef.addx_standalone_test__DOT__extended_result[1U])) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  vlSelfRef.addx_standalone_test__DOT__extended_result[0U]))))
            : (((QData)((IData)(vlSelfRef.addx_standalone_test__DOT__extended_result[1U])) 
                << 0x20U) | (QData)((IData)(vlSelfRef.addx_standalone_test__DOT__extended_result[0U]))));
}

void Vaddx_standalone_test___024root___nba_sequent__TOP__0(Vaddx_standalone_test___024root* vlSelf);
void Vaddx_standalone_test___024root___nba_sequent__TOP__1(Vaddx_standalone_test___024root* vlSelf);
void Vaddx_standalone_test___024root___nba_sequent__TOP__2(Vaddx_standalone_test___024root* vlSelf);

void Vaddx_standalone_test___024root___eval_nba(Vaddx_standalone_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaddx_standalone_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddx_standalone_test___024root___eval_nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vaddx_standalone_test___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vaddx_standalone_test___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vaddx_standalone_test___024root___nba_sequent__TOP__2(vlSelf);
    }
}

VL_INLINE_OPT void Vaddx_standalone_test___024root___nba_sequent__TOP__0(Vaddx_standalone_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaddx_standalone_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddx_standalone_test___024root___nba_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vdly__addx_standalone_test__DOT__cycle_counter 
        = vlSelfRef.addx_standalone_test__DOT__cycle_counter;
    vlSelfRef.__Vdly__addx_standalone_test__DOT__cycle_counter 
        = ((IData)(vlSelfRef.addx_standalone_test__DOT__rst_ni)
            ? (1ULL + vlSelfRef.addx_standalone_test__DOT__cycle_counter)
            : 0ULL);
}

VL_INLINE_OPT void Vaddx_standalone_test___024root___nba_sequent__TOP__1(Vaddx_standalone_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaddx_standalone_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddx_standalone_test___024root___nba_sequent__TOP__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<6>/*191:0*/ __Vtemp_4;
    VlWide<3>/*95:0*/ __Vtemp_6;
    VlWide<3>/*95:0*/ __Vtemp_7;
    VlWide<3>/*95:0*/ __Vtemp_8;
    // Body
    if (VL_UNLIKELY(((IData)(vlSelfRef.addx_standalone_test__DOT__rst_ni) 
                     & (IData)(vlSelfRef.addx_standalone_test__DOT__valid)))) {
        VL_WRITEF_NX("================================================================================\n[ADDX ACCELERATOR] Execution at time %0t (Cycle: %0#)\n--------------------------------------------------------------------------------\n  Operand A:  0x%016x (%0d)\n  Operand B:  0x%016x (%0d)\n  Result:     0x%016x (%0d)\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,64,
                     vlSelfRef.addx_standalone_test__DOT__cycle_counter,
                     64,vlSelfRef.addx_standalone_test__DOT__operand_a,
                     64,vlSelfRef.addx_standalone_test__DOT__operand_a,
                     64,vlSelfRef.addx_standalone_test__DOT__operand_b,
                     64,vlSelfRef.addx_standalone_test__DOT__operand_b,
                     64,vlSelfRef.addx_standalone_test__DOT__addx_result,
                     64,vlSelfRef.addx_standalone_test__DOT__addx_result);
        if (VL_LIKELY((1U & vlSelfRef.addx_standalone_test__DOT__extended_result[2U]))) {
            if (((1U & (IData)((vlSelfRef.addx_standalone_test__DOT__operand_a 
                                >> 0x3fU))) == (1U 
                                                & (IData)(
                                                          (vlSelfRef.addx_standalone_test__DOT__operand_b 
                                                           >> 0x3fU))))) {
                if ((1U & (IData)((vlSelfRef.addx_standalone_test__DOT__operand_a 
                                   >> 0x3fU)))) {
                    __Vtemp_4[0U] = 0x30303029U;
                    __Vtemp_4[1U] = 0x30303030U;
                    __Vtemp_4[2U] = 0x30303030U;
                    __Vtemp_4[3U] = 0x30303030U;
                    __Vtemp_4[4U] = 0x28307838U;
                    __Vtemp_4[5U] = 0x4d494e20U;
                } else {
                    __Vtemp_4[0U] = 0x46464629U;
                    __Vtemp_4[1U] = 0x46464646U;
                    __Vtemp_4[2U] = 0x46464646U;
                    __Vtemp_4[3U] = 0x46464646U;
                    __Vtemp_4[4U] = 0x28307837U;
                    __Vtemp_4[5U] = 0x4d415820U;
                }
                VL_WRITEF_NX("  Status:     OVERFLOW DETECTED - Result SATURATED to %s\n",0,
                             192,__Vtemp_4.data());
            } else {
                VL_WRITEF_NX("  Status:     Overflow bit set but operands have different signs (Normal)\n",0);
            }
        } else {
            VL_WRITEF_NX("  Status:     Normal addition (No overflow)\n",0);
        }
        VL_WRITEF_NX("  Mode:       64-bit\n================================================================================\n",0);
    }
    __Vtemp_6[0U] = (IData)(vlSelfRef.addx_standalone_test__DOT__operand_a);
    __Vtemp_6[1U] = (IData)((vlSelfRef.addx_standalone_test__DOT__operand_a 
                             >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = (IData)(vlSelfRef.addx_standalone_test__DOT__operand_b);
    __Vtemp_7[1U] = (IData)((vlSelfRef.addx_standalone_test__DOT__operand_b 
                             >> 0x20U));
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.addx_standalone_test__DOT__extended_result[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.addx_standalone_test__DOT__extended_result[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.addx_standalone_test__DOT__extended_result[2U] 
        = (1U & __Vtemp_8[2U]);
    vlSelfRef.addx_standalone_test__DOT__addx_result 
        = ((1U & vlSelfRef.addx_standalone_test__DOT__extended_result[2U])
            ? (((1U & (IData)((vlSelfRef.addx_standalone_test__DOT__operand_a 
                               >> 0x3fU))) == (1U & (IData)(
                                                            (vlSelfRef.addx_standalone_test__DOT__operand_b 
                                                             >> 0x3fU))))
                ? ((1U & (IData)((vlSelfRef.addx_standalone_test__DOT__operand_a 
                                  >> 0x3fU))) ? 0x8000000000000000ULL
                    : 0x7fffffffffffffffULL) : (((QData)((IData)(
                                                                 vlSelfRef.addx_standalone_test__DOT__extended_result[1U])) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  vlSelfRef.addx_standalone_test__DOT__extended_result[0U]))))
            : (((QData)((IData)(vlSelfRef.addx_standalone_test__DOT__extended_result[1U])) 
                << 0x20U) | (QData)((IData)(vlSelfRef.addx_standalone_test__DOT__extended_result[0U]))));
}

VL_INLINE_OPT void Vaddx_standalone_test___024root___nba_sequent__TOP__2(Vaddx_standalone_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaddx_standalone_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddx_standalone_test___024root___nba_sequent__TOP__2\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.addx_standalone_test__DOT__cycle_counter 
        = vlSelfRef.__Vdly__addx_standalone_test__DOT__cycle_counter;
}

void Vaddx_standalone_test___024root___timing_resume(Vaddx_standalone_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaddx_standalone_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddx_standalone_test___024root___timing_resume\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_h431d7217__0.resume(
                                                   "@(posedge addx_standalone_test.clk_i)");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vaddx_standalone_test___024root___timing_commit(Vaddx_standalone_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaddx_standalone_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddx_standalone_test___024root___timing_commit\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((! (2ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_h431d7217__0.commit(
                                                   "@(posedge addx_standalone_test.clk_i)");
    }
}

void Vaddx_standalone_test___024root___eval_triggers__act(Vaddx_standalone_test___024root* vlSelf);

bool Vaddx_standalone_test___024root___eval_phase__act(Vaddx_standalone_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaddx_standalone_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddx_standalone_test___024root___eval_phase__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<3> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vaddx_standalone_test___024root___eval_triggers__act(vlSelf);
    Vaddx_standalone_test___024root___timing_commit(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vaddx_standalone_test___024root___timing_resume(vlSelf);
        Vaddx_standalone_test___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vaddx_standalone_test___024root___eval_phase__nba(Vaddx_standalone_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaddx_standalone_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddx_standalone_test___024root___eval_phase__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vaddx_standalone_test___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vaddx_standalone_test___024root___dump_triggers__nba(Vaddx_standalone_test___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vaddx_standalone_test___024root___dump_triggers__act(Vaddx_standalone_test___024root* vlSelf);
#endif  // VL_DEBUG

void Vaddx_standalone_test___024root___eval(Vaddx_standalone_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaddx_standalone_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddx_standalone_test___024root___eval\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vaddx_standalone_test___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("addx_standalone_test.sv", 3, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                Vaddx_standalone_test___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("addx_standalone_test.sv", 3, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vaddx_standalone_test___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vaddx_standalone_test___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vaddx_standalone_test___024root___eval_debug_assertions(Vaddx_standalone_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaddx_standalone_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddx_standalone_test___024root___eval_debug_assertions\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
