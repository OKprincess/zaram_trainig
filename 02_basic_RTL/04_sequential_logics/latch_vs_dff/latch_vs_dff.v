// ==================================================
//	[ VLSISYS Lab. ]
//	* Author		: SoJeong Ok (oksj@sookmyung.ac.kr)
//	* Filename		: latch_vs_dff.v
//	* Date			: 2024-09-13 15:57:26
//	* Description	: 
// ==================================================

module latch	
(
	output	reg		o_q,
	input			i_d,
	input			i_clk
);

	always @(*) begin
		if(i_clk) begin
			o_q		<= i_d;
		end
	end
	
endmodule


module dff 
(
	output	reg		o_q,
	input			i_d,
	input			i_clk
);

	always @(posedge i_clk) begin
		o_q		<= i_d;
	end
	
endmodule
