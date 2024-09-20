// ==================================================
//	[ VLSISYS Lab. ]
//	* Author		: SoJeong Ok (oksj@sookmyung.ac.kr)
//	* Filename		: seq_detect_moore_tb.v
//	* Date			: 2024-09-20 17:17:31
//	* Description	: 
// ==================================================
 // --------------------------------------------------
//	Define Global Variables
// --------------------------------------------------
`define	CLKFREQ		100		// Clock Freq. (Unit: MHz)
`define	SIMCYCLE	100		// Sim. Cycles

// --------------------------------------------------
//	Includes
// --------------------------------------------------
`include	"seq_detect_moore.v"

module seq_detect_moore_tb;
// --------------------------------------------------
//	DUT Signals & Instantiate
// --------------------------------------------------
	wire					o_out;
	reg						i_seq;
	reg						i_clk;
	reg						i_rstn;

	seq_detect_moore
	u_seq_detect_moore(
		.o_out			(o_out			),
		.i_seq			(i_seq			),
		.i_clk			(i_clk			),
		.i_rstn			(i_rstn			)
	);

// --------------------------------------------------
//	Clock
// --------------------------------------------------
//	reg							i_clk = 0;
	always	#(500/`CLKFREQ)		i_clk = ~i_clk;

// --------------------------------------------------
//	Tasks
// --------------------------------------------------
	reg		[4*32-1:0] taskState;	// Length is limitted to 32

	task init;
		begin
			i_seq			= 0;
			i_clk			= 1;
			i_rstn			= 0;
		end
	endtask

	task resetReleaseAfterNCycles;
		input	[  9:0]		n;
		begin
			taskState	= "Reset";
			i_rstn = 1'b0;
			#(n*1000/`CLKFREQ);
			i_rstn = 1'b1;
		end
	endtask

// --------------------------------------------------
//	Test Stimulus
// --------------------------------------------------
	integer		i, j;
	initial begin
		init();
		resetReleaseAfterNCycles(4);

		for (i=0; i<`SIMCYCLE; i++) begin
			i_seq	= $random;
			#(1000/`CLKFREQ);
		end
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
			$dumpfile("seq_detect_moore_tb.vcd");
			$dumpvars;
		end
	end

endmodule
