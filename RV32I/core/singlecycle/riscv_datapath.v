// ==================================================
//	[ VLSISYS Lab. ]
//	* Author		: SoJeong Ok (oksj@sookmyung.ac.kr)
//	* Filename		: riscv_datapath.v
//	* Description	: 
// ==================================================

`ifndef		NOINC
`include	"../common/riscv_configs.v"
`include	"../common/riscv_mux.v"
`include	"../common/riscv_register.v"
`include	"../common/riscv_adder.v"
`include	"../common/riscv_regfile.v"
`include	"../common/riscv_immext.v"
`include	"../common/riscv_alu.v"
`endif

module riscv_datapath
#(	
	parameter	REGISTER_INIT	= 0
)
(	
	output		[`XLEN-1:0]		o_dp_pc,
	output						o_dp_alu_zero,
	output		[`XLEN-1:0]		o_dp_mem_addr,
	output		[`XLEN-1:0]		o_dp_mem_wr_data,

	input		[`XLEN-1:0]		i_dp_mem_rd_data,
	input		[`XLEN-1:0]		i_dp_instr,
	input		[2:0]			i_dp_src_imm,
	input		[1:0]			i_dp_src_pc,
	input		[1:0]			i_dp_src_rd,
	input						i_dp_src_alu_a,
	input						i_dp_src_alu_b,
	input						i_dp_reg_wr_en,
	input		[3:0]			i_dp_alu_ctrl,
	input						i_clk,
	input						i_rstn
);

	// ==================================================
	// 	Declare internal Signal: from Left to Right in BlockDiagram
	// ==================================================
	// 	PC register 
	// 	pc+4/pc+imm/rs1+imm --(src_pc)--> pc_next --> o_dp_pc
	wire		[`XLEN-1:0]		pc_next;
	wire		[`XLEN-1:0]		pc_plus_4, pc_plus_imm;

	// 	Register File 
	//	i_dp_instr(rs1,rs2,rd),rd_data --(i_dp_reg_wr_en)
	//	--> rs1_data ,rs2_data(=o_dp_mem_wr_data)
	wire		[`XLEN-1:0]		regfile_rd_data;
	wire		[`XLEN-1:0]		regfile_rs1_data, regfile_rs2_data;

	// 	Immidiate Decode
	// 	i_dp_instr--(i_dp_src_imm)--> Immidiate
	wire		[`XLEN-1:0]		immediate;

	// 	ALU
	//	alu_a/alu_b --(i_dp_alu_ctrl)--> o_dp_alu_zero,alu_result(=o_dp_mem_addr)
	wire		[`XLEN-1:0]		alu_a, alu_b;
	wire		[`XLEN-1:0]		alu_result;
	
	// ==================================================
	// 	Assign which above signal is same as output of module.
	// ==================================================

	// assign output of Datapath is same as wire
	assign						o_dp_mem_addr		= alu_result;
	assign						o_dp_mem_wr_data	= regfile_rs2_data;
	
	// ==================================================
	// 	MUX input is concat data like {...in2, in1, in0}
	// ==================================================

	// MUX concat - concat input of mux with above signals
	wire		[(3*`XLEN)-1:0]		mux_concat_pc;
	wire		[(4*`XLEN)-1:0]		mux_concat_rd;
	wire		[(2*`XLEN)-1:0]		mux_concat_alu_a;
	wire		[(2*`XLEN)-1:0]		mux_concat_alu_b;

	assign		mux_concat_pc		= {alu_result,		pc_plus_imm,		pc_plus_4							};
	assign		mux_concat_rd		= {immediate,		pc_plus_4,			i_dp_mem_rd_data,		alu_result	};
	assign		mux_concat_alu_a	= {o_dp_pc,			regfile_rs1_data										};
	assign		mux_concat_alu_b	= {immediate,		regfile_rs2_data										};

	// ==================================================
	// 	module Instantiation
	// ==================================================
	riscv_mux
	#(
		.N_MUX_IN			(3				)
	)
	u_riscv_mux_pc(
		.o_mux_data			(pc_next		),
		.i_mux_concat_data	(mux_concat_pc	),
		.i_mux_sel			(i_dp_src_pc	)
	);

	riscv_register
	#(
		.REGISTER_INIT		(REGISTER_INIT	)
	)
	u_riscv_register_pc(
		.o_register_q		(o_dp_pc		),
		.i_register_d		(pc_next		),
		.i_register_en		(1'b1			),
		.i_clk				(i_clk			),
		.i_rstn				(i_rstn			)
	);

	riscv_regfile
	u_riscv_regfile(
		.o_regfile_rs1_data	(regfile_rs1_data	),
		.o_regfile_rs2_data	(regfile_rs2_data	),
		.i_regfile_rs1_addr	(i_dp_instr[19:15]	),
		.i_regfile_rs2_addr	(i_dp_instr[24:20]	),
		.i_regfile_rd_data	(regfile_rd_data	),
		.i_regfile_rd_addr	(i_dp_instr[11:7]	),
		.i_regfile_rd_wen	(i_dp_reg_wr_en		),
		.i_clk				(i_clk				)
	);

	riscv_immext
	u_riscv_immext(
		.o_imm_ext			(immediate			),
		.i_imm_instr		(i_dp_instr			),
		.i_imm_src			(i_dp_src_imm		)
	);

	riscv_adder
	u_riscv_adder_pc_plus_4(
		.o_adder_sum		(pc_plus_4			),
		.i_adder_a			(o_dp_pc			),
		.i_adder_b			(32'd4				)
	);

	riscv_adder
	u_riscv_adder_pc_plus_imm(
		.o_adder_sum		(pc_plus_imm		),
		.i_adder_a			(o_dp_pc			),
		.i_adder_b			(immediate			)
	);

	riscv_mux
	#(
		.N_MUX_IN			(2					)
	)
	u_riscv_mux_alu_a(
		.o_mux_data			(alu_a				),
		.i_mux_concat_data	(mux_concat_alu_a	),
		.i_mux_sel			(i_dp_src_alu_a		)
	);

	riscv_mux
	#(
		.N_MUX_IN			(2					)
	)
	u_riscv_mux_alu_b(
		.o_mux_data			(alu_b				),
		.i_mux_concat_data	(mux_concat_alu_b	),
		.i_mux_sel			(i_dp_src_alu_b		)
	);

	riscv_alu
	u_riscv_alu(
		.o_alu_result		(alu_result			),
		.o_alu_zero			(o_dp_alu_zero		),
		.i_alu_a			(alu_a				),
		.i_alu_b			(alu_b				),
		.i_alu_ctrl			(i_dp_alu_ctrl		)
	);

	riscv_mux
	#(
		.N_MUX_IN			(4					)
	)
	u_riscv_mux_regfile_rd_data(
		.o_mux_data			(regfile_rd_data	),
		.i_mux_concat_data	(mux_concat_rd		),
		.i_mux_sel			(i_dp_src_rd		)
	);

endmodule
