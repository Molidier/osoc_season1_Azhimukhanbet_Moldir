// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vbitty__Syms.h"


//======================

void Vbitty::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vbitty* t = (Vbitty*)userthis;
    Vbitty__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
        t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void Vbitty::traceChgThis(Vbitty__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vbitty* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 1U))))) {
            vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((1U & ((vlTOPp->__Vm_traceActivity 
                                | (vlTOPp->__Vm_traceActivity 
                                   >> 2U)) | (vlTOPp->__Vm_traceActivity 
                                              >> 3U))))) {
            vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 3U))))) {
            vlTOPp->traceChgThis__4(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((2U & vlTOPp->__Vm_traceActivity))) {
            vlTOPp->traceChgThis__5(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((4U & vlTOPp->__Vm_traceActivity))) {
            vlTOPp->traceChgThis__6(vlSymsp, vcdp, code);
        }
        vlTOPp->traceChgThis__7(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vbitty::traceChgThis__2(Vbitty__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vbitty* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+1,(vlTOPp->bitty__DOT__out[0]),16);
        vcdp->chgBus(c+2,(vlTOPp->bitty__DOT__out[1]),16);
        vcdp->chgBus(c+3,(vlTOPp->bitty__DOT__out[2]),16);
        vcdp->chgBus(c+4,(vlTOPp->bitty__DOT__out[3]),16);
        vcdp->chgBus(c+5,(vlTOPp->bitty__DOT__out[4]),16);
        vcdp->chgBus(c+6,(vlTOPp->bitty__DOT__out[5]),16);
        vcdp->chgBus(c+7,(vlTOPp->bitty__DOT__out[6]),16);
        vcdp->chgBus(c+8,(vlTOPp->bitty__DOT__out[7]),16);
        vcdp->chgBus(c+65,(vlTOPp->bitty__DOT__out[0U]),16);
        vcdp->chgBus(c+73,(vlTOPp->bitty__DOT__out[1U]),16);
        vcdp->chgBus(c+81,(vlTOPp->bitty__DOT__out[2U]),16);
        vcdp->chgBus(c+89,(vlTOPp->bitty__DOT__out[3U]),16);
        vcdp->chgBus(c+97,(vlTOPp->bitty__DOT__out[4U]),16);
        vcdp->chgBus(c+105,(vlTOPp->bitty__DOT__out
                            [5U]),16);
        vcdp->chgBus(c+113,(vlTOPp->bitty__DOT__out
                            [6U]),16);
        vcdp->chgBus(c+121,(vlTOPp->bitty__DOT__out
                            [7U]),16);
        vcdp->chgBus(c+129,(vlTOPp->bitty__DOT__out
                            [0U]),16);
        vcdp->chgBus(c+137,(vlTOPp->bitty__DOT__out
                            [1U]),16);
        vcdp->chgBus(c+145,(vlTOPp->bitty__DOT__out
                            [2U]),16);
        vcdp->chgBus(c+153,(vlTOPp->bitty__DOT__out
                            [3U]),16);
        vcdp->chgBus(c+161,(vlTOPp->bitty__DOT__out
                            [4U]),16);
        vcdp->chgBus(c+169,(vlTOPp->bitty__DOT__out
                            [5U]),16);
        vcdp->chgBus(c+177,(vlTOPp->bitty__DOT__out
                            [6U]),16);
        vcdp->chgBus(c+185,(vlTOPp->bitty__DOT__out
                            [7U]),16);
    }
}

void Vbitty::traceChgThis__3(Vbitty__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vbitty* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+193,(((0U == (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))
                              ? 1U : ((1U == (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))
                                       ? 3U : ((3U 
                                                == (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))
                                                ? ((IData)(vlTOPp->bitty__DOT__done)
                                                    ? 0U
                                                    : 3U)
                                                : 0U)))),2);
    }
}

void Vbitty::traceChgThis__4(Vbitty__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vbitty* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+201,(vlTOPp->bitty__DOT__mux_sel),4);
        vcdp->chgBus(c+209,(vlTOPp->bitty__DOT__en),8);
        vcdp->chgBus(c+217,(vlTOPp->bitty__DOT__out_mux),16);
        vcdp->chgBus(c+225,(vlTOPp->bitty__DOT__alu_inst__DOT__res),16);
        vcdp->chgBit(c+233,(vlTOPp->bitty__DOT__en_s));
        vcdp->chgBit(c+241,(vlTOPp->bitty__DOT__en_c));
        vcdp->chgBit(c+249,(vlTOPp->bitty__DOT__en_inst));
        vcdp->chgBit(c+257,(vlTOPp->bitty__DOT__done));
        vcdp->chgBit(c+265,(vlTOPp->bitty__DOT__mode));
        vcdp->chgBus(c+273,(vlTOPp->bitty__DOT__alu_sel),4);
        vcdp->chgBus(c+281,(vlTOPp->bitty__DOT__alu_inst__DOT__u1__DOT__res),16);
        vcdp->chgBus(c+289,((0xffffU & vlTOPp->bitty__DOT__alu_inst__DOT__u2__DOT__extended_res)),16);
        vcdp->chgBit(c+297,(vlTOPp->bitty__DOT__alu_inst__DOT__car_out));
        vcdp->chgBit(c+305,(vlTOPp->bitty__DOT__alu_inst__DOT__car_arith));
        vcdp->chgBus(c+313,(vlTOPp->bitty__DOT__alu_inst__DOT__u2__DOT__extended_res),17);
        vcdp->chgBit(c+321,((1U & (IData)(vlTOPp->bitty__DOT__en))));
        vcdp->chgBit(c+329,((1U & ((IData)(vlTOPp->bitty__DOT__en) 
                                   >> 1U))));
        vcdp->chgBit(c+337,((1U & ((IData)(vlTOPp->bitty__DOT__en) 
                                   >> 2U))));
        vcdp->chgBit(c+345,((1U & ((IData)(vlTOPp->bitty__DOT__en) 
                                   >> 3U))));
        vcdp->chgBit(c+353,((1U & ((IData)(vlTOPp->bitty__DOT__en) 
                                   >> 4U))));
        vcdp->chgBit(c+361,((1U & ((IData)(vlTOPp->bitty__DOT__en) 
                                   >> 5U))));
        vcdp->chgBit(c+369,((1U & ((IData)(vlTOPp->bitty__DOT__en) 
                                   >> 6U))));
        vcdp->chgBit(c+377,((1U & ((IData)(vlTOPp->bitty__DOT__en) 
                                   >> 7U))));
    }
}

void Vbitty::traceChgThis__5(Vbitty__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vbitty* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+385,(vlTOPp->bitty__DOT__instruction),16);
        vcdp->chgBus(c+393,(vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__0__KET____DOT__reg_out__mux_out),16);
        vcdp->chgBus(c+401,(vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__1__KET____DOT__reg_out__mux_out),16);
        vcdp->chgBus(c+409,(vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__2__KET____DOT__reg_out__mux_out),16);
        vcdp->chgBus(c+417,(vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__3__KET____DOT__reg_out__mux_out),16);
        vcdp->chgBus(c+425,(vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__4__KET____DOT__reg_out__mux_out),16);
        vcdp->chgBus(c+433,(vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__5__KET____DOT__reg_out__mux_out),16);
        vcdp->chgBus(c+441,(vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__6__KET____DOT__reg_out__mux_out),16);
        vcdp->chgBus(c+449,(vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__7__KET____DOT__reg_out__mux_out),16);
    }
}

void Vbitty::traceChgThis__6(Vbitty__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vbitty* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+457,(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state),2);
    }
}

void Vbitty::traceChgThis__7(Vbitty__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vbitty* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+465,(vlTOPp->run));
        vcdp->chgBit(c+473,(vlTOPp->clk));
        vcdp->chgBit(c+481,(vlTOPp->reset));
        vcdp->chgBus(c+489,(vlTOPp->d_instr),16);
        vcdp->chgBit(c+497,(vlTOPp->carry_in));
        vcdp->chgBus(c+505,(vlTOPp->reg0),16);
        vcdp->chgBus(c+513,(vlTOPp->reg1),16);
        vcdp->chgBus(c+521,(vlTOPp->reg2),16);
        vcdp->chgBus(c+529,(vlTOPp->reg3),16);
        vcdp->chgBus(c+537,(vlTOPp->reg4),16);
        vcdp->chgBus(c+545,(vlTOPp->reg5),16);
        vcdp->chgBus(c+553,(vlTOPp->reg6),16);
        vcdp->chgBus(c+561,(vlTOPp->reg7),16);
        vcdp->chgBus(c+569,(vlTOPp->regs),16);
        vcdp->chgBus(c+577,(vlTOPp->regc),16);
        vcdp->chgBus(c+585,(vlTOPp->d_out),16);
        vcdp->chgBit(c+593,(vlTOPp->carry_out));
    }
}
