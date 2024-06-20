// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vprelab__Syms.h"


//======================

void Vprelab::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vprelab* t = (Vprelab*)userthis;
    Vprelab__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
        t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void Vprelab::traceChgThis(Vprelab__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vprelab* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY((1U & ((vlTOPp->__Vm_traceActivity 
                                | (vlTOPp->__Vm_traceActivity 
                                   >> 1U)) | (vlTOPp->__Vm_traceActivity 
                                              >> 2U))))) {
            vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 2U))))) {
            vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((2U & vlTOPp->__Vm_traceActivity))) {
            vlTOPp->traceChgThis__4(vlSymsp, vcdp, code);
        }
        vlTOPp->traceChgThis__5(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vprelab::traceChgThis__2(Vprelab__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vprelab* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+1,(vlTOPp->prelab__DOT__counter),32);
    }
}

void Vprelab::traceChgThis__3(Vprelab__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vprelab* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+9,(vlTOPp->prelab__DOT__next_state),2);
    }
}

void Vprelab::traceChgThis__4(Vprelab__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vprelab* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+17,(vlTOPp->prelab__DOT__current_state),2);
    }
}

void Vprelab::traceChgThis__5(Vprelab__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vprelab* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+25,(vlTOPp->clk));
        vcdp->chgBit(c+33,(vlTOPp->reset));
        vcdp->chgBus(c+41,(vlTOPp->light),3);
    }
}
