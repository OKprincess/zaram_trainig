// ==================================================
//	[ VLSISYS Lab. ]
//	* Author		: SoJeong Ok (oksj@sookmyung.ac.kr)
//	* Filename		: spsram_doubled.v
//	* Date			: 2024-09-23 12:04:50
//	* Description	: 
// ==================================================
`include	"spsram.v"

module spsram_doubled
 (	
 	output 		[31:0]			o_data,
 	input		[31:0]			i_data,
 	input		[4:0]			i_addr,
 	input						i_cen,
 	input						i_wen,
 	input						i_oen,
	input						i_clk
 );

 	spsram
	#(
		.BW_DATA				(32		),
		.BW_ADDR				(4		)
	)
	u_spsram_0(
		.o_data					(o_data	 		),
		.i_data					(i_data			),
		.i_addr					(i_addr[3:0]	), 
		.i_cen					(~i_addr[4]	 	),
		.i_wen					(i_wen			),
		.i_oen					(~i_addr[4]		),	
		.i_clk					(i_clk			)
	);

	
 	spsram
	#(
		.BW_DATA				(32		),
		.BW_ADDR				(4		)
	)
	u_spsram_1(
		.o_data					(o_data	 		),
		.i_data					(i_data			),
		.i_addr					(i_addr[3:0]	), 
		.i_cen					(i_addr[4]	 	),
		.i_wen					(i_wen			),
		.i_oen					(i_addr[4]		),	
		.i_clk					(i_clk			)
	);

	endmodule
