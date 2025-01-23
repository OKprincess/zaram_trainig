// ===================================================
//	=================[ VLSISYS Lab. ]=================
//	* Author		: oksj (oksj@sookmyung.ac.kr)
//	* Filename		: click_element_tb.v
//	* Date			: 2025-01-22 
//	* Description	: 
// ===================================================

// --------------------------------------------------
//	Define Global Variables
// --------------------------------------------------
`define	CLKFREQ		100		// Clock Freq. (Unit: MHz)
`define	SIMCYCLE	`NVEC	// Sim. Cycles
`define NVEC		100		// # of Test Vector

// --------------------------------------------------
//	Includes
// --------------------------------------------------
`include	"click_element.v"

module click_element_tb;
// --------------------------------------------------
//	DUT Signals & Instantiate
// --------------------------------------------------
	wire		o_fire;
	wire		o_req;
	reg			i_req;
	reg			i_out_ack;

	click_element
	u_click_element(
		.o_fire		(o_fire		),
		.o_req		(o_req		),
		.i_req		(i_req		),
		.i_out_ack	(i_out_ack	)
	);

// --------------------------------------------------
//	Clock	
// --------------------------------------------------

// --------------------------------------------------
//	Tasks	
// --------------------------------------------------
	task	init;
		begin	
			i_req		= 0;
			i_out_ack	= 0;
		end
	endtask

	task	ready;
		begin
			i_req		= !i_req;
		end
	endtask

	task	capture;
		begin
			i_out_ack	= !i_out_ack;
		end
	endtask
// --------------------------------------------------
//	Test Stimulus
// --------------------------------------------------
	integer		i, j;
	initial begin
		init();
		for (i=0; i<`SIMCYCLE; i++) begin
			ready();	
			#(1000/`CLKFREQ);
			capture();
			#(1000/`CLKFREQ);
		end
		#(1000/`CLKFREQ);
		$finish;
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
			$dumpfile("click_element_tb.vcd");
			$dumpvars;
		end
	end

endmodule
