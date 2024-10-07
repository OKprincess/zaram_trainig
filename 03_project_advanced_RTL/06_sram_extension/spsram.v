// ==================================================
//	[ VLSISYS Lab. ]
//	* Author		: SoJeong Ok (oksj@sookmyung.ac.kr)
//	* Filename		: spsram.v
//	* Date			: 2024-09-24 17:41:30
//	* Description	: 
// ==================================================
module spsram
#(	
	parameter	BW_DATA			= 32,
	parameter	BW_ADDR			= 4
)
(	
	output 		[BW_DATA-1:0]	o_data,
	input		[BW_DATA-1:0]	i_data,
	input		[BW_ADDR-1:0]	i_addr,
	input						i_cen,
	input						i_wen,
	input						i_oen,
	input						i_clk
);

// Memory Write
	reg		[BW_DATA-1:0]	mem[0:2**BW_ADDR-1];
	always @(posedge i_clk) begin
		if(i_cen && i_wen) begin
			mem[i_addr]	<= i_data;
		end else begin
			mem[i_addr]	<= mem[i_addr];
		end
	end

// Memory Read
// BiddongGi Let's Go ( no delay )
`ifdef	SPSRAM_ASYNC
	assign	o_data	=	!i_oen			?	'bz:
						i_cen && !i_wen	?	mem[i_addr] : 'bx;

// DDong-Gi Let's Go == Sync
`else
	reg		[BW_DATA-1:0]	o_data;
	always @(posedge i_clk) begin
		if (i_oen) begin
			if (i_cen && !i_wen) begin
				o_data	<= mem[i_addr];
			end else begin
				o_data	<= 'bx;
			end
		end else begin
			o_data	<= 'bz;
		end
	end
`endif

endmodule
