// ==================================================
//	[ VLSISYS Lab. ]
//	* Author		: SoJeong Ok (oksj@sookmyung.ac.kr)
//	* Filename		: riscv_top.v
//	* Date			: 2024-10-14 18:53:57
//	* Description	: 
// ==================================================
`ifndef		NOINC
`include	"../common/riscv_imem.v"
`include	"../common/riscv_dmem.v"
`include	"riscv_cpu.v"
`endif

module riscv_top 
#(
	parameter	REGISTER_INIT	= 0
)
(
	output		[`XLEN-1:0]		o_riscv_imem_pc,
	output		[`XLEN-1:0]		o_riscv_imem_instr,
	output		[`XLEN-1:0]		o_riscv_dmem_addr,
	output						o_riscv_dmem_wr_en,
	output		[	   3:0]		o_riscv_dmem_byte_sel,
	output		[`XLEN-1:0]		o_riscv_dmem_wr_data,
	output		[`XLEN-1:0]		o_riscv_dmem_rd_data,
	input						i_clk,
	input						i_rstn
);

	riscv_cpu
	#(
		.REGISTER_INIT			(REGISTER_INIT			)
	)
	u_riscv_cpu(
		.o_cpu_imem_pc			(o_riscv_imem_pc		),
		.o_cpu_dmem_addr		(o_riscv_dmem_addr		),
		.o_cpu_dmem_wr_en		(o_riscv_dmem_wr_en		),
		.o_cpu_dmem_wr_data		(o_riscv_dmem_wr_data	),
		.o_cpu_dmem_byte_sel	(o_riscv_dmem_byte_sel	),
		.i_cpu_imem_instr		(o_riscv_imem_instr		),
		.i_cpu_dmem_rd_data		(o_riscv_dmem_rd_data	),
		.i_clk					(i_clk					),
		.i_rstn					(i_rstn					)
	);

	riscv_imem
	u_riscv_imem(
		.o_imem_data			(o_riscv_imem_instr						),
		.i_mem_addr				(o_riscv_imem_pc[`IMEM_ADDR_BIT-1:2]	)
	);

	riscv_dmem
	u_riscv_dmem(
		.o_dmem_data			(o_riscv_dmem_rd_data					),
		.i_dmem_data			(o_riscv_dmem_wr_data					),
		.i_dmem_addr			(o_riscv_dmem_addr[`DMEM_ADDR_BIT-1:2]	),
		.i_dmem_byte_sel		(o_riscv_dmem_byte_sel					),
		.i_dmem_wr_en			(o_riscv_dmem_wr_en						),
		.i_clk					(i_clk									)
	);
	
endmodule
