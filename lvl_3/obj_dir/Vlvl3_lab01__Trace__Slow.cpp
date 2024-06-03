// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vlvl3_lab01__Syms.h"


//======================

void Vlvl3_lab01::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&Vlvl3_lab01::traceInit, &Vlvl3_lab01::traceFull, &Vlvl3_lab01::traceChg, this);
}
void Vlvl3_lab01::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    Vlvl3_lab01* t = (Vlvl3_lab01*)userthis;
    Vlvl3_lab01__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void Vlvl3_lab01::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vlvl3_lab01* t = (Vlvl3_lab01*)userthis;
    Vlvl3_lab01__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void Vlvl3_lab01::traceInitThis(Vlvl3_lab01__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vlvl3_lab01* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
        vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void Vlvl3_lab01::traceFullThis(Vlvl3_lab01__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vlvl3_lab01* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vlvl3_lab01::traceInitThis__1(Vlvl3_lab01__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vlvl3_lab01* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->declBit(c+49,"carry_in", false,-1);
        vcdp->declBus(c+57,"a_in", false,-1, 15,0);
        vcdp->declBus(c+65,"b_in", false,-1, 15,0);
        vcdp->declBus(c+73,"select", false,-1, 3,0);
        vcdp->declBit(c+81,"mode", false,-1);
        vcdp->declBit(c+89,"carry_out", false,-1);
        vcdp->declBit(c+97,"compare", false,-1);
        vcdp->declBus(c+105,"alu_out", false,-1, 15,0);
        vcdp->declBus(c+129,"alu WIDTH", false,-1, 31,0);
        vcdp->declBit(c+49,"alu carry_in", false,-1);
        vcdp->declBus(c+57,"alu a_in", false,-1, 15,0);
        vcdp->declBus(c+65,"alu b_in", false,-1, 15,0);
        vcdp->declBus(c+73,"alu select", false,-1, 3,0);
        vcdp->declBit(c+81,"alu mode", false,-1);
        vcdp->declBit(c+89,"alu carry_out", false,-1);
        vcdp->declBit(c+97,"alu compare", false,-1);
        vcdp->declBus(c+105,"alu alu_out", false,-1, 15,0);
        vcdp->declBus(c+113,"alu res", false,-1, 15,0);
        vcdp->declBus(c+1,"alu logic_res", false,-1, 15,0);
        vcdp->declBus(c+9,"alu arithmetic_res", false,-1, 15,0);
        vcdp->declBit(c+17,"alu car_out", false,-1);
        vcdp->declBit(c+25,"alu car_arith", false,-1);
        vcdp->declBit(c+33,"alu cmp", false,-1);
        vcdp->declBit(c+121,"alu cmp_ari", false,-1);
        vcdp->declBus(c+129,"alu u1 WIDTH", false,-1, 31,0);
        vcdp->declBus(c+57,"alu u1 in_a", false,-1, 15,0);
        vcdp->declBus(c+65,"alu u1 in_b", false,-1, 15,0);
        vcdp->declBus(c+73,"alu u1 select", false,-1, 3,0);
        vcdp->declBus(c+1,"alu u1 logic_out", false,-1, 15,0);
        vcdp->declBus(c+1,"alu u1 res", false,-1, 15,0);
        vcdp->declBus(c+129,"alu u2 WIDTH", false,-1, 31,0);
        vcdp->declBit(c+49,"alu u2 carry_in", false,-1);
        vcdp->declBus(c+57,"alu u2 in_a", false,-1, 15,0);
        vcdp->declBus(c+65,"alu u2 in_b", false,-1, 15,0);
        vcdp->declBus(c+73,"alu u2 select", false,-1, 3,0);
        vcdp->declBit(c+121,"alu u2 cmp", false,-1);
        vcdp->declBit(c+25,"alu u2 carry_out", false,-1);
        vcdp->declBus(c+9,"alu u2 arithmetic_out", false,-1, 15,0);
        vcdp->declBus(c+41,"alu u2 extended_res", false,-1, 16,0);
    }
}

void Vlvl3_lab01::traceFullThis__1(Vlvl3_lab01__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vlvl3_lab01* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->fullBus(c+1,(vlTOPp->alu__DOT__u1__DOT__res),16);
        vcdp->fullBus(c+9,((0xffffU & vlTOPp->alu__DOT__u2__DOT__extended_res)),16);
        vcdp->fullBit(c+17,(vlTOPp->alu__DOT__car_out));
        vcdp->fullBit(c+25,(vlTOPp->alu__DOT__car_arith));
        vcdp->fullBit(c+33,(vlTOPp->alu__DOT__cmp));
        vcdp->fullBus(c+41,(vlTOPp->alu__DOT__u2__DOT__extended_res),17);
        vcdp->fullBit(c+49,(vlTOPp->carry_in));
        vcdp->fullBus(c+57,(vlTOPp->a_in),16);
        vcdp->fullBus(c+65,(vlTOPp->b_in),16);
        vcdp->fullBus(c+73,(vlTOPp->select),4);
        vcdp->fullBit(c+81,(vlTOPp->mode));
        vcdp->fullBit(c+89,(vlTOPp->carry_out));
        vcdp->fullBit(c+97,(vlTOPp->compare));
        vcdp->fullBus(c+105,(vlTOPp->alu_out),16);
        vcdp->fullBus(c+113,((0xffffU & ((IData)(vlTOPp->mode)
                                          ? (IData)(vlTOPp->alu__DOT__u1__DOT__res)
                                          : vlTOPp->alu__DOT__u2__DOT__extended_res))),16);
        vcdp->fullBit(c+121,((((IData)(vlTOPp->a_in) 
                               == (IData)(vlTOPp->b_in))
                               ? 1U : 0U)));
        vcdp->fullBus(c+129,(0x10U),32);
    }
}
