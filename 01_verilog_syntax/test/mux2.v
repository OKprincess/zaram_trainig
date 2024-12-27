// two-in mux2

module	mux2
(
	output	o_out,
	input	i_sel,
	input	i_in0,
	input 	i_in1
);

	assign	o_out	= i_sel ? i_in1 : i_in0;

endmodule
