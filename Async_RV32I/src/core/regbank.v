// ===================================================
//	=================[ VLSISYS Lab. ]=================
//	* Author		: oksj (oksj@sookmyung.ac.kr)
//	* Filename		: regbank.v
//	* Description	: 
// ===================================================
module regbank(
    input               i_clk, 
	input				i_rstn,
    input       [4:0]   i_addr_a,
    input       [4:0]   i_addr_b,
    input       [31:1]  i_addr_w,
    input       [31:0]  i_in,
    output     	[31:0] 	o_outa,
    output     	[31:0] 	o_outb);

    reg	[31:0] regfile [31:1];
    wire [31:0] outa_int, outb_int;

    // Assign to outputs
    assign  o_outa = outa_int;
    assign	o_outb = outb_int;

    // Emulate zero register
    assign  outa_int = (i_addr_a == 0) ? 0 : 'z;
    assign	outb_int = (i_addr_b == 0) ? 0 : 'z;

    // Read regA
    for (genvar i = 1; i < 32 ; i=i+1)
        assign outa_int = (i_addr_a == i) ?  regfile[i] :  'z;

    // Read RegB
    for (genvar i = 1; i < 32 ; i=i+1)
        assign outb_int = (i_addr_b == i) ?  regfile[i] :  'z;

    // Reset and Write control
    for (genvar i = 1; i < 32 ; i=i+1)
		always @(posedge i_clk or negedge i_rstn) begin
            if(!i_rstn)
                regfile[i] <= 0;
            else if (i_addr_w[i])
                regfile[i] <= i_in;
		end

endmodule
