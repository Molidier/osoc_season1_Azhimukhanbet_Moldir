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
        vcdp->declBit(c+465,"run", false,-1);
        vcdp->declBit(c+473,"clk", false,-1);
        vcdp->declBit(c+481,"reset", false,-1);
        vcdp->declBus(c+489,"d_instr", false,-1, 15,0);
        vcdp->declBit(c+497,"carry_in", false,-1);
        vcdp->declBus(c+505,"reg0", false,-1, 15,0);
        vcdp->declBus(c+513,"reg1", false,-1, 15,0);
        vcdp->declBus(c+521,"reg2", false,-1, 15,0);
        vcdp->declBus(c+529,"reg3", false,-1, 15,0);
        vcdp->declBus(c+537,"reg4", false,-1, 15,0);
        vcdp->declBus(c+545,"reg5", false,-1, 15,0);
        vcdp->declBus(c+553,"reg6", false,-1, 15,0);
        vcdp->declBus(c+561,"reg7", false,-1, 15,0);
        vcdp->declBus(c+569,"regs", false,-1, 15,0);
        vcdp->declBus(c+577,"regc", false,-1, 15,0);
        vcdp->declBus(c+585,"d_out", false,-1, 15,0);
        vcdp->declBit(c+593,"carry_out", false,-1);
        vcdp->declBit(c+465,"bitty run", false,-1);
        vcdp->declBit(c+473,"bitty clk", false,-1);
        vcdp->declBit(c+481,"bitty reset", false,-1);
        vcdp->declBus(c+489,"bitty d_instr", false,-1, 15,0);
        vcdp->declBit(c+497,"bitty carry_in", false,-1);
        vcdp->declBus(c+505,"bitty reg0", false,-1, 15,0);
        vcdp->declBus(c+513,"bitty reg1", false,-1, 15,0);
        vcdp->declBus(c+521,"bitty reg2", false,-1, 15,0);
        vcdp->declBus(c+529,"bitty reg3", false,-1, 15,0);
        vcdp->declBus(c+537,"bitty reg4", false,-1, 15,0);
        vcdp->declBus(c+545,"bitty reg5", false,-1, 15,0);
        vcdp->declBus(c+553,"bitty reg6", false,-1, 15,0);
        vcdp->declBus(c+561,"bitty reg7", false,-1, 15,0);
        vcdp->declBus(c+569,"bitty regs", false,-1, 15,0);
        vcdp->declBus(c+577,"bitty regc", false,-1, 15,0);
        vcdp->declBus(c+585,"bitty d_out", false,-1, 15,0);
        vcdp->declBit(c+593,"bitty carry_out", false,-1);
        vcdp->declBus(c+201,"bitty mux_sel", false,-1, 3,0);
        vcdp->declBus(c+209,"bitty en", false,-1, 7,0);
        {int i; for (i=0; i<8; i++) {
                vcdp->declBus(c+1+i*1,"bitty out", true,(i+0), 15,0);}}
        vcdp->declBus(c+217,"bitty out_mux", false,-1, 15,0);
        vcdp->declBus(c+225,"bitty alu_out", false,-1, 15,0);
        vcdp->declBit(c+233,"bitty en_s", false,-1);
        vcdp->declBit(c+241,"bitty en_c", false,-1);
        vcdp->declBit(c+249,"bitty en_inst", false,-1);
        vcdp->declBit(c+257,"bitty done", false,-1);
        vcdp->declBit(c+265,"bitty mode", false,-1);
        vcdp->declBus(c+273,"bitty alu_sel", false,-1, 3,0);
        vcdp->declBus(c+385,"bitty instruction", false,-1, 15,0);
        vcdp->declBit(c+473,"bitty reg_inst clk", false,-1);
        vcdp->declBit(c+249,"bitty reg_inst en", false,-1);
        vcdp->declBus(c+489,"bitty reg_inst d_in", false,-1, 15,0);
        vcdp->declBus(c+385,"bitty reg_inst mux_out", false,-1, 15,0);
        vcdp->declBit(c+473,"bitty reg_s clk", false,-1);
        vcdp->declBit(c+233,"bitty reg_s en", false,-1);
        vcdp->declBus(c+217,"bitty reg_s d_in", false,-1, 15,0);
        vcdp->declBus(c+569,"bitty reg_s mux_out", false,-1, 15,0);
        vcdp->declBit(c+473,"bitty reg_c clk", false,-1);
        vcdp->declBit(c+241,"bitty reg_c en", false,-1);
        vcdp->declBus(c+225,"bitty reg_c d_in", false,-1, 15,0);
        vcdp->declBus(c+577,"bitty reg_c mux_out", false,-1, 15,0);
        vcdp->declBit(c+473,"bitty cpu_inst clk", false,-1);
        vcdp->declBit(c+465,"bitty cpu_inst run", false,-1);
        vcdp->declBit(c+481,"bitty cpu_inst reset", false,-1);
        vcdp->declBus(c+385,"bitty cpu_inst d_inst", false,-1, 15,0);
        vcdp->declBus(c+201,"bitty cpu_inst mux_sel", false,-1, 3,0);
        vcdp->declBit(c+257,"bitty cpu_inst done", false,-1);
        vcdp->declBus(c+273,"bitty cpu_inst sel", false,-1, 3,0);
        vcdp->declBit(c+265,"bitty cpu_inst mode", false,-1);
        vcdp->declBit(c+233,"bitty cpu_inst en_s", false,-1);
        vcdp->declBit(c+241,"bitty cpu_inst en_c", false,-1);
        vcdp->declBus(c+209,"bitty cpu_inst en", false,-1, 7,0);
        vcdp->declBit(c+249,"bitty cpu_inst en_inst", false,-1);
        vcdp->declBus(c+457,"bitty cpu_inst cur_state", false,-1, 1,0);
        vcdp->declBus(c+193,"bitty cpu_inst next_state", false,-1, 1,0);
        vcdp->declBus(c+601,"bitty alu_inst WIDTH", false,-1, 31,0);
        vcdp->declBit(c+497,"bitty alu_inst carry_in", false,-1);
        vcdp->declBus(c+569,"bitty alu_inst a_in", false,-1, 15,0);
        vcdp->declBus(c+217,"bitty alu_inst b_in", false,-1, 15,0);
        vcdp->declBus(c+273,"bitty alu_inst select", false,-1, 3,0);
        vcdp->declBit(c+265,"bitty alu_inst mode", false,-1);
        vcdp->declBit(c+593,"bitty alu_inst carry_out", false,-1);
        vcdp->declBus(c+225,"bitty alu_inst alu_out", false,-1, 15,0);
        vcdp->declBus(c+225,"bitty alu_inst res", false,-1, 15,0);
        vcdp->declBus(c+281,"bitty alu_inst logic_res", false,-1, 15,0);
        vcdp->declBus(c+289,"bitty alu_inst arithmetic_res", false,-1, 15,0);
        vcdp->declBit(c+297,"bitty alu_inst car_out", false,-1);
        vcdp->declBit(c+305,"bitty alu_inst car_arith", false,-1);
        vcdp->declBus(c+601,"bitty alu_inst u1 WIDTH", false,-1, 31,0);
        vcdp->declBus(c+569,"bitty alu_inst u1 in_a", false,-1, 15,0);
        vcdp->declBus(c+217,"bitty alu_inst u1 in_b", false,-1, 15,0);
        vcdp->declBus(c+273,"bitty alu_inst u1 select", false,-1, 3,0);
        vcdp->declBus(c+281,"bitty alu_inst u1 logic_out", false,-1, 15,0);
        vcdp->declBus(c+281,"bitty alu_inst u1 res", false,-1, 15,0);
        vcdp->declBus(c+601,"bitty alu_inst u2 WIDTH", false,-1, 31,0);
        vcdp->declBit(c+497,"bitty alu_inst u2 carry_in", false,-1);
        vcdp->declBus(c+569,"bitty alu_inst u2 in_a", false,-1, 15,0);
        vcdp->declBus(c+217,"bitty alu_inst u2 in_b", false,-1, 15,0);
        vcdp->declBus(c+273,"bitty alu_inst u2 select", false,-1, 3,0);
        vcdp->declBit(c+305,"bitty alu_inst u2 carry_out", false,-1);
        vcdp->declBus(c+289,"bitty alu_inst u2 arithmetic_out", false,-1, 15,0);
        vcdp->declBus(c+313,"bitty alu_inst u2 extended_res", false,-1, 16,0);
        vcdp->declBus(c+65,"bitty mux_inst reg0", false,-1, 15,0);
        vcdp->declBus(c+73,"bitty mux_inst reg1", false,-1, 15,0);
        vcdp->declBus(c+81,"bitty mux_inst reg2", false,-1, 15,0);
        vcdp->declBus(c+89,"bitty mux_inst reg3", false,-1, 15,0);
        vcdp->declBus(c+97,"bitty mux_inst reg4", false,-1, 15,0);
        vcdp->declBus(c+105,"bitty mux_inst reg5", false,-1, 15,0);
        vcdp->declBus(c+113,"bitty mux_inst reg6", false,-1, 15,0);
        vcdp->declBus(c+121,"bitty mux_inst reg7", false,-1, 15,0);
        vcdp->declBus(c+201,"bitty mux_inst mux_sel", false,-1, 3,0);
        vcdp->declBus(c+217,"bitty mux_inst mux_out", false,-1, 15,0);
        vcdp->declBit(c+473,"bitty genblk1[0] reg_out clk", false,-1);
        vcdp->declBit(c+321,"bitty genblk1[0] reg_out en", false,-1);
        vcdp->declBus(c+129,"bitty genblk1[0] reg_out d_in", false,-1, 15,0);
        vcdp->declBus(c+393,"bitty genblk1[0] reg_out mux_out", false,-1, 15,0);
        vcdp->declBit(c+473,"bitty genblk1[1] reg_out clk", false,-1);
        vcdp->declBit(c+329,"bitty genblk1[1] reg_out en", false,-1);
        vcdp->declBus(c+137,"bitty genblk1[1] reg_out d_in", false,-1, 15,0);
        vcdp->declBus(c+401,"bitty genblk1[1] reg_out mux_out", false,-1, 15,0);
        vcdp->declBit(c+473,"bitty genblk1[2] reg_out clk", false,-1);
        vcdp->declBit(c+337,"bitty genblk1[2] reg_out en", false,-1);
        vcdp->declBus(c+145,"bitty genblk1[2] reg_out d_in", false,-1, 15,0);
        vcdp->declBus(c+409,"bitty genblk1[2] reg_out mux_out", false,-1, 15,0);
        vcdp->declBit(c+473,"bitty genblk1[3] reg_out clk", false,-1);
        vcdp->declBit(c+345,"bitty genblk1[3] reg_out en", false,-1);
        vcdp->declBus(c+153,"bitty genblk1[3] reg_out d_in", false,-1, 15,0);
        vcdp->declBus(c+417,"bitty genblk1[3] reg_out mux_out", false,-1, 15,0);
        vcdp->declBit(c+473,"bitty genblk1[4] reg_out clk", false,-1);
        vcdp->declBit(c+353,"bitty genblk1[4] reg_out en", false,-1);
        vcdp->declBus(c+161,"bitty genblk1[4] reg_out d_in", false,-1, 15,0);
        vcdp->declBus(c+425,"bitty genblk1[4] reg_out mux_out", false,-1, 15,0);
        vcdp->declBit(c+473,"bitty genblk1[5] reg_out clk", false,-1);
        vcdp->declBit(c+361,"bitty genblk1[5] reg_out en", false,-1);
        vcdp->declBus(c+169,"bitty genblk1[5] reg_out d_in", false,-1, 15,0);
        vcdp->declBus(c+433,"bitty genblk1[5] reg_out mux_out", false,-1, 15,0);
        vcdp->declBit(c+473,"bitty genblk1[6] reg_out clk", false,-1);
        vcdp->declBit(c+369,"bitty genblk1[6] reg_out en", false,-1);
        vcdp->declBus(c+177,"bitty genblk1[6] reg_out d_in", false,-1, 15,0);
        vcdp->declBus(c+441,"bitty genblk1[6] reg_out mux_out", false,-1, 15,0);
        vcdp->declBit(c+473,"bitty genblk1[7] reg_out clk", false,-1);
        vcdp->declBit(c+377,"bitty genblk1[7] reg_out en", false,-1);
        vcdp->declBus(c+185,"bitty genblk1[7] reg_out d_in", false,-1, 15,0);
        vcdp->declBus(c+449,"bitty genblk1[7] reg_out mux_out", false,-1, 15,0);
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
        vcdp->fullBus(c+129,(vlTOPp->bitty__DOT__out
                             [0U]),16);
        vcdp->fullBus(c+137,(vlTOPp->bitty__DOT__out
                             [1U]),16);
        vcdp->fullBus(c+145,(vlTOPp->bitty__DOT__out
                             [2U]),16);
        vcdp->fullBus(c+153,(vlTOPp->bitty__DOT__out
                             [3U]),16);
        vcdp->fullBus(c+161,(vlTOPp->bitty__DOT__out
                             [4U]),16);
        vcdp->fullBus(c+169,(vlTOPp->bitty__DOT__out
                             [5U]),16);
        vcdp->fullBus(c+177,(vlTOPp->bitty__DOT__out
                             [6U]),16);
        vcdp->fullBus(c+185,(vlTOPp->bitty__DOT__out
                             [7U]),16);
        vcdp->fullBus(c+193,(((0U == (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))
                               ? 1U : ((1U == (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))
                                        ? 3U : ((3U 
                                                 == (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))
                                                 ? 
                                                ((IData)(vlTOPp->bitty__DOT__done)
                                                  ? 0U
                                                  : 3U)
                                                 : 0U)))),2);
        vcdp->fullBus(c+201,(vlTOPp->bitty__DOT__mux_sel),4);
        vcdp->fullBus(c+209,(vlTOPp->bitty__DOT__en),8);
        vcdp->fullBus(c+217,(vlTOPp->bitty__DOT__out_mux),16);
        vcdp->fullBus(c+225,(vlTOPp->bitty__DOT__alu_inst__DOT__res),16);
        vcdp->fullBit(c+233,(vlTOPp->bitty__DOT__en_s));
        vcdp->fullBit(c+241,(vlTOPp->bitty__DOT__en_c));
        vcdp->fullBit(c+249,(vlTOPp->bitty__DOT__en_inst));
        vcdp->fullBit(c+257,(vlTOPp->bitty__DOT__done));
        vcdp->fullBit(c+265,(vlTOPp->bitty__DOT__mode));
        vcdp->fullBus(c+273,(vlTOPp->bitty__DOT__alu_sel),4);
        vcdp->fullBus(c+281,(vlTOPp->bitty__DOT__alu_inst__DOT__u1__DOT__res),16);
        vcdp->fullBus(c+289,((0xffffU & vlTOPp->bitty__DOT__alu_inst__DOT__u2__DOT__extended_res)),16);
        vcdp->fullBit(c+297,(vlTOPp->bitty__DOT__alu_inst__DOT__car_out));
        vcdp->fullBit(c+305,(vlTOPp->bitty__DOT__alu_inst__DOT__car_arith));
        vcdp->fullBus(c+313,(vlTOPp->bitty__DOT__alu_inst__DOT__u2__DOT__extended_res),17);
        vcdp->fullBit(c+321,((1U & (IData)(vlTOPp->bitty__DOT__en))));
        vcdp->fullBit(c+329,((1U & ((IData)(vlTOPp->bitty__DOT__en) 
                                    >> 1U))));
        vcdp->fullBit(c+337,((1U & ((IData)(vlTOPp->bitty__DOT__en) 
                                    >> 2U))));
        vcdp->fullBit(c+345,((1U & ((IData)(vlTOPp->bitty__DOT__en) 
                                    >> 3U))));
        vcdp->fullBit(c+353,((1U & ((IData)(vlTOPp->bitty__DOT__en) 
                                    >> 4U))));
        vcdp->fullBit(c+361,((1U & ((IData)(vlTOPp->bitty__DOT__en) 
                                    >> 5U))));
        vcdp->fullBit(c+369,((1U & ((IData)(vlTOPp->bitty__DOT__en) 
                                    >> 6U))));
        vcdp->fullBit(c+377,((1U & ((IData)(vlTOPp->bitty__DOT__en) 
                                    >> 7U))));
        vcdp->fullBus(c+385,(vlTOPp->bitty__DOT__instruction),16);
        vcdp->fullBus(c+393,(vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__0__KET____DOT__reg_out__mux_out),16);
        vcdp->fullBus(c+401,(vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__1__KET____DOT__reg_out__mux_out),16);
        vcdp->fullBus(c+409,(vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__2__KET____DOT__reg_out__mux_out),16);
        vcdp->fullBus(c+417,(vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__3__KET____DOT__reg_out__mux_out),16);
        vcdp->fullBus(c+425,(vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__4__KET____DOT__reg_out__mux_out),16);
        vcdp->fullBus(c+433,(vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__5__KET____DOT__reg_out__mux_out),16);
        vcdp->fullBus(c+441,(vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__6__KET____DOT__reg_out__mux_out),16);
        vcdp->fullBus(c+449,(vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__7__KET____DOT__reg_out__mux_out),16);
        vcdp->fullBus(c+457,(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state),2);
        vcdp->fullBit(c+465,(vlTOPp->run));
        vcdp->fullBit(c+473,(vlTOPp->clk));
        vcdp->fullBit(c+481,(vlTOPp->reset));
        vcdp->fullBus(c+489,(vlTOPp->d_instr),16);
        vcdp->fullBit(c+497,(vlTOPp->carry_in));
        vcdp->fullBus(c+505,(vlTOPp->reg0),16);
        vcdp->fullBus(c+513,(vlTOPp->reg1),16);
        vcdp->fullBus(c+521,(vlTOPp->reg2),16);
        vcdp->fullBus(c+529,(vlTOPp->reg3),16);
        vcdp->fullBus(c+537,(vlTOPp->reg4),16);
        vcdp->fullBus(c+545,(vlTOPp->reg5),16);
        vcdp->fullBus(c+553,(vlTOPp->reg6),16);
        vcdp->fullBus(c+561,(vlTOPp->reg7),16);
        vcdp->fullBus(c+569,(vlTOPp->regs),16);
        vcdp->fullBus(c+577,(vlTOPp->regc),16);
        vcdp->fullBus(c+585,(vlTOPp->d_out),16);
        vcdp->fullBit(c+593,(vlTOPp->carry_out));
        vcdp->fullBus(c+601,(0x10U),32);
    }
}
