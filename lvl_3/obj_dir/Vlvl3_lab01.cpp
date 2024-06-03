// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vlvl3_lab01.h for the primary calling header

#include "Vlvl3_lab01.h"
#include "Vlvl3_lab01__Syms.h"

//==========

VL_CTOR_IMP(Vlvl3_lab01) {
    Vlvl3_lab01__Syms* __restrict vlSymsp = __VlSymsp = new Vlvl3_lab01__Syms(this, name());
    Vlvl3_lab01* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vlvl3_lab01::__Vconfigure(Vlvl3_lab01__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vlvl3_lab01::~Vlvl3_lab01() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void Vlvl3_lab01::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vlvl3_lab01::eval\n"); );
    Vlvl3_lab01__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vlvl3_lab01* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("lvl3_lab01.sv", 119, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vlvl3_lab01::_eval_initial_loop(Vlvl3_lab01__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("lvl3_lab01.sv", 119, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vlvl3_lab01::_initial__TOP__1(Vlvl3_lab01__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlvl3_lab01::_initial__TOP__1\n"); );
    Vlvl3_lab01* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->alu__DOT__car_arith = 0U;
}

VL_INLINE_OPT void Vlvl3_lab01::_combo__TOP__2(Vlvl3_lab01__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlvl3_lab01::_combo__TOP__2\n"); );
    Vlvl3_lab01* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->alu__DOT__cmp = ((IData)(vlTOPp->a_in) 
                             == (IData)(vlTOPp->b_in));
    if ((1U & (~ (IData)(vlTOPp->mode)))) {
        vlTOPp->alu__DOT__cmp = (((IData)(vlTOPp->a_in) 
                                  == (IData)(vlTOPp->b_in))
                                  ? 1U : 0U);
    }
    vlTOPp->alu__DOT__u1__DOT__res = (0xffffU & ((8U 
                                                  & (IData)(vlTOPp->select))
                                                  ? 
                                                 ((4U 
                                                   & (IData)(vlTOPp->select))
                                                   ? 
                                                  ((2U 
                                                    & (IData)(vlTOPp->select))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->select))
                                                     ? (IData)(vlTOPp->a_in)
                                                     : 
                                                    ((IData)(vlTOPp->a_in) 
                                                     | (IData)(vlTOPp->b_in)))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->select))
                                                     ? 
                                                    ((IData)(vlTOPp->a_in) 
                                                     | (~ (IData)(vlTOPp->b_in)))
                                                     : 1U))
                                                   : 
                                                  ((2U 
                                                    & (IData)(vlTOPp->select))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->select))
                                                     ? 
                                                    ((IData)(vlTOPp->a_in) 
                                                     & (IData)(vlTOPp->b_in))
                                                     : (IData)(vlTOPp->b_in))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->select))
                                                     ? 
                                                    (~ 
                                                     ((IData)(vlTOPp->a_in) 
                                                      ^ (IData)(vlTOPp->b_in)))
                                                     : 
                                                    ((~ (IData)(vlTOPp->a_in)) 
                                                     | (IData)(vlTOPp->b_in)))))
                                                  : 
                                                 ((4U 
                                                   & (IData)(vlTOPp->select))
                                                   ? 
                                                  ((2U 
                                                    & (IData)(vlTOPp->select))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->select))
                                                     ? 
                                                    ((IData)(vlTOPp->a_in) 
                                                     & (~ (IData)(vlTOPp->b_in)))
                                                     : 
                                                    ((IData)(vlTOPp->a_in) 
                                                     ^ (IData)(vlTOPp->b_in)))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->select))
                                                     ? 
                                                    (~ (IData)(vlTOPp->b_in))
                                                     : 
                                                    (~ 
                                                     ((IData)(vlTOPp->a_in) 
                                                      & (IData)(vlTOPp->b_in)))))
                                                   : 
                                                  ((2U 
                                                    & (IData)(vlTOPp->select))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->select))
                                                     ? 0U
                                                     : 
                                                    ((~ (IData)(vlTOPp->a_in)) 
                                                     & (IData)(vlTOPp->b_in)))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->select))
                                                     ? 
                                                    (~ 
                                                     ((IData)(vlTOPp->a_in) 
                                                      | (IData)(vlTOPp->b_in)))
                                                     : 
                                                    (~ (IData)(vlTOPp->a_in)))))));
    vlTOPp->alu__DOT__u2__DOT__extended_res = (0x1ffffU 
                                               & ((8U 
                                                   & (IData)(vlTOPp->select))
                                                   ? 
                                                  ((4U 
                                                    & (IData)(vlTOPp->select))
                                                    ? 
                                                   ((2U 
                                                     & (IData)(vlTOPp->select))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(vlTOPp->select))
                                                      ? 
                                                     ((IData)(vlTOPp->a_in) 
                                                      + (IData)(vlTOPp->carry_in))
                                                      : 
                                                     (((0xffffU 
                                                        & ((IData)(vlTOPp->a_in) 
                                                           | (~ (IData)(vlTOPp->b_in)))) 
                                                       + (IData)(vlTOPp->a_in)) 
                                                      + (IData)(vlTOPp->carry_in)))
                                                     : 
                                                    ((1U 
                                                      & (IData)(vlTOPp->select))
                                                      ? 
                                                     ((((IData)(vlTOPp->a_in) 
                                                        | (IData)(vlTOPp->b_in)) 
                                                       + (IData)(vlTOPp->a_in)) 
                                                      + (IData)(vlTOPp->carry_in))
                                                      : 
                                                     (((IData)(vlTOPp->a_in) 
                                                       + (IData)(vlTOPp->a_in)) 
                                                      + (IData)(vlTOPp->carry_in))))
                                                    : 
                                                   ((2U 
                                                     & (IData)(vlTOPp->select))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(vlTOPp->select))
                                                      ? 
                                                     ((IData)(vlTOPp->a_in) 
                                                      & (IData)(vlTOPp->b_in))
                                                      : 
                                                     (((0xffffU 
                                                        & ((IData)(vlTOPp->a_in) 
                                                           | (~ (IData)(vlTOPp->b_in)))) 
                                                       + 
                                                       ((IData)(vlTOPp->a_in) 
                                                        & (IData)(vlTOPp->b_in))) 
                                                      + (IData)(vlTOPp->carry_in)))
                                                     : 
                                                    ((1U 
                                                      & (IData)(vlTOPp->select))
                                                      ? 
                                                     (((IData)(vlTOPp->a_in) 
                                                       + (IData)(vlTOPp->b_in)) 
                                                      + (IData)(vlTOPp->carry_in))
                                                      : 
                                                     (((IData)(vlTOPp->a_in) 
                                                       + 
                                                       ((IData)(vlTOPp->a_in) 
                                                        & (IData)(vlTOPp->b_in))) 
                                                      + (IData)(vlTOPp->carry_in)))))
                                                   : 
                                                  ((4U 
                                                    & (IData)(vlTOPp->select))
                                                    ? 
                                                   ((2U 
                                                     & (IData)(vlTOPp->select))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(vlTOPp->select))
                                                      ? 
                                                     ((IData)(vlTOPp->a_in) 
                                                      & (~ (IData)(vlTOPp->b_in)))
                                                      : 
                                                     ((IData)(vlTOPp->a_in) 
                                                      + 
                                                      (0xffffU 
                                                       & (~ (IData)(vlTOPp->b_in)))))
                                                     : 
                                                    ((1U 
                                                      & (IData)(vlTOPp->select))
                                                      ? 
                                                     ((0xffffU 
                                                       & (((IData)(vlTOPp->a_in) 
                                                           | (IData)(vlTOPp->b_in)) 
                                                          + 
                                                          ((IData)(vlTOPp->a_in) 
                                                           & (~ (IData)(vlTOPp->b_in))))) 
                                                      + (IData)(vlTOPp->carry_in))
                                                      : 
                                                     ((IData)(vlTOPp->a_in) 
                                                      | (0xffffU 
                                                         & ((IData)(vlTOPp->a_in) 
                                                            & (~ (IData)(vlTOPp->b_in)))))))
                                                    : 
                                                   ((2U 
                                                     & (IData)(vlTOPp->select))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(vlTOPp->select))
                                                      ? 0x1ffffU
                                                      : 
                                                     ((IData)(vlTOPp->a_in) 
                                                      | (0xffffU 
                                                         & (~ (IData)(vlTOPp->b_in)))))
                                                     : 
                                                    ((1U 
                                                      & (IData)(vlTOPp->select))
                                                      ? 
                                                     ((IData)(vlTOPp->a_in) 
                                                      | (IData)(vlTOPp->b_in))
                                                      : (IData)(vlTOPp->a_in))))));
    vlTOPp->compare = vlTOPp->alu__DOT__cmp;
    vlTOPp->alu_out = (0xffffU & ((IData)(vlTOPp->mode)
                                   ? (IData)(vlTOPp->alu__DOT__u1__DOT__res)
                                   : vlTOPp->alu__DOT__u2__DOT__extended_res));
    vlTOPp->alu__DOT__car_arith = (1U & (vlTOPp->alu__DOT__u2__DOT__extended_res 
                                         >> 0x10U));
    vlTOPp->alu__DOT__car_out = ((~ (IData)(vlTOPp->mode)) 
                                 & (IData)(vlTOPp->alu__DOT__car_arith));
    vlTOPp->carry_out = vlTOPp->alu__DOT__car_out;
}

void Vlvl3_lab01::_eval(Vlvl3_lab01__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlvl3_lab01::_eval\n"); );
    Vlvl3_lab01* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__2(vlSymsp);
    vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
}

void Vlvl3_lab01::_eval_initial(Vlvl3_lab01__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlvl3_lab01::_eval_initial\n"); );
    Vlvl3_lab01* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
}

void Vlvl3_lab01::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlvl3_lab01::final\n"); );
    // Variables
    Vlvl3_lab01__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vlvl3_lab01* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vlvl3_lab01::_eval_settle(Vlvl3_lab01__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlvl3_lab01::_eval_settle\n"); );
    Vlvl3_lab01* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__2(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
}

VL_INLINE_OPT QData Vlvl3_lab01::_change_request(Vlvl3_lab01__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlvl3_lab01::_change_request\n"); );
    Vlvl3_lab01* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vlvl3_lab01::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlvl3_lab01::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((carry_in & 0xfeU))) {
        Verilated::overWidthError("carry_in");}
    if (VL_UNLIKELY((select & 0xf0U))) {
        Verilated::overWidthError("select");}
    if (VL_UNLIKELY((mode & 0xfeU))) {
        Verilated::overWidthError("mode");}
}
#endif  // VL_DEBUG

void Vlvl3_lab01::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlvl3_lab01::_ctor_var_reset\n"); );
    // Body
    carry_in = VL_RAND_RESET_I(1);
    a_in = VL_RAND_RESET_I(16);
    b_in = VL_RAND_RESET_I(16);
    select = VL_RAND_RESET_I(4);
    mode = VL_RAND_RESET_I(1);
    carry_out = VL_RAND_RESET_I(1);
    compare = VL_RAND_RESET_I(1);
    alu_out = VL_RAND_RESET_I(16);
    alu__DOT__car_out = VL_RAND_RESET_I(1);
    alu__DOT__car_arith = VL_RAND_RESET_I(1);
    alu__DOT__cmp = VL_RAND_RESET_I(1);
    alu__DOT__u1__DOT__res = VL_RAND_RESET_I(16);
    alu__DOT__u2__DOT__extended_res = VL_RAND_RESET_I(17);
    __Vm_traceActivity = 0;
}
