// ==================================================
//	[ VLSISYS Lab. ]
//	* Author		: SoJeong Ok (oksj@sookmyung.ac.kr)
//	* Filename		: pos_vs_neg_resettable_dff_tb.v
//	* Date			: 2024-09-19 13:45:39
//	* Description	: 
// ==================================================

// --------------------------------------------------
//	Define Global Variables
// --------------------------------------------------
`define	CLKFREQ		100		// Clock Freq. (Unit: MHz)
`define	SIMCYCLE	`NVEC	// Sim. Cycles
`define NVEC		100		// # of Test Vector

// --------------------------------------------------
//	Includes
// --------------------------------------------------
`include	"pos_vs_neg_resettable_dff.v"

module pos_vs_neg_resettable_dff_tb;
// --------------------------------------------------
//	DUT Signals & Instantiate
// --------------------------------------------------
	wire			o_q_pos;
	wire			o_q_neg;
	reg				i_d;
	reg				i_clk;
	reg				i_rstn;
	reg				i_rst;

	dff_neg
	u_dff_neg(
		.o_q				(o_q_neg			),
		.i_d				(i_d				),
		.i_clk				(i_clk				),
		.i_rstn				(i_rstn				)
	);


	dff_pos
	u_dff_pos(
		.o_q				(o_q_pos			),
		.i_d				(i_d				),
		.i_clk				(i_clk				),
		.i_rst 				(i_rst 				)
	);

// --------------------------------------------------
//	Clock
// --------------------------------------------------
	always #(500/`CLKFREQ) i_clk = ~i_clk;
		
// --------------------------------------------------
//	Tasks
// --------------------------------------------------
	task	init;
		begin	
			i_d		= 0;
			i_clk	= 0;
			i_rst	= 1;
			i_rstn	= 0;
		end
	endtask

	task	resetNCycle;
		input	[9:0]	n;
		begin
			#(n*1000/`CLKFREQ);
			i_rst	= 1'b0;
			i_rstn	= 1'b1;
		end
	endtask
// --------------------------------------------------
//	Test Stimulus
// --------------------------------------------------
	integer		i, j;
	initial begin
		init();
		resetNCycle(4);

		for (i=0; i<`SIMCYCLE; i++) begin
			j		= $urandom_range(0,10);
			#((  (j*0.1)) * 1000/`CLKFREQ);
			i_d		= $urandom;
			i_rst	= $urandom;
			i_rstn	= ~i_rst;
			#((1-(j*0.1)) * 1000/`CLKFREQ);
		end
		#(1000/`CLKFREQ);
		$finish;
	end

// --------------------------------------------------
//	Dump VCD
// --------------------------------------------------
	reg	[8*48-1:0]	vcd_file;
	initial begin
		if ($value$plusargs("vcd_file=%s", vcd_file)) begin
			$dumpfile(vcd_file);
			$dumpvars;
		end else begin
			$dumpfile("pos_vs_neg_resettable_dff_tb.vcd");
			$dumpvars;
		end
	end

endmodule
