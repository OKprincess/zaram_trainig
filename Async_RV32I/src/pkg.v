// ===================================================
//	=================[ VLSISYS Lab. ]=================
//	* Author		: oksj (oksj@sookmyung.ac.kr)
//	* Filename		: pkg.v
//	* Date			: 2025-02-21 
//	* Description	: 
// ===================================================

/////////////////////////Instruction Format/////////////////////
`define	R_TYPE	3'b000
`define	I_TYPE	3'b001
`define	S_TYPE	3'b010
`define	B_TYPE	3'b011
`define	U_TYPE	3'b100
`define	J_TYPE	3'b101

/////////////////////////Instruction Type///////////////////
`define	OP0		3'b000
`define	OP1		3'b001
`define	OP2		3'b010
`define	OP3		3'b011
`define	OP4		3'b100
`define	OP5		3'b101
`define	OP6		3'b110
`define	OP7		3'b111
`define	NOTOKEN	3'bzzz

//////////////////alu_logic/////////////////////
`define	NOP		5'b00000
`define	LUI		5'b00001
`define	INVALID	5'b00010

`define	ADD		5'b00011
`define	SUB		5'b00100
`define	SLTU	5'b00101
`define	SLT		5'b00110

`define	XOR		5'b00111
`define	OR		5'b01000
`define	AND		5'b01001

`define	SLL		5'b01010
`define	SRL		5'b01011
`define	SRA		5'b01100

`define	BEQ		5'b01101
`define	BNE		5'b01110
`define	BLT		5'b01111
`define	BLTU	5'b10000
`define	BGE		5'b10001
`define	BGEU	5'b10010
`define	JAL		5'b10011
`define	JALR	5'b10100

`define	LB		5'b10101
`define	LBU		5'b10110
`define	LH		5'b10111
`define	LHU		5'b11000
`define	LW		5'b11001
`define	SB		5'b11010
`define	SH		5'b11011
`define	SW		5'b11100

/////////////////////// alu_sel///////////////////
`define	BYPASS	3'b000
`define	ADDER	3'b001
`define	LOGICAL	3'b010
`define	SHIFTER	3'b011
`define	BRANCH	3'b100
`define	MEMORY	3'b101
















