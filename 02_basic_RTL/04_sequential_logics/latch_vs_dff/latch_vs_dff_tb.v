// ==================================================
//	[ VLSISYS Lab. ]
//	* Author		: SoJeong Ok (oksj@sookmyung.ac.kr)
//	* Filename		: latch_vs_dff_tb.v
//	* Date			: 2024-09-13 19:18:23
//	* Description	: 
// ==================================================

// --------------------------------------------------
//	Define Global Variables
// --------------------------------------------------
`define	CLKFREQ		100		// Clock Freq. (Unit: MHz)
`define	SIMCYCLE	50		// Sim. Cycles

// --------------------------------------------------
//	Includes
// --------------------------------------------------
`include	"latch_vs_dff.v"

module latch_vs_dff_tb;
// --------------------------------------------------
//	DUT Signals & Instantiate
// --------------------------------------------------
	wire			o_q_lat;
	wire			o_q_dff;
	reg				i_d;
	reg				i_clk;

	latch
	u_latch(
		.o_q				(o_q_lat 			),
		.i_d				(i_d				),
		.i_clk				(i_clk				)
	);


	dff
	u_dff(
		.o_q				(o_q_dff			),
		.i_d				(i_d				),
		.i_clk				(i_clk				)
	);


// --------------------------------------------------
//	Clock
// --------------------------------------------------
	always #(500/`CLKFREQ) i_clk = ~i_clk;
// --------------------------------------------------
//	Tasks
// --------------------------------------------------
	task init;
		begin
			i_d		= 0;
			i_clk	= 0;
		end
	endtask
// --------------------------------------------------
//	Test Stimulus
// --------------------------------------------------
	integer		i, j;
	initial begin
		init();
		for (i=0; i<`SIMCYCLE; i++) begin
			j	= $urandom_range(0,10);
			#((   (j*0.1)) * 1000/`CLKFREQ);
			i_d = $urandom;
			#((1- (j*0.1)) * 1000/`CLKFREQ);
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
			$dumpfile("latch_vs_dff_tb.vcd");
			$dumpvars;
		end
	end

endmodule
