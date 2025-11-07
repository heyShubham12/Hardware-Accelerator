// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vaes_real_instruction_test.h for the primary calling header

#include "Vaes_real_instruction_test__pch.h"
#include "Vaes_real_instruction_test___024root.h"

VlCoroutine Vaes_real_instruction_test___024root___eval_initial__TOP__Vtiming__0(Vaes_real_instruction_test___024root* vlSelf);
VlCoroutine Vaes_real_instruction_test___024root___eval_initial__TOP__Vtiming__1(Vaes_real_instruction_test___024root* vlSelf);
VlCoroutine Vaes_real_instruction_test___024root___eval_initial__TOP__Vtiming__2(Vaes_real_instruction_test___024root* vlSelf);

void Vaes_real_instruction_test___024root___eval_initial(Vaes_real_instruction_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaes_real_instruction_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaes_real_instruction_test___024root___eval_initial\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vaes_real_instruction_test___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vaes_real_instruction_test___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    Vaes_real_instruction_test___024root___eval_initial__TOP__Vtiming__2(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__aes_real_instruction_test__DOT__clk_i__0 
        = vlSelfRef.aes_real_instruction_test__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__aes_real_instruction_test__DOT__rst_ni__0 
        = vlSelfRef.aes_real_instruction_test__DOT__rst_ni;
}

VL_INLINE_OPT VlCoroutine Vaes_real_instruction_test___024root___eval_initial__TOP__Vtiming__0(Vaes_real_instruction_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaes_real_instruction_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaes_real_instruction_test___024root___eval_initial__TOP__Vtiming__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.aes_real_instruction_test__DOT__clk_i = 0U;
    while (1U) {
        co_await vlSelfRef.__VdlySched.delay(0x1388ULL, 
                                             nullptr, 
                                             "aes_real_instruction_test.sv", 
                                             28);
        vlSelfRef.aes_real_instruction_test__DOT__clk_i 
            = (1U & (~ (IData)(vlSelfRef.aes_real_instruction_test__DOT__clk_i)));
    }
}

VL_INLINE_OPT VlCoroutine Vaes_real_instruction_test___024root___eval_initial__TOP__Vtiming__1(Vaes_real_instruction_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaes_real_instruction_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaes_real_instruction_test___024root___eval_initial__TOP__Vtiming__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ aes_real_instruction_test__DOT__test_num;
    aes_real_instruction_test__DOT__test_num = 0;
    std::string __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__0__test_description;
    std::string __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__0__instruction_name;
    QData/*63:0*/ __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__0__operand1;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__0__operand1 = 0;
    QData/*63:0*/ __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__0__operand2;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__0__operand2 = 0;
    std::string __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__1__test_description;
    std::string __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__1__instruction_name;
    QData/*63:0*/ __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__1__operand1;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__1__operand1 = 0;
    QData/*63:0*/ __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__1__operand2;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__1__operand2 = 0;
    std::string __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__2__test_description;
    std::string __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__2__instruction_name;
    QData/*63:0*/ __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__2__operand1;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__2__operand1 = 0;
    QData/*63:0*/ __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__2__operand2;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__2__operand2 = 0;
    std::string __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__3__test_description;
    std::string __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__3__instruction_name;
    QData/*63:0*/ __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__3__operand1;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__3__operand1 = 0;
    QData/*63:0*/ __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__3__operand2;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__3__operand2 = 0;
    std::string __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__4__test_description;
    std::string __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__4__instruction_name;
    QData/*63:0*/ __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__4__operand1;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__4__operand1 = 0;
    QData/*63:0*/ __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__4__operand2;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__4__operand2 = 0;
    std::string __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__5__test_description;
    std::string __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__5__instruction_name;
    QData/*63:0*/ __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__5__operand1;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__5__operand1 = 0;
    QData/*63:0*/ __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__5__operand2;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__5__operand2 = 0;
    std::string __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__6__test_description;
    std::string __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__6__instruction_name;
    QData/*63:0*/ __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__6__operand1;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__6__operand1 = 0;
    QData/*63:0*/ __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__6__operand2;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__6__operand2 = 0;
    std::string __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__7__test_description;
    std::string __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__7__instruction_name;
    QData/*63:0*/ __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__7__operand1;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__7__operand1 = 0;
    QData/*63:0*/ __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__7__operand2;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__7__operand2 = 0;
    std::string __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__8__test_description;
    std::string __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__8__instruction_name;
    QData/*63:0*/ __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__8__operand1;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__8__operand1 = 0;
    QData/*63:0*/ __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__8__operand2;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__8__operand2 = 0;
    std::string __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__9__test_description;
    std::string __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__9__instruction_name;
    QData/*63:0*/ __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__9__operand1;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__9__operand1 = 0;
    QData/*63:0*/ __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__9__operand2;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__9__operand2 = 0;
    std::string __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__10__test_description;
    std::string __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__10__instruction_name;
    QData/*63:0*/ __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__10__operand1;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__10__operand1 = 0;
    QData/*63:0*/ __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__10__operand2;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__10__operand2 = 0;
    std::string __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__11__test_description;
    std::string __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__11__instruction_name;
    QData/*63:0*/ __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__11__operand1;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__11__operand1 = 0;
    QData/*63:0*/ __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__11__operand2;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__11__operand2 = 0;
    std::string __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__12__test_description;
    std::string __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__12__instruction_name;
    QData/*63:0*/ __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__12__operand1;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__12__operand1 = 0;
    QData/*63:0*/ __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__12__operand2;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__12__operand2 = 0;
    std::string __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__13__test_description;
    std::string __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__13__instruction_name;
    QData/*63:0*/ __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__13__operand1;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__13__operand1 = 0;
    QData/*63:0*/ __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__13__operand2;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__13__operand2 = 0;
    std::string __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__14__test_description;
    std::string __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__14__instruction_name;
    QData/*63:0*/ __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__14__operand1;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__14__operand1 = 0;
    QData/*63:0*/ __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__14__operand2;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__14__operand2 = 0;
    // Body
    VL_WRITEF_NX("\n################################################################################\n#                                                                              #\n#           CVA6 Cryptographic Accelerator Test (Zkn Extension)               #\n#                                                                              #\n#  RISC-V Scalar Cryptography Extension                                       #\n#  - AES Encryption/Decryption (Zkne/Zknd)                                    #\n",0);
    VL_WRITEF_NX("#  - SHA-256/SHA-512 Hash Functions (Zknh)                                    #\n#                                                                              #\n################################################################################\n\n",0);
    vlSelfRef.aes_real_instruction_test__DOT__rst_ni = 0U;
    vlSelfRef.aes_real_instruction_test__DOT__valid = 0U;
    vlSelfRef.aes_real_instruction_test__DOT__rs1 = 0ULL;
    vlSelfRef.aes_real_instruction_test__DOT__rs2 = 0ULL;
    aes_real_instruction_test__DOT__test_num = 1U;
    vlSelfRef.aes_real_instruction_test__DOT__current_instruction = 
        std::string{"NONE"};
    VL_WRITEF_NX(">>> Initializing Cryptographic Accelerator...\n",0);
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         169);
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         169);
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         169);
    vlSelfRef.aes_real_instruction_test__DOT__rst_ni = 1U;
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         171);
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         171);
    VL_WRITEF_NX(">>> Cryptographic Accelerator Ready!\n\n\n\342\225\224\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\227\n\342\225\221                      SHA-256 HASH INSTRUCTIONS                               \342\225\221\n",0);
    VL_WRITEF_NX("\342\225\232\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\235\n\n",0);
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__0__operand2 = 0ULL;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__0__operand1 = 0x6162638000000000ULL;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__0__instruction_name = 
        std::string{"SHA256SIG0"};
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__0__test_description = 
        std::string{"SHA-256 Sigma0: Message Schedule (\"abc\" padding)"};
    VL_WRITEF_NX("\n\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n  TEST %0d: %@\n\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n",0,
                 32,aes_real_instruction_test__DOT__test_num,
                 -1,&(__Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__0__test_description));
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         129);
    vlSelfRef.aes_real_instruction_test__DOT__rs1 = __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__0__operand1;
    vlSelfRef.aes_real_instruction_test__DOT__rs2 = __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__0__operand2;
    vlSelfRef.aes_real_instruction_test__DOT__current_instruction 
        = __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__0__instruction_name;
    vlSelfRef.aes_real_instruction_test__DOT__valid = 1U;
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         135);
    vlSelfRef.aes_real_instruction_test__DOT__valid = 0U;
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         138);
    aes_real_instruction_test__DOT__test_num = ((IData)(1U) 
                                                + aes_real_instruction_test__DOT__test_num);
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__1__operand2 = 0ULL;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__1__operand1 = 0x18ULL;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__1__instruction_name = 
        std::string{"SHA256SIG1"};
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__1__test_description = 
        std::string{"SHA-256 Sigma1: Message Schedule"};
    VL_WRITEF_NX("\n\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n  TEST %0d: %@\n\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n",0,
                 32,aes_real_instruction_test__DOT__test_num,
                 -1,&(__Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__1__test_description));
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         129);
    vlSelfRef.aes_real_instruction_test__DOT__rs1 = __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__1__operand1;
    vlSelfRef.aes_real_instruction_test__DOT__rs2 = __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__1__operand2;
    vlSelfRef.aes_real_instruction_test__DOT__current_instruction 
        = __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__1__instruction_name;
    vlSelfRef.aes_real_instruction_test__DOT__valid = 1U;
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         135);
    vlSelfRef.aes_real_instruction_test__DOT__valid = 0U;
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         138);
    aes_real_instruction_test__DOT__test_num = ((IData)(1U) 
                                                + aes_real_instruction_test__DOT__test_num);
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__2__operand2 = 0ULL;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__2__operand1 = 0x6a09e66700000000ULL;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__2__instruction_name = 
        std::string{"SHA256SUM0"};
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__2__test_description = 
        std::string{"SHA-256 Sum0: Compression Function"};
    VL_WRITEF_NX("\n\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n  TEST %0d: %@\n\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n",0,
                 32,aes_real_instruction_test__DOT__test_num,
                 -1,&(__Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__2__test_description));
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         129);
    vlSelfRef.aes_real_instruction_test__DOT__rs1 = __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__2__operand1;
    vlSelfRef.aes_real_instruction_test__DOT__rs2 = __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__2__operand2;
    vlSelfRef.aes_real_instruction_test__DOT__current_instruction 
        = __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__2__instruction_name;
    vlSelfRef.aes_real_instruction_test__DOT__valid = 1U;
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         135);
    vlSelfRef.aes_real_instruction_test__DOT__valid = 0U;
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         138);
    aes_real_instruction_test__DOT__test_num = ((IData)(1U) 
                                                + aes_real_instruction_test__DOT__test_num);
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__3__operand2 = 0ULL;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__3__operand1 = 0x510e527f00000000ULL;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__3__instruction_name = 
        std::string{"SHA256SUM1"};
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__3__test_description = 
        std::string{"SHA-256 Sum1: Compression Function"};
    VL_WRITEF_NX("\n\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n  TEST %0d: %@\n\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n",0,
                 32,aes_real_instruction_test__DOT__test_num,
                 -1,&(__Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__3__test_description));
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         129);
    vlSelfRef.aes_real_instruction_test__DOT__rs1 = __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__3__operand1;
    vlSelfRef.aes_real_instruction_test__DOT__rs2 = __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__3__operand2;
    vlSelfRef.aes_real_instruction_test__DOT__current_instruction 
        = __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__3__instruction_name;
    vlSelfRef.aes_real_instruction_test__DOT__valid = 1U;
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         135);
    vlSelfRef.aes_real_instruction_test__DOT__valid = 0U;
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         138);
    aes_real_instruction_test__DOT__test_num = ((IData)(1U) 
                                                + aes_real_instruction_test__DOT__test_num);
    VL_WRITEF_NX("\n\342\225\224\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\227\n\342\225\221                      AES ENCRYPTION INSTRUCTIONS                             \342\225\221\n",0);
    VL_WRITEF_NX("\342\225\232\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\235\n\n",0);
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__4__operand2 = 0xfedcba9876543210ULL;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__4__operand1 = 0x123456789abcdefULL;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__4__instruction_name = 
        std::string{"AES64ES"};
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__4__test_description = 
        std::string{"AES-64 Final Round Encryption (SubBytes + ShiftRows)"};
    VL_WRITEF_NX("\n\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n  TEST %0d: %@\n\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n",0,
                 32,aes_real_instruction_test__DOT__test_num,
                 -1,&(__Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__4__test_description));
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         129);
    vlSelfRef.aes_real_instruction_test__DOT__rs1 = __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__4__operand1;
    vlSelfRef.aes_real_instruction_test__DOT__rs2 = __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__4__operand2;
    vlSelfRef.aes_real_instruction_test__DOT__current_instruction 
        = __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__4__instruction_name;
    vlSelfRef.aes_real_instruction_test__DOT__valid = 1U;
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         135);
    vlSelfRef.aes_real_instruction_test__DOT__valid = 0U;
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         138);
    aes_real_instruction_test__DOT__test_num = ((IData)(1U) 
                                                + aes_real_instruction_test__DOT__test_num);
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__5__operand2 = 0x8877665544332211ULL;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__5__operand1 = 0x1122334455667788ULL;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__5__instruction_name = 
        std::string{"AES64ESM"};
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__5__test_description = 
        std::string{"AES-64 Middle Round Encryption (+ MixColumns)"};
    VL_WRITEF_NX("\n\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n  TEST %0d: %@\n\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n",0,
                 32,aes_real_instruction_test__DOT__test_num,
                 -1,&(__Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__5__test_description));
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         129);
    vlSelfRef.aes_real_instruction_test__DOT__rs1 = __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__5__operand1;
    vlSelfRef.aes_real_instruction_test__DOT__rs2 = __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__5__operand2;
    vlSelfRef.aes_real_instruction_test__DOT__current_instruction 
        = __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__5__instruction_name;
    vlSelfRef.aes_real_instruction_test__DOT__valid = 1U;
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         135);
    vlSelfRef.aes_real_instruction_test__DOT__valid = 0U;
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         138);
    aes_real_instruction_test__DOT__test_num = ((IData)(1U) 
                                                + aes_real_instruction_test__DOT__test_num);
    VL_WRITEF_NX("\n\342\225\224\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\227\n\342\225\221                      AES DECRYPTION INSTRUCTIONS                             \342\225\221\n",0);
    VL_WRITEF_NX("\342\225\232\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\235\n\n",0);
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__6__operand2 = 0x1100ffeeddccbbaaULL;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__6__operand1 = 0xaabbccddeeff0011ULL;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__6__instruction_name = 
        std::string{"AES64DS"};
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__6__test_description = 
        std::string{"AES-64 Final Round Decryption (InvSubBytes + InvShiftRows)"};
    VL_WRITEF_NX("\n\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n  TEST %0d: %@\n\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n",0,
                 32,aes_real_instruction_test__DOT__test_num,
                 -1,&(__Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__6__test_description));
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         129);
    vlSelfRef.aes_real_instruction_test__DOT__rs1 = __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__6__operand1;
    vlSelfRef.aes_real_instruction_test__DOT__rs2 = __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__6__operand2;
    vlSelfRef.aes_real_instruction_test__DOT__current_instruction 
        = __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__6__instruction_name;
    vlSelfRef.aes_real_instruction_test__DOT__valid = 1U;
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         135);
    vlSelfRef.aes_real_instruction_test__DOT__valid = 0U;
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         138);
    aes_real_instruction_test__DOT__test_num = ((IData)(1U) 
                                                + aes_real_instruction_test__DOT__test_num);
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__7__operand2 = 0xeeccaa0088664422ULL;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__7__operand1 = 0x2244668800aacceeULL;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__7__instruction_name = 
        std::string{"AES64DSM"};
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__7__test_description = 
        std::string{"AES-64 Middle Round Decryption (+ InvMixColumns)"};
    VL_WRITEF_NX("\n\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n  TEST %0d: %@\n\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n",0,
                 32,aes_real_instruction_test__DOT__test_num,
                 -1,&(__Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__7__test_description));
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         129);
    vlSelfRef.aes_real_instruction_test__DOT__rs1 = __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__7__operand1;
    vlSelfRef.aes_real_instruction_test__DOT__rs2 = __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__7__operand2;
    vlSelfRef.aes_real_instruction_test__DOT__current_instruction 
        = __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__7__instruction_name;
    vlSelfRef.aes_real_instruction_test__DOT__valid = 1U;
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         135);
    vlSelfRef.aes_real_instruction_test__DOT__valid = 0U;
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         138);
    aes_real_instruction_test__DOT__test_num = ((IData)(1U) 
                                                + aes_real_instruction_test__DOT__test_num);
    VL_WRITEF_NX("\n\342\225\224\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\227\n\342\225\221                    REAL-WORLD EXAMPLE: HASHING                               \342\225\221\n",0);
    VL_WRITEF_NX("\342\225\232\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\235\n\n",0);
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__8__operand2 = 0ULL;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__8__operand1 = 0x48656c6c6f800000ULL;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__8__instruction_name = 
        std::string{"SHA256SIG0"};
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__8__test_description = 
        std::string{"Hash Message: \"Hello\" (Step 1 - Sigma0)"};
    VL_WRITEF_NX("\n\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n  TEST %0d: %@\n\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n",0,
                 32,aes_real_instruction_test__DOT__test_num,
                 -1,&(__Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__8__test_description));
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         129);
    vlSelfRef.aes_real_instruction_test__DOT__rs1 = __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__8__operand1;
    vlSelfRef.aes_real_instruction_test__DOT__rs2 = __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__8__operand2;
    vlSelfRef.aes_real_instruction_test__DOT__current_instruction 
        = __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__8__instruction_name;
    vlSelfRef.aes_real_instruction_test__DOT__valid = 1U;
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         135);
    vlSelfRef.aes_real_instruction_test__DOT__valid = 0U;
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         138);
    aes_real_instruction_test__DOT__test_num = ((IData)(1U) 
                                                + aes_real_instruction_test__DOT__test_num);
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__9__operand2 = 0ULL;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__9__operand1 = 0x6a09e667f3bcc908ULL;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__9__instruction_name = 
        std::string{"SHA256SUM0"};
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__9__test_description = 
        std::string{"Hash Message: \"Hello\" (Step 2 - Sum0)"};
    VL_WRITEF_NX("\n\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n  TEST %0d: %@\n\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n",0,
                 32,aes_real_instruction_test__DOT__test_num,
                 -1,&(__Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__9__test_description));
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         129);
    vlSelfRef.aes_real_instruction_test__DOT__rs1 = __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__9__operand1;
    vlSelfRef.aes_real_instruction_test__DOT__rs2 = __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__9__operand2;
    vlSelfRef.aes_real_instruction_test__DOT__current_instruction 
        = __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__9__instruction_name;
    vlSelfRef.aes_real_instruction_test__DOT__valid = 1U;
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         135);
    vlSelfRef.aes_real_instruction_test__DOT__valid = 0U;
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         138);
    aes_real_instruction_test__DOT__test_num = ((IData)(1U) 
                                                + aes_real_instruction_test__DOT__test_num);
    VL_WRITEF_NX("\n\342\225\224\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\227\n\342\225\221                      PERFORMANCE TEST                                        \342\225\221\n",0);
    VL_WRITEF_NX("\342\225\232\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\235\n\n",0);
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__10__operand2 = 0ULL;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__10__operand1 = 0x123456789abcdef0ULL;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__10__instruction_name = 
        std::string{"SHA256SIG0"};
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__10__test_description = 
        std::string{"Performance: SHA256SIG0 #1"};
    VL_WRITEF_NX("\n\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n  TEST %0d: %@\n\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n",0,
                 32,aes_real_instruction_test__DOT__test_num,
                 -1,&(__Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__10__test_description));
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         129);
    vlSelfRef.aes_real_instruction_test__DOT__rs1 = __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__10__operand1;
    vlSelfRef.aes_real_instruction_test__DOT__rs2 = __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__10__operand2;
    vlSelfRef.aes_real_instruction_test__DOT__current_instruction 
        = __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__10__instruction_name;
    vlSelfRef.aes_real_instruction_test__DOT__valid = 1U;
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         135);
    vlSelfRef.aes_real_instruction_test__DOT__valid = 0U;
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         138);
    aes_real_instruction_test__DOT__test_num = ((IData)(1U) 
                                                + aes_real_instruction_test__DOT__test_num);
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__11__operand2 = 0ULL;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__11__operand1 = 0xfedcba9876543210ULL;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__11__instruction_name = 
        std::string{"SHA256SIG0"};
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__11__test_description = 
        std::string{"Performance: SHA256SIG0 #2"};
    VL_WRITEF_NX("\n\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n  TEST %0d: %@\n\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n",0,
                 32,aes_real_instruction_test__DOT__test_num,
                 -1,&(__Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__11__test_description));
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         129);
    vlSelfRef.aes_real_instruction_test__DOT__rs1 = __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__11__operand1;
    vlSelfRef.aes_real_instruction_test__DOT__rs2 = __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__11__operand2;
    vlSelfRef.aes_real_instruction_test__DOT__current_instruction 
        = __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__11__instruction_name;
    vlSelfRef.aes_real_instruction_test__DOT__valid = 1U;
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         135);
    vlSelfRef.aes_real_instruction_test__DOT__valid = 0U;
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         138);
    aes_real_instruction_test__DOT__test_num = ((IData)(1U) 
                                                + aes_real_instruction_test__DOT__test_num);
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__12__operand2 = 0ULL;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__12__operand1 = 0x1111111122222222ULL;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__12__instruction_name = 
        std::string{"SHA256SUM0"};
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__12__test_description = 
        std::string{"Performance: SHA256SUM0 #1"};
    VL_WRITEF_NX("\n\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n  TEST %0d: %@\n\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n",0,
                 32,aes_real_instruction_test__DOT__test_num,
                 -1,&(__Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__12__test_description));
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         129);
    vlSelfRef.aes_real_instruction_test__DOT__rs1 = __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__12__operand1;
    vlSelfRef.aes_real_instruction_test__DOT__rs2 = __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__12__operand2;
    vlSelfRef.aes_real_instruction_test__DOT__current_instruction 
        = __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__12__instruction_name;
    vlSelfRef.aes_real_instruction_test__DOT__valid = 1U;
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         135);
    vlSelfRef.aes_real_instruction_test__DOT__valid = 0U;
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         138);
    aes_real_instruction_test__DOT__test_num = ((IData)(1U) 
                                                + aes_real_instruction_test__DOT__test_num);
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__13__operand2 = 0ULL;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__13__operand1 = 0x3333333344444444ULL;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__13__instruction_name = 
        std::string{"SHA256SUM1"};
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__13__test_description = 
        std::string{"Performance: SHA256SUM1 #1"};
    VL_WRITEF_NX("\n\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n  TEST %0d: %@\n\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n",0,
                 32,aes_real_instruction_test__DOT__test_num,
                 -1,&(__Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__13__test_description));
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         129);
    vlSelfRef.aes_real_instruction_test__DOT__rs1 = __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__13__operand1;
    vlSelfRef.aes_real_instruction_test__DOT__rs2 = __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__13__operand2;
    vlSelfRef.aes_real_instruction_test__DOT__current_instruction 
        = __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__13__instruction_name;
    vlSelfRef.aes_real_instruction_test__DOT__valid = 1U;
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         135);
    vlSelfRef.aes_real_instruction_test__DOT__valid = 0U;
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         138);
    aes_real_instruction_test__DOT__test_num = ((IData)(1U) 
                                                + aes_real_instruction_test__DOT__test_num);
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__14__operand2 = 0xccccccccddddddddULL;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__14__operand1 = 0xaaaaaaaabbbbbbbbULL;
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__14__instruction_name = 
        std::string{"AES64ES"};
    __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__14__test_description = 
        std::string{"Performance: AES64ES #1"};
    VL_WRITEF_NX("\n\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n  TEST %0d: %@\n\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n",0,
                 32,aes_real_instruction_test__DOT__test_num,
                 -1,&(__Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__14__test_description));
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         129);
    vlSelfRef.aes_real_instruction_test__DOT__rs1 = __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__14__operand1;
    vlSelfRef.aes_real_instruction_test__DOT__rs2 = __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__14__operand2;
    vlSelfRef.aes_real_instruction_test__DOT__current_instruction 
        = __Vtask_aes_real_instruction_test__DOT__execute_crypto_instr__14__instruction_name;
    vlSelfRef.aes_real_instruction_test__DOT__valid = 1U;
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         135);
    vlSelfRef.aes_real_instruction_test__DOT__valid = 0U;
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         138);
    aes_real_instruction_test__DOT__test_num = ((IData)(1U) 
                                                + aes_real_instruction_test__DOT__test_num);
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         310);
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         310);
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         310);
    VL_WRITEF_NX("\n################################################################################\n#                                                                              #\n#                          TEST SUMMARY                                       #\n#                                                                              #\n################################################################################\n\n  Total Cryptographic Instructions Executed: %0d\n  Total Simulation Cycles: %0#\n",0,
                 32,(aes_real_instruction_test__DOT__test_num 
                     - (IData)(1U)),64,vlSelfRef.aes_real_instruction_test__DOT__cycle_counter);
    VL_WRITEF_NX("  Clock Frequency: 100 MHz (10ns period)\n  Average Cycles per Operation: ~1 cycle\n\n  Instructions Tested:\n    \342\234\223 SHA256SIG0  - SHA-256 message schedule sigma0\n    \342\234\223 SHA256SIG1  - SHA-256 message schedule sigma1\n    \342\234\223 SHA256SUM0  - SHA-256 compression sum0\n    \342\234\223 SHA256SUM1  - SHA-256 compression sum1\n    \342\234\223 AES64ES     - AES encryption final round\n    \342\234\223 AES64ESM    - AES encryption middle round\n    \342\234\223 AES64DS     - AES decryption final round\n",0);
    VL_WRITEF_NX("    \342\234\223 AES64DSM    - AES decryption middle round\n\n  Applications:\n    \342\200\242 Secure hashing (SHA-256, SHA-512)\n    \342\200\242 Block cipher encryption/decryption (AES-128, AES-256)\n    \342\200\242 Message authentication\n    \342\200\242 Digital signatures\n    \342\200\242 Secure key derivation\n\n################################################################################\n#              ALL CRYPTOGRAPHIC TESTS COMPLETED!                             #\n",0);
    VL_WRITEF_NX("################################################################################\n\n",0);
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         346);
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         346);
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         346);
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         346);
    co_await vlSelfRef.__VtrigSched_h524b4869__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge aes_real_instruction_test.clk_i)", 
                                                         "aes_real_instruction_test.sv", 
                                                         346);
    VL_FINISH_MT("aes_real_instruction_test.sv", 347, "");
}

VL_INLINE_OPT VlCoroutine Vaes_real_instruction_test___024root___eval_initial__TOP__Vtiming__2(Vaes_real_instruction_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaes_real_instruction_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaes_real_instruction_test___024root___eval_initial__TOP__Vtiming__2\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x1dcd6500ULL, 
                                         nullptr, "aes_real_instruction_test.sv", 
                                         352);
    VL_WRITEF_NX("\nERROR: Simulation timeout!\n",0);
    VL_FINISH_MT("aes_real_instruction_test.sv", 355, "");
}

void Vaes_real_instruction_test___024root___act_sequent__TOP__0(Vaes_real_instruction_test___024root* vlSelf);

void Vaes_real_instruction_test___024root___eval_act(Vaes_real_instruction_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaes_real_instruction_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaes_real_instruction_test___024root___eval_act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vaes_real_instruction_test___024root___act_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vaes_real_instruction_test___024root___act_sequent__TOP__0(Vaes_real_instruction_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaes_real_instruction_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaes_real_instruction_test___024root___act_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ aes_real_instruction_test__DOT__sha256_sig0_result;
    aes_real_instruction_test__DOT__sha256_sig0_result = 0;
    // Body
    aes_real_instruction_test__DOT__sha256_sig0_result 
        = (((((IData)(vlSelfRef.aes_real_instruction_test__DOT__rs1) 
              << 7U) | (0x7fU & (IData)((vlSelfRef.aes_real_instruction_test__DOT__rs1 
                                         >> 0x19U)))) 
            ^ (((IData)(vlSelfRef.aes_real_instruction_test__DOT__rs1) 
                << 0x12U) | (0x3ffffU & (IData)((vlSelfRef.aes_real_instruction_test__DOT__rs1 
                                                 >> 0xeU))))) 
           ^ VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.aes_real_instruction_test__DOT__rs1), 3U));
    vlSelfRef.aes_real_instruction_test__DOT__rd = (QData)((IData)(aes_real_instruction_test__DOT__sha256_sig0_result));
}

void Vaes_real_instruction_test___024root___nba_sequent__TOP__0(Vaes_real_instruction_test___024root* vlSelf);
void Vaes_real_instruction_test___024root___nba_sequent__TOP__1(Vaes_real_instruction_test___024root* vlSelf);
void Vaes_real_instruction_test___024root___nba_sequent__TOP__2(Vaes_real_instruction_test___024root* vlSelf);

void Vaes_real_instruction_test___024root___eval_nba(Vaes_real_instruction_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaes_real_instruction_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaes_real_instruction_test___024root___eval_nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vaes_real_instruction_test___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vaes_real_instruction_test___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vaes_real_instruction_test___024root___nba_sequent__TOP__2(vlSelf);
    }
}

VL_INLINE_OPT void Vaes_real_instruction_test___024root___nba_sequent__TOP__0(Vaes_real_instruction_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaes_real_instruction_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaes_real_instruction_test___024root___nba_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vdly__aes_real_instruction_test__DOT__cycle_counter 
        = vlSelfRef.aes_real_instruction_test__DOT__cycle_counter;
    vlSelfRef.__Vdly__aes_real_instruction_test__DOT__cycle_counter 
        = ((IData)(vlSelfRef.aes_real_instruction_test__DOT__rst_ni)
            ? (1ULL + vlSelfRef.aes_real_instruction_test__DOT__cycle_counter)
            : 0ULL);
}

VL_INLINE_OPT void Vaes_real_instruction_test___024root___nba_sequent__TOP__1(Vaes_real_instruction_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaes_real_instruction_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaes_real_instruction_test___024root___nba_sequent__TOP__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ aes_real_instruction_test__DOT__sha256_sig0_result;
    aes_real_instruction_test__DOT__sha256_sig0_result = 0;
    // Body
    if (VL_UNLIKELY(((IData)(vlSelfRef.aes_real_instruction_test__DOT__rst_ni) 
                     & (IData)(vlSelfRef.aes_real_instruction_test__DOT__valid)))) {
        VL_WRITEF_NX("\n================================================================================\n  INSTRUCTION: %@\n  Time: %0t ns | Cycle: %0#\n================================================================================\n\n  INPUT REGISTERS:\n    rs1 (input data)  = 0x%016x\n",0,
                     -1,&(vlSelfRef.aes_real_instruction_test__DOT__current_instruction),
                     64,VL_TIME_UNITED_Q(1000),-9,64,
                     vlSelfRef.aes_real_instruction_test__DOT__cycle_counter,
                     64,vlSelfRef.aes_real_instruction_test__DOT__rs1);
        if (VL_UNLIKELY((0ULL != vlSelfRef.aes_real_instruction_test__DOT__rs2))) {
            VL_WRITEF_NX("    rs2 (key/data)    = 0x%016x\n",0,
                         64,vlSelfRef.aes_real_instruction_test__DOT__rs2);
        }
        VL_WRITEF_NX("\n  CRYPTOGRAPHIC OPERATION:\n",0);
        if (VL_UNLIKELY((std::string{"SHA256SIG0"} 
                         == vlSelfRef.aes_real_instruction_test__DOT__current_instruction))) {
            VL_WRITEF_NX("    Performs: ROTR^7(rs1) \342\212\225 ROTR^18(rs1) \342\212\225 SHR^3(rs1)\n    Used in: SHA-256 message schedule\n",0);
        } else if (VL_UNLIKELY((std::string{"SHA256SIG1"} 
                                == vlSelfRef.aes_real_instruction_test__DOT__current_instruction))) {
            VL_WRITEF_NX("    Performs: ROTR^17(rs1) \342\212\225 ROTR^19(rs1) \342\212\225 SHR^10(rs1)\n    Used in: SHA-256 message schedule\n",0);
        } else if (VL_UNLIKELY((std::string{"SHA256SUM0"} 
                                == vlSelfRef.aes_real_instruction_test__DOT__current_instruction))) {
            VL_WRITEF_NX("    Performs: ROTR^2(rs1) \342\212\225 ROTR^13(rs1) \342\212\225 ROTR^22(rs1)\n    Used in: SHA-256 compression function\n",0);
        } else if (VL_UNLIKELY((std::string{"SHA256SUM1"} 
                                == vlSelfRef.aes_real_instruction_test__DOT__current_instruction))) {
            VL_WRITEF_NX("    Performs: ROTR^6(rs1) \342\212\225 ROTR^11(rs1) \342\212\225 ROTR^25(rs1)\n    Used in: SHA-256 compression function\n",0);
        } else if (VL_UNLIKELY((std::string{"AES64ES"} 
                                == vlSelfRef.aes_real_instruction_test__DOT__current_instruction))) {
            VL_WRITEF_NX("    Performs: AES Forward ShiftRows + SubBytes (Final Round)\n    Used in: AES encryption\n",0);
        } else if (VL_UNLIKELY((std::string{"AES64ESM"} 
                                == vlSelfRef.aes_real_instruction_test__DOT__current_instruction))) {
            VL_WRITEF_NX("    Performs: AES Forward ShiftRows + SubBytes + MixColumns\n    Used in: AES encryption middle rounds\n",0);
        } else if (VL_UNLIKELY((std::string{"AES64DS"} 
                                == vlSelfRef.aes_real_instruction_test__DOT__current_instruction))) {
            VL_WRITEF_NX("    Performs: AES Inverse ShiftRows + SubBytes (Final Round)\n    Used in: AES decryption\n",0);
        } else if (VL_UNLIKELY((std::string{"AES64DSM"} 
                                == vlSelfRef.aes_real_instruction_test__DOT__current_instruction))) {
            VL_WRITEF_NX("    Performs: AES Inverse ShiftRows + SubBytes + MixColumns\n    Used in: AES decryption middle rounds\n",0);
        }
        VL_WRITEF_NX("\n  OUTPUT REGISTER:\n    rd  (result)      = 0x%016x\n\n",0,
                     64,vlSelfRef.aes_real_instruction_test__DOT__rd);
        if (((((std::string{"SHA256SIG0"} == vlSelfRef.aes_real_instruction_test__DOT__current_instruction) 
               | (std::string{"SHA256SIG1"} == vlSelfRef.aes_real_instruction_test__DOT__current_instruction)) 
              | (std::string{"SHA256SUM0"} == vlSelfRef.aes_real_instruction_test__DOT__current_instruction)) 
             | (std::string{"SHA256SUM1"} == vlSelfRef.aes_real_instruction_test__DOT__current_instruction))) {
            VL_WRITEF_NX("  ACCELERATOR: SHA Hardware Unit - Single cycle execution\n",0);
        } else {
            VL_WRITEF_NX("  ACCELERATOR: AES Hardware Unit - Single cycle execution\n",0);
        }
        VL_WRITEF_NX("================================================================================\n\n",0);
    }
    aes_real_instruction_test__DOT__sha256_sig0_result 
        = (((((IData)(vlSelfRef.aes_real_instruction_test__DOT__rs1) 
              << 7U) | (0x7fU & (IData)((vlSelfRef.aes_real_instruction_test__DOT__rs1 
                                         >> 0x19U)))) 
            ^ (((IData)(vlSelfRef.aes_real_instruction_test__DOT__rs1) 
                << 0x12U) | (0x3ffffU & (IData)((vlSelfRef.aes_real_instruction_test__DOT__rs1 
                                                 >> 0xeU))))) 
           ^ VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.aes_real_instruction_test__DOT__rs1), 3U));
    vlSelfRef.aes_real_instruction_test__DOT__rd = (QData)((IData)(aes_real_instruction_test__DOT__sha256_sig0_result));
}

VL_INLINE_OPT void Vaes_real_instruction_test___024root___nba_sequent__TOP__2(Vaes_real_instruction_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaes_real_instruction_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaes_real_instruction_test___024root___nba_sequent__TOP__2\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.aes_real_instruction_test__DOT__cycle_counter 
        = vlSelfRef.__Vdly__aes_real_instruction_test__DOT__cycle_counter;
}

void Vaes_real_instruction_test___024root___timing_resume(Vaes_real_instruction_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaes_real_instruction_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaes_real_instruction_test___024root___timing_resume\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_h524b4869__0.resume(
                                                   "@(posedge aes_real_instruction_test.clk_i)");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vaes_real_instruction_test___024root___timing_commit(Vaes_real_instruction_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaes_real_instruction_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaes_real_instruction_test___024root___timing_commit\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((! (2ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_h524b4869__0.commit(
                                                   "@(posedge aes_real_instruction_test.clk_i)");
    }
}

void Vaes_real_instruction_test___024root___eval_triggers__act(Vaes_real_instruction_test___024root* vlSelf);

bool Vaes_real_instruction_test___024root___eval_phase__act(Vaes_real_instruction_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaes_real_instruction_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaes_real_instruction_test___024root___eval_phase__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<3> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vaes_real_instruction_test___024root___eval_triggers__act(vlSelf);
    Vaes_real_instruction_test___024root___timing_commit(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vaes_real_instruction_test___024root___timing_resume(vlSelf);
        Vaes_real_instruction_test___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vaes_real_instruction_test___024root___eval_phase__nba(Vaes_real_instruction_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaes_real_instruction_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaes_real_instruction_test___024root___eval_phase__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vaes_real_instruction_test___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vaes_real_instruction_test___024root___dump_triggers__nba(Vaes_real_instruction_test___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vaes_real_instruction_test___024root___dump_triggers__act(Vaes_real_instruction_test___024root* vlSelf);
#endif  // VL_DEBUG

void Vaes_real_instruction_test___024root___eval(Vaes_real_instruction_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaes_real_instruction_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaes_real_instruction_test___024root___eval\n"); );
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
            Vaes_real_instruction_test___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("aes_real_instruction_test.sv", 8, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                Vaes_real_instruction_test___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("aes_real_instruction_test.sv", 8, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vaes_real_instruction_test___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vaes_real_instruction_test___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vaes_real_instruction_test___024root___eval_debug_assertions(Vaes_real_instruction_test___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaes_real_instruction_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaes_real_instruction_test___024root___eval_debug_assertions\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
