// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbitty.h for the primary calling header

#include "Vbitty.h"
#include "Vbitty__Syms.h"

#include "verilated_dpi.h"

//==========
CData/*1:0*/ Vbitty::__Vtable1_bitty__DOT__cpu_inst__DOT__next_state[32];

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
        vlSymsp->__Vm_activity = true;
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
    if (vlTOPp->reset) {
        vlTOPp->bitty__DOT__regs = 0U;
    } else {
        if (vlTOPp->bitty__DOT__en_s) {
            vlTOPp->bitty__DOT__regs = vlTOPp->bitty__DOT__out_mux;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bitty__DOT__instruction = 0U;
    } else {
        if (vlTOPp->bitty__DOT__en_inst) {
            vlTOPp->bitty__DOT__instruction = vlTOPp->d_instr;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__0__KET____DOT__reg_out__mux_out = 0xaU;
    } else {
        if ((1U & (IData)(vlTOPp->bitty__DOT__en))) {
            vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__0__KET____DOT__reg_out__mux_out 
                = vlTOPp->bitty__DOT__regc;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__1__KET____DOT__reg_out__mux_out = 0xaU;
    } else {
        if ((2U & (IData)(vlTOPp->bitty__DOT__en))) {
            vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__1__KET____DOT__reg_out__mux_out 
                = vlTOPp->bitty__DOT__regc;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__2__KET____DOT__reg_out__mux_out = 0xaU;
    } else {
        if ((4U & (IData)(vlTOPp->bitty__DOT__en))) {
            vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__2__KET____DOT__reg_out__mux_out 
                = vlTOPp->bitty__DOT__regc;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__3__KET____DOT__reg_out__mux_out = 0xaU;
    } else {
        if ((8U & (IData)(vlTOPp->bitty__DOT__en))) {
            vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__3__KET____DOT__reg_out__mux_out 
                = vlTOPp->bitty__DOT__regc;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__4__KET____DOT__reg_out__mux_out = 0xaU;
    } else {
        if ((0x10U & (IData)(vlTOPp->bitty__DOT__en))) {
            vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__4__KET____DOT__reg_out__mux_out 
                = vlTOPp->bitty__DOT__regc;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__5__KET____DOT__reg_out__mux_out = 0xaU;
    } else {
        if ((0x20U & (IData)(vlTOPp->bitty__DOT__en))) {
            vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__5__KET____DOT__reg_out__mux_out 
                = vlTOPp->bitty__DOT__regc;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__6__KET____DOT__reg_out__mux_out = 0xaU;
    } else {
        if ((0x40U & (IData)(vlTOPp->bitty__DOT__en))) {
            vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__6__KET____DOT__reg_out__mux_out 
                = vlTOPp->bitty__DOT__regc;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__7__KET____DOT__reg_out__mux_out = 0xaU;
    } else {
        if ((0x80U & (IData)(vlTOPp->bitty__DOT__en))) {
            vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__7__KET____DOT__reg_out__mux_out 
                = vlTOPp->bitty__DOT__regc;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bitty__DOT__regc = 0U;
    } else {
        if (vlTOPp->bitty__DOT__en_c) {
            vlTOPp->bitty__DOT__regc = (0xffffU & (
                                                   (4U 
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
                                                       >= 
                                                       (0x1fU 
                                                        & (IData)(vlTOPp->bitty__DOT__out_mux)))
                                                       ? 
                                                      ((IData)(vlTOPp->bitty__DOT__regs) 
                                                       >> 
                                                       (0x1fU 
                                                        & (IData)(vlTOPp->bitty__DOT__out_mux)))
                                                       : 0U))
                                                     : 
                                                    ((1U 
                                                      & (IData)(vlTOPp->bitty__DOT__alu_sel))
                                                      ? 
                                                     ((0xfU 
                                                       >= 
                                                       (0x1fU 
                                                        & (IData)(vlTOPp->bitty__DOT__out_mux)))
                                                       ? 
                                                      ((IData)(vlTOPp->bitty__DOT__regs) 
                                                       << 
                                                       (0x1fU 
                                                        & (IData)(vlTOPp->bitty__DOT__out_mux)))
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
    }
    vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state = 
        ((IData)(vlTOPp->reset) ? 0U : (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__next_state));
    vlTOPp->rega = vlTOPp->bitty__DOT__regs;
    vlTOPp->regss = vlTOPp->bitty__DOT__regs;
    vlTOPp->reginst = vlTOPp->bitty__DOT__instruction;
    vlTOPp->bitty__DOT__out[0U] = vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__0__KET____DOT__reg_out__mux_out;
    vlTOPp->bitty__DOT__out[1U] = vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__1__KET____DOT__reg_out__mux_out;
    vlTOPp->bitty__DOT__out[2U] = vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__2__KET____DOT__reg_out__mux_out;
    vlTOPp->bitty__DOT__out[3U] = vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__3__KET____DOT__reg_out__mux_out;
    vlTOPp->bitty__DOT__out[4U] = vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__4__KET____DOT__reg_out__mux_out;
    vlTOPp->bitty__DOT__out[5U] = vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__5__KET____DOT__reg_out__mux_out;
    vlTOPp->bitty__DOT__out[6U] = vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__6__KET____DOT__reg_out__mux_out;
    vlTOPp->bitty__DOT__out[7U] = vlTOPp->bitty__DOT____Vcellout__genblk1__BRA__7__KET____DOT__reg_out__mux_out;
    vlTOPp->d_out = vlTOPp->bitty__DOT__regc;
    vlTOPp->regcc = vlTOPp->bitty__DOT__regc;
    vlTOPp->reg0 = vlTOPp->bitty__DOT__out[0U];
    vlTOPp->reg1 = vlTOPp->bitty__DOT__out[1U];
    vlTOPp->reg2 = vlTOPp->bitty__DOT__out[2U];
    vlTOPp->reg3 = vlTOPp->bitty__DOT__out[3U];
    vlTOPp->reg4 = vlTOPp->bitty__DOT__out[4U];
    vlTOPp->reg5 = vlTOPp->bitty__DOT__out[5U];
    vlTOPp->reg6 = vlTOPp->bitty__DOT__out[6U];
    vlTOPp->reg7 = vlTOPp->bitty__DOT__out[7U];
}

void Vbitty::_settle__TOP__2(Vbitty__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty::_settle__TOP__2\n"); );
    Vbitty* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->rega = vlTOPp->bitty__DOT__regs;
    vlTOPp->d_out = vlTOPp->bitty__DOT__regc;
    vlTOPp->regcc = vlTOPp->bitty__DOT__regc;
    vlTOPp->regss = vlTOPp->bitty__DOT__regs;
    vlTOPp->reginst = vlTOPp->bitty__DOT__instruction;
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
        vlTOPp->bitty__DOT__en_c = 0U;
        vlTOPp->done = 0U;
        vlTOPp->bitty__DOT__mux_sel = 0U;
        vlTOPp->bitty__DOT__alu_sel = 0U;
        vlTOPp->bitty__DOT__en = 0U;
        vlTOPp->bitty__DOT__en_inst = 0U;
    } else {
        if (vlTOPp->run) {
            vlTOPp->bitty__DOT__en_inst = 1U;
            vlTOPp->bitty__DOT__en_s = 0U;
            vlTOPp->bitty__DOT__en_c = 0U;
            vlTOPp->done = 0U;
            vlTOPp->bitty__DOT__alu_sel = 0U;
            vlTOPp->bitty__DOT__en = 0U;
            if ((0U == (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
                vlTOPp->bitty__DOT__en_s = 1U;
                vlTOPp->bitty__DOT__mux_sel = (7U & 
                                               ((IData)(vlTOPp->bitty__DOT__instruction) 
                                                >> 0xdU));
                vlTOPp->done = 0U;
                vlTOPp->bitty__DOT__en_inst = 1U;
                vlSymsp->TOP____024unit.__Vdpiimwrap_notify_counter_nine_1_TOP____024unit();
            } else {
                if ((1U == (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
                    if (vlTOPp->bitty__DOT__en_s) {
                        vlSymsp->TOP____024unit.__Vdpiimwrap_notify_counter_nine_2_TOP____024unit();
                    }
                    vlTOPp->bitty__DOT__mux_sel = (7U 
                                                   & ((IData)(vlTOPp->bitty__DOT__instruction) 
                                                      >> 0xaU));
                    vlTOPp->bitty__DOT__en_c = 1U;
                    vlTOPp->bitty__DOT__alu_sel = (7U 
                                                   & ((IData)(vlTOPp->bitty__DOT__instruction) 
                                                      >> 2U));
                    vlTOPp->bitty__DOT__en_inst = 0U;
                } else {
                    if ((3U == (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
                        if (vlTOPp->bitty__DOT__en_s) {
                            vlSymsp->TOP____024unit.__Vdpiimwrap_notify_counter_nine_3_TOP____024unit();
                        }
                        vlTOPp->bitty__DOT__en = ((IData)(vlTOPp->bitty__DOT__en) 
                                                  | ((IData)(1U) 
                                                     << 
                                                     (7U 
                                                      & ((IData)(vlTOPp->bitty__DOT__instruction) 
                                                         >> 0xdU))));
                        vlTOPp->done = 1U;
                    } else {
                        vlTOPp->bitty__DOT__en_s = 0U;
                        vlTOPp->bitty__DOT__en_c = 0U;
                        vlTOPp->done = 0U;
                        vlTOPp->bitty__DOT__mux_sel = 0U;
                        vlTOPp->bitty__DOT__alu_sel = 0U;
                        vlTOPp->bitty__DOT__en = 0U;
                    }
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
    vlTOPp->__Vtableidx1 = (((IData)(vlTOPp->done) 
                             << 4U) | (((IData)(vlTOPp->bitty__DOT__en_c) 
                                        << 3U) | (((IData)(vlTOPp->bitty__DOT__en_s) 
                                                   << 2U) 
                                                  | (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))));
    vlTOPp->bitty__DOT__cpu_inst__DOT__next_state = 
        vlTOPp->__Vtable1_bitty__DOT__cpu_inst__DOT__next_state
        [vlTOPp->__Vtableidx1];
    vlTOPp->bitty__DOT__out_mux = ((4U & (IData)(vlTOPp->bitty__DOT__mux_sel))
                                    ? ((2U & (IData)(vlTOPp->bitty__DOT__mux_sel))
                                        ? ((1U & (IData)(vlTOPp->bitty__DOT__mux_sel))
                                            ? vlTOPp->bitty__DOT__out
                                           [7U] : vlTOPp->bitty__DOT__out
                                           [6U]) : 
                                       ((1U & (IData)(vlTOPp->bitty__DOT__mux_sel))
                                         ? vlTOPp->bitty__DOT__out
                                        [5U] : vlTOPp->bitty__DOT__out
                                        [4U])) : ((2U 
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
                                                   [0U])));
    vlTOPp->regb = vlTOPp->bitty__DOT__out_mux;
}

VL_INLINE_OPT void Vbitty::_combo__TOP__3(Vbitty__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty::_combo__TOP__3\n"); );
    Vbitty* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->reset) {
        vlTOPp->bitty__DOT__en_s = 0U;
        vlTOPp->bitty__DOT__en_c = 0U;
        vlTOPp->done = 0U;
        vlTOPp->bitty__DOT__mux_sel = 0U;
        vlTOPp->bitty__DOT__alu_sel = 0U;
        vlTOPp->bitty__DOT__en = 0U;
        vlTOPp->bitty__DOT__en_inst = 0U;
    } else {
        if (vlTOPp->run) {
            vlTOPp->bitty__DOT__en_inst = 1U;
            vlTOPp->bitty__DOT__en_s = 0U;
            vlTOPp->bitty__DOT__en_c = 0U;
            vlTOPp->done = 0U;
            vlTOPp->bitty__DOT__alu_sel = 0U;
            vlTOPp->bitty__DOT__en = 0U;
            if ((0U == (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
                vlTOPp->bitty__DOT__en_s = 1U;
                vlTOPp->bitty__DOT__mux_sel = (7U & 
                                               ((IData)(vlTOPp->bitty__DOT__instruction) 
                                                >> 0xdU));
                vlTOPp->done = 0U;
                vlTOPp->bitty__DOT__en_inst = 1U;
                vlSymsp->TOP____024unit.__Vdpiimwrap_notify_counter_nine_1_TOP____024unit();
            } else {
                if ((1U == (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
                    if (vlTOPp->bitty__DOT__en_s) {
                        vlSymsp->TOP____024unit.__Vdpiimwrap_notify_counter_nine_2_TOP____024unit();
                    }
                    vlTOPp->bitty__DOT__mux_sel = (7U 
                                                   & ((IData)(vlTOPp->bitty__DOT__instruction) 
                                                      >> 0xaU));
                    vlTOPp->bitty__DOT__en_c = 1U;
                    vlTOPp->bitty__DOT__alu_sel = (7U 
                                                   & ((IData)(vlTOPp->bitty__DOT__instruction) 
                                                      >> 2U));
                    vlTOPp->bitty__DOT__en_inst = 0U;
                } else {
                    if ((3U == (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))) {
                        if (vlTOPp->bitty__DOT__en_s) {
                            vlSymsp->TOP____024unit.__Vdpiimwrap_notify_counter_nine_3_TOP____024unit();
                        }
                        vlTOPp->bitty__DOT__en = ((IData)(vlTOPp->bitty__DOT__en) 
                                                  | ((IData)(1U) 
                                                     << 
                                                     (7U 
                                                      & ((IData)(vlTOPp->bitty__DOT__instruction) 
                                                         >> 0xdU))));
                        vlTOPp->done = 1U;
                    } else {
                        vlTOPp->bitty__DOT__en_s = 0U;
                        vlTOPp->bitty__DOT__en_c = 0U;
                        vlTOPp->done = 0U;
                        vlTOPp->bitty__DOT__mux_sel = 0U;
                        vlTOPp->bitty__DOT__alu_sel = 0U;
                        vlTOPp->bitty__DOT__en = 0U;
                    }
                }
            }
        }
    }
    vlTOPp->__Vtableidx1 = (((IData)(vlTOPp->done) 
                             << 4U) | (((IData)(vlTOPp->bitty__DOT__en_c) 
                                        << 3U) | (((IData)(vlTOPp->bitty__DOT__en_s) 
                                                   << 2U) 
                                                  | (IData)(vlTOPp->bitty__DOT__cpu_inst__DOT__cur_state))));
    vlTOPp->bitty__DOT__cpu_inst__DOT__next_state = 
        vlTOPp->__Vtable1_bitty__DOT__cpu_inst__DOT__next_state
        [vlTOPp->__Vtableidx1];
    vlTOPp->bitty__DOT__out_mux = ((4U & (IData)(vlTOPp->bitty__DOT__mux_sel))
                                    ? ((2U & (IData)(vlTOPp->bitty__DOT__mux_sel))
                                        ? ((1U & (IData)(vlTOPp->bitty__DOT__mux_sel))
                                            ? vlTOPp->bitty__DOT__out
                                           [7U] : vlTOPp->bitty__DOT__out
                                           [6U]) : 
                                       ((1U & (IData)(vlTOPp->bitty__DOT__mux_sel))
                                         ? vlTOPp->bitty__DOT__out
                                        [5U] : vlTOPp->bitty__DOT__out
                                        [4U])) : ((2U 
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
                                                   [0U])));
    vlTOPp->regb = vlTOPp->bitty__DOT__out_mux;
}

void Vbitty::_eval(Vbitty__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty::_eval\n"); );
    Vbitty* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((IData)(vlTOPp->reset) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset))))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
        vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    }
    vlTOPp->_combo__TOP__3(vlSymsp);
    vlTOPp->__Vm_traceActivity = (4U | vlTOPp->__Vm_traceActivity);
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
    vlTOPp->_settle__TOP__2(vlSymsp);
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
    regcc = VL_RAND_RESET_I(16);
    regss = VL_RAND_RESET_I(16);
    reg0 = VL_RAND_RESET_I(16);
    reg1 = VL_RAND_RESET_I(16);
    reg2 = VL_RAND_RESET_I(16);
    reg3 = VL_RAND_RESET_I(16);
    reg4 = VL_RAND_RESET_I(16);
    reg5 = VL_RAND_RESET_I(16);
    reg6 = VL_RAND_RESET_I(16);
    reg7 = VL_RAND_RESET_I(16);
    reginst = VL_RAND_RESET_I(16);
    done = VL_RAND_RESET_I(1);
    bitty__DOT__mux_sel = VL_RAND_RESET_I(3);
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
    __Vtableidx1 = 0;
    __Vtable1_bitty__DOT__cpu_inst__DOT__next_state[0] = 0U;
    __Vtable1_bitty__DOT__cpu_inst__DOT__next_state[1] = 1U;
    __Vtable1_bitty__DOT__cpu_inst__DOT__next_state[2] = 0U;
    __Vtable1_bitty__DOT__cpu_inst__DOT__next_state[3] = 3U;
    __Vtable1_bitty__DOT__cpu_inst__DOT__next_state[4] = 1U;
    __Vtable1_bitty__DOT__cpu_inst__DOT__next_state[5] = 1U;
    __Vtable1_bitty__DOT__cpu_inst__DOT__next_state[6] = 0U;
    __Vtable1_bitty__DOT__cpu_inst__DOT__next_state[7] = 3U;
    __Vtable1_bitty__DOT__cpu_inst__DOT__next_state[8] = 0U;
    __Vtable1_bitty__DOT__cpu_inst__DOT__next_state[9] = 3U;
    __Vtable1_bitty__DOT__cpu_inst__DOT__next_state[10] = 0U;
    __Vtable1_bitty__DOT__cpu_inst__DOT__next_state[11] = 3U;
    __Vtable1_bitty__DOT__cpu_inst__DOT__next_state[12] = 1U;
    __Vtable1_bitty__DOT__cpu_inst__DOT__next_state[13] = 3U;
    __Vtable1_bitty__DOT__cpu_inst__DOT__next_state[14] = 0U;
    __Vtable1_bitty__DOT__cpu_inst__DOT__next_state[15] = 3U;
    __Vtable1_bitty__DOT__cpu_inst__DOT__next_state[16] = 0U;
    __Vtable1_bitty__DOT__cpu_inst__DOT__next_state[17] = 1U;
    __Vtable1_bitty__DOT__cpu_inst__DOT__next_state[18] = 0U;
    __Vtable1_bitty__DOT__cpu_inst__DOT__next_state[19] = 0U;
    __Vtable1_bitty__DOT__cpu_inst__DOT__next_state[20] = 1U;
    __Vtable1_bitty__DOT__cpu_inst__DOT__next_state[21] = 1U;
    __Vtable1_bitty__DOT__cpu_inst__DOT__next_state[22] = 0U;
    __Vtable1_bitty__DOT__cpu_inst__DOT__next_state[23] = 0U;
    __Vtable1_bitty__DOT__cpu_inst__DOT__next_state[24] = 0U;
    __Vtable1_bitty__DOT__cpu_inst__DOT__next_state[25] = 3U;
    __Vtable1_bitty__DOT__cpu_inst__DOT__next_state[26] = 0U;
    __Vtable1_bitty__DOT__cpu_inst__DOT__next_state[27] = 0U;
    __Vtable1_bitty__DOT__cpu_inst__DOT__next_state[28] = 1U;
    __Vtable1_bitty__DOT__cpu_inst__DOT__next_state[29] = 3U;
    __Vtable1_bitty__DOT__cpu_inst__DOT__next_state[30] = 0U;
    __Vtable1_bitty__DOT__cpu_inst__DOT__next_state[31] = 0U;
    __Vm_traceActivity = 0;
}
