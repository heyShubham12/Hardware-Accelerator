// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vaddx_real_instruction_test__pch.h"

//============================================================
// Constructors

Vaddx_real_instruction_test::Vaddx_real_instruction_test(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vaddx_real_instruction_test__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vaddx_real_instruction_test::Vaddx_real_instruction_test(const char* _vcname__)
    : Vaddx_real_instruction_test(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vaddx_real_instruction_test::~Vaddx_real_instruction_test() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vaddx_real_instruction_test___024root___eval_debug_assertions(Vaddx_real_instruction_test___024root* vlSelf);
#endif  // VL_DEBUG
void Vaddx_real_instruction_test___024root___eval_static(Vaddx_real_instruction_test___024root* vlSelf);
void Vaddx_real_instruction_test___024root___eval_initial(Vaddx_real_instruction_test___024root* vlSelf);
void Vaddx_real_instruction_test___024root___eval_settle(Vaddx_real_instruction_test___024root* vlSelf);
void Vaddx_real_instruction_test___024root___eval(Vaddx_real_instruction_test___024root* vlSelf);

void Vaddx_real_instruction_test::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vaddx_real_instruction_test::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vaddx_real_instruction_test___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vaddx_real_instruction_test___024root___eval_static(&(vlSymsp->TOP));
        Vaddx_real_instruction_test___024root___eval_initial(&(vlSymsp->TOP));
        Vaddx_real_instruction_test___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vaddx_real_instruction_test___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vaddx_real_instruction_test::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vaddx_real_instruction_test::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vaddx_real_instruction_test::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vaddx_real_instruction_test___024root___eval_final(Vaddx_real_instruction_test___024root* vlSelf);

VL_ATTR_COLD void Vaddx_real_instruction_test::final() {
    Vaddx_real_instruction_test___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vaddx_real_instruction_test::hierName() const { return vlSymsp->name(); }
const char* Vaddx_real_instruction_test::modelName() const { return "Vaddx_real_instruction_test"; }
unsigned Vaddx_real_instruction_test::threads() const { return 1; }
void Vaddx_real_instruction_test::prepareClone() const { contextp()->prepareClone(); }
void Vaddx_real_instruction_test::atClone() const {
    contextp()->threadPoolpOnClone();
}
