// ==================================================
//	[ VLSISYS Lab. ]
//	* Author		: SoJeong Ok (oksj@sookmyung.ac.kr)
//	* Filename		: dff_async_rstn_tb.v
//	* Date			: 2024-09-19 15:26:56
//	* Description	: 
// ==================================================
// --------------------------------------------------
//	Define Global Variables
// --------------------------------------------------
`define	CLKFREQ		100		// Clock Freq. (Unit: MHz)
`define	SIMCYCLE	10		// Sim. Cycles
`define BW_DATA		32

// --------------------------------------------------
//	Includes
// --------------------------------------------------
`include	"dff_async_rstn.v"

module	dff_async_rstn_tb;
// --------------------------------------------------
//	DUT Signals & Instantiate
// --------------------------------------------------

	wire	[`BW_DATA-1:0]	o_q;
	reg		[`BW_DATA-1:0]	i_d;
	reg						i_clk;
	reg						i_rstn;

	dff_async_rstn
	#(
		.BW_DATA		(`BW_DATA		)
	)
	u_dff_async_rstn(
		.o_q			(o_q			),
		.i_d			(i_d			),
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
			i_d				= 0;
			i_clk			= 0;
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

	task singleCycle;
		begin
			#(1000/`CLKFREQ);
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
			#(1000/`CLKFREQ);
			{i_d} = $random;
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
			$dumpfile("dff_async_rstn_tb.vcd");
			$dumpvars;
		end
	end

	endmodule
