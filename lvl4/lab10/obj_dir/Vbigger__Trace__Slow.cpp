// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vbigger__Syms.h"


//======================

void Vbigger::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&Vbigger::traceInit, &Vbigger::traceFull, &Vbigger::traceChg, this);
}
void Vbigger::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    Vbigger* t = (Vbigger*)userthis;
    Vbigger__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void Vbigger::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vbigger* t = (Vbigger*)userthis;
    Vbigger__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void Vbigger::traceInitThis(Vbigger__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vbigger* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
        vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void Vbigger::traceFullThis(Vbigger__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vbigger* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vbigger::traceInitThis__1(Vbigger__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vbigger* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->declBit(c+441,"clk", false,-1);
        vcdp->declBit(c+449,"reset", false,-1);
        vcdp->declBit(c+457,"run", false,-1);
        vcdp->declBit(c+465,"done", false,-1);
        vcdp->declBus(c+473,"instr", false,-1, 15,0);
        vcdp->declBus(c+481,"d_out", false,-1, 15,0);
        vcdp->declBit(c+441,"bigger clk", false,-1);
        vcdp->declBit(c+449,"bigger reset", false,-1);
        vcdp->declBit(c+457,"bigger run", false,-1);
        vcdp->declBit(c+465,"bigger done", false,-1);
        vcdp->declBus(c+473,"bigger instr", false,-1, 15,0);
        vcdp->declBus(c+481,"bigger d_out", false,-1, 15,0);
        vcdp->declBus(c+273,"bigger cur_state", false,-1, 1,0);
        vcdp->declBus(c+281,"bigger next_state", false,-1, 1,0);
        vcdp->declBit(c+289,"bigger run_bitty", false,-1);
        vcdp->declBus(c+401,"bigger mem_out", false,-1, 15,0);
        vcdp->declBus(c+409,"bigger addr", false,-1, 7,0);
        vcdp->declBus(c+489,"bigger new_pc", false,-1, 7,0);
        vcdp->declBus(c+505,"bigger d_in", false,-1, 7,0);
        vcdp->declBit(c+513,"bigger instr_valid", false,-1);
        vcdp->declBus(c+409,"bigger instance4 address", false,-1, 7,0);
        vcdp->declBus(c+401,"bigger instance4 instruction", false,-1, 15,0);
        vcdp->declBus(c+481,"bigger instance4 last_alu_result", false,-1, 15,0);
        vcdp->declBit(c+465,"bigger instance4 done", false,-1);
        vcdp->declBus(c+489,"bigger instance4 new_pc", false,-1, 7,0);
        vcdp->declBit(c+433,"bigger instance4 cur_state", false,-1);
        vcdp->declBit(c+497,"bigger instance4 next_state", false,-1);
        vcdp->declBus(c+417,"bigger instance4 branch_cond", false,-1, 1,0);
        vcdp->declBus(c+425,"bigger instance4 immediate", false,-1, 7,0);
        vcdp->declBit(c+441,"bigger instance1 clk", false,-1);
        vcdp->declBit(c+465,"bigger instance1 en_pc", false,-1);
        vcdp->declBit(c+449,"bigger instance1 reset", false,-1);
        vcdp->declBus(c+489,"bigger instance1 d_in", false,-1, 7,0);
        vcdp->declBus(c+409,"bigger instance1 d_out", false,-1, 7,0);
        vcdp->declBit(c+441,"bigger instance2 clk", false,-1);
        vcdp->declBus(c+409,"bigger instance2 addr", false,-1, 7,0);
        vcdp->declBus(c+401,"bigger instance2 out", false,-1, 15,0);
        vcdp->declBit(c+289,"bigger instance3 run", false,-1);
        vcdp->declBit(c+441,"bigger instance3 clk", false,-1);
        vcdp->declBit(c+449,"bigger instance3 reset", false,-1);
        vcdp->declBus(c+401,"bigger instance3 d_instr", false,-1, 15,0);
        vcdp->declBus(c+481,"bigger instance3 d_out", false,-1, 15,0);
        vcdp->declBit(c+465,"bigger instance3 done", false,-1);
        vcdp->declBus(c+137,"bigger instance3 mux_sel", false,-1, 3,0);
        vcdp->declBus(c+145,"bigger instance3 en", false,-1, 7,0);
        {int i; for (i=0; i<8; i++) {
                vcdp->declBus(c+1+i*1,"bigger instance3 out", true,(i+0), 15,0);}}
        vcdp->declBus(c+153,"bigger instance3 out_mux", false,-1, 15,0);
        vcdp->declBus(c+129,"bigger instance3 alu_out", false,-1, 15,0);
        vcdp->declBit(c+161,"bigger instance3 en_s", false,-1);
        vcdp->declBit(c+169,"bigger instance3 en_c", false,-1);
        vcdp->declBit(c+177,"bigger instance3 en_inst", false,-1);
        vcdp->declBus(c+185,"bigger instance3 alu_sel", false,-1, 2,0);
        vcdp->declBus(c+297,"bigger instance3 instruction", false,-1, 15,0);
        vcdp->declBus(c+193,"bigger instance3 im_d", false,-1, 15,0);
        vcdp->declBus(c+305,"bigger instance3 regs", false,-1, 15,0);
        vcdp->declBus(c+313,"bigger instance3 regc", false,-1, 15,0);
        vcdp->declBit(c+441,"bigger instance3 cpu_inst clk", false,-1);
        vcdp->declBit(c+289,"bigger instance3 cpu_inst run", false,-1);
        vcdp->declBit(c+449,"bigger instance3 cpu_inst reset", false,-1);
        vcdp->declBus(c+297,"bigger instance3 cpu_inst d_inst", false,-1, 15,0);
        vcdp->declBus(c+137,"bigger instance3 cpu_inst mux_sel", false,-1, 3,0);
        vcdp->declBit(c+465,"bigger instance3 cpu_inst done", false,-1);
        vcdp->declBus(c+185,"bigger instance3 cpu_inst sel", false,-1, 2,0);
        vcdp->declBit(c+161,"bigger instance3 cpu_inst en_s", false,-1);
        vcdp->declBit(c+169,"bigger instance3 cpu_inst en_c", false,-1);
        vcdp->declBus(c+145,"bigger instance3 cpu_inst en", false,-1, 7,0);
        vcdp->declBit(c+177,"bigger instance3 cpu_inst en_inst", false,-1);
        vcdp->declBus(c+193,"bigger instance3 cpu_inst im_d", false,-1, 15,0);
        vcdp->declBus(c+321,"bigger instance3 cpu_inst cur_state", false,-1, 1,0);
        vcdp->declBus(c+201,"bigger instance3 cpu_inst next_state", false,-1, 1,0);
        vcdp->declBus(c+329,"bigger instance3 cpu_inst format", false,-1, 1,0);
        vcdp->declBus(c+185,"bigger instance3 alu_inst select", false,-1, 2,0);
        vcdp->declBus(c+305,"bigger instance3 alu_inst in_a", false,-1, 15,0);
        vcdp->declBus(c+153,"bigger instance3 alu_inst in_b", false,-1, 15,0);
        vcdp->declBus(c+129,"bigger instance3 alu_inst alu_out", false,-1, 15,0);
        vcdp->declBus(c+129,"bigger instance3 alu_inst res", false,-1, 15,0);
        vcdp->declBus(c+65,"bigger instance3 mux_inst reg0", false,-1, 15,0);
        vcdp->declBus(c+73,"bigger instance3 mux_inst reg1", false,-1, 15,0);
        vcdp->declBus(c+81,"bigger instance3 mux_inst reg2", false,-1, 15,0);
        vcdp->declBus(c+89,"bigger instance3 mux_inst reg3", false,-1, 15,0);
        vcdp->declBus(c+97,"bigger instance3 mux_inst reg4", false,-1, 15,0);
        vcdp->declBus(c+105,"bigger instance3 mux_inst reg5", false,-1, 15,0);
        vcdp->declBus(c+113,"bigger instance3 mux_inst reg6", false,-1, 15,0);
        vcdp->declBus(c+121,"bigger instance3 mux_inst reg7", false,-1, 15,0);
        vcdp->declBus(c+193,"bigger instance3 mux_inst im_d", false,-1, 15,0);
        vcdp->declBus(c+137,"bigger instance3 mux_inst mux_sel", false,-1, 3,0);
        vcdp->declBus(c+153,"bigger instance3 mux_inst mux_out", false,-1, 15,0);
        vcdp->declBit(c+441,"bigger instance3 reg_inst clk", false,-1);
        vcdp->declBit(c+177,"bigger instance3 reg_inst en", false,-1);
        vcdp->declBus(c+401,"bigger instance3 reg_inst d_in", false,-1, 15,0);
        vcdp->declBus(c+521,"bigger instance3 reg_inst starting", false,-1, 15,0);
        vcdp->declBit(c+449,"bigger instance3 reg_inst reset", false,-1);
        vcdp->declBus(c+297,"bigger instance3 reg_inst mux_out", false,-1, 15,0);
        vcdp->declBit(c+441,"bigger instance3 reg_s clk", false,-1);
        vcdp->declBit(c+161,"bigger instance3 reg_s en", false,-1);
        vcdp->declBus(c+153,"bigger instance3 reg_s d_in", false,-1, 15,0);
        vcdp->declBus(c+521,"bigger instance3 reg_s starting", false,-1, 15,0);
        vcdp->declBit(c+449,"bigger instance3 reg_s reset", false,-1);
        vcdp->declBus(c+305,"bigger instance3 reg_s mux_out", false,-1, 15,0);
        vcdp->declBit(c+441,"bigger instance3 reg_c clk", false,-1);
        vcdp->declBit(c+169,"bigger instance3 reg_c en", false,-1);
        vcdp->declBus(c+129,"bigger instance3 reg_c d_in", false,-1, 15,0);
        vcdp->declBus(c+521,"bigger instance3 reg_c starting", false,-1, 15,0);
        vcdp->declBit(c+449,"bigger instance3 reg_c reset", false,-1);
        vcdp->declBus(c+313,"bigger instance3 reg_c mux_out", false,-1, 15,0);
        vcdp->declBit(c+441,"bigger instance3 genblk1[0] reg_out clk", false,-1);
        vcdp->declBit(c+209,"bigger instance3 genblk1[0] reg_out en", false,-1);
        vcdp->declBus(c+313,"bigger instance3 genblk1[0] reg_out d_in", false,-1, 15,0);
        vcdp->declBus(c+529,"bigger instance3 genblk1[0] reg_out starting", false,-1, 15,0);
        vcdp->declBit(c+449,"bigger instance3 genblk1[0] reg_out reset", false,-1);
        vcdp->declBus(c+337,"bigger instance3 genblk1[0] reg_out mux_out", false,-1, 15,0);
        vcdp->declBit(c+441,"bigger instance3 genblk1[1] reg_out clk", false,-1);
        vcdp->declBit(c+217,"bigger instance3 genblk1[1] reg_out en", false,-1);
        vcdp->declBus(c+313,"bigger instance3 genblk1[1] reg_out d_in", false,-1, 15,0);
        vcdp->declBus(c+529,"bigger instance3 genblk1[1] reg_out starting", false,-1, 15,0);
        vcdp->declBit(c+449,"bigger instance3 genblk1[1] reg_out reset", false,-1);
        vcdp->declBus(c+345,"bigger instance3 genblk1[1] reg_out mux_out", false,-1, 15,0);
        vcdp->declBit(c+441,"bigger instance3 genblk1[2] reg_out clk", false,-1);
        vcdp->declBit(c+225,"bigger instance3 genblk1[2] reg_out en", false,-1);
        vcdp->declBus(c+313,"bigger instance3 genblk1[2] reg_out d_in", false,-1, 15,0);
        vcdp->declBus(c+529,"bigger instance3 genblk1[2] reg_out starting", false,-1, 15,0);
        vcdp->declBit(c+449,"bigger instance3 genblk1[2] reg_out reset", false,-1);
        vcdp->declBus(c+353,"bigger instance3 genblk1[2] reg_out mux_out", false,-1, 15,0);
        vcdp->declBit(c+441,"bigger instance3 genblk1[3] reg_out clk", false,-1);
        vcdp->declBit(c+233,"bigger instance3 genblk1[3] reg_out en", false,-1);
        vcdp->declBus(c+313,"bigger instance3 genblk1[3] reg_out d_in", false,-1, 15,0);
        vcdp->declBus(c+529,"bigger instance3 genblk1[3] reg_out starting", false,-1, 15,0);
        vcdp->declBit(c+449,"bigger instance3 genblk1[3] reg_out reset", false,-1);
        vcdp->declBus(c+361,"bigger instance3 genblk1[3] reg_out mux_out", false,-1, 15,0);
        vcdp->declBit(c+441,"bigger instance3 genblk1[4] reg_out clk", false,-1);
        vcdp->declBit(c+241,"bigger instance3 genblk1[4] reg_out en", false,-1);
        vcdp->declBus(c+313,"bigger instance3 genblk1[4] reg_out d_in", false,-1, 15,0);
        vcdp->declBus(c+529,"bigger instance3 genblk1[4] reg_out starting", false,-1, 15,0);
        vcdp->declBit(c+449,"bigger instance3 genblk1[4] reg_out reset", false,-1);
        vcdp->declBus(c+369,"bigger instance3 genblk1[4] reg_out mux_out", false,-1, 15,0);
        vcdp->declBit(c+441,"bigger instance3 genblk1[5] reg_out clk", false,-1);
        vcdp->declBit(c+249,"bigger instance3 genblk1[5] reg_out en", false,-1);
        vcdp->declBus(c+313,"bigger instance3 genblk1[5] reg_out d_in", false,-1, 15,0);
        vcdp->declBus(c+529,"bigger instance3 genblk1[5] reg_out starting", false,-1, 15,0);
        vcdp->declBit(c+449,"bigger instance3 genblk1[5] reg_out reset", false,-1);
        vcdp->declBus(c+377,"bigger instance3 genblk1[5] reg_out mux_out", false,-1, 15,0);
        vcdp->declBit(c+441,"bigger instance3 genblk1[6] reg_out clk", false,-1);
        vcdp->declBit(c+257,"bigger instance3 genblk1[6] reg_out en", false,-1);
        vcdp->declBus(c+313,"bigger instance3 genblk1[6] reg_out d_in", false,-1, 15,0);
        vcdp->declBus(c+529,"bigger instance3 genblk1[6] reg_out starting", false,-1, 15,0);
        vcdp->declBit(c+449,"bigger instance3 genblk1[6] reg_out reset", false,-1);
        vcdp->declBus(c+385,"bigger instance3 genblk1[6] reg_out mux_out", false,-1, 15,0);
        vcdp->declBit(c+441,"bigger instance3 genblk1[7] reg_out clk", false,-1);
        vcdp->declBit(c+265,"bigger instance3 genblk1[7] reg_out en", false,-1);
        vcdp->declBus(c+313,"bigger instance3 genblk1[7] reg_out d_in", false,-1, 15,0);
        vcdp->declBus(c+529,"bigger instance3 genblk1[7] reg_out starting", false,-1, 15,0);
        vcdp->declBit(c+449,"bigger instance3 genblk1[7] reg_out reset", false,-1);
        vcdp->declBus(c+393,"bigger instance3 genblk1[7] reg_out mux_out", false,-1, 15,0);
    }
}

void Vbigger::traceFullThis__1(Vbigger__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vbigger* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->fullBus(c+1,(vlTOPp->bigger__DOT__instance3__DOT__out[0]),16);
        vcdp->fullBus(c+2,(vlTOPp->bigger__DOT__instance3__DOT__out[1]),16);
        vcdp->fullBus(c+3,(vlTOPp->bigger__DOT__instance3__DOT__out[2]),16);
        vcdp->fullBus(c+4,(vlTOPp->bigger__DOT__instance3__DOT__out[3]),16);
        vcdp->fullBus(c+5,(vlTOPp->bigger__DOT__instance3__DOT__out[4]),16);
        vcdp->fullBus(c+6,(vlTOPp->bigger__DOT__instance3__DOT__out[5]),16);
        vcdp->fullBus(c+7,(vlTOPp->bigger__DOT__instance3__DOT__out[6]),16);
        vcdp->fullBus(c+8,(vlTOPp->bigger__DOT__instance3__DOT__out[7]),16);
        vcdp->fullBus(c+65,(vlTOPp->bigger__DOT__instance3__DOT__out
                            [0U]),16);
        vcdp->fullBus(c+73,(vlTOPp->bigger__DOT__instance3__DOT__out
                            [1U]),16);
        vcdp->fullBus(c+81,(vlTOPp->bigger__DOT__instance3__DOT__out
                            [2U]),16);
        vcdp->fullBus(c+89,(vlTOPp->bigger__DOT__instance3__DOT__out
                            [3U]),16);
        vcdp->fullBus(c+97,(vlTOPp->bigger__DOT__instance3__DOT__out
                            [4U]),16);
        vcdp->fullBus(c+105,(vlTOPp->bigger__DOT__instance3__DOT__out
                             [5U]),16);
        vcdp->fullBus(c+113,(vlTOPp->bigger__DOT__instance3__DOT__out
                             [6U]),16);
        vcdp->fullBus(c+121,(vlTOPp->bigger__DOT__instance3__DOT__out
                             [7U]),16);
        vcdp->fullBus(c+129,((0xffffU & ((4U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__alu_sel))
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
        vcdp->fullBus(c+137,(vlTOPp->bigger__DOT__instance3__DOT__mux_sel),4);
        vcdp->fullBus(c+145,(vlTOPp->bigger__DOT__instance3__DOT__en),8);
        vcdp->fullBus(c+153,(vlTOPp->bigger__DOT__instance3__DOT__out_mux),16);
        vcdp->fullBit(c+161,(vlTOPp->bigger__DOT__instance3__DOT__en_s));
        vcdp->fullBit(c+169,(vlTOPp->bigger__DOT__instance3__DOT__en_c));
        vcdp->fullBit(c+177,(vlTOPp->bigger__DOT__instance3__DOT__en_inst));
        vcdp->fullBus(c+185,(vlTOPp->bigger__DOT__instance3__DOT__alu_sel),3);
        vcdp->fullBus(c+193,(vlTOPp->bigger__DOT__instance3__DOT__im_d),16);
        vcdp->fullBus(c+201,(vlTOPp->bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state),2);
        vcdp->fullBit(c+209,((1U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__en))));
        vcdp->fullBit(c+217,((1U & ((IData)(vlTOPp->bigger__DOT__instance3__DOT__en) 
                                    >> 1U))));
        vcdp->fullBit(c+225,((1U & ((IData)(vlTOPp->bigger__DOT__instance3__DOT__en) 
                                    >> 2U))));
        vcdp->fullBit(c+233,((1U & ((IData)(vlTOPp->bigger__DOT__instance3__DOT__en) 
                                    >> 3U))));
        vcdp->fullBit(c+241,((1U & ((IData)(vlTOPp->bigger__DOT__instance3__DOT__en) 
                                    >> 4U))));
        vcdp->fullBit(c+249,((1U & ((IData)(vlTOPp->bigger__DOT__instance3__DOT__en) 
                                    >> 5U))));
        vcdp->fullBit(c+257,((1U & ((IData)(vlTOPp->bigger__DOT__instance3__DOT__en) 
                                    >> 6U))));
        vcdp->fullBit(c+265,((1U & ((IData)(vlTOPp->bigger__DOT__instance3__DOT__en) 
                                    >> 7U))));
        vcdp->fullBus(c+273,(vlTOPp->bigger__DOT__cur_state),2);
        vcdp->fullBus(c+281,(((0U == (IData)(vlTOPp->bigger__DOT__cur_state))
                               ? 1U : ((1U == (IData)(vlTOPp->bigger__DOT__cur_state))
                                        ? 1U : 0U))),2);
        vcdp->fullBit(c+289,(((0U != (IData)(vlTOPp->bigger__DOT__cur_state)) 
                              & (1U == (IData)(vlTOPp->bigger__DOT__cur_state)))));
        vcdp->fullBus(c+297,(vlTOPp->bigger__DOT__instance3__DOT__instruction),16);
        vcdp->fullBus(c+305,(vlTOPp->bigger__DOT__instance3__DOT__regs),16);
        vcdp->fullBus(c+313,(vlTOPp->bigger__DOT__instance3__DOT__regc),16);
        vcdp->fullBus(c+321,(vlTOPp->bigger__DOT__instance3__DOT__cpu_inst__DOT__cur_state),2);
        vcdp->fullBus(c+329,((3U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__instruction))),2);
        vcdp->fullBus(c+337,(vlTOPp->bigger__DOT__instance3__DOT____Vcellout__genblk1__BRA__0__KET____DOT__reg_out__mux_out),16);
        vcdp->fullBus(c+345,(vlTOPp->bigger__DOT__instance3__DOT____Vcellout__genblk1__BRA__1__KET____DOT__reg_out__mux_out),16);
        vcdp->fullBus(c+353,(vlTOPp->bigger__DOT__instance3__DOT____Vcellout__genblk1__BRA__2__KET____DOT__reg_out__mux_out),16);
        vcdp->fullBus(c+361,(vlTOPp->bigger__DOT__instance3__DOT____Vcellout__genblk1__BRA__3__KET____DOT__reg_out__mux_out),16);
        vcdp->fullBus(c+369,(vlTOPp->bigger__DOT__instance3__DOT____Vcellout__genblk1__BRA__4__KET____DOT__reg_out__mux_out),16);
        vcdp->fullBus(c+377,(vlTOPp->bigger__DOT__instance3__DOT____Vcellout__genblk1__BRA__5__KET____DOT__reg_out__mux_out),16);
        vcdp->fullBus(c+385,(vlTOPp->bigger__DOT__instance3__DOT____Vcellout__genblk1__BRA__6__KET____DOT__reg_out__mux_out),16);
        vcdp->fullBus(c+393,(vlTOPp->bigger__DOT__instance3__DOT____Vcellout__genblk1__BRA__7__KET____DOT__reg_out__mux_out),16);
        vcdp->fullBus(c+401,(vlTOPp->bigger__DOT__mem_out),16);
        vcdp->fullBus(c+409,(vlTOPp->bigger__DOT__addr),8);
        vcdp->fullBus(c+417,((3U & ((IData)(vlTOPp->bigger__DOT__mem_out) 
                                    >> 2U))),2);
        vcdp->fullBus(c+425,((0xffU & ((IData)(vlTOPp->bigger__DOT__mem_out) 
                                       >> 4U))),8);
        vcdp->fullBit(c+433,(vlTOPp->bigger__DOT__instance4__DOT__cur_state));
        vcdp->fullBit(c+441,(vlTOPp->clk));
        vcdp->fullBit(c+449,(vlTOPp->reset));
        vcdp->fullBit(c+457,(vlTOPp->run));
        vcdp->fullBit(c+465,(vlTOPp->done));
        vcdp->fullBus(c+473,(vlTOPp->instr),16);
        vcdp->fullBus(c+481,(vlTOPp->d_out),16);
        vcdp->fullBus(c+489,((0xffU & ((0U == (3U & 
                                               ((IData)(vlTOPp->bigger__DOT__mem_out) 
                                                >> 2U)))
                                        ? ((0U == (IData)(vlTOPp->d_out))
                                            ? ((IData)(vlTOPp->bigger__DOT__mem_out) 
                                               >> 4U)
                                            : ((IData)(1U) 
                                               + (IData)(vlTOPp->bigger__DOT__addr)))
                                        : ((1U == (3U 
                                                   & ((IData)(vlTOPp->bigger__DOT__mem_out) 
                                                      >> 2U)))
                                            ? ((1U 
                                                == (IData)(vlTOPp->d_out))
                                                ? ((IData)(vlTOPp->bigger__DOT__mem_out) 
                                                   >> 4U)
                                                : ((IData)(1U) 
                                                   + (IData)(vlTOPp->bigger__DOT__addr)))
                                            : ((2U 
                                                == 
                                                (3U 
                                                 & ((IData)(vlTOPp->bigger__DOT__mem_out) 
                                                    >> 2U)))
                                                ? (
                                                   (2U 
                                                    == (IData)(vlTOPp->d_out))
                                                    ? 
                                                   ((IData)(vlTOPp->bigger__DOT__mem_out) 
                                                    >> 4U)
                                                    : 
                                                   ((IData)(1U) 
                                                    + (IData)(vlTOPp->bigger__DOT__addr)))
                                                : ((IData)(1U) 
                                                   + (IData)(vlTOPp->bigger__DOT__addr))))))),8);
        vcdp->fullBit(c+497,(((~ (IData)(vlTOPp->bigger__DOT__instance4__DOT__cur_state)) 
                              & (IData)(vlTOPp->done))));
        vcdp->fullBus(c+505,(vlTOPp->bigger__DOT__d_in),8);
        vcdp->fullBit(c+513,(vlTOPp->bigger__DOT__instr_valid));
        vcdp->fullBus(c+521,(0U),16);
        vcdp->fullBus(c+529,(0xaU),16);
    }
}
