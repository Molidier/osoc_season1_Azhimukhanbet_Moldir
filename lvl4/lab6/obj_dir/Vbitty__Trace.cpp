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
                                   >> 1U)) | (vlTOPp->__Vm_traceActivity 
                                              >> 2U))))) {
            vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 2U))))) {
            vlTOPp->traceChgThis__4(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((2U & vlTOPp->__Vm_traceActivity))) {
            vlTOPp->traceChgThis__5(vlSymsp, vcdp, code);
        }
        vlTOPp->traceChgThis__6(vlSymsp, vcdp, code);
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
    }
}

void Vbitty::traceChgThis__3(Vbitty__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vbitty* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+129,((0xffffU & ((4U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                         ? ((2U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                             ? ((1U 
                                                 & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                                 ? 
                                                (((IData)(vlTOPp->bitty__DOT__regs) 
                                                  == (IData)(vlTOPp->bitty__DOT__out_mux))
                                                  ? 0U
                                                  : 
                                                 (((IData)(vlTOPp->bitty__DOT__regs) 
                                                   > (IData)(vlTOPp->bitty__DOT__out_mux))
                                                   ? 1U
                                                   : 2U))
                                                 : 
                                                ((0xfU 
                                                  >= 
                                                  (0x1fU 
                                                   & (IData)(vlTOPp->bitty__DOT__out_mux)))
                                                  ? 
                                                 ((IData)(vlTOPp->bitty__DOT__regs) 
                                                  >> 
                                                  (0x1fU 
                                                   & (IData)(vlTOPp->bitty__DOT__out_mux)))
                                                  : 0U))
                                             : ((1U 
                                                 & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                                 ? 
                                                ((0xfU 
                                                  >= 
                                                  (0x1fU 
                                                   & (IData)(vlTOPp->bitty__DOT__out_mux)))
                                                  ? 
                                                 ((IData)(vlTOPp->bitty__DOT__regs) 
                                                  << 
                                                  (0x1fU 
                                                   & (IData)(vlTOPp->bitty__DOT__out_mux)))
                                                  : 0U)
                                                 : 
                                                ((IData)(vlTOPp->bitty__DOT__regs) 
                                                 ^ (IData)(vlTOPp->bitty__DOT__out_mux))))
                                         : ((2U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                             ? ((1U 
                                                 & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                                 ? 
                                                ((IData)(vlTOPp->bitty__DOT__regs) 
                                                 | (IData)(vlTOPp->bitty__DOT__out_mux))
                                                 : 
                                                ((IData)(vlTOPp->bitty__DOT__regs) 
                                                 & (IData)(vlTOPp->bitty__DOT__out_mux)))
                                             : ((1U 
                                                 & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                                 ? 
                                                ((IData)(vlTOPp->bitty__DOT__regs) 
                                                 - (IData)(vlTOPp->bitty__DOT__out_mux))
                                                 : 
                                                ((IData)(vlTOPp->bitty__DOT__regs) 
                                                 + (IData)(vlTOPp->bitty__DOT__out_mux))))))),16);
    }
}

void Vbitty::traceChgThis__4(Vbitty__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vbitty* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+137,(vlTOPp->bitty__DOT__mux_sel),3);
        vcdp->chgBus(c+145,(vlTOPp->bitty__DOT__en),8);
        vcdp->chgBus(c+153,(vlTOPp->bitty__DOT__out_mux),16);
        vcdp->chgBit(c+161,(vlTOPp->bitty__DOT__en_s));
        vcdp->chgBit(c+169,(vlTOPp->bitty__DOT__en_c));
        vcdp->chgBit(c+177,(vlTOPp->bitty__DOT__en_inst));
        vcdp->chgBus(c+185,(vlTOPp->bitty__DOT__alu_sel),3);
        vcdp->chgBus(c+193,(vlTOPp->bitty__DOT__cpu_inst__DOT__next_state),2);
        vcdp->chgBit(c+201,((1U & (IData)(vlTOPp->bitty__DOT__en))));
        vcdp->chgBit(c+209,((1U & ((IData)(vlTOPp->bitty__DOT__en) 
                                   >> 1U))));
        vcdp->chgBit(c+217,((1U & ((IData)(vlTOPp->bitty__DOT__en) 
                                   >> 2U))));
        vcdp->chgBit(c+225,((1U & ((IData)(vlTOPp->bitty__DOT__en) 
                                   >> 3U))));
        vcdp->chgBit(c+233,((1U & ((IData)(vlTOPp->bitty__DOT__en) 
                                   >> 4U))));
        vcdp->chgBit(c+241,((1U & ((IData)(vlTOPp->bitty__DOT__en) 
                                   >> 5U))));
        vcdp->chgBit(c+249,((1U & ((IData)(vlTOPp->bitty__DOT__en) 
                                   >> 6U))));
        vcdp->chgBit(c+257,((1U & ((IData)(vlTOPp->bitty__DOT__en) 
                                   >> 7U))));
    }
}

void Vbitty::traceChgThis__5(Vbitty__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vbitty* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+265,(vlTOPp->bitty__DOT__instruction),16);
        vcdp->chgBus(c+273,(vlTOPp->bitty__DOT__regs),16);
        vcdp->chgBus(c+281,(vlTOPp->bitty__DOT__regc),16);
        vcdp->chgBus(c+289,(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state),2);
        vcdp->chgBus(c+297,(vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__0__KET____DOT__reg_out__mux_out),16);
        vcdp->chgBus(c+305,(vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__1__KET____DOT__reg_out__mux_out),16);
        vcdp->chgBus(c+313,(vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__2__KET____DOT__reg_out__mux_out),16);
        vcdp->chgBus(c+321,(vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__3__KET____DOT__reg_out__mux_out),16);
        vcdp->chgBus(c+329,(vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__4__KET____DOT__reg_out__mux_out),16);
        vcdp->chgBus(c+337,(vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__5__KET____DOT__reg_out__mux_out),16);
        vcdp->chgBus(c+345,(vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__6__KET____DOT__reg_out__mux_out),16);
        vcdp->chgBus(c+353,(vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__7__KET____DOT__reg_out__mux_out),16);
    }
}

void Vbitty::traceChgThis__6(Vbitty__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vbitty* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+361,(vlTOPp->run));
        vcdp->chgBit(c+369,(vlTOPp->clk));
        vcdp->chgBit(c+377,(vlTOPp->reset));
        vcdp->chgBus(c+385,(vlTOPp->d_instr),16);
        vcdp->chgBus(c+393,(vlTOPp->d_out),16);
        vcdp->chgBus(c+401,(vlTOPp->rega),16);
        vcdp->chgBus(c+409,(vlTOPp->regb),16);
        vcdp->chgBus(c+417,(vlTOPp->regcc),16);
        vcdp->chgBus(c+425,(vlTOPp->regss),16);
        vcdp->chgBus(c+433,(vlTOPp->reg0),16);
        vcdp->chgBus(c+441,(vlTOPp->reg1),16);
        vcdp->chgBus(c+449,(vlTOPp->reg2),16);
        vcdp->chgBus(c+457,(vlTOPp->reg3),16);
        vcdp->chgBus(c+465,(vlTOPp->reg4),16);
        vcdp->chgBus(c+473,(vlTOPp->reg5),16);
        vcdp->chgBus(c+481,(vlTOPp->reg6),16);
        vcdp->chgBus(c+489,(vlTOPp->reg7),16);
        vcdp->chgBus(c+497,(vlTOPp->reginst),16);
        vcdp->chgBit(c+505,(vlTOPp->done));
    }
}
