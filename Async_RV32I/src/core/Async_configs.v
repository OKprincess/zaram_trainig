// ===================================================
//	=================[ VLSISYS Lab. ]=================
//	* Author		: oksj (oksj@sookmyung.ac.kr)
//	* Filename		: Async_configs.v
//	* Description	: 
// ===================================================

// ===================================================
//	ALU Operation		{funct7[5],funct3}
// ===================================================
`define	ALU_ADD				4'b0000	//
`define	ALU_SUB				4'b1000	//
`define	ALU_XOR				4'b0100
`define	ALU_OR				4'b0110
`define	ALU_AND				4'b0111
`define	ALU_SLL				4'b0001
`define	ALU_SRL				4'b0101	//
`define	ALU_SRA				4'b1101	//
`define	ALU_SLT				4'b0010
`define	ALU_SLTU			4'b0011
`define	ALU_NONE			4'b1111

// ===================================================
// 	Opcodes
// ===================================================
`define	OPCODE_R_OP			7'b0110011
`define	OPCODE_I_OP			7'b0010011
`define	OPCODE_I_LOAD		7'b0000011
`define	OPCODE_S_STORE		7'b0100011
`define	OPCODE_B_BRANCH		7'b1100011
`define	OPCODE_J_JAL		7'b1101111
`define	OPCODE_I_JALR		7'b1100111
`define	OPCODE_U_LUI		7'b0110111
`define	OPCODE_U_AUIPC		7'b0010111
