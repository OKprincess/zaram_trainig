// ===================================================
//	=================[ VLSISYS Lab. ]=================
//	* Author		: oksj (oksj@sookmyung.ac.kr)
//	* Filename		: memory.v
//	* Description	: 
// ===================================================
`include			"pkg.v"

module memoryUnit 
(
	input				i_clk,
	input		[31:0]	i_opA,
	input		[31:0]	i_opB,
	input		[31:0]	i_wr_data,
	input		[2:0]	i_instr_type,
	
	output	reg	[31:0]	o_read_addr,
	output	reg			o_read,
	input		[31:0]	i_read_data,
	output	reg	[31:0]	o_wr_addr,
	output	reg	[31:0]	o_wb_data,
	output	reg			o_write,
	output	reg	[1:0]	o_size,
	output	reg			o_wr_en
);

	reg	wr_int, wr_en_int;
	reg	[31:0]	wr_data, wr_addr2;
	reg	[1:0]	size_int;

	// generate all signals for read or write 
	always @(*) begin
		if((i_instr_type==`OP0)||(i_instr_type==`OP1))begin
			wr_int		<= 0;
			o_read		<= 1;
			wr_data		<= 0;
			size_int	<= 2'b00;

		end else if((i_instr_type==`OP2)||(i_instr_type==`OP3))begin
			wr_int		<= 0;
			o_read		<= 1;
			wr_data		<= 0;
			size_int	<= 2'b00;
		
		end else if(i_instr_type==`OP4) begin
			wr_int		<= 0;
			o_read		<= 1;
			wr_data		<= 0;
			size_int	<= 2'b00;

		end else if(i_instr_type==`OP7)begin
			wr_int		<= 1;
			o_read		<= 0;
			wr_data[31:8]	<= 24'h000000;
			wr_data[7:0]	<= i_wr_data[7:0];
			size_int		<= 2'b01;

		end else if(i_instr_type==`OP6)begin
			wr_int		<= 1;
			o_read		<= 0;
			wr_data[31:16]	<=	16'h0000;
			wr_data[15:0]	<= i_wr_data[15:0];
			size_int		<= 2'b01;

		end else if(i_instr_type==`OP5)begin
			wr_int		<= 1;
			o_read		<= 0;
			wr_data[31:0]	<= i_wr_data[31:0];
			size_int		<= 2'b11;
		end

		if((i_instr_type==`OP0)||(i_instr_type==`OP1)||(i_instr_type==`OP2)||(i_instr_type==`OP3)||(i_instr_type==`OP4))
			o_read_addr	= i_opA+i_opB;
		else 
			o_read_addr	= 0;

	end



	// Data write back parse
	always @(posedge i_clk) begin
		if((i_instr_type==`OP0)||(i_instr_type==`OP1)) begin
			if((i_read_data[7]==1)&&(i_instr_type==`OP0))
				o_wb_data[31:8]	<= 24'hffffff;
			else 
				o_wb_data[31:8]	<= 24'h000000;
			o_wb_data[7:0]	<= i_read_data[7:0];
		end else if((i_instr_type==`OP2)||(i_instr_type==`OP3))begin
			if((i_read_data[15]==1)&&(i_instr_type==`OP2))
				o_wb_data[31:16]	<= 16'hffff;
			else 
				o_wb_data[31:16]	<= 16'h0000;
			o_wb_data[15:0]	<= i_read_data[15:0];

		end else if(i_instr_type==`OP4)
			o_wb_data	<= i_read_data;
		else 
			o_wb_data	<= wr_data;
	end
	
	// write enable to register 
	always @(*) begin
		if((i_instr_type==`OP5)||(i_instr_type==`OP6)||(i_instr_type==`OP7))
			wr_en_int	<= 0;
		else
			wr_en_int	<= 1;
	end

	always @(posedge i_clk) begin
		o_wr_addr	<= i_opA+i_opB;
		o_write		<= wr_int;
		o_size		<= size_int;
		o_wr_en		<= wr_en_int;
	end









	
endmodule
