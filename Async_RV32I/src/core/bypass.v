// ===================================================
//	=================[ VLSISYS Lab. ]=================
//	* Author		: oksj (oksj@sookmyung.ac.kr)
//	* Filename		: bypass.v
//	* Description	: 
// ===================================================
`include		"pkg.v"

module bypassUnit
(
	input				i_clk,
	input		[31:0]	i_opA,
	output	reg	[31:0]	o_result
);

	always @(*) begin
		o_result	<= i_opA;
	end
	
endmodule
