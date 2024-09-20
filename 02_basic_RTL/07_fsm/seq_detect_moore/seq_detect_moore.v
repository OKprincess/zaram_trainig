// ==================================================
//	[ VLSISYS Lab. ]
//	* Author		: SoJeong Ok (oksj@sookmyung.ac.kr)
//	* Filename		: seq_detect_moore.v
//	* Date			: 2024-09-20 16:52:49
//	* Description	: 
// ==================================================

module seq_detect_moore
(	
	output reg					o_out,
	input						i_seq,
	input						i_clk,
	input						i_rstn
);

	reg			[2:0]			cState;
	reg			[2:0]			nState;
	reg							seq;

	// States
	localparam	S_IDLE	=		3'b000;
	localparam	S_H		=		3'b001;
	localparam	S_HL	=		3'b010;
	localparam	S_HLH	=		3'b011;
	localparam	S_HLHH	= 		3'b100;

	// State Register
	always @(posedge i_clk or negedge i_rstn) begin
		if(!i_rstn) begin
			cState	<= S_IDLE;
			seq		<= 1'b0;
		end else begin
			cState	<= nState;
			seq		<= i_seq;
		end
	end

	
	// 'Next State' Combinational Logic
	always @(*) begin
		if(seq == 1'b0) begin
			case(cState)
				S_IDLE	:	nState	= S_IDLE;
				S_H		:	nState	= S_HL;
				S_HL	: 	nState	= S_IDLE;
				S_HLH	:	nState	= S_HL;
				S_HLHH	:	nState 	= S_IDLE;
			endcase
		end else begin
			case(cState)
				S_IDLE	:	nState	= S_H;
				S_H		:	nState	= S_H;
				S_HL	:	nState	= S_HLH;
				S_HLH	: 	nState	= S_HLHH;
				S_HLHH	:	nState	= S_H;
			endcase
		end
	end

	// 'Output' Combinational Logic
	always @(*) begin
		case(cState)
			S_HLHH	:	o_out	= 1'b1;
			default	:	o_out	= 1'b0;
		endcase
	end

endmodule
