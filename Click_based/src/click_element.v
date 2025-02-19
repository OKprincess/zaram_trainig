// ===================================================
//	=================[ VLSISYS Lab. ]=================
//	* Author		: oksj (oksj@sookmyung.ac.kr)
//	* Filename		: click_element.v
//	* Description	: 
// ===================================================
module click_element #(
	parameter	DATA_WIDTH	= 32,
	parameter	VALUE		= 0,
	parameter	PHASE_INIT	= 1'b0
)(
	output	reg						in_ack,
	output	reg						out_req,
	output	reg	[DATA_WIDTH-1:0]	out_data,

	input							in_req, 
	input							out_ack,
	input		[DATA_WIDTH-1:0]	in_data,
	input							reset
);

	reg							phase;
	reg		[DATA_WIDTH-1:0]	data_sig;
	wire						click;

	// Control path
	assign	out_req		= phase;
	assign	in_ack		= phase;
	assign	out_data	= data_sig;

	// Click generation
	assign	click		= (~in_req&phase&out_ack) | (~out_ack&~phase&in_req);

	// State register process
	always @(posedge click or posedge reset) begin
		if(reset) begin
			phase		<= PHASE_INIT;
			data_sig	<= VALUE;
		end else begin
			phase		<= ~phase;
			data_sig	<= in_data;
		end
	end


endmodule



	


