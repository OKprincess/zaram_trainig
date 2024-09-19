// ==================================================
//	[ VLSISYS Lab. ]
//	* Author		: SoJeong Ok (oksj@sookmyung.ac.kr)
//	* Filename		: upcnt.v
//	* Date			: 2024-09-19 14:16:12
//	* Description	: 
// ==================================================

module upcnt
#(	
	parameter	UPBND	= 32 
)
(	
	output reg	[$clog2(UPBND+1)-1:0]	o_cnt,
	input								i_clk,
	input								i_rstn
);

	always @(posedge i_clk or negedge i_rstn) begin
		if(!i_rstn) begin
			o_cnt	<= 0;
		end else begin
			if(o_cnt == UPBND) begin
				o_cnt	<= 0;
			end else begin
				o_cnt	<= o_cnt + 1;
			end
		end
	end



endmodule
