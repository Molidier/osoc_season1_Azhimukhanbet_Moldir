// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbitty.h for the primary calling header

#include "Vbitty___024unit.h"
#include "Vbitty__Syms.h"

#include "verilated_dpi.h"

//==========

VL_CTOR_IMP(Vbitty___024unit) {
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void Vbitty___024unit::__Vconfigure(Vbitty__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vbitty___024unit::~Vbitty___024unit() {
}

VL_INLINE_OPT void Vbitty___024unit::__Vdpiimwrap_evaluate_values_TOP____024unit(const IData/*31:0*/ instr, const IData/*31:0*/ out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbitty___024unit::__Vdpiimwrap_evaluate_values_TOP____024unit\n"); );
    // Body
    int instr__Vcvt;
    instr__Vcvt = instr;
    int out__Vcvt;
    out__Vcvt = out;
    evaluate_values(instr__Vcvt, out__Vcvt);
}

VL_INLINE_OPT void Vbitty___024unit::__Vdpiimwrap_notify_counter_nine_here_TOP____024unit() {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbitty___024unit::__Vdpiimwrap_notify_counter_nine_here_TOP____024unit\n"); );
    // Body
    notify_counter_nine_here();
}

VL_INLINE_OPT void Vbitty___024unit::__Vdpiimwrap_notify_counter_nine_1_TOP____024unit() {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbitty___024unit::__Vdpiimwrap_notify_counter_nine_1_TOP____024unit\n"); );
    // Body
    notify_counter_nine_1();
}

VL_INLINE_OPT void Vbitty___024unit::__Vdpiimwrap_notify_counter_nine_2_TOP____024unit() {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbitty___024unit::__Vdpiimwrap_notify_counter_nine_2_TOP____024unit\n"); );
    // Body
    notify_counter_nine_2();
}

VL_INLINE_OPT void Vbitty___024unit::__Vdpiimwrap_notify_counter_nine_3_TOP____024unit() {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbitty___024unit::__Vdpiimwrap_notify_counter_nine_3_TOP____024unit\n"); );
    // Body
    notify_counter_nine_3();
}

void Vbitty___024unit::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbitty___024unit::_ctor_var_reset\n"); );
}
