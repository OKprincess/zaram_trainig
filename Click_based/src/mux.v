// ===================================================
//	=================[ VLSISYS Lab. ]=================
//	* Author		: oksj (oksj@sookmyung.ac.kr)
//	* Filename		: mux.v
//	* Description	: 
// ===================================================
module mux #(
    parameter DATA_WIDTH = 32,
    parameter PHASE_INIT_C = 1'b0,
    parameter PHASE_INIT_A = 1'b0,
    parameter PHASE_INIT_B = 1'b0,
    parameter PHASE_INIT_SEL = 1'b0
) (
    input 	    					reset,
    input 	     					inA_req,
    input 	     [DATA_WIDTH-1:0] 	inA_data,
    output	reg 					inA_ack,
    input 	     					inB_req,
    input 	     [DATA_WIDTH-1:0] 	inB_data,
    output	reg 					inB_ack,
    output	reg 					outC_req,
    output	reg [DATA_WIDTH-1:0] 	outC_data,
    input 	     					outC_ack,
    input 	     					inSel_req,
    output	reg 					inSel_ack,
    input 	     					selector
);

    // Registers
    reg phase_c, phase_sel;
    reg phase_a, phase_b;
    
    // Control Signals
    wire inA_token, inB_token, inSel_token;
    wire click_req, click_ack;
    
    // Input state
    assign inA_token = phase_a ^ inA_req;
    assign inB_token = phase_b ^ inB_req;
    assign inSel_token = phase_sel ^ inSel_req;
    
    // Selector triggered pulse
    assign click_req = (inA_token & inSel_token & selector) | (inB_token & inSel_token & ~selector);
    
    // Output state
    assign click_ack = ~(phase_c ^ outC_ack);
    
    // Output assignments
    always @(*) begin
        inSel_ack = phase_sel;
        outC_req = phase_c;
        outC_data = selector ? inA_data : inB_data;
        inA_ack = phase_a;
        inB_ack = phase_b;
    end
    
    // Request register process
    always @(posedge click_req or posedge reset) begin
        if (reset)
            phase_c <= PHASE_INIT_C;
        else 
            phase_c <= ~phase_c;
    end
    
    // Acknowledgment register process
    always @(posedge click_ack or posedge reset) begin
        if (reset) begin
            phase_a <= PHASE_INIT_A;
            phase_b <= PHASE_INIT_B;
            phase_sel <= PHASE_INIT_SEL;
        end else begin
            phase_a <= phase_a ^ selector;
            phase_b <= phase_b ^ ~selector;
            phase_sel <= inSel_req;
        end
    end
    
endmodule
