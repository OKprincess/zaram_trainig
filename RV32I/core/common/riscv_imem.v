// ==================================================
//	[ VLSISYS Lab. ]
//	* Author		: SoJeong Ok (oksj@sookmyung.ac.kr)
//	* Filename		: riscv_imem.v
//	* Date			: 2024-10-04 15:43:11
//	* Description	: Instruction Memory
// ==================================================
`ifndef			NOINC
`include		"riscv_configs.v"
`endif

module riscv_imem
(
	output		[		  `XLEN-1:0]	o_imem_data,
	input		[`IMEM_ADDR_BIT-3:0]	i_mem_addr
);

	reg					 [`XLEN-1:0]	imem_arr[0:2**(`IMEM_ADDR_BIT-2)-1];

`ifdef	IMEM_INIT
	initial		$readmemh(`IMEM_INIT_FILE, i_mem_addr);
`endif

	assign		o_imem_data = imem_arr[i_mem_addr];

endmodule