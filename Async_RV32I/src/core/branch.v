// ===================================================
//	=================[ VLSISYS Lab. ]=================
//	* Author		: oksj (oksj@sookmyung.ac.kr)
//	* Filename		: branch.v
//	* Description	: 
// ===================================================
`include 		"pkg.v"

module branchUnit
(
	input					i_clk,
	input		[31:0]		i_opA,
	input		[31:0]		i_opB,
	input		[31:0]		i_offset,
	input		[31:0]		i_next_pc,
	input		[2:0]		i_instr_type,
	output	reg	[31:0]		o_result,
	output	reg	[31:0]		o_result_jal,
	output	reg				o_jump,
	output	reg				o_wr_en
);

	reg		[31:0]	result;
	wire	[31:0]	sum;
	reg				jump, wr_en_int;

	// Result assign
	assign	sum = i_opA + i_opB;

	always @(*) begin
		if(i_instr_type==`OP6)
			result	<= sum;
		else if (i_instr_type==`OP7) begin
			result[31:1] 	<= sum[31:1];
			result[0]		<= 0;
		end else
			result	<= i_next_pc + i_offset;
	end

	// generate branch signal
	always @(*) begin
		if(i_instr_type==`OP0)
			jump	<= (i_opA == i_opB);
		else if (i_instr_type==`OP1)
			jump	<= (i_opA != i_opB);
		else if (i_instr_type==`OP2)
			jump	<= ($signed(i_opA) < $signed(i_opB));
		else if (i_instr_type==`OP3)
			jump	<= ($unsigned(i_opA) < $unsigned(i_opB));
		else if (i_instr_type==`OP4)
			jump	<= ($signed(i_opA) >= $signed(i_opB));
		else if (i_instr_type==`OP5)
			jump	<= ($unsigned(i_opA) >= $unsigned(i_opB));
		else if ((i_instr_type==`OP6)||(i_instr_type==`OP7))
			jump	<= 1;
		else
			jump	<= 0;
	end


	// write enable signal
	always @(*) begin
		if((i_instr_type==`OP6)||(i_instr_type==`OP7))
			wr_en_int	<= 1'b1;
		else 
			wr_en_int	<= 1'b0;
	end

	// Output register
	always @(i_clk) begin
		o_result		<= result;
		o_result_jal	<= i_next_pc + 4;
		o_jump			<= jump;
		o_wr_en			<= wr_en_int;
	end



endmodule
