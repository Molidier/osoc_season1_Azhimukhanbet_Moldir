// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcounter.h for the primary calling header

#include "Vcounter___024unit.h"
#include "Vcounter__Syms.h"

#include "verilated_dpi.h"

//==========

VL_CTOR_IMP(Vcounter___024unit) {
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void Vcounter___024unit::__Vconfigure(Vcounter__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vcounter___024unit::~Vcounter___024unit() {
}

VL_INLINE_OPT void Vcounter___024unit::__Vdpiimwrap_notify_counter_nine_TOP____024unit() {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vcounter___024unit::__Vdpiimwrap_notify_counter_nine_TOP____024unit\n"); );
    // Body
    notify_counter_nine();
}

void Vcounter___024unit::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vcounter___024unit::_ctor_var_reset\n"); );
}
