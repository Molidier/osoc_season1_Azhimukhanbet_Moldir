// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vprelab.h for the primary calling header

#include "Vprelab.h"
#include "Vprelab__Syms.h"

//==========

VL_CTOR_IMP(Vprelab) {
    Vprelab__Syms* __restrict vlSymsp = __VlSymsp = new Vprelab__Syms(this, name());
    Vprelab* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vprelab::__Vconfigure(Vprelab__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vprelab::~Vprelab() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void Vprelab::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vprelab::eval\n"); );
    Vprelab__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vprelab* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("prelab.sv", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vprelab::_eval_initial_loop(Vprelab__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
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
            VL_FATAL_MT("prelab.sv", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vprelab::_sequent__TOP__1(Vprelab__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprelab::_sequent__TOP__1\n"); );
    Vprelab* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->prelab__DOT__counter = ((IData)(vlTOPp->reset)
                                     ? 0U : ((IData)(1U) 
                                             + vlTOPp->prelab__DOT__counter));
    vlTOPp->prelab__DOT__current_state = ((IData)(vlTOPp->reset)
                                           ? 0U : (IData)(vlTOPp->prelab__DOT__next_state));
    vlTOPp->light = ((0U == (IData)(vlTOPp->prelab__DOT__current_state))
                      ? 1U : ((1U == (IData)(vlTOPp->prelab__DOT__current_state))
                               ? 2U : ((2U == (IData)(vlTOPp->prelab__DOT__current_state))
                                        ? 4U : 1U)));
}

void Vprelab::_settle__TOP__2(Vprelab__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprelab::_settle__TOP__2\n"); );
    Vprelab* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->light = ((0U == (IData)(vlTOPp->prelab__DOT__current_state))
                      ? 1U : ((1U == (IData)(vlTOPp->prelab__DOT__current_state))
                               ? 2U : ((2U == (IData)(vlTOPp->prelab__DOT__current_state))
                                        ? 4U : 1U)));
    if ((0U == (IData)(vlTOPp->prelab__DOT__current_state))) {
        if ((0x9c4U == vlTOPp->prelab__DOT__counter)) {
            vlTOPp->prelab__DOT__next_state = 1U;
            vlTOPp->prelab__DOT__counter = 0U;
        } else {
            vlTOPp->prelab__DOT__next_state = 0U;
        }
    } else {
        if ((1U == (IData)(vlTOPp->prelab__DOT__current_state))) {
            if ((0x9c4U == vlTOPp->prelab__DOT__counter)) {
                vlTOPp->prelab__DOT__next_state = 2U;
                vlTOPp->prelab__DOT__counter = 0U;
            } else {
                vlTOPp->prelab__DOT__next_state = 1U;
            }
        } else {
            if ((2U == (IData)(vlTOPp->prelab__DOT__current_state))) {
                if ((0xfaU == vlTOPp->prelab__DOT__counter)) {
                    vlTOPp->prelab__DOT__next_state = 0U;
                    vlTOPp->prelab__DOT__counter = 0U;
                } else {
                    vlTOPp->prelab__DOT__next_state = 2U;
                }
            } else {
                vlTOPp->prelab__DOT__next_state = 0U;
                vlTOPp->prelab__DOT__counter = 0U;
            }
        }
    }
}

VL_INLINE_OPT void Vprelab::_combo__TOP__3(Vprelab__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprelab::_combo__TOP__3\n"); );
    Vprelab* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((0U == (IData)(vlTOPp->prelab__DOT__current_state))) {
        if ((0x9c4U == vlTOPp->prelab__DOT__counter)) {
            vlTOPp->prelab__DOT__next_state = 1U;
            vlTOPp->prelab__DOT__counter = 0U;
        } else {
            vlTOPp->prelab__DOT__next_state = 0U;
        }
    } else {
        if ((1U == (IData)(vlTOPp->prelab__DOT__current_state))) {
            if ((0x9c4U == vlTOPp->prelab__DOT__counter)) {
                vlTOPp->prelab__DOT__next_state = 2U;
                vlTOPp->prelab__DOT__counter = 0U;
            } else {
                vlTOPp->prelab__DOT__next_state = 1U;
            }
        } else {
            if ((2U == (IData)(vlTOPp->prelab__DOT__current_state))) {
                if ((0xfaU == vlTOPp->prelab__DOT__counter)) {
                    vlTOPp->prelab__DOT__next_state = 0U;
                    vlTOPp->prelab__DOT__counter = 0U;
                } else {
                    vlTOPp->prelab__DOT__next_state = 2U;
                }
            } else {
                vlTOPp->prelab__DOT__next_state = 0U;
                vlTOPp->prelab__DOT__counter = 0U;
            }
        }
    }
}

void Vprelab::_eval(Vprelab__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprelab::_eval\n"); );
    Vprelab* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((IData)(vlTOPp->reset) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset))))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
        vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    }
    vlTOPp->_combo__TOP__3(vlSymsp);
    vlTOPp->__Vm_traceActivity = (4U | vlTOPp->__Vm_traceActivity);
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
}

void Vprelab::_eval_initial(Vprelab__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprelab::_eval_initial\n"); );
    Vprelab* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
}

void Vprelab::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprelab::final\n"); );
    // Variables
    Vprelab__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vprelab* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vprelab::_eval_settle(Vprelab__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprelab::_eval_settle\n"); );
    Vprelab* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
}

VL_INLINE_OPT QData Vprelab::_change_request(Vprelab__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprelab::_change_request\n"); );
    Vprelab* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlTOPp->prelab__DOT__counter ^ vlTOPp->__Vchglast__TOP__prelab__DOT__counter));
    VL_DEBUG_IF( if(__req && ((vlTOPp->prelab__DOT__counter ^ vlTOPp->__Vchglast__TOP__prelab__DOT__counter))) VL_DBG_MSGF("        CHANGE: prelab.sv:13: prelab.counter\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__prelab__DOT__counter = vlTOPp->prelab__DOT__counter;
    return __req;
}

#ifdef VL_DEBUG
void Vprelab::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprelab::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG

void Vprelab::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprelab::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    light = VL_RAND_RESET_I(3);
    prelab__DOT__counter = VL_RAND_RESET_I(32);
    prelab__DOT__current_state = VL_RAND_RESET_I(2);
    prelab__DOT__next_state = VL_RAND_RESET_I(2);
    __Vchglast__TOP__prelab__DOT__counter = VL_RAND_RESET_I(32);
    __Vm_traceActivity = 0;
}
