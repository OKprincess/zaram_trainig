// ===================================================
//	=================[ VLSISYS Lab. ]=================
//	* Author		: oksj (oksj@sookmyung.ac.kr)
//	* Filename		: click_buf_tb.v
//	* Date			: 2025-01-23 
//	* Description	: 
// ===================================================

`define	CLKFREQ		100		// Clock Freq. (Unit: MHz)
`define	SIMCYCLE	`NVEC	// Sim. Cycles
`define NVEC		10		// # of Test Vector

`include			"click_buf.v"

module click_buf_tb;

// Testbench signals
	reg 		reset;
	reg [1:0] 	in_data;
	reg 		in_req;
	wire 		in_ack;
	wire [1:0] 	out_data;
	wire 		out_req;
	reg 		out_ack;
	
	// Clock signal for testing
	reg clk;
	
	// Instantiate the DUT (Device Under Test)
	click_buf  
	u_click_buf(
	    .reset		(reset),
	    .in_data	(in_data),
	    .in_req		(in_req),
	    .in_ack		(in_ack),
	    .out_data	(out_data),
	    .out_req	(out_req),
	    .out_ack	(out_ack)
	);
	
	// Clock generation
	initial begin
	    clk = 0;
	    forever #5 clk = ~clk;  // 100 MHz clock (10 ns period)
	end
	
	// Test sequence
	initial begin
	    // Initialize signals
	    reset = 1;
	    in_data = 2'b00;
	    in_req = 0;
	    out_ack = 0;
	
	    // Reset pulse
	    #10;
	    reset = 0;
	
	    // Test Case 1: Basic data transfer
	    #10;
	    in_data = 2'b10;
	    in_req = 1;
	    #10;
	    in_req = 0;  // Deactivate request
	    #10;
	
	    // Simulate out_ack response
	    out_ack = 1;
	    #10;
	    out_ack = 0;
	
	    // Test Case 2: Another data transfer
	    #20;
	    in_data = 2'b01;
	    in_req = 1;
	    #10;
	    in_req = 0;
	    #10;
	
	    // Simulate out_ack response
	    out_ack = 1;
	    #10;
	    out_ack = 0;
	
	    // Finish simulation
	    #50;
	    $finish;
	end
	
	// Monitor signals
	initial begin
	    $monitor("Time: %0dns, reset: %b, in_data: %b, in_req: %b, in_ack: %b, out_data: %b, out_req: %b, out_ack: %b", 
	             $time, reset, in_data, in_req, in_ack, out_data, out_req, out_ack);
	end

endmodule
