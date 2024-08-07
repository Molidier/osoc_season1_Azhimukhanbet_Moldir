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
        vcdp->declBit(c+361,"run", false,-1);
        vcdp->declBit(c+369,"clk", false,-1);
        vcdp->declBit(c+377,"reset", false,-1);
        vcdp->declBus(c+385,"d_instr", false,-1, 15,0);
        vcdp->declBus(c+393,"d_out", false,-1, 15,0);
        vcdp->declBus(c+401,"rega", false,-1, 15,0);
        vcdp->declBus(c+409,"regb", false,-1, 15,0);
        vcdp->declBus(c+417,"regcc", false,-1, 15,0);
        vcdp->declBus(c+425,"regss", false,-1, 15,0);
        vcdp->declBus(c+433,"reg0", false,-1, 15,0);
        vcdp->declBus(c+441,"reg1", false,-1, 15,0);
        vcdp->declBus(c+449,"reg2", false,-1, 15,0);
        vcdp->declBus(c+457,"reg3", false,-1, 15,0);
        vcdp->declBus(c+465,"reg4", false,-1, 15,0);
        vcdp->declBus(c+473,"reg5", false,-1, 15,0);
        vcdp->declBus(c+481,"reg6", false,-1, 15,0);
        vcdp->declBus(c+489,"reg7", false,-1, 15,0);
        vcdp->declBus(c+497,"reginst", false,-1, 15,0);
        vcdp->declBit(c+505,"done", false,-1);
        vcdp->declBit(c+361,"bitty run", false,-1);
        vcdp->declBit(c+369,"bitty clk", false,-1);
        vcdp->declBit(c+377,"bitty reset", false,-1);
        vcdp->declBus(c+385,"bitty d_instr", false,-1, 15,0);
        vcdp->declBus(c+393,"bitty d_out", false,-1, 15,0);
        vcdp->declBus(c+401,"bitty rega", false,-1, 15,0);
        vcdp->declBus(c+409,"bitty regb", false,-1, 15,0);
        vcdp->declBus(c+417,"bitty regcc", false,-1, 15,0);
        vcdp->declBus(c+425,"bitty regss", false,-1, 15,0);
        vcdp->declBus(c+433,"bitty reg0", false,-1, 15,0);
        vcdp->declBus(c+441,"bitty reg1", false,-1, 15,0);
        vcdp->declBus(c+449,"bitty reg2", false,-1, 15,0);
        vcdp->declBus(c+457,"bitty reg3", false,-1, 15,0);
        vcdp->declBus(c+465,"bitty reg4", false,-1, 15,0);
        vcdp->declBus(c+473,"bitty reg5", false,-1, 15,0);
        vcdp->declBus(c+481,"bitty reg6", false,-1, 15,0);
        vcdp->declBus(c+489,"bitty reg7", false,-1, 15,0);
        vcdp->declBus(c+497,"bitty reginst", false,-1, 15,0);
        vcdp->declBit(c+505,"bitty done", false,-1);
        vcdp->declBus(c+137,"bitty mux_sel", false,-1, 2,0);
        vcdp->declBus(c+145,"bitty en", false,-1, 7,0);
        {int i; for (i=0; i<8; i++) {
                vcdp->declBus(c+1+i*1,"bitty out", true,(i+0), 15,0);}}
        vcdp->declBus(c+153,"bitty out_mux", false,-1, 15,0);
        vcdp->declBus(c+129,"bitty alu_out", false,-1, 15,0);
        vcdp->declBit(c+161,"bitty en_s", false,-1);
        vcdp->declBit(c+169,"bitty en_c", false,-1);
        vcdp->declBit(c+177,"bitty en_inst", false,-1);
        vcdp->declBus(c+185,"bitty alu_sel", false,-1, 2,0);
        vcdp->declBus(c+265,"bitty instruction", false,-1, 15,0);
        vcdp->declBus(c+273,"bitty regs", false,-1, 15,0);
        vcdp->declBus(c+281,"bitty regc", false,-1, 15,0);
        vcdp->declBit(c+369,"bitty reg_inst clk", false,-1);
        vcdp->declBit(c+177,"bitty reg_inst en", false,-1);
        vcdp->declBus(c+385,"bitty reg_inst d_in", false,-1, 15,0);
        vcdp->declBus(c+513,"bitty reg_inst starting", false,-1, 15,0);
        vcdp->declBit(c+377,"bitty reg_inst reset", false,-1);
        vcdp->declBus(c+265,"bitty reg_inst mux_out", false,-1, 15,0);
        vcdp->declBit(c+369,"bitty reg_s clk", false,-1);
        vcdp->declBit(c+161,"bitty reg_s en", false,-1);
        vcdp->declBus(c+153,"bitty reg_s d_in", false,-1, 15,0);
        vcdp->declBus(c+513,"bitty reg_s starting", false,-1, 15,0);
        vcdp->declBit(c+377,"bitty reg_s reset", false,-1);
        vcdp->declBus(c+273,"bitty reg_s mux_out", false,-1, 15,0);
        vcdp->declBit(c+369,"bitty reg_c clk", false,-1);
        vcdp->declBit(c+169,"bitty reg_c en", false,-1);
        vcdp->declBus(c+129,"bitty reg_c d_in", false,-1, 15,0);
        vcdp->declBus(c+513,"bitty reg_c starting", false,-1, 15,0);
        vcdp->declBit(c+377,"bitty reg_c reset", false,-1);
        vcdp->declBus(c+281,"bitty reg_c mux_out", false,-1, 15,0);
        vcdp->declBit(c+369,"bitty cpu_inst clk", false,-1);
        vcdp->declBit(c+361,"bitty cpu_inst run", false,-1);
        vcdp->declBit(c+377,"bitty cpu_inst reset", false,-1);
        vcdp->declBus(c+265,"bitty cpu_inst d_inst", false,-1, 15,0);
        vcdp->declBus(c+137,"bitty cpu_inst mux_sel", false,-1, 2,0);
        vcdp->declBit(c+505,"bitty cpu_inst done", false,-1);
        vcdp->declBus(c+185,"bitty cpu_inst sel", false,-1, 2,0);
        vcdp->declBit(c+161,"bitty cpu_inst en_s", false,-1);
        vcdp->declBit(c+169,"bitty cpu_inst en_c", false,-1);
        vcdp->declBus(c+145,"bitty cpu_inst en", false,-1, 7,0);
        vcdp->declBit(c+177,"bitty cpu_inst en_inst", false,-1);
        vcdp->declBus(c+289,"bitty cpu_inst cur_state", false,-1, 1,0);
        vcdp->declBus(c+193,"bitty cpu_inst next_state", false,-1, 1,0);
        vcdp->declBus(c+185,"bitty alu_inst select", false,-1, 2,0);
        vcdp->declBus(c+273,"bitty alu_inst in_a", false,-1, 15,0);
        vcdp->declBus(c+153,"bitty alu_inst in_b", false,-1, 15,0);
        vcdp->declBus(c+129,"bitty alu_inst alu_out", false,-1, 15,0);
        vcdp->declBus(c+129,"bitty alu_inst res", false,-1, 15,0);
        vcdp->declBus(c+65,"bitty mux_inst reg0", false,-1, 15,0);
        vcdp->declBus(c+73,"bitty mux_inst reg1", false,-1, 15,0);
        vcdp->declBus(c+81,"bitty mux_inst reg2", false,-1, 15,0);
        vcdp->declBus(c+89,"bitty mux_inst reg3", false,-1, 15,0);
        vcdp->declBus(c+97,"bitty mux_inst reg4", false,-1, 15,0);
        vcdp->declBus(c+105,"bitty mux_inst reg5", false,-1, 15,0);
        vcdp->declBus(c+113,"bitty mux_inst reg6", false,-1, 15,0);
        vcdp->declBus(c+121,"bitty mux_inst reg7", false,-1, 15,0);
        vcdp->declBus(c+137,"bitty mux_inst mux_sel", false,-1, 2,0);
        vcdp->declBus(c+153,"bitty mux_inst mux_out", false,-1, 15,0);
        vcdp->declBit(c+369,"bitty genblk1[0] reg_out clk", false,-1);
        vcdp->declBit(c+201,"bitty genblk1[0] reg_out en", false,-1);
        vcdp->declBus(c+281,"bitty genblk1[0] reg_out d_in", false,-1, 15,0);
        vcdp->declBus(c+521,"bitty genblk1[0] reg_out starting", false,-1, 15,0);
        vcdp->declBit(c+377,"bitty genblk1[0] reg_out reset", false,-1);
        vcdp->declBus(c+297,"bitty genblk1[0] reg_out mux_out", false,-1, 15,0);
        vcdp->declBit(c+369,"bitty genblk1[1] reg_out clk", false,-1);
        vcdp->declBit(c+209,"bitty genblk1[1] reg_out en", false,-1);
        vcdp->declBus(c+281,"bitty genblk1[1] reg_out d_in", false,-1, 15,0);
        vcdp->declBus(c+521,"bitty genblk1[1] reg_out starting", false,-1, 15,0);
        vcdp->declBit(c+377,"bitty genblk1[1] reg_out reset", false,-1);
        vcdp->declBus(c+305,"bitty genblk1[1] reg_out mux_out", false,-1, 15,0);
        vcdp->declBit(c+369,"bitty genblk1[2] reg_out clk", false,-1);
        vcdp->declBit(c+217,"bitty genblk1[2] reg_out en", false,-1);
        vcdp->declBus(c+281,"bitty genblk1[2] reg_out d_in", false,-1, 15,0);
        vcdp->declBus(c+521,"bitty genblk1[2] reg_out starting", false,-1, 15,0);
        vcdp->declBit(c+377,"bitty genblk1[2] reg_out reset", false,-1);
        vcdp->declBus(c+313,"bitty genblk1[2] reg_out mux_out", false,-1, 15,0);
        vcdp->declBit(c+369,"bitty genblk1[3] reg_out clk", false,-1);
        vcdp->declBit(c+225,"bitty genblk1[3] reg_out en", false,-1);
        vcdp->declBus(c+281,"bitty genblk1[3] reg_out d_in", false,-1, 15,0);
        vcdp->declBus(c+521,"bitty genblk1[3] reg_out starting", false,-1, 15,0);
        vcdp->declBit(c+377,"bitty genblk1[3] reg_out reset", false,-1);
        vcdp->declBus(c+321,"bitty genblk1[3] reg_out mux_out", false,-1, 15,0);
        vcdp->declBit(c+369,"bitty genblk1[4] reg_out clk", false,-1);
        vcdp->declBit(c+233,"bitty genblk1[4] reg_out en", false,-1);
        vcdp->declBus(c+281,"bitty genblk1[4] reg_out d_in", false,-1, 15,0);
        vcdp->declBus(c+521,"bitty genblk1[4] reg_out starting", false,-1, 15,0);
        vcdp->declBit(c+377,"bitty genblk1[4] reg_out reset", false,-1);
        vcdp->declBus(c+329,"bitty genblk1[4] reg_out mux_out", false,-1, 15,0);
        vcdp->declBit(c+369,"bitty genblk1[5] reg_out clk", false,-1);
        vcdp->declBit(c+241,"bitty genblk1[5] reg_out en", false,-1);
        vcdp->declBus(c+281,"bitty genblk1[5] reg_out d_in", false,-1, 15,0);
        vcdp->declBus(c+521,"bitty genblk1[5] reg_out starting", false,-1, 15,0);
        vcdp->declBit(c+377,"bitty genblk1[5] reg_out reset", false,-1);
        vcdp->declBus(c+337,"bitty genblk1[5] reg_out mux_out", false,-1, 15,0);
        vcdp->declBit(c+369,"bitty genblk1[6] reg_out clk", false,-1);
        vcdp->declBit(c+249,"bitty genblk1[6] reg_out en", false,-1);
        vcdp->declBus(c+281,"bitty genblk1[6] reg_out d_in", false,-1, 15,0);
        vcdp->declBus(c+521,"bitty genblk1[6] reg_out starting", false,-1, 15,0);
        vcdp->declBit(c+377,"bitty genblk1[6] reg_out reset", false,-1);
        vcdp->declBus(c+345,"bitty genblk1[6] reg_out mux_out", false,-1, 15,0);
        vcdp->declBit(c+369,"bitty genblk1[7] reg_out clk", false,-1);
        vcdp->declBit(c+257,"bitty genblk1[7] reg_out en", false,-1);
        vcdp->declBus(c+281,"bitty genblk1[7] reg_out d_in", false,-1, 15,0);
        vcdp->declBus(c+521,"bitty genblk1[7] reg_out starting", false,-1, 15,0);
        vcdp->declBit(c+377,"bitty genblk1[7] reg_out reset", false,-1);
        vcdp->declBus(c+353,"bitty genblk1[7] reg_out mux_out", false,-1, 15,0);
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
        vcdp->fullBus(c+129,((0xffffU & ((4U & (IData)(vlTOPp->bitty__DOT__alu_sel))
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
        vcdp->fullBus(c+137,(vlTOPp->bitty__DOT__mux_sel),3);
        vcdp->fullBus(c+145,(vlTOPp->bitty__DOT__en),8);
        vcdp->fullBus(c+153,(vlTOPp->bitty__DOT__out_mux),16);
        vcdp->fullBit(c+161,(vlTOPp->bitty__DOT__en_s));
        vcdp->fullBit(c+169,(vlTOPp->bitty__DOT__en_c));
        vcdp->fullBit(c+177,(vlTOPp->bitty__DOT__en_inst));
        vcdp->fullBus(c+185,(vlTOPp->bitty__DOT__alu_sel),3);
        vcdp->fullBus(c+193,(vlTOPp->bitty__DOT__cpu_inst__DOT__next_state),2);
        vcdp->fullBit(c+201,((1U & (IData)(vlTOPp->bitty__DOT__en))));
        vcdp->fullBit(c+209,((1U & ((IData)(vlTOPp->bitty__DOT__en) 
                                    >> 1U))));
        vcdp->fullBit(c+217,((1U & ((IData)(vlTOPp->bitty__DOT__en) 
                                    >> 2U))));
        vcdp->fullBit(c+225,((1U & ((IData)(vlTOPp->bitty__DOT__en) 
                                    >> 3U))));
        vcdp->fullBit(c+233,((1U & ((IData)(vlTOPp->bitty__DOT__en) 
                                    >> 4U))));
        vcdp->fullBit(c+241,((1U & ((IData)(vlTOPp->bitty__DOT__en) 
                                    >> 5U))));
        vcdp->fullBit(c+249,((1U & ((IData)(vlTOPp->bitty__DOT__en) 
                                    >> 6U))));
        vcdp->fullBit(c+257,((1U & ((IData)(vlTOPp->bitty__DOT__en) 
                                    >> 7U))));
        vcdp->fullBus(c+265,(vlTOPp->bitty__DOT__instruction),16);
        vcdp->fullBus(c+273,(vlTOPp->bitty__DOT__regs),16);
        vcdp->fullBus(c+281,(vlTOPp->bitty__DOT__regc),16);
        vcdp->fullBus(c+289,(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state),2);
        vcdp->fullBus(c+297,(vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__0__KET____DOT__reg_out__mux_out),16);
        vcdp->fullBus(c+305,(vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__1__KET____DOT__reg_out__mux_out),16);
        vcdp->fullBus(c+313,(vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__2__KET____DOT__reg_out__mux_out),16);
        vcdp->fullBus(c+321,(vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__3__KET____DOT__reg_out__mux_out),16);
        vcdp->fullBus(c+329,(vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__4__KET____DOT__reg_out__mux_out),16);
        vcdp->fullBus(c+337,(vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__5__KET____DOT__reg_out__mux_out),16);
        vcdp->fullBus(c+345,(vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__6__KET____DOT__reg_out__mux_out),16);
        vcdp->fullBus(c+353,(vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__7__KET____DOT__reg_out__mux_out),16);
        vcdp->fullBit(c+361,(vlTOPp->run));
        vcdp->fullBit(c+369,(vlTOPp->clk));
        vcdp->fullBit(c+377,(vlTOPp->reset));
        vcdp->fullBus(c+385,(vlTOPp->d_instr),16);
        vcdp->fullBus(c+393,(vlTOPp->d_out),16);
        vcdp->fullBus(c+401,(vlTOPp->rega),16);
        vcdp->fullBus(c+409,(vlTOPp->regb),16);
        vcdp->fullBus(c+417,(vlTOPp->regcc),16);
        vcdp->fullBus(c+425,(vlTOPp->regss),16);
        vcdp->fullBus(c+433,(vlTOPp->reg0),16);
        vcdp->fullBus(c+441,(vlTOPp->reg1),16);
        vcdp->fullBus(c+449,(vlTOPp->reg2),16);
        vcdp->fullBus(c+457,(vlTOPp->reg3),16);
        vcdp->fullBus(c+465,(vlTOPp->reg4),16);
        vcdp->fullBus(c+473,(vlTOPp->reg5),16);
        vcdp->fullBus(c+481,(vlTOPp->reg6),16);
        vcdp->fullBus(c+489,(vlTOPp->reg7),16);
        vcdp->fullBus(c+497,(vlTOPp->reginst),16);
        vcdp->fullBit(c+505,(vlTOPp->done));
        vcdp->fullBus(c+513,(0U),16);
        vcdp->fullBus(c+521,(0xaU),16);
    }
}
