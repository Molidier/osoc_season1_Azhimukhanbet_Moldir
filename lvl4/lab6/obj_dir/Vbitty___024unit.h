// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vbitty.h for the primary calling header

#ifndef _VBITTY___024UNIT_H_
#define _VBITTY___024UNIT_H_  // guard

#include "verilated.h"
#include "Vbitty__Dpi.h"

//==========

class Vbitty__Syms;
class Vbitty_VerilatedVcd;


//----------

VL_MODULE(Vbitty___024unit) {
  public:
    
    // INTERNAL VARIABLES
  private:
    Vbitty__Syms* __VlSymsp;  // Symbol table
  public:
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vbitty___024unit);  ///< Copying not allowed
  public:
    Vbitty___024unit(const char* name = "TOP");
    ~Vbitty___024unit();
    
    // INTERNAL METHODS
    void __Vconfigure(Vbitty__Syms* symsp, bool first);
    void __Vdpiimwrap_notify_counter_nine_1_TOP____024unit();
    void __Vdpiimwrap_notify_counter_nine_2_TOP____024unit();
    void __Vdpiimwrap_notify_counter_nine_3_TOP____024unit();
    void __Vdpiimwrap_notify_counter_nine_here_TOP____024unit();
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
