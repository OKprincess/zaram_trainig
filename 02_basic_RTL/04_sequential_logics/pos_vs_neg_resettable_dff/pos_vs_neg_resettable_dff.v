// ==================================================
//	[ VLSISYS Lab. ]
//	* Author		: SoJeong Ok (oksj@sookmyung.ac.kr)
//	* Filename		: pos_vs_neg_resettable_dff.v
//	* Date			: 2024-09-19 13:40:18
//	* Description	: 
// ==================================================

module dff_neg 
(
	output	reg		o_q,
	input			i_d,
	input			i_clk,
	input			i_rstn
);
	always @(posedge i_clk or negedge i_rstn) begin
		if(!i_rstn) begin
			o_q		<= 1'b0;
		end else begin
			o_q		<= i_d;
		end
	end
	
endmodule


module dff_pos 
(
	output	reg		o_q,
	input			i_d,
	input			i_clk,
	input			i_rst
);
	always @(posedge i_clk or posedge i_rst) begin
		if(i_rst) begin
			o_q		<= 1'b0;
		end else begin
			o_q		<= i_d;
		end
	end
	
endmodule
