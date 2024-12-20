// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef _VBIGGER__SYMS_H_
#define _VBIGGER__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODULE CLASSES
#include "Vbigger.h"
#include "Vbigger___024unit.h"

// DPI TYPES for DPI Export callbacks (Internal use)

// SYMS CLASS
class Vbigger__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_activity;  ///< Used by trace routines to determine change occurred
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vbigger*                       TOPp;
    Vbigger___024unit              TOP____024unit;
    
    // CREATORS
    Vbigger__Syms(Vbigger* topp, const char* namep);
    ~Vbigger__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    inline bool getClearActivity() { bool r=__Vm_activity; __Vm_activity=false; return r; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
