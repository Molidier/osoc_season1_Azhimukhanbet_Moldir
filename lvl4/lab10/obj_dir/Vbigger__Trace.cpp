// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vbigger__Syms.h"


//======================

void Vbigger::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vbigger* t = (Vbigger*)userthis;
    Vbigger__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
        t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void Vbigger::traceChgThis(Vbigger__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vbigger* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 1U))))) {
            vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((2U & vlTOPp->__Vm_traceActivity))) {
            vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
        }
        vlTOPp->traceChgThis__4(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vbigger::traceChgThis__2(Vbigger__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vbigger* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+1,(vlTOPp->bigger__DOT__next_state),4);
        vcdp->chgBus(c+9,(vlTOPp->bigger__DOT__new_pc),8);
        vcdp->chgBus(c+17,(vlTOPp->bigger__DOT__instance3__DOT__mux_sel),4);
        vcdp->chgBus(c+25,(vlTOPp->bigger__DOT__instance3__DOT__en),8);
        vcdp->chgBus(c+33,(vlTOPp->bigger__DOT__instance3__DOT__out[0]),16);
        vcdp->chgBus(c+34,(vlTOPp->bigger__DOT__instance3__DOT__out[1]),16);
        vcdp->chgBus(c+35,(vlTOPp->bigger__DOT__instance3__DOT__out[2]),16);
        vcdp->chgBus(c+36,(vlTOPp->bigger__DOT__instance3__DOT__out[3]),16);
        vcdp->chgBus(c+37,(vlTOPp->bigger__DOT__instance3__DOT__out[4]),16);
        vcdp->chgBus(c+38,(vlTOPp->bigger__DOT__instance3__DOT__out[5]),16);
        vcdp->chgBus(c+39,(vlTOPp->bigger__DOT__instance3__DOT__out[6]),16);
        vcdp->chgBus(c+40,(vlTOPp->bigger__DOT__instance3__DOT__out[7]),16);
        vcdp->chgBus(c+97,(vlTOPp->bigger__DOT__instance3__DOT__out_mux),16);
        vcdp->chgBus(c+105,((0xffffU & ((4U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__alu_sel))
                                         ? ((2U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__alu_sel))
                                             ? ((1U 
                                                 & (IData)(vlTOPp->bigger__DOT__instance3__DOT__alu_sel))
                                                 ? 
                                                (((IData)(vlTOPp->bigger__DOT__instance3__DOT__regs) 
                                                  == (IData)(vlTOPp->bigger__DOT__instance3__DOT__out_mux))
                                                  ? 0U
                                                  : 
                                                 (((IData)(vlTOPp->bigger__DOT__instance3__DOT__regs) 
                                                   > (IData)(vlTOPp->bigger__DOT__instance3__DOT__out_mux))
                                                   ? 1U
                                                   : 2U))
                                                 : 
                                                ((0xfU 
                                                  >= 
                                                  (0x1fU 
                                                   & (IData)(vlTOPp->bigger__DOT__instance3__DOT__out_mux)))
                                                  ? 
                                                 ((IData)(vlTOPp->bigger__DOT__instance3__DOT__regs) 
                                                  >> 
                                                  (0x1fU 
                                                   & (IData)(vlTOPp->bigger__DOT__instance3__DOT__out_mux)))
                                                  : 0U))
                                             : ((1U 
                                                 & (IData)(vlTOPp->bigger__DOT__instance3__DOT__alu_sel))
                                                 ? 
                                                ((0xfU 
                                                  >= 
                                                  (0x1fU 
                                                   & (IData)(vlTOPp->bigger__DOT__instance3__DOT__out_mux)))
                                                  ? 
                                                 ((IData)(vlTOPp->bigger__DOT__instance3__DOT__regs) 
                                                  << 
                                                  (0x1fU 
                                                   & (IData)(vlTOPp->bigger__DOT__instance3__DOT__out_mux)))
                                                  : 0U)
                                                 : 
                                                ((IData)(vlTOPp->bigger__DOT__instance3__DOT__regs) 
                                                 ^ (IData)(vlTOPp->bigger__DOT__instance3__DOT__out_mux))))
                                         : ((2U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__alu_sel))
                                             ? ((1U 
                                                 & (IData)(vlTOPp->bigger__DOT__instance3__DOT__alu_sel))
                                                 ? 
                                                ((IData)(vlTOPp->bigger__DOT__instance3__DOT__regs) 
                                                 | (IData)(vlTOPp->bigger__DOT__instance3__DOT__out_mux))
                                                 : 
                                                ((IData)(vlTOPp->bigger__DOT__instance3__DOT__regs) 
                                                 & (IData)(vlTOPp->bigger__DOT__instance3__DOT__out_mux)))
                                             : ((1U 
                                                 & (IData)(vlTOPp->bigger__DOT__instance3__DOT__alu_sel))
                                                 ? 
                                                ((IData)(vlTOPp->bigger__DOT__instance3__DOT__regs) 
                                                 - (IData)(vlTOPp->bigger__DOT__instance3__DOT__out_mux))
                                                 : 
                                                ((IData)(vlTOPp->bigger__DOT__instance3__DOT__regs) 
                                                 + (IData)(vlTOPp->bigger__DOT__instance3__DOT__out_mux))))))),16);
        vcdp->chgBit(c+113,(vlTOPp->bigger__DOT__instance3__DOT__en_s));
        vcdp->chgBit(c+121,(vlTOPp->bigger__DOT__instance3__DOT__en_c));
        vcdp->chgBit(c+129,(vlTOPp->bigger__DOT__instance3__DOT__en_inst));
        vcdp->chgBus(c+137,(vlTOPp->bigger__DOT__instance3__DOT__alu_sel),3);
        vcdp->chgBus(c+145,(vlTOPp->bigger__DOT__instance3__DOT__im_d),16);
        vcdp->chgBus(c+153,(vlTOPp->bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state),2);
        vcdp->chgBus(c+161,(vlTOPp->bigger__DOT__instance3__DOT__out
                            [0U]),16);
        vcdp->chgBus(c+169,(vlTOPp->bigger__DOT__instance3__DOT__out
                            [1U]),16);
        vcdp->chgBus(c+177,(vlTOPp->bigger__DOT__instance3__DOT__out
                            [2U]),16);
        vcdp->chgBus(c+185,(vlTOPp->bigger__DOT__instance3__DOT__out
                            [3U]),16);
        vcdp->chgBus(c+193,(vlTOPp->bigger__DOT__instance3__DOT__out
                            [4U]),16);
        vcdp->chgBus(c+201,(vlTOPp->bigger__DOT__instance3__DOT__out
                            [5U]),16);
        vcdp->chgBus(c+209,(vlTOPp->bigger__DOT__instance3__DOT__out
                            [6U]),16);
        vcdp->chgBus(c+217,(vlTOPp->bigger__DOT__instance3__DOT__out
                            [7U]),16);
        vcdp->chgBit(c+225,((1U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__en))));
        vcdp->chgBit(c+233,((1U & ((IData)(vlTOPp->bigger__DOT__instance3__DOT__en) 
                                   >> 1U))));
        vcdp->chgBit(c+241,((1U & ((IData)(vlTOPp->bigger__DOT__instance3__DOT__en) 
                                   >> 2U))));
        vcdp->chgBit(c+249,((1U & ((IData)(vlTOPp->bigger__DOT__instance3__DOT__en) 
                                   >> 3U))));
        vcdp->chgBit(c+257,((1U & ((IData)(vlTOPp->bigger__DOT__instance3__DOT__en) 
                                   >> 4U))));
        vcdp->chgBit(c+265,((1U & ((IData)(vlTOPp->bigger__DOT__instance3__DOT__en) 
                                   >> 5U))));
        vcdp->chgBit(c+273,((1U & ((IData)(vlTOPp->bigger__DOT__instance3__DOT__en) 
                                   >> 6U))));
        vcdp->chgBit(c+281,((1U & ((IData)(vlTOPp->bigger__DOT__instance3__DOT__en) 
                                   >> 7U))));
    }
}

void Vbigger::traceChgThis__3(Vbigger__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vbigger* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+289,(vlTOPp->bigger__DOT__cur_state),4);
        vcdp->chgBit(c+297,(((0U != (IData)(vlTOPp->bigger__DOT__cur_state)) 
                             & (3U == (IData)(vlTOPp->bigger__DOT__cur_state)))));
        vcdp->chgBus(c+305,(vlTOPp->bigger__DOT__mem_out),16);
        vcdp->chgBus(c+313,(vlTOPp->bigger__DOT__addr),8);
        vcdp->chgBus(c+321,((3U & ((IData)(vlTOPp->bigger__DOT__mem_out) 
                                   >> 2U))),2);
        vcdp->chgBus(c+329,((0xffU & ((IData)(vlTOPp->bigger__DOT__mem_out) 
                                      >> 4U))),8);
        vcdp->chgBus(c+337,((3U & (IData)(vlTOPp->bigger__DOT__mem_out))),2);
        vcdp->chgBus(c+345,(vlTOPp->bigger__DOT__instance3__DOT__instruction),16);
        vcdp->chgBus(c+353,(vlTOPp->bigger__DOT__instance3__DOT__regs),16);
        vcdp->chgBus(c+361,(vlTOPp->bigger__DOT__instance3__DOT__regc),16);
        vcdp->chgBus(c+369,(vlTOPp->bigger__DOT__instance3__DOT__cpu_inst__DOT__cur_state),2);
        vcdp->chgBus(c+377,((3U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__instruction))),2);
        vcdp->chgBus(c+385,(vlTOPp->bigger__DOT__instance3__DOT____Vcellout__gen_dff__BRA__0__KET____DOT__reg_out__mux_out),16);
        vcdp->chgBus(c+393,(vlTOPp->bigger__DOT__instance3__DOT____Vcellout__gen_dff__BRA__1__KET____DOT__reg_out__mux_out),16);
        vcdp->chgBus(c+401,(vlTOPp->bigger__DOT__instance3__DOT____Vcellout__gen_dff__BRA__2__KET____DOT__reg_out__mux_out),16);
        vcdp->chgBus(c+409,(vlTOPp->bigger__DOT__instance3__DOT____Vcellout__gen_dff__BRA__3__KET____DOT__reg_out__mux_out),16);
        vcdp->chgBus(c+417,(vlTOPp->bigger__DOT__instance3__DOT____Vcellout__gen_dff__BRA__4__KET____DOT__reg_out__mux_out),16);
        vcdp->chgBus(c+425,(vlTOPp->bigger__DOT__instance3__DOT____Vcellout__gen_dff__BRA__5__KET____DOT__reg_out__mux_out),16);
        vcdp->chgBus(c+433,(vlTOPp->bigger__DOT__instance3__DOT____Vcellout__gen_dff__BRA__6__KET____DOT__reg_out__mux_out),16);
        vcdp->chgBus(c+441,(vlTOPp->bigger__DOT__instance3__DOT____Vcellout__gen_dff__BRA__7__KET____DOT__reg_out__mux_out),16);
    }
}

void Vbigger::traceChgThis__4(Vbigger__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vbigger* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+449,(vlTOPp->clk));
        vcdp->chgBit(c+457,(vlTOPp->reset));
        vcdp->chgBit(c+465,(vlTOPp->run));
        vcdp->chgBit(c+473,(vlTOPp->done));
        vcdp->chgBus(c+481,(vlTOPp->instr),16);
        vcdp->chgBus(c+489,(vlTOPp->d_out),16);
    }
}
