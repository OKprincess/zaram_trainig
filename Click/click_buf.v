// ===================================================
//	=================[ VLSISYS Lab. ]=================
//	* Author		: oksj (oksj@sookmyung.ac.kr)
//	* Filename		: click_buf.v
//	* Date			: 2025-01-23 
//	* Description	: system verilog to verilog
// ===================================================

module click_buf(
  input					reset,
  input			[1:0]	in_data,	// 2-bit input data
  input					in_req,		// Input request
  output	reg			in_ack,		// Input acknowledge
  output	reg	[1:0]	out_data,	// 2-bit output dta
  output	reg			out_req,	// Output request
  input					out_ack		// Output acknowledge
);
  
  // Intermal signals
  wire		ai_out;
  wire		wi_out;
  wire		clk_out;
  reg		toggle;

  // INV gate
  assign	ai_out 	= ~in_req;
  
  // NAND3 gate
  assign	wi_out 	= ~(ai_out & out_ack & toggle);
  
  // OAI31 gate
  assign	clk_out	= ~((ai_out | out_ack | toggle) & wi_out);
  
  // Flip-Flop for toggle with reset
  always @(posedge clk_out or posedge reset) begin
	if (reset) begin
      toggle <= 0;
  	end else begin
      toggle <= ~toggle;
  	end
end
  

	// Flip-Flops for data transfer
	always @(posedge clk_out) begin
   	 if (!reset) begin
 		out_data[0] <= in_data[0];
   	    out_data[1] <= in_data[1];
   	 end
	end

	// Assigning toggle to in_ack and out_req
	always @(*) begin
    	in_ack = toggle;
    	out_req = toggle;
	end

endmodule
