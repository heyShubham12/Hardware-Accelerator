// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vaddx_real_instruction_test.h for the primary calling header

#ifndef VERILATED_VADDX_REAL_INSTRUCTION_TEST___024ROOT_H_
#define VERILATED_VADDX_REAL_INSTRUCTION_TEST___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vaddx_real_instruction_test__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vaddx_real_instruction_test___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ addx_real_instruction_test__DOT__clk_i;
    CData/*0:0*/ addx_real_instruction_test__DOT__rst_ni;
    CData/*0:0*/ addx_real_instruction_test__DOT__valid;
    CData/*0:0*/ addx_real_instruction_test__DOT__saturation_occurred;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__addx_real_instruction_test__DOT__clk_i__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__addx_real_instruction_test__DOT__rst_ni__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VactIterCount;
    QData/*63:0*/ addx_real_instruction_test__DOT__rs1;
    QData/*63:0*/ addx_real_instruction_test__DOT__rs2;
    QData/*63:0*/ addx_real_instruction_test__DOT__rd;
    QData/*63:0*/ addx_real_instruction_test__DOT__cycle_counter;
    QData/*63:0*/ __Vdly__addx_real_instruction_test__DOT__cycle_counter;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_hd97f067f__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<3> __VactTriggered;
    VlTriggerVec<3> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vaddx_real_instruction_test__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vaddx_real_instruction_test___024root(Vaddx_real_instruction_test__Syms* symsp, const char* v__name);
    ~Vaddx_real_instruction_test___024root();
    VL_UNCOPYABLE(Vaddx_real_instruction_test___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
