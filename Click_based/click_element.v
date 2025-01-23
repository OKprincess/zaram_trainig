// ===================================================
//	=================[ VLSISYS Lab. ]=================
//	* Author		: oksj (oksj@sookmyung.ac.kr)
//	* Filename		: click_element.v
//	* Date			: 2025-01-22 
//	* Description	: 
// ===================================================
`include	"dff.v"

module click_element
(
	output	o_fire,
	output	o_req,
	input	i_req, 
	input	i_out_ack
);

	wire	out_xor; 
	wire	out_xnor;
	wire	fire;
	wire	ack_req;

	xor 	u_xor0 	(out_xor, 	i_req,		ack_req);
	xnor	u_xnor0	(out_xnor,	i_out_ack, 	ack_req);
	and		u_and0	(fire,		out_xor,	out_xnor);

	dff
	u_dff(
		.o_q		(ack_req	),
		.i_d		(!ack_req	),
		.i_clk		(fire		)
	);


	assign	o_fire	= fire;
	assign	o_req	= ack_req;

endmodule



	


