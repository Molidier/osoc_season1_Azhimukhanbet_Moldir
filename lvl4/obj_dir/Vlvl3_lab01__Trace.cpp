// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vlvl3_lab01__Syms.h"


//======================

void Vlvl3_lab01::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vlvl3_lab01* t = (Vlvl3_lab01*)userthis;
    Vlvl3_lab01__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
        t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void Vlvl3_lab01::traceChgThis(Vlvl3_lab01__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vlvl3_lab01* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 1U))))) {
            vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
        }
        vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vlvl3_lab01::traceChgThis__2(Vlvl3_lab01__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vlvl3_lab01* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+1,(vlTOPp->alu__DOT__u1__DOT__res),16);
        vcdp->chgBus(c+9,((0xffffU & vlTOPp->alu__DOT__u2__DOT__extended_res)),16);
        vcdp->chgBit(c+17,(vlTOPp->alu__DOT__car_out));
        vcdp->chgBit(c+25,(vlTOPp->alu__DOT__car_arith));
        vcdp->chgBit(c+33,(vlTOPp->alu__DOT__cmp));
        vcdp->chgBus(c+41,(vlTOPp->alu__DOT__u2__DOT__extended_res),17);
    }
}

void Vlvl3_lab01::traceChgThis__3(Vlvl3_lab01__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vlvl3_lab01* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+49,(vlTOPp->carry_in));
        vcdp->chgBus(c+57,(vlTOPp->a_in),16);
        vcdp->chgBus(c+65,(vlTOPp->b_in),16);
        vcdp->chgBus(c+73,(vlTOPp->select),4);
        vcdp->chgBit(c+81,(vlTOPp->mode));
        vcdp->chgBit(c+89,(vlTOPp->carry_out));
        vcdp->chgBit(c+97,(vlTOPp->compare));
        vcdp->chgBus(c+105,(vlTOPp->alu_out),16);
        vcdp->chgBus(c+113,((0xffffU & ((IData)(vlTOPp->mode)
                                         ? (IData)(vlTOPp->alu__DOT__u1__DOT__res)
                                         : vlTOPp->alu__DOT__u2__DOT__extended_res))),16);
        vcdp->chgBit(c+121,((((IData)(vlTOPp->a_in) 
                              == (IData)(vlTOPp->b_in))
                              ? 1U : 0U)));
    }
}
