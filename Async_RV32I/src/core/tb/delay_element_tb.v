// ===================================================
//	=================[ VLSISYS Lab. ]=================
//	* Author		: oksj (oksj@sookmyung.ac.kr)
//	* Filename		: delay_element_tb.v
//	* Description	: 
// ===================================================
`include	"../delay_element.v"

module delay_element_tb; 

	parameter	SIZE = 10;

	reg 	i_d;
	wire	o_z;

	delay_element #(
		.SIZE	(SIZE	)
	) u_delay_element(
		.i_d	(i_d	),
		.o_z	(o_z	)
	);

	initial begin
		// reset
		i_d	= 0;
		#10 i_d	= 1;
		#10	i_d	= 0;
		#20	i_d = 1;
		#20	i_d = 0;

		#50 $finish;
	end

	reg	[8*32-1:0]	vcd_file;
	initial begin
		if ($value$plusargs("vcd_file=%s", vcd_file)) begin
			$dumpfile(vcd_file);
			$dumpvars;
		end else begin
			$dumpfile("delay_element_tb.vcd");
			$dumpvars;
		end
	end
	
endmodule
