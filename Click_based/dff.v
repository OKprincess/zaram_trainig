// ===================================================
//	=================[ VLSISYS Lab. ]=================
//	* Author		: oksj (oksj@sookmyung.ac.kr)
//	* Filename		: dff.v
//	* Date			: 2025-01-22 
//	* Description	: 
// ===================================================

module dff
(
	output	reg		o_q,
	input			i_d,
	input			i_clk
);

	always @(posedge i_clk) begin
		if (i_clk != 1 && i_clk !=0) begin
			o_q <= 0;
		end else begin
			o_q	<= i_d;
		end
	end

endmodule

