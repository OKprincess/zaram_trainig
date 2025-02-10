// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vriscv_top.h for the primary calling header

#include "Vriscv_top_riscv_top.h"
#include "Vriscv_top__Syms.h"

#include "verilated_dpi.h"

//==========

VL_INLINE_OPT void Vriscv_top_riscv_top::_sequent__TOP__riscv_top__3(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vriscv_top_riscv_top::_sequent__TOP__riscv_top__3\n"); );
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*4:0*/ __Vdlyvval__u_riscv_cpu__DOT__rs1__v0;
    CData/*6:0*/ __Vdlyvval__u_riscv_cpu__DOT__opcode__v0;
    CData/*2:0*/ __Vdlyvval__u_riscv_cpu__DOT__funct3__v0;
    CData/*0:0*/ __Vdlyvval__u_riscv_cpu__DOT__src_alu_b__v0;
    CData/*0:0*/ __Vdlyvval__u_riscv_cpu__DOT__src_alu_a__v0;
    CData/*3:0*/ __Vdlyvval__u_riscv_cpu__DOT__alu_ctrl__v0;
    CData/*0:0*/ __Vdlyvval__u_riscv_cpu__DOT__mem_wr_en__v0;
    CData/*1:0*/ __Vdlyvval__u_riscv_cpu__DOT__src_rd__v0;
    CData/*0:0*/ __Vdlyvval__u_riscv_cpu__DOT__reg_wr_en__v0;
    CData/*4:0*/ __Vdlyvval__u_riscv_cpu__DOT__rs2__v0;
    CData/*4:0*/ __Vdlyvval__u_riscv_cpu__DOT__rd__v0;
    CData/*0:0*/ __Vdlyvval__u_riscv_cpu__DOT__reg_wr_en__v1;
    CData/*1:0*/ __Vdlyvval__u_riscv_cpu__DOT__src_rd__v1;
    CData/*0:0*/ __Vdlyvval__u_riscv_cpu__DOT__mem_wr_en__v1;
    CData/*2:0*/ __Vdlyvval__u_riscv_cpu__DOT__funct3__v1;
    CData/*4:0*/ __Vdlyvval__u_riscv_cpu__DOT__rd__v1;
    CData/*0:0*/ __Vdlyvval__u_riscv_cpu__DOT__reg_wr_en__v2;
    CData/*1:0*/ __Vdlyvval__u_riscv_cpu__DOT__src_rd__v2;
    CData/*4:0*/ __Vdlyvval__u_riscv_cpu__DOT__rd__v2;
    CData/*4:0*/ __Vdlyvlsb__u_riscv_dmem__DOT__dmem_arr__v0;
    CData/*7:0*/ __Vdlyvval__u_riscv_dmem__DOT__dmem_arr__v0;
    CData/*0:0*/ __Vdlyvset__u_riscv_dmem__DOT__dmem_arr__v0;
    CData/*4:0*/ __Vdlyvlsb__u_riscv_dmem__DOT__dmem_arr__v1;
    CData/*7:0*/ __Vdlyvval__u_riscv_dmem__DOT__dmem_arr__v1;
    CData/*0:0*/ __Vdlyvset__u_riscv_dmem__DOT__dmem_arr__v1;
    CData/*4:0*/ __Vdlyvlsb__u_riscv_dmem__DOT__dmem_arr__v2;
    CData/*7:0*/ __Vdlyvval__u_riscv_dmem__DOT__dmem_arr__v2;
    CData/*0:0*/ __Vdlyvset__u_riscv_dmem__DOT__dmem_arr__v2;
    CData/*4:0*/ __Vdlyvlsb__u_riscv_dmem__DOT__dmem_arr__v3;
    CData/*7:0*/ __Vdlyvval__u_riscv_dmem__DOT__dmem_arr__v3;
    CData/*0:0*/ __Vdlyvset__u_riscv_dmem__DOT__dmem_arr__v3;
    CData/*0:0*/ __Vdlyvset__u_riscv_dmem__DOT__dmem_arr__v4;
    SData/*13:0*/ __Vdlyvdim0__u_riscv_dmem__DOT__dmem_arr__v0;
    SData/*13:0*/ __Vdlyvdim0__u_riscv_dmem__DOT__dmem_arr__v1;
    SData/*13:0*/ __Vdlyvdim0__u_riscv_dmem__DOT__dmem_arr__v2;
    SData/*13:0*/ __Vdlyvdim0__u_riscv_dmem__DOT__dmem_arr__v3;
    SData/*13:0*/ __Vdlyvdim0__u_riscv_dmem__DOT__dmem_arr__v4;
    IData/*31:0*/ __Vdlyvval__u_riscv_cpu__DOT__pc__v0;
    IData/*31:0*/ __Vdlyvval__u_riscv_cpu__DOT__instr__v0;
    IData/*31:0*/ __Vdlyvval__u_riscv_cpu__DOT__pc__v1;
    IData/*31:0*/ __Vdlyvval__u_riscv_cpu__DOT__pc4__v0;
    IData/*31:0*/ __Vdlyvval__u_riscv_cpu__DOT__pc__v2;
    IData/*31:0*/ __Vdlyvval__u_riscv_cpu__DOT__rs2_data__v0;
    IData/*31:0*/ __Vdlyvval__u_riscv_cpu__DOT__rs1_data__v0;
    IData/*31:0*/ __Vdlyvval__u_riscv_cpu__DOT__pc4__v1;
    IData/*31:0*/ __Vdlyvval__u_riscv_cpu__DOT__imm__v0;
    IData/*31:0*/ __Vdlyvval__u_riscv_cpu__DOT__imm__v1;
    IData/*31:0*/ __Vdlyvval__u_riscv_cpu__DOT__alu_out__v0;
    IData/*31:0*/ __Vdlyvval__u_riscv_cpu__DOT__fwd_b__v0;
    IData/*31:0*/ __Vdlyvval__u_riscv_cpu__DOT__pc4__v2;
    IData/*31:0*/ __Vdlyvval__u_riscv_cpu__DOT__alu_out__v1;
    IData/*31:0*/ __Vdlyvval__u_riscv_cpu__DOT__mem_rd_data__v0;
    IData/*31:0*/ __Vdlyvval__u_riscv_cpu__DOT__pc4__v3;
    IData/*31:0*/ __Vdlyvval__u_riscv_cpu__DOT__imm__v2;
    IData/*31:0*/ __Vdlyvval__u_riscv_dmem__DOT__dmem_arr__v4;
    // Body
    if (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mem_wr_en
        [1U]) {
        vlSymsp->TOP__riscv_top.__PVT__u_riscv_dmem__DOT__i = 4U;
    }
    __Vdlyvset__u_riscv_dmem__DOT__dmem_arr__v0 = 0U;
    __Vdlyvset__u_riscv_dmem__DOT__dmem_arr__v1 = 0U;
    __Vdlyvset__u_riscv_dmem__DOT__dmem_arr__v2 = 0U;
    __Vdlyvset__u_riscv_dmem__DOT__dmem_arr__v3 = 0U;
    __Vdlyvset__u_riscv_dmem__DOT__dmem_arr__v4 = 0U;
    __Vdlyvval__u_riscv_cpu__DOT__mem_wr_en__v1 = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mem_wr_en
        [0U];
    __Vdlyvval__u_riscv_cpu__DOT__mem_wr_en__v0 = (
                                                   (~ 
                                                    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__flush
                                                    [1U]) 
                                                   & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__w_mem_wr_en
                                                   [0U]);
    if (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__flush
        [1U]) {
        __Vdlyvval__u_riscv_cpu__DOT__opcode__v0 = 0U;
        __Vdlyvval__u_riscv_cpu__DOT__alu_ctrl__v0 = 0U;
    } else {
        __Vdlyvval__u_riscv_cpu__DOT__opcode__v0 = 
            vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__opcode
            [0U];
        __Vdlyvval__u_riscv_cpu__DOT__alu_ctrl__v0 
            = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__w_alu_ctrl
            [0U];
    }
    __Vdlyvval__u_riscv_cpu__DOT__src_alu_a__v0 = (
                                                   (~ 
                                                    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__flush
                                                    [1U]) 
                                                   & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__w_src_alu_a
                                                   [0U]);
    __Vdlyvval__u_riscv_cpu__DOT__src_alu_b__v0 = (
                                                   (~ 
                                                    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__flush
                                                    [1U]) 
                                                   & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__w_src_alu_b
                                                   [0U]);
    __Vdlyvval__u_riscv_cpu__DOT__fwd_b__v0 = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__w_fwd_b
        [0U];
    if (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__flush
        [1U]) {
        __Vdlyvval__u_riscv_cpu__DOT__rs2__v0 = 0U;
        __Vdlyvval__u_riscv_cpu__DOT__rs1__v0 = 0U;
    } else {
        __Vdlyvval__u_riscv_cpu__DOT__rs2__v0 = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs2
            [0U];
        __Vdlyvval__u_riscv_cpu__DOT__rs1__v0 = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs1
            [0U];
    }
    __Vdlyvval__u_riscv_cpu__DOT__reg_wr_en__v0 = (
                                                   (~ 
                                                    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__flush
                                                    [1U]) 
                                                   & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__w_reg_wr_en
                                                   [0U]);
    __Vdlyvval__u_riscv_cpu__DOT__reg_wr_en__v1 = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__reg_wr_en
        [0U];
    __Vdlyvval__u_riscv_cpu__DOT__reg_wr_en__v2 = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__reg_wr_en
        [1U];
    if (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__flush
        [1U]) {
        __Vdlyvval__u_riscv_cpu__DOT__rs1_data__v0 = 0U;
        __Vdlyvval__u_riscv_cpu__DOT__rs2_data__v0 = 0U;
    } else {
        __Vdlyvval__u_riscv_cpu__DOT__rs1_data__v0 
            = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__w_rs1_data
            [0U];
        __Vdlyvval__u_riscv_cpu__DOT__rs2_data__v0 
            = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__w_rs2_data
            [0U];
    }
    __Vdlyvval__u_riscv_cpu__DOT__rd__v1 = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rd
        [1U];
    __Vdlyvval__u_riscv_cpu__DOT__rd__v2 = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rd
        [2U];
    if (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__flush
        [1U]) {
        __Vdlyvval__u_riscv_cpu__DOT__rd__v0 = 0U;
        __Vdlyvval__u_riscv_cpu__DOT__src_rd__v0 = 0U;
    } else {
        __Vdlyvval__u_riscv_cpu__DOT__rd__v0 = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rd
            [0U];
        __Vdlyvval__u_riscv_cpu__DOT__src_rd__v0 = 
            vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__w_src_rd
            [0U];
    }
    __Vdlyvval__u_riscv_cpu__DOT__src_rd__v1 = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_rd
        [0U];
    __Vdlyvval__u_riscv_cpu__DOT__src_rd__v2 = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_rd
        [1U];
    __Vdlyvval__u_riscv_cpu__DOT__mem_rd_data__v0 = 
        vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mem_rd_data
        [0U];
    __Vdlyvval__u_riscv_cpu__DOT__imm__v0 = (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__flush
                                             [1U] ? 0U
                                              : vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__w_imm
                                             [0U]);
    __Vdlyvval__u_riscv_cpu__DOT__imm__v1 = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__imm
        [0U];
    __Vdlyvval__u_riscv_cpu__DOT__imm__v2 = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__imm
        [1U];
    __Vdlyvval__u_riscv_cpu__DOT__instr__v0 = (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__stall
                                               [1U]
                                                ? vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__instr
                                               [0U]
                                                : (
                                                   vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__flush
                                                   [0U]
                                                    ? 0U
                                                    : vlSymsp->TOP__riscv_top.o_riscv_imem_instr));
    __Vdlyvval__u_riscv_cpu__DOT__pc4__v2 = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pc4
        [2U];
    __Vdlyvval__u_riscv_cpu__DOT__pc4__v3 = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pc4
        [3U];
    __Vdlyvval__u_riscv_cpu__DOT__pc4__v1 = (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__flush
                                             [1U] ? 0U
                                              : vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pc4
                                             [1U]);
    __Vdlyvval__u_riscv_cpu__DOT__pc4__v0 = (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__stall
                                             [1U] ? 
                                             vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pc4
                                             [1U] : 
                                             (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__flush
                                              [0U] ? 0U
                                               : vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pc4
                                              [0U]));
    __Vdlyvval__u_riscv_cpu__DOT__funct3__v1 = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
        [1U];
    if (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__flush
        [1U]) {
        __Vdlyvval__u_riscv_cpu__DOT__funct3__v0 = 0U;
        __Vdlyvval__u_riscv_cpu__DOT__pc__v2 = 0U;
    } else {
        __Vdlyvval__u_riscv_cpu__DOT__funct3__v0 = 
            vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
            [0U];
        __Vdlyvval__u_riscv_cpu__DOT__pc__v2 = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pc
            [1U];
    }
    __Vdlyvval__u_riscv_cpu__DOT__pc__v1 = (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__stall
                                            [1U] ? 
                                            vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pc
                                            [1U] : 
                                            (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__flush
                                             [0U] ? 0U
                                              : vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pc
                                             [0U]));
    __Vdlyvval__u_riscv_cpu__DOT__pc__v0 = ((IData)(vlSymsp->TOP__riscv_top.i_rstn)
                                             ? (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__stall
                                                [0U]
                                                 ? 
                                                vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pc
                                                [0U]
                                                 : 
                                                ((2U 
                                                  >= 
                                                  vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_pc
                                                  [0U])
                                                  ? 
                                                 vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_pc__DOT__mux_input_arr
                                                 [vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_pc
                                                 [0U]]
                                                  : 0U))
                                             : 0U);
    __Vdlyvval__u_riscv_cpu__DOT__alu_out__v0 = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__w_alu_out
        [0U];
    __Vdlyvval__u_riscv_cpu__DOT__alu_out__v1 = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_out
        [0U];
    if (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mem_wr_en
        [1U]) {
        if ((1U & (IData)(vlSymsp->TOP__riscv_top.o_riscv_dmem_strb))) {
            __Vdlyvval__u_riscv_dmem__DOT__dmem_arr__v0 
                = (0xffU & vlSymsp->TOP__riscv_top.o_riscv_dmem_wr_data);
            __Vdlyvset__u_riscv_dmem__DOT__dmem_arr__v0 = 1U;
            __Vdlyvlsb__u_riscv_dmem__DOT__dmem_arr__v0 = 0U;
            __Vdlyvdim0__u_riscv_dmem__DOT__dmem_arr__v0 
                = (0x3fffU & (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_out
                              [0U] >> 2U));
        }
        if ((2U & (IData)(vlSymsp->TOP__riscv_top.o_riscv_dmem_strb))) {
            __Vdlyvval__u_riscv_dmem__DOT__dmem_arr__v1 
                = (0xffU & (vlSymsp->TOP__riscv_top.o_riscv_dmem_wr_data 
                            >> 8U));
            __Vdlyvset__u_riscv_dmem__DOT__dmem_arr__v1 = 1U;
            __Vdlyvlsb__u_riscv_dmem__DOT__dmem_arr__v1 = 8U;
            __Vdlyvdim0__u_riscv_dmem__DOT__dmem_arr__v1 
                = (0x3fffU & (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_out
                              [0U] >> 2U));
        }
        if ((4U & (IData)(vlSymsp->TOP__riscv_top.o_riscv_dmem_strb))) {
            __Vdlyvval__u_riscv_dmem__DOT__dmem_arr__v2 
                = (0xffU & (vlSymsp->TOP__riscv_top.o_riscv_dmem_wr_data 
                            >> 0x10U));
            __Vdlyvset__u_riscv_dmem__DOT__dmem_arr__v2 = 1U;
            __Vdlyvlsb__u_riscv_dmem__DOT__dmem_arr__v2 = 0x10U;
            __Vdlyvdim0__u_riscv_dmem__DOT__dmem_arr__v2 
                = (0x3fffU & (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_out
                              [0U] >> 2U));
        }
        if ((8U & (IData)(vlSymsp->TOP__riscv_top.o_riscv_dmem_strb))) {
            __Vdlyvval__u_riscv_dmem__DOT__dmem_arr__v3 
                = (0xffU & (vlSymsp->TOP__riscv_top.o_riscv_dmem_wr_data 
                            >> 0x18U));
            __Vdlyvset__u_riscv_dmem__DOT__dmem_arr__v3 = 1U;
            __Vdlyvlsb__u_riscv_dmem__DOT__dmem_arr__v3 = 0x18U;
            __Vdlyvdim0__u_riscv_dmem__DOT__dmem_arr__v3 
                = (0x3fffU & (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_out
                              [0U] >> 2U));
        }
    } else {
        __Vdlyvval__u_riscv_dmem__DOT__dmem_arr__v4 
            = vlSymsp->TOP__riscv_top.__PVT__u_riscv_dmem__DOT__dmem_arr
            [(0x3fffU & (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_out
                         [0U] >> 2U))];
        __Vdlyvset__u_riscv_dmem__DOT__dmem_arr__v4 = 1U;
        __Vdlyvdim0__u_riscv_dmem__DOT__dmem_arr__v4 
            = (0x3fffU & (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_out
                          [0U] >> 2U));
    }
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__opcode[1U] 
        = __Vdlyvval__u_riscv_cpu__DOT__opcode__v0;
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_ctrl[0U] 
        = __Vdlyvval__u_riscv_cpu__DOT__alu_ctrl__v0;
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_alu_a[0U] 
        = __Vdlyvval__u_riscv_cpu__DOT__src_alu_a__v0;
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_alu_b[0U] 
        = __Vdlyvval__u_riscv_cpu__DOT__src_alu_b__v0;
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__fwd_b[0U] 
        = __Vdlyvval__u_riscv_cpu__DOT__fwd_b__v0;
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs2[1U] 
        = __Vdlyvval__u_riscv_cpu__DOT__rs2__v0;
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs1[1U] 
        = __Vdlyvval__u_riscv_cpu__DOT__rs1__v0;
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__reg_wr_en[0U] 
        = __Vdlyvval__u_riscv_cpu__DOT__reg_wr_en__v0;
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__reg_wr_en[1U] 
        = __Vdlyvval__u_riscv_cpu__DOT__reg_wr_en__v1;
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__reg_wr_en[2U] 
        = __Vdlyvval__u_riscv_cpu__DOT__reg_wr_en__v2;
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs1_data[0U] 
        = __Vdlyvval__u_riscv_cpu__DOT__rs1_data__v0;
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs2_data[0U] 
        = __Vdlyvval__u_riscv_cpu__DOT__rs2_data__v0;
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rd[1U] 
        = __Vdlyvval__u_riscv_cpu__DOT__rd__v0;
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rd[2U] 
        = __Vdlyvval__u_riscv_cpu__DOT__rd__v1;
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rd[3U] 
        = __Vdlyvval__u_riscv_cpu__DOT__rd__v2;
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_rd[0U] 
        = __Vdlyvval__u_riscv_cpu__DOT__src_rd__v0;
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_rd[1U] 
        = __Vdlyvval__u_riscv_cpu__DOT__src_rd__v1;
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_rd[2U] 
        = __Vdlyvval__u_riscv_cpu__DOT__src_rd__v2;
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mem_rd_data[1U] 
        = __Vdlyvval__u_riscv_cpu__DOT__mem_rd_data__v0;
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__imm[0U] 
        = __Vdlyvval__u_riscv_cpu__DOT__imm__v0;
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__imm[1U] 
        = __Vdlyvval__u_riscv_cpu__DOT__imm__v1;
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__imm[2U] 
        = __Vdlyvval__u_riscv_cpu__DOT__imm__v2;
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__instr[0U] 
        = __Vdlyvval__u_riscv_cpu__DOT__instr__v0;
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pc4[1U] 
        = __Vdlyvval__u_riscv_cpu__DOT__pc4__v0;
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pc4[2U] 
        = __Vdlyvval__u_riscv_cpu__DOT__pc4__v1;
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pc4[3U] 
        = __Vdlyvval__u_riscv_cpu__DOT__pc4__v2;
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pc4[4U] 
        = __Vdlyvval__u_riscv_cpu__DOT__pc4__v3;
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3[1U] 
        = __Vdlyvval__u_riscv_cpu__DOT__funct3__v0;
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3[2U] 
        = __Vdlyvval__u_riscv_cpu__DOT__funct3__v1;
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pc[0U] 
        = __Vdlyvval__u_riscv_cpu__DOT__pc__v0;
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pc[1U] 
        = __Vdlyvval__u_riscv_cpu__DOT__pc__v1;
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pc[2U] 
        = __Vdlyvval__u_riscv_cpu__DOT__pc__v2;
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mem_wr_en[0U] 
        = __Vdlyvval__u_riscv_cpu__DOT__mem_wr_en__v0;
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mem_wr_en[1U] 
        = __Vdlyvval__u_riscv_cpu__DOT__mem_wr_en__v1;
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_out[0U] 
        = __Vdlyvval__u_riscv_cpu__DOT__alu_out__v0;
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_out[1U] 
        = __Vdlyvval__u_riscv_cpu__DOT__alu_out__v1;
    if (__Vdlyvset__u_riscv_dmem__DOT__dmem_arr__v0) {
        vlSymsp->TOP__riscv_top.__PVT__u_riscv_dmem__DOT__dmem_arr[__Vdlyvdim0__u_riscv_dmem__DOT__dmem_arr__v0] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__u_riscv_dmem__DOT__dmem_arr__v0))) 
                & vlSymsp->TOP__riscv_top.__PVT__u_riscv_dmem__DOT__dmem_arr
                [__Vdlyvdim0__u_riscv_dmem__DOT__dmem_arr__v0]) 
               | ((IData)(__Vdlyvval__u_riscv_dmem__DOT__dmem_arr__v0) 
                  << (IData)(__Vdlyvlsb__u_riscv_dmem__DOT__dmem_arr__v0)));
    }
    if (__Vdlyvset__u_riscv_dmem__DOT__dmem_arr__v1) {
        vlSymsp->TOP__riscv_top.__PVT__u_riscv_dmem__DOT__dmem_arr[__Vdlyvdim0__u_riscv_dmem__DOT__dmem_arr__v1] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__u_riscv_dmem__DOT__dmem_arr__v1))) 
                & vlSymsp->TOP__riscv_top.__PVT__u_riscv_dmem__DOT__dmem_arr
                [__Vdlyvdim0__u_riscv_dmem__DOT__dmem_arr__v1]) 
               | ((IData)(__Vdlyvval__u_riscv_dmem__DOT__dmem_arr__v1) 
                  << (IData)(__Vdlyvlsb__u_riscv_dmem__DOT__dmem_arr__v1)));
    }
    if (__Vdlyvset__u_riscv_dmem__DOT__dmem_arr__v2) {
        vlSymsp->TOP__riscv_top.__PVT__u_riscv_dmem__DOT__dmem_arr[__Vdlyvdim0__u_riscv_dmem__DOT__dmem_arr__v2] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__u_riscv_dmem__DOT__dmem_arr__v2))) 
                & vlSymsp->TOP__riscv_top.__PVT__u_riscv_dmem__DOT__dmem_arr
                [__Vdlyvdim0__u_riscv_dmem__DOT__dmem_arr__v2]) 
               | ((IData)(__Vdlyvval__u_riscv_dmem__DOT__dmem_arr__v2) 
                  << (IData)(__Vdlyvlsb__u_riscv_dmem__DOT__dmem_arr__v2)));
    }
    if (__Vdlyvset__u_riscv_dmem__DOT__dmem_arr__v3) {
        vlSymsp->TOP__riscv_top.__PVT__u_riscv_dmem__DOT__dmem_arr[__Vdlyvdim0__u_riscv_dmem__DOT__dmem_arr__v3] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__u_riscv_dmem__DOT__dmem_arr__v3))) 
                & vlSymsp->TOP__riscv_top.__PVT__u_riscv_dmem__DOT__dmem_arr
                [__Vdlyvdim0__u_riscv_dmem__DOT__dmem_arr__v3]) 
               | ((IData)(__Vdlyvval__u_riscv_dmem__DOT__dmem_arr__v3) 
                  << (IData)(__Vdlyvlsb__u_riscv_dmem__DOT__dmem_arr__v3)));
    }
    if (__Vdlyvset__u_riscv_dmem__DOT__dmem_arr__v4) {
        vlSymsp->TOP__riscv_top.__PVT__u_riscv_dmem__DOT__dmem_arr[__Vdlyvdim0__u_riscv_dmem__DOT__dmem_arr__v4] 
            = __Vdlyvval__u_riscv_dmem__DOT__dmem_arr__v4;
    }
    vlSymsp->TOP__riscv_top.__Vtableidx5 = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_ctrl
        [0U];
    if (vlSymsp->TOP__riscv_top.__Vtablechg5[vlSymsp->TOP__riscv_top.__Vtableidx5]) {
        vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_alu__DOT__DEBUG_ALU_OP 
            = vlSymsp->TOP__riscv_top.__Vtable5___PVT__u_riscv_cpu__DOT__u_riscv_alu__DOT__DEBUG_ALU_OP
            [vlSymsp->TOP__riscv_top.__Vtableidx5];
    }
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct7_5b[0U] 
        = (1U & (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__instr
                 [0U] >> 0x1eU));
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__opcode[0U] 
        = (0x7fU & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__instr
           [0U]);
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs1[0U] 
        = (0x1fU & (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__instr
                    [0U] >> 0xfU));
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs2[0U] 
        = (0x1fU & (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__instr
                    [0U] >> 0x14U));
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rd[0U] 
        = (0x1fU & (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__instr
                    [0U] >> 7U));
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3[0U] 
        = (7U & (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__instr
                 [0U] >> 0xcU));
    vlSymsp->TOP__riscv_top.o_riscv_imem_instr = vlSymsp->TOP__riscv_top.__PVT__u_riscv_imem__DOT__imem_arr
        [(0x3fffU & (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pc
                     [0U] >> 2U))];
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pcimm[0U] 
        = (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pc
           [2U] + vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__imm
           [0U]);
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pc4[0U] 
        = ((IData)(4U) + vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pc
           [0U]);
    vlSymsp->TOP__riscv_top.o_riscv_dmem_wr_data = 
        ((0x1fU >= (0x18U & (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_out
                             [0U] << 3U))) ? (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__fwd_b
                                              [0U] 
                                              << (0x18U 
                                                  & (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_out
                                                     [0U] 
                                                     << 3U)))
          : 0U);
    vlSymsp->TOP__riscv_top.o_riscv_dmem_rd_data = 
        vlSymsp->TOP__riscv_top.__PVT__u_riscv_dmem__DOT__dmem_arr
        [(0x3fffU & (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_out
                     [0U] >> 2U))];
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__w_mem_wr_en[0U] 
        = (0x23U == vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__opcode
           [0U]);
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__w_reg_wr_en[0U] 
        = (1U & (~ ((0x23U == vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__opcode
                     [0U]) | (0x63U == vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__opcode
                              [0U]))));
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__w_src_alu_a[0U] 
        = (0x17U == vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__opcode
           [0U]);
    vlSymsp->TOP__riscv_top.__Vtableidx2 = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__opcode
        [0U];
    vlSymsp->TOP__riscv_top.u_riscv_cpu__DOT____Vcellout__u_riscv_ctrl__o_ctrl_src_rd 
        = vlSymsp->TOP__riscv_top.__Vtable2_u_riscv_cpu__DOT____Vcellout__u_riscv_ctrl__o_ctrl_src_rd
        [vlSymsp->TOP__riscv_top.__Vtableidx2];
    vlSymsp->TOP__riscv_top.__Vtableidx3 = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__opcode
        [0U];
    vlSymsp->TOP__riscv_top.u_riscv_cpu__DOT____Vcellout__u_riscv_ctrl__o_ctrl_src_alu_b 
        = vlSymsp->TOP__riscv_top.__Vtable3_u_riscv_cpu__DOT____Vcellout__u_riscv_ctrl__o_ctrl_src_alu_b
        [vlSymsp->TOP__riscv_top.__Vtableidx3];
    vlSymsp->TOP__riscv_top.__Vtableidx1 = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__opcode
        [0U];
    vlSymsp->TOP__riscv_top.u_riscv_cpu__DOT____Vcellout__u_riscv_ctrl__o_ctrl_src_imm 
        = vlSymsp->TOP__riscv_top.__Vtable1_u_riscv_cpu__DOT____Vcellout__u_riscv_ctrl__o_ctrl_src_imm
        [vlSymsp->TOP__riscv_top.__Vtableidx1];
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_hazard__DOT__stall 
        = (((vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs1
             [0U] == vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rd
             [1U]) | (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs2
                      [0U] == vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rd
                      [1U])) & (0U != vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_rd
                                [0U]));
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__fwd_sel_b[0U] 
        = ((((vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs2
              [1U] == vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rd
              [2U]) & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__reg_wr_en
             [1U]) & (0U != vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs2
                      [1U])) ? 1U : ((((vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs2
                                        [1U] == vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rd
                                        [3U]) & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__reg_wr_en
                                       [2U]) & (0U 
                                                != 
                                                vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs2
                                                [1U]))
                                      ? 2U : 0U));
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__fwd_sel_a[0U] 
        = ((((vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs1
              [1U] == vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rd
              [2U]) & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__reg_wr_en
             [1U]) & (0U != vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs1
                      [1U])) ? 1U : ((((vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs1
                                        [1U] == vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rd
                                        [3U]) & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__reg_wr_en
                                       [2U]) & (0U 
                                                != 
                                                vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs1
                                                [1U]))
                                      ? 2U : 0U));
    vlSymsp->TOP__riscv_top.__Vtableidx4 = ((vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct7_5b
                                             [0U] << 0xaU) 
                                            | ((vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
                                                [0U] 
                                                << 7U) 
                                               | vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__opcode
                                               [0U]));
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR[0U] 
        = vlSymsp->TOP__riscv_top.__Vtable4___PVT__u_riscv_cpu__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR
        [vlSymsp->TOP__riscv_top.__Vtableidx4][0U];
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR[1U] 
        = vlSymsp->TOP__riscv_top.__Vtable4___PVT__u_riscv_cpu__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR
        [vlSymsp->TOP__riscv_top.__Vtableidx4][1U];
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR[2U] 
        = vlSymsp->TOP__riscv_top.__Vtable4___PVT__u_riscv_cpu__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR
        [vlSymsp->TOP__riscv_top.__Vtableidx4][2U];
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR[3U] 
        = vlSymsp->TOP__riscv_top.__Vtable4___PVT__u_riscv_cpu__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR
        [vlSymsp->TOP__riscv_top.__Vtableidx4][3U];
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR[4U] 
        = vlSymsp->TOP__riscv_top.__Vtable4___PVT__u_riscv_cpu__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR
        [vlSymsp->TOP__riscv_top.__Vtableidx4][4U];
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR[5U] 
        = vlSymsp->TOP__riscv_top.__Vtable4___PVT__u_riscv_cpu__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR
        [vlSymsp->TOP__riscv_top.__Vtableidx4][5U];
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR[6U] 
        = vlSymsp->TOP__riscv_top.__Vtable4___PVT__u_riscv_cpu__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR
        [vlSymsp->TOP__riscv_top.__Vtableidx4][6U];
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR[7U] 
        = vlSymsp->TOP__riscv_top.__Vtable4___PVT__u_riscv_cpu__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR
        [vlSymsp->TOP__riscv_top.__Vtableidx4][7U];
    vlSymsp->TOP__riscv_top.u_riscv_cpu__DOT____Vcellout__u_riscv_ctrl__o_ctrl_alu_ctrl 
        = (((0x33U == vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__opcode
             [0U]) | (0x13U == vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__opcode
                      [0U])) ? ((4U & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
                                 [0U]) ? ((2U & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
                                           [0U]) ? 
                                          ((1U & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
                                            [0U]) ? 7U
                                            : 6U) : 
                                          ((1U & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
                                            [0U]) ? 
                                           (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct7_5b
                                            [0U] ? 0xdU
                                             : 5U) : 4U))
                                 : ((2U & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
                                     [0U]) ? ((1U & 
                                               vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
                                               [0U])
                                               ? 3U
                                               : 2U)
                                     : ((1U & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
                                         [0U]) ? 1U
                                         : ((vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct7_5b
                                             [0U] & 
                                             (0x33U 
                                              == vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__opcode
                                              [0U]))
                                             ? 8U : 0U))))
            : ((0x63U == vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__opcode
                [0U]) ? ((4U & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
                          [0U]) ? ((2U & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
                                    [0U]) ? 3U : 2U)
                          : ((2U & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
                              [0U]) ? 0xfU : 8U)) : 0U));
    vlSymsp->TOP__riscv_top.__Vtableidx6 = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
        [2U];
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_dmem_interface__DOT__dmem_intf_strb 
        = vlSymsp->TOP__riscv_top.__Vtable6___PVT__u_riscv_cpu__DOT__u_riscv_dmem_interface__DOT__dmem_intf_strb
        [vlSymsp->TOP__riscv_top.__Vtableidx6];
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data 
        = ((0x1fU >= (0x18U & (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_out
                               [0U] << 3U))) ? (vlSymsp->TOP__riscv_top.o_riscv_dmem_rd_data 
                                                >> 
                                                (0x18U 
                                                 & (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_out
                                                    [0U] 
                                                    << 3U)))
            : 0U);
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__w_src_rd[0U] 
        = vlSymsp->TOP__riscv_top.u_riscv_cpu__DOT____Vcellout__u_riscv_ctrl__o_ctrl_src_rd;
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__w_src_alu_b[0U] 
        = vlSymsp->TOP__riscv_top.u_riscv_cpu__DOT____Vcellout__u_riscv_ctrl__o_ctrl_src_alu_b;
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_imm[0U] 
        = vlSymsp->TOP__riscv_top.u_riscv_cpu__DOT____Vcellout__u_riscv_ctrl__o_ctrl_src_imm;
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__stall[1U] 
        = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_hazard__DOT__stall;
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__stall[0U] 
        = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_hazard__DOT__stall;
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__w_alu_ctrl[0U] 
        = vlSymsp->TOP__riscv_top.u_riscv_cpu__DOT____Vcellout__u_riscv_ctrl__o_ctrl_alu_ctrl;
    vlSymsp->TOP__riscv_top.o_riscv_dmem_strb = ((3U 
                                                  >= 
                                                  (3U 
                                                   & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_out
                                                   [0U]))
                                                  ? 
                                                 (0xfU 
                                                  & ((IData)(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_dmem_interface__DOT__dmem_intf_strb) 
                                                     << 
                                                     (3U 
                                                      & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_out
                                                      [0U])))
                                                  : 0U);
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mem_rd_data[0U] 
        = ((4U & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
            [2U]) ? ((2U & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
                      [2U]) ? 0U : ((1U & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
                                     [2U]) ? (0xffffU 
                                              & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)
                                     : (0xffU & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)))
            : ((2U & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
                [2U]) ? ((1U & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
                          [2U]) ? 0U : vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)
                : ((1U & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
                    [2U]) ? ((0xffff0000U & ((- (IData)(
                                                        (1U 
                                                         & (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data 
                                                            >> 0xfU)))) 
                                             << 0x10U)) 
                             | (0xffffU & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data))
                    : ((0xffffff00U & ((- (IData)((1U 
                                                   & (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data 
                                                      >> 7U)))) 
                                       << 8U)) | (0xffU 
                                                  & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)))));
    vlSymsp->TOP__riscv_top.u_riscv_cpu__DOT____Vcellout__u_riscv_immmext__o_imm_ext 
        = ((4U & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_imm
            [0U]) ? ((2U & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_imm
                      [0U]) ? 0U : ((1U & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_imm
                                     [0U]) ? (0x1fff000U 
                                              & (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__instr
                                                 [0U] 
                                                 >> 7U))
                                     : ((0xff000U & 
                                         (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__instr
                                          [0U] >> 7U)) 
                                        | ((0x800U 
                                            & (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__instr
                                               [0U] 
                                               >> 0x10U)) 
                                           | (0x1eU 
                                              & (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__instr
                                                 [0U] 
                                                 >> 0x1bU))))))
            : ((2U & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_imm
                [0U]) ? ((1U & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_imm
                          [0U]) ? ((0x800U & (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__instr
                                              [0U] 
                                              >> 3U)) 
                                   | (0x1eU & (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__instr
                                               [0U] 
                                               >> 0xeU)))
                          : (0x1fU & (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__instr
                                      [0U] >> 0xeU)))
                : ((1U & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_imm
                    [0U]) ? (0x1fU & (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__instr
                                      [0U] >> 0x1bU))
                    : 0U)));
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mux_concat_rd[0U] 
        = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_out
        [1U];
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mux_concat_rd[1U] 
        = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mem_rd_data
        [1U];
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mux_concat_rd[2U] 
        = (IData)((((QData)((IData)(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__imm
                                    [2U])) << 0x20U) 
                   | (QData)((IData)(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pc4
                                     [4U]))));
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mux_concat_rd[3U] 
        = (IData)(((((QData)((IData)(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__imm
                                     [2U])) << 0x20U) 
                    | (QData)((IData)(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pc4
                                      [4U]))) >> 0x20U));
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__w_imm[0U] 
        = vlSymsp->TOP__riscv_top.u_riscv_cpu__DOT____Vcellout__u_riscv_immmext__o_imm_ext;
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_regfile_rd_data__DOT__mux_input_arr[0U] 
        = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mux_concat_rd[0U];
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_regfile_rd_data__DOT__mux_input_arr[1U] 
        = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mux_concat_rd[1U];
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_regfile_rd_data__DOT__mux_input_arr[2U] 
        = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mux_concat_rd[2U];
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_regfile_rd_data__DOT__mux_input_arr[3U] 
        = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mux_concat_rd[3U];
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rd_data[0U] 
        = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_regfile_rd_data__DOT__mux_input_arr
        [vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_rd
        [2U]];
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mux_concat_fwd_a[0U] 
        = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs1_data
        [0U];
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mux_concat_fwd_a[1U] 
        = (IData)((((QData)((IData)(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rd_data
                                    [0U])) << 0x20U) 
                   | (QData)((IData)(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_out
                                     [0U]))));
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mux_concat_fwd_a[2U] 
        = (IData)(((((QData)((IData)(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rd_data
                                     [0U])) << 0x20U) 
                    | (QData)((IData)(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_out
                                      [0U]))) >> 0x20U));
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mux_concat_fwd_b[0U] 
        = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs2_data
        [0U];
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mux_concat_fwd_b[1U] 
        = (IData)((((QData)((IData)(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rd_data
                                    [0U])) << 0x20U) 
                   | (QData)((IData)(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_out
                                     [0U]))));
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mux_concat_fwd_b[2U] 
        = (IData)(((((QData)((IData)(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rd_data
                                     [0U])) << 0x20U) 
                    | (QData)((IData)(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_out
                                      [0U]))) >> 0x20U));
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_fwd_a__DOT__mux_input_arr[0U] 
        = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mux_concat_fwd_a[0U];
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_fwd_a__DOT__mux_input_arr[1U] 
        = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mux_concat_fwd_a[1U];
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_fwd_a__DOT__mux_input_arr[2U] 
        = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mux_concat_fwd_a[2U];
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_fwd_b__DOT__mux_input_arr[0U] 
        = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mux_concat_fwd_b[0U];
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_fwd_b__DOT__mux_input_arr[1U] 
        = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mux_concat_fwd_b[1U];
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_fwd_b__DOT__mux_input_arr[2U] 
        = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mux_concat_fwd_b[2U];
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__fwd_a[0U] 
        = ((2U >= vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__fwd_sel_a
            [0U]) ? vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_fwd_a__DOT__mux_input_arr
           [vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__fwd_sel_a
           [0U]] : 0U);
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__w_fwd_b[0U] 
        = ((2U >= vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__fwd_sel_b
            [0U]) ? vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_fwd_b__DOT__mux_input_arr
           [vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__fwd_sel_b
           [0U]] : 0U);
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mux_concat_alu_a 
        = (((QData)((IData)(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pc
                            [2U])) << 0x20U) | (QData)((IData)(
                                                               vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__fwd_a
                                                               [0U])));
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mux_concat_alu_b 
        = (((QData)((IData)(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__imm
                            [0U])) << 0x20U) | (QData)((IData)(
                                                               vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__w_fwd_b
                                                               [0U])));
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_alu_a__DOT__mux_input_arr[0U] 
        = (IData)(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mux_concat_alu_a);
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_alu_a__DOT__mux_input_arr[1U] 
        = (IData)((vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mux_concat_alu_a 
                   >> 0x20U));
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_alu_b__DOT__mux_input_arr[0U] 
        = (IData)(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mux_concat_alu_b);
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_alu_b__DOT__mux_input_arr[1U] 
        = (IData)((vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mux_concat_alu_b 
                   >> 0x20U));
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_a[0U] 
        = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_alu_a__DOT__mux_input_arr
        [vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_alu_a
        [0U]];
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_b[0U] 
        = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_alu_b__DOT__mux_input_arr
        [vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_alu_b
        [0U]];
    vlSymsp->TOP__riscv_top.u_riscv_cpu__DOT____Vcellout__u_riscv_alu__o_alu_out 
        = ((8U & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_ctrl
            [0U]) ? ((4U & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_ctrl
                      [0U]) ? ((2U & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_ctrl
                                [0U]) ? 0U : ((1U & 
                                               vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_ctrl
                                               [0U])
                                               ? VL_SHIFTRS_III(32,32,5, 
                                                                vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_a
                                                                [0U], 
                                                                (0x1fU 
                                                                 & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_b
                                                                 [0U]))
                                               : 0U))
                      : ((2U & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_ctrl
                          [0U]) ? 0U : ((1U & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_ctrl
                                         [0U]) ? 0U
                                         : (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_a
                                            [0U] - 
                                            vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_b
                                            [0U]))))
            : ((4U & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_ctrl
                [0U]) ? ((2U & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_ctrl
                          [0U]) ? ((1U & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_ctrl
                                    [0U]) ? (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_a
                                             [0U] & 
                                             vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_b
                                             [0U]) : 
                                   (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_a
                                    [0U] | vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_b
                                    [0U])) : ((1U & 
                                               vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_ctrl
                                               [0U])
                                               ? (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_a
                                                  [0U] 
                                                  >> 
                                                  (0x1fU 
                                                   & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_b
                                                   [0U]))
                                               : (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_a
                                                  [0U] 
                                                  ^ 
                                                  vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_b
                                                  [0U])))
                : ((2U & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_ctrl
                    [0U]) ? ((1U & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_ctrl
                              [0U]) ? ((vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_a
                                        [0U] < vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_b
                                        [0U]) ? 1U : 0U)
                              : (VL_LTS_III(1,32,32, 
                                            vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_a
                                            [0U], vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_b
                                            [0U]) ? 1U
                                  : 0U)) : ((1U & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_ctrl
                                             [0U]) ? 
                                            (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_a
                                             [0U] << 
                                             (0x1fU 
                                              & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_b
                                              [0U]))
                                             : (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_a
                                                [0U] 
                                                + vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_b
                                                [0U])))));
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_pc[0U] 
        = ((0x63U == vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__opcode
            [1U]) ? (((0x63U == vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__opcode
                       [1U]) & ((4U & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
                                 [1U]) ? ((2U & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
                                           [1U]) ? 
                                          ((1U & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
                                            [1U]) ? 
                                           (0U == vlSymsp->TOP__riscv_top.u_riscv_cpu__DOT____Vcellout__u_riscv_alu__o_alu_out)
                                            : (0U != vlSymsp->TOP__riscv_top.u_riscv_cpu__DOT____Vcellout__u_riscv_alu__o_alu_out))
                                           : ((1U & 
                                               vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
                                               [1U])
                                               ? (0U 
                                                  == vlSymsp->TOP__riscv_top.u_riscv_cpu__DOT____Vcellout__u_riscv_alu__o_alu_out)
                                               : (0U 
                                                  != vlSymsp->TOP__riscv_top.u_riscv_cpu__DOT____Vcellout__u_riscv_alu__o_alu_out)))
                                 : ((~ (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
                                        [1U] >> 1U)) 
                                    & ((1U & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
                                        [1U]) ? (0U 
                                                 != vlSymsp->TOP__riscv_top.u_riscv_cpu__DOT____Vcellout__u_riscv_alu__o_alu_out)
                                        : (0U == vlSymsp->TOP__riscv_top.u_riscv_cpu__DOT____Vcellout__u_riscv_alu__o_alu_out)))))
                      ? 1U : 0U) : ((0x6fU == vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__opcode
                                     [1U]) ? 1U : (
                                                   (0x67U 
                                                    == 
                                                    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__opcode
                                                    [1U])
                                                    ? 2U
                                                    : 0U)));
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__w_alu_out[0U] 
        = vlSymsp->TOP__riscv_top.u_riscv_cpu__DOT____Vcellout__u_riscv_alu__o_alu_out;
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__flush[0U] 
        = (0U != vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_pc
           [0U]);
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__flush[1U] 
        = ((IData)(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_hazard__DOT__stall) 
           | (0U != vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_pc
              [0U]));
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mux_concat_pc[0U] 
        = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pc4
        [0U];
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mux_concat_pc[1U] 
        = (IData)((((QData)((IData)(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__w_alu_out
                                    [0U])) << 0x20U) 
                   | (QData)((IData)(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pcimm
                                     [0U]))));
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mux_concat_pc[2U] 
        = (IData)(((((QData)((IData)(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__w_alu_out
                                     [0U])) << 0x20U) 
                    | (QData)((IData)(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pcimm
                                      [0U]))) >> 0x20U));
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_pc__DOT__mux_input_arr[0U] 
        = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mux_concat_pc[0U];
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_pc__DOT__mux_input_arr[1U] 
        = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mux_concat_pc[1U];
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_pc__DOT__mux_input_arr[2U] 
        = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mux_concat_pc[2U];
}

VL_INLINE_OPT void Vriscv_top_riscv_top::_sequent__TOP__riscv_top__4(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vriscv_top_riscv_top::_sequent__TOP__riscv_top__4\n"); );
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*4:0*/ __Vdlyvdim0__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers__v0;
    IData/*31:0*/ __Vdlyvval__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers__v0;
    // Body
    __Vdlyvval__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers__v0 
        = ((vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__reg_wr_en
            [2U] & (0U != vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rd
                    [3U])) ? vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rd_data
           [0U] : vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers
           [vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rd
           [3U]]);
    __Vdlyvdim0__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers__v0 
        = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rd
        [3U];
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[__Vdlyvdim0__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers__v0] 
        = __Vdlyvval__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers__v0;
}

VL_INLINE_OPT void Vriscv_top_riscv_top::_multiclk__TOP__riscv_top__5(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vriscv_top_riscv_top::_multiclk__TOP__riscv_top__5\n"); );
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__w_rs2_data[0U] 
        = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers
        [vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs2
        [0U]];
    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__w_rs1_data[0U] 
        = vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers
        [vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs1
        [0U]];
}
