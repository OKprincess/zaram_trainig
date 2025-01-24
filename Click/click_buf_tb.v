// ===================================================
//	=================[ VLSISYS Lab. ]=================
//	* Author		: oksj (oksj@sookmyung.ac.kr)
//	* Filename		: click_buf_tb.v
//	* Date			: 2025-01-23 
//	* Description	: 
// ===================================================

`define	CLKFREQ		100		// Clock Freq. (Unit: MHz)
`define	SIMCYCLE	`NVEC	// Sim. Cycles
`define NVEC		100		// # of Test Vector

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

	wire		o_fire;
	
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
	    .out_ack	(out_ack),
		.o_fire		(o_fire)
	);
	
	// Clock generation
	initial begin
	    clk = 0;
	    forever #5 clk = ~clk;  // 100 MHz clock (10 ns period)
	end


	reg		[8*32-1:0]	taskState;
	task init;
		begin
			taskState		= "Init";
			clk				= 0;
			reset			= 0;
			in_data			= 2'b00;
			in_req			= 0;
			out_ack			= 0;
		end 
	endtask


	integer		i, j;
	// Test sequence
	initial begin
	    // Initialize signals
		init();	
	    // Reset pulse
	    #10;
	    reset = 1;
	
	    // Test Case 1: Basic data transfer
	    #10;
		taskState	= "Ready";
		reset		= 0;
		#10
	    in_data = 2'b10;
	    in_req = 1;
	    #10;
	    in_req = 0;  // Deactivate request
	    #10;
	
	    /* Simulate out_ack response
	    out_ack = 1;
	    #10;
	    out_ack = 0;
		*/

	    // Test Case 2: Another data transfer
	    #20;
		taskState	= "Case1";
	    in_data		= 2'b11;
		in_req		= 1;
		#10;
		if (o_fire == 1) begin
			out_ack = 1;
			in_req  = 0;
		end else begin
			out_ack = 0;
		end
		#10
	    // Simulate out_ack response
	
	    // Finish simulation
	    #50;
	    $finish;
	end
	
	// Monitor signals
	initial begin
	    $monitor("Time: %0dns, reset: %b, in_data: %b, in_req: %b, in_ack: %b, out_data: %b, out_req: %b, out_ack: %b", 
	             $time, reset, in_data, in_req, in_ack, out_data, out_req, out_ack);
	end



// --------------------------------------------------
//	Dump VCD
// --------------------------------------------------
	reg	[8*32-1:0]	vcd_file;
	initial begin
		if ($value$plusargs("vcd_file=%s", vcd_file)) begin
			$dumpfile(vcd_file);
			$dumpvars;
		end else begin
			$dumpfile("click_buf_tb.vcd");
			$dumpvars;
		end
	end





endmodule
