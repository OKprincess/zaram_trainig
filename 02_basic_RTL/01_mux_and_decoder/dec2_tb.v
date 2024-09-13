// ==================================================
//	[ VLSISYS Lab. ]
//	* Author		: SoJeong Ok (oksj@sookmyung.ac.kr)
//	* Filename		: dec2_tb.v
//	* Description	: 
// ==================================================
	
// --------------------------------------------------
//	Define Global Variables
// --------------------------------------------------
`define	CLKFREQ		100		// Clock Freq. (Unit: MHz)
`define	SIMCYCLE	20	// Sim. Cycles
// --------------------------------------------------
//	Includes
// --------------------------------------------------
`include	"dec2.v"

module dec2_tb;
// --------------------------------------------------
//	DUT Signals & Instantiate
// --------------------------------------------------
	wire		[3:0]	o_out_dataflow;
	wire		[3:0]	o_out_behavior;
	reg			[1:0]	i_in;
	reg					i_en;

	dec2_dataflow
	u_dec2_dataflow(
		.o_out  		(o_out_dataflow	),
		.i_in   		(i_in			),
		.i_en   		(i_en			)
	);

	dec2_behavior
	u_dec2_behavior(
		.o_out			(o_out_behavior	),
		.i_in			(i_in			),
		.i_en			(i_en			)
	);


// --------------------------------------------------
//	Task
// --------------------------------------------------
	task init;
		begin
			i_in	= 0;
			i_en	= 0;
		end
	endtask
// --------------------------------------------------
//	Test Stimulus
// --------------------------------------------------
	integer		i;
	initial begin
		init();
		for (i=0; i<`SIMCYCLE; i++) begin
			{i_in, i_en} = $urandom_range(0, 2**3-1);
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
			$dumpfile("dec2_tb.vcd");
			$dumpvars;
		end
	end

endmodule
