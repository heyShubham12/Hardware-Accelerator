// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vaddx_real_instruction_test.h for the primary calling header

#include "Vaddx_real_instruction_test__pch.h"
#include "Vaddx_real_instruction_test___024root.h"

VlCoroutine Vaddx_real_instruction_test___024root___eval_initial__TOP__Vtiming__0(Vaddx_real_instruction_test___024root* vlSelf);
VlCoroutine Vaddx_real_instruction_test___024root___eval_initial__TOP__Vtiming__1(Vaddx_real_instruction_test___024root* vlSelf);
VlCoroutine Vaddx_real_instruction_test___024root___eval_initial__TOP__Vtiming__2(Vaddx_real_instruction_test___024root* vlSelf);

void Vaddx_real_instruction_test___024root___eval_initial(Vaddx_real_instruction_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaddx_real_instruction_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddx_real_instruction_test___024root___eval_initial\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vaddx_real_instruction_test___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vaddx_real_instruction_test___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    Vaddx_real_instruction_test___024root___eval_initial__TOP__Vtiming__2(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__addx_real_instruction_test__DOT__clk_i__0 
        = vlSelfRef.addx_real_instruction_test__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__addx_real_instruction_test__DOT__rst_ni__0 
        = vlSelfRef.addx_real_instruction_test__DOT__rst_ni;
}

VL_INLINE_OPT VlCoroutine Vaddx_real_instruction_test___024root___eval_initial__TOP__Vtiming__0(Vaddx_real_instruction_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaddx_real_instruction_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddx_real_instruction_test___024root___eval_initial__TOP__Vtiming__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.addx_real_instruction_test__DOT__clk_i = 0U;
    while (1U) {
        co_await vlSelfRef.__VdlySched.delay(0x1388ULL, 
                                             nullptr, 
                                             "addx_real_instruction_test.sv", 
                                             27);
        vlSelfRef.addx_real_instruction_test__DOT__clk_i 
            = (1U & (~ (IData)(vlSelfRef.addx_real_instruction_test__DOT__clk_i)));
    }
}

VL_INLINE_OPT VlCoroutine Vaddx_real_instruction_test___024root___eval_initial__TOP__Vtiming__1(Vaddx_real_instruction_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaddx_real_instruction_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddx_real_instruction_test___024root___eval_initial__TOP__Vtiming__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ addx_real_instruction_test__DOT__test_num;
    addx_real_instruction_test__DOT__test_num = 0;
    std::string __Vtask_addx_real_instruction_test__DOT__execute_addx__0__test_description;
    QData/*63:0*/ __Vtask_addx_real_instruction_test__DOT__execute_addx__0__operand1;
    __Vtask_addx_real_instruction_test__DOT__execute_addx__0__operand1 = 0;
    QData/*63:0*/ __Vtask_addx_real_instruction_test__DOT__execute_addx__0__operand2;
    __Vtask_addx_real_instruction_test__DOT__execute_addx__0__operand2 = 0;
    std::string __Vtask_addx_real_instruction_test__DOT__execute_addx__1__test_description;
    QData/*63:0*/ __Vtask_addx_real_instruction_test__DOT__execute_addx__1__operand1;
    __Vtask_addx_real_instruction_test__DOT__execute_addx__1__operand1 = 0;
    QData/*63:0*/ __Vtask_addx_real_instruction_test__DOT__execute_addx__1__operand2;
    __Vtask_addx_real_instruction_test__DOT__execute_addx__1__operand2 = 0;
    std::string __Vtask_addx_real_instruction_test__DOT__execute_addx__2__test_description;
    QData/*63:0*/ __Vtask_addx_real_instruction_test__DOT__execute_addx__2__operand1;
    __Vtask_addx_real_instruction_test__DOT__execute_addx__2__operand1 = 0;
    QData/*63:0*/ __Vtask_addx_real_instruction_test__DOT__execute_addx__2__operand2;
    __Vtask_addx_real_instruction_test__DOT__execute_addx__2__operand2 = 0;
    std::string __Vtask_addx_real_instruction_test__DOT__execute_addx__3__test_description;
    QData/*63:0*/ __Vtask_addx_real_instruction_test__DOT__execute_addx__3__operand1;
    __Vtask_addx_real_instruction_test__DOT__execute_addx__3__operand1 = 0;
    QData/*63:0*/ __Vtask_addx_real_instruction_test__DOT__execute_addx__3__operand2;
    __Vtask_addx_real_instruction_test__DOT__execute_addx__3__operand2 = 0;
    std::string __Vtask_addx_real_instruction_test__DOT__execute_addx__4__test_description;
    QData/*63:0*/ __Vtask_addx_real_instruction_test__DOT__execute_addx__4__operand1;
    __Vtask_addx_real_instruction_test__DOT__execute_addx__4__operand1 = 0;
    QData/*63:0*/ __Vtask_addx_real_instruction_test__DOT__execute_addx__4__operand2;
    __Vtask_addx_real_instruction_test__DOT__execute_addx__4__operand2 = 0;
    std::string __Vtask_addx_real_instruction_test__DOT__execute_addx__5__test_description;
    QData/*63:0*/ __Vtask_addx_real_instruction_test__DOT__execute_addx__5__operand1;
    __Vtask_addx_real_instruction_test__DOT__execute_addx__5__operand1 = 0;
    QData/*63:0*/ __Vtask_addx_real_instruction_test__DOT__execute_addx__5__operand2;
    __Vtask_addx_real_instruction_test__DOT__execute_addx__5__operand2 = 0;
    std::string __Vtask_addx_real_instruction_test__DOT__execute_addx__6__test_description;
    QData/*63:0*/ __Vtask_addx_real_instruction_test__DOT__execute_addx__6__operand1;
    __Vtask_addx_real_instruction_test__DOT__execute_addx__6__operand1 = 0;
    QData/*63:0*/ __Vtask_addx_real_instruction_test__DOT__execute_addx__6__operand2;
    __Vtask_addx_real_instruction_test__DOT__execute_addx__6__operand2 = 0;
    std::string __Vtask_addx_real_instruction_test__DOT__execute_addx__7__test_description;
    QData/*63:0*/ __Vtask_addx_real_instruction_test__DOT__execute_addx__7__operand1;
    __Vtask_addx_real_instruction_test__DOT__execute_addx__7__operand1 = 0;
    QData/*63:0*/ __Vtask_addx_real_instruction_test__DOT__execute_addx__7__operand2;
    __Vtask_addx_real_instruction_test__DOT__execute_addx__7__operand2 = 0;
    std::string __Vtask_addx_real_instruction_test__DOT__execute_addx__8__test_description;
    QData/*63:0*/ __Vtask_addx_real_instruction_test__DOT__execute_addx__8__operand1;
    __Vtask_addx_real_instruction_test__DOT__execute_addx__8__operand1 = 0;
    QData/*63:0*/ __Vtask_addx_real_instruction_test__DOT__execute_addx__8__operand2;
    __Vtask_addx_real_instruction_test__DOT__execute_addx__8__operand2 = 0;
    std::string __Vtask_addx_real_instruction_test__DOT__execute_addx__9__test_description;
    QData/*63:0*/ __Vtask_addx_real_instruction_test__DOT__execute_addx__9__operand1;
    __Vtask_addx_real_instruction_test__DOT__execute_addx__9__operand1 = 0;
    QData/*63:0*/ __Vtask_addx_real_instruction_test__DOT__execute_addx__9__operand2;
    __Vtask_addx_real_instruction_test__DOT__execute_addx__9__operand2 = 0;
    std::string __Vtask_addx_real_instruction_test__DOT__execute_addx__10__test_description;
    QData/*63:0*/ __Vtask_addx_real_instruction_test__DOT__execute_addx__10__operand1;
    __Vtask_addx_real_instruction_test__DOT__execute_addx__10__operand1 = 0;
    QData/*63:0*/ __Vtask_addx_real_instruction_test__DOT__execute_addx__10__operand2;
    __Vtask_addx_real_instruction_test__DOT__execute_addx__10__operand2 = 0;
    std::string __Vtask_addx_real_instruction_test__DOT__execute_addx__11__test_description;
    QData/*63:0*/ __Vtask_addx_real_instruction_test__DOT__execute_addx__11__operand1;
    __Vtask_addx_real_instruction_test__DOT__execute_addx__11__operand1 = 0;
    QData/*63:0*/ __Vtask_addx_real_instruction_test__DOT__execute_addx__11__operand2;
    __Vtask_addx_real_instruction_test__DOT__execute_addx__11__operand2 = 0;
    // Body
    VL_WRITEF_NX("\n################################################################################\n#                                                                              #\n#              CVA6 ADDX Custom Instruction Hardware Test                     #\n#                                                                              #\n#  ADDX: Custom saturating addition instruction                               #\n#  Format: ADDX rd, rs1, rs2                                                  #\n",0);
    VL_WRITEF_NX("#  Operation: rd = saturate(rs1 + rs2)                                        #\n#                                                                              #\n################################################################################\n\n",0);
    vlSelfRef.addx_real_instruction_test__DOT__rst_ni = 0U;
    vlSelfRef.addx_real_instruction_test__DOT__valid = 0U;
    vlSelfRef.addx_real_instruction_test__DOT__rs1 = 0ULL;
    vlSelfRef.addx_real_instruction_test__DOT__rs2 = 0ULL;
    addx_real_instruction_test__DOT__test_num = 1U;
    VL_WRITEF_NX(">>> Initializing ADDX accelerator...\n",0);
    co_await vlSelfRef.__VtrigSched_hd97f067f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_real_instruction_test.clk_i)", 
                                                         "addx_real_instruction_test.sv", 
                                                         158);
    co_await vlSelfRef.__VtrigSched_hd97f067f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_real_instruction_test.clk_i)", 
                                                         "addx_real_instruction_test.sv", 
                                                         158);
    co_await vlSelfRef.__VtrigSched_hd97f067f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_real_instruction_test.clk_i)", 
                                                         "addx_real_instruction_test.sv", 
                                                         158);
    vlSelfRef.addx_real_instruction_test__DOT__rst_ni = 1U;
    co_await vlSelfRef.__VtrigSched_hd97f067f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_real_instruction_test.clk_i)", 
                                                         "addx_real_instruction_test.sv", 
                                                         160);
    co_await vlSelfRef.__VtrigSched_hd97f067f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_real_instruction_test.clk_i)", 
                                                         "addx_real_instruction_test.sv", 
                                                         160);
    VL_WRITEF_NX(">>> ADDX accelerator ready!\n\n",0);
    __Vtask_addx_real_instruction_test__DOT__execute_addx__0__operand2 = 0x25ULL;
    __Vtask_addx_real_instruction_test__DOT__execute_addx__0__operand1 = 0x19ULL;
    __Vtask_addx_real_instruction_test__DOT__execute_addx__0__test_description = 
        std::string{"Basic Addition: 25 + 37"};
    VL_WRITEF_NX("\n\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n  TEST %0d: %@\n\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n",0,
                 32,addx_real_instruction_test__DOT__test_num,
                 -1,&(__Vtask_addx_real_instruction_test__DOT__execute_addx__0__test_description));
    co_await vlSelfRef.__VtrigSched_hd97f067f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_real_instruction_test.clk_i)", 
                                                         "addx_real_instruction_test.sv", 
                                                         120);
    vlSelfRef.addx_real_instruction_test__DOT__rs1 
        = __Vtask_addx_real_instruction_test__DOT__execute_addx__0__operand1;
    vlSelfRef.addx_real_instruction_test__DOT__rs2 
        = __Vtask_addx_real_instruction_test__DOT__execute_addx__0__operand2;
    vlSelfRef.addx_real_instruction_test__DOT__valid = 1U;
    co_await vlSelfRef.__VtrigSched_hd97f067f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_real_instruction_test.clk_i)", 
                                                         "addx_real_instruction_test.sv", 
                                                         125);
    vlSelfRef.addx_real_instruction_test__DOT__valid = 0U;
    co_await vlSelfRef.__VtrigSched_hd97f067f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_real_instruction_test.clk_i)", 
                                                         "addx_real_instruction_test.sv", 
                                                         128);
    addx_real_instruction_test__DOT__test_num = ((IData)(1U) 
                                                 + addx_real_instruction_test__DOT__test_num);
    __Vtask_addx_real_instruction_test__DOT__execute_addx__1__operand2 = 0x7d0ULL;
    __Vtask_addx_real_instruction_test__DOT__execute_addx__1__operand1 = 0x3e8ULL;
    __Vtask_addx_real_instruction_test__DOT__execute_addx__1__test_description = 
        std::string{"Medium Numbers: 1000 + 2000"};
    VL_WRITEF_NX("\n\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n  TEST %0d: %@\n\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n",0,
                 32,addx_real_instruction_test__DOT__test_num,
                 -1,&(__Vtask_addx_real_instruction_test__DOT__execute_addx__1__test_description));
    co_await vlSelfRef.__VtrigSched_hd97f067f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_real_instruction_test.clk_i)", 
                                                         "addx_real_instruction_test.sv", 
                                                         120);
    vlSelfRef.addx_real_instruction_test__DOT__rs1 
        = __Vtask_addx_real_instruction_test__DOT__execute_addx__1__operand1;
    vlSelfRef.addx_real_instruction_test__DOT__rs2 
        = __Vtask_addx_real_instruction_test__DOT__execute_addx__1__operand2;
    vlSelfRef.addx_real_instruction_test__DOT__valid = 1U;
    co_await vlSelfRef.__VtrigSched_hd97f067f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_real_instruction_test.clk_i)", 
                                                         "addx_real_instruction_test.sv", 
                                                         125);
    vlSelfRef.addx_real_instruction_test__DOT__valid = 0U;
    co_await vlSelfRef.__VtrigSched_hd97f067f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_real_instruction_test.clk_i)", 
                                                         "addx_real_instruction_test.sv", 
                                                         128);
    addx_real_instruction_test__DOT__test_num = ((IData)(1U) 
                                                 + addx_real_instruction_test__DOT__test_num);
    __Vtask_addx_real_instruction_test__DOT__execute_addx__2__operand2 = 0x5678ULL;
    __Vtask_addx_real_instruction_test__DOT__execute_addx__2__operand1 = 0x1234ULL;
    __Vtask_addx_real_instruction_test__DOT__execute_addx__2__test_description = 
        std::string{"Hex Values: 0x1234 + 0x5678"};
    VL_WRITEF_NX("\n\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n  TEST %0d: %@\n\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n",0,
                 32,addx_real_instruction_test__DOT__test_num,
                 -1,&(__Vtask_addx_real_instruction_test__DOT__execute_addx__2__test_description));
    co_await vlSelfRef.__VtrigSched_hd97f067f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_real_instruction_test.clk_i)", 
                                                         "addx_real_instruction_test.sv", 
                                                         120);
    vlSelfRef.addx_real_instruction_test__DOT__rs1 
        = __Vtask_addx_real_instruction_test__DOT__execute_addx__2__operand1;
    vlSelfRef.addx_real_instruction_test__DOT__rs2 
        = __Vtask_addx_real_instruction_test__DOT__execute_addx__2__operand2;
    vlSelfRef.addx_real_instruction_test__DOT__valid = 1U;
    co_await vlSelfRef.__VtrigSched_hd97f067f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_real_instruction_test.clk_i)", 
                                                         "addx_real_instruction_test.sv", 
                                                         125);
    vlSelfRef.addx_real_instruction_test__DOT__valid = 0U;
    co_await vlSelfRef.__VtrigSched_hd97f067f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_real_instruction_test.clk_i)", 
                                                         "addx_real_instruction_test.sv", 
                                                         128);
    addx_real_instruction_test__DOT__test_num = ((IData)(1U) 
                                                 + addx_real_instruction_test__DOT__test_num);
    __Vtask_addx_real_instruction_test__DOT__execute_addx__3__operand2 = 0x1e8480ULL;
    __Vtask_addx_real_instruction_test__DOT__execute_addx__3__operand1 = 0xf4240ULL;
    __Vtask_addx_real_instruction_test__DOT__execute_addx__3__test_description = 
        std::string{"Large Numbers: 1000000 + 2000000"};
    VL_WRITEF_NX("\n\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n  TEST %0d: %@\n\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n",0,
                 32,addx_real_instruction_test__DOT__test_num,
                 -1,&(__Vtask_addx_real_instruction_test__DOT__execute_addx__3__test_description));
    co_await vlSelfRef.__VtrigSched_hd97f067f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_real_instruction_test.clk_i)", 
                                                         "addx_real_instruction_test.sv", 
                                                         120);
    vlSelfRef.addx_real_instruction_test__DOT__rs1 
        = __Vtask_addx_real_instruction_test__DOT__execute_addx__3__operand1;
    vlSelfRef.addx_real_instruction_test__DOT__rs2 
        = __Vtask_addx_real_instruction_test__DOT__execute_addx__3__operand2;
    vlSelfRef.addx_real_instruction_test__DOT__valid = 1U;
    co_await vlSelfRef.__VtrigSched_hd97f067f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_real_instruction_test.clk_i)", 
                                                         "addx_real_instruction_test.sv", 
                                                         125);
    vlSelfRef.addx_real_instruction_test__DOT__valid = 0U;
    co_await vlSelfRef.__VtrigSched_hd97f067f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_real_instruction_test.clk_i)", 
                                                         "addx_real_instruction_test.sv", 
                                                         128);
    addx_real_instruction_test__DOT__test_num = ((IData)(1U) 
                                                 + addx_real_instruction_test__DOT__test_num);
    __Vtask_addx_real_instruction_test__DOT__execute_addx__4__operand2 = 0xffffffffffffff38ULL;
    __Vtask_addx_real_instruction_test__DOT__execute_addx__4__operand1 = 0xffffffffffffff9cULL;
    __Vtask_addx_real_instruction_test__DOT__execute_addx__4__test_description = 
        std::string{"Negative Addition: (-100) + (-200)"};
    VL_WRITEF_NX("\n\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n  TEST %0d: %@\n\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n",0,
                 32,addx_real_instruction_test__DOT__test_num,
                 -1,&(__Vtask_addx_real_instruction_test__DOT__execute_addx__4__test_description));
    co_await vlSelfRef.__VtrigSched_hd97f067f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_real_instruction_test.clk_i)", 
                                                         "addx_real_instruction_test.sv", 
                                                         120);
    vlSelfRef.addx_real_instruction_test__DOT__rs1 
        = __Vtask_addx_real_instruction_test__DOT__execute_addx__4__operand1;
    vlSelfRef.addx_real_instruction_test__DOT__rs2 
        = __Vtask_addx_real_instruction_test__DOT__execute_addx__4__operand2;
    vlSelfRef.addx_real_instruction_test__DOT__valid = 1U;
    co_await vlSelfRef.__VtrigSched_hd97f067f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_real_instruction_test.clk_i)", 
                                                         "addx_real_instruction_test.sv", 
                                                         125);
    vlSelfRef.addx_real_instruction_test__DOT__valid = 0U;
    co_await vlSelfRef.__VtrigSched_hd97f067f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_real_instruction_test.clk_i)", 
                                                         "addx_real_instruction_test.sv", 
                                                         128);
    addx_real_instruction_test__DOT__test_num = ((IData)(1U) 
                                                 + addx_real_instruction_test__DOT__test_num);
    __Vtask_addx_real_instruction_test__DOT__execute_addx__5__operand2 = 0xfffffffffffffed4ULL;
    __Vtask_addx_real_instruction_test__DOT__execute_addx__5__operand1 = 0x1f4ULL;
    __Vtask_addx_real_instruction_test__DOT__execute_addx__5__test_description = 
        std::string{"Mixed Signs: 500 + (-300)"};
    VL_WRITEF_NX("\n\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n  TEST %0d: %@\n\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n",0,
                 32,addx_real_instruction_test__DOT__test_num,
                 -1,&(__Vtask_addx_real_instruction_test__DOT__execute_addx__5__test_description));
    co_await vlSelfRef.__VtrigSched_hd97f067f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_real_instruction_test.clk_i)", 
                                                         "addx_real_instruction_test.sv", 
                                                         120);
    vlSelfRef.addx_real_instruction_test__DOT__rs1 
        = __Vtask_addx_real_instruction_test__DOT__execute_addx__5__operand1;
    vlSelfRef.addx_real_instruction_test__DOT__rs2 
        = __Vtask_addx_real_instruction_test__DOT__execute_addx__5__operand2;
    vlSelfRef.addx_real_instruction_test__DOT__valid = 1U;
    co_await vlSelfRef.__VtrigSched_hd97f067f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_real_instruction_test.clk_i)", 
                                                         "addx_real_instruction_test.sv", 
                                                         125);
    vlSelfRef.addx_real_instruction_test__DOT__valid = 0U;
    co_await vlSelfRef.__VtrigSched_hd97f067f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_real_instruction_test.clk_i)", 
                                                         "addx_real_instruction_test.sv", 
                                                         128);
    addx_real_instruction_test__DOT__test_num = ((IData)(1U) 
                                                 + addx_real_instruction_test__DOT__test_num);
    __Vtask_addx_real_instruction_test__DOT__execute_addx__6__operand2 = 1ULL;
    __Vtask_addx_real_instruction_test__DOT__execute_addx__6__operand1 = 0x7fffffffffffffffULL;
    __Vtask_addx_real_instruction_test__DOT__execute_addx__6__test_description = 
        std::string{"OVERFLOW TEST: MAX_INT + 1"};
    VL_WRITEF_NX("\n\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n  TEST %0d: %@\n\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n",0,
                 32,addx_real_instruction_test__DOT__test_num,
                 -1,&(__Vtask_addx_real_instruction_test__DOT__execute_addx__6__test_description));
    co_await vlSelfRef.__VtrigSched_hd97f067f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_real_instruction_test.clk_i)", 
                                                         "addx_real_instruction_test.sv", 
                                                         120);
    vlSelfRef.addx_real_instruction_test__DOT__rs1 
        = __Vtask_addx_real_instruction_test__DOT__execute_addx__6__operand1;
    vlSelfRef.addx_real_instruction_test__DOT__rs2 
        = __Vtask_addx_real_instruction_test__DOT__execute_addx__6__operand2;
    vlSelfRef.addx_real_instruction_test__DOT__valid = 1U;
    co_await vlSelfRef.__VtrigSched_hd97f067f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_real_instruction_test.clk_i)", 
                                                         "addx_real_instruction_test.sv", 
                                                         125);
    vlSelfRef.addx_real_instruction_test__DOT__valid = 0U;
    co_await vlSelfRef.__VtrigSched_hd97f067f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_real_instruction_test.clk_i)", 
                                                         "addx_real_instruction_test.sv", 
                                                         128);
    addx_real_instruction_test__DOT__test_num = ((IData)(1U) 
                                                 + addx_real_instruction_test__DOT__test_num);
    __Vtask_addx_real_instruction_test__DOT__execute_addx__7__operand2 = 0x3e8ULL;
    __Vtask_addx_real_instruction_test__DOT__execute_addx__7__operand1 = 0x7fffffffffffffffULL;
    __Vtask_addx_real_instruction_test__DOT__execute_addx__7__test_description = 
        std::string{"OVERFLOW TEST: MAX_INT + 1000"};
    VL_WRITEF_NX("\n\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n  TEST %0d: %@\n\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n",0,
                 32,addx_real_instruction_test__DOT__test_num,
                 -1,&(__Vtask_addx_real_instruction_test__DOT__execute_addx__7__test_description));
    co_await vlSelfRef.__VtrigSched_hd97f067f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_real_instruction_test.clk_i)", 
                                                         "addx_real_instruction_test.sv", 
                                                         120);
    vlSelfRef.addx_real_instruction_test__DOT__rs1 
        = __Vtask_addx_real_instruction_test__DOT__execute_addx__7__operand1;
    vlSelfRef.addx_real_instruction_test__DOT__rs2 
        = __Vtask_addx_real_instruction_test__DOT__execute_addx__7__operand2;
    vlSelfRef.addx_real_instruction_test__DOT__valid = 1U;
    co_await vlSelfRef.__VtrigSched_hd97f067f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_real_instruction_test.clk_i)", 
                                                         "addx_real_instruction_test.sv", 
                                                         125);
    vlSelfRef.addx_real_instruction_test__DOT__valid = 0U;
    co_await vlSelfRef.__VtrigSched_hd97f067f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_real_instruction_test.clk_i)", 
                                                         "addx_real_instruction_test.sv", 
                                                         128);
    addx_real_instruction_test__DOT__test_num = ((IData)(1U) 
                                                 + addx_real_instruction_test__DOT__test_num);
    __Vtask_addx_real_instruction_test__DOT__execute_addx__8__operand2 = 0xffffffffffffffffULL;
    __Vtask_addx_real_instruction_test__DOT__execute_addx__8__operand1 = 0x8000000000000000ULL;
    __Vtask_addx_real_instruction_test__DOT__execute_addx__8__test_description = 
        std::string{"OVERFLOW TEST: MIN_INT + (-1)"};
    VL_WRITEF_NX("\n\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n  TEST %0d: %@\n\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n",0,
                 32,addx_real_instruction_test__DOT__test_num,
                 -1,&(__Vtask_addx_real_instruction_test__DOT__execute_addx__8__test_description));
    co_await vlSelfRef.__VtrigSched_hd97f067f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_real_instruction_test.clk_i)", 
                                                         "addx_real_instruction_test.sv", 
                                                         120);
    vlSelfRef.addx_real_instruction_test__DOT__rs1 
        = __Vtask_addx_real_instruction_test__DOT__execute_addx__8__operand1;
    vlSelfRef.addx_real_instruction_test__DOT__rs2 
        = __Vtask_addx_real_instruction_test__DOT__execute_addx__8__operand2;
    vlSelfRef.addx_real_instruction_test__DOT__valid = 1U;
    co_await vlSelfRef.__VtrigSched_hd97f067f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_real_instruction_test.clk_i)", 
                                                         "addx_real_instruction_test.sv", 
                                                         125);
    vlSelfRef.addx_real_instruction_test__DOT__valid = 0U;
    co_await vlSelfRef.__VtrigSched_hd97f067f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_real_instruction_test.clk_i)", 
                                                         "addx_real_instruction_test.sv", 
                                                         128);
    addx_real_instruction_test__DOT__test_num = ((IData)(1U) 
                                                 + addx_real_instruction_test__DOT__test_num);
    __Vtask_addx_real_instruction_test__DOT__execute_addx__9__operand2 = 0ULL;
    __Vtask_addx_real_instruction_test__DOT__execute_addx__9__operand1 = 0ULL;
    __Vtask_addx_real_instruction_test__DOT__execute_addx__9__test_description = 
        std::string{"Edge Case: 0 + 0"};
    VL_WRITEF_NX("\n\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n  TEST %0d: %@\n\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n",0,
                 32,addx_real_instruction_test__DOT__test_num,
                 -1,&(__Vtask_addx_real_instruction_test__DOT__execute_addx__9__test_description));
    co_await vlSelfRef.__VtrigSched_hd97f067f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_real_instruction_test.clk_i)", 
                                                         "addx_real_instruction_test.sv", 
                                                         120);
    vlSelfRef.addx_real_instruction_test__DOT__rs1 
        = __Vtask_addx_real_instruction_test__DOT__execute_addx__9__operand1;
    vlSelfRef.addx_real_instruction_test__DOT__rs2 
        = __Vtask_addx_real_instruction_test__DOT__execute_addx__9__operand2;
    vlSelfRef.addx_real_instruction_test__DOT__valid = 1U;
    co_await vlSelfRef.__VtrigSched_hd97f067f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_real_instruction_test.clk_i)", 
                                                         "addx_real_instruction_test.sv", 
                                                         125);
    vlSelfRef.addx_real_instruction_test__DOT__valid = 0U;
    co_await vlSelfRef.__VtrigSched_hd97f067f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_real_instruction_test.clk_i)", 
                                                         "addx_real_instruction_test.sv", 
                                                         128);
    addx_real_instruction_test__DOT__test_num = ((IData)(1U) 
                                                 + addx_real_instruction_test__DOT__test_num);
    __Vtask_addx_real_instruction_test__DOT__execute_addx__10__operand2 = 0x1000ULL;
    __Vtask_addx_real_instruction_test__DOT__execute_addx__10__operand1 = 0x80000000ULL;
    __Vtask_addx_real_instruction_test__DOT__execute_addx__10__test_description = 
        std::string{"Address Calculation: 0x80000000 + 0x1000"};
    VL_WRITEF_NX("\n\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n  TEST %0d: %@\n\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n",0,
                 32,addx_real_instruction_test__DOT__test_num,
                 -1,&(__Vtask_addx_real_instruction_test__DOT__execute_addx__10__test_description));
    co_await vlSelfRef.__VtrigSched_hd97f067f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_real_instruction_test.clk_i)", 
                                                         "addx_real_instruction_test.sv", 
                                                         120);
    vlSelfRef.addx_real_instruction_test__DOT__rs1 
        = __Vtask_addx_real_instruction_test__DOT__execute_addx__10__operand1;
    vlSelfRef.addx_real_instruction_test__DOT__rs2 
        = __Vtask_addx_real_instruction_test__DOT__execute_addx__10__operand2;
    vlSelfRef.addx_real_instruction_test__DOT__valid = 1U;
    co_await vlSelfRef.__VtrigSched_hd97f067f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_real_instruction_test.clk_i)", 
                                                         "addx_real_instruction_test.sv", 
                                                         125);
    vlSelfRef.addx_real_instruction_test__DOT__valid = 0U;
    co_await vlSelfRef.__VtrigSched_hd97f067f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_real_instruction_test.clk_i)", 
                                                         "addx_real_instruction_test.sv", 
                                                         128);
    addx_real_instruction_test__DOT__test_num = ((IData)(1U) 
                                                 + addx_real_instruction_test__DOT__test_num);
    __Vtask_addx_real_instruction_test__DOT__execute_addx__11__operand2 = 0xc8ULL;
    __Vtask_addx_real_instruction_test__DOT__execute_addx__11__operand1 = 0x7fffffffffffff9bULL;
    __Vtask_addx_real_instruction_test__DOT__execute_addx__11__test_description = 
        std::string{"OVERFLOW TEST: (MAX_INT - 100) + 200"};
    VL_WRITEF_NX("\n\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n  TEST %0d: %@\n\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n",0,
                 32,addx_real_instruction_test__DOT__test_num,
                 -1,&(__Vtask_addx_real_instruction_test__DOT__execute_addx__11__test_description));
    co_await vlSelfRef.__VtrigSched_hd97f067f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_real_instruction_test.clk_i)", 
                                                         "addx_real_instruction_test.sv", 
                                                         120);
    vlSelfRef.addx_real_instruction_test__DOT__rs1 
        = __Vtask_addx_real_instruction_test__DOT__execute_addx__11__operand1;
    vlSelfRef.addx_real_instruction_test__DOT__rs2 
        = __Vtask_addx_real_instruction_test__DOT__execute_addx__11__operand2;
    vlSelfRef.addx_real_instruction_test__DOT__valid = 1U;
    co_await vlSelfRef.__VtrigSched_hd97f067f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_real_instruction_test.clk_i)", 
                                                         "addx_real_instruction_test.sv", 
                                                         125);
    vlSelfRef.addx_real_instruction_test__DOT__valid = 0U;
    co_await vlSelfRef.__VtrigSched_hd97f067f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_real_instruction_test.clk_i)", 
                                                         "addx_real_instruction_test.sv", 
                                                         128);
    addx_real_instruction_test__DOT__test_num = ((IData)(1U) 
                                                 + addx_real_instruction_test__DOT__test_num);
    co_await vlSelfRef.__VtrigSched_hd97f067f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_real_instruction_test.clk_i)", 
                                                         "addx_real_instruction_test.sv", 
                                                         207);
    co_await vlSelfRef.__VtrigSched_hd97f067f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_real_instruction_test.clk_i)", 
                                                         "addx_real_instruction_test.sv", 
                                                         207);
    co_await vlSelfRef.__VtrigSched_hd97f067f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_real_instruction_test.clk_i)", 
                                                         "addx_real_instruction_test.sv", 
                                                         207);
    VL_WRITEF_NX("\n################################################################################\n#                                                                              #\n#                          TEST SUMMARY                                       #\n#                                                                              #\n################################################################################\n\n  Total ADDX Instructions Executed: %0d\n  Total Simulation Cycles: %0#\n",0,
                 32,(addx_real_instruction_test__DOT__test_num 
                     - (IData)(1U)),64,vlSelfRef.addx_real_instruction_test__DOT__cycle_counter);
    VL_WRITEF_NX("  Clock Frequency: 100 MHz (10ns period)\n  Average Cycles per ADDX: ~1 cycle\n\n  ADDX Features Demonstrated:\n    \342\234\223 Normal addition operations\n    \342\234\223 Positive overflow with saturation\n    \342\234\223 Negative overflow with saturation\n    \342\234\223 Mixed sign operations\n    \342\234\223 Single-cycle execution\n\n################################################################################\n#                    ALL ADDX TESTS COMPLETED!                                #\n",0);
    VL_WRITEF_NX("################################################################################\n\n",0);
    co_await vlSelfRef.__VtrigSched_hd97f067f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_real_instruction_test.clk_i)", 
                                                         "addx_real_instruction_test.sv", 
                                                         233);
    co_await vlSelfRef.__VtrigSched_hd97f067f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_real_instruction_test.clk_i)", 
                                                         "addx_real_instruction_test.sv", 
                                                         233);
    co_await vlSelfRef.__VtrigSched_hd97f067f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_real_instruction_test.clk_i)", 
                                                         "addx_real_instruction_test.sv", 
                                                         233);
    co_await vlSelfRef.__VtrigSched_hd97f067f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_real_instruction_test.clk_i)", 
                                                         "addx_real_instruction_test.sv", 
                                                         233);
    co_await vlSelfRef.__VtrigSched_hd97f067f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge addx_real_instruction_test.clk_i)", 
                                                         "addx_real_instruction_test.sv", 
                                                         233);
    VL_FINISH_MT("addx_real_instruction_test.sv", 234, "");
}

VL_INLINE_OPT VlCoroutine Vaddx_real_instruction_test___024root___eval_initial__TOP__Vtiming__2(Vaddx_real_instruction_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaddx_real_instruction_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddx_real_instruction_test___024root___eval_initial__TOP__Vtiming__2\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x5f5e100ULL, 
                                         nullptr, "addx_real_instruction_test.sv", 
                                         239);
    VL_WRITEF_NX("\nERROR: Simulation timeout!\n",0);
    VL_FINISH_MT("addx_real_instruction_test.sv", 242, "");
}

void Vaddx_real_instruction_test___024root___act_sequent__TOP__0(Vaddx_real_instruction_test___024root* vlSelf);

void Vaddx_real_instruction_test___024root___eval_act(Vaddx_real_instruction_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaddx_real_instruction_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddx_real_instruction_test___024root___eval_act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vaddx_real_instruction_test___024root___act_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vaddx_real_instruction_test___024root___act_sequent__TOP__0(Vaddx_real_instruction_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaddx_real_instruction_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddx_real_instruction_test___024root___act_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<3>/*64:0*/ addx_real_instruction_test__DOT__extended_result;
    VL_ZERO_W(65, addx_real_instruction_test__DOT__extended_result);
    CData/*0:0*/ addx_real_instruction_test__DOT__overflow_detected;
    addx_real_instruction_test__DOT__overflow_detected = 0;
    VlWide<3>/*95:0*/ __Vtemp_2;
    VlWide<3>/*95:0*/ __Vtemp_3;
    VlWide<3>/*95:0*/ __Vtemp_4;
    // Body
    __Vtemp_2[0U] = (IData)(vlSelfRef.addx_real_instruction_test__DOT__rs1);
    __Vtemp_2[1U] = (IData)((vlSelfRef.addx_real_instruction_test__DOT__rs1 
                             >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = (IData)(vlSelfRef.addx_real_instruction_test__DOT__rs2);
    __Vtemp_3[1U] = (IData)((vlSelfRef.addx_real_instruction_test__DOT__rs2 
                             >> 0x20U));
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    addx_real_instruction_test__DOT__extended_result[0U] 
        = __Vtemp_4[0U];
    addx_real_instruction_test__DOT__extended_result[1U] 
        = __Vtemp_4[1U];
    addx_real_instruction_test__DOT__extended_result[2U] 
        = (1U & __Vtemp_4[2U]);
    addx_real_instruction_test__DOT__overflow_detected 
        = (1U & addx_real_instruction_test__DOT__extended_result[2U]);
    if (((IData)(addx_real_instruction_test__DOT__overflow_detected) 
         & ((1U & (IData)((vlSelfRef.addx_real_instruction_test__DOT__rs1 
                           >> 0x3fU))) == (1U & (IData)(
                                                        (vlSelfRef.addx_real_instruction_test__DOT__rs2 
                                                         >> 0x3fU)))))) {
        vlSelfRef.addx_real_instruction_test__DOT__saturation_occurred = 1U;
        vlSelfRef.addx_real_instruction_test__DOT__rd 
            = ((1U & (IData)((vlSelfRef.addx_real_instruction_test__DOT__rs1 
                              >> 0x3fU))) ? 0x8000000000000000ULL
                : 0x7fffffffffffffffULL);
    } else {
        vlSelfRef.addx_real_instruction_test__DOT__saturation_occurred = 0U;
        vlSelfRef.addx_real_instruction_test__DOT__rd 
            = (((QData)((IData)(addx_real_instruction_test__DOT__extended_result[1U])) 
                << 0x20U) | (QData)((IData)(addx_real_instruction_test__DOT__extended_result[0U])));
    }
}

void Vaddx_real_instruction_test___024root___nba_sequent__TOP__0(Vaddx_real_instruction_test___024root* vlSelf);
void Vaddx_real_instruction_test___024root___nba_sequent__TOP__1(Vaddx_real_instruction_test___024root* vlSelf);
void Vaddx_real_instruction_test___024root___nba_sequent__TOP__2(Vaddx_real_instruction_test___024root* vlSelf);

void Vaddx_real_instruction_test___024root___eval_nba(Vaddx_real_instruction_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaddx_real_instruction_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddx_real_instruction_test___024root___eval_nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vaddx_real_instruction_test___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vaddx_real_instruction_test___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vaddx_real_instruction_test___024root___nba_sequent__TOP__2(vlSelf);
    }
}

VL_INLINE_OPT void Vaddx_real_instruction_test___024root___nba_sequent__TOP__0(Vaddx_real_instruction_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaddx_real_instruction_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddx_real_instruction_test___024root___nba_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vdly__addx_real_instruction_test__DOT__cycle_counter 
        = vlSelfRef.addx_real_instruction_test__DOT__cycle_counter;
    vlSelfRef.__Vdly__addx_real_instruction_test__DOT__cycle_counter 
        = ((IData)(vlSelfRef.addx_real_instruction_test__DOT__rst_ni)
            ? (1ULL + vlSelfRef.addx_real_instruction_test__DOT__cycle_counter)
            : 0ULL);
}

VL_INLINE_OPT void Vaddx_real_instruction_test___024root___nba_sequent__TOP__1(Vaddx_real_instruction_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaddx_real_instruction_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddx_real_instruction_test___024root___nba_sequent__TOP__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<3>/*64:0*/ addx_real_instruction_test__DOT__extended_result;
    VL_ZERO_W(65, addx_real_instruction_test__DOT__extended_result);
    CData/*0:0*/ addx_real_instruction_test__DOT__overflow_detected;
    addx_real_instruction_test__DOT__overflow_detected = 0;
    VlWide<3>/*95:0*/ __Vtemp_2;
    VlWide<3>/*95:0*/ __Vtemp_3;
    VlWide<3>/*95:0*/ __Vtemp_4;
    // Body
    if (VL_UNLIKELY(((IData)(vlSelfRef.addx_real_instruction_test__DOT__rst_ni) 
                     & (IData)(vlSelfRef.addx_real_instruction_test__DOT__valid)))) {
        VL_WRITEF_NX("\n================================================================================\n  INSTRUCTION: ADDX rd, rs1, rs2  (Custom Saturating Addition)\n  Time: %0t ns | Cycle: %0#\n================================================================================\n\n  INPUT REGISTERS:\n    rs1 (source 1) = 0x%016x  (%0d)\n    rs2 (source 2) = 0x%016x  (%0d)\n\n  OPERATION:\n    rd = saturate(rs1 + rs2)\n\n  OUTPUT REGISTER:\n    rd  (result)   = 0x%016x  (%0d)\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,64,
                     vlSelfRef.addx_real_instruction_test__DOT__cycle_counter,
                     64,vlSelfRef.addx_real_instruction_test__DOT__rs1,
                     64,vlSelfRef.addx_real_instruction_test__DOT__rs1,
                     64,vlSelfRef.addx_real_instruction_test__DOT__rs2,
                     64,vlSelfRef.addx_real_instruction_test__DOT__rs2,
                     64,vlSelfRef.addx_real_instruction_test__DOT__rd,
                     64,vlSelfRef.addx_real_instruction_test__DOT__rd);
        if (vlSelfRef.addx_real_instruction_test__DOT__saturation_occurred) {
            VL_WRITEF_NX("  STATUS: \342\232\240 OVERFLOW - Result SATURATED!\n",0);
            if ((1U & (IData)((vlSelfRef.addx_real_instruction_test__DOT__rs1 
                               >> 0x3fU)))) {
                VL_WRITEF_NX("          Negative overflow \342\206\222 Saturated to MIN (0x8000000000000000)\n",0);
            } else {
                VL_WRITEF_NX("          Positive overflow \342\206\222 Saturated to MAX (0x7FFFFFFFFFFFFFFF)\n",0);
            }
        } else {
            VL_WRITEF_NX("  STATUS: \342\234\223 Normal addition (No overflow)\n",0);
        }
        VL_WRITEF_NX("\n  ACCELERATOR: ADDX Hardware Unit - 1 cycle execution\n================================================================================\n\n",0);
    }
    __Vtemp_2[0U] = (IData)(vlSelfRef.addx_real_instruction_test__DOT__rs1);
    __Vtemp_2[1U] = (IData)((vlSelfRef.addx_real_instruction_test__DOT__rs1 
                             >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = (IData)(vlSelfRef.addx_real_instruction_test__DOT__rs2);
    __Vtemp_3[1U] = (IData)((vlSelfRef.addx_real_instruction_test__DOT__rs2 
                             >> 0x20U));
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    addx_real_instruction_test__DOT__extended_result[0U] 
        = __Vtemp_4[0U];
    addx_real_instruction_test__DOT__extended_result[1U] 
        = __Vtemp_4[1U];
    addx_real_instruction_test__DOT__extended_result[2U] 
        = (1U & __Vtemp_4[2U]);
    addx_real_instruction_test__DOT__overflow_detected 
        = (1U & addx_real_instruction_test__DOT__extended_result[2U]);
    if (((IData)(addx_real_instruction_test__DOT__overflow_detected) 
         & ((1U & (IData)((vlSelfRef.addx_real_instruction_test__DOT__rs1 
                           >> 0x3fU))) == (1U & (IData)(
                                                        (vlSelfRef.addx_real_instruction_test__DOT__rs2 
                                                         >> 0x3fU)))))) {
        vlSelfRef.addx_real_instruction_test__DOT__saturation_occurred = 1U;
        vlSelfRef.addx_real_instruction_test__DOT__rd 
            = ((1U & (IData)((vlSelfRef.addx_real_instruction_test__DOT__rs1 
                              >> 0x3fU))) ? 0x8000000000000000ULL
                : 0x7fffffffffffffffULL);
    } else {
        vlSelfRef.addx_real_instruction_test__DOT__saturation_occurred = 0U;
        vlSelfRef.addx_real_instruction_test__DOT__rd 
            = (((QData)((IData)(addx_real_instruction_test__DOT__extended_result[1U])) 
                << 0x20U) | (QData)((IData)(addx_real_instruction_test__DOT__extended_result[0U])));
    }
}

VL_INLINE_OPT void Vaddx_real_instruction_test___024root___nba_sequent__TOP__2(Vaddx_real_instruction_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaddx_real_instruction_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddx_real_instruction_test___024root___nba_sequent__TOP__2\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.addx_real_instruction_test__DOT__cycle_counter 
        = vlSelfRef.__Vdly__addx_real_instruction_test__DOT__cycle_counter;
}

void Vaddx_real_instruction_test___024root___timing_resume(Vaddx_real_instruction_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaddx_real_instruction_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddx_real_instruction_test___024root___timing_resume\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_hd97f067f__0.resume(
                                                   "@(posedge addx_real_instruction_test.clk_i)");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vaddx_real_instruction_test___024root___timing_commit(Vaddx_real_instruction_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaddx_real_instruction_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddx_real_instruction_test___024root___timing_commit\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((! (2ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_hd97f067f__0.commit(
                                                   "@(posedge addx_real_instruction_test.clk_i)");
    }
}

void Vaddx_real_instruction_test___024root___eval_triggers__act(Vaddx_real_instruction_test___024root* vlSelf);

bool Vaddx_real_instruction_test___024root___eval_phase__act(Vaddx_real_instruction_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaddx_real_instruction_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddx_real_instruction_test___024root___eval_phase__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<3> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vaddx_real_instruction_test___024root___eval_triggers__act(vlSelf);
    Vaddx_real_instruction_test___024root___timing_commit(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vaddx_real_instruction_test___024root___timing_resume(vlSelf);
        Vaddx_real_instruction_test___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vaddx_real_instruction_test___024root___eval_phase__nba(Vaddx_real_instruction_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaddx_real_instruction_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddx_real_instruction_test___024root___eval_phase__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vaddx_real_instruction_test___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vaddx_real_instruction_test___024root___dump_triggers__nba(Vaddx_real_instruction_test___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vaddx_real_instruction_test___024root___dump_triggers__act(Vaddx_real_instruction_test___024root* vlSelf);
#endif  // VL_DEBUG

void Vaddx_real_instruction_test___024root___eval(Vaddx_real_instruction_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaddx_real_instruction_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddx_real_instruction_test___024root___eval\n"); );
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
            Vaddx_real_instruction_test___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("addx_real_instruction_test.sv", 8, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                Vaddx_real_instruction_test___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("addx_real_instruction_test.sv", 8, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vaddx_real_instruction_test___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vaddx_real_instruction_test___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vaddx_real_instruction_test___024root___eval_debug_assertions(Vaddx_real_instruction_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaddx_real_instruction_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddx_real_instruction_test___024root___eval_debug_assertions\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
