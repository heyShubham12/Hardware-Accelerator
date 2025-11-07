// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vaddx_standalone_test.h for the primary calling header

#ifndef VERILATED_VADDX_STANDALONE_TEST___024ROOT_H_
#define VERILATED_VADDX_STANDALONE_TEST___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vaddx_standalone_test__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vaddx_standalone_test___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ addx_standalone_test__DOT__clk_i;
    CData/*0:0*/ addx_standalone_test__DOT__rst_ni;
    CData/*0:0*/ addx_standalone_test__DOT__valid;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__addx_standalone_test__DOT__clk_i__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__addx_standalone_test__DOT__rst_ni__0;
    CData/*0:0*/ __VactContinue;
    VlWide<3>/*64:0*/ addx_standalone_test__DOT__extended_result;
    IData/*31:0*/ __VactIterCount;
    QData/*63:0*/ addx_standalone_test__DOT__operand_a;
    QData/*63:0*/ addx_standalone_test__DOT__operand_b;
    QData/*63:0*/ addx_standalone_test__DOT__addx_result;
    QData/*63:0*/ addx_standalone_test__DOT__cycle_counter;
    QData/*63:0*/ __Vdly__addx_standalone_test__DOT__cycle_counter;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h431d7217__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<3> __VactTriggered;
    VlTriggerVec<3> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vaddx_standalone_test__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vaddx_standalone_test___024root(Vaddx_standalone_test__Syms* symsp, const char* v__name);
    ~Vaddx_standalone_test___024root();
    VL_UNCOPYABLE(Vaddx_standalone_test___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
