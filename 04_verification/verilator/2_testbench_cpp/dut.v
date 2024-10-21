// ==================================================
//	[ VLSISYS Lab. ]
//	* Author		: SoJeong Ok (oksj@sookmyung.ac.kr)
//	* Filename		: dut.v
//	* Description	: 
// ==================================================

module dut 
#(
	parameter	BW_DATA 	= 4
)
(
	output	reg	[BW_DATA-1:0]	o_y,
	input		[BW_DATA-1:0]	i_a,
	input		[BW_DATA-1:0]	i_b,
	input						i_clk,
	input						i_rstn
);

	always @(posedge i_clk or negedge i_rstn) begin
		if(!i_rstn) begin
			o_y <= 0;
		end else begin
			o_y <= i_a + i_b;
		end
	end
	
endmodule
