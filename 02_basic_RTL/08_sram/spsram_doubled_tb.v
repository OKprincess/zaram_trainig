// ==================================================
//	[ VLSISYS Lab. ]
//	* Author		: SoJeong Ok (oksj@sookmyung.ac.kr)
//	* Filename		: spsram_doubled_tb.v
//	* Date			: 2024-09-23 12:40:14
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
`include	"spsram_doubled.v"

module spsram_doubled_tb;
// --------------------------------------------------
//	DUT Signals & Instantiate
// --------------------------------------------------
	wire 		[31:0]			o_data;
	reg			[31:0]			i_data;		// input data canbe write or read
	reg			[4:0]			i_addr;		// memory address
	reg							i_cen;		// chip enable 
	reg							i_wen;		// write enable
	reg							i_oen;		//wire enable
	reg							i_clk;
	
	spsram_doubled
	u_spsram_doubled(
	.o_data				(o_data				),
	.i_data				(i_data				),
	.i_addr				(i_addr				),
	.i_cen				(i_cen				),
	.i_wen				(i_wen				),
	.i_oen				(i_oen				),
	.i_clk				(i_clk				)
	);
	
	
// --------------------------------------------------
//	Clock	
// --------------------------------------------------
	always	#(500/`CLKFREQ)	i_clk	= ~i_clk;

// --------------------------------------------------
// 	Tasks	
// --------------------------------------------------
	reg				[8*32-1:0]		taskState;
	task init;
		begin
					i_data	= 0;
					i_addr	= 0;
					i_cen	= 0;
					i_wen	= 0;
					i_oen	= 0;
					i_clk	= 0;
		end
	endtask

	task memWR;
		input		[31:0]	ti_data;
		input		[4:0]	ti_addr;
		begin
				@ (negedge i_clk) begin
					taskState	=	"WR";
					i_data	= ti_data;
					i_addr	= ti_addr;
					i_cen	= 1;
					i_wen	= 1;
					i_oen	= 0;
				end
		end
	endtask


	task memRD;
		input		[31:0]	ti_addr;
		begin
				@ (negedge i_clk) begin
					taskState	=	"RD";
					i_addr	= ti_addr;
					i_cen	= 1;
					i_wen	= 0;
					i_oen	= 1;
				end
		end
	endtask

// --------------------------------------------------
//	Test Stimulus
// --------------------------------------------------
	integer		i, j;
	initial begin
		init();
		#(4*1000/`CLKFREQ);
		for (i=0; i<2**5; i++) begin
			memWR(i, i);
		end
		
		for (i=0; i<2**5; i++) begin
			memRD(i);
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
			$dumpfile("spsram_tb.vcd");
			$dumpvars;
		end
	end

endmodule
