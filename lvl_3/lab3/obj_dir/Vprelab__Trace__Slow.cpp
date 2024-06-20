// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vprelab__Syms.h"


//======================

void Vprelab::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&Vprelab::traceInit, &Vprelab::traceFull, &Vprelab::traceChg, this);
}
void Vprelab::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    Vprelab* t = (Vprelab*)userthis;
    Vprelab__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void Vprelab::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vprelab* t = (Vprelab*)userthis;
    Vprelab__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void Vprelab::traceInitThis(Vprelab__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vprelab* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
        vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void Vprelab::traceFullThis(Vprelab__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vprelab* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vprelab::traceInitThis__1(Vprelab__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vprelab* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->declBit(c+25,"clk", false,-1);
        vcdp->declBit(c+33,"reset", false,-1);
        vcdp->declBus(c+41,"light", false,-1, 2,0);
        vcdp->declBit(c+25,"prelab clk", false,-1);
        vcdp->declBit(c+33,"prelab reset", false,-1);
        vcdp->declBus(c+41,"prelab light", false,-1, 2,0);
        vcdp->declBus(c+49,"prelab RED", false,-1, 1,0);
        vcdp->declBus(c+57,"prelab GREEN", false,-1, 1,0);
        vcdp->declBus(c+65,"prelab YELLOW", false,-1, 1,0);
        vcdp->declBus(c+73,"prelab CLOCK_FREQ", false,-1, 31,0);
        vcdp->declBus(c+81,"prelab DURATION", false,-1, 31,0);
        vcdp->declBus(c+1,"prelab counter", false,-1, 31,0);
        vcdp->declBus(c+17,"prelab current_state", false,-1, 1,0);
        vcdp->declBus(c+9,"prelab next_state", false,-1, 1,0);
    }
}

void Vprelab::traceFullThis__1(Vprelab__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vprelab* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->fullBus(c+1,(vlTOPp->prelab__DOT__counter),32);
        vcdp->fullBus(c+9,(vlTOPp->prelab__DOT__next_state),2);
        vcdp->fullBus(c+17,(vlTOPp->prelab__DOT__current_state),2);
        vcdp->fullBit(c+25,(vlTOPp->clk));
        vcdp->fullBit(c+33,(vlTOPp->reset));
        vcdp->fullBus(c+41,(vlTOPp->light),3);
        vcdp->fullBus(c+49,(0U),2);
        vcdp->fullBus(c+57,(1U),2);
        vcdp->fullBus(c+65,(2U),2);
        vcdp->fullBus(c+73,(0x32U),32);
        vcdp->fullBus(c+81,(5U),32);
    }
}
