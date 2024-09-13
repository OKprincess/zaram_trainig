// ==================================================
//	[ VLSISYS Lab. ]
//	* Author		: SoJeong Ok (oksj@sookmyung.ac.kr)
//	* Filename		: adder_4bit_tb.v
//	* Description	: 
// ==================================================
// --------------------------------------------------
//	Define Global Variables
// --------------------------------------------------
`define	CLKFREQ		100		// Clock Freq. (Unit: MHz)
`define	SIMCYCLE	10	// Sim. Cycles

// --------------------------------------------------
//	Includes
// --------------------------------------------------
`include	"adder_4bit.v"

module adder_4bit_tb;
// --------------------------------------------------
//	DUT Signals & Instantiate
// --------------------------------------------------

	wire		[3:0]	o_s;
	wire				o_c;
	reg			[3:0]	i_a;
	reg			[3:0]	i_b;
	reg					i_c;

	adder_4bit 
	u_adder_4bit(
		.o_s		(o_s	), 
		.o_c		(o_c	),
		.i_a		(i_a	),
		.i_b		(i_b	),
	    .i_c		(i_c	) 
);


// --------------------------------------------------
//	Task
// --------------------------------------------------
	task init;
		begin
			i_a		= 0;
			i_b		= 0;
			i_c		= 0;
		end
	endtask
// --------------------------------------------------
//	Test Stimulus
// --------------------------------------------------
	integer		i, j, k ,n;
	initial begin
		for (i=0; i<`SIMCYCLE; i++) begin
			{i_a, i_b, i_c} = $urandom_range(0, 2**9-1);
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
			$dumpfile("adder_4bit_tb.vcd");
			$dumpvars;
		end
	end

endmodule
