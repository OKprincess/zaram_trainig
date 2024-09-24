// ==================================================
//	[ VLSISYS Lab. ]
//	* Author		: SoJeong Ok (oksj@sookmyung.ac.kr)
//	* Filename		: alu.v
//	* Date			: 2024-09-24 11:09:10
//	* Description	: 
// ==================================================
module alu
(	
	output reg	[31:0]			o_y,
	output 						o_c,
	input		[31:0]			i_a,
	input		[31:0]			i_b,
	input		[2:0]			i_f
);

	wire		[31:0]			b_mux;
	wire		[31:0]			sum;

	assign		b_mux		= i_f[2] ? ~i_b : i_b;
	assign		{o_c, sum}	= i_a + b_mux + i_f[2];
	// define o_y with assign
	// assign		o_y			= (i_f[1:0] == 0) ? i_a & b_mux :
	// 								(i_f[1:0] == 1) ? i_a | b_mux :
	// 								(i_f[1:0] == 2) ? sum 			: {{31{1'b0}}, sum[31]}; 
	always @(*) begin
		case(i_f[1:0])
			2'b00:	o_y		= i_a&b_mux;
			2'b01:	o_y		= i_a|b_mux;
			2'b10:	o_y		= sum;
			2'b11:	o_y		= {{31{1'b0}}, sum[31]};	// zero-extension
		endcase
	end
endmodule
