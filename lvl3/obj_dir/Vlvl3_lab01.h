// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VLVL3_LAB01_H_
#define _VLVL3_LAB01_H_  // guard

#include "verilated.h"

//==========

class Vlvl3_lab01__Syms;
class Vlvl3_lab01_VerilatedVcd;


//----------

VL_MODULE(Vlvl3_lab01) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(carry_in,0,0);
    VL_IN8(select,3,0);
    VL_IN8(mode,0,0);
    VL_OUT8(carry_out,0,0);
    VL_OUT8(compare,0,0);
    VL_IN16(a_in,15,0);
    VL_IN16(b_in,15,0);
    VL_OUT16(alu_out,15,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*0:0*/ alu__DOT__car_out;
    CData/*0:0*/ alu__DOT__car_arith;
    CData/*0:0*/ alu__DOT__cmp;
    SData/*15:0*/ alu__DOT__u1__DOT__res;
    IData/*16:0*/ alu__DOT__u2__DOT__extended_res;
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    IData/*31:0*/ __Vm_traceActivity;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vlvl3_lab01__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vlvl3_lab01);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vlvl3_lab01(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vlvl3_lab01();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vlvl3_lab01__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vlvl3_lab01__Syms* symsp, bool first);
  private:
    static QData _change_request(Vlvl3_lab01__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__2(Vlvl3_lab01__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vlvl3_lab01__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vlvl3_lab01__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vlvl3_lab01__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(Vlvl3_lab01__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void traceChgThis(Vlvl3_lab01__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__2(Vlvl3_lab01__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__3(Vlvl3_lab01__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceFullThis(Vlvl3_lab01__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceFullThis__1(Vlvl3_lab01__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis(Vlvl3_lab01__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis__1(Vlvl3_lab01__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
