// ==================================================
//	[ VLSISYS Lab. ]
//	* Author		: SoJeong Ok (oksj@sookmyung.ac.kr)
//	* Filename		: barrel_shifter.v
//	* Date			: 2024-09-23 18:53:16
//	* Description	: 
// ==================================================

module mux2 
(
	output	o_out,
	input	i_in0,
	input	i_in1,
	input	i_sel
);

	assign	o_out	= i_sel ? i_in1 : i_in0;
	
endmodule

module barrel_shifter
(
	output	[7:0]	o_y,
	input	[7:0]	i_a,
	input	[2:0]	i_k
);

	wire	[7:0]	pass_or_shift4;
	wire	[7:0]	pass_or_shift2;

	genvar	i;
	generate
	
		// First mux. if k=1-> Shift 4	, or k=0-> pass
		// 	4-bit right Shift
		for(i=0; i<8; i=i+1) begin
			mux2
			u_mux2(
				.o_out	(pass_or_shift4[i]		),	// this node is input of next mux's i_in0
				.i_in0	(i_a[i]					),
				.i_in1	(i_a[(i+4)%8]			),
				.i_sel	(i_k[2]					)
			);
		end

		// Second mux. if k=1-> Shift 2, or k=0-> pass
		// 2-bit right Shift
		for(i=0; i<8; i=i+1) begin
			mux2
			u_mux2(
				.o_out	(pass_or_shift2[i]			),
				.i_in0	(pass_or_shift4[i]			),
				.i_in1	(pass_or_shift4[(i+2)%8]	),
				.i_sel	(i_k[1]						)
			);
		end

		// Third mux. if k=1-> Shift 1, or k=0->pass
		// 1-bit right Shift
		for(i=0; i<8; i=i+1) begin
			mux2
			u_mux2(
				.o_out	(o_y[i]						),
				.i_in0	(pass_or_shift2[i]			),
				.i_in1	(pass_or_shift2[(i+1)%8]	),
				.i_sel	(i_k[0]						)
			);
		end

	endgenerate

endmodule
