// ===================================================
//	=================[ VLSISYS Lab. ]=================
//	* Author		: oksj (oksj@sookmyung.ac.kr)
//	* Filename		: operandFetch.v
//	* Description	: 
// ===================================================
`include	"pkg.v"

module operandFetch 
#(
	parameter DEPTH = 2
)(
    input       		i_clk,
    input       		i_rstn,
    input       		i_wr_en,
    input       [4:0]   i_rs1,                   // Address of the 1st register, from decode unit
    input       [4:0]   i_rs2,                   // Address of the 2nd register, from decode unit
    input       [4:0]   i_rd,                   // Address of the destination register, from decode unit
    input 		[2:0]	i_instr_format,                    // Instruction Format
    input 		[31:0]  i_instr,            // Object code of the instruction to extract the immediate operand
    input       [31:0]  i_next_pc,                    // Bypassed to execute unit as an operand
    input       [2:0]   i_instr_type,                   // Instruction operation (OP0, OP1...)
    input       [2:0]   i_alu_sel,              // Instruction unity     (adder,shifter...)
    input       [3:0]   i_tag,                 // Instruction Tag
    input       [31:0]  i_data_rs1,                  // Data read from register bank
    input       [31:0]  i_data_rs2,                  // Data read from register bank
    output     	[4:0]  	o_rs1_add,               // Address of the 1st register, conected directly in the register bank
    output     	[4:0]  	o_rs2_add,               // Address of the 2nd register, conected directly in the register bank
    output     	[31:1] 	o_addr_wr,                 // Write Address to register bank
    output  reg	[31:0] 	o_opA,                // First operand output register
    output  reg	[31:0] 	o_opB,                // Second operand output register
    output  reg	[31:0] 	o_opC,                // Third operand output register
    output  reg	[31:0] 	o_next_pc,                // PC operand output register
    output  reg	[2:0]   o_instr_type,              // Instruction operation (OP0, OP1...)
    output  reg [2:0]   o_alu_sel,                 // Instruction unity     (adder,shifter...)
    output  reg [3:0]  	o_tag,                // Instruction Tag
    output  reg         o_bubble);                // Bubble issue indicator (0 active)

    reg	 	[31:0] imed, opA, opB, opC, regD_add, target;
    wor 	[31:0] locked;
    reg		[31:0] lock_queue[DEPTH];

///////////////////////////////////////////////// Extract the immediate based on instruction type ///////////////////////////////////////////////////
	always @(*) begin
        if(i_instr_format==`I_TYPE) begin
            imed[10:0] <= i_instr[30:20];
            if(i_instr[31]==0)
                imed[31:11] <= 21'b000000000000000000000;
            else
                imed[31:11] <= 21'b111111111111111111111;

        end else if(i_instr_format==`S_TYPE) begin
            imed[10:5] <= i_instr[30:25];
            imed[4:0]  <= i_instr[11:7];
            if(i_instr[31]==0)
                imed[31:11] <= 21'b000000000000000000000;
            else
                imed[31:11] <= 21'b111111111111111111111;

        end else if(i_instr_format==`B_TYPE) begin
            imed[11] <= i_instr[7];
            imed[10:5] <= i_instr[30:25];
            imed[4:1] <= i_instr[11:8];
            imed[0] <= 0;
            if(i_instr[31]==0)
                imed[31:12] <= 20'b00000000000000000000;
            else
                imed[31:12]<=20'b11111111111111111111;

        end else if(i_instr_format==`U_TYPE) begin
            imed[31:12] <= i_instr[31:12];
            imed[11:0] <= 12'b000000000000;

        end else if(i_instr_format==`J_TYPE) begin
            imed[19:12] <= i_instr[19:12];
            imed[11] <= i_instr[20];
            imed[10:5] <= i_instr[30:25];
            imed[4:1] <= i_instr[24:21];
            imed[0] <= 0;
            if(i_instr[31]==0)
                imed[31:20] <= 12'b000000000000;
            else
                imed[31:20] <= 12'b111111111111;

        end else
            imed[31:0] <= 32'h00000000;
	end

///////////////////////////////////////////////// Read Addresses to RegBank /////////////////////////////////////////////////////////////////////////
    assign o_rs1_add = i_rs1;
    assign o_rs2_add = i_rs2;

///////////////////////////////////////////////// Control of the exits based on format //////////////////////////////////////////////////////////////
	always @(*) begin
        if(i_instr_format==`I_TYPE) begin                               // addi, slti, andi, ori, xori, slli, slri, srai, LOADS, JALR
            opA <= i_data_rs1;
            opB <= i_data_rs2;
            opC <= 32'h00000000;

        end else if(i_instr_format==`U_TYPE | i_instr_format==`J_TYPE) begin        // auipc, lui, jal
            opA <= i_next_pc;
            opB <= imed;
            opC <= 32'h00000000;

        end else if(i_instr_format==`S_TYPE) begin                      // STORES
            opA <= i_data_rs1;
            opB <= imed;
            opC <= i_data_rs2;

        end else if(i_instr_format==`R_TYPE | i_instr_format==`B_TYPE) begin        // Conditional branches and register-register instructions
            opA <= i_data_rs1;
            opB <= i_data_rs2;
            opC <= imed;

        end else begin                                      //nop, invalid
            opA <= imed;
            opB <= 32'h00000000;
            opC <= 32'h00000000;
        end
	end

////////////////////////////////////////////////// Conversion to one-hot codification ///////////////////////////////////////////////////////////////
    always @(*) begin
        regD_add <= 1 << i_rd;
    ////////////////////////////////
        if(i_alu_sel==`MEMORY && (i_instr_type==`OP5 | i_instr_type==`OP6 | i_instr_type==`OP7)) // [0] Indicates a pending write in memory, used to avoid data hazards in memory
            regD_add[0] <= 1;
        else
            regD_add[0] <= 0;
    end

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	always @(*) begin
        if(!o_bubble)                                         // If a bubble is being issued then regD=0 is inserted in queue (to avoid deadlock)
            target <=  0;
        else                                                // Otherwise the instruction regD is the target to be inserted in queue
            target <=regD_add;
	end

////////////////////////////////////////////////// REGISTER LOCK QUEUE //////////////////////////////////////////////////////////////////////////////
always @(posedge i_clk or negedge i_rstn) begin
		if(!i_rstn) begin                                          // Reset clears the queue
            for (integer i = 0; i < DEPTH; i++)
                lock_queue[i] <=  0;
		end else begin
            for (integer j = 0; j < DEPTH-1; j++)
               	lock_queue[j+1] <= lock_queue[j];           // Move the queue forward
            lock_queue[0] <= target;                        // and inserts a new Target in the queue
        end
	end

	genvar w;
    generate                                                // Assign to wire or (wor) signal to generate the mask of locked registers (register with pending writes)
		for( w = 0; w < DEPTH; w=w+1) begin
        	assign locked = lock_queue[w];
		end
    endgenerate

    assign o_addr_wr = lock_queue[DEPTH-1][31:1] & {32{&i_wr_en}};  // Write Address is the last position with a bitwise AND with the write enable signal

///////////////////////////////////////////////// BUBBLE SIGNAL GENERATION //////////////////////////////////////////////////////////////////////////
	always @(*) begin
        if((locked[0]==1) && (i_alu_sel==`MEMORY) && (i_instr_type==`OP0 | i_instr_type==`OP1 | i_instr_type ==`OP2 | i_instr_type==`OP3 | i_instr_type==`OP4)) //Can't read from memory if a write in memory is pending
            o_bubble <= 0;
        else if((locked[o_rs1_add]==1) || (locked[o_rs2_add]==1)) // Checks if rs1 and rs2 are not in the list of pending write registers
            o_bubble <= 0;
        else                                                // No Hazards identified
            o_bubble <= 1;
	end
///////////////////////////////////////////////// Output registers //////////////////////////////////////////////////////////////////////////////////
	always @(posedge i_clk or negedge i_rstn) begin
        if (!i_rstn) begin                                   // Reset
            o_opA <= 0;
            o_opB <= 0;
            o_opC <= 0;
            o_next_pc <= 0;
            o_instr_type <= `OP0;
            o_alu_sel <= `BYPASS;
            o_tag <=  0;

         end else if(o_bubble==0) begin                       // Propagate bubble
            o_opA <= 0;
            o_opB <= 0;
            o_opC <= 0;
            o_next_pc <=  0;
            o_instr_type <= `OP0;
            o_alu_sel <= `BYPASS;
            o_tag <=  0;

        end else if(o_bubble==1) begin                        // Propagate instruction
            o_opA <= opA;
            o_opB <= opB;
            o_opC <= opC;
            o_next_pc<= i_next_pc;
            o_instr_type <= i_instr_type;
            o_alu_sel <= i_alu_sel;
            o_tag <= i_tag;
        end
	end

		endmodule
