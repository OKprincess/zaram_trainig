// ==================================================
//	[ VLSISYS Lab. ]
//	* Author		: SoJeong Ok (oksj@sookmyung.ac.kr)
//	* Filename		: gray_code_converter_tb.v
//	* Date			: 2024-09-23 17:59:11
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
`include	"gray_code_converter.v"

module gray_code_converter_tb;
// --------------------------------------------------
//	DUT Signals & Instantiate
// --------------------------------------------------
	parameter		BW_DATA		= 8;

	wire			[BW_DATA-1:0]	out_gray;
	wire			[BW_DATA-1:0]	out_bin;
	reg				[BW_DATA-1:0]	i_data;

	// First, input i_data to "bin_to_gray" module. 
	// Next, out_gray go in "gray_to_bin" module.
	// Binary(i_data) -> Gray(out_gray) -> Binary(out_bin)
	
	bin_to_gray
	#(
		.BW_DATA			(BW_DATA			)
	)
	u_bin_to_gray(
		.out_gray			(out_gray			),
		.in_bin				(i_data				)
	);

	gray_to_bin	
	#(
		.BW_DATA			(BW_DATA			)
	)
	u_gray_to_bin(
		.out_bin			(out_bin			),
		.in_gray			(out_gray			)
	);

// --------------------------------------------------
//	Tasks
// --------------------------------------------------
	task	init;
		begin
			i_data	= 0;
		end
	endtask
// --------------------------------------------------
//	Test Stimulus
// --------------------------------------------------
	integer		i, j;
	initial begin
		init();
		for (i=0; i<`SIMCYCLE; i++) begin
			i_data	= i;
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
			$dumpfile("gray_code_converter_tb.vcd");
			$dumpvars;
		end
	end

endmodule
