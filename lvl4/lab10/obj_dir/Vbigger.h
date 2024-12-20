// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VBIGGER_H_
#define _VBIGGER_H_  // guard

#include "verilated_heavy.h"

//==========

class Vbigger__Syms;
class Vbigger_VerilatedVcd;


//----------

VL_MODULE(Vbigger) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(run,0,0);
    VL_OUT8(done,0,0);
    VL_OUT16(instr,15,0);
    VL_OUT16(d_out,15,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*3:0*/ bigger__DOT__cur_state;
    CData/*3:0*/ bigger__DOT__next_state;
    CData/*7:0*/ bigger__DOT__addr;
    CData/*7:0*/ bigger__DOT__new_pc;
    CData/*3:0*/ bigger__DOT__instance3__DOT__mux_sel;
    CData/*7:0*/ bigger__DOT__instance3__DOT__en;
    CData/*0:0*/ bigger__DOT__instance3__DOT__en_s;
    CData/*0:0*/ bigger__DOT__instance3__DOT__en_c;
    CData/*0:0*/ bigger__DOT__instance3__DOT__en_inst;
    CData/*2:0*/ bigger__DOT__instance3__DOT__alu_sel;
    CData/*1:0*/ bigger__DOT__instance3__DOT__cpu_inst__DOT__cur_state;
    CData/*1:0*/ bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state;
    SData/*15:0*/ bigger__DOT__mem_out;
    SData/*15:0*/ bigger__DOT__instance3__DOT__out_mux;
    SData/*15:0*/ bigger__DOT__instance3__DOT__instruction;
    SData/*15:0*/ bigger__DOT__instance3__DOT__im_d;
    SData/*15:0*/ bigger__DOT__instance3__DOT__regs;
    SData/*15:0*/ bigger__DOT__instance3__DOT__regc;
    SData/*15:0*/ bigger__DOT__instance2__DOT__memory_array[256];
    SData/*15:0*/ bigger__DOT__instance3__DOT__out[8];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*4:0*/ __Vtableidx1;
    CData/*6:0*/ __Vtableidx2;
    CData/*0:0*/ __Vclklast__TOP__clk;
    SData/*15:0*/ bigger__DOT__instance3__DOT____Vcellout__gen_dff__BRA__0__KET____DOT__reg_out__mux_out;
    SData/*15:0*/ bigger__DOT__instance3__DOT____Vcellout__gen_dff__BRA__1__KET____DOT__reg_out__mux_out;
    SData/*15:0*/ bigger__DOT__instance3__DOT____Vcellout__gen_dff__BRA__2__KET____DOT__reg_out__mux_out;
    SData/*15:0*/ bigger__DOT__instance3__DOT____Vcellout__gen_dff__BRA__3__KET____DOT__reg_out__mux_out;
    SData/*15:0*/ bigger__DOT__instance3__DOT____Vcellout__gen_dff__BRA__4__KET____DOT__reg_out__mux_out;
    SData/*15:0*/ bigger__DOT__instance3__DOT____Vcellout__gen_dff__BRA__5__KET____DOT__reg_out__mux_out;
    SData/*15:0*/ bigger__DOT__instance3__DOT____Vcellout__gen_dff__BRA__6__KET____DOT__reg_out__mux_out;
    SData/*15:0*/ bigger__DOT__instance3__DOT____Vcellout__gen_dff__BRA__7__KET____DOT__reg_out__mux_out;
    IData/*31:0*/ __Vm_traceActivity;
    static CData/*3:0*/ __Vtable1_bigger__DOT__next_state[32];
    static CData/*1:0*/ __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[128];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vbigger__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vbigger);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vbigger(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vbigger();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vbigger__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vbigger__Syms* symsp, bool first);
  private:
    static QData _change_request(Vbigger__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vbigger__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vbigger__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vbigger__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__3(Vbigger__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__1(Vbigger__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(Vbigger__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void traceChgThis(Vbigger__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__2(Vbigger__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__3(Vbigger__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__4(Vbigger__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceFullThis(Vbigger__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceFullThis__1(Vbigger__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis(Vbigger__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis__1(Vbigger__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
