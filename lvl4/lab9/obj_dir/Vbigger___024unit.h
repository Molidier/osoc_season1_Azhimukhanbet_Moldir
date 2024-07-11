// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vbigger.h for the primary calling header

#ifndef _VBIGGER___024UNIT_H_
#define _VBIGGER___024UNIT_H_  // guard

#include "verilated_heavy.h"
#include "Vbigger__Dpi.h"

//==========

class Vbigger__Syms;
class Vbigger_VerilatedVcd;


//----------

VL_MODULE(Vbigger___024unit) {
  public:
    
    // INTERNAL VARIABLES
  private:
    Vbigger__Syms* __VlSymsp;  // Symbol table
  public:
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vbigger___024unit);  ///< Copying not allowed
  public:
    Vbigger___024unit(const char* name = "TOP");
    ~Vbigger___024unit();
    
    // INTERNAL METHODS
    void __Vconfigure(Vbigger__Syms* symsp, bool first);
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
