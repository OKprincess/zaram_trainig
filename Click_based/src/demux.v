// ===================================================
//	=================[ VLSISYS Lab. ]=================
//	* Author		: oksj (oksj@sookmyung.ac.kr)
//	* Filename		: demux.v
//	* Description	: 
// ===================================================
module demux #(
	parameter	PHASE_INIT_A	= 1'b0,	
	parameter	PHASE_INIT_B	= 1'b0,
	parameter	PHASE_INIT_C	= 1'b0,
	parameter	DATA_WIDTH		= 32
)(
	input							reset,
	// Input port
	input							inA_req,
	input	[DATA_WIDTH-1:0]		inA_data,
	output	reg						inA_ack,
	// Select port	
	input							inSel_req,
	output	reg						inSel_ack,
	input							selector,

	output	reg						outB_req,
	output	reg	[DATA_WIDTH-1:0]	outB_data,
	input							outB_ack,

	output	reg						outC_req,
	output	reg	[DATA_WIDTH-1:0]	outC_data,
	input							outC_ack
	);
	
	reg	phase_a;
	reg	click_req, click_ack;
	reg	phase_b;
	reg	phase_c;

	// Control
	always @(*) begin
		inSel_ack	= phase_a;
		inA_ack		= phase_a;
		outB_req	= phase_b;
		outB_data	= inA_data;
		outC_req	= phase_c;
		outC_data	= inA_data;
	end

	// Request FF click
	always @(*) begin
		click_req	= (inSel_req&~phase_a&inA_req)|(~inSel_req&phase_a&~inA_req);
	end

	// Acknowledge FF Click
	always @(*) begin
		click_ack	= ((outB_ack~^phase_b)&(outC_ack~^phase_c));
	end

	//Request process
	always @(posedge click_req or posedge reset) begin
		if (reset) begin
			phase_b	<= PHASE_INIT_B;
			phase_c	<= PHASE_INIT_C;
		end else begin
			phase_b	<= phase_b ^ selector;
			phase_c	<= phase_c ^ ~selector;
		end
	end

	// Acknowledge process
	always @(posedge click_ack or posedge reset) begin
		if (reset) begin
			phase_a	<= PHASE_INIT_A;
		end else begin
			phase_a	<= ~phase_a;
		end
	end

endmodule
