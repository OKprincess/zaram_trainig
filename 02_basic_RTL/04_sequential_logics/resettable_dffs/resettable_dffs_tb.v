// ==================================================
//	[ VLSISYS Lab. ]
//	* Author		: SoJeong Ok (oksj@sookmyung.ac.kr)
//	* Filename		: resettable_dffs_tb.v
//	* Date			: 2024-09-13 19:38:22
//	* Description	: 
// ==================================================
// --------------------------------------------------
//	Define Global Variables
// --------------------------------------------------
`define	CLKFREQ		100		// Clock Freq. (Unit: MHz)
`define	SIMCYCLE	40		// Sim. Cycles

// --------------------------------------------------
//	Includes
// --------------------------------------------------
`include	"resettable_dffs.v"

module resettable_dffs_tb;
// --------------------------------------------------
//	DUT Signals & Instantiate
// --------------------------------------------------
	wire			o_q_sync;
	wire			o_q_async;
	reg				i_d;
	reg				i_clk;
	reg				i_rstn;

	dff_sync
	u_dff_sync(
		.o_q				(o_q_sync			),
		.i_d				(i_d				),
		.i_clk				(i_clk				),
		.i_rstn				(i_rstn				)
	);


	dff_async
	u_dff_async(
		.o_q				(o_q_async			),
		.i_d				(i_d				),
		.i_clk				(i_clk				),
		.i_rstn				(i_rstn				)
	);


// --------------------------------------------------
//		Clock	
// --------------------------------------------------
	always	#(500/`CLKFREQ) i_clk = ~i_clk;

// --------------------------------------------------
//	Tasks 
// --------------------------------------------------
	task init;
		begin
			i_d		= 0;
			i_clk	= 0;
			i_rstn  = 0;
		end
	endtask

	task resetReleaseAfterNCycles;
		input	[9:0]	n;
		begin
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
		resetNCycle(4);

		for (i=0; i<`SIMCYCLE; i++) begin
			vecInsert(i);
			vecVerify(i);
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
			$dumpfile("resettable_dffs_tb.vcd");
			$dumpvars;
		end
	end

endmodule
