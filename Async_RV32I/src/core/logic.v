// ===================================================
//	=================[ VLSISYS Lab. ]=================
//	* Author		: oksj (oksj@sookmyung.ac.kr)
//	* Filename		: logic.v
//	* Description	: 
// ===================================================
`include		"pkg.v"

module logicUnit 
(
	input				i_clk,
	input		[31:0]	i_opA,
	input		[31:0]	i_opB,
	input		[2:0]	i_instr_type,
	output	reg	[31:0]	o_result
);

	reg		[31:0]	result;

	always @(*) begin
		if(i_instr_type==`OP0)				// XOR
			result	<= i_opA ^ i_opB;
		else if (i_instr_type==`OP1)		// OR
			result	<= i_opA | i_opB;
		else								// AND
			result	<= i_opA & i_opB;
	end

	always @(posedge i_clk) begin
		o_result	<= result;
	end
	
endmodule
