// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vaes_real_instruction_test.h for the primary calling header

#ifndef VERILATED_VAES_REAL_INSTRUCTION_TEST___024ROOT_H_
#define VERILATED_VAES_REAL_INSTRUCTION_TEST___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vaes_real_instruction_test__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vaes_real_instruction_test___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ aes_real_instruction_test__DOT__clk_i;
    CData/*0:0*/ aes_real_instruction_test__DOT__rst_ni;
    CData/*0:0*/ aes_real_instruction_test__DOT__valid;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__aes_real_instruction_test__DOT__clk_i__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__aes_real_instruction_test__DOT__rst_ni__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VactIterCount;
    QData/*63:0*/ aes_real_instruction_test__DOT__rs1;
    QData/*63:0*/ aes_real_instruction_test__DOT__rs2;
    QData/*63:0*/ aes_real_instruction_test__DOT__rd;
    QData/*63:0*/ aes_real_instruction_test__DOT__cycle_counter;
    QData/*63:0*/ __Vdly__aes_real_instruction_test__DOT__cycle_counter;
    std::string aes_real_instruction_test__DOT__current_instruction;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h524b4869__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<3> __VactTriggered;
    VlTriggerVec<3> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vaes_real_instruction_test__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vaes_real_instruction_test___024root(Vaes_real_instruction_test__Syms* symsp, const char* v__name);
    ~Vaes_real_instruction_test___024root();
    VL_UNCOPYABLE(Vaes_real_instruction_test___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
