// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vriscv_top.h for the primary calling header

#include "Vriscv_top.h"
#include "Vriscv_top__Syms.h"

#include "verilated_dpi.h"

//==========

VL_CTOR_IMP(Vriscv_top) {
    Vriscv_top__Syms* __restrict vlSymsp = __VlSymsp = new Vriscv_top__Syms(this, name());
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    VL_CELL(riscv_top, Vriscv_top_riscv_top);
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vriscv_top::__Vconfigure(Vriscv_top__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vriscv_top::~Vriscv_top() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vriscv_top::_settle__TOP__2(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_top::_settle__TOP__2\n"); );
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__riscv_top.i_clk = vlTOPp->i_clk;
    vlSymsp->TOP__riscv_top.i_rstn = vlTOPp->i_rstn;
    vlTOPp->o_riscv_dmem_wr_en = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mem_wr_en
        [1U];
    vlTOPp->o_riscv_dmem_addr = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_out
        [0U];
    vlTOPp->o_riscv_imem_pc = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pc
        [0U];
}

void Vriscv_top::_settle__TOP__3(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_top::_settle__TOP__3\n"); );
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->o_riscv_dmem_wr_data = vlSymsp->TOP__riscv_top.o_riscv_dmem_wr_data;
    vlTOPp->o_riscv_imem_instr = vlSymsp->TOP__riscv_top.o_riscv_imem_instr;
    vlTOPp->o_riscv_dmem_rd_data = vlSymsp->TOP__riscv_top.o_riscv_dmem_rd_data;
    vlTOPp->o_riscv_dmem_strb = vlSymsp->TOP__riscv_top.o_riscv_dmem_strb;
}

void Vriscv_top::_eval_initial(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_top::_eval_initial\n"); );
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__riscv_top._initial__TOP__riscv_top__1(vlSymsp);
    vlTOPp->__Vm_traceActivity[2U] = 1U;
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
    vlTOPp->__Vclklast__TOP__riscv_top__i_clk = vlSymsp->TOP__riscv_top.i_clk;
}

void Vriscv_top::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_top::final\n"); );
    // Variables
    Vriscv_top__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vriscv_top::_eval_settle(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_top::_eval_settle\n"); );
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
    vlTOPp->__Vm_traceActivity[2U] = 1U;
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
    vlSymsp->TOP__riscv_top._settle__TOP__riscv_top__2(vlSymsp);
    vlTOPp->_settle__TOP__3(vlSymsp);
}

void Vriscv_top::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_top::_ctor_var_reset\n"); );
    // Body
    o_riscv_imem_pc = VL_RAND_RESET_I(32);
    o_riscv_imem_instr = VL_RAND_RESET_I(32);
    o_riscv_dmem_addr = VL_RAND_RESET_I(32);
    o_riscv_dmem_wr_en = VL_RAND_RESET_I(1);
    o_riscv_dmem_strb = VL_RAND_RESET_I(4);
    o_riscv_dmem_wr_data = VL_RAND_RESET_I(32);
    o_riscv_dmem_rd_data = VL_RAND_RESET_I(32);
    i_clk = VL_RAND_RESET_I(1);
    i_rstn = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<3; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
