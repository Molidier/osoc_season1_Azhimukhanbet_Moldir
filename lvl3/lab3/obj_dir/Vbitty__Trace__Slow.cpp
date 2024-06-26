// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vbitty__Syms.h"


//======================

void Vbitty::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&Vbitty::traceInit, &Vbitty::traceFull, &Vbitty::traceChg, this);
}
void Vbitty::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    Vbitty* t = (Vbitty*)userthis;
    Vbitty__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void Vbitty::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vbitty* t = (Vbitty*)userthis;
    Vbitty__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void Vbitty::traceInitThis(Vbitty__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vbitty* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
        vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void Vbitty::traceFullThis(Vbitty__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vbitty* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vbitty::traceInitThis__1(Vbitty__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vbitty* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->declBit(c+393,"run", false,-1);
        vcdp->declBit(c+401,"clk", false,-1);
        vcdp->declBit(c+409,"reset", false,-1);
        vcdp->declBus(c+417,"d_instr", false,-1, 15,0);
        vcdp->declBit(c+425,"carry_in", false,-1);
        vcdp->declBus(c+433,"reg0", false,-1, 15,0);
        vcdp->declBus(c+441,"reg1", false,-1, 15,0);
        vcdp->declBus(c+449,"reg2", false,-1, 15,0);
        vcdp->declBus(c+457,"reg3", false,-1, 15,0);
        vcdp->declBus(c+465,"reg4", false,-1, 15,0);
        vcdp->declBus(c+473,"reg5", false,-1, 15,0);
        vcdp->declBus(c+481,"reg6", false,-1, 15,0);
        vcdp->declBus(c+489,"reg7", false,-1, 15,0);
        vcdp->declBus(c+497,"regs", false,-1, 15,0);
        vcdp->declBus(c+505,"regc", false,-1, 15,0);
        vcdp->declBus(c+513,"d_out", false,-1, 15,0);
        vcdp->declBit(c+521,"carry_out", false,-1);
        vcdp->declBit(c+529,"done", false,-1);
        vcdp->declBit(c+393,"bitty run", false,-1);
        vcdp->declBit(c+401,"bitty clk", false,-1);
        vcdp->declBit(c+409,"bitty reset", false,-1);
        vcdp->declBus(c+417,"bitty d_instr", false,-1, 15,0);
        vcdp->declBit(c+425,"bitty carry_in", false,-1);
        vcdp->declBus(c+433,"bitty reg0", false,-1, 15,0);
        vcdp->declBus(c+441,"bitty reg1", false,-1, 15,0);
        vcdp->declBus(c+449,"bitty reg2", false,-1, 15,0);
        vcdp->declBus(c+457,"bitty reg3", false,-1, 15,0);
        vcdp->declBus(c+465,"bitty reg4", false,-1, 15,0);
        vcdp->declBus(c+473,"bitty reg5", false,-1, 15,0);
        vcdp->declBus(c+481,"bitty reg6", false,-1, 15,0);
        vcdp->declBus(c+489,"bitty reg7", false,-1, 15,0);
        vcdp->declBus(c+497,"bitty regs", false,-1, 15,0);
        vcdp->declBus(c+505,"bitty regc", false,-1, 15,0);
        vcdp->declBus(c+513,"bitty d_out", false,-1, 15,0);
        vcdp->declBit(c+521,"bitty carry_out", false,-1);
        vcdp->declBit(c+529,"bitty done", false,-1);
        vcdp->declBus(c+129,"bitty mux_sel", false,-1, 3,0);
        vcdp->declBus(c+137,"bitty en", false,-1, 7,0);
        {int i; for (i=0; i<8; i++) {
                vcdp->declBus(c+1+i*1,"bitty out", true,(i+0), 15,0);}}
        vcdp->declBus(c+241,"bitty out_mux", false,-1, 15,0);
        vcdp->declBus(c+249,"bitty alu_out", false,-1, 15,0);
        vcdp->declBit(c+145,"bitty en_s", false,-1);
        vcdp->declBit(c+153,"bitty en_c", false,-1);
        vcdp->declBit(c+257,"bitty en_inst", false,-1);
        vcdp->declBit(c+161,"bitty mode", false,-1);
        vcdp->declBus(c+169,"bitty alu_sel", false,-1, 3,0);
        vcdp->declBus(c+313,"bitty instruction", false,-1, 15,0);
        vcdp->declBit(c+401,"bitty reg_inst clk", false,-1);
        vcdp->declBit(c+257,"bitty reg_inst en", false,-1);
        vcdp->declBus(c+417,"bitty reg_inst d_in", false,-1, 15,0);
        vcdp->declBus(c+313,"bitty reg_inst mux_out", false,-1, 15,0);
        vcdp->declBit(c+401,"bitty reg_s clk", false,-1);
        vcdp->declBit(c+145,"bitty reg_s en", false,-1);
        vcdp->declBus(c+241,"bitty reg_s d_in", false,-1, 15,0);
        vcdp->declBus(c+497,"bitty reg_s mux_out", false,-1, 15,0);
        vcdp->declBit(c+401,"bitty reg_c clk", false,-1);
        vcdp->declBit(c+153,"bitty reg_c en", false,-1);
        vcdp->declBus(c+249,"bitty reg_c d_in", false,-1, 15,0);
        vcdp->declBus(c+505,"bitty reg_c mux_out", false,-1, 15,0);
        vcdp->declBit(c+401,"bitty cpu_inst clk", false,-1);
        vcdp->declBit(c+393,"bitty cpu_inst run", false,-1);
        vcdp->declBit(c+409,"bitty cpu_inst reset", false,-1);
        vcdp->declBus(c+313,"bitty cpu_inst d_inst", false,-1, 15,0);
        vcdp->declBus(c+129,"bitty cpu_inst mux_sel", false,-1, 3,0);
        vcdp->declBit(c+529,"bitty cpu_inst done", false,-1);
        vcdp->declBus(c+169,"bitty cpu_inst sel", false,-1, 3,0);
        vcdp->declBit(c+161,"bitty cpu_inst mode", false,-1);
        vcdp->declBit(c+145,"bitty cpu_inst en_s", false,-1);
        vcdp->declBit(c+153,"bitty cpu_inst en_c", false,-1);
        vcdp->declBus(c+137,"bitty cpu_inst en", false,-1, 7,0);
        vcdp->declBit(c+257,"bitty cpu_inst en_inst", false,-1);
        vcdp->declBus(c+385,"bitty cpu_inst cur_state", false,-1, 1,0);
        vcdp->declBus(c+265,"bitty cpu_inst next_state", false,-1, 1,0);
        vcdp->declBus(c+537,"bitty alu_inst WIDTH", false,-1, 31,0);
        vcdp->declBit(c+425,"bitty alu_inst carry_in", false,-1);
        vcdp->declBus(c+497,"bitty alu_inst a_in", false,-1, 15,0);
        vcdp->declBus(c+241,"bitty alu_inst b_in", false,-1, 15,0);
        vcdp->declBus(c+169,"bitty alu_inst select", false,-1, 3,0);
        vcdp->declBit(c+161,"bitty alu_inst mode", false,-1);
        vcdp->declBit(c+521,"bitty alu_inst carry_out", false,-1);
        vcdp->declBus(c+249,"bitty alu_inst alu_out", false,-1, 15,0);
        vcdp->declBus(c+249,"bitty alu_inst res", false,-1, 15,0);
        vcdp->declBus(c+273,"bitty alu_inst logic_res", false,-1, 15,0);
        vcdp->declBus(c+281,"bitty alu_inst arithmetic_res", false,-1, 15,0);
        vcdp->declBit(c+289,"bitty alu_inst car_out", false,-1);
        vcdp->declBit(c+297,"bitty alu_inst car_arith", false,-1);
        vcdp->declBus(c+537,"bitty alu_inst u1 WIDTH", false,-1, 31,0);
        vcdp->declBus(c+497,"bitty alu_inst u1 in_a", false,-1, 15,0);
        vcdp->declBus(c+241,"bitty alu_inst u1 in_b", false,-1, 15,0);
        vcdp->declBus(c+169,"bitty alu_inst u1 select", false,-1, 3,0);
        vcdp->declBus(c+273,"bitty alu_inst u1 logic_out", false,-1, 15,0);
        vcdp->declBus(c+273,"bitty alu_inst u1 res", false,-1, 15,0);
        vcdp->declBus(c+537,"bitty alu_inst u2 WIDTH", false,-1, 31,0);
        vcdp->declBit(c+425,"bitty alu_inst u2 carry_in", false,-1);
        vcdp->declBus(c+497,"bitty alu_inst u2 in_a", false,-1, 15,0);
        vcdp->declBus(c+241,"bitty alu_inst u2 in_b", false,-1, 15,0);
        vcdp->declBus(c+169,"bitty alu_inst u2 select", false,-1, 3,0);
        vcdp->declBit(c+297,"bitty alu_inst u2 carry_out", false,-1);
        vcdp->declBus(c+281,"bitty alu_inst u2 arithmetic_out", false,-1, 15,0);
        vcdp->declBus(c+305,"bitty alu_inst u2 extended_res", false,-1, 16,0);
        vcdp->declBus(c+65,"bitty mux_inst reg0", false,-1, 15,0);
        vcdp->declBus(c+73,"bitty mux_inst reg1", false,-1, 15,0);
        vcdp->declBus(c+81,"bitty mux_inst reg2", false,-1, 15,0);
        vcdp->declBus(c+89,"bitty mux_inst reg3", false,-1, 15,0);
        vcdp->declBus(c+97,"bitty mux_inst reg4", false,-1, 15,0);
        vcdp->declBus(c+105,"bitty mux_inst reg5", false,-1, 15,0);
        vcdp->declBus(c+113,"bitty mux_inst reg6", false,-1, 15,0);
        vcdp->declBus(c+121,"bitty mux_inst reg7", false,-1, 15,0);
        vcdp->declBus(c+129,"bitty mux_inst mux_sel", false,-1, 3,0);
        vcdp->declBus(c+241,"bitty mux_inst mux_out", false,-1, 15,0);
        vcdp->declBit(c+401,"bitty genblk1[0] reg_out clk", false,-1);
        vcdp->declBit(c+177,"bitty genblk1[0] reg_out en", false,-1);
        vcdp->declBus(c+505,"bitty genblk1[0] reg_out d_in", false,-1, 15,0);
        vcdp->declBus(c+321,"bitty genblk1[0] reg_out mux_out", false,-1, 15,0);
        vcdp->declBit(c+401,"bitty genblk1[1] reg_out clk", false,-1);
        vcdp->declBit(c+185,"bitty genblk1[1] reg_out en", false,-1);
        vcdp->declBus(c+505,"bitty genblk1[1] reg_out d_in", false,-1, 15,0);
        vcdp->declBus(c+329,"bitty genblk1[1] reg_out mux_out", false,-1, 15,0);
        vcdp->declBit(c+401,"bitty genblk1[2] reg_out clk", false,-1);
        vcdp->declBit(c+193,"bitty genblk1[2] reg_out en", false,-1);
        vcdp->declBus(c+505,"bitty genblk1[2] reg_out d_in", false,-1, 15,0);
        vcdp->declBus(c+337,"bitty genblk1[2] reg_out mux_out", false,-1, 15,0);
        vcdp->declBit(c+401,"bitty genblk1[3] reg_out clk", false,-1);
        vcdp->declBit(c+201,"bitty genblk1[3] reg_out en", false,-1);
        vcdp->declBus(c+505,"bitty genblk1[3] reg_out d_in", false,-1, 15,0);
        vcdp->declBus(c+345,"bitty genblk1[3] reg_out mux_out", false,-1, 15,0);
        vcdp->declBit(c+401,"bitty genblk1[4] reg_out clk", false,-1);
        vcdp->declBit(c+209,"bitty genblk1[4] reg_out en", false,-1);
        vcdp->declBus(c+505,"bitty genblk1[4] reg_out d_in", false,-1, 15,0);
        vcdp->declBus(c+353,"bitty genblk1[4] reg_out mux_out", false,-1, 15,0);
        vcdp->declBit(c+401,"bitty genblk1[5] reg_out clk", false,-1);
        vcdp->declBit(c+217,"bitty genblk1[5] reg_out en", false,-1);
        vcdp->declBus(c+505,"bitty genblk1[5] reg_out d_in", false,-1, 15,0);
        vcdp->declBus(c+361,"bitty genblk1[5] reg_out mux_out", false,-1, 15,0);
        vcdp->declBit(c+401,"bitty genblk1[6] reg_out clk", false,-1);
        vcdp->declBit(c+225,"bitty genblk1[6] reg_out en", false,-1);
        vcdp->declBus(c+505,"bitty genblk1[6] reg_out d_in", false,-1, 15,0);
        vcdp->declBus(c+369,"bitty genblk1[6] reg_out mux_out", false,-1, 15,0);
        vcdp->declBit(c+401,"bitty genblk1[7] reg_out clk", false,-1);
        vcdp->declBit(c+233,"bitty genblk1[7] reg_out en", false,-1);
        vcdp->declBus(c+505,"bitty genblk1[7] reg_out d_in", false,-1, 15,0);
        vcdp->declBus(c+377,"bitty genblk1[7] reg_out mux_out", false,-1, 15,0);
    }
}

void Vbitty::traceFullThis__1(Vbitty__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vbitty* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->fullBus(c+1,(vlTOPp->bitty__DOT__out[0]),16);
        vcdp->fullBus(c+2,(vlTOPp->bitty__DOT__out[1]),16);
        vcdp->fullBus(c+3,(vlTOPp->bitty__DOT__out[2]),16);
        vcdp->fullBus(c+4,(vlTOPp->bitty__DOT__out[3]),16);
        vcdp->fullBus(c+5,(vlTOPp->bitty__DOT__out[4]),16);
        vcdp->fullBus(c+6,(vlTOPp->bitty__DOT__out[5]),16);
        vcdp->fullBus(c+7,(vlTOPp->bitty__DOT__out[6]),16);
        vcdp->fullBus(c+8,(vlTOPp->bitty__DOT__out[7]),16);
        vcdp->fullBus(c+65,(vlTOPp->bitty__DOT__out
                            [0U]),16);
        vcdp->fullBus(c+73,(vlTOPp->bitty__DOT__out
                            [1U]),16);
        vcdp->fullBus(c+81,(vlTOPp->bitty__DOT__out
                            [2U]),16);
        vcdp->fullBus(c+89,(vlTOPp->bitty__DOT__out
                            [3U]),16);
        vcdp->fullBus(c+97,(vlTOPp->bitty__DOT__out
                            [4U]),16);
        vcdp->fullBus(c+105,(vlTOPp->bitty__DOT__out
                             [5U]),16);
        vcdp->fullBus(c+113,(vlTOPp->bitty__DOT__out
                             [6U]),16);
        vcdp->fullBus(c+121,(vlTOPp->bitty__DOT__out
                             [7U]),16);
        vcdp->fullBus(c+129,(vlTOPp->bitty__DOT__mux_sel),4);
        vcdp->fullBus(c+137,(vlTOPp->bitty__DOT__en),8);
        vcdp->fullBit(c+145,(vlTOPp->bitty__DOT__en_s));
        vcdp->fullBit(c+153,(vlTOPp->bitty__DOT__en_c));
        vcdp->fullBit(c+161,(vlTOPp->bitty__DOT__mode));
        vcdp->fullBus(c+169,(vlTOPp->bitty__DOT__alu_sel),4);
        vcdp->fullBit(c+177,((1U & (IData)(vlTOPp->bitty__DOT__en))));
        vcdp->fullBit(c+185,((1U & ((IData)(vlTOPp->bitty__DOT__en) 
                                    >> 1U))));
        vcdp->fullBit(c+193,((1U & ((IData)(vlTOPp->bitty__DOT__en) 
                                    >> 2U))));
        vcdp->fullBit(c+201,((1U & ((IData)(vlTOPp->bitty__DOT__en) 
                                    >> 3U))));
        vcdp->fullBit(c+209,((1U & ((IData)(vlTOPp->bitty__DOT__en) 
                                    >> 4U))));
        vcdp->fullBit(c+217,((1U & ((IData)(vlTOPp->bitty__DOT__en) 
                                    >> 5U))));
        vcdp->fullBit(c+225,((1U & ((IData)(vlTOPp->bitty__DOT__en) 
                                    >> 6U))));
        vcdp->fullBit(c+233,((1U & ((IData)(vlTOPp->bitty__DOT__en) 
                                    >> 7U))));
        vcdp->fullBus(c+241,(vlTOPp->bitty__DOT__out_mux),16);
        vcdp->fullBus(c+249,(vlTOPp->bitty__DOT__alu_inst__DOT__res),16);
        vcdp->fullBit(c+257,(vlTOPp->bitty__DOT__en_inst));
        vcdp->fullBus(c+265,(vlTOPp->bitty__DOT__cpu_inst__DOT__next_state),2);
        vcdp->fullBus(c+273,(vlTOPp->bitty__DOT__alu_inst__DOT__u1__DOT__res),16);
        vcdp->fullBus(c+281,((0xffffU & vlTOPp->bitty__DOT__alu_inst__DOT__u2__DOT__extended_res)),16);
        vcdp->fullBit(c+289,(vlTOPp->bitty__DOT__alu_inst__DOT__car_out));
        vcdp->fullBit(c+297,(vlTOPp->bitty__DOT__alu_inst__DOT__car_arith));
        vcdp->fullBus(c+305,(vlTOPp->bitty__DOT__alu_inst__DOT__u2__DOT__extended_res),17);
        vcdp->fullBus(c+313,(vlTOPp->bitty__DOT__instruction),16);
        vcdp->fullBus(c+321,(vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__0__KET____DOT__reg_out__mux_out),16);
        vcdp->fullBus(c+329,(vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__1__KET____DOT__reg_out__mux_out),16);
        vcdp->fullBus(c+337,(vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__2__KET____DOT__reg_out__mux_out),16);
        vcdp->fullBus(c+345,(vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__3__KET____DOT__reg_out__mux_out),16);
        vcdp->fullBus(c+353,(vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__4__KET____DOT__reg_out__mux_out),16);
        vcdp->fullBus(c+361,(vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__5__KET____DOT__reg_out__mux_out),16);
        vcdp->fullBus(c+369,(vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__6__KET____DOT__reg_out__mux_out),16);
        vcdp->fullBus(c+377,(vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__7__KET____DOT__reg_out__mux_out),16);
        vcdp->fullBus(c+385,(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state),2);
        vcdp->fullBit(c+393,(vlTOPp->run));
        vcdp->fullBit(c+401,(vlTOPp->clk));
        vcdp->fullBit(c+409,(vlTOPp->reset));
        vcdp->fullBus(c+417,(vlTOPp->d_instr),16);
        vcdp->fullBit(c+425,(vlTOPp->carry_in));
        vcdp->fullBus(c+433,(vlTOPp->reg0),16);
        vcdp->fullBus(c+441,(vlTOPp->reg1),16);
        vcdp->fullBus(c+449,(vlTOPp->reg2),16);
        vcdp->fullBus(c+457,(vlTOPp->reg3),16);
        vcdp->fullBus(c+465,(vlTOPp->reg4),16);
        vcdp->fullBus(c+473,(vlTOPp->reg5),16);
        vcdp->fullBus(c+481,(vlTOPp->reg6),16);
        vcdp->fullBus(c+489,(vlTOPp->reg7),16);
        vcdp->fullBus(c+497,(vlTOPp->regs),16);
        vcdp->fullBus(c+505,(vlTOPp->regc),16);
        vcdp->fullBus(c+513,(vlTOPp->d_out),16);
        vcdp->fullBit(c+521,(vlTOPp->carry_out));
        vcdp->fullBit(c+529,(vlTOPp->done));
        vcdp->fullBus(c+537,(0x10U),32);
    }
}
