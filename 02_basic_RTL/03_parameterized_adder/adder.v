// ==================================================
//	[ VLSISYS Lab. ]
//	* Author		: SoJeong Ok (oksj@sookmyung.ac.kr)
//	* Filename		: adder.v
//	* Description	: 
// ==================================================

module adder_param
#(	
	parameter	BW_DATA			= 8
)
(	
	output 		[BW_DATA-1:0]	o_s,
	output 						o_c,
	input		[BW_DATA-1:0]	i_a,
	input		[BW_DATA-1:0]	i_b,
	input						i_c
);

	assign		{o_c, o_s} = i_a + i_b + i_c;

endmodule


module adder_def 
(
	output 		[`BW_DATA-1:0]	o_s,
	output 						o_c,
	input		[`BW_DATA-1:0]	i_a,
	input		[`BW_DATA-1:0]	i_b,
	input						i_c
);
	assign		{o_c, o_s} = i_a + i_b + i_c;
	
endmodule
