// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vriscv_top__Syms.h"


void Vriscv_top::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vriscv_top__Syms* __restrict vlSymsp = static_cast<Vriscv_top__Syms*>(userp);
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vriscv_top::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vriscv_top__Syms* __restrict vlSymsp = static_cast<Vriscv_top__Syms*>(userp);
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[0U])) {
            tracep->chgWData(oldp+0,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_imem__DOT__FILE_TEXT_MIF),1024);
            tracep->chgWData(oldp+32,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_dmem__DOT__FILE_DATA_MIF),1024);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgIData(oldp+64,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pc
                                      [0U]),32);
            tracep->chgIData(oldp+65,(vlSymsp->TOP__riscv_top.o_riscv_imem_instr),32);
            tracep->chgIData(oldp+66,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_out
                                      [0U]),32);
            tracep->chgBit(oldp+67,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mem_wr_en
                                    [1U]));
            tracep->chgCData(oldp+68,(vlSymsp->TOP__riscv_top.o_riscv_dmem_strb),4);
            tracep->chgIData(oldp+69,(vlSymsp->TOP__riscv_top.o_riscv_dmem_wr_data),32);
            tracep->chgIData(oldp+70,(vlSymsp->TOP__riscv_top.o_riscv_dmem_rd_data),32);
            tracep->chgCData(oldp+71,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3[0]),3);
            tracep->chgCData(oldp+72,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3[1]),3);
            tracep->chgCData(oldp+73,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3[2]),3);
            tracep->chgCData(oldp+74,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__opcode[0]),7);
            tracep->chgCData(oldp+75,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__opcode[1]),7);
            tracep->chgBit(oldp+76,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct7_5b[0]));
            tracep->chgBit(oldp+77,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__w_reg_wr_en[0]));
            tracep->chgBit(oldp+78,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__reg_wr_en[0]));
            tracep->chgBit(oldp+79,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__reg_wr_en[1]));
            tracep->chgBit(oldp+80,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__reg_wr_en[2]));
            tracep->chgCData(oldp+81,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__w_src_rd[0]),2);
            tracep->chgCData(oldp+82,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_rd[0]),2);
            tracep->chgCData(oldp+83,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_rd[1]),2);
            tracep->chgCData(oldp+84,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_rd[2]),2);
            tracep->chgBit(oldp+85,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__w_mem_wr_en[0]));
            tracep->chgBit(oldp+86,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mem_wr_en[0]));
            tracep->chgBit(oldp+87,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mem_wr_en[1]));
            tracep->chgCData(oldp+88,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__w_alu_ctrl[0]),4);
            tracep->chgCData(oldp+89,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_ctrl[0]),4);
            tracep->chgBit(oldp+90,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__w_src_alu_a[0]));
            tracep->chgBit(oldp+91,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__w_src_alu_b[0]));
            tracep->chgBit(oldp+92,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_alu_a[0]));
            tracep->chgBit(oldp+93,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_alu_b[0]));
            tracep->chgCData(oldp+94,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_imm[0]),3);
            tracep->chgCData(oldp+95,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_pc[0]),2);
            tracep->chgIData(oldp+96,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pc[0]),32);
            tracep->chgIData(oldp+97,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pc[1]),32);
            tracep->chgIData(oldp+98,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pc[2]),32);
            tracep->chgIData(oldp+99,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pc4[0]),32);
            tracep->chgIData(oldp+100,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pc4[1]),32);
            tracep->chgIData(oldp+101,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pc4[2]),32);
            tracep->chgIData(oldp+102,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pc4[3]),32);
            tracep->chgIData(oldp+103,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pc4[4]),32);
            tracep->chgIData(oldp+104,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pcimm[0]),32);
            tracep->chgIData(oldp+105,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__instr[0]),32);
            tracep->chgIData(oldp+106,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__w_imm[0]),32);
            tracep->chgIData(oldp+107,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__imm[0]),32);
            tracep->chgIData(oldp+108,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__imm[1]),32);
            tracep->chgIData(oldp+109,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__imm[2]),32);
            tracep->chgCData(oldp+110,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs1[0]),5);
            tracep->chgCData(oldp+111,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs1[1]),5);
            tracep->chgCData(oldp+112,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs2[0]),5);
            tracep->chgCData(oldp+113,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs2[1]),5);
            tracep->chgIData(oldp+114,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs1_data[0]),32);
            tracep->chgIData(oldp+115,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs2_data[0]),32);
            tracep->chgCData(oldp+116,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rd[0]),5);
            tracep->chgCData(oldp+117,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rd[1]),5);
            tracep->chgCData(oldp+118,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rd[2]),5);
            tracep->chgCData(oldp+119,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rd[3]),5);
            tracep->chgIData(oldp+120,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rd_data[0]),32);
            tracep->chgIData(oldp+121,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mem_rd_data[0]),32);
            tracep->chgIData(oldp+122,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mem_rd_data[1]),32);
            tracep->chgIData(oldp+123,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__fwd_a[0]),32);
            tracep->chgIData(oldp+124,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__w_fwd_b[0]),32);
            tracep->chgIData(oldp+125,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__fwd_b[0]),32);
            tracep->chgIData(oldp+126,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_a[0]),32);
            tracep->chgIData(oldp+127,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_b[0]),32);
            tracep->chgIData(oldp+128,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__w_alu_out[0]),32);
            tracep->chgIData(oldp+129,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_out[0]),32);
            tracep->chgIData(oldp+130,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_out[1]),32);
            tracep->chgCData(oldp+131,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__fwd_sel_a[0]),2);
            tracep->chgCData(oldp+132,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__fwd_sel_b[0]),2);
            tracep->chgBit(oldp+133,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__stall[0]));
            tracep->chgBit(oldp+134,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__stall[1]));
            tracep->chgBit(oldp+135,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__flush[0]));
            tracep->chgBit(oldp+136,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__flush[1]));
            tracep->chgWData(oldp+137,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mux_concat_pc),96);
            tracep->chgWData(oldp+140,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mux_concat_fwd_a),96);
            tracep->chgWData(oldp+143,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mux_concat_fwd_b),96);
            tracep->chgQData(oldp+146,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mux_concat_alu_a),64);
            tracep->chgQData(oldp+148,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mux_concat_alu_b),64);
            tracep->chgWData(oldp+150,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mux_concat_rd),128);
            tracep->chgIData(oldp+154,(((2U >= vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_pc
                                         [0U]) ? vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_pc__DOT__mux_input_arr
                                        [vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_pc
                                        [0U]] : 0U)),32);
            tracep->chgCData(oldp+155,(((((vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs1
                                           [1U] == 
                                           vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rd
                                           [2U]) & 
                                          vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__reg_wr_en
                                          [1U]) & (0U 
                                                   != 
                                                   vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs1
                                                   [1U]))
                                         ? 1U : (((
                                                   (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs1
                                                    [1U] 
                                                    == 
                                                    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rd
                                                    [3U]) 
                                                   & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__reg_wr_en
                                                   [2U]) 
                                                  & (0U 
                                                     != 
                                                     vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs1
                                                     [1U]))
                                                  ? 2U
                                                  : 0U))),2);
            tracep->chgCData(oldp+156,(((((vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs2
                                           [1U] == 
                                           vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rd
                                           [2U]) & 
                                          vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__reg_wr_en
                                          [1U]) & (0U 
                                                   != 
                                                   vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs2
                                                   [1U]))
                                         ? 1U : (((
                                                   (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs2
                                                    [1U] 
                                                    == 
                                                    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rd
                                                    [3U]) 
                                                   & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__reg_wr_en
                                                   [2U]) 
                                                  & (0U 
                                                     != 
                                                     vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs2
                                                     [1U]))
                                                  ? 2U
                                                  : 0U))),2);
            tracep->chgBit(oldp+157,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_hazard__DOT__stall));
            tracep->chgBit(oldp+158,((0U != vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_pc
                                      [0U])));
            tracep->chgBit(oldp+159,(((IData)(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_hazard__DOT__stall) 
                                      | (0U != vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_pc
                                         [0U]))));
            tracep->chgCData(oldp+160,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_pc
                                       [0U]),2);
            tracep->chgCData(oldp+161,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_rd
                                       [0U]),2);
            tracep->chgCData(oldp+162,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs1
                                       [0U]),5);
            tracep->chgCData(oldp+163,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs2
                                       [0U]),5);
            tracep->chgCData(oldp+164,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs1
                                       [1U]),5);
            tracep->chgCData(oldp+165,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs2
                                       [1U]),5);
            tracep->chgCData(oldp+166,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rd
                                       [1U]),5);
            tracep->chgCData(oldp+167,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rd
                                       [2U]),5);
            tracep->chgCData(oldp+168,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rd
                                       [3U]),5);
            tracep->chgBit(oldp+169,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__reg_wr_en
                                     [0U]));
            tracep->chgBit(oldp+170,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__reg_wr_en
                                     [1U]));
            tracep->chgBit(oldp+171,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__reg_wr_en
                                     [2U]));
            tracep->chgIData(oldp+172,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_pc__DOT__mux_input_arr[0]),32);
            tracep->chgIData(oldp+173,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_pc__DOT__mux_input_arr[1]),32);
            tracep->chgIData(oldp+174,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_pc__DOT__mux_input_arr[2]),32);
            tracep->chgIData(oldp+175,(((IData)(4U) 
                                        + vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pc
                                        [0U])),32);
            tracep->chgCData(oldp+176,(vlSymsp->TOP__riscv_top.u_riscv_cpu__DOT____Vcellout__u_riscv_ctrl__o_ctrl_src_imm),3);
            tracep->chgCData(oldp+177,(vlSymsp->TOP__riscv_top.u_riscv_cpu__DOT____Vcellout__u_riscv_ctrl__o_ctrl_src_rd),2);
            tracep->chgBit(oldp+178,((0x17U == vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__opcode
                                      [0U])));
            tracep->chgBit(oldp+179,(vlSymsp->TOP__riscv_top.u_riscv_cpu__DOT____Vcellout__u_riscv_ctrl__o_ctrl_src_alu_b));
            tracep->chgBit(oldp+180,((1U & (~ ((0x23U 
                                                == 
                                                vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__opcode
                                                [0U]) 
                                               | (0x63U 
                                                  == 
                                                  vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__opcode
                                                  [0U]))))));
            tracep->chgBit(oldp+181,((0x23U == vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__opcode
                                      [0U])));
            tracep->chgCData(oldp+182,(vlSymsp->TOP__riscv_top.u_riscv_cpu__DOT____Vcellout__u_riscv_ctrl__o_ctrl_alu_ctrl),4);
            tracep->chgCData(oldp+183,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__opcode
                                       [0U]),7);
            tracep->chgCData(oldp+184,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
                                       [0U]),3);
            tracep->chgBit(oldp+185,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct7_5b
                                     [0U]));
            tracep->chgWData(oldp+186,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR),256);
            tracep->chgIData(oldp+194,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rd_data
                                       [0U]),32);
            tracep->chgIData(oldp+195,(vlSymsp->TOP__riscv_top.u_riscv_cpu__DOT____Vcellout__u_riscv_immmext__o_imm_ext),32);
            tracep->chgIData(oldp+196,((0x1ffffffU 
                                        & (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__instr
                                           [0U] >> 7U))),32);
            tracep->chgCData(oldp+197,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_imm
                                       [0U]),3);
            tracep->chgIData(oldp+198,(((2U >= vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__fwd_sel_a
                                         [0U]) ? vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_fwd_a__DOT__mux_input_arr
                                        [vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__fwd_sel_a
                                        [0U]] : 0U)),32);
            tracep->chgCData(oldp+199,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__fwd_sel_a
                                       [0U]),2);
            tracep->chgIData(oldp+200,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_fwd_a__DOT__mux_input_arr[0]),32);
            tracep->chgIData(oldp+201,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_fwd_a__DOT__mux_input_arr[1]),32);
            tracep->chgIData(oldp+202,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_fwd_a__DOT__mux_input_arr[2]),32);
            tracep->chgIData(oldp+203,(((2U >= vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__fwd_sel_b
                                         [0U]) ? vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_fwd_b__DOT__mux_input_arr
                                        [vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__fwd_sel_b
                                        [0U]] : 0U)),32);
            tracep->chgCData(oldp+204,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__fwd_sel_b
                                       [0U]),2);
            tracep->chgIData(oldp+205,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_fwd_b__DOT__mux_input_arr[0]),32);
            tracep->chgIData(oldp+206,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_fwd_b__DOT__mux_input_arr[1]),32);
            tracep->chgIData(oldp+207,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_fwd_b__DOT__mux_input_arr[2]),32);
            tracep->chgIData(oldp+208,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_alu_a__DOT__mux_input_arr
                                       [vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_alu_a
                                       [0U]]),32);
            tracep->chgBit(oldp+209,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_alu_a
                                     [0U]));
            tracep->chgIData(oldp+210,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_alu_a__DOT__mux_input_arr[0]),32);
            tracep->chgIData(oldp+211,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_alu_a__DOT__mux_input_arr[1]),32);
            tracep->chgIData(oldp+212,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_alu_b__DOT__mux_input_arr
                                       [vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_alu_b
                                       [0U]]),32);
            tracep->chgBit(oldp+213,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_alu_b
                                     [0U]));
            tracep->chgIData(oldp+214,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_alu_b__DOT__mux_input_arr[0]),32);
            tracep->chgIData(oldp+215,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_alu_b__DOT__mux_input_arr[1]),32);
            tracep->chgIData(oldp+216,(vlSymsp->TOP__riscv_top.u_riscv_cpu__DOT____Vcellout__u_riscv_alu__o_alu_out),32);
            tracep->chgCData(oldp+217,(((0x63U == vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__opcode
                                         [1U]) ? ((
                                                   (0x63U 
                                                    == 
                                                    vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__opcode
                                                    [1U]) 
                                                   & ((4U 
                                                       & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
                                                       [1U])
                                                       ? 
                                                      ((2U 
                                                        & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
                                                        [1U])
                                                        ? 
                                                       ((1U 
                                                         & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
                                                         [1U])
                                                         ? 
                                                        (0U 
                                                         == vlSymsp->TOP__riscv_top.u_riscv_cpu__DOT____Vcellout__u_riscv_alu__o_alu_out)
                                                         : 
                                                        (0U 
                                                         != vlSymsp->TOP__riscv_top.u_riscv_cpu__DOT____Vcellout__u_riscv_alu__o_alu_out))
                                                        : 
                                                       ((1U 
                                                         & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
                                                         [1U])
                                                         ? 
                                                        (0U 
                                                         == vlSymsp->TOP__riscv_top.u_riscv_cpu__DOT____Vcellout__u_riscv_alu__o_alu_out)
                                                         : 
                                                        (0U 
                                                         != vlSymsp->TOP__riscv_top.u_riscv_cpu__DOT____Vcellout__u_riscv_alu__o_alu_out)))
                                                       : 
                                                      ((~ 
                                                        (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
                                                         [1U] 
                                                         >> 1U)) 
                                                       & ((1U 
                                                           & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
                                                           [1U])
                                                           ? 
                                                          (0U 
                                                           != vlSymsp->TOP__riscv_top.u_riscv_cpu__DOT____Vcellout__u_riscv_alu__o_alu_out)
                                                           : 
                                                          (0U 
                                                           == vlSymsp->TOP__riscv_top.u_riscv_cpu__DOT____Vcellout__u_riscv_alu__o_alu_out)))))
                                                   ? 1U
                                                   : 0U)
                                         : ((0x6fU 
                                             == vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__opcode
                                             [1U]) ? 1U
                                             : ((0x67U 
                                                 == 
                                                 vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__opcode
                                                 [1U])
                                                 ? 2U
                                                 : 0U)))),2);
            tracep->chgIData(oldp+218,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_a
                                       [0U]),32);
            tracep->chgIData(oldp+219,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_b
                                       [0U]),32);
            tracep->chgCData(oldp+220,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__opcode
                                       [1U]),7);
            tracep->chgCData(oldp+221,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
                                       [1U]),3);
            tracep->chgCData(oldp+222,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_ctrl
                                       [0U]),4);
            tracep->chgBit(oldp+223,((0U == vlSymsp->TOP__riscv_top.u_riscv_cpu__DOT____Vcellout__u_riscv_alu__o_alu_out)));
            tracep->chgBit(oldp+224,(((0x63U == vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__opcode
                                       [1U]) & ((4U 
                                                 & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
                                                 [1U])
                                                 ? 
                                                ((2U 
                                                  & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
                                                  [1U])
                                                  ? 
                                                 ((1U 
                                                   & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
                                                   [1U])
                                                   ? 
                                                  (0U 
                                                   == vlSymsp->TOP__riscv_top.u_riscv_cpu__DOT____Vcellout__u_riscv_alu__o_alu_out)
                                                   : 
                                                  (0U 
                                                   != vlSymsp->TOP__riscv_top.u_riscv_cpu__DOT____Vcellout__u_riscv_alu__o_alu_out))
                                                  : 
                                                 ((1U 
                                                   & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
                                                   [1U])
                                                   ? 
                                                  (0U 
                                                   == vlSymsp->TOP__riscv_top.u_riscv_cpu__DOT____Vcellout__u_riscv_alu__o_alu_out)
                                                   : 
                                                  (0U 
                                                   != vlSymsp->TOP__riscv_top.u_riscv_cpu__DOT____Vcellout__u_riscv_alu__o_alu_out)))
                                                 : 
                                                ((~ 
                                                  (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
                                                   [1U] 
                                                   >> 1U)) 
                                                 & ((1U 
                                                     & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
                                                     [1U])
                                                     ? 
                                                    (0U 
                                                     != vlSymsp->TOP__riscv_top.u_riscv_cpu__DOT____Vcellout__u_riscv_alu__o_alu_out)
                                                     : 
                                                    (0U 
                                                     == vlSymsp->TOP__riscv_top.u_riscv_cpu__DOT____Vcellout__u_riscv_alu__o_alu_out)))))));
            tracep->chgQData(oldp+225,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_alu__DOT__DEBUG_ALU_OP),64);
            tracep->chgIData(oldp+227,((vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pc
                                        [2U] + vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__imm
                                        [0U])),32);
            tracep->chgIData(oldp+228,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pc
                                       [2U]),32);
            tracep->chgIData(oldp+229,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__imm
                                       [0U]),32);
            tracep->chgIData(oldp+230,(((4U & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
                                         [2U]) ? ((2U 
                                                   & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
                                                   [2U])
                                                   ? 0U
                                                   : 
                                                  ((1U 
                                                    & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
                                                    [2U])
                                                    ? 
                                                   (0xffffU 
                                                    & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)
                                                    : 
                                                   (0xffU 
                                                    & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)))
                                         : ((2U & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
                                             [2U]) ? 
                                            ((1U & 
                                              vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
                                              [2U])
                                              ? 0U : vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)
                                             : ((1U 
                                                 & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
                                                 [2U])
                                                 ? 
                                                ((0xffff0000U 
                                                  & ((- (IData)(
                                                                (1U 
                                                                 & (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data 
                                                                    >> 0xfU)))) 
                                                     << 0x10U)) 
                                                 | (0xffffU 
                                                    & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data))
                                                 : 
                                                ((0xffffff00U 
                                                  & ((- (IData)(
                                                                (1U 
                                                                 & (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data 
                                                                    >> 7U)))) 
                                                     << 8U)) 
                                                 | (0xffU 
                                                    & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)))))),32);
            tracep->chgIData(oldp+231,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__fwd_b
                                       [0U]),32);
            tracep->chgCData(oldp+232,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
                                       [2U]),3);
            tracep->chgCData(oldp+233,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_dmem_interface__DOT__dmem_intf_strb),4);
            tracep->chgIData(oldp+234,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data),32);
            tracep->chgIData(oldp+235,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_regfile_rd_data__DOT__mux_input_arr
                                       [vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_rd
                                       [2U]]),32);
            tracep->chgCData(oldp+236,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_rd
                                       [2U]),2);
            tracep->chgIData(oldp+237,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_regfile_rd_data__DOT__mux_input_arr[0]),32);
            tracep->chgIData(oldp+238,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_regfile_rd_data__DOT__mux_input_arr[1]),32);
            tracep->chgIData(oldp+239,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_regfile_rd_data__DOT__mux_input_arr[2]),32);
            tracep->chgIData(oldp+240,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_regfile_rd_data__DOT__mux_input_arr[3]),32);
            tracep->chgSData(oldp+241,((0x3fffU & (
                                                   vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pc
                                                   [0U] 
                                                   >> 2U))),14);
            tracep->chgSData(oldp+242,((0x3fffU & (
                                                   vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_out
                                                   [0U] 
                                                   >> 2U))),14);
            tracep->chgIData(oldp+243,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_dmem__DOT__i),32);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[2U])) {
            tracep->chgIData(oldp+244,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[0]),32);
            tracep->chgIData(oldp+245,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[1]),32);
            tracep->chgIData(oldp+246,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[2]),32);
            tracep->chgIData(oldp+247,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[3]),32);
            tracep->chgIData(oldp+248,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[4]),32);
            tracep->chgIData(oldp+249,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[5]),32);
            tracep->chgIData(oldp+250,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[6]),32);
            tracep->chgIData(oldp+251,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[7]),32);
            tracep->chgIData(oldp+252,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[8]),32);
            tracep->chgIData(oldp+253,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[9]),32);
            tracep->chgIData(oldp+254,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[10]),32);
            tracep->chgIData(oldp+255,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[11]),32);
            tracep->chgIData(oldp+256,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[12]),32);
            tracep->chgIData(oldp+257,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[13]),32);
            tracep->chgIData(oldp+258,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[14]),32);
            tracep->chgIData(oldp+259,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[15]),32);
            tracep->chgIData(oldp+260,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[16]),32);
            tracep->chgIData(oldp+261,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[17]),32);
            tracep->chgIData(oldp+262,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[18]),32);
            tracep->chgIData(oldp+263,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[19]),32);
            tracep->chgIData(oldp+264,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[20]),32);
            tracep->chgIData(oldp+265,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[21]),32);
            tracep->chgIData(oldp+266,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[22]),32);
            tracep->chgIData(oldp+267,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[23]),32);
            tracep->chgIData(oldp+268,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[24]),32);
            tracep->chgIData(oldp+269,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[25]),32);
            tracep->chgIData(oldp+270,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[26]),32);
            tracep->chgIData(oldp+271,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[27]),32);
            tracep->chgIData(oldp+272,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[28]),32);
            tracep->chgIData(oldp+273,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[29]),32);
            tracep->chgIData(oldp+274,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[30]),32);
            tracep->chgIData(oldp+275,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[31]),32);
        }
        tracep->chgIData(oldp+276,(vlTOPp->o_riscv_imem_pc),32);
        tracep->chgIData(oldp+277,(vlTOPp->o_riscv_imem_instr),32);
        tracep->chgIData(oldp+278,(vlTOPp->o_riscv_dmem_addr),32);
        tracep->chgBit(oldp+279,(vlTOPp->o_riscv_dmem_wr_en));
        tracep->chgCData(oldp+280,(vlTOPp->o_riscv_dmem_strb),4);
        tracep->chgIData(oldp+281,(vlTOPp->o_riscv_dmem_wr_data),32);
        tracep->chgIData(oldp+282,(vlTOPp->o_riscv_dmem_rd_data),32);
        tracep->chgBit(oldp+283,(vlTOPp->i_clk));
        tracep->chgBit(oldp+284,(vlTOPp->i_rstn));
        tracep->chgBit(oldp+285,(vlSymsp->TOP__riscv_top.i_clk));
        tracep->chgBit(oldp+286,(vlSymsp->TOP__riscv_top.i_rstn));
        tracep->chgIData(oldp+287,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__w_rs1_data[0]),32);
        tracep->chgIData(oldp+288,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__w_rs2_data[0]),32);
        tracep->chgIData(oldp+289,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers
                                   [vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs1
                                   [0U]]),32);
        tracep->chgIData(oldp+290,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers
                                   [vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs2
                                   [0U]]),32);
        tracep->chgBit(oldp+291,((1U & (~ (IData)(vlSymsp->TOP__riscv_top.i_clk)))));
    }
}

void Vriscv_top::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vriscv_top__Syms* __restrict vlSymsp = static_cast<Vriscv_top__Syms*>(userp);
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
        vlTOPp->__Vm_traceActivity[2U] = 0U;
    }
}
