// ===================================================
//	=================[ VLSISYS Lab. ]=================
//	* Author		: oksj (oksj@sookmyung.ac.kr)
//	* Filename		: delay_element.v
//	* Description	: 
// ===================================================
module delay_element #(
	parameter	SIZE = 10
)(
	input	i_d,
	output	o_z
);

	reg	[SIZE:0]	s_connect;

	always @(*) begin
		s_connect[0] = i_d;
	end

	// LUT chain
	genvar i;
	generate
		for(i=0; i<SIZE; i=i+1)begin : lut_chain
			always @(*) begin
				s_connect[i+1] = ~s_connect[i];
			end
		end
	endgenerate

	assign o_z = s_connect[SIZE];
	
endmodule
