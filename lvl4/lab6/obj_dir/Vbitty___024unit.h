// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vbitty.h for the primary calling header

#ifndef _VBITTY___024UNIT_H_
#define _VBITTY___024UNIT_H_  // guard

#include "verilated.h"

//==========

class Vbitty__Syms;

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
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
