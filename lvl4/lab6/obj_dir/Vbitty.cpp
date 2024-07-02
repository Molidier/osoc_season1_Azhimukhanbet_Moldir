// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbitty.h for the primary calling header

#include "Vbitty.h"
#include "Vbitty__Syms.h"

#include "verilated_dpi.h"

//==========

VL_CTOR_IMP(Vbitty) {
    Vbitty__Syms* __restrict vlSymsp = __VlSymsp = new Vbitty__Syms(this, name());
    Vbitty* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    VL_CELL(__PVT____024unit, Vbitty___024unit);
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vbitty::__Vconfigure(Vbitty__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vbitty::~Vbitty() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void Vbitty::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vbitty::eval\n"); );
    Vbitty__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vbitty* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("bitty.v", 4, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vbitty::_eval_initial_loop(Vbitty__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("bitty.v", 4, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vbitty::_sequent__TOP__1(Vbitty__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty::_sequent__TOP__1\n"); );
    Vbitty* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state = vlTOPp->bitty__DOT__cpu_inst__DOT__next_state;
}

VL_INLINE_OPT void Vbitty::_sequent__TOP__2(Vbitty__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty::_sequent__TOP__2\n"); );
    Vbitty* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->reset) {
        vlTOPp->bitty__DOT__regc = 0U;
    } else {
        if (vlTOPp->bitty__DOT__en_c) {
            vlSymsp->TOP____024unit.__Vdpiimwrap_notify_counter_nine_here_TOP____024unit();
            vlTOPp->bitty__DOT__regc = vlTOPp->bitty__DOT__alu_inst__DOT__res;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bitty__DOT__regs = 0U;
    } else {
        if (vlTOPp->bitty__DOT__en_s) {
            vlSymsp->TOP____024unit.__Vdpiimwrap_notify_counter_nine_here_TOP____024unit();
            vlTOPp->bitty__DOT__regs = vlTOPp->bitty__DOT__out_mux;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bitty__DOT__instruction = 0U;
    } else {
        if (vlTOPp->bitty__DOT__en_inst) {
            vlSymsp->TOP____024unit.__Vdpiimwrap_notify_counter_nine_here_TOP____024unit();
            vlTOPp->bitty__DOT__instruction = vlTOPp->d_instr;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__0__KET____DOT__reg_out__mux_out = 0xaU;
    } else {
        if ((1U & (IData)(vlTOPp->bitty__DOT__en))) {
            vlSymsp->TOP____024unit.__Vdpiimwrap_notify_counter_nine_here_TOP____024unit();
            vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__0__KET____DOT__reg_out__mux_out 
                = vlTOPp->bitty__DOT__alu_inst__DOT__res;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__1__KET____DOT__reg_out__mux_out = 0xaU;
    } else {
        if ((2U & (IData)(vlTOPp->bitty__DOT__en))) {
            vlSymsp->TOP____024unit.__Vdpiimwrap_notify_counter_nine_here_TOP____024unit();
            vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__1__KET____DOT__reg_out__mux_out 
                = vlTOPp->bitty__DOT__alu_inst__DOT__res;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__2__KET____DOT__reg_out__mux_out = 0xaU;
    } else {
        if ((4U & (IData)(vlTOPp->bitty__DOT__en))) {
            vlSymsp->TOP____024unit.__Vdpiimwrap_notify_counter_nine_here_TOP____024unit();
            vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__2__KET____DOT__reg_out__mux_out 
                = vlTOPp->bitty__DOT__alu_inst__DOT__res;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__3__KET____DOT__reg_out__mux_out = 0xaU;
    } else {
        if ((8U & (IData)(vlTOPp->bitty__DOT__en))) {
            vlSymsp->TOP____024unit.__Vdpiimwrap_notify_counter_nine_here_TOP____024unit();
            vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__3__KET____DOT__reg_out__mux_out 
                = vlTOPp->bitty__DOT__alu_inst__DOT__res;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__4__KET____DOT__reg_out__mux_out = 0xaU;
    } else {
        if ((0x10U & (IData)(vlTOPp->bitty__DOT__en))) {
            vlSymsp->TOP____024unit.__Vdpiimwrap_notify_counter_nine_here_TOP____024unit();
            vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__4__KET____DOT__reg_out__mux_out 
                = vlTOPp->bitty__DOT__alu_inst__DOT__res;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__5__KET____DOT__reg_out__mux_out = 0xaU;
    } else {
        if ((0x20U & (IData)(vlTOPp->bitty__DOT__en))) {
            vlSymsp->TOP____024unit.__Vdpiimwrap_notify_counter_nine_here_TOP____024unit();
            vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__5__KET____DOT__reg_out__mux_out 
                = vlTOPp->bitty__DOT__alu_inst__DOT__res;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__6__KET____DOT__reg_out__mux_out = 0xaU;
    } else {
        if ((0x40U & (IData)(vlTOPp->bitty__DOT__en))) {
            vlSymsp->TOP____024unit.__Vdpiimwrap_notify_counter_nine_here_TOP____024unit();
            vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__6__KET____DOT__reg_out__mux_out 
                = vlTOPp->bitty__DOT__alu_inst__DOT__res;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__7__KET____DOT__reg_out__mux_out = 0xaU;
    } else {
        if ((0x80U & (IData)(vlTOPp->bitty__DOT__en))) {
            vlSymsp->TOP____024unit.__Vdpiimwrap_notify_counter_nine_here_TOP____024unit();
            vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__7__KET____DOT__reg_out__mux_out 
                = vlTOPp->bitty__DOT__alu_inst__DOT__res;
        }
    }
    vlTOPp->d_out = vlTOPp->bitty__DOT__regc;
    vlTOPp->rega = vlTOPp->bitty__DOT__regs;
    vlTOPp->bitty__DOT__out[0U] = vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__0__KET____DOT__reg_out__mux_out;
    vlTOPp->bitty__DOT__out[1U] = vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__1__KET____DOT__reg_out__mux_out;
    vlTOPp->bitty__DOT__out[2U] = vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__2__KET____DOT__reg_out__mux_out;
    vlTOPp->bitty__DOT__out[3U] = vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__3__KET____DOT__reg_out__mux_out;
    vlTOPp->bitty__DOT__out[4U] = vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__4__KET____DOT__reg_out__mux_out;
    vlTOPp->bitty__DOT__out[5U] = vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__5__KET____DOT__reg_out__mux_out;
    vlTOPp->bitty__DOT__out[6U] = vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__6__KET____DOT__reg_out__mux_out;
    vlTOPp->bitty__DOT__out[7U] = vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__7__KET____DOT__reg_out__mux_out;
}

void Vbitty::_settle__TOP__3(Vbitty__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty::_settle__TOP__3\n"); );
    Vbitty* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->rega = vlTOPp->bitty__DOT__regs;
    if (vlTOPp->reset) {
        vlTOPp->bitty__DOT__en_inst = 0U;
    }
    vlTOPp->d_out = vlTOPp->bitty__DOT__regc;
    vlTOPp->bitty__DOT__out[0U] = vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__0__KET____DOT__reg_out__mux_out;
    vlTOPp->bitty__DOT__out[1U] = vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__1__KET____DOT__reg_out__mux_out;
    vlTOPp->bitty__DOT__out[2U] = vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__2__KET____DOT__reg_out__mux_out;
    vlTOPp->bitty__DOT__out[3U] = vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__3__KET____DOT__reg_out__mux_out;
    vlTOPp->bitty__DOT__out[4U] = vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__4__KET____DOT__reg_out__mux_out;
    vlTOPp->bitty__DOT__out[5U] = vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__5__KET____DOT__reg_out__mux_out;
    vlTOPp->bitty__DOT__out[6U] = vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__6__KET____DOT__reg_out__mux_out;
    vlTOPp->bitty__DOT__out[7U] = vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__7__KET____DOT__reg_out__mux_out;
    if (vlTOPp->reset) {
        vlTOPp->bitty__DOT__en_s = 0U;
    }
    if (vlTOPp->run) {
        if ((0U == (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
            vlTOPp->bitty__DOT__en_s = 1U;
        } else {
            if ((1U != (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
                if ((3U != (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
                    vlTOPp->bitty__DOT__en_s = 0U;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bitty__DOT__en_c = 0U;
    }
    if (vlTOPp->run) {
        if ((0U != (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
            if ((1U == (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
                vlTOPp->bitty__DOT__en_c = 1U;
            } else {
                if ((3U != (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
                    vlTOPp->bitty__DOT__en_c = 0U;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bitty__DOT__en = 0U;
    }
    if (vlTOPp->run) {
        if ((0U != (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
            if ((1U != (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
                if ((3U == (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
                    vlTOPp->bitty__DOT__en = 0U;
                    vlTOPp->bitty__DOT__en = ((IData)(vlTOPp->bitty__DOT__en) 
                                              | ((IData)(1U) 
                                                 << 
                                                 (7U 
                                                  & ((IData)(vlTOPp->bitty__DOT__instruction) 
                                                     >> 0xdU))));
                } else {
                    vlTOPp->bitty__DOT__en = 0U;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bitty__DOT__alu_sel = 0U;
    }
    if (vlTOPp->run) {
        if ((0U != (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
            if ((1U == (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
                vlTOPp->bitty__DOT__alu_sel = (7U & 
                                               ((IData)(vlTOPp->bitty__DOT__instruction) 
                                                >> 2U));
            } else {
                if ((3U != (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
                    vlTOPp->bitty__DOT__alu_sel = 0U;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->done = 0U;
    }
    if (vlTOPp->run) {
        if ((0U != (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
            if ((1U != (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
                vlTOPp->done = (3U == (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state));
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bitty__DOT__mux_sel = 0U;
    }
    if (vlTOPp->run) {
        if ((0U == (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
            vlTOPp->bitty__DOT__mux_sel = (7U & ((IData)(vlTOPp->bitty__DOT__instruction) 
                                                 >> 0xdU));
        } else {
            if ((1U == (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
                vlTOPp->bitty__DOT__mux_sel = (7U & 
                                               ((IData)(vlTOPp->bitty__DOT__instruction) 
                                                >> 0xaU));
            } else {
                if ((3U != (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
                    vlTOPp->bitty__DOT__mux_sel = 0U;
                }
            }
        }
    }
    if (vlTOPp->done) {
        vlSymsp->TOP____024unit.__Vdpiimwrap_evaluate_values_TOP____024unit(vlTOPp->bitty__DOT__instruction, (IData)(vlTOPp->d_out));
    }
    vlTOPp->bitty__DOT__cpu_inst__DOT__next_state = 
        ((0U == (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))
          ? 1U : ((1U == (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))
                   ? 3U : ((3U == (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))
                            ? ((IData)(vlTOPp->done)
                                ? 0U : 3U) : 0U)));
    vlTOPp->bitty__DOT__out_mux = ((8U & (IData)(vlTOPp->bitty__DOT__mux_sel))
                                    ? 0U : ((4U & (IData)(vlTOPp->bitty__DOT__mux_sel))
                                             ? ((2U 
                                                 & (IData)(vlTOPp->bitty__DOT__mux_sel))
                                                 ? 
                                                ((1U 
                                                  & (IData)(vlTOPp->bitty__DOT__mux_sel))
                                                  ? 
                                                 vlTOPp->bitty__DOT__out
                                                 [7U]
                                                  : 
                                                 vlTOPp->bitty__DOT__out
                                                 [6U])
                                                 : 
                                                ((1U 
                                                  & (IData)(vlTOPp->bitty__DOT__mux_sel))
                                                  ? 
                                                 vlTOPp->bitty__DOT__out
                                                 [5U]
                                                  : 
                                                 vlTOPp->bitty__DOT__out
                                                 [4U]))
                                             : ((2U 
                                                 & (IData)(vlTOPp->bitty__DOT__mux_sel))
                                                 ? 
                                                ((1U 
                                                  & (IData)(vlTOPp->bitty__DOT__mux_sel))
                                                  ? 
                                                 vlTOPp->bitty__DOT__out
                                                 [3U]
                                                  : 
                                                 vlTOPp->bitty__DOT__out
                                                 [2U])
                                                 : 
                                                ((1U 
                                                  & (IData)(vlTOPp->bitty__DOT__mux_sel))
                                                  ? 
                                                 vlTOPp->bitty__DOT__out
                                                 [1U]
                                                  : 
                                                 vlTOPp->bitty__DOT__out
                                                 [0U]))));
    vlTOPp->regb = vlTOPp->bitty__DOT__out_mux;
    vlTOPp->bitty__DOT__alu_inst__DOT__res = (0xffffU 
                                              & ((4U 
                                                  & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                                  ? 
                                                 ((2U 
                                                   & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                                   ? 
                                                  ((1U 
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
                                                     >= (IData)(vlTOPp->bitty__DOT__out_mux))
                                                     ? 
                                                    ((IData)(vlTOPp->bitty__DOT__regs) 
                                                     >> (IData)(vlTOPp->bitty__DOT__out_mux))
                                                     : 0U))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                                    ? 
                                                   ((0xfU 
                                                     >= (IData)(vlTOPp->bitty__DOT__out_mux))
                                                     ? 
                                                    ((IData)(vlTOPp->bitty__DOT__regs) 
                                                     << (IData)(vlTOPp->bitty__DOT__out_mux))
                                                     : 0U)
                                                    : 
                                                   ((IData)(vlTOPp->bitty__DOT__regs) 
                                                    ^ (IData)(vlTOPp->bitty__DOT__out_mux))))
                                                  : 
                                                 ((2U 
                                                   & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                                    ? 
                                                   ((IData)(vlTOPp->bitty__DOT__regs) 
                                                    | (IData)(vlTOPp->bitty__DOT__out_mux))
                                                    : 
                                                   ((IData)(vlTOPp->bitty__DOT__regs) 
                                                    & (IData)(vlTOPp->bitty__DOT__out_mux)))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                                    ? 
                                                   ((IData)(vlTOPp->bitty__DOT__regs) 
                                                    - (IData)(vlTOPp->bitty__DOT__out_mux))
                                                    : 
                                                   ((IData)(vlTOPp->bitty__DOT__regs) 
                                                    + (IData)(vlTOPp->bitty__DOT__out_mux))))));
}

VL_INLINE_OPT void Vbitty::_combo__TOP__4(Vbitty__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty::_combo__TOP__4\n"); );
    Vbitty* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->reset) {
        vlTOPp->done = 0U;
    }
    if (vlTOPp->run) {
        if ((0U != (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
            if ((1U != (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
                vlTOPp->done = (3U == (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state));
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bitty__DOT__en_c = 0U;
    }
    if (vlTOPp->run) {
        if ((0U != (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
            if ((1U == (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
                vlTOPp->bitty__DOT__en_c = 1U;
            } else {
                if ((3U != (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
                    vlTOPp->bitty__DOT__en_c = 0U;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bitty__DOT__en_s = 0U;
    }
    if (vlTOPp->run) {
        if ((0U == (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
            vlTOPp->bitty__DOT__en_s = 1U;
        } else {
            if ((1U != (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
                if ((3U != (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
                    vlTOPp->bitty__DOT__en_s = 0U;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bitty__DOT__en_inst = 0U;
    }
    if (vlTOPp->reset) {
        vlTOPp->bitty__DOT__alu_sel = 0U;
    }
    if (vlTOPp->run) {
        if ((0U != (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
            if ((1U == (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
                vlTOPp->bitty__DOT__alu_sel = (7U & 
                                               ((IData)(vlTOPp->bitty__DOT__instruction) 
                                                >> 2U));
            } else {
                if ((3U != (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
                    vlTOPp->bitty__DOT__alu_sel = 0U;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bitty__DOT__mux_sel = 0U;
    }
    if (vlTOPp->run) {
        if ((0U == (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
            vlTOPp->bitty__DOT__mux_sel = (7U & ((IData)(vlTOPp->bitty__DOT__instruction) 
                                                 >> 0xdU));
        } else {
            if ((1U == (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
                vlTOPp->bitty__DOT__mux_sel = (7U & 
                                               ((IData)(vlTOPp->bitty__DOT__instruction) 
                                                >> 0xaU));
            } else {
                if ((3U != (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
                    vlTOPp->bitty__DOT__mux_sel = 0U;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bitty__DOT__en = 0U;
    }
    if (vlTOPp->run) {
        if ((0U != (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
            if ((1U != (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
                if ((3U == (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
                    vlTOPp->bitty__DOT__en = 0U;
                    vlTOPp->bitty__DOT__en = ((IData)(vlTOPp->bitty__DOT__en) 
                                              | ((IData)(1U) 
                                                 << 
                                                 (7U 
                                                  & ((IData)(vlTOPp->bitty__DOT__instruction) 
                                                     >> 0xdU))));
                } else {
                    vlTOPp->bitty__DOT__en = 0U;
                }
            }
        }
    }
    if (vlTOPp->done) {
        vlSymsp->TOP____024unit.__Vdpiimwrap_evaluate_values_TOP____024unit(vlTOPp->bitty__DOT__instruction, (IData)(vlTOPp->d_out));
    }
    vlTOPp->bitty__DOT__cpu_inst__DOT__next_state = 
        ((0U == (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))
          ? 1U : ((1U == (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))
                   ? 3U : ((3U == (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))
                            ? ((IData)(vlTOPp->done)
                                ? 0U : 3U) : 0U)));
    vlTOPp->bitty__DOT__out_mux = ((8U & (IData)(vlTOPp->bitty__DOT__mux_sel))
                                    ? 0U : ((4U & (IData)(vlTOPp->bitty__DOT__mux_sel))
                                             ? ((2U 
                                                 & (IData)(vlTOPp->bitty__DOT__mux_sel))
                                                 ? 
                                                ((1U 
                                                  & (IData)(vlTOPp->bitty__DOT__mux_sel))
                                                  ? 
                                                 vlTOPp->bitty__DOT__out
                                                 [7U]
                                                  : 
                                                 vlTOPp->bitty__DOT__out
                                                 [6U])
                                                 : 
                                                ((1U 
                                                  & (IData)(vlTOPp->bitty__DOT__mux_sel))
                                                  ? 
                                                 vlTOPp->bitty__DOT__out
                                                 [5U]
                                                  : 
                                                 vlTOPp->bitty__DOT__out
                                                 [4U]))
                                             : ((2U 
                                                 & (IData)(vlTOPp->bitty__DOT__mux_sel))
                                                 ? 
                                                ((1U 
                                                  & (IData)(vlTOPp->bitty__DOT__mux_sel))
                                                  ? 
                                                 vlTOPp->bitty__DOT__out
                                                 [3U]
                                                  : 
                                                 vlTOPp->bitty__DOT__out
                                                 [2U])
                                                 : 
                                                ((1U 
                                                  & (IData)(vlTOPp->bitty__DOT__mux_sel))
                                                  ? 
                                                 vlTOPp->bitty__DOT__out
                                                 [1U]
                                                  : 
                                                 vlTOPp->bitty__DOT__out
                                                 [0U]))));
    vlTOPp->regb = vlTOPp->bitty__DOT__out_mux;
    vlTOPp->bitty__DOT__alu_inst__DOT__res = (0xffffU 
                                              & ((4U 
                                                  & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                                  ? 
                                                 ((2U 
                                                   & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                                   ? 
                                                  ((1U 
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
                                                     >= (IData)(vlTOPp->bitty__DOT__out_mux))
                                                     ? 
                                                    ((IData)(vlTOPp->bitty__DOT__regs) 
                                                     >> (IData)(vlTOPp->bitty__DOT__out_mux))
                                                     : 0U))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                                    ? 
                                                   ((0xfU 
                                                     >= (IData)(vlTOPp->bitty__DOT__out_mux))
                                                     ? 
                                                    ((IData)(vlTOPp->bitty__DOT__regs) 
                                                     << (IData)(vlTOPp->bitty__DOT__out_mux))
                                                     : 0U)
                                                    : 
                                                   ((IData)(vlTOPp->bitty__DOT__regs) 
                                                    ^ (IData)(vlTOPp->bitty__DOT__out_mux))))
                                                  : 
                                                 ((2U 
                                                   & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                                    ? 
                                                   ((IData)(vlTOPp->bitty__DOT__regs) 
                                                    | (IData)(vlTOPp->bitty__DOT__out_mux))
                                                    : 
                                                   ((IData)(vlTOPp->bitty__DOT__regs) 
                                                    & (IData)(vlTOPp->bitty__DOT__out_mux)))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                                    ? 
                                                   ((IData)(vlTOPp->bitty__DOT__regs) 
                                                    - (IData)(vlTOPp->bitty__DOT__out_mux))
                                                    : 
                                                   ((IData)(vlTOPp->bitty__DOT__regs) 
                                                    + (IData)(vlTOPp->bitty__DOT__out_mux))))));
}

void Vbitty::_eval(Vbitty__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty::_eval\n"); );
    Vbitty* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((IData)(vlTOPp->reset) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset))))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    vlTOPp->_combo__TOP__4(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
}

void Vbitty::_eval_initial(Vbitty__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty::_eval_initial\n"); );
    Vbitty* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
}

void Vbitty::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty::final\n"); );
    // Variables
    Vbitty__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vbitty* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vbitty::_eval_settle(Vbitty__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty::_eval_settle\n"); );
    Vbitty* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
}

VL_INLINE_OPT QData Vbitty::_change_request(Vbitty__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty::_change_request\n"); );
    Vbitty* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vbitty::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((run & 0xfeU))) {
        Verilated::overWidthError("run");}
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG

void Vbitty::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty::_ctor_var_reset\n"); );
    // Body
    run = VL_RAND_RESET_I(1);
    clk = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    d_instr = VL_RAND_RESET_I(16);
    d_out = VL_RAND_RESET_I(16);
    rega = VL_RAND_RESET_I(16);
    regb = VL_RAND_RESET_I(16);
    done = VL_RAND_RESET_I(1);
    bitty__DOT__mux_sel = VL_RAND_RESET_I(4);
    bitty__DOT__en = VL_RAND_RESET_I(8);
    { int __Vi0=0; for (; __Vi0<8; ++__Vi0) {
            bitty__DOT__out[__Vi0] = VL_RAND_RESET_I(16);
    }}
    bitty__DOT__out_mux = VL_RAND_RESET_I(16);
    bitty__DOT__en_s = VL_RAND_RESET_I(1);
    bitty__DOT__en_c = VL_RAND_RESET_I(1);
    bitty__DOT__en_inst = VL_RAND_RESET_I(1);
    bitty__DOT__alu_sel = VL_RAND_RESET_I(3);
    bitty__DOT__instruction = VL_RAND_RESET_I(16);
    bitty__DOT__regs = VL_RAND_RESET_I(16);
    bitty__DOT__regc = VL_RAND_RESET_I(16);
    bitty__DOT____Vcellout__genblk1__BRA__0__KET____DOT__reg_out__mux_out = VL_RAND_RESET_I(16);
    bitty__DOT____Vcellout__genblk1__BRA__1__KET____DOT__reg_out__mux_out = VL_RAND_RESET_I(16);
    bitty__DOT____Vcellout__genblk1__BRA__2__KET____DOT__reg_out__mux_out = VL_RAND_RESET_I(16);
    bitty__DOT____Vcellout__genblk1__BRA__3__KET____DOT__reg_out__mux_out = VL_RAND_RESET_I(16);
    bitty__DOT____Vcellout__genblk1__BRA__4__KET____DOT__reg_out__mux_out = VL_RAND_RESET_I(16);
    bitty__DOT____Vcellout__genblk1__BRA__5__KET____DOT__reg_out__mux_out = VL_RAND_RESET_I(16);
    bitty__DOT____Vcellout__genblk1__BRA__6__KET____DOT__reg_out__mux_out = VL_RAND_RESET_I(16);
    bitty__DOT____Vcellout__genblk1__BRA__7__KET____DOT__reg_out__mux_out = VL_RAND_RESET_I(16);
    bitty__DOT__cpu_inst__DOT__cur_state = VL_RAND_RESET_I(2);
    bitty__DOT__cpu_inst__DOT__next_state = VL_RAND_RESET_I(2);
    bitty__DOT__alu_inst__DOT__res = VL_RAND_RESET_I(16);
}
