// ==================================================
//	[ VLSISYS Lab. ]
//	* Author		: SoJeong Ok (oksj@sookmyung.ac.kr)
//	* Filename		: adder_tb.v
//	* Description	: 
// ==================================================

// --------------------------------------------------
//	Define Global Variables
// --------------------------------------------------
`define	CLKFREQ		100		// Clock Freq. (Unit: MHz)
`define NVEC		100
`define	SIMCYCLE	`NVEC	// Sim. Cycles
`define BW_DATA		8		// Bitwidth of ~~

// --------------------------------------------------
//	Includes
// --------------------------------------------------
`include	"adder.v"

module adder_tb;
// --------------------------------------------------
//	DUT Signals & Instantiate
// --------------------------------------------------
	parameter	BW_DATA = 8;

	wire		[BW_DATA-1:0]	o_s_param;
	wire		[BW_DATA-1:0]	o_s_def;
	wire						o_c_param;
	wire						o_c_def;
	reg			[BW_DATA-1:0]	i_a;
	reg			[BW_DATA-1:0]	i_b;
	reg							i_c;


	adder_param
	#(	
		.BW_DATA			(BW_DATA		)	
	)
	u_adder_param(
		.o_s				(o_s_param		), 
	   	.o_c				(o_c_param		),
		.i_a				(i_a			),
		.i_b				(i_b			),
	   	.i_c				(i_c			)
   );
	
	adder_def 
	u_adder_def(
		.o_s				(o_s_def		), 
	   	.o_c				(o_c_def		),
		.i_a				(i_a			),
		.i_b				(i_b			),
	   	.i_c				(i_c			)
	);

// --------------------------------------------------
//	Test Stimulus
// --------------------------------------------------
	integer		i, j;
	initial begin
		for (i=0; i<`SIMCYCLE; i++) begin
			i_a = $random;
			i_b = $random;
			i_c = $random;
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
			$dumpfile("adder_tb.vcd");
			$dumpvars;
		end
	end

endmodule
