// ===================================================
//	=================[ VLSISYS Lab. ]=================
//	* Author		: oksj (oksj@sookmyung.ac.kr)
//	* Filename		: riscv_cpu.v
//	* Date			: 2025-01-14 
//	* Description	: 
// ===================================================

`ifndef		NOINC
`include	"../common/riscv_configs.v"
`endif

module riscv_cpu
(
	output reg	[`XLEN-1:0]		o_cpu_pc,
	output		[`XLEN-1:0]		o_cpu_mem_addr,
	output						o_cpu_mem_wr_en,
	output		[3:0]			o_cpu_mem_strb,
	output		[`XLEN-1:0]		o_cpu_mem_wr_data,

	input		[`XLEN-1:0]		i_cpu_instr,
	input		[`XLEN-1:0]		i_cpu_mem_rd_data,
	input						i_clk,
	input						i_rstn
);

	localparam	IF	=	0;
	localparam	ID	=	1;
	localparam	EX	=	2;
	localparam	MM	=	3;
	localparam	WB	=	4;

	// -----------------------------------------------------
	// IF Stage
	// -----------------------------------------------------
	always @(*) begin
		o_cpu_pc	= pc[IF];
		instr[IF]	= i_cpu_instr;
	end

	// -----------------------------------------------------
	// ID Stage
	// -----------------------------------------------------

	// -----------------------------------------------------
	//  EX Stage
	// -----------------------------------------------------


	// -----------------------------------------------------
	//  MM Stage
	// -----------------------------------------------------


	// -----------------------------------------------------
	//  WB Stage
	// -----------------------------------------------------


	// -----------------------------------------------------
	// Internal Signals (Control I/O Signals)
	// w_xxx: output of module && transfer to next Stage
	// -----------------------------------------------------


	// -----------------------------------------------------
	// Internal Signals (Non-Control)
	// -----------------------------------------------------


	// -----------------------------------------------------
	// Hazard Unit
	// -----------------------------------------------------

	// -----------------------------------------------------
	// Pipeline Flip-Flop
	// -----------------------------------------------------
	// Pipeline Stage: IF


	// Pipeline Stage: ID
	 

	// Pipeline Stage: EX
	

	// Pipeline Stage: MM
	

	// Pipeline Stage: WB


	// -----------------------------------------------------
	//	MUX Concat 
	// -----------------------------------------------------





endmodule
