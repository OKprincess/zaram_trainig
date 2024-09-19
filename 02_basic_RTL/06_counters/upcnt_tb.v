// ==================================================
//	[ VLSISYS Lab. ]
//	* Author		: SoJeong Ok (oksj@sookmyung.ac.kr)
//	* Filename		: upcnt_tb.v
//	* Date			: 2024-09-19 14:20:42
//	* Description	: 
// ==================================================

// --------------------------------------------------
//	Define Global Variables
// --------------------------------------------------
`define	CLKFREQ		100		// Clock Freq. (Unit: MHz)
`define	SIMCYCLE	`NVEC	// Sim. Cycles
`define	BW_DATA		32
`define NVEC		100		// # of Test Vector
`define	UPBND		15

// --------------------------------------------------
//	Includes
// --------------------------------------------------
`include	"upcnt.v"

module upcnt_tb;
// --------------------------------------------------
//	DUT Signals & Instantiate
// --------------------------------------------------
	wire		[$clog2(`UPBND+1)-1:0]	o_cnt;
	reg									i_clk;
	reg									i_rstn;

	upcnt
	#(
		.UPBND				(`UPBND				)
	)
	u_upcnt(
		.o_cnt				(o_cnt				),
		.i_clk				(i_clk				),
		.i_rstn				(i_rstn				)
	);


// --------------------------------------------------
//	Clock	
// --------------------------------------------------
	always	#(500/`CLKFREQ)	i_clk = ~i_clk;

// --------------------------------------------------
//	Tasks
// --------------------------------------------------
	reg		[4*32-1:0]		taskState;
	integer					err = 0;

	task	init;
		begin	
			taskState		= "Init";
			i_clk			= 0;
			i_rstn			= 0;
		end
	endtask

	task	resetNCycle;
		input	[9:0]	i;
		begin
			taskState		= "Reset";
			i_rstn			= 1'b0;
			#(i*1000/`CLKFREQ);
			i_rstn			= 1'b1;
			taskState		= "";
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
			$dumpfile("upcnt_tb.vcd");
			$dumpvars;
		end
	end

endmodule
