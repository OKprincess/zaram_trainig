// ===================================================
//	=================[ VLSISYS Lab. ]=================
//	* Author		: oksj (oksj@sookmyung.ac.kr)
//	* Filename		: adder.v
//	* Date			: 2025-02-24 
//	* Description	: 
// ===================================================
`include		"pkg.v"

module adder 
(
	input				i_clk,
	input		[31:0]	i_opA,
	input		[31:0]	i_opB,
	input		[2:0]	i_instr_type,
	output	reg	[31:0]	o_result
);

	reg	[31:0]	result;

	always @(*) begin
		if(i_instr_type==`OP3) begin
			if($signed(i_opA) < $signed(i_opB))
				result	<= 32'b1;
			else
				result	<= 32'b0;
		end else if(i_instr_type==`OP2) begin
			if($unsigned(i_opA) < $unsigned(i_opB))
				result	<= 32'b1;
			else 
				result	<= 32'b0;
		end else if(i_instr_type==`OP1) begin
			result	<= i_opA - i_opB;
		end else begin
			result	<= i_opA + i_opB;
		end
	end

	always @(posedge i_clk) begin
		o_result	<= result;
	end
	
endmodule
