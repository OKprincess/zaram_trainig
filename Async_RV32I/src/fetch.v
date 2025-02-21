// ===================================================
//	=================[ VLSISYS Lab. ]=================
//	* Author		: oksj (oksj@sookmyung.ac.kr)
//	* Filename		: fetch.v
//	* Description	: 
// ===================================================
 module fetch 
 #(
	 parameter	REGISTER_INIT = 0
 )
 (
	 input					i_clk,
	 input					i_rstn,
	 input					i_en,			//bubble propagation(0: hold)
	 input					i_jump,
	 input			[31:0]	i_addr_result,
	 input			[31:0]	i_instr,
	 output	    	[31:0]	o_addr,		// instr address
	 output	reg		[31:0]	o_instr_reg,
	 output	reg		[31:0]	o_next_pc,
	 output	   		[3:0]	o_tag
 );

	reg		[31:0]		pc;
	reg		[3:0]		next_tag, curr_tag;

	// PC control
	always @(posedge i_clk	or negedge i_rstn) begin
		if(!i_rstn)
			pc	<= REGISTER_INIT;
		else if(i_jump)
			pc	<= i_addr_result;						// If branch taken: pc receive new value from retire unit
		else if(i_en==1)								// If no bubble issue: pc <= pc + 4
			pc	<= pc+4;
		else 
			pc	<= pc;
	end

	// sensitive output
	always @(posedge i_clk) begin
		if(i_en==1) begin
			o_instr_reg	<= i_instr;
			o_next_pc	<= pc;
		end
	end

	// TAG caculate
	always @(posedge i_clk or negedge i_rstn) begin
		if(!i_rstn)begin
			curr_tag <= 0;
			next_tag <= 0;
		end else if (i_jump)
			next_tag	<= curr_tag + 1;
		else if (i_en==1)
			curr_tag	<= next_tag;
	end

	// nonsensitive output
	assign	o_addr = pc;
	assign	o_tag  = curr_tag;
 
endmodule
