// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vriscv_top.h for the primary calling header

#include "Vriscv_top.h"
#include "Vriscv_top__Syms.h"

#include "verilated_dpi.h"

//==========

void Vriscv_top::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vriscv_top::eval\n"); );
    Vriscv_top__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("/home/oksj_unix/projects/zaram_training/RV32I/core/pipelined/riscv_top.v", 14, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vriscv_top::_eval_initial_loop(Vriscv_top__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("/home/oksj_unix/projects/zaram_training/RV32I/core/pipelined/riscv_top.v", 14, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vriscv_top::_combo__TOP__1(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_top::_combo__TOP__1\n"); );
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__riscv_top.i_clk = vlTOPp->i_clk;
}

VL_INLINE_OPT void Vriscv_top::_sequent__TOP__4(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_top::_sequent__TOP__4\n"); );
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->o_riscv_imem_pc = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pc
        [0U];
    vlTOPp->o_riscv_dmem_wr_en = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mem_wr_en
        [1U];
    vlTOPp->o_riscv_dmem_addr = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_out
        [0U];
    vlTOPp->o_riscv_imem_instr = vlSymsp->TOP__riscv_top.o_riscv_imem_instr;
    vlTOPp->o_riscv_dmem_wr_data = vlSymsp->TOP__riscv_top.o_riscv_dmem_wr_data;
    vlTOPp->o_riscv_dmem_rd_data = vlSymsp->TOP__riscv_top.o_riscv_dmem_rd_data;
    vlTOPp->o_riscv_dmem_strb = vlSymsp->TOP__riscv_top.o_riscv_dmem_strb;
}

VL_INLINE_OPT void Vriscv_top::_combo__TOP__5(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_top::_combo__TOP__5\n"); );
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__riscv_top.i_rstn = vlTOPp->i_rstn;
}

void Vriscv_top::_eval(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_top::_eval\n"); );
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
    if (((IData)(vlSymsp->TOP__riscv_top.i_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__riscv_top__i_clk)))) {
        vlSymsp->TOP__riscv_top._sequent__TOP__riscv_top__3(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
        vlTOPp->_sequent__TOP__4(vlSymsp);
    }
    if (((~ (IData)(vlSymsp->TOP__riscv_top.i_clk)) 
         & (IData)(vlTOPp->__Vclklast__TOP__riscv_top__i_clk))) {
        vlSymsp->TOP__riscv_top._sequent__TOP__riscv_top__4(vlSymsp);
        vlTOPp->__Vm_traceActivity[2U] = 1U;
    }
    vlTOPp->_combo__TOP__5(vlSymsp);
    if (((IData)(vlSymsp->TOP__riscv_top.i_clk) ^ (IData)(vlTOPp->__Vclklast__TOP__riscv_top__i_clk))) {
        vlSymsp->TOP__riscv_top._multiclk__TOP__riscv_top__5(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__riscv_top__i_clk = vlSymsp->TOP__riscv_top.i_clk;
}

VL_INLINE_OPT QData Vriscv_top::_change_request(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_top::_change_request\n"); );
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vriscv_top::_change_request_1(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_top::_change_request_1\n"); );
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vriscv_top::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_top::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((i_clk & 0xfeU))) {
        Verilated::overWidthError("i_clk");}
    if (VL_UNLIKELY((i_rstn & 0xfeU))) {
        Verilated::overWidthError("i_rstn");}
}
#endif  // VL_DEBUG
