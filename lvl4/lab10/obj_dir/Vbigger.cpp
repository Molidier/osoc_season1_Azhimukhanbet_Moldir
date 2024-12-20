// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbigger.h for the primary calling header

#include "Vbigger.h"
#include "Vbigger__Syms.h"

//==========
CData/*3:0*/ Vbigger::__Vtable1_bigger__DOT__next_state[32];
CData/*1:0*/ Vbigger::__Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[128];

VL_CTOR_IMP(Vbigger) {
    Vbigger__Syms* __restrict vlSymsp = __VlSymsp = new Vbigger__Syms(this, name());
    Vbigger* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vbigger::__Vconfigure(Vbigger__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vbigger::~Vbigger() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void Vbigger::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vbigger::eval\n"); );
    Vbigger__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vbigger* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("bigger.v", 2, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vbigger::_eval_initial_loop(Vbigger__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("bigger.v", 2, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vbigger::_sequent__TOP__1(Vbigger__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbigger::_sequent__TOP__1\n"); );
    Vbigger* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->run) {
        vlTOPp->bigger__DOT__cur_state = vlTOPp->bigger__DOT__next_state;
    }
    if (vlTOPp->reset) {
        vlTOPp->bigger__DOT__cur_state = 0U;
    }
    if (vlTOPp->reset) {
        vlTOPp->bigger__DOT__instance3__DOT____Vcellout__gen_dff__BRA__7__KET____DOT__reg_out__mux_out = 0U;
    } else {
        if ((0x80U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__en))) {
            vlTOPp->bigger__DOT__instance3__DOT____Vcellout__gen_dff__BRA__7__KET____DOT__reg_out__mux_out 
                = vlTOPp->bigger__DOT__instance3__DOT__regc;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bigger__DOT__instance3__DOT____Vcellout__gen_dff__BRA__6__KET____DOT__reg_out__mux_out = 0U;
    } else {
        if ((0x40U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__en))) {
            vlTOPp->bigger__DOT__instance3__DOT____Vcellout__gen_dff__BRA__6__KET____DOT__reg_out__mux_out 
                = vlTOPp->bigger__DOT__instance3__DOT__regc;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bigger__DOT__instance3__DOT____Vcellout__gen_dff__BRA__5__KET____DOT__reg_out__mux_out = 0U;
    } else {
        if ((0x20U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__en))) {
            vlTOPp->bigger__DOT__instance3__DOT____Vcellout__gen_dff__BRA__5__KET____DOT__reg_out__mux_out 
                = vlTOPp->bigger__DOT__instance3__DOT__regc;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bigger__DOT__instance3__DOT____Vcellout__gen_dff__BRA__4__KET____DOT__reg_out__mux_out = 0U;
    } else {
        if ((0x10U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__en))) {
            vlTOPp->bigger__DOT__instance3__DOT____Vcellout__gen_dff__BRA__4__KET____DOT__reg_out__mux_out 
                = vlTOPp->bigger__DOT__instance3__DOT__regc;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bigger__DOT__instance3__DOT____Vcellout__gen_dff__BRA__3__KET____DOT__reg_out__mux_out = 0U;
    } else {
        if ((8U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__en))) {
            vlTOPp->bigger__DOT__instance3__DOT____Vcellout__gen_dff__BRA__3__KET____DOT__reg_out__mux_out 
                = vlTOPp->bigger__DOT__instance3__DOT__regc;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bigger__DOT__instance3__DOT____Vcellout__gen_dff__BRA__2__KET____DOT__reg_out__mux_out = 0U;
    } else {
        if ((4U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__en))) {
            vlTOPp->bigger__DOT__instance3__DOT____Vcellout__gen_dff__BRA__2__KET____DOT__reg_out__mux_out 
                = vlTOPp->bigger__DOT__instance3__DOT__regc;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bigger__DOT__instance3__DOT____Vcellout__gen_dff__BRA__1__KET____DOT__reg_out__mux_out = 0U;
    } else {
        if ((2U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__en))) {
            vlTOPp->bigger__DOT__instance3__DOT____Vcellout__gen_dff__BRA__1__KET____DOT__reg_out__mux_out 
                = vlTOPp->bigger__DOT__instance3__DOT__regc;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bigger__DOT__instance3__DOT____Vcellout__gen_dff__BRA__0__KET____DOT__reg_out__mux_out = 0U;
    } else {
        if ((1U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__en))) {
            vlTOPp->bigger__DOT__instance3__DOT____Vcellout__gen_dff__BRA__0__KET____DOT__reg_out__mux_out 
                = vlTOPp->bigger__DOT__instance3__DOT__regc;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bigger__DOT__instance3__DOT__instruction = 0U;
    } else {
        if (vlTOPp->bigger__DOT__instance3__DOT__en_inst) {
            vlTOPp->bigger__DOT__instance3__DOT__instruction 
                = vlTOPp->bigger__DOT__mem_out;
        }
    }
    vlTOPp->bigger__DOT__instance3__DOT__cpu_inst__DOT__cur_state 
        = ((IData)(vlTOPp->reset) ? 0U : (IData)(vlTOPp->bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state));
    vlTOPp->bigger__DOT__instance3__DOT__out[7U] = vlTOPp->bigger__DOT__instance3__DOT____Vcellout__gen_dff__BRA__7__KET____DOT__reg_out__mux_out;
    vlTOPp->bigger__DOT__instance3__DOT__out[6U] = vlTOPp->bigger__DOT__instance3__DOT____Vcellout__gen_dff__BRA__6__KET____DOT__reg_out__mux_out;
    vlTOPp->bigger__DOT__instance3__DOT__out[5U] = vlTOPp->bigger__DOT__instance3__DOT____Vcellout__gen_dff__BRA__5__KET____DOT__reg_out__mux_out;
    vlTOPp->bigger__DOT__instance3__DOT__out[4U] = vlTOPp->bigger__DOT__instance3__DOT____Vcellout__gen_dff__BRA__4__KET____DOT__reg_out__mux_out;
    vlTOPp->bigger__DOT__instance3__DOT__out[3U] = vlTOPp->bigger__DOT__instance3__DOT____Vcellout__gen_dff__BRA__3__KET____DOT__reg_out__mux_out;
    vlTOPp->bigger__DOT__instance3__DOT__out[2U] = vlTOPp->bigger__DOT__instance3__DOT____Vcellout__gen_dff__BRA__2__KET____DOT__reg_out__mux_out;
    vlTOPp->bigger__DOT__instance3__DOT__out[1U] = vlTOPp->bigger__DOT__instance3__DOT____Vcellout__gen_dff__BRA__1__KET____DOT__reg_out__mux_out;
    vlTOPp->bigger__DOT__instance3__DOT__out[0U] = vlTOPp->bigger__DOT__instance3__DOT____Vcellout__gen_dff__BRA__0__KET____DOT__reg_out__mux_out;
    if (vlTOPp->reset) {
        vlTOPp->bigger__DOT__instance3__DOT__regc = 0U;
    } else {
        if (vlTOPp->bigger__DOT__instance3__DOT__en_c) {
            vlTOPp->bigger__DOT__instance3__DOT__regc 
                = (0xffffU & ((4U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__alu_sel))
                               ? ((2U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__alu_sel))
                                   ? ((1U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__alu_sel))
                                       ? (((IData)(vlTOPp->bigger__DOT__instance3__DOT__regs) 
                                           == (IData)(vlTOPp->bigger__DOT__instance3__DOT__out_mux))
                                           ? 0U : (
                                                   ((IData)(vlTOPp->bigger__DOT__instance3__DOT__regs) 
                                                    > (IData)(vlTOPp->bigger__DOT__instance3__DOT__out_mux))
                                                    ? 1U
                                                    : 2U))
                                       : ((0xfU >= 
                                           (0x1fU & (IData)(vlTOPp->bigger__DOT__instance3__DOT__out_mux)))
                                           ? ((IData)(vlTOPp->bigger__DOT__instance3__DOT__regs) 
                                              >> (0x1fU 
                                                  & (IData)(vlTOPp->bigger__DOT__instance3__DOT__out_mux)))
                                           : 0U)) : 
                                  ((1U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__alu_sel))
                                    ? ((0xfU >= (0x1fU 
                                                 & (IData)(vlTOPp->bigger__DOT__instance3__DOT__out_mux)))
                                        ? ((IData)(vlTOPp->bigger__DOT__instance3__DOT__regs) 
                                           << (0x1fU 
                                               & (IData)(vlTOPp->bigger__DOT__instance3__DOT__out_mux)))
                                        : 0U) : ((IData)(vlTOPp->bigger__DOT__instance3__DOT__regs) 
                                                 ^ (IData)(vlTOPp->bigger__DOT__instance3__DOT__out_mux))))
                               : ((2U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__alu_sel))
                                   ? ((1U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__alu_sel))
                                       ? ((IData)(vlTOPp->bigger__DOT__instance3__DOT__regs) 
                                          | (IData)(vlTOPp->bigger__DOT__instance3__DOT__out_mux))
                                       : ((IData)(vlTOPp->bigger__DOT__instance3__DOT__regs) 
                                          & (IData)(vlTOPp->bigger__DOT__instance3__DOT__out_mux)))
                                   : ((1U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__alu_sel))
                                       ? ((IData)(vlTOPp->bigger__DOT__instance3__DOT__regs) 
                                          - (IData)(vlTOPp->bigger__DOT__instance3__DOT__out_mux))
                                       : ((IData)(vlTOPp->bigger__DOT__instance3__DOT__regs) 
                                          + (IData)(vlTOPp->bigger__DOT__instance3__DOT__out_mux))))));
        }
    }
    vlTOPp->bigger__DOT__mem_out = vlTOPp->bigger__DOT__instance2__DOT__memory_array
        [vlTOPp->bigger__DOT__addr];
    vlTOPp->bigger__DOT__instance3__DOT__en_inst = 
        ((0U == (IData)(vlTOPp->bigger__DOT__instance3__DOT__cpu_inst__DOT__cur_state)) 
         | ((1U != (IData)(vlTOPp->bigger__DOT__instance3__DOT__cpu_inst__DOT__cur_state)) 
            & (2U == (IData)(vlTOPp->bigger__DOT__instance3__DOT__cpu_inst__DOT__cur_state))));
    vlTOPp->bigger__DOT__instance3__DOT__en = 0U;
    if ((0U != (IData)(vlTOPp->bigger__DOT__instance3__DOT__cpu_inst__DOT__cur_state))) {
        if ((1U != (IData)(vlTOPp->bigger__DOT__instance3__DOT__cpu_inst__DOT__cur_state))) {
            vlTOPp->bigger__DOT__instance3__DOT__en 
                = ((2U == (IData)(vlTOPp->bigger__DOT__instance3__DOT__cpu_inst__DOT__cur_state))
                    ? ((2U != (3U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__instruction)))
                        ? ((IData)(vlTOPp->bigger__DOT__instance3__DOT__en) 
                           | ((IData)(1U) << (7U & 
                                              ((IData)(vlTOPp->bigger__DOT__instance3__DOT__instruction) 
                                               >> 0xdU))))
                        : 0U) : 0U);
        }
    }
    vlTOPp->bigger__DOT__instance3__DOT__im_d = (0xffU 
                                                 & ((IData)(vlTOPp->bigger__DOT__instance3__DOT__instruction) 
                                                    >> 5U));
    if ((0U == (IData)(vlTOPp->bigger__DOT__instance3__DOT__cpu_inst__DOT__cur_state))) {
        if ((2U != (3U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__instruction)))) {
            if ((1U == (3U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__instruction)))) {
                vlTOPp->bigger__DOT__instance3__DOT__im_d 
                    = (0xffU & ((IData)(vlTOPp->bigger__DOT__instance3__DOT__instruction) 
                                >> 5U));
            }
        }
    }
    vlTOPp->bigger__DOT__instance3__DOT__mux_sel = 9U;
    if ((0U == (IData)(vlTOPp->bigger__DOT__instance3__DOT__cpu_inst__DOT__cur_state))) {
        if ((2U != (3U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__instruction)))) {
            vlTOPp->bigger__DOT__instance3__DOT__mux_sel 
                = (7U & ((IData)(vlTOPp->bigger__DOT__instance3__DOT__instruction) 
                         >> 0xdU));
        }
    } else {
        if ((1U == (IData)(vlTOPp->bigger__DOT__instance3__DOT__cpu_inst__DOT__cur_state))) {
            vlTOPp->bigger__DOT__instance3__DOT__mux_sel 
                = ((2U != (3U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__instruction)))
                    ? ((0U == (3U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__instruction)))
                        ? (7U & ((IData)(vlTOPp->bigger__DOT__instance3__DOT__instruction) 
                                 >> 0xaU)) : ((1U == 
                                               (3U 
                                                & (IData)(vlTOPp->bigger__DOT__instance3__DOT__instruction)))
                                               ? 8U
                                               : 9U))
                    : 9U);
        } else {
            if ((2U != (IData)(vlTOPp->bigger__DOT__instance3__DOT__cpu_inst__DOT__cur_state))) {
                vlTOPp->bigger__DOT__instance3__DOT__mux_sel = 9U;
            }
        }
    }
    vlTOPp->bigger__DOT__instance3__DOT__alu_sel = 
        ((0U == (IData)(vlTOPp->bigger__DOT__instance3__DOT__cpu_inst__DOT__cur_state))
          ? 0U : ((1U == (IData)(vlTOPp->bigger__DOT__instance3__DOT__cpu_inst__DOT__cur_state))
                   ? ((2U != (3U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__instruction)))
                       ? (7U & ((IData)(vlTOPp->bigger__DOT__instance3__DOT__instruction) 
                                >> 2U)) : 0U) : 0U));
    vlTOPp->bigger__DOT__instance3__DOT__en_c = 0U;
    if ((0U != (IData)(vlTOPp->bigger__DOT__instance3__DOT__cpu_inst__DOT__cur_state))) {
        if ((1U == (IData)(vlTOPp->bigger__DOT__instance3__DOT__cpu_inst__DOT__cur_state))) {
            vlTOPp->bigger__DOT__instance3__DOT__en_c = 1U;
        } else {
            if ((2U != (IData)(vlTOPp->bigger__DOT__instance3__DOT__cpu_inst__DOT__cur_state))) {
                vlTOPp->bigger__DOT__instance3__DOT__en_c = 0U;
            }
        }
    }
    vlTOPp->d_out = vlTOPp->bigger__DOT__instance3__DOT__regc;
    if (vlTOPp->reset) {
        vlTOPp->bigger__DOT__instance3__DOT__regs = 0U;
    } else {
        if (vlTOPp->bigger__DOT__instance3__DOT__en_s) {
            vlTOPp->bigger__DOT__instance3__DOT__regs 
                = vlTOPp->bigger__DOT__instance3__DOT__out_mux;
        }
    }
    vlTOPp->instr = vlTOPp->bigger__DOT__mem_out;
    if (vlTOPp->reset) {
        vlTOPp->bigger__DOT__addr = 0U;
    } else {
        if (vlTOPp->done) {
            vlTOPp->bigger__DOT__addr = vlTOPp->bigger__DOT__new_pc;
        }
    }
    vlTOPp->bigger__DOT__instance3__DOT__en_s = 0U;
    if ((0U == (IData)(vlTOPp->bigger__DOT__instance3__DOT__cpu_inst__DOT__cur_state))) {
        if ((2U != (3U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__instruction)))) {
            vlTOPp->bigger__DOT__instance3__DOT__en_s = 1U;
        }
    } else {
        if ((1U != (IData)(vlTOPp->bigger__DOT__instance3__DOT__cpu_inst__DOT__cur_state))) {
            if ((2U != (IData)(vlTOPp->bigger__DOT__instance3__DOT__cpu_inst__DOT__cur_state))) {
                vlTOPp->bigger__DOT__instance3__DOT__en_s = 0U;
            }
        }
    }
    vlTOPp->bigger__DOT__instance3__DOT__out_mux = 
        ((8U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__mux_sel))
          ? ((4U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__mux_sel))
              ? 0U : ((2U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__mux_sel))
                       ? 0U : ((1U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__mux_sel))
                                ? 0U : (IData)(vlTOPp->bigger__DOT__instance3__DOT__im_d))))
          : ((4U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__mux_sel))
              ? ((2U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__mux_sel))
                  ? ((1U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__mux_sel))
                      ? vlTOPp->bigger__DOT__instance3__DOT__out
                     [7U] : vlTOPp->bigger__DOT__instance3__DOT__out
                     [6U]) : ((1U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__mux_sel))
                               ? vlTOPp->bigger__DOT__instance3__DOT__out
                              [5U] : vlTOPp->bigger__DOT__instance3__DOT__out
                              [4U])) : ((2U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__mux_sel))
                                         ? ((1U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__mux_sel))
                                             ? vlTOPp->bigger__DOT__instance3__DOT__out
                                            [3U] : 
                                            vlTOPp->bigger__DOT__instance3__DOT__out
                                            [2U]) : 
                                        ((1U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__mux_sel))
                                          ? vlTOPp->bigger__DOT__instance3__DOT__out
                                         [1U] : vlTOPp->bigger__DOT__instance3__DOT__out
                                         [0U]))));
    vlTOPp->done = 0U;
    vlTOPp->done = ((0U != (IData)(vlTOPp->bigger__DOT__instance3__DOT__cpu_inst__DOT__cur_state)) 
                    & ((1U != (IData)(vlTOPp->bigger__DOT__instance3__DOT__cpu_inst__DOT__cur_state)) 
                       & (2U == (IData)(vlTOPp->bigger__DOT__instance3__DOT__cpu_inst__DOT__cur_state))));
    if ((2U == (3U & (IData)(vlTOPp->bigger__DOT__mem_out)))) {
        if ((0U == (3U & ((IData)(vlTOPp->bigger__DOT__mem_out) 
                          >> 2U)))) {
            if (VL_UNLIKELY((0U == (IData)(vlTOPp->d_out)))) {
                vlTOPp->bigger__DOT__new_pc = (0xffU 
                                               & ((IData)(vlTOPp->bigger__DOT__mem_out) 
                                                  >> 4U));
                VL_WRITEF("branching to: %x\n",8,(0xffU 
                                                  & ((IData)(vlTOPp->bigger__DOT__mem_out) 
                                                     >> 4U)));
            } else {
                vlTOPp->bigger__DOT__new_pc = (0xffU 
                                               & ((IData)(1U) 
                                                  + (IData)(vlTOPp->bigger__DOT__addr)));
            }
        } else {
            if ((1U == (3U & ((IData)(vlTOPp->bigger__DOT__mem_out) 
                              >> 2U)))) {
                if (VL_UNLIKELY((1U == (IData)(vlTOPp->d_out)))) {
                    VL_WRITEF("branching to: %x\n",
                              8,(0xffU & ((IData)(vlTOPp->bigger__DOT__mem_out) 
                                          >> 4U)));
                    vlTOPp->bigger__DOT__new_pc = (0xffU 
                                                   & ((IData)(vlTOPp->bigger__DOT__mem_out) 
                                                      >> 4U));
                } else {
                    vlTOPp->bigger__DOT__new_pc = (0xffU 
                                                   & ((IData)(1U) 
                                                      + (IData)(vlTOPp->bigger__DOT__addr)));
                }
            } else {
                if ((2U == (3U & ((IData)(vlTOPp->bigger__DOT__mem_out) 
                                  >> 2U)))) {
                    if (VL_UNLIKELY((2U == (IData)(vlTOPp->d_out)))) {
                        VL_WRITEF("branching to: %x\n",
                                  8,(0xffU & ((IData)(vlTOPp->bigger__DOT__mem_out) 
                                              >> 4U)));
                        vlTOPp->bigger__DOT__new_pc 
                            = (0xffU & ((IData)(vlTOPp->bigger__DOT__mem_out) 
                                        >> 4U));
                    } else {
                        vlTOPp->bigger__DOT__new_pc 
                            = (0xffU & ((IData)(1U) 
                                        + (IData)(vlTOPp->bigger__DOT__addr)));
                    }
                } else {
                    vlTOPp->bigger__DOT__new_pc = (0xffU 
                                                   & ((IData)(1U) 
                                                      + (IData)(vlTOPp->bigger__DOT__addr)));
                }
            }
        }
    } else {
        vlTOPp->bigger__DOT__new_pc = (0xffU & ((IData)(1U) 
                                                + (IData)(vlTOPp->bigger__DOT__addr)));
    }
    vlTOPp->__Vtableidx1 = (((IData)(vlTOPp->done) 
                             << 4U) | (IData)(vlTOPp->bigger__DOT__cur_state));
    vlTOPp->bigger__DOT__next_state = vlTOPp->__Vtable1_bigger__DOT__next_state
        [vlTOPp->__Vtableidx1];
    vlTOPp->__Vtableidx2 = (((IData)(vlTOPp->done) 
                             << 6U) | (((IData)(vlTOPp->bigger__DOT__instance3__DOT__en_c) 
                                        << 5U) | ((0x18U 
                                                   & ((IData)(vlTOPp->bigger__DOT__instance3__DOT__instruction) 
                                                      << 3U)) 
                                                  | ((((0U 
                                                        != (IData)(vlTOPp->bigger__DOT__cur_state)) 
                                                       & (3U 
                                                          == (IData)(vlTOPp->bigger__DOT__cur_state))) 
                                                      << 2U) 
                                                     | (IData)(vlTOPp->bigger__DOT__instance3__DOT__cpu_inst__DOT__cur_state)))));
    vlTOPp->bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state 
        = vlTOPp->__Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state
        [vlTOPp->__Vtableidx2];
}

void Vbigger::_settle__TOP__2(Vbigger__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbigger::_settle__TOP__2\n"); );
    Vbigger* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->bigger__DOT__instance3__DOT__en_inst = 
        ((0U == (IData)(vlTOPp->bigger__DOT__instance3__DOT__cpu_inst__DOT__cur_state)) 
         | ((1U != (IData)(vlTOPp->bigger__DOT__instance3__DOT__cpu_inst__DOT__cur_state)) 
            & (2U == (IData)(vlTOPp->bigger__DOT__instance3__DOT__cpu_inst__DOT__cur_state))));
    vlTOPp->bigger__DOT__instance3__DOT__en = 0U;
    if ((0U != (IData)(vlTOPp->bigger__DOT__instance3__DOT__cpu_inst__DOT__cur_state))) {
        if ((1U != (IData)(vlTOPp->bigger__DOT__instance3__DOT__cpu_inst__DOT__cur_state))) {
            vlTOPp->bigger__DOT__instance3__DOT__en 
                = ((2U == (IData)(vlTOPp->bigger__DOT__instance3__DOT__cpu_inst__DOT__cur_state))
                    ? ((2U != (3U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__instruction)))
                        ? ((IData)(vlTOPp->bigger__DOT__instance3__DOT__en) 
                           | ((IData)(1U) << (7U & 
                                              ((IData)(vlTOPp->bigger__DOT__instance3__DOT__instruction) 
                                               >> 0xdU))))
                        : 0U) : 0U);
        }
    }
    vlTOPp->bigger__DOT__instance3__DOT__im_d = (0xffU 
                                                 & ((IData)(vlTOPp->bigger__DOT__instance3__DOT__instruction) 
                                                    >> 5U));
    if ((0U == (IData)(vlTOPp->bigger__DOT__instance3__DOT__cpu_inst__DOT__cur_state))) {
        if ((2U != (3U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__instruction)))) {
            if ((1U == (3U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__instruction)))) {
                vlTOPp->bigger__DOT__instance3__DOT__im_d 
                    = (0xffU & ((IData)(vlTOPp->bigger__DOT__instance3__DOT__instruction) 
                                >> 5U));
            }
        }
    }
    vlTOPp->bigger__DOT__instance3__DOT__mux_sel = 9U;
    if ((0U == (IData)(vlTOPp->bigger__DOT__instance3__DOT__cpu_inst__DOT__cur_state))) {
        if ((2U != (3U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__instruction)))) {
            vlTOPp->bigger__DOT__instance3__DOT__mux_sel 
                = (7U & ((IData)(vlTOPp->bigger__DOT__instance3__DOT__instruction) 
                         >> 0xdU));
        }
    } else {
        if ((1U == (IData)(vlTOPp->bigger__DOT__instance3__DOT__cpu_inst__DOT__cur_state))) {
            vlTOPp->bigger__DOT__instance3__DOT__mux_sel 
                = ((2U != (3U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__instruction)))
                    ? ((0U == (3U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__instruction)))
                        ? (7U & ((IData)(vlTOPp->bigger__DOT__instance3__DOT__instruction) 
                                 >> 0xaU)) : ((1U == 
                                               (3U 
                                                & (IData)(vlTOPp->bigger__DOT__instance3__DOT__instruction)))
                                               ? 8U
                                               : 9U))
                    : 9U);
        } else {
            if ((2U != (IData)(vlTOPp->bigger__DOT__instance3__DOT__cpu_inst__DOT__cur_state))) {
                vlTOPp->bigger__DOT__instance3__DOT__mux_sel = 9U;
            }
        }
    }
    vlTOPp->bigger__DOT__instance3__DOT__out[0U] = vlTOPp->bigger__DOT__instance3__DOT____Vcellout__gen_dff__BRA__0__KET____DOT__reg_out__mux_out;
    vlTOPp->bigger__DOT__instance3__DOT__out[1U] = vlTOPp->bigger__DOT__instance3__DOT____Vcellout__gen_dff__BRA__1__KET____DOT__reg_out__mux_out;
    vlTOPp->bigger__DOT__instance3__DOT__out[2U] = vlTOPp->bigger__DOT__instance3__DOT____Vcellout__gen_dff__BRA__2__KET____DOT__reg_out__mux_out;
    vlTOPp->bigger__DOT__instance3__DOT__out[3U] = vlTOPp->bigger__DOT__instance3__DOT____Vcellout__gen_dff__BRA__3__KET____DOT__reg_out__mux_out;
    vlTOPp->bigger__DOT__instance3__DOT__out[4U] = vlTOPp->bigger__DOT__instance3__DOT____Vcellout__gen_dff__BRA__4__KET____DOT__reg_out__mux_out;
    vlTOPp->bigger__DOT__instance3__DOT__out[5U] = vlTOPp->bigger__DOT__instance3__DOT____Vcellout__gen_dff__BRA__5__KET____DOT__reg_out__mux_out;
    vlTOPp->bigger__DOT__instance3__DOT__out[6U] = vlTOPp->bigger__DOT__instance3__DOT____Vcellout__gen_dff__BRA__6__KET____DOT__reg_out__mux_out;
    vlTOPp->bigger__DOT__instance3__DOT__out[7U] = vlTOPp->bigger__DOT__instance3__DOT____Vcellout__gen_dff__BRA__7__KET____DOT__reg_out__mux_out;
    vlTOPp->bigger__DOT__instance3__DOT__alu_sel = 
        ((0U == (IData)(vlTOPp->bigger__DOT__instance3__DOT__cpu_inst__DOT__cur_state))
          ? 0U : ((1U == (IData)(vlTOPp->bigger__DOT__instance3__DOT__cpu_inst__DOT__cur_state))
                   ? ((2U != (3U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__instruction)))
                       ? (7U & ((IData)(vlTOPp->bigger__DOT__instance3__DOT__instruction) 
                                >> 2U)) : 0U) : 0U));
    vlTOPp->bigger__DOT__instance3__DOT__en_c = 0U;
    if ((0U != (IData)(vlTOPp->bigger__DOT__instance3__DOT__cpu_inst__DOT__cur_state))) {
        if ((1U == (IData)(vlTOPp->bigger__DOT__instance3__DOT__cpu_inst__DOT__cur_state))) {
            vlTOPp->bigger__DOT__instance3__DOT__en_c = 1U;
        } else {
            if ((2U != (IData)(vlTOPp->bigger__DOT__instance3__DOT__cpu_inst__DOT__cur_state))) {
                vlTOPp->bigger__DOT__instance3__DOT__en_c = 0U;
            }
        }
    }
    vlTOPp->instr = vlTOPp->bigger__DOT__mem_out;
    vlTOPp->d_out = vlTOPp->bigger__DOT__instance3__DOT__regc;
    vlTOPp->bigger__DOT__instance3__DOT__en_s = 0U;
    if ((0U == (IData)(vlTOPp->bigger__DOT__instance3__DOT__cpu_inst__DOT__cur_state))) {
        if ((2U != (3U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__instruction)))) {
            vlTOPp->bigger__DOT__instance3__DOT__en_s = 1U;
        }
    } else {
        if ((1U != (IData)(vlTOPp->bigger__DOT__instance3__DOT__cpu_inst__DOT__cur_state))) {
            if ((2U != (IData)(vlTOPp->bigger__DOT__instance3__DOT__cpu_inst__DOT__cur_state))) {
                vlTOPp->bigger__DOT__instance3__DOT__en_s = 0U;
            }
        }
    }
    vlTOPp->done = 0U;
    vlTOPp->done = ((0U != (IData)(vlTOPp->bigger__DOT__instance3__DOT__cpu_inst__DOT__cur_state)) 
                    & ((1U != (IData)(vlTOPp->bigger__DOT__instance3__DOT__cpu_inst__DOT__cur_state)) 
                       & (2U == (IData)(vlTOPp->bigger__DOT__instance3__DOT__cpu_inst__DOT__cur_state))));
    vlTOPp->bigger__DOT__instance3__DOT__out_mux = 
        ((8U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__mux_sel))
          ? ((4U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__mux_sel))
              ? 0U : ((2U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__mux_sel))
                       ? 0U : ((1U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__mux_sel))
                                ? 0U : (IData)(vlTOPp->bigger__DOT__instance3__DOT__im_d))))
          : ((4U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__mux_sel))
              ? ((2U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__mux_sel))
                  ? ((1U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__mux_sel))
                      ? vlTOPp->bigger__DOT__instance3__DOT__out
                     [7U] : vlTOPp->bigger__DOT__instance3__DOT__out
                     [6U]) : ((1U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__mux_sel))
                               ? vlTOPp->bigger__DOT__instance3__DOT__out
                              [5U] : vlTOPp->bigger__DOT__instance3__DOT__out
                              [4U])) : ((2U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__mux_sel))
                                         ? ((1U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__mux_sel))
                                             ? vlTOPp->bigger__DOT__instance3__DOT__out
                                            [3U] : 
                                            vlTOPp->bigger__DOT__instance3__DOT__out
                                            [2U]) : 
                                        ((1U & (IData)(vlTOPp->bigger__DOT__instance3__DOT__mux_sel))
                                          ? vlTOPp->bigger__DOT__instance3__DOT__out
                                         [1U] : vlTOPp->bigger__DOT__instance3__DOT__out
                                         [0U]))));
    if ((2U == (3U & (IData)(vlTOPp->bigger__DOT__mem_out)))) {
        if ((0U == (3U & ((IData)(vlTOPp->bigger__DOT__mem_out) 
                          >> 2U)))) {
            if (VL_UNLIKELY((0U == (IData)(vlTOPp->d_out)))) {
                vlTOPp->bigger__DOT__new_pc = (0xffU 
                                               & ((IData)(vlTOPp->bigger__DOT__mem_out) 
                                                  >> 4U));
                VL_WRITEF("branching to: %x\n",8,(0xffU 
                                                  & ((IData)(vlTOPp->bigger__DOT__mem_out) 
                                                     >> 4U)));
            } else {
                vlTOPp->bigger__DOT__new_pc = (0xffU 
                                               & ((IData)(1U) 
                                                  + (IData)(vlTOPp->bigger__DOT__addr)));
            }
        } else {
            if ((1U == (3U & ((IData)(vlTOPp->bigger__DOT__mem_out) 
                              >> 2U)))) {
                if (VL_UNLIKELY((1U == (IData)(vlTOPp->d_out)))) {
                    VL_WRITEF("branching to: %x\n",
                              8,(0xffU & ((IData)(vlTOPp->bigger__DOT__mem_out) 
                                          >> 4U)));
                    vlTOPp->bigger__DOT__new_pc = (0xffU 
                                                   & ((IData)(vlTOPp->bigger__DOT__mem_out) 
                                                      >> 4U));
                } else {
                    vlTOPp->bigger__DOT__new_pc = (0xffU 
                                                   & ((IData)(1U) 
                                                      + (IData)(vlTOPp->bigger__DOT__addr)));
                }
            } else {
                if ((2U == (3U & ((IData)(vlTOPp->bigger__DOT__mem_out) 
                                  >> 2U)))) {
                    if (VL_UNLIKELY((2U == (IData)(vlTOPp->d_out)))) {
                        VL_WRITEF("branching to: %x\n",
                                  8,(0xffU & ((IData)(vlTOPp->bigger__DOT__mem_out) 
                                              >> 4U)));
                        vlTOPp->bigger__DOT__new_pc 
                            = (0xffU & ((IData)(vlTOPp->bigger__DOT__mem_out) 
                                        >> 4U));
                    } else {
                        vlTOPp->bigger__DOT__new_pc 
                            = (0xffU & ((IData)(1U) 
                                        + (IData)(vlTOPp->bigger__DOT__addr)));
                    }
                } else {
                    vlTOPp->bigger__DOT__new_pc = (0xffU 
                                                   & ((IData)(1U) 
                                                      + (IData)(vlTOPp->bigger__DOT__addr)));
                }
            }
        }
    } else {
        vlTOPp->bigger__DOT__new_pc = (0xffU & ((IData)(1U) 
                                                + (IData)(vlTOPp->bigger__DOT__addr)));
    }
    vlTOPp->__Vtableidx1 = (((IData)(vlTOPp->done) 
                             << 4U) | (IData)(vlTOPp->bigger__DOT__cur_state));
    vlTOPp->bigger__DOT__next_state = vlTOPp->__Vtable1_bigger__DOT__next_state
        [vlTOPp->__Vtableidx1];
    vlTOPp->__Vtableidx2 = (((IData)(vlTOPp->done) 
                             << 6U) | (((IData)(vlTOPp->bigger__DOT__instance3__DOT__en_c) 
                                        << 5U) | ((0x18U 
                                                   & ((IData)(vlTOPp->bigger__DOT__instance3__DOT__instruction) 
                                                      << 3U)) 
                                                  | ((((0U 
                                                        != (IData)(vlTOPp->bigger__DOT__cur_state)) 
                                                       & (3U 
                                                          == (IData)(vlTOPp->bigger__DOT__cur_state))) 
                                                      << 2U) 
                                                     | (IData)(vlTOPp->bigger__DOT__instance3__DOT__cpu_inst__DOT__cur_state)))));
    vlTOPp->bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state 
        = vlTOPp->__Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state
        [vlTOPp->__Vtableidx2];
}

void Vbigger::_initial__TOP__3(Vbigger__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbigger::_initial__TOP__3\n"); );
    Vbigger* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    WData/*127:0*/ __Vtemp1[4];
    // Body
    __Vtemp1[0U] = 0x2e747874U;
    __Vtemp1[1U] = 0x696f6e73U;
    __Vtemp1[2U] = 0x72756374U;
    __Vtemp1[3U] = 0x696e7374U;
    VL_READMEM_N(true, 16, 256, 0, VL_CVT_PACK_STR_NW(4, __Vtemp1)
                 , vlTOPp->bigger__DOT__instance2__DOT__memory_array
                 , 0, ~VL_ULL(0));
}

void Vbigger::_eval(Vbigger__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbigger::_eval\n"); );
    Vbigger* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
        vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void Vbigger::_eval_initial(Vbigger__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbigger::_eval_initial\n"); );
    Vbigger* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->_initial__TOP__3(vlSymsp);
}

void Vbigger::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbigger::final\n"); );
    // Variables
    Vbigger__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vbigger* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vbigger::_eval_settle(Vbigger__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbigger::_eval_settle\n"); );
    Vbigger* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
}

VL_INLINE_OPT QData Vbigger::_change_request(Vbigger__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbigger::_change_request\n"); );
    Vbigger* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vbigger::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbigger::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((run & 0xfeU))) {
        Verilated::overWidthError("run");}
}
#endif  // VL_DEBUG

void Vbigger::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbigger::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    run = VL_RAND_RESET_I(1);
    done = VL_RAND_RESET_I(1);
    instr = VL_RAND_RESET_I(16);
    d_out = VL_RAND_RESET_I(16);
    bigger__DOT__cur_state = VL_RAND_RESET_I(4);
    bigger__DOT__next_state = VL_RAND_RESET_I(4);
    bigger__DOT__mem_out = VL_RAND_RESET_I(16);
    bigger__DOT__addr = VL_RAND_RESET_I(8);
    bigger__DOT__new_pc = VL_RAND_RESET_I(8);
    { int __Vi0=0; for (; __Vi0<256; ++__Vi0) {
            bigger__DOT__instance2__DOT__memory_array[__Vi0] = VL_RAND_RESET_I(16);
    }}
    bigger__DOT__instance3__DOT__mux_sel = VL_RAND_RESET_I(4);
    bigger__DOT__instance3__DOT__en = VL_RAND_RESET_I(8);
    { int __Vi0=0; for (; __Vi0<8; ++__Vi0) {
            bigger__DOT__instance3__DOT__out[__Vi0] = VL_RAND_RESET_I(16);
    }}
    bigger__DOT__instance3__DOT__out_mux = VL_RAND_RESET_I(16);
    bigger__DOT__instance3__DOT__en_s = VL_RAND_RESET_I(1);
    bigger__DOT__instance3__DOT__en_c = VL_RAND_RESET_I(1);
    bigger__DOT__instance3__DOT__en_inst = VL_RAND_RESET_I(1);
    bigger__DOT__instance3__DOT__alu_sel = VL_RAND_RESET_I(3);
    bigger__DOT__instance3__DOT__instruction = VL_RAND_RESET_I(16);
    bigger__DOT__instance3__DOT__im_d = VL_RAND_RESET_I(16);
    bigger__DOT__instance3__DOT__regs = VL_RAND_RESET_I(16);
    bigger__DOT__instance3__DOT__regc = VL_RAND_RESET_I(16);
    bigger__DOT__instance3__DOT____Vcellout__gen_dff__BRA__0__KET____DOT__reg_out__mux_out = VL_RAND_RESET_I(16);
    bigger__DOT__instance3__DOT____Vcellout__gen_dff__BRA__1__KET____DOT__reg_out__mux_out = VL_RAND_RESET_I(16);
    bigger__DOT__instance3__DOT____Vcellout__gen_dff__BRA__2__KET____DOT__reg_out__mux_out = VL_RAND_RESET_I(16);
    bigger__DOT__instance3__DOT____Vcellout__gen_dff__BRA__3__KET____DOT__reg_out__mux_out = VL_RAND_RESET_I(16);
    bigger__DOT__instance3__DOT____Vcellout__gen_dff__BRA__4__KET____DOT__reg_out__mux_out = VL_RAND_RESET_I(16);
    bigger__DOT__instance3__DOT____Vcellout__gen_dff__BRA__5__KET____DOT__reg_out__mux_out = VL_RAND_RESET_I(16);
    bigger__DOT__instance3__DOT____Vcellout__gen_dff__BRA__6__KET____DOT__reg_out__mux_out = VL_RAND_RESET_I(16);
    bigger__DOT__instance3__DOT____Vcellout__gen_dff__BRA__7__KET____DOT__reg_out__mux_out = VL_RAND_RESET_I(16);
    bigger__DOT__instance3__DOT__cpu_inst__DOT__cur_state = VL_RAND_RESET_I(2);
    bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state = VL_RAND_RESET_I(2);
    __Vtableidx1 = 0;
    __Vtable1_bigger__DOT__next_state[0] = 1U;
    __Vtable1_bigger__DOT__next_state[1] = 2U;
    __Vtable1_bigger__DOT__next_state[2] = 3U;
    __Vtable1_bigger__DOT__next_state[3] = 3U;
    __Vtable1_bigger__DOT__next_state[4] = 0U;
    __Vtable1_bigger__DOT__next_state[5] = 0U;
    __Vtable1_bigger__DOT__next_state[6] = 0U;
    __Vtable1_bigger__DOT__next_state[7] = 0U;
    __Vtable1_bigger__DOT__next_state[8] = 0U;
    __Vtable1_bigger__DOT__next_state[9] = 0U;
    __Vtable1_bigger__DOT__next_state[10] = 0U;
    __Vtable1_bigger__DOT__next_state[11] = 0U;
    __Vtable1_bigger__DOT__next_state[12] = 0U;
    __Vtable1_bigger__DOT__next_state[13] = 0U;
    __Vtable1_bigger__DOT__next_state[14] = 0U;
    __Vtable1_bigger__DOT__next_state[15] = 0U;
    __Vtable1_bigger__DOT__next_state[16] = 1U;
    __Vtable1_bigger__DOT__next_state[17] = 2U;
    __Vtable1_bigger__DOT__next_state[18] = 3U;
    __Vtable1_bigger__DOT__next_state[19] = 0U;
    __Vtable1_bigger__DOT__next_state[20] = 0U;
    __Vtable1_bigger__DOT__next_state[21] = 0U;
    __Vtable1_bigger__DOT__next_state[22] = 0U;
    __Vtable1_bigger__DOT__next_state[23] = 0U;
    __Vtable1_bigger__DOT__next_state[24] = 0U;
    __Vtable1_bigger__DOT__next_state[25] = 0U;
    __Vtable1_bigger__DOT__next_state[26] = 0U;
    __Vtable1_bigger__DOT__next_state[27] = 0U;
    __Vtable1_bigger__DOT__next_state[28] = 0U;
    __Vtable1_bigger__DOT__next_state[29] = 0U;
    __Vtable1_bigger__DOT__next_state[30] = 0U;
    __Vtable1_bigger__DOT__next_state[31] = 0U;
    __Vtableidx2 = 0;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[0] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[1] = 1U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[2] = 2U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[3] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[4] = 1U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[5] = 1U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[6] = 2U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[7] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[8] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[9] = 1U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[10] = 2U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[11] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[12] = 1U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[13] = 1U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[14] = 2U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[15] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[16] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[17] = 1U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[18] = 2U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[19] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[20] = 2U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[21] = 1U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[22] = 2U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[23] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[24] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[25] = 1U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[26] = 2U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[27] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[28] = 1U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[29] = 1U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[30] = 2U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[31] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[32] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[33] = 2U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[34] = 2U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[35] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[36] = 1U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[37] = 2U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[38] = 2U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[39] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[40] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[41] = 2U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[42] = 2U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[43] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[44] = 1U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[45] = 2U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[46] = 2U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[47] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[48] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[49] = 2U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[50] = 2U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[51] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[52] = 2U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[53] = 2U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[54] = 2U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[55] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[56] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[57] = 2U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[58] = 2U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[59] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[60] = 1U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[61] = 2U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[62] = 2U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[63] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[64] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[65] = 1U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[66] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[67] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[68] = 1U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[69] = 1U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[70] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[71] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[72] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[73] = 1U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[74] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[75] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[76] = 1U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[77] = 1U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[78] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[79] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[80] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[81] = 1U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[82] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[83] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[84] = 2U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[85] = 1U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[86] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[87] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[88] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[89] = 1U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[90] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[91] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[92] = 1U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[93] = 1U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[94] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[95] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[96] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[97] = 2U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[98] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[99] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[100] = 1U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[101] = 2U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[102] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[103] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[104] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[105] = 2U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[106] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[107] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[108] = 1U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[109] = 2U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[110] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[111] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[112] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[113] = 2U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[114] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[115] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[116] = 2U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[117] = 2U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[118] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[119] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[120] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[121] = 2U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[122] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[123] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[124] = 1U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[125] = 2U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[126] = 0U;
    __Vtable2_bigger__DOT__instance3__DOT__cpu_inst__DOT__next_state[127] = 0U;
    __Vm_traceActivity = 0;
}
