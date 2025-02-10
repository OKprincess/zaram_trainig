// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vriscv_top__Syms.h"


//======================

void Vriscv_top::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vriscv_top::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vriscv_top__Syms* __restrict vlSymsp = static_cast<Vriscv_top__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vriscv_top::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vriscv_top::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vriscv_top__Syms* __restrict vlSymsp = static_cast<Vriscv_top__Syms*>(userp);
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vriscv_top::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vriscv_top__Syms* __restrict vlSymsp = static_cast<Vriscv_top__Syms*>(userp);
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBus(c+277,"o_riscv_imem_pc", false,-1, 31,0);
        tracep->declBus(c+278,"o_riscv_imem_instr", false,-1, 31,0);
        tracep->declBus(c+279,"o_riscv_dmem_addr", false,-1, 31,0);
        tracep->declBit(c+280,"o_riscv_dmem_wr_en", false,-1);
        tracep->declBus(c+281,"o_riscv_dmem_strb", false,-1, 3,0);
        tracep->declBus(c+282,"o_riscv_dmem_wr_data", false,-1, 31,0);
        tracep->declBus(c+283,"o_riscv_dmem_rd_data", false,-1, 31,0);
        tracep->declBit(c+284,"i_clk", false,-1);
        tracep->declBit(c+285,"i_rstn", false,-1);
        tracep->declBus(c+293,"riscv_top REGISTER_INIT", false,-1, 31,0);
        tracep->declBus(c+65,"riscv_top o_riscv_imem_pc", false,-1, 31,0);
        tracep->declBus(c+66,"riscv_top o_riscv_imem_instr", false,-1, 31,0);
        tracep->declBus(c+67,"riscv_top o_riscv_dmem_addr", false,-1, 31,0);
        tracep->declBit(c+68,"riscv_top o_riscv_dmem_wr_en", false,-1);
        tracep->declBus(c+69,"riscv_top o_riscv_dmem_strb", false,-1, 3,0);
        tracep->declBus(c+70,"riscv_top o_riscv_dmem_wr_data", false,-1, 31,0);
        tracep->declBus(c+71,"riscv_top o_riscv_dmem_rd_data", false,-1, 31,0);
        tracep->declBit(c+286,"riscv_top i_clk", false,-1);
        tracep->declBit(c+287,"riscv_top i_rstn", false,-1);
        tracep->declBus(c+65,"riscv_top u_riscv_cpu o_cpu_pc", false,-1, 31,0);
        tracep->declBus(c+67,"riscv_top u_riscv_cpu o_cpu_mem_addr", false,-1, 31,0);
        tracep->declBit(c+68,"riscv_top u_riscv_cpu o_cpu_mem_wr_en", false,-1);
        tracep->declBus(c+69,"riscv_top u_riscv_cpu o_cpu_mem_strb", false,-1, 3,0);
        tracep->declBus(c+70,"riscv_top u_riscv_cpu o_cpu_mem_wr_data", false,-1, 31,0);
        tracep->declBus(c+66,"riscv_top u_riscv_cpu i_cpu_instr", false,-1, 31,0);
        tracep->declBus(c+71,"riscv_top u_riscv_cpu i_cpu_mem_rd_data", false,-1, 31,0);
        tracep->declBit(c+286,"riscv_top u_riscv_cpu i_clk", false,-1);
        tracep->declBit(c+287,"riscv_top u_riscv_cpu i_rstn", false,-1);
        tracep->declBus(c+293,"riscv_top u_riscv_cpu IF", false,-1, 31,0);
        tracep->declBus(c+294,"riscv_top u_riscv_cpu ID", false,-1, 31,0);
        tracep->declBus(c+295,"riscv_top u_riscv_cpu EX", false,-1, 31,0);
        tracep->declBus(c+296,"riscv_top u_riscv_cpu MM", false,-1, 31,0);
        tracep->declBus(c+297,"riscv_top u_riscv_cpu WB", false,-1, 31,0);
        {int i; for (i=0; i<3; i++) {
                tracep->declBus(c+72+i*1,"riscv_top u_riscv_cpu funct3", true,(i+1), 2,0);}}
        {int i; for (i=0; i<2; i++) {
                tracep->declBus(c+75+i*1,"riscv_top u_riscv_cpu opcode", true,(i+1), 6,0);}}
        {int i; for (i=0; i<1; i++) {
                tracep->declBus(c+77+i*1,"riscv_top u_riscv_cpu funct7_5b", true,(i+1), 0,0);}}
        {int i; for (i=0; i<1; i++) {
                tracep->declBus(c+78+i*1,"riscv_top u_riscv_cpu w_reg_wr_en", true,(i+1), 0,0);}}
        {int i; for (i=0; i<3; i++) {
                tracep->declBus(c+79+i*1,"riscv_top u_riscv_cpu reg_wr_en", true,(i+2), 0,0);}}
        {int i; for (i=0; i<1; i++) {
                tracep->declBus(c+82+i*1,"riscv_top u_riscv_cpu w_src_rd", true,(i+1), 1,0);}}
        {int i; for (i=0; i<3; i++) {
                tracep->declBus(c+83+i*1,"riscv_top u_riscv_cpu src_rd", true,(i+2), 1,0);}}
        {int i; for (i=0; i<1; i++) {
                tracep->declBus(c+86+i*1,"riscv_top u_riscv_cpu w_mem_wr_en", true,(i+1), 0,0);}}
        {int i; for (i=0; i<2; i++) {
                tracep->declBus(c+87+i*1,"riscv_top u_riscv_cpu mem_wr_en", true,(i+2), 0,0);}}
        {int i; for (i=0; i<1; i++) {
                tracep->declBus(c+89+i*1,"riscv_top u_riscv_cpu w_alu_ctrl", true,(i+1), 3,0);}}
        {int i; for (i=0; i<1; i++) {
                tracep->declBus(c+90+i*1,"riscv_top u_riscv_cpu alu_ctrl", true,(i+2), 3,0);}}
        {int i; for (i=0; i<1; i++) {
                tracep->declBus(c+91+i*1,"riscv_top u_riscv_cpu w_src_alu_a", true,(i+1), 0,0);}}
        {int i; for (i=0; i<1; i++) {
                tracep->declBus(c+92+i*1,"riscv_top u_riscv_cpu w_src_alu_b", true,(i+1), 0,0);}}
        {int i; for (i=0; i<1; i++) {
                tracep->declBus(c+93+i*1,"riscv_top u_riscv_cpu src_alu_a", true,(i+2), 0,0);}}
        {int i; for (i=0; i<1; i++) {
                tracep->declBus(c+94+i*1,"riscv_top u_riscv_cpu src_alu_b", true,(i+2), 0,0);}}
        {int i; for (i=0; i<1; i++) {
                tracep->declBus(c+95+i*1,"riscv_top u_riscv_cpu src_imm", true,(i+1), 2,0);}}
        {int i; for (i=0; i<1; i++) {
                tracep->declBus(c+96+i*1,"riscv_top u_riscv_cpu src_pc", true,(i+2), 1,0);}}
        {int i; for (i=0; i<3; i++) {
                tracep->declBus(c+97+i*1,"riscv_top u_riscv_cpu pc", true,(i+0), 31,0);}}
        {int i; for (i=0; i<5; i++) {
                tracep->declBus(c+100+i*1,"riscv_top u_riscv_cpu pc4", true,(i+0), 31,0);}}
        {int i; for (i=0; i<1; i++) {
                tracep->declBus(c+105+i*1,"riscv_top u_riscv_cpu pcimm", true,(i+2), 31,0);}}
        {int i; for (i=0; i<1; i++) {
                tracep->declBus(c+106+i*1,"riscv_top u_riscv_cpu instr", true,(i+1), 31,0);}}
        {int i; for (i=0; i<1; i++) {
                tracep->declBus(c+107+i*1,"riscv_top u_riscv_cpu w_imm", true,(i+1), 31,0);}}
        {int i; for (i=0; i<3; i++) {
                tracep->declBus(c+108+i*1,"riscv_top u_riscv_cpu imm", true,(i+2), 31,0);}}
        {int i; for (i=0; i<2; i++) {
                tracep->declBus(c+111+i*1,"riscv_top u_riscv_cpu rs1", true,(i+1), 4,0);}}
        {int i; for (i=0; i<2; i++) {
                tracep->declBus(c+113+i*1,"riscv_top u_riscv_cpu rs2", true,(i+1), 4,0);}}
        {int i; for (i=0; i<1; i++) {
                tracep->declBus(c+288+i*1,"riscv_top u_riscv_cpu w_rs1_data", true,(i+1), 31,0);}}
        {int i; for (i=0; i<1; i++) {
                tracep->declBus(c+289+i*1,"riscv_top u_riscv_cpu w_rs2_data", true,(i+1), 31,0);}}
        {int i; for (i=0; i<1; i++) {
                tracep->declBus(c+115+i*1,"riscv_top u_riscv_cpu rs1_data", true,(i+2), 31,0);}}
        {int i; for (i=0; i<1; i++) {
                tracep->declBus(c+116+i*1,"riscv_top u_riscv_cpu rs2_data", true,(i+2), 31,0);}}
        {int i; for (i=0; i<4; i++) {
                tracep->declBus(c+117+i*1,"riscv_top u_riscv_cpu rd", true,(i+1), 4,0);}}
        {int i; for (i=0; i<1; i++) {
                tracep->declBus(c+121+i*1,"riscv_top u_riscv_cpu rd_data", true,(i+4), 31,0);}}
        {int i; for (i=0; i<2; i++) {
                tracep->declBus(c+122+i*1,"riscv_top u_riscv_cpu mem_rd_data", true,(i+3), 31,0);}}
        {int i; for (i=0; i<1; i++) {
                tracep->declBus(c+124+i*1,"riscv_top u_riscv_cpu fwd_a", true,(i+2), 31,0);}}
        {int i; for (i=0; i<1; i++) {
                tracep->declBus(c+125+i*1,"riscv_top u_riscv_cpu w_fwd_b", true,(i+2), 31,0);}}
        {int i; for (i=0; i<1; i++) {
                tracep->declBus(c+126+i*1,"riscv_top u_riscv_cpu fwd_b", true,(i+3), 31,0);}}
        {int i; for (i=0; i<1; i++) {
                tracep->declBus(c+127+i*1,"riscv_top u_riscv_cpu alu_a", true,(i+2), 31,0);}}
        {int i; for (i=0; i<1; i++) {
                tracep->declBus(c+128+i*1,"riscv_top u_riscv_cpu alu_b", true,(i+2), 31,0);}}
        {int i; for (i=0; i<1; i++) {
                tracep->declBus(c+129+i*1,"riscv_top u_riscv_cpu w_alu_out", true,(i+2), 31,0);}}
        {int i; for (i=0; i<2; i++) {
                tracep->declBus(c+130+i*1,"riscv_top u_riscv_cpu alu_out", true,(i+3), 31,0);}}
        {int i; for (i=0; i<1; i++) {
                tracep->declBus(c+132+i*1,"riscv_top u_riscv_cpu fwd_sel_a", true,(i+2), 1,0);}}
        {int i; for (i=0; i<1; i++) {
                tracep->declBus(c+133+i*1,"riscv_top u_riscv_cpu fwd_sel_b", true,(i+2), 1,0);}}
        {int i; for (i=0; i<2; i++) {
                tracep->declBit(c+134+i*1,"riscv_top u_riscv_cpu stall", true,(i+0));}}
        {int i; for (i=0; i<2; i++) {
                tracep->declBit(c+136+i*1,"riscv_top u_riscv_cpu flush", true,(i+1));}}
        tracep->declArray(c+138,"riscv_top u_riscv_cpu mux_concat_pc", false,-1, 95,0);
        tracep->declArray(c+141,"riscv_top u_riscv_cpu mux_concat_fwd_a", false,-1, 95,0);
        tracep->declArray(c+144,"riscv_top u_riscv_cpu mux_concat_fwd_b", false,-1, 95,0);
        tracep->declQuad(c+147,"riscv_top u_riscv_cpu mux_concat_alu_a", false,-1, 63,0);
        tracep->declQuad(c+149,"riscv_top u_riscv_cpu mux_concat_alu_b", false,-1, 63,0);
        tracep->declArray(c+151,"riscv_top u_riscv_cpu mux_concat_rd", false,-1, 127,0);
        tracep->declBus(c+155,"riscv_top u_riscv_cpu pc_next", false,-1, 31,0);
        tracep->declBus(c+156,"riscv_top u_riscv_cpu u_riscv_hazard o_fwd_sel_a_ex", false,-1, 1,0);
        tracep->declBus(c+157,"riscv_top u_riscv_cpu u_riscv_hazard o_fwd_sel_b_ex", false,-1, 1,0);
        tracep->declBit(c+158,"riscv_top u_riscv_cpu u_riscv_hazard o_stall_if", false,-1);
        tracep->declBit(c+158,"riscv_top u_riscv_cpu u_riscv_hazard o_stall_id", false,-1);
        tracep->declBit(c+159,"riscv_top u_riscv_cpu u_riscv_hazard o_flush_id", false,-1);
        tracep->declBit(c+160,"riscv_top u_riscv_cpu u_riscv_hazard o_flush_ex", false,-1);
        tracep->declBus(c+161,"riscv_top u_riscv_cpu u_riscv_hazard i_src_pc_ex", false,-1, 1,0);
        tracep->declBus(c+162,"riscv_top u_riscv_cpu u_riscv_hazard i_src_rd_ex", false,-1, 1,0);
        tracep->declBus(c+163,"riscv_top u_riscv_cpu u_riscv_hazard i_rs1_id", false,-1, 4,0);
        tracep->declBus(c+164,"riscv_top u_riscv_cpu u_riscv_hazard i_rs2_id", false,-1, 4,0);
        tracep->declBus(c+165,"riscv_top u_riscv_cpu u_riscv_hazard i_rs1_ex", false,-1, 4,0);
        tracep->declBus(c+166,"riscv_top u_riscv_cpu u_riscv_hazard i_rs2_ex", false,-1, 4,0);
        tracep->declBus(c+167,"riscv_top u_riscv_cpu u_riscv_hazard i_rd_ex", false,-1, 4,0);
        tracep->declBus(c+168,"riscv_top u_riscv_cpu u_riscv_hazard i_rd_mm", false,-1, 4,0);
        tracep->declBus(c+169,"riscv_top u_riscv_cpu u_riscv_hazard i_rd_wb", false,-1, 4,0);
        tracep->declBit(c+170,"riscv_top u_riscv_cpu u_riscv_hazard i_reg_wr_en_ex", false,-1);
        tracep->declBit(c+171,"riscv_top u_riscv_cpu u_riscv_hazard i_reg_wr_en_mm", false,-1);
        tracep->declBit(c+172,"riscv_top u_riscv_cpu u_riscv_hazard i_reg_wr_en_wb", false,-1);
        tracep->declBit(c+158,"riscv_top u_riscv_cpu u_riscv_hazard stall", false,-1);
        tracep->declBus(c+296,"riscv_top u_riscv_cpu u_riscv_mux_pc N_MUX_IN", false,-1, 31,0);
        tracep->declBus(c+155,"riscv_top u_riscv_cpu u_riscv_mux_pc o_mux_data", false,-1, 31,0);
        tracep->declArray(c+138,"riscv_top u_riscv_cpu u_riscv_mux_pc i_mux_concat_data", false,-1, 95,0);
        tracep->declBus(c+161,"riscv_top u_riscv_cpu u_riscv_mux_pc i_mux_sel", false,-1, 1,0);
        {int i; for (i=0; i<3; i++) {
                tracep->declBus(c+173+i*1,"riscv_top u_riscv_cpu u_riscv_mux_pc mux_input_arr", true,(i+0), 31,0);}}
        tracep->declBus(c+176,"riscv_top u_riscv_cpu u_riscv_adder_pc_plus_4 o_adder_sum", false,-1, 31,0);
        tracep->declBus(c+65,"riscv_top u_riscv_cpu u_riscv_adder_pc_plus_4 i_adder_a", false,-1, 31,0);
        tracep->declBus(c+298,"riscv_top u_riscv_cpu u_riscv_adder_pc_plus_4 i_adder_b", false,-1, 31,0);
        tracep->declBus(c+177,"riscv_top u_riscv_cpu u_riscv_ctrl o_ctrl_src_imm", false,-1, 2,0);
        tracep->declBus(c+178,"riscv_top u_riscv_cpu u_riscv_ctrl o_ctrl_src_rd", false,-1, 1,0);
        tracep->declBit(c+179,"riscv_top u_riscv_cpu u_riscv_ctrl o_ctrl_src_alu_a", false,-1);
        tracep->declBit(c+180,"riscv_top u_riscv_cpu u_riscv_ctrl o_ctrl_src_alu_b", false,-1);
        tracep->declBit(c+181,"riscv_top u_riscv_cpu u_riscv_ctrl o_ctrl_reg_wr_en", false,-1);
        tracep->declBit(c+182,"riscv_top u_riscv_cpu u_riscv_ctrl o_ctrl_mem_wr_en", false,-1);
        tracep->declBus(c+183,"riscv_top u_riscv_cpu u_riscv_ctrl o_ctrl_alu_ctrl", false,-1, 3,0);
        tracep->declBus(c+184,"riscv_top u_riscv_cpu u_riscv_ctrl i_ctrl_opcode", false,-1, 6,0);
        tracep->declBus(c+185,"riscv_top u_riscv_cpu u_riscv_ctrl i_ctrl_funct3", false,-1, 2,0);
        tracep->declBit(c+186,"riscv_top u_riscv_cpu u_riscv_ctrl i_ctrl_funct7_5b", false,-1);
        tracep->declArray(c+187,"riscv_top u_riscv_cpu u_riscv_ctrl DEBUG_INSTR", false,-1, 255,0);
        tracep->declBus(c+290,"riscv_top u_riscv_cpu u_riscv_regfile o_regfile_rs1_data", false,-1, 31,0);
        tracep->declBus(c+291,"riscv_top u_riscv_cpu u_riscv_regfile o_regfile_rs2_data", false,-1, 31,0);
        tracep->declBus(c+163,"riscv_top u_riscv_cpu u_riscv_regfile i_regfile_rs1_addr", false,-1, 4,0);
        tracep->declBus(c+164,"riscv_top u_riscv_cpu u_riscv_regfile i_regfile_rs2_addr", false,-1, 4,0);
        tracep->declBus(c+195,"riscv_top u_riscv_cpu u_riscv_regfile i_regfile_rd_data", false,-1, 31,0);
        tracep->declBus(c+169,"riscv_top u_riscv_cpu u_riscv_regfile i_regfile_rd_addr", false,-1, 4,0);
        tracep->declBit(c+172,"riscv_top u_riscv_cpu u_riscv_regfile i_regfile_rd_wen", false,-1);
        tracep->declBit(c+292,"riscv_top u_riscv_cpu u_riscv_regfile i_clk", false,-1);
        {int i; for (i=0; i<32; i++) {
                tracep->declBus(c+245+i*1,"riscv_top u_riscv_cpu u_riscv_regfile registers", true,(i+0), 31,0);}}
        tracep->declBus(c+196,"riscv_top u_riscv_cpu u_riscv_immmext o_imm_ext", false,-1, 31,0);
        tracep->declBus(c+197,"riscv_top u_riscv_cpu u_riscv_immmext i_imm_instr", false,-1, 31,0);
        tracep->declBus(c+198,"riscv_top u_riscv_cpu u_riscv_immmext i_imm_src", false,-1, 2,0);
        tracep->declBus(c+296,"riscv_top u_riscv_cpu u_riscv_mux_fwd_a N_MUX_IN", false,-1, 31,0);
        tracep->declBus(c+199,"riscv_top u_riscv_cpu u_riscv_mux_fwd_a o_mux_data", false,-1, 31,0);
        tracep->declArray(c+141,"riscv_top u_riscv_cpu u_riscv_mux_fwd_a i_mux_concat_data", false,-1, 95,0);
        tracep->declBus(c+200,"riscv_top u_riscv_cpu u_riscv_mux_fwd_a i_mux_sel", false,-1, 1,0);
        {int i; for (i=0; i<3; i++) {
                tracep->declBus(c+201+i*1,"riscv_top u_riscv_cpu u_riscv_mux_fwd_a mux_input_arr", true,(i+0), 31,0);}}
        tracep->declBus(c+296,"riscv_top u_riscv_cpu u_riscv_mux_fwd_b N_MUX_IN", false,-1, 31,0);
        tracep->declBus(c+204,"riscv_top u_riscv_cpu u_riscv_mux_fwd_b o_mux_data", false,-1, 31,0);
        tracep->declArray(c+144,"riscv_top u_riscv_cpu u_riscv_mux_fwd_b i_mux_concat_data", false,-1, 95,0);
        tracep->declBus(c+205,"riscv_top u_riscv_cpu u_riscv_mux_fwd_b i_mux_sel", false,-1, 1,0);
        {int i; for (i=0; i<3; i++) {
                tracep->declBus(c+206+i*1,"riscv_top u_riscv_cpu u_riscv_mux_fwd_b mux_input_arr", true,(i+0), 31,0);}}
        tracep->declBus(c+295,"riscv_top u_riscv_cpu u_riscv_mux_alu_a N_MUX_IN", false,-1, 31,0);
        tracep->declBus(c+209,"riscv_top u_riscv_cpu u_riscv_mux_alu_a o_mux_data", false,-1, 31,0);
        tracep->declQuad(c+147,"riscv_top u_riscv_cpu u_riscv_mux_alu_a i_mux_concat_data", false,-1, 63,0);
        tracep->declBus(c+210,"riscv_top u_riscv_cpu u_riscv_mux_alu_a i_mux_sel", false,-1, 0,0);
        {int i; for (i=0; i<2; i++) {
                tracep->declBus(c+211+i*1,"riscv_top u_riscv_cpu u_riscv_mux_alu_a mux_input_arr", true,(i+0), 31,0);}}
        tracep->declBus(c+295,"riscv_top u_riscv_cpu u_riscv_mux_alu_b N_MUX_IN", false,-1, 31,0);
        tracep->declBus(c+213,"riscv_top u_riscv_cpu u_riscv_mux_alu_b o_mux_data", false,-1, 31,0);
        tracep->declQuad(c+149,"riscv_top u_riscv_cpu u_riscv_mux_alu_b i_mux_concat_data", false,-1, 63,0);
        tracep->declBus(c+214,"riscv_top u_riscv_cpu u_riscv_mux_alu_b i_mux_sel", false,-1, 0,0);
        {int i; for (i=0; i<2; i++) {
                tracep->declBus(c+215+i*1,"riscv_top u_riscv_cpu u_riscv_mux_alu_b mux_input_arr", true,(i+0), 31,0);}}
        tracep->declBus(c+217,"riscv_top u_riscv_cpu u_riscv_alu o_alu_out", false,-1, 31,0);
        tracep->declBus(c+218,"riscv_top u_riscv_cpu u_riscv_alu o_alu_src_pc", false,-1, 1,0);
        tracep->declBus(c+219,"riscv_top u_riscv_cpu u_riscv_alu i_alu_a", false,-1, 31,0);
        tracep->declBus(c+220,"riscv_top u_riscv_cpu u_riscv_alu i_alu_b", false,-1, 31,0);
        tracep->declBus(c+221,"riscv_top u_riscv_cpu u_riscv_alu i_alu_opcode", false,-1, 6,0);
        tracep->declBus(c+222,"riscv_top u_riscv_cpu u_riscv_alu i_alu_funct3", false,-1, 2,0);
        tracep->declBus(c+223,"riscv_top u_riscv_cpu u_riscv_alu i_alu_ctrl", false,-1, 3,0);
        tracep->declBit(c+224,"riscv_top u_riscv_cpu u_riscv_alu alu_zero", false,-1);
        tracep->declBit(c+225,"riscv_top u_riscv_cpu u_riscv_alu take_branch", false,-1);
        tracep->declQuad(c+226,"riscv_top u_riscv_cpu u_riscv_alu DEBUG_ALU_OP", false,-1, 63,0);
        tracep->declBus(c+228,"riscv_top u_riscv_cpu u_riscv_adder_pc_plus_imm o_adder_sum", false,-1, 31,0);
        tracep->declBus(c+229,"riscv_top u_riscv_cpu u_riscv_adder_pc_plus_imm i_adder_a", false,-1, 31,0);
        tracep->declBus(c+230,"riscv_top u_riscv_cpu u_riscv_adder_pc_plus_imm i_adder_b", false,-1, 31,0);
        tracep->declBus(c+67,"riscv_top u_riscv_cpu u_riscv_dmem_interface o_dmem_intf_addr", false,-1, 31,0);
        tracep->declBit(c+68,"riscv_top u_riscv_cpu u_riscv_dmem_interface o_dmem_intf_wen", false,-1);
        tracep->declBus(c+67,"riscv_top u_riscv_cpu u_riscv_dmem_interface i_dmem_intf_addr", false,-1, 31,0);
        tracep->declBit(c+68,"riscv_top u_riscv_cpu u_riscv_dmem_interface i_dmem_intf_wen", false,-1);
        tracep->declBus(c+70,"riscv_top u_riscv_cpu u_riscv_dmem_interface o_dmem_intf_wr_data", false,-1, 31,0);
        tracep->declBus(c+69,"riscv_top u_riscv_cpu u_riscv_dmem_interface o_dmem_intf_byte_sel", false,-1, 3,0);
        tracep->declBus(c+231,"riscv_top u_riscv_cpu u_riscv_dmem_interface o_dmem_intf_rd_data", false,-1, 31,0);
        tracep->declBus(c+232,"riscv_top u_riscv_cpu u_riscv_dmem_interface i_dmem_intf_wr_data", false,-1, 31,0);
        tracep->declBus(c+71,"riscv_top u_riscv_cpu u_riscv_dmem_interface i_dmem_intf_rd_data", false,-1, 31,0);
        tracep->declBus(c+233,"riscv_top u_riscv_cpu u_riscv_dmem_interface i_dmem_intf_func3", false,-1, 2,0);
        tracep->declBus(c+234,"riscv_top u_riscv_cpu u_riscv_dmem_interface dmem_intf_strb", false,-1, 3,0);
        tracep->declBus(c+235,"riscv_top u_riscv_cpu u_riscv_dmem_interface byte_aligned_dmem_rd_data", false,-1, 31,0);
        tracep->declBus(c+297,"riscv_top u_riscv_cpu u_riscv_mux_regfile_rd_data N_MUX_IN", false,-1, 31,0);
        tracep->declBus(c+236,"riscv_top u_riscv_cpu u_riscv_mux_regfile_rd_data o_mux_data", false,-1, 31,0);
        tracep->declArray(c+151,"riscv_top u_riscv_cpu u_riscv_mux_regfile_rd_data i_mux_concat_data", false,-1, 127,0);
        tracep->declBus(c+237,"riscv_top u_riscv_cpu u_riscv_mux_regfile_rd_data i_mux_sel", false,-1, 1,0);
        {int i; for (i=0; i<4; i++) {
                tracep->declBus(c+238+i*1,"riscv_top u_riscv_cpu u_riscv_mux_regfile_rd_data mux_input_arr", true,(i+0), 31,0);}}
        tracep->declBus(c+66,"riscv_top u_riscv_imem o_imem_data", false,-1, 31,0);
        tracep->declBus(c+242,"riscv_top u_riscv_imem i_imem_addr", false,-1, 13,0);
        tracep->declArray(c+1,"riscv_top u_riscv_imem FILE_TEXT_MIF", false,-1, 1023,0);
        tracep->declBus(c+71,"riscv_top u_riscv_dmem o_dmem_data", false,-1, 31,0);
        tracep->declBus(c+70,"riscv_top u_riscv_dmem i_dmem_data", false,-1, 31,0);
        tracep->declBus(c+243,"riscv_top u_riscv_dmem i_dmem_addr", false,-1, 13,0);
        tracep->declBus(c+69,"riscv_top u_riscv_dmem i_dmem_byte_sel", false,-1, 3,0);
        tracep->declBit(c+68,"riscv_top u_riscv_dmem i_dmem_wr_en", false,-1);
        tracep->declBit(c+286,"riscv_top u_riscv_dmem i_clk", false,-1);
        tracep->declArray(c+33,"riscv_top u_riscv_dmem FILE_DATA_MIF", false,-1, 1023,0);
        tracep->declBus(c+244,"riscv_top u_riscv_dmem i", false,-1, 31,0);
    }
}

void Vriscv_top::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vriscv_top::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vriscv_top__Syms* __restrict vlSymsp = static_cast<Vriscv_top__Syms*>(userp);
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vriscv_top::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vriscv_top__Syms* __restrict vlSymsp = static_cast<Vriscv_top__Syms*>(userp);
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullWData(oldp+1,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_imem__DOT__FILE_TEXT_MIF),1024);
        tracep->fullWData(oldp+33,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_dmem__DOT__FILE_DATA_MIF),1024);
        tracep->fullIData(oldp+65,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pc
                                   [0U]),32);
        tracep->fullIData(oldp+66,(vlSymsp->TOP__riscv_top.o_riscv_imem_instr),32);
        tracep->fullIData(oldp+67,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_out
                                   [0U]),32);
        tracep->fullBit(oldp+68,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mem_wr_en
                                 [1U]));
        tracep->fullCData(oldp+69,(vlSymsp->TOP__riscv_top.o_riscv_dmem_strb),4);
        tracep->fullIData(oldp+70,(vlSymsp->TOP__riscv_top.o_riscv_dmem_wr_data),32);
        tracep->fullIData(oldp+71,(vlSymsp->TOP__riscv_top.o_riscv_dmem_rd_data),32);
        tracep->fullCData(oldp+72,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3[0]),3);
        tracep->fullCData(oldp+73,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3[1]),3);
        tracep->fullCData(oldp+74,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3[2]),3);
        tracep->fullCData(oldp+75,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__opcode[0]),7);
        tracep->fullCData(oldp+76,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__opcode[1]),7);
        tracep->fullBit(oldp+77,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct7_5b[0]));
        tracep->fullBit(oldp+78,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__w_reg_wr_en[0]));
        tracep->fullBit(oldp+79,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__reg_wr_en[0]));
        tracep->fullBit(oldp+80,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__reg_wr_en[1]));
        tracep->fullBit(oldp+81,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__reg_wr_en[2]));
        tracep->fullCData(oldp+82,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__w_src_rd[0]),2);
        tracep->fullCData(oldp+83,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_rd[0]),2);
        tracep->fullCData(oldp+84,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_rd[1]),2);
        tracep->fullCData(oldp+85,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_rd[2]),2);
        tracep->fullBit(oldp+86,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__w_mem_wr_en[0]));
        tracep->fullBit(oldp+87,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mem_wr_en[0]));
        tracep->fullBit(oldp+88,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mem_wr_en[1]));
        tracep->fullCData(oldp+89,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__w_alu_ctrl[0]),4);
        tracep->fullCData(oldp+90,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_ctrl[0]),4);
        tracep->fullBit(oldp+91,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__w_src_alu_a[0]));
        tracep->fullBit(oldp+92,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__w_src_alu_b[0]));
        tracep->fullBit(oldp+93,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_alu_a[0]));
        tracep->fullBit(oldp+94,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_alu_b[0]));
        tracep->fullCData(oldp+95,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_imm[0]),3);
        tracep->fullCData(oldp+96,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_pc[0]),2);
        tracep->fullIData(oldp+97,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pc[0]),32);
        tracep->fullIData(oldp+98,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pc[1]),32);
        tracep->fullIData(oldp+99,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pc[2]),32);
        tracep->fullIData(oldp+100,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pc4[0]),32);
        tracep->fullIData(oldp+101,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pc4[1]),32);
        tracep->fullIData(oldp+102,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pc4[2]),32);
        tracep->fullIData(oldp+103,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pc4[3]),32);
        tracep->fullIData(oldp+104,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pc4[4]),32);
        tracep->fullIData(oldp+105,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pcimm[0]),32);
        tracep->fullIData(oldp+106,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__instr[0]),32);
        tracep->fullIData(oldp+107,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__w_imm[0]),32);
        tracep->fullIData(oldp+108,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__imm[0]),32);
        tracep->fullIData(oldp+109,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__imm[1]),32);
        tracep->fullIData(oldp+110,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__imm[2]),32);
        tracep->fullCData(oldp+111,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs1[0]),5);
        tracep->fullCData(oldp+112,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs1[1]),5);
        tracep->fullCData(oldp+113,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs2[0]),5);
        tracep->fullCData(oldp+114,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs2[1]),5);
        tracep->fullIData(oldp+115,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs1_data[0]),32);
        tracep->fullIData(oldp+116,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs2_data[0]),32);
        tracep->fullCData(oldp+117,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rd[0]),5);
        tracep->fullCData(oldp+118,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rd[1]),5);
        tracep->fullCData(oldp+119,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rd[2]),5);
        tracep->fullCData(oldp+120,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rd[3]),5);
        tracep->fullIData(oldp+121,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rd_data[0]),32);
        tracep->fullIData(oldp+122,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mem_rd_data[0]),32);
        tracep->fullIData(oldp+123,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mem_rd_data[1]),32);
        tracep->fullIData(oldp+124,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__fwd_a[0]),32);
        tracep->fullIData(oldp+125,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__w_fwd_b[0]),32);
        tracep->fullIData(oldp+126,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__fwd_b[0]),32);
        tracep->fullIData(oldp+127,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_a[0]),32);
        tracep->fullIData(oldp+128,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_b[0]),32);
        tracep->fullIData(oldp+129,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__w_alu_out[0]),32);
        tracep->fullIData(oldp+130,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_out[0]),32);
        tracep->fullIData(oldp+131,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_out[1]),32);
        tracep->fullCData(oldp+132,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__fwd_sel_a[0]),2);
        tracep->fullCData(oldp+133,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__fwd_sel_b[0]),2);
        tracep->fullBit(oldp+134,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__stall[0]));
        tracep->fullBit(oldp+135,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__stall[1]));
        tracep->fullBit(oldp+136,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__flush[0]));
        tracep->fullBit(oldp+137,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__flush[1]));
        tracep->fullWData(oldp+138,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mux_concat_pc),96);
        tracep->fullWData(oldp+141,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mux_concat_fwd_a),96);
        tracep->fullWData(oldp+144,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mux_concat_fwd_b),96);
        tracep->fullQData(oldp+147,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mux_concat_alu_a),64);
        tracep->fullQData(oldp+149,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mux_concat_alu_b),64);
        tracep->fullWData(oldp+151,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__mux_concat_rd),128);
        tracep->fullIData(oldp+155,(((2U >= vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_pc
                                      [0U]) ? vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_pc__DOT__mux_input_arr
                                     [vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_pc
                                     [0U]] : 0U)),32);
        tracep->fullCData(oldp+156,(((((vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs1
                                        [1U] == vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rd
                                        [2U]) & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__reg_wr_en
                                       [1U]) & (0U 
                                                != 
                                                vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs1
                                                [1U]))
                                      ? 1U : ((((vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs1
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
        tracep->fullCData(oldp+157,(((((vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs2
                                        [1U] == vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rd
                                        [2U]) & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__reg_wr_en
                                       [1U]) & (0U 
                                                != 
                                                vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs2
                                                [1U]))
                                      ? 1U : ((((vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs2
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
        tracep->fullBit(oldp+158,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_hazard__DOT__stall));
        tracep->fullBit(oldp+159,((0U != vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_pc
                                   [0U])));
        tracep->fullBit(oldp+160,(((IData)(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_hazard__DOT__stall) 
                                   | (0U != vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_pc
                                      [0U]))));
        tracep->fullCData(oldp+161,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_pc
                                    [0U]),2);
        tracep->fullCData(oldp+162,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_rd
                                    [0U]),2);
        tracep->fullCData(oldp+163,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs1
                                    [0U]),5);
        tracep->fullCData(oldp+164,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs2
                                    [0U]),5);
        tracep->fullCData(oldp+165,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs1
                                    [1U]),5);
        tracep->fullCData(oldp+166,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs2
                                    [1U]),5);
        tracep->fullCData(oldp+167,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rd
                                    [1U]),5);
        tracep->fullCData(oldp+168,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rd
                                    [2U]),5);
        tracep->fullCData(oldp+169,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rd
                                    [3U]),5);
        tracep->fullBit(oldp+170,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__reg_wr_en
                                  [0U]));
        tracep->fullBit(oldp+171,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__reg_wr_en
                                  [1U]));
        tracep->fullBit(oldp+172,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__reg_wr_en
                                  [2U]));
        tracep->fullIData(oldp+173,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_pc__DOT__mux_input_arr[0]),32);
        tracep->fullIData(oldp+174,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_pc__DOT__mux_input_arr[1]),32);
        tracep->fullIData(oldp+175,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_pc__DOT__mux_input_arr[2]),32);
        tracep->fullIData(oldp+176,(((IData)(4U) + 
                                     vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pc
                                     [0U])),32);
        tracep->fullCData(oldp+177,(vlSymsp->TOP__riscv_top.u_riscv_cpu__DOT____Vcellout__u_riscv_ctrl__o_ctrl_src_imm),3);
        tracep->fullCData(oldp+178,(vlSymsp->TOP__riscv_top.u_riscv_cpu__DOT____Vcellout__u_riscv_ctrl__o_ctrl_src_rd),2);
        tracep->fullBit(oldp+179,((0x17U == vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__opcode
                                   [0U])));
        tracep->fullBit(oldp+180,(vlSymsp->TOP__riscv_top.u_riscv_cpu__DOT____Vcellout__u_riscv_ctrl__o_ctrl_src_alu_b));
        tracep->fullBit(oldp+181,((1U & (~ ((0x23U 
                                             == vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__opcode
                                             [0U]) 
                                            | (0x63U 
                                               == vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__opcode
                                               [0U]))))));
        tracep->fullBit(oldp+182,((0x23U == vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__opcode
                                   [0U])));
        tracep->fullCData(oldp+183,(vlSymsp->TOP__riscv_top.u_riscv_cpu__DOT____Vcellout__u_riscv_ctrl__o_ctrl_alu_ctrl),4);
        tracep->fullCData(oldp+184,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__opcode
                                    [0U]),7);
        tracep->fullCData(oldp+185,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
                                    [0U]),3);
        tracep->fullBit(oldp+186,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct7_5b
                                  [0U]));
        tracep->fullWData(oldp+187,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR),256);
        tracep->fullIData(oldp+195,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rd_data
                                    [0U]),32);
        tracep->fullIData(oldp+196,(vlSymsp->TOP__riscv_top.u_riscv_cpu__DOT____Vcellout__u_riscv_immmext__o_imm_ext),32);
        tracep->fullIData(oldp+197,((0x1ffffffU & (
                                                   vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__instr
                                                   [0U] 
                                                   >> 7U))),32);
        tracep->fullCData(oldp+198,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_imm
                                    [0U]),3);
        tracep->fullIData(oldp+199,(((2U >= vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__fwd_sel_a
                                      [0U]) ? vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_fwd_a__DOT__mux_input_arr
                                     [vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__fwd_sel_a
                                     [0U]] : 0U)),32);
        tracep->fullCData(oldp+200,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__fwd_sel_a
                                    [0U]),2);
        tracep->fullIData(oldp+201,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_fwd_a__DOT__mux_input_arr[0]),32);
        tracep->fullIData(oldp+202,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_fwd_a__DOT__mux_input_arr[1]),32);
        tracep->fullIData(oldp+203,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_fwd_a__DOT__mux_input_arr[2]),32);
        tracep->fullIData(oldp+204,(((2U >= vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__fwd_sel_b
                                      [0U]) ? vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_fwd_b__DOT__mux_input_arr
                                     [vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__fwd_sel_b
                                     [0U]] : 0U)),32);
        tracep->fullCData(oldp+205,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__fwd_sel_b
                                    [0U]),2);
        tracep->fullIData(oldp+206,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_fwd_b__DOT__mux_input_arr[0]),32);
        tracep->fullIData(oldp+207,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_fwd_b__DOT__mux_input_arr[1]),32);
        tracep->fullIData(oldp+208,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_fwd_b__DOT__mux_input_arr[2]),32);
        tracep->fullIData(oldp+209,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_alu_a__DOT__mux_input_arr
                                    [vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_alu_a
                                    [0U]]),32);
        tracep->fullBit(oldp+210,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_alu_a
                                  [0U]));
        tracep->fullIData(oldp+211,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_alu_a__DOT__mux_input_arr[0]),32);
        tracep->fullIData(oldp+212,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_alu_a__DOT__mux_input_arr[1]),32);
        tracep->fullIData(oldp+213,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_alu_b__DOT__mux_input_arr
                                    [vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_alu_b
                                    [0U]]),32);
        tracep->fullBit(oldp+214,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_alu_b
                                  [0U]));
        tracep->fullIData(oldp+215,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_alu_b__DOT__mux_input_arr[0]),32);
        tracep->fullIData(oldp+216,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_alu_b__DOT__mux_input_arr[1]),32);
        tracep->fullIData(oldp+217,(vlSymsp->TOP__riscv_top.u_riscv_cpu__DOT____Vcellout__u_riscv_alu__o_alu_out),32);
        tracep->fullCData(oldp+218,(((0x63U == vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__opcode
                                      [1U]) ? (((0x63U 
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
                                      : ((0x6fU == 
                                          vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__opcode
                                          [1U]) ? 1U
                                          : ((0x67U 
                                              == vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__opcode
                                              [1U])
                                              ? 2U : 0U)))),2);
        tracep->fullIData(oldp+219,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_a
                                    [0U]),32);
        tracep->fullIData(oldp+220,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_b
                                    [0U]),32);
        tracep->fullCData(oldp+221,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__opcode
                                    [1U]),7);
        tracep->fullCData(oldp+222,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
                                    [1U]),3);
        tracep->fullCData(oldp+223,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_ctrl
                                    [0U]),4);
        tracep->fullBit(oldp+224,((0U == vlSymsp->TOP__riscv_top.u_riscv_cpu__DOT____Vcellout__u_riscv_alu__o_alu_out)));
        tracep->fullBit(oldp+225,(((0x63U == vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__opcode
                                    [1U]) & ((4U & 
                                              vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
                                              [1U])
                                              ? ((2U 
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
                                              : ((~ 
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
        tracep->fullQData(oldp+226,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_alu__DOT__DEBUG_ALU_OP),64);
        tracep->fullIData(oldp+228,((vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pc
                                     [2U] + vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__imm
                                     [0U])),32);
        tracep->fullIData(oldp+229,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pc
                                    [2U]),32);
        tracep->fullIData(oldp+230,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__imm
                                    [0U]),32);
        tracep->fullIData(oldp+231,(((4U & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
                                      [2U]) ? ((2U 
                                                & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
                                                [2U])
                                                ? 0U
                                                : (
                                                   (1U 
                                                    & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
                                                    [2U])
                                                    ? 
                                                   (0xffffU 
                                                    & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)
                                                    : 
                                                   (0xffU 
                                                    & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)))
                                      : ((2U & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
                                          [2U]) ? (
                                                   (1U 
                                                    & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
                                                    [2U])
                                                    ? 0U
                                                    : vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)
                                          : ((1U & 
                                              vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
                                              [2U])
                                              ? ((0xffff0000U 
                                                  & ((- (IData)(
                                                                (1U 
                                                                 & (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data 
                                                                    >> 0xfU)))) 
                                                     << 0x10U)) 
                                                 | (0xffffU 
                                                    & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data))
                                              : ((0xffffff00U 
                                                  & ((- (IData)(
                                                                (1U 
                                                                 & (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data 
                                                                    >> 7U)))) 
                                                     << 8U)) 
                                                 | (0xffU 
                                                    & vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)))))),32);
        tracep->fullIData(oldp+232,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__fwd_b
                                    [0U]),32);
        tracep->fullCData(oldp+233,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__funct3
                                    [2U]),3);
        tracep->fullCData(oldp+234,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_dmem_interface__DOT__dmem_intf_strb),4);
        tracep->fullIData(oldp+235,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data),32);
        tracep->fullIData(oldp+236,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_regfile_rd_data__DOT__mux_input_arr
                                    [vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_rd
                                    [2U]]),32);
        tracep->fullCData(oldp+237,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__src_rd
                                    [2U]),2);
        tracep->fullIData(oldp+238,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_regfile_rd_data__DOT__mux_input_arr[0]),32);
        tracep->fullIData(oldp+239,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_regfile_rd_data__DOT__mux_input_arr[1]),32);
        tracep->fullIData(oldp+240,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_regfile_rd_data__DOT__mux_input_arr[2]),32);
        tracep->fullIData(oldp+241,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_mux_regfile_rd_data__DOT__mux_input_arr[3]),32);
        tracep->fullSData(oldp+242,((0x3fffU & (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__pc
                                                [0U] 
                                                >> 2U))),14);
        tracep->fullSData(oldp+243,((0x3fffU & (vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__alu_out
                                                [0U] 
                                                >> 2U))),14);
        tracep->fullIData(oldp+244,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_dmem__DOT__i),32);
        tracep->fullIData(oldp+245,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[0]),32);
        tracep->fullIData(oldp+246,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[1]),32);
        tracep->fullIData(oldp+247,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[2]),32);
        tracep->fullIData(oldp+248,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[3]),32);
        tracep->fullIData(oldp+249,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[4]),32);
        tracep->fullIData(oldp+250,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[5]),32);
        tracep->fullIData(oldp+251,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[6]),32);
        tracep->fullIData(oldp+252,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[7]),32);
        tracep->fullIData(oldp+253,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[8]),32);
        tracep->fullIData(oldp+254,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[9]),32);
        tracep->fullIData(oldp+255,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[10]),32);
        tracep->fullIData(oldp+256,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[11]),32);
        tracep->fullIData(oldp+257,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[12]),32);
        tracep->fullIData(oldp+258,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[13]),32);
        tracep->fullIData(oldp+259,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[14]),32);
        tracep->fullIData(oldp+260,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[15]),32);
        tracep->fullIData(oldp+261,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[16]),32);
        tracep->fullIData(oldp+262,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[17]),32);
        tracep->fullIData(oldp+263,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[18]),32);
        tracep->fullIData(oldp+264,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[19]),32);
        tracep->fullIData(oldp+265,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[20]),32);
        tracep->fullIData(oldp+266,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[21]),32);
        tracep->fullIData(oldp+267,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[22]),32);
        tracep->fullIData(oldp+268,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[23]),32);
        tracep->fullIData(oldp+269,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[24]),32);
        tracep->fullIData(oldp+270,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[25]),32);
        tracep->fullIData(oldp+271,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[26]),32);
        tracep->fullIData(oldp+272,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[27]),32);
        tracep->fullIData(oldp+273,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[28]),32);
        tracep->fullIData(oldp+274,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[29]),32);
        tracep->fullIData(oldp+275,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[30]),32);
        tracep->fullIData(oldp+276,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers[31]),32);
        tracep->fullIData(oldp+277,(vlTOPp->o_riscv_imem_pc),32);
        tracep->fullIData(oldp+278,(vlTOPp->o_riscv_imem_instr),32);
        tracep->fullIData(oldp+279,(vlTOPp->o_riscv_dmem_addr),32);
        tracep->fullBit(oldp+280,(vlTOPp->o_riscv_dmem_wr_en));
        tracep->fullCData(oldp+281,(vlTOPp->o_riscv_dmem_strb),4);
        tracep->fullIData(oldp+282,(vlTOPp->o_riscv_dmem_wr_data),32);
        tracep->fullIData(oldp+283,(vlTOPp->o_riscv_dmem_rd_data),32);
        tracep->fullBit(oldp+284,(vlTOPp->i_clk));
        tracep->fullBit(oldp+285,(vlTOPp->i_rstn));
        tracep->fullBit(oldp+286,(vlSymsp->TOP__riscv_top.i_clk));
        tracep->fullBit(oldp+287,(vlSymsp->TOP__riscv_top.i_rstn));
        tracep->fullIData(oldp+288,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__w_rs1_data[0]),32);
        tracep->fullIData(oldp+289,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__w_rs2_data[0]),32);
        tracep->fullIData(oldp+290,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers
                                    [vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs1
                                    [0U]]),32);
        tracep->fullIData(oldp+291,(vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__u_riscv_regfile__DOT__registers
                                    [vlSymsp->TOP__riscv_top.__PVT__u_riscv_cpu__DOT__rs2
                                    [0U]]),32);
        tracep->fullBit(oldp+292,((1U & (~ (IData)(vlSymsp->TOP__riscv_top.i_clk)))));
        tracep->fullIData(oldp+293,(0U),32);
        tracep->fullIData(oldp+294,(1U),32);
        tracep->fullIData(oldp+295,(2U),32);
        tracep->fullIData(oldp+296,(3U),32);
        tracep->fullIData(oldp+297,(4U),32);
        tracep->fullIData(oldp+298,(4U),32);
    }
}
