// ===================================================
//	=================[ VLSISYS Lab. ]=================
//	* Author		: oksj (oksj@sookmyung.ac.kr)
//	* Filename		: click_element.v
//	* Description	: 
// ===================================================
//`include	"dff.v"

module click_element
(
	output	out_click,
	output	out_ackL,
	output	out_reqR,
	input	in_reqL,
	input	in_ackR,
	input	i_rstn
);

	wire	xor_outL, xnor_outR, and_out; 
	reg		dff_outL,  dff_outR;

	assign	xor_outL	= in_reqL ^ dff_outL;
	assign	xnor_outR	= ~(dff_outR ^ in_ackR);	
	assign	and_out		= xor_outL & xnor_outR;

	/*dff
	#(
		.BW_DFF			(1				)
	)
	u_dffL(
		.o_q			(dff_outL		),
		.i_d			(~dff_outL		),
		.i_clk			(and_out		),
		.i_rstn			(				)
	);*/
	always @(posedge and_out or negedge i_rstn) begin
		if(!i_rstn) begin
			dff_outL <= 1'b0;
		end else begin
			dff_outL <= ~dff_outL;
		end
	end

	/*dff
	#(
		.BW_DFF			(1				)
	)
	u_dffR(
		.o_q			(dff_outR		),
		.i_d			(~dff_outR		),
		.i_clk			(and_out		),
		.i_rstn			(				)
	);*/
	always @(posedge and_out or negedge i_rstn) begin
		if(!i_rstn) begin
			dff_outR <= 1'b0;
		end else begin
			dff_outR <= ~dff_outR;
		end
	end

	assign	out_click	= and_out;
	assign	out_reqR	= dff_outR;
	assign	out_ackL	= dff_outL;

	endmodule
