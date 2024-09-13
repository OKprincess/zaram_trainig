// ==================================================
//	[ VLSISYS Lab. ]
//	* Author		: SoJeong Ok (oksj@sookmyung.ac.kr)
//	* Filename		: blockings_tb.v
//	* Description	: 
// ==================================================

// --------------------------------------------------
//	Define Global Variables
// --------------------------------------------------
`define	CLKFREQ		100		// Clock Freq. (Unit: MHz)
`define	SIMCYCLE	10		// Sim. Cycles

// --------------------------------------------------
//	Includes
// --------------------------------------------------
`include	"blockings.v"

module blockings_tb;
// --------------------------------------------------
//	DUT Signals & Instantiate
// --------------------------------------------------
	wire		o_q_block;
	wire		o_q_nonblock;
	reg			i_d;
	reg			i_clk;

	block
	u_block(
		.o_q	(o_q_block		),
		.i_d	(i_d			),
		.i_clk	(i_clk			)
	);

	nonblock
	u_nonblock(
		.o_q	(o_q_nonblock	),
		.i_d	(i_d			),
		.i_clk	(i_clk			)
	);


// --------------------------------------------------
//	Clock
// --------------------------------------------------
	always #(500/`CLKFREQ) i_clk = ~i_clk;


// --------------------------------------------------
//	Task
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
			j 	= $urandom_range(0,10);
			#((	(j*0.1))  * 1000/`CLKFREQ);
			i_d	= $urandom;
			#((1-(j*0.1)) * 1000/`CLKFREQ);
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
			$dumpfile("blockings_tb.vcd");
			$dumpvars;
		end
	end

endmodule
