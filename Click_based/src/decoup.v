// ===================================================
//	=================[ VLSISYS Lab. ]=================
//	* Author		: oksj (oksj@sookmyung.ac.kr)
//	* Filename		: decoup.v
//	* Description	: 
// ===================================================
module decoup #(
	parameter	DATA_WIDTH		= 32,
	parameter	VALUE			= 0,
	parameter	PHASE_INIT_IN	= 1'b0,
	parameter	PHASE_INIT_OUT	= 1'b0
)(
	input							reset,
	// Input channel
	output	reg						in_ack,
	input							in_req,
	input		[DATA_WIDTH-1:0]	in_data,
	// Output channel
	output	reg						out_req,
	output	reg	[DATA_WIDTH-1:0]	out_data,
	input							out_ack
);

	reg						phase_in, phase_out;
	reg	[DATA_WIDTH-1:0]	data_sig;
	wire					click;

	// Control Path
	always @(*) begin
		out_req		= phase_out;
		in_ack		= phase_in;
		out_data	= data_sig;
	end
	// Click generation
	assign	click		= (in_req ^ phase_in)&(out_ack ~^ phase_out);

	// State register
	always @(posedge click or posedge reset) begin
		if (reset) begin
			phase_in	<= PHASE_INIT_IN;
			phase_out	<= PHASE_INIT_OUT;
			data_sig	<= VALUE;
		end else begin
			phase_in	<= ~phase_in;
			phase_out	<= ~phase_out;
			data_sig	<= in_data;
		end
	end
endmodule
