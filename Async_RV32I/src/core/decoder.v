// ===================================================
//	=================[ VLSISYS Lab. ]=================
//	* Author		: oksj (oksj@sookmyung.ac.kr)
//	* Filename		: decoder.v
//	* Description	: 
// =================================================
`include	"pkg.v"

module decoder 
(
	input				i_clk,
	input				i_rstn,
	input				i_en,
	input		[31:0]	i_next_pc,
	input		[31:0]	i_instr,
	input		[3:0]	i_tag,
	output	reg	[4:0]	o_rs1,
	output	reg	[4:0]	o_rs2,
	output	reg	[4:0]	o_rd,
	output	reg	[31:0]	o_next_pc,
	output	reg	[2:0]	o_instr_format,		// type
	output	reg	[31:0]	o_instr,
	output	reg	[2:0]	o_instr_type,		// OP0,1,2 ,,
	output	reg	[2:0]	o_alu_sel,			//xu
	output	reg	[3:0]	o_tag
);

	reg		[4:0]	alu_logic;
	reg		[2:0]	format;
	reg		[2:0]	alu_sel;
	reg		[2:0]	instr_type;
	// instr type
	always @(*) begin
		if(i_instr[6:0]==7'b011011) 								alu_logic=`LUI;
		else if(i_instr[6:0]==7'b0010111) 							alu_logic=`ADD;
		else if(i_instr[6:0]==7'b1101111) 							alu_logic=`JAL;

		else if((i_instr[14:12]==3'b000)&&(i_instr[6:0]==7'b1100111)) alu_logic=`JALR;
		
		else if ((i_instr[14:12]==3'b000)&&(i_instr[6:0]==7'b1100011)) alu_logic=`BEQ;
        else if ((i_instr[14:12]==3'b001)&&(i_instr[6:0]==7'b1100011)) alu_logic=`BNE;
        else if ((i_instr[14:12]==3'b100)&&(i_instr[6:0]==7'b1100011)) alu_logic=`BLT;
        else if ((i_instr[14:12]==3'b101)&&(i_instr[6:0]==7'b1100011)) alu_logic=`BGE;
        else if ((i_instr[14:12]==3'b110)&&(i_instr[6:0]==7'b1100011)) alu_logic=`BLTU;
        else if ((i_instr[14:12]==3'b111)&&(i_instr[6:0]==7'b1100011)) alu_logic=`BGEU;

        else if ((i_instr[14:12]==3'b000)&&(i_instr[6:0]==7'b0000011)) alu_logic=`LB;
        else if ((i_instr[14:12]==3'b001)&&(i_instr[6:0]==7'b0000011)) alu_logic=`LH;
        else if ((i_instr[14:12]==3'b010)&&(i_instr[6:0]==7'b0000011)) alu_logic=`LW;
        else if ((i_instr[14:12]==3'b100)&&(i_instr[6:0]==7'b0000011)) alu_logic=`LBU;
        else if ((i_instr[14:12]==3'b101)&&(i_instr[6:0]==7'b0000011)) alu_logic=`LHU;

        else if ((i_instr[14:12]==3'b000)&&(i_instr[6:0]==7'b0100011)) alu_logic=`SB;
        else if ((i_instr[14:12]==3'b001)&&(i_instr[6:0]==7'b0100011)) alu_logic=`SH;
        else if ((i_instr[14:12]==3'b010)&&(i_instr[6:0]==7'b0100011)) alu_logic=`SW;
        
        else if ((i_instr[14:12]==3'b000)&&(i_instr[6:0]==7'b0010011)) alu_logic=`ADD;     // ADDI
        else if ((i_instr[14:12]==3'b010)&&(i_instr[6:0]==7'b0010011)) alu_logic=`SLT;     // SLTI
        else if ((i_instr[14:12]==3'b011)&&(i_instr[6:0]==7'b0010011)) alu_logic=`SLTU;    // SLTIU
        else if ((i_instr[14:12]==3'b100)&&(i_instr[6:0]==7'b0010011)) alu_logic=`XOR;     // XORI
        else if ((i_instr[14:12]==3'b110)&&(i_instr[6:0]==7'b0010011)) alu_logic=`OR;      // ORI
        else if ((i_instr[14:12]==3'b111)&&(i_instr[6:0]==7'b0010011)) alu_logic=`AND;     // ANDI

        else if ((i_instr[31:25]==7'b0000000)&&(i_instr[14:12]==3'b001)&&(i_instr[6:0]==7'b0010011)) alu_logic=`SLL;    // SLLI
        else if ((i_instr[31:25]==7'b0000000)&&(i_instr[14:12]==3'b101)&&(i_instr[6:0]==7'b0010011)) alu_logic=`SRL;    // SRLI
        else if ((i_instr[31:25]==7'b0100000)&&(i_instr[14:12]==3'b101)&&(i_instr[6:0]==7'b0010011)) alu_logic=`SRA;    // SRAI

        else if ((i_instr[31:25]==7'b0000000)&&(i_instr[14:12]==3'b000)&&(i_instr[6:0]==7'b0110011)) alu_logic=`ADD;
        else if ((i_instr[31:25]==7'b0100000)&&(i_instr[14:12]==3'b000)&&(i_instr[6:0]==7'b0110011)) alu_logic=`SUB;
        else if ((i_instr[31:25]==7'b0000000)&&(i_instr[14:12]==3'b001)&&(i_instr[6:0]==7'b0110011)) alu_logic=`SLL;
        else if ((i_instr[31:25]==7'b0000000)&&(i_instr[14:12]==3'b010)&&(i_instr[6:0]==7'b0110011)) alu_logic=`SLT;
        else if ((i_instr[31:25]==7'b0000000)&&(i_instr[14:12]==3'b011)&&(i_instr[6:0]==7'b0110011)) alu_logic=`SLTU;
        else if ((i_instr[31:25]==7'b0000000)&&(i_instr[14:12]==3'b100)&&(i_instr[6:0]==7'b0110011)) alu_logic=`XOR;
        else if ((i_instr[31:25]==7'b0000000)&&(i_instr[14:12]==3'b101)&&(i_instr[6:0]==7'b0110011)) alu_logic=`SRL;
        else if ((i_instr[31:25]==7'b0100000)&&(i_instr[14:12]==3'b101)&&(i_instr[6:0]==7'b0110011)) alu_logic=`SRA;
        else if ((i_instr[31:25]==7'b0000000)&&(i_instr[14:12]==3'b110)&&(i_instr[6:0]==7'b0110011)) alu_logic=`OR;
        else if ((i_instr[31:25]==7'b0000000)&&(i_instr[14:12]==3'b111)&&(i_instr[6:0]==7'b0110011)) alu_logic=`AND;

        else if (i_instr[31:0]==32'h00000000) alu_logic=`NOP;
        else if (i_instr[31:0]==32'h00000013) alu_logic=`NOP;

        else alu_logic=`INVALID;                        // if the opcodes are not recognized
    end

	always @(*) begin
		case (alu_logic)
			`ADD, `SUB, `SLTU, `SLT								:	alu_sel = `ADDER;			
			`XOR, `OR, `AND	   									:	alu_sel	= `LOGICAL;
			`SLL, `SRL, `SRA									:	alu_sel	= `SHIFTER;
			`BEQ, `BNE, `BLT, `BLTU, `BGE, `BGEU, `JAL, `JALR	:	alu_sel	= `BRANCH;
			`LB, `LBU, `LH, `LHU, `LW, `SB, `SH, `SW			:	alu_sel	= `MEMORY;
			default												:	alu_sel	= `BYPASS;
		endcase
	end

	always @(*) begin
		case (alu_logic)
			`ADD, `XOR,	`SLL, `BEQ, `LB							:	instr_type	= `OP0;
			`SUB, `OR, `SRL, `BNE,	`LBU, `LUI					:	instr_type	= `OP1;
			`SLTU, `AND, `SRA, `BLT, `LH						:  	instr_type	= `OP2;
			`SLT, `BLTU, `LHU									:	instr_type	= `OP3;
			`BGE, `LW											:	instr_type	= `OP4;
			`BGEU, `SW											:	instr_type	= `OP5;
			`JAL, `SH											:	instr_type	= `OP6;
			`JALR, `SB											:	instr_type	= `OP7;
			default												:	instr_type	= `OP0;
		endcase
	end

	// Decode the instr format
	always @(*) begin
 		if((i_instr[6:0]==7'b0010011)||(i_instr[6:0]==7'b1100111)||(i_instr[6:0]==7'b0000011)) // Register-Imediate(ADDI,ORI,ANDI,JALR,LOADS)
 		    format = `I_TYPE;                  
 		 else if(i_instr[6:0]==7'b0100011)   // Store_type(SW,SB,SH)
 		    format	= `S_TYPE;
 		 else if(i_instr[6:0]==7'b1100011)   // Conditional branches(BEQ,BNE,BLT, BLTU, BGE, BGEU)
 		    format	= `B_TYPE;
 		 else if ((i_instr[6:0]==7'b0110111) || (i_instr[6:0]==7'b0010111)) // U_type(LUI,AUIPC)
 		     format = `U_TYPE;
 		 else if (i_instr[6:0]==7'b1101111)  // J_type(JAL)
 		     format = `J_TYPE;
 		 else                                    // Register-Register instructions (ADD,SUB,AND...)
 		     format = `R_TYPE;
	end

	// output Register
	always @(posedge i_clk) begin
		if(i_en==1) begin
			o_rs1	<= i_instr[19:15];
			o_rs2	<= i_instr[24:20];
			o_rd	<= i_instr[11:7];
			o_next_pc	<= i_next_pc;
			o_instr		<= i_instr;
			o_instr_format	<= format;
			o_instr_type	<= instr_type;
			o_alu_sel		<= alu_sel;
			o_tag			<= i_tag;
		end
		
	end
	
	
endmodule
