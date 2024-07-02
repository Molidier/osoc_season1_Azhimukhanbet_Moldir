// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VBITTY_H_
#define _VBITTY_H_  // guard

#include "verilated.h"
#include "Vbitty__Dpi.h"

//==========

class Vbitty__Syms;
class Vbitty___024unit;


//----------

VL_MODULE(Vbitty) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    Vbitty___024unit* __PVT____024unit;
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(run,0,0);
    VL_OUT8(done,0,0);
    VL_IN16(d_instr,15,0);
    VL_OUT16(d_out,15,0);
    VL_OUT16(reg2,15,0);
    VL_OUT16(regb,15,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*3:0*/ bitty__DOT__mux_sel;
    CData/*7:0*/ bitty__DOT__en;
    CData/*0:0*/ bitty__DOT__en_s;
    CData/*0:0*/ bitty__DOT__en_c;
    CData/*0:0*/ bitty__DOT__en_inst;
    CData/*2:0*/ bitty__DOT__alu_sel;
    CData/*1:0*/ bitty__DOT__cpu_inst__DOT__cur_state;
    CData/*1:0*/ bitty__DOT__cpu_inst__DOT__next_state;
    SData/*15:0*/ bitty__DOT__out_mux;
    SData/*15:0*/ bitty__DOT__instruction;
    SData/*15:0*/ bitty__DOT__regs;
    SData/*15:0*/ bitty__DOT__regc;
    SData/*15:0*/ bitty__DOT__out[8];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vclklast__TOP__reset;
    SData/*15:0*/ bitty__DOT____Vcellout__genblk1__BRA__0__KET____DOT__reg_out__mux_out;
    SData/*15:0*/ bitty__DOT____Vcellout__genblk1__BRA__1__KET____DOT__reg_out__mux_out;
    SData/*15:0*/ bitty__DOT____Vcellout__genblk1__BRA__2__KET____DOT__reg_out__mux_out;
    SData/*15:0*/ bitty__DOT____Vcellout__genblk1__BRA__3__KET____DOT__reg_out__mux_out;
    SData/*15:0*/ bitty__DOT____Vcellout__genblk1__BRA__4__KET____DOT__reg_out__mux_out;
    SData/*15:0*/ bitty__DOT____Vcellout__genblk1__BRA__5__KET____DOT__reg_out__mux_out;
    SData/*15:0*/ bitty__DOT____Vcellout__genblk1__BRA__6__KET____DOT__reg_out__mux_out;
    SData/*15:0*/ bitty__DOT____Vcellout__genblk1__BRA__7__KET____DOT__reg_out__mux_out;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vbitty__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vbitty);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vbitty(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vbitty();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vbitty__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vbitty__Syms* symsp, bool first);
  private:
    static QData _change_request(Vbitty__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__4(Vbitty__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vbitty__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vbitty__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vbitty__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__1(Vbitty__Syms* __restrict vlSymsp);
    static void _sequent__TOP__2(Vbitty__Syms* __restrict vlSymsp);
    static void _settle__TOP__3(Vbitty__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
