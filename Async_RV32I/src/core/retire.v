// ===================================================
//	=================[ VLSISYS Lab. ]=================
//	* Author		: oksj (oksj@sookmyung.ac.kr)
//	* Filename		: retire.v
//	* Description	: 
// ===================================================
`include		"pkg.v"

module retire 
(
	input					i_clk,
	input					i_rstn,
	input			[31:0]	i_result[1:0],
	input					i_jump,
	input					i_wr_en,
	input			[3:0]	i_tag,
	input					i_write,
	input			[1:0]	i_size,
	output	reg				o_reg_wr_en,
	output	   		[31:0]	o_wr_data,
	output	reg				o_jump,
	output	reg		[31:0]	o_new_pc,
	output	reg		[31:0]	o_wr_addr,
	output	reg		[31:0]	o_data,
	output	reg				o_write,
	output	reg		[1:0]	o_size
);

	reg	[31:0]		data;
	reg	[3:0]		next_tag;
	reg	[3:0]		curr_tag;
	reg				killed;

	// assign to register bank write back
	assign		o_wr_data = i_result[0];

	// killed signal generation
	always @(*) begin
		if(curr_tag!=i_tag)
			killed	<= 1;
		else
			killed	<= 0;
	end

	// TAG control based on Jump&killed signal
	always @(posedge i_clk or negedge i_rstn) begin
		if(i_rstn)
			curr_tag	<= 0;
		else if ((o_jump==1)&&(killed==0))
			curr_tag	<= curr_tag + 1;
	end

	// Flow control
	always @(*) begin
		if(killed)
			o_reg_wr_en	<= 0;
		else 
			o_reg_wr_en	<= i_wr_en;
	end


	// PC flow control
	always @(*) begin
		if((i_jump==1)&&(killed==0)) begin
			o_new_pc	<= i_result[1];
			o_jump		<= 1;
		end else begin
			o_new_pc	<= 'Z;
			o_jump		<= 'Z;
		end
	end

	// mem wr control
	always @(posedge i_clk) begin
		if((i_write==1)&&(killed==0)) begin
			o_write	<= i_write;
			o_size	<= i_size;
			o_wr_addr	<= i_result[1];
			o_data		<= i_result[0];
		end else begin
			o_write		<= 'Z;
			o_size		<= 'Z;
			o_wr_addr	<= 'Z;
			o_data		<= 'Z;
		end
	end

	
endmodule
