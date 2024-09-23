// ==================================================
//	[ VLSISYS Lab. ]
//	* Author		: SoJeong Ok (oksj@sookmyung.ac.kr)
//	* Filename		: gray_code_converter.v
//	* Date			: 2024-09-23 17:36:26
//	* Description	: 
// ==================================================

// Convert Binary to Graycode
module bin_to_gray
#(	
	parameter	BW_DATA			= 8 
)
(	
	output 		[BW_DATA-1:0]	out_gray,
	input		[BW_DATA-1:0]	in_bin
);

	assign		out_gray[BW_DATA-1]	= in_bin[BW_DATA-1];		// MSB is always same

	genvar		i;
	generate
		for	(i=0; i<BW_DATA-1; i=i+1) begin
			assign	out_gray[i]	= in_bin[i+1] ^ in_bin[i];	// xor
		end
	endgenerate

endmodule


// Convert Gray to Binary
module gray_to_bin 
#(	
	parameter	BW_DATA			= 8
)
(
	output		[BW_DATA-1:0]	out_bin,
	input		[BW_DATA-1:0]	in_gray
);

	assign		out_bin[BW_DATA-1]	= in_gray[BW_DATA-1];

	genvar		i;
	generate
		for	(i=BW_DATA-2; i>=0; i=i-1) begin
			assign	out_bin[i]	= out_bin[i+1] ^ in_gray[i];
		end
	endgenerate

endmodule
