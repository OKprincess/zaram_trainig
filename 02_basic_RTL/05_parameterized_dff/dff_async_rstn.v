// ==================================================
//	[ VLSISYS Lab. ]
//	* Author		: SoJeong Ok (oksj@sookmyung.ac.kr)
//	* Filename		: dff_async_rstn.v
//	* Date			: 2024-09-19 15:26:00
//	* Description	: 
// ==================================================

module	dff_async_rstn
#(	
	parameter	BW_DATA	= 8
)
(	
	output reg	[BW_DATA-1:0]	o_q,
	input		[BW_DATA-1:0]	i_d,
	input						i_clk,
	input						i_rstn
);

	always @(posedge i_clk or negedge i_rstn) begin
		if(!i_rstn) begin
			o_q		<= 1'b0;
		end else begin
			o_q		<= i_d;
		end
	end

	endmodule
