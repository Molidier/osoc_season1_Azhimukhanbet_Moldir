// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbitty.h for the primary calling header

#include "Vbitty.h"
#include "Vbitty__Syms.h"

//==========
CData/*1:0*/ Vbitty::__Vtable1_bitty__DOT__cpu_inst__DOT__next_state[8];

VL_CTOR_IMP(Vbitty) {
    Vbitty__Syms* __restrict vlSymsp = __VlSymsp = new Vbitty__Syms(this, name());
    Vbitty* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("bitty.sv", 3, "",
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
    vlSymsp->__Vm_activity = true;
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
            VL_FATAL_MT("bitty.sv", 3, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vbitty::_initial__TOP__1(Vbitty__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty::_initial__TOP__1\n"); );
    Vbitty* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->bitty__DOT__alu_inst__DOT__car_arith = 0U;
}

VL_INLINE_OPT void Vbitty::_sequent__TOP__2(Vbitty__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty::_sequent__TOP__2\n"); );
    Vbitty* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->bitty__DOT__en_s) {
        vlTOPp->regs = vlTOPp->bitty__DOT__out_mux;
    }
    if ((0x80U & (IData)(vlTOPp->bitty__DOT__en))) {
        vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__7__KET____DOT__reg_out__mux_out 
            = vlTOPp->regc;
    }
    if ((0x40U & (IData)(vlTOPp->bitty__DOT__en))) {
        vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__6__KET____DOT__reg_out__mux_out 
            = vlTOPp->regc;
    }
    if ((0x20U & (IData)(vlTOPp->bitty__DOT__en))) {
        vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__5__KET____DOT__reg_out__mux_out 
            = vlTOPp->regc;
    }
    if ((0x10U & (IData)(vlTOPp->bitty__DOT__en))) {
        vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__4__KET____DOT__reg_out__mux_out 
            = vlTOPp->regc;
    }
    if ((8U & (IData)(vlTOPp->bitty__DOT__en))) {
        vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__3__KET____DOT__reg_out__mux_out 
            = vlTOPp->regc;
    }
    if ((4U & (IData)(vlTOPp->bitty__DOT__en))) {
        vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__2__KET____DOT__reg_out__mux_out 
            = vlTOPp->regc;
    }
    if ((2U & (IData)(vlTOPp->bitty__DOT__en))) {
        vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__1__KET____DOT__reg_out__mux_out 
            = vlTOPp->regc;
    }
    if ((1U & (IData)(vlTOPp->bitty__DOT__en))) {
        vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__0__KET____DOT__reg_out__mux_out 
            = vlTOPp->regc;
    }
    if (vlTOPp->bitty__DOT__en_inst) {
        vlTOPp->bitty__DOT__instruction = vlTOPp->d_instr;
    }
    vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state = 
        ((IData)(vlTOPp->reset) ? 0U : (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__next_state));
    vlTOPp->bitty__DOT__out[7U] = vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__7__KET____DOT__reg_out__mux_out;
    vlTOPp->bitty__DOT__out[6U] = vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__6__KET____DOT__reg_out__mux_out;
    vlTOPp->bitty__DOT__out[5U] = vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__5__KET____DOT__reg_out__mux_out;
    vlTOPp->bitty__DOT__out[4U] = vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__4__KET____DOT__reg_out__mux_out;
    vlTOPp->bitty__DOT__out[3U] = vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__3__KET____DOT__reg_out__mux_out;
    vlTOPp->bitty__DOT__out[2U] = vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__2__KET____DOT__reg_out__mux_out;
    vlTOPp->bitty__DOT__out[1U] = vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__1__KET____DOT__reg_out__mux_out;
    if (vlTOPp->bitty__DOT__en_c) {
        vlTOPp->regc = vlTOPp->bitty__DOT__alu_inst__DOT__res;
    }
    vlTOPp->bitty__DOT__out[0U] = vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__0__KET____DOT__reg_out__mux_out;
    vlTOPp->reg0 = vlTOPp->bitty__DOT__out[0U];
    vlTOPp->reg1 = vlTOPp->bitty__DOT__out[1U];
    vlTOPp->reg2 = vlTOPp->bitty__DOT__out[2U];
    vlTOPp->reg3 = vlTOPp->bitty__DOT__out[3U];
    vlTOPp->reg4 = vlTOPp->bitty__DOT__out[4U];
    vlTOPp->reg5 = vlTOPp->bitty__DOT__out[5U];
    vlTOPp->reg6 = vlTOPp->bitty__DOT__out[6U];
    vlTOPp->reg7 = vlTOPp->bitty__DOT__out[7U];
}

VL_INLINE_OPT void Vbitty::_sequent__TOP__3(Vbitty__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty::_sequent__TOP__3\n"); );
    Vbitty* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->reset) | (IData)(vlTOPp->done))) {
        vlTOPp->reg3 = 0U;
    }
    if (((IData)(vlTOPp->reset) | (IData)(vlTOPp->done))) {
        vlTOPp->reg2 = 0U;
    }
    if (((IData)(vlTOPp->reset) | (IData)(vlTOPp->done))) {
        vlTOPp->reg1 = 0U;
    }
    if (((IData)(vlTOPp->reset) | (IData)(vlTOPp->done))) {
        vlTOPp->reg4 = 0U;
    }
    if (((IData)(vlTOPp->reset) | (IData)(vlTOPp->done))) {
        vlTOPp->reg0 = 0U;
    }
    if (((IData)(vlTOPp->reset) | (IData)(vlTOPp->done))) {
        vlTOPp->reg5 = 0U;
    }
    if (((IData)(vlTOPp->reset) | (IData)(vlTOPp->done))) {
        vlTOPp->reg6 = 0U;
    }
    if (((IData)(vlTOPp->reset) | (IData)(vlTOPp->done))) {
        vlTOPp->reg7 = 0U;
    }
    if (((IData)(vlTOPp->reset) | (IData)(vlTOPp->done))) {
        vlTOPp->bitty__DOT__en = 0U;
    }
}

void Vbitty::_settle__TOP__4(Vbitty__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty::_settle__TOP__4\n"); );
    Vbitty* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->bitty__DOT__en_inst = 0U;
    if (vlTOPp->reset) {
        vlTOPp->bitty__DOT__en_inst = 0U;
    }
    if (vlTOPp->run) {
        vlTOPp->bitty__DOT__en_inst = 1U;
        if ((0U == (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
            vlTOPp->bitty__DOT__en_inst = 0U;
        } else {
            if ((1U == (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
                vlTOPp->bitty__DOT__en_inst = 0U;
            } else {
                if ((3U == (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
                    vlTOPp->bitty__DOT__en_inst = 0U;
                }
            }
        }
    }
    vlTOPp->bitty__DOT__en_s = 0U;
    if (vlTOPp->reset) {
        vlTOPp->bitty__DOT__en_s = 0U;
    }
    if (vlTOPp->run) {
        if ((0U == (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
            vlTOPp->bitty__DOT__en_s = 1U;
        } else {
            if ((1U == (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
                vlTOPp->bitty__DOT__en_s = 0U;
            } else {
                if ((3U != (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
                    vlTOPp->bitty__DOT__en_s = 0U;
                }
            }
        }
    }
    vlTOPp->done = 0U;
    if (vlTOPp->reset) {
        vlTOPp->done = 0U;
    }
    if (vlTOPp->run) {
        vlTOPp->done = ((0U != (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state)) 
                        & ((1U != (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state)) 
                           & (3U == (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))));
    }
    vlTOPp->bitty__DOT__en = 0U;
    if (vlTOPp->reset) {
        vlTOPp->bitty__DOT__en = 0U;
    }
    if (vlTOPp->run) {
        if ((0U == (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
            vlTOPp->bitty__DOT__en = 0U;
        } else {
            if ((1U == (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
                vlTOPp->bitty__DOT__en = 0U;
            } else {
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
    vlTOPp->__Vtableidx1 = (((IData)(vlTOPp->run) << 2U) 
                            | (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state));
    vlTOPp->bitty__DOT__cpu_inst__DOT__next_state = 
        vlTOPp->__Vtable1_bitty__DOT__cpu_inst__DOT__next_state
        [vlTOPp->__Vtableidx1];
    vlTOPp->bitty__DOT__mode = 0U;
    if (vlTOPp->reset) {
        vlTOPp->bitty__DOT__mode = 0U;
    }
    if (vlTOPp->run) {
        if ((0U != (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
            if ((1U == (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
                vlTOPp->bitty__DOT__mode = (1U & ((IData)(vlTOPp->bitty__DOT__instruction) 
                                                  >> 2U));
            } else {
                if ((3U != (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
                    vlTOPp->bitty__DOT__mode = 0U;
                }
            }
        }
    }
    vlTOPp->bitty__DOT__alu_sel = 0U;
    if (vlTOPp->reset) {
        vlTOPp->bitty__DOT__alu_sel = 0U;
    }
    if (vlTOPp->run) {
        if ((0U != (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
            if ((1U == (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
                vlTOPp->bitty__DOT__alu_sel = (0xfU 
                                               & ((IData)(vlTOPp->bitty__DOT__instruction) 
                                                  >> 3U));
            } else {
                if ((3U != (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
                    vlTOPp->bitty__DOT__alu_sel = 0U;
                }
            }
        }
    }
    vlTOPp->bitty__DOT__mux_sel = 0U;
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
    vlTOPp->bitty__DOT__out[0U] = vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__0__KET____DOT__reg_out__mux_out;
    vlTOPp->bitty__DOT__out[1U] = vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__1__KET____DOT__reg_out__mux_out;
    vlTOPp->bitty__DOT__out[2U] = vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__2__KET____DOT__reg_out__mux_out;
    vlTOPp->bitty__DOT__out[3U] = vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__3__KET____DOT__reg_out__mux_out;
    vlTOPp->bitty__DOT__out[4U] = vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__4__KET____DOT__reg_out__mux_out;
    vlTOPp->bitty__DOT__out[5U] = vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__5__KET____DOT__reg_out__mux_out;
    vlTOPp->bitty__DOT__out[6U] = vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__6__KET____DOT__reg_out__mux_out;
    vlTOPp->bitty__DOT__out[7U] = vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__7__KET____DOT__reg_out__mux_out;
    vlTOPp->bitty__DOT__en_c = 0U;
    if (vlTOPp->reset) {
        vlTOPp->bitty__DOT__en_c = 0U;
    }
    if (vlTOPp->run) {
        if ((0U == (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
            vlTOPp->bitty__DOT__en_c = 0U;
        } else {
            if ((1U == (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
                vlTOPp->bitty__DOT__en_c = 1U;
            } else {
                if ((3U != (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
                    vlTOPp->bitty__DOT__en_c = 0U;
                }
            }
        }
    }
    vlTOPp->reg0 = vlTOPp->bitty__DOT__out[0U];
    vlTOPp->reg1 = vlTOPp->bitty__DOT__out[1U];
    vlTOPp->reg2 = vlTOPp->bitty__DOT__out[2U];
    vlTOPp->reg3 = vlTOPp->bitty__DOT__out[3U];
    vlTOPp->reg4 = vlTOPp->bitty__DOT__out[4U];
    vlTOPp->reg5 = vlTOPp->bitty__DOT__out[5U];
    vlTOPp->reg6 = vlTOPp->bitty__DOT__out[6U];
    vlTOPp->reg7 = vlTOPp->bitty__DOT__out[7U];
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
    vlTOPp->bitty__DOT__alu_inst__DOT__u1__DOT__res 
        = (0xffffU & ((8U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                       ? ((4U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                           ? ((2U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                               ? ((1U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                   ? (IData)(vlTOPp->regs)
                                   : ((IData)(vlTOPp->regs) 
                                      | (IData)(vlTOPp->bitty__DOT__out_mux)))
                               : ((1U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                   ? ((IData)(vlTOPp->regs) 
                                      | (~ (IData)(vlTOPp->bitty__DOT__out_mux)))
                                   : 1U)) : ((2U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                              ? ((1U 
                                                  & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                                  ? 
                                                 ((IData)(vlTOPp->regs) 
                                                  & (IData)(vlTOPp->bitty__DOT__out_mux))
                                                  : (IData)(vlTOPp->bitty__DOT__out_mux))
                                              : ((1U 
                                                  & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                                  ? 
                                                 (~ 
                                                  ((IData)(vlTOPp->regs) 
                                                   ^ (IData)(vlTOPp->bitty__DOT__out_mux)))
                                                  : 
                                                 ((~ (IData)(vlTOPp->regs)) 
                                                  | (IData)(vlTOPp->bitty__DOT__out_mux)))))
                       : ((4U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                           ? ((2U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                               ? ((1U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                   ? ((IData)(vlTOPp->regs) 
                                      & (~ (IData)(vlTOPp->bitty__DOT__out_mux)))
                                   : ((IData)(vlTOPp->regs) 
                                      ^ (IData)(vlTOPp->bitty__DOT__out_mux)))
                               : ((1U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                   ? (~ (IData)(vlTOPp->bitty__DOT__out_mux))
                                   : (~ ((IData)(vlTOPp->regs) 
                                         & (IData)(vlTOPp->bitty__DOT__out_mux)))))
                           : ((2U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                               ? ((1U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                   ? 0U : ((~ (IData)(vlTOPp->regs)) 
                                           & (IData)(vlTOPp->bitty__DOT__out_mux)))
                               : ((1U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                   ? (~ ((IData)(vlTOPp->regs) 
                                         | (IData)(vlTOPp->bitty__DOT__out_mux)))
                                   : (~ (IData)(vlTOPp->regs)))))));
    vlTOPp->bitty__DOT__alu_inst__DOT__u2__DOT__extended_res 
        = (0x1ffffU & ((8U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                        ? ((4U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                            ? ((2U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                ? ((1U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                    ? ((IData)(vlTOPp->regs) 
                                       + (IData)(vlTOPp->carry_in))
                                    : (((0xffffU & 
                                         ((IData)(vlTOPp->regs) 
                                          | (~ (IData)(vlTOPp->bitty__DOT__out_mux)))) 
                                        + (IData)(vlTOPp->regs)) 
                                       + (IData)(vlTOPp->carry_in)))
                                : ((1U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                    ? ((((IData)(vlTOPp->regs) 
                                         | (IData)(vlTOPp->bitty__DOT__out_mux)) 
                                        + (IData)(vlTOPp->regs)) 
                                       + (IData)(vlTOPp->carry_in))
                                    : (((IData)(vlTOPp->regs) 
                                        + (IData)(vlTOPp->regs)) 
                                       + (IData)(vlTOPp->carry_in))))
                            : ((2U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                ? ((1U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                    ? ((IData)(vlTOPp->regs) 
                                       & (IData)(vlTOPp->bitty__DOT__out_mux))
                                    : (((0xffffU & 
                                         ((IData)(vlTOPp->regs) 
                                          | (~ (IData)(vlTOPp->bitty__DOT__out_mux)))) 
                                        + ((IData)(vlTOPp->regs) 
                                           & (IData)(vlTOPp->bitty__DOT__out_mux))) 
                                       + (IData)(vlTOPp->carry_in)))
                                : ((1U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                    ? (((IData)(vlTOPp->regs) 
                                        + (IData)(vlTOPp->bitty__DOT__out_mux)) 
                                       + (IData)(vlTOPp->carry_in))
                                    : (((IData)(vlTOPp->regs) 
                                        + ((IData)(vlTOPp->regs) 
                                           & (IData)(vlTOPp->bitty__DOT__out_mux))) 
                                       + (IData)(vlTOPp->carry_in)))))
                        : ((4U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                            ? ((2U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                ? ((1U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                    ? ((IData)(vlTOPp->regs) 
                                       & (~ (IData)(vlTOPp->bitty__DOT__out_mux)))
                                    : ((IData)(vlTOPp->regs) 
                                       + (0xffffU & 
                                          (~ (IData)(vlTOPp->bitty__DOT__out_mux)))))
                                : ((1U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                    ? ((0xffffU & (
                                                   ((IData)(vlTOPp->regs) 
                                                    | (IData)(vlTOPp->bitty__DOT__out_mux)) 
                                                   + 
                                                   ((IData)(vlTOPp->regs) 
                                                    & (~ (IData)(vlTOPp->bitty__DOT__out_mux))))) 
                                       + (IData)(vlTOPp->carry_in))
                                    : ((IData)(vlTOPp->regs) 
                                       | (0xffffU & 
                                          ((IData)(vlTOPp->regs) 
                                           & (~ (IData)(vlTOPp->bitty__DOT__out_mux)))))))
                            : ((2U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                ? ((1U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                    ? 0x1ffffU : ((IData)(vlTOPp->regs) 
                                                  | (0xffffU 
                                                     & (~ (IData)(vlTOPp->bitty__DOT__out_mux)))))
                                : ((1U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                    ? ((IData)(vlTOPp->regs) 
                                       | (IData)(vlTOPp->bitty__DOT__out_mux))
                                    : (IData)(vlTOPp->regs))))));
    vlTOPp->bitty__DOT__alu_inst__DOT__res = (0xffffU 
                                              & ((IData)(vlTOPp->bitty__DOT__mode)
                                                  ? (IData)(vlTOPp->bitty__DOT__alu_inst__DOT__u1__DOT__res)
                                                  : vlTOPp->bitty__DOT__alu_inst__DOT__u2__DOT__extended_res));
    vlTOPp->bitty__DOT__alu_inst__DOT__car_arith = 
        (1U & (vlTOPp->bitty__DOT__alu_inst__DOT__u2__DOT__extended_res 
               >> 0x10U));
    vlTOPp->d_out = vlTOPp->bitty__DOT__alu_inst__DOT__res;
    vlTOPp->bitty__DOT__alu_inst__DOT__car_out = ((~ (IData)(vlTOPp->bitty__DOT__mode)) 
                                                  & (IData)(vlTOPp->bitty__DOT__alu_inst__DOT__car_arith));
    vlTOPp->carry_out = vlTOPp->bitty__DOT__alu_inst__DOT__car_out;
}

VL_INLINE_OPT void Vbitty::_combo__TOP__5(Vbitty__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty::_combo__TOP__5\n"); );
    Vbitty* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->bitty__DOT__en_inst = 0U;
    if (vlTOPp->reset) {
        vlTOPp->bitty__DOT__en_inst = 0U;
    }
    if (vlTOPp->run) {
        vlTOPp->bitty__DOT__en_inst = 1U;
        if ((0U == (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
            vlTOPp->bitty__DOT__en_inst = 0U;
        } else {
            if ((1U == (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
                vlTOPp->bitty__DOT__en_inst = 0U;
            } else {
                if ((3U == (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
                    vlTOPp->bitty__DOT__en_inst = 0U;
                }
            }
        }
    }
    vlTOPp->bitty__DOT__en_s = 0U;
    if (vlTOPp->reset) {
        vlTOPp->bitty__DOT__en_s = 0U;
    }
    if (vlTOPp->run) {
        if ((0U == (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
            vlTOPp->bitty__DOT__en_s = 1U;
        } else {
            if ((1U == (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
                vlTOPp->bitty__DOT__en_s = 0U;
            } else {
                if ((3U != (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
                    vlTOPp->bitty__DOT__en_s = 0U;
                }
            }
        }
    }
    vlTOPp->bitty__DOT__en = 0U;
    if (vlTOPp->reset) {
        vlTOPp->bitty__DOT__en = 0U;
    }
    if (vlTOPp->run) {
        if ((0U == (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
            vlTOPp->bitty__DOT__en = 0U;
        } else {
            if ((1U == (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
                vlTOPp->bitty__DOT__en = 0U;
            } else {
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
    vlTOPp->__Vtableidx1 = (((IData)(vlTOPp->run) << 2U) 
                            | (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state));
    vlTOPp->bitty__DOT__cpu_inst__DOT__next_state = 
        vlTOPp->__Vtable1_bitty__DOT__cpu_inst__DOT__next_state
        [vlTOPp->__Vtableidx1];
    vlTOPp->bitty__DOT__mode = 0U;
    if (vlTOPp->reset) {
        vlTOPp->bitty__DOT__mode = 0U;
    }
    if (vlTOPp->run) {
        if ((0U != (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
            if ((1U == (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
                vlTOPp->bitty__DOT__mode = (1U & ((IData)(vlTOPp->bitty__DOT__instruction) 
                                                  >> 2U));
            } else {
                if ((3U != (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
                    vlTOPp->bitty__DOT__mode = 0U;
                }
            }
        }
    }
    vlTOPp->bitty__DOT__alu_sel = 0U;
    if (vlTOPp->reset) {
        vlTOPp->bitty__DOT__alu_sel = 0U;
    }
    if (vlTOPp->run) {
        if ((0U != (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
            if ((1U == (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
                vlTOPp->bitty__DOT__alu_sel = (0xfU 
                                               & ((IData)(vlTOPp->bitty__DOT__instruction) 
                                                  >> 3U));
            } else {
                if ((3U != (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
                    vlTOPp->bitty__DOT__alu_sel = 0U;
                }
            }
        }
    }
    vlTOPp->bitty__DOT__mux_sel = 0U;
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
    vlTOPp->bitty__DOT__en_c = 0U;
    if (vlTOPp->reset) {
        vlTOPp->bitty__DOT__en_c = 0U;
    }
    if (vlTOPp->run) {
        if ((0U == (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
            vlTOPp->bitty__DOT__en_c = 0U;
        } else {
            if ((1U == (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
                vlTOPp->bitty__DOT__en_c = 1U;
            } else {
                if ((3U != (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
                    vlTOPp->bitty__DOT__en_c = 0U;
                }
            }
        }
    }
    vlTOPp->done = 0U;
    if (vlTOPp->reset) {
        vlTOPp->done = 0U;
    }
    if (vlTOPp->run) {
        vlTOPp->done = ((0U != (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state)) 
                        & ((1U != (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state)) 
                           & (3U == (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))));
    }
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
    vlTOPp->bitty__DOT__alu_inst__DOT__u1__DOT__res 
        = (0xffffU & ((8U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                       ? ((4U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                           ? ((2U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                               ? ((1U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                   ? (IData)(vlTOPp->regs)
                                   : ((IData)(vlTOPp->regs) 
                                      | (IData)(vlTOPp->bitty__DOT__out_mux)))
                               : ((1U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                   ? ((IData)(vlTOPp->regs) 
                                      | (~ (IData)(vlTOPp->bitty__DOT__out_mux)))
                                   : 1U)) : ((2U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                              ? ((1U 
                                                  & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                                  ? 
                                                 ((IData)(vlTOPp->regs) 
                                                  & (IData)(vlTOPp->bitty__DOT__out_mux))
                                                  : (IData)(vlTOPp->bitty__DOT__out_mux))
                                              : ((1U 
                                                  & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                                  ? 
                                                 (~ 
                                                  ((IData)(vlTOPp->regs) 
                                                   ^ (IData)(vlTOPp->bitty__DOT__out_mux)))
                                                  : 
                                                 ((~ (IData)(vlTOPp->regs)) 
                                                  | (IData)(vlTOPp->bitty__DOT__out_mux)))))
                       : ((4U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                           ? ((2U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                               ? ((1U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                   ? ((IData)(vlTOPp->regs) 
                                      & (~ (IData)(vlTOPp->bitty__DOT__out_mux)))
                                   : ((IData)(vlTOPp->regs) 
                                      ^ (IData)(vlTOPp->bitty__DOT__out_mux)))
                               : ((1U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                   ? (~ (IData)(vlTOPp->bitty__DOT__out_mux))
                                   : (~ ((IData)(vlTOPp->regs) 
                                         & (IData)(vlTOPp->bitty__DOT__out_mux)))))
                           : ((2U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                               ? ((1U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                   ? 0U : ((~ (IData)(vlTOPp->regs)) 
                                           & (IData)(vlTOPp->bitty__DOT__out_mux)))
                               : ((1U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                   ? (~ ((IData)(vlTOPp->regs) 
                                         | (IData)(vlTOPp->bitty__DOT__out_mux)))
                                   : (~ (IData)(vlTOPp->regs)))))));
    vlTOPp->bitty__DOT__alu_inst__DOT__u2__DOT__extended_res 
        = (0x1ffffU & ((8U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                        ? ((4U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                            ? ((2U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                ? ((1U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                    ? ((IData)(vlTOPp->regs) 
                                       + (IData)(vlTOPp->carry_in))
                                    : (((0xffffU & 
                                         ((IData)(vlTOPp->regs) 
                                          | (~ (IData)(vlTOPp->bitty__DOT__out_mux)))) 
                                        + (IData)(vlTOPp->regs)) 
                                       + (IData)(vlTOPp->carry_in)))
                                : ((1U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                    ? ((((IData)(vlTOPp->regs) 
                                         | (IData)(vlTOPp->bitty__DOT__out_mux)) 
                                        + (IData)(vlTOPp->regs)) 
                                       + (IData)(vlTOPp->carry_in))
                                    : (((IData)(vlTOPp->regs) 
                                        + (IData)(vlTOPp->regs)) 
                                       + (IData)(vlTOPp->carry_in))))
                            : ((2U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                ? ((1U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                    ? ((IData)(vlTOPp->regs) 
                                       & (IData)(vlTOPp->bitty__DOT__out_mux))
                                    : (((0xffffU & 
                                         ((IData)(vlTOPp->regs) 
                                          | (~ (IData)(vlTOPp->bitty__DOT__out_mux)))) 
                                        + ((IData)(vlTOPp->regs) 
                                           & (IData)(vlTOPp->bitty__DOT__out_mux))) 
                                       + (IData)(vlTOPp->carry_in)))
                                : ((1U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                    ? (((IData)(vlTOPp->regs) 
                                        + (IData)(vlTOPp->bitty__DOT__out_mux)) 
                                       + (IData)(vlTOPp->carry_in))
                                    : (((IData)(vlTOPp->regs) 
                                        + ((IData)(vlTOPp->regs) 
                                           & (IData)(vlTOPp->bitty__DOT__out_mux))) 
                                       + (IData)(vlTOPp->carry_in)))))
                        : ((4U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                            ? ((2U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                ? ((1U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                    ? ((IData)(vlTOPp->regs) 
                                       & (~ (IData)(vlTOPp->bitty__DOT__out_mux)))
                                    : ((IData)(vlTOPp->regs) 
                                       + (0xffffU & 
                                          (~ (IData)(vlTOPp->bitty__DOT__out_mux)))))
                                : ((1U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                    ? ((0xffffU & (
                                                   ((IData)(vlTOPp->regs) 
                                                    | (IData)(vlTOPp->bitty__DOT__out_mux)) 
                                                   + 
                                                   ((IData)(vlTOPp->regs) 
                                                    & (~ (IData)(vlTOPp->bitty__DOT__out_mux))))) 
                                       + (IData)(vlTOPp->carry_in))
                                    : ((IData)(vlTOPp->regs) 
                                       | (0xffffU & 
                                          ((IData)(vlTOPp->regs) 
                                           & (~ (IData)(vlTOPp->bitty__DOT__out_mux)))))))
                            : ((2U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                ? ((1U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                    ? 0x1ffffU : ((IData)(vlTOPp->regs) 
                                                  | (0xffffU 
                                                     & (~ (IData)(vlTOPp->bitty__DOT__out_mux)))))
                                : ((1U & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                    ? ((IData)(vlTOPp->regs) 
                                       | (IData)(vlTOPp->bitty__DOT__out_mux))
                                    : (IData)(vlTOPp->regs))))));
    vlTOPp->bitty__DOT__alu_inst__DOT__res = (0xffffU 
                                              & ((IData)(vlTOPp->bitty__DOT__mode)
                                                  ? (IData)(vlTOPp->bitty__DOT__alu_inst__DOT__u1__DOT__res)
                                                  : vlTOPp->bitty__DOT__alu_inst__DOT__u2__DOT__extended_res));
    vlTOPp->bitty__DOT__alu_inst__DOT__car_arith = 
        (1U & (vlTOPp->bitty__DOT__alu_inst__DOT__u2__DOT__extended_res 
               >> 0x10U));
    vlTOPp->d_out = vlTOPp->bitty__DOT__alu_inst__DOT__res;
    vlTOPp->bitty__DOT__alu_inst__DOT__car_out = ((~ (IData)(vlTOPp->bitty__DOT__mode)) 
                                                  & (IData)(vlTOPp->bitty__DOT__alu_inst__DOT__car_arith));
    vlTOPp->carry_out = vlTOPp->bitty__DOT__alu_inst__DOT__car_out;
}

void Vbitty::_eval(Vbitty__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty::_eval\n"); );
    Vbitty* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
        vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    }
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((IData)(vlTOPp->reset) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset))))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
        vlTOPp->__Vm_traceActivity = (4U | vlTOPp->__Vm_traceActivity);
    }
    vlTOPp->_combo__TOP__5(vlSymsp);
    vlTOPp->__Vm_traceActivity = (8U | vlTOPp->__Vm_traceActivity);
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
}

void Vbitty::_eval_initial(Vbitty__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty::_eval_initial\n"); );
    Vbitty* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
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
    vlTOPp->_settle__TOP__4(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
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
    if (VL_UNLIKELY((carry_in & 0xfeU))) {
        Verilated::overWidthError("carry_in");}
}
#endif  // VL_DEBUG

void Vbitty::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty::_ctor_var_reset\n"); );
    // Body
    run = VL_RAND_RESET_I(1);
    clk = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    d_instr = VL_RAND_RESET_I(16);
    carry_in = VL_RAND_RESET_I(1);
    reg0 = VL_RAND_RESET_I(16);
    reg1 = VL_RAND_RESET_I(16);
    reg2 = VL_RAND_RESET_I(16);
    reg3 = VL_RAND_RESET_I(16);
    reg4 = VL_RAND_RESET_I(16);
    reg5 = VL_RAND_RESET_I(16);
    reg6 = VL_RAND_RESET_I(16);
    reg7 = VL_RAND_RESET_I(16);
    regs = VL_RAND_RESET_I(16);
    regc = VL_RAND_RESET_I(16);
    d_out = VL_RAND_RESET_I(16);
    carry_out = VL_RAND_RESET_I(1);
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
    bitty__DOT__mode = VL_RAND_RESET_I(1);
    bitty__DOT__alu_sel = VL_RAND_RESET_I(4);
    bitty__DOT__instruction = VL_RAND_RESET_I(16);
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
    bitty__DOT__alu_inst__DOT__car_out = VL_RAND_RESET_I(1);
    bitty__DOT__alu_inst__DOT__car_arith = VL_RAND_RESET_I(1);
    bitty__DOT__alu_inst__DOT__u1__DOT__res = VL_RAND_RESET_I(16);
    bitty__DOT__alu_inst__DOT__u2__DOT__extended_res = VL_RAND_RESET_I(17);
    __Vtableidx1 = 0;
    __Vtable1_bitty__DOT__cpu_inst__DOT__next_state[0] = 0U;
    __Vtable1_bitty__DOT__cpu_inst__DOT__next_state[1] = 0U;
    __Vtable1_bitty__DOT__cpu_inst__DOT__next_state[2] = 0U;
    __Vtable1_bitty__DOT__cpu_inst__DOT__next_state[3] = 3U;
    __Vtable1_bitty__DOT__cpu_inst__DOT__next_state[4] = 1U;
    __Vtable1_bitty__DOT__cpu_inst__DOT__next_state[5] = 3U;
    __Vtable1_bitty__DOT__cpu_inst__DOT__next_state[6] = 0U;
    __Vtable1_bitty__DOT__cpu_inst__DOT__next_state[7] = 0U;
    __Vm_traceActivity = 0;
}
