// ===================================================
//	=================[ VLSISYS Lab. ]=================
//	* Author		: oksj (oksj@sookmyung.ac.kr)
//	* Filename		: riscv_cpu.v
//	* Date			: 2025-01-14 
//	* Description	: 
// ===================================================

`ifndef		NOINC
`include	"../common/riscv_configs.v"
`include	"../common/riscv_dmem_interface.v"
`include	"../common/riscv_mux.v"
`include	"../common/riscv_register.v"
`include	"../common/riscv_adder.v"
`include	"../common/riscv_regfile.v"
`include	"../common/riscv_alu.v"
`include	"../common/riscv_immext.v"
`include	"riscv_ctrl.v"
`include	"riscv_hazard.v"
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
	
	wire	[`XLEN-1:0]		pc_next;

	riscv_mux
	#(
		.N_MUX_IN			(3				)
	)
	u_riscv_mux_pc(
		.o_mux_data			(pc_next		),
		.i_mux_concat_data	(mux_concat_pc	),
		.i_mux_sel			(src_pc[EX]		)
	);
		
	riscv_adder
	u_riscv_adder_pc_plus_4(
		.o_adder_sum		(pc4	[IF]	),
		.i_adder_a			(pc		[IF]	),
		.i_adder_b			(32'd4			)
	);

	// -----------------------------------------------------
	// ID Stage
	// -----------------------------------------------------
	always @(*) begin
		opcode		[ID]	= instr[ID][06:00];
		funct3		[ID]	= instr[ID][14:12];
		funct7_5b	[ID]	= instr[ID][30];
		rs1			[ID]	= instr[ID][19:15];
		rs2			[ID]	= instr[ID][24:20];
		rd			[ID]	= instr[ID][11:07];
	end

	// controll unit
	riscv_ctrl
	u_riscv_ctrl(
		.o_ctrl_src_imm		(src_imm		[ID]	),
		.o_ctrl_src_rd		(w_src_rd		[ID]	),
		.o_ctrl_src_alu_a	(w_src_alu_a	[ID]	),
		.o_ctrl_src_alu_b	(w_src_alu_b	[ID]	),
		.o_ctrl_reg_wr_en	(w_reg_wr_en	[ID]	),
		.o_ctrl_mem_wr_en	(w_mem_wr_en	[ID]	),
		.o_ctrl_alu_ctrl	(w_alu_ctrl		[ID]	),
		.i_ctrl_opcode		(opcode			[ID]	),
		.i_ctrl_funct3		(funct3			[ID]	),
		.i_ctrl_funct7_5b	(funct7_5b		[ID]	)
	);

	// regfile addrress is for Hazard control
	// ~i_clk is for synchrnous
	riscv_regfile
	u_riscv_regfile(
		.o_regfile_rs1_data	(w_rs1_data		[ID]	),
		.o_regfile_rs2_data	(w_rs2_data		[ID]	),
		.i_regfile_rs1_addr	(rs1			[ID]	),
		.i_regfile_rs2_addr	(rs2			[ID]	),
		.i_regfile_rd_data	(rd_data		[WB]	),
		.i_regfile_rd_addr	(rd				[WB]	),
		.i_regfile_rd_wen	(reg_wr_en		[WB]	),
		.i_clk				(~i_clk					)
	);

	// immediate extension
	riscv_immext
	u_riscv_immmext(
		.o_imm_ext			(w_imm			[ID]		),
		.i_imm_instr		(instr			[ID][31:7]	),
		.i_imm_src			(src_imm		[ID]		)
	);
	// -----------------------------------------------------
	//  EX Stage
	// -----------------------------------------------------
	riscv_mux
	#(
		N_MUX_IN			(3					)
	)
	u_riscv_mux_fwd_a(
		.o_mux_data			(fwd_a		[EX]	),
		.i_mux_concat_data	(mux_concat_fwd_a	),
		.i_mux_sel			(fwd_sel_a	[EX]	)
	);

	riscv_mux
	#(
		N_MUX_IN			(3					)
	)
	u_riscv_mux_fwd_b(
		.o_mux_data			(fwd_b		[EX]	),
		.i_mux_concat_data	(mux_concat_fwd_b	),
		.i_mux_sel			(fwd_sel_b	[EX]	)
	);


	riscv_mux
	#(
		N_MUX_IN			(2					)
	)
	u_riscv_mux_alu_a(
		.o_mux_data			(alu_a		[EX]	),
		.i_mux_concat_data	(mux_concat_alu_a	),
		.i_mux_sel			(src_alu_a	[EX]	)
	);

	riscv_alu
	u_riscv_alu(
		.o_alu_out			(w_alu_out	[EX]	),
		.o_alu_src_pc		(src_pc		[EX]	),
		.i_alu_a			(alu_a		[EX]	),
		.i_alu_b			(alu_b		[EX]	),
		.i_alu_opcode		(opcode		[EX]	),
		.i_alu_funct3		(funct3		[EX]	),
		.i_alu_ctrl			(alu_ctrl	[EX]	)
	);

	riscv_adder
	u_riscv_adder_pc_plus_imm(
		.o_adder_sum		(pcimm		[EX]	),
		.i_adder_a			(pc			[EX]	),
		.i_adder_b			(imm		[EX]	)
	);
	// -----------------------------------------------------
	//  MM Stage
	// -----------------------------------------------------
	riscv_dmem_interface
	u_riscv_dmem_interface(
		.o_dmem_intf_addr		(o_cpu_mem_addr			),
		.o_dmem_intf_wen		(o_cpu_mem_wr_en		),
		.o_dmem_intf_wr_data	(o_cpu_mem_wr_data		),
		.o_dmem_intf_byte_sel	(o_cpu_mem_strb			),
		.o_dmem_intf_rd_data	(mem_rd_data[MM]		),
		.i_dmem_intf_addr		(alu_out	[MM]		),
		.i_dmem_intf_wen		(mem_wr_en	[MM]		),
		.i_dmem_intf_wr_data	(fwd_b		[MM]		),
		.i_dmem_intf_rd_data	(i_cpu_mem_rd_data		),
		.i_dmem_intf_func3		(funct3		[MM]		)
		);
		
	// -----------------------------------------------------
	//  WB Stage
	// -----------------------------------------------------
	riscv_mux
	#(
		.N_MUX_IN		(4						)
	)
	u_riscv_mux_regfile_rd_data(
		.o_mux_data			(rd_data	[WB]	),
		.i_mux_concat_data	(mux_concat_rd		),
		.i_mux_sel			(src_rd		[WB]	)
	);

	// -----------------------------------------------------
	// Internal Signals 
	// -----------------------------------------------------
	// Control unit: Control I/O Signals
	// w_xxx: output of module && transfer to next Stage
	reg		[2:0]			funct3		[ID:MM];
	reg		[6:0]			opcode		[ID:EX];
	reg		[0:0]			funct7_5b	[ID:ID];

	wire	[0:0]			w_reg_wr_en	[ID:ID];
	wire	[1:0]			w_src_rd	[ID:ID];
	wire	[0:0]			w_mem_wr_en	[ID:ID];
	wire	[3:0]			w_alu_ctrl	[ID:ID];
	wire	[0:0]			w_src_alu_a	[ID:ID];
	wire	[0:0]			w_src_alu_b	[ID:ID];
	wire	[2:0]			src_imm		[ID:ID];

	reg		[0:0]			reg_wr_en	[EX:WB];
	reg		[1:0]			src_rd		[EX:WB];
	reg		[0:0]			mem_wr_en	[EX:MM];
	reg		[3:0]			alu_ctrl	[EX:EX];
	reg		[0:0]			src_alu_a	[EX:EX];
	reg		[0:0]			src_alu_b	[EX:EX];

	// Internal Signals (Non-Control)
	wire	[1:0]			src_pc		[EX:EX];
	
	reg		[`XLEN-1:0]		pc			[IF:EX];
	reg		[`XLEN-1:0]		pc4			[IF:WB];
	wire	[`XLEN-1:0]		pcimm		[EX:EX];
	
	reg		[`XLEN-1:0]		instr		[ID:ID];

	wire	[`XLEN-1:0]		w_imm		[ID:ID];
	reg		[`XLEN-1:0]		imm			[EX:WB];
	
	reg		[4:0]			rs1			[ID:EX];
	reg		[4:0]			rs2			[ID:EX];
	wire	[`XLEN-1:0]		w_rs1_data	[ID:ID];
	wire	[`XLEN-1:0]		w_rs2_data	[ID:ID];
	reg		[`XLEN-1:0]		rs1_data	[EX:EX];
	reg		[`XLEN-1:0]		rs2_data	[EX:EX];
	reg		[4:0]			rd			[ID:WB];
	wire	[`XLEN-1:0]		rd_data		[WB:WB];

	reg		[`XLEN-1:0]		mem_rd_data	[MM:WB];

	wire	[`XLEN-1:0]		fwd_a		[EX:EX];
	wire	[`XLEN-1:0]		w_fwd_b		[EX:EX];
	reg		[`XLEN-1:0]		fwd_b		[MM:MM];

	wire	[`XLEN-1:0]		alu_a		[EX:EX];
	wire	[`XLEN-1:0]		alu_b		[EX:EX];
	
	wire	[`XLEN-1:0]		w_alu_out	[EX:EX];
	reg		[`XLEN-1:0]		alu_out		[MM:WB];


	// -----------------------------------------------------
	// Hazard Unit
	// -----------------------------------------------------
	wire	[1:0]			fwd_sel_a	[EX:EX];
	wire	[1:0]			fwd_sel_b	[EX:EX];
	wire					stall		[IF:ID];
	wire					flush		[ID:EX];

	riscv_hazard
	u_riscv_hazard(
		.o_fwd_sel_a_ex		(fwd_sel_a	[EX]	),
		.o_fwd_sel_b_ex		(fwd_sel_b	[EX]	),
		.o_stall_if			(stall		[IF]	),
		.o_stall_id			(stall		[ID]	),
		.o_flush_id			(flush		[ID]	),
		.o_flush_ex			(flush		[EX]	),
		.i_src_pc_ex		(src_pc		[EX]	),
		.i_src_rd_ex		(src_rd		[EX]	),
		.i_rs1_id			(rs1		[ID]	),
		.i_rs2_id			(rs2		[ID]	),
		.i_rs1_ex			(rs1		[EX]	),
		.i_rs2_ex			(rs2		[EX]	),
		.i_rd_ex			(rd			[EX]	),
		.i_rd_mm			(rd			[MM]	),
		.i_rd_wb			(rd			[WB]	),
		.i_reg_wr_en_ex		(reg_wr_en	[EX]	),
		.i_reg_wr_en_mm		(reg_wr_en	[MM]	),
		.i_reg_wr_en_wb		(reg_wr_en	[WB]	)
	);

	// -----------------------------------------------------
	// Pipeline Flip-Flop
	// -----------------------------------------------------
	// Pipeline Stage: IF
	always @(posedge i_clk) begin
		if (~i_rstn) begin
			pc[IF]	<= 0;
		end else begin
			if (stall[IF]) begin
				pc[IF]	<= pc[IF];
			end else begin
				pc[IF]	<= pc_next;
			end
		end
	end

	// Pipeline Stage: ID
	always @(posedge i_clk) begin
		if (stall[ID]) begin
			instr	[ID]	<= instr	[ID];
			pc		[ID]	<= pc		[ID];
			pc4		[ID]	<= pc4		[ID];
		end else begin
			if (flush[ID]) begin
				instr	[ID]	<= 0;
				pc		[ID]	<= 0;
				pc4		[ID]	<= 0;
			end else begin
				instr	[ID]	<= i_cpu_instr;
				pc		[ID]	<= pc	[IF];
				pc4		[ID]	<= pc4	[IF];
			end
		end
	end

	// Pipeline Stage: EX
	always @(posedge i_clk) begin
		if(flush[EX]) begin
			// Control Signals
			reg_wr_en	[EX]	<= 0; 
			src_rd	 	[EX]	<= 0;
			mem_wr_en	[EX]	<= 0;
			alu_ctrl 	[EX]	<= 0;
			src_alu_a	[EX]	<= 0;
			src_alu_b	[EX]	<= 0;
			funct3	 	[EX]	<= 0;	
			opcode	 	[EX]	<= 0;
			// Other Signals
            rs1_data	[EX]	<= 0; 
            rs2_data	[EX]	<= 0;
			pc			[EX]	<= 0;
            rs1			[EX]	<= 0;
            rs2			[EX]	<= 0;
            rd			[EX]	<= 0;
            pc4			[EX]	<= 0;
            imm			[EX]	<= 0;
		end else begin
			// Control Signals
			reg_wr_en	[EX]	<= w_reg_wr_en	[ID]; 
			src_rd	 	[EX]	<= w_src_rd	 	[ID];
			mem_wr_en	[EX]	<= w_mem_wr_en	[ID];
			alu_ctrl 	[EX]	<= w_alu_ctrl 	[ID];
			src_alu_a	[EX]	<= w_src_alu_a	[ID];
			src_alu_b	[EX]	<= w_src_alu_b	[ID];
			funct3	 	[EX]	<= funct3	 	[ID];	
			opcode	 	[EX]	<= opcode	 	[ID];
			// Other Signals
            rs1_data	[EX]	<= w_rs1_data	[ID]; 
            rs2_data	[EX]	<= w_rs2_data	[ID];
			pc			[EX]	<= pc			[ID];
            rs1			[EX]	<= rs1			[ID];
            rs2			[EX]	<= rs2			[ID];
            rd			[EX]	<= rd			[ID];
            pc4			[EX]	<= pc4			[ID];
            imm			[EX]	<= w_imm		[ID];
        end 
	end

	// Pipeline Stage: MM
	always @(posedge i_clk) begin
		// Control Signals
        reg_wr_en	[MM]	<= reg_wr_en	[EX]; 
        src_rd	 	[MM]	<= src_rd	 	[EX];
        mem_wr_en	[MM]	<= mem_wr_en	[EX];
        funct3	 	[MM]	<= funct3	 	[EX]; 
		// Other Signals
		fwd_b		[MM]	<= w_fwd_b		[EX];
		alu_out		[MM]	<= w_alu_out	[EX];
		rd			[MM]	<= rd			[EX];
		pc4			[MM]	<= pc4			[EX];
		imm			[MM]	<= imm			[EX];
	end

	// Pipeline Stage: WB
	always @(posedge i_clk) begin
		// Control Signals
		reg_wr_en	[WB]	<= reg_wr_en	[MM];
		src_rd		[WB]	<= src_rd		[MM];
		// Other Signals
		alu_out		[WB]	<= alu_out		[MM];
		mem_rd_data	[WB]	<= mem_rd_data	[MM];
		rd			[WB]	<= rd			[MM];
		pc4			[WB]	<= pc4			[MM];
		imm			[WB]	<= imm			[MM];
	end

	// -----------------------------------------------------
	//	MUX Concat 
	// -----------------------------------------------------
	wire		[(3*`XLEN)-1:0]	mux_concat_pc;
	wire		[(3*`XLEN)-1:0]	mux_concat_fwd_a;
	wire		[(3*`XLEN)-1:0]	mux_concat_fwd_b;
	wire		[(2*`XLEN)-1:0]	mux_concat_alu_a;
	wire		[(2*`XLEN)-1:0]	mux_concat_alu_b;
	wire		[(4*`XLEN)-1:0]	mux_concat_rd;

	assign	mux_concat_pc   	= {w_alu_out[EX],	pcimm[EX],		pc4[IF]			};	
	assign	mux_concat_fwd_a	= {rd_data[WB],		alu_out[MM],	rs1_data[EX]	};
	assign	mux_concat_fwd_b	= {rd_data[WB],		alu_out[MM],	rs2_data[EX]	};
	assign	mux_concat_alu_a	= {pc[EX],			fwd_a[EX]		};
	assign	mux_concat_alu_b	= {imm[EX],			w_fwd_b[EX]		};
	assign	mux_concat_rd		= {imm[WB],			pc4[WB],		mem_rd_data[WB],	alu_out[WB]};


endmodule
