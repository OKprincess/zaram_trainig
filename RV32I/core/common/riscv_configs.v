// ==================================================
//	[ VLSISYS Lab. ]
//	* Author		: SoJeong Ok (oksj@sookmyung.ac.kr)
//	* Filename		: riscv_configs.v
//	* Date			: 2024-09-30 17:55:04
//	* Description	: 
// ==================================================

// ==================================================
// 	RISC-V Integer Bit & Memory Specification	
// ==================================================
`define	XLEN			32
`define	DMEM_ADDR_BIT	8
`define	IMEM_ADDR_BIT	8

`define	DMEM_INIT
`define	DMEM_INIT_FILE	"riscv_dmem.mif"
`define	IMEM_INIT
`define	IMEM_INIT_FILE	"riscv_imem.mif"
// ==================================================
// 	Immidiate Source	
// ==================================================

// ==================================================
// 	Immidiate Source	
// ==================================================
`define	SRC_IMM_R		3'b000
`define	SRC_IMM_I		3'b001
`define	SRC_IMM_S		3'b010
`define	SRC_IMM_B		3'b011
`define	SRC_IMM_U		3'b100
`define	SRC_IMM_J		3'b101

// ==================================================
// 	RISC-V Integer Bit & Memory Specification	
// ==================================================

