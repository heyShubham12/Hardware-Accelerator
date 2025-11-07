// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vaes_real_instruction_test__pch.h"

//============================================================
// Constructors

Vaes_real_instruction_test::Vaes_real_instruction_test(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vaes_real_instruction_test__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vaes_real_instruction_test::Vaes_real_instruction_test(const char* _vcname__)
    : Vaes_real_instruction_test(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vaes_real_instruction_test::~Vaes_real_instruction_test() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vaes_real_instruction_test___024root___eval_debug_assertions(Vaes_real_instruction_test___024root* vlSelf);
#endif  // VL_DEBUG
void Vaes_real_instruction_test___024root___eval_static(Vaes_real_instruction_test___024root* vlSelf);
void Vaes_real_instruction_test___024root___eval_initial(Vaes_real_instruction_test___024root* vlSelf);
void Vaes_real_instruction_test___024root___eval_settle(Vaes_real_instruction_test___024root* vlSelf);
void Vaes_real_instruction_test___024root___eval(Vaes_real_instruction_test___024root* vlSelf);

void Vaes_real_instruction_test::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vaes_real_instruction_test::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vaes_real_instruction_test___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vaes_real_instruction_test___024root___eval_static(&(vlSymsp->TOP));
        Vaes_real_instruction_test___024root___eval_initial(&(vlSymsp->TOP));
        Vaes_real_instruction_test___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vaes_real_instruction_test___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vaes_real_instruction_test::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vaes_real_instruction_test::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vaes_real_instruction_test::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vaes_real_instruction_test___024root___eval_final(Vaes_real_instruction_test___024root* vlSelf);

VL_ATTR_COLD void Vaes_real_instruction_test::final() {
    Vaes_real_instruction_test___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vaes_real_instruction_test::hierName() const { return vlSymsp->name(); }
const char* Vaes_real_instruction_test::modelName() const { return "Vaes_real_instruction_test"; }
unsigned Vaes_real_instruction_test::threads() const { return 1; }
void Vaes_real_instruction_test::prepareClone() const { contextp()->prepareClone(); }
void Vaes_real_instruction_test::atClone() const {
    contextp()->threadPoolpOnClone();
}
