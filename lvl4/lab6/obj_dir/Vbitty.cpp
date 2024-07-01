// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbitty.h for the primary calling header

#include "Vbitty.h"
#include "Vbitty__Syms.h"

//==========

VL_CTOR_IMP(Vbitty) {
    Vbitty__Syms* __restrict vlSymsp = __VlSymsp = new Vbitty__Syms(this, name());
    Vbitty* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vbitty::__Vconfigure(Vbitty__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vbitty::~Vbitty() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void Vbitty::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vbitty::eval\n"); );
    Vbitty__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vbitty* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("bitty.v", 3, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vbitty::_eval_initial_loop(Vbitty__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("bitty.v", 3, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vbitty::_eval(Vbitty__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty::_eval\n"); );
    Vbitty* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
}

void Vbitty::_eval_initial(Vbitty__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty::_eval_initial\n"); );
    Vbitty* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
}

void Vbitty::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty::final\n"); );
    // Variables
    Vbitty__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vbitty* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vbitty::_eval_settle(Vbitty__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty::_eval_settle\n"); );
    Vbitty* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

VL_INLINE_OPT QData Vbitty::_change_request(Vbitty__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty::_change_request\n"); );
    Vbitty* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vbitty::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((run & 0xfeU))) {
        Verilated::overWidthError("run");}
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG

void Vbitty::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty::_ctor_var_reset\n"); );
    // Body
    run = VL_RAND_RESET_I(1);
    clk = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    d_instr = VL_RAND_RESET_I(16);
    d_out = VL_RAND_RESET_I(16);
}
