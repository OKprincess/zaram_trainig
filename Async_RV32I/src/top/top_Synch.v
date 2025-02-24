// ===================================================
//	=================[ VLSISYS Lab. ]=================
//	* Author		: oksj (oksj@sookmyung.ac.kr)
//	* Filename		: top_PUCRS.v
//	* Description	: 
// ===================================================
`include		"../core/pkg.v"
`include		"../core/adder.v"
`include		"../core/branch.v"
`include		"../core/bypass.v"
`include		"../core/logic.v"
`include		"../core/memory.v"
`include		"../core/shift.v"
`include		"../core/fetch.v"
`include		"../core/decoder.v"
`include		"../core/operandFetch.v"
`include		"../core/regbank.v"
`include		"../core/execute.v"
`include		"../core/retire.v"

module top_Synch
(
	input				i_clk,
	input				i_rstn,
	input		[31:0]	i_instr,
	output		[31:0]	o_instr_addr,
	output				o_read,
	output		[31:0]	o_read_addr,
	input		[31:0]	i_data_in,
	output		[31:0]	o_data_out,
	output		[31:0]	o_wr_addr,
	output				o_write,
	output		[1:0]	o_size
);
	 wire	jump_wb, jump_retire, bubble, write_retire, freeMem, we_retire;
     wire	regD_we;
     wire	[31:0] dataA, dataB, data_RLock;
     wire	[4:0] regA_add, regB_add;
     wire	[31:0] regD_add, regD_add_int;
     wire	[31:0] result_wb, data_wb, New_pc;
     wire	[31:0] IR, instruction_OPFetch;
     wire	[31:0] NPC_decode, NPC_OPFetch, NPC_execute;
     wire	[31:0] opA_execute, opB_execute, opC_execute;
     wire	[31:0] write_address_retire;
     wire	[3:0] decode_tag, OPF_tag, execute_tag, retire_tag;
     wire	[4:0] regA_OPFetch, regB_OPFetch, regD_OPFetch;
     wire	[1:0] size_retire;
     wire	[2:0]	fmt_OPFetch;
     wire	[2:0]	i_OPFetch, i_execute, i_retire;
     wire	[2:0]	xu_OPFetch, xu_execute;
     wire	[31:0] result_retire [1:0];
     wire	[31:1] wrAddr;
     wire	[1:0] MEMBlock;
//////////////////////////////////////////////////////////// FETCH //////////////////////////////////////////////////////////////////////////////////

    fetch 
	#(32'h00000000) 
	u_fetch (.i_clk	(i_clk), .i_rstn(i_rstn), .i_en(bubble), .i_jump(jump_wb), .i_addr_result(New_pc), .i_instr(instruction), 
                .o_addr(i_address), .o_instr_reg(IR), .o_next_pc(NPC_decode), .o_tag(decode_tag));

//////////////////////////////////////////////////////////// DECODER ////////////////////////////////////////////////////////////////////////////////

    decoder 
	u_decoder (.i_clk(i_clk), .i_rstn(i_rstn), .i_en(bubble), .i_next_pc(NPC_decode), .i_instr(IR), .i_tag(decode_tag), 
                .o_rs1(regA_OPFetch), .o_rs2(regB_OPFetch), .o_rd(regD_OPFetch), .o_next_pc(NPC_OPFetch), .o_instr_format(fmt_OPFetch), 
                .o_instr(instruction_OPFetch), .o_instr_type(i_OPFetch), .o_alu_sel(xu_OPFetch), .o_tag(OPF_tag));

/////////////////////////////////////////////////////////// OP FETCH ////////////////////////////////////////////////////////////////////////////////

    operandFetch 
	u_operandFetch (.i_clk(i_clk), .i_rstn(i_rstn), .i_wr_en(regD_we), .i_next_pc(NPC_OPFetch), .i_rs1(regA_OPFetch), .i_rs2(regB_OPFetch), .i_rd(regD_OPFetch), 
                .i_instr_format(fmt_OPFetch), .i_instr(instruction_OPFetch), .i_instr_type(i_OPFetch), .i_alu_sel(xu_OPFetch), .i_tag(OPF_tag), .i_data_rs1(dataA), 
                .i_data_rs2(dataB), .o_rs1_add(regA_add), .o_rs2_add(regB_add), .o_opA(opA_execute), .o_opB(opB_execute), 
                .o_opC(opC_execute), .o_next_pc(NPC_execute), .o_instr_type(i_execute), .o_alu_sel(xu_execute), .o_tag(execute_tag), .o_addr_wr(wrAddr), .o_bubble(bubble));

/////////////////////////////////////////////////////////// execute /////////////////////////////////////////////////////////////////////////////////

    execute 
	u_execute  (.i_clk(i_clk), .i_rstn(i_rstn), .NPC(NPC_execute), .opA(opA_execute), .opB(opB_execute), .opC(opC_execute),
                .i(i_execute), .xu_sel(xu_execute), .tag_in(execute_tag),  .result_out(result_retire), .jump_out(jump_retire), 
                .tag_out(retire_tag), .we_out(we_retire),
                .DATA_in(DATA_in), .read_address(read_address), .read(read), .write(write_retire), .size(size_retire));

/////////////////////////////////////////////////////////// RETIRE //////////////////////////////////////////////////////////////////////////////////

    retire retire1 (.clk(clk), .reset(reset), .result(result_retire), .jump(jump_retire), .we(we_retire),
                .tag_in(retire_tag), .reg_we(regD_we), .WrData(data_wb),
                .New_pc(New_pc), .jump_out(jump_wb),
                .write_in(write_retire), .size_in(size_retire),
                .write(write), .size(size), .write_address(write_address), .DATA_out(DATA_out));

/////////////////////////////////////////////////////////// REGISTER BANK ///////////////////////////////////////////////////////////////////////////

    regbank regbank1 (.clk(clk), .reset(reset), .addra(regA_add), .addrb(regB_add), .addrw(wrAddr), .in(data_wb), .outa(dataA), .outb(dataB));	
endmodule
