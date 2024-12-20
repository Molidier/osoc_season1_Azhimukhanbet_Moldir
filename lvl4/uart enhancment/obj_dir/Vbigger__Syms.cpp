// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vbigger__Syms.h"
#include "Vbigger.h"
#include "Vbigger___024unit.h"



// FUNCTIONS
Vbigger__Syms::Vbigger__Syms(Vbigger* topp, const char* namep)
    // Setup locals
    : __Vm_namep(namep)
    , __Vm_activity(false)
    , __Vm_didInit(false)
    // Setup submodule names
    , TOP____024unit(Verilated::catName(topp->name(), "$unit"))
{
    // Pointer to top level
    TOPp = topp;
    // Setup each module's pointers to their submodules
    TOPp->__PVT____024unit = &TOP____024unit;
    // Setup each module's pointer back to symbol table (for public functions)
    TOPp->__Vconfigure(this, true);
    TOP____024unit.__Vconfigure(this, true);
    // Setup export functions
    for (int __Vfinal=0; __Vfinal<2; __Vfinal++) {
    }
}
