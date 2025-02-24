// ===================================================
//	=================[ VLSISYS Lab. ]=================
//	* Author		: oksj (oksj@sookmyung.ac.kr)
//	* Filename		: execute.v
//	* Description	: 
// ===================================================
`include	"pkg.v"
`include	"adder.v"
`include	"logic.v"
`include	"shift.v"
`include	"branch.v"
`include	"memory.v"
`include	"branch.v"

module execute(
    input 		         i_clk,
    input 		         i_rstn,
    input 		 [31:0]  i_next_pc,                // Operand from Operand Fetch stage
    input 		 [31:0]  i_opA,                //              ||
    input 		 [31:0]  i_opB,                //              ||
    input 		 [31:0]  i_opC,                //              ||
    input        [2:0]   i_instr_type,               // Operation selector
    input        [2:0]   i_alu_sel,             // Execute Unit selector
    input  		 [3:0]   i_tag,             // Instruction tag
    output reg   [31:0] o_result [1:0],   // Results array
    output reg          o_jump,           // Signal that indicates a branch taken
    output reg   [3:0]  o_tag,            // Instruction tag
    output reg          o_wr_en,             // Write enable to regbank
    output reg   [31:0] o_read_addr,       // Memory Read Address
    output reg          o_read_en,               // Allows memory read
	//
    input       [31:0]  i_DATA,            // Data returned from memory
    output              o_write,              // Signal that indicates the write memory operation to retire
    output       [1:0]  o_size);              // Signal that indicates the size of Write in memory(byte(1),half(2),word(4))

    reg	 jump_int, write_int;
    reg	 [1:0] size_int;
    reg	 [31:0] adderA, adderB, logicA, logicB, shiftA, branchA, branchB, branchC, memoryA, memoryB, memoryC, bypassB, NPCbranch;
    reg	 [4:0] shiftB;
    reg	 [31:0] result [7:0];
    reg	[2:0] adder_i, logic_i, shift_i, branch_i, memory_i, queue_i;
    reg	[2:0]	alu_stage2;

///////////////////////////////////////////////////// Instantiation of execution units  ////////////////////
    adder       
	u_adder (
		.i_clk			(i_clk), 
		.i_opA			(adderA), 	
		.i_opB			(adderB), 
		.i_instr_type	(adder_i), 
		.o_result		(result[0])
	);

    logicUnit   
	u_logic (
		.i_clk			(i_clk), 
		.i_opA			(logicA), 
		.i_opB			(logicB), 
		.i_instr_type	(logic_i), 
		.o_result		(result[1])
	);
	shiftUnit   
	u_shift (
		.i_clk			(i_clk), 
		.i_opA			(shiftA), 
		.i_opB			(shiftB), 
		.i_instr_type	(shift_i), 
		.o_result		(result[2])
	);
    branchUnit  
	u_branch (
		.i_clk			(i_clk), 
		.i_opA			(branchA), 
		.i_opB			(branchB), 
		.i_offset		(branchC), 
		.i_next_pc		(NPCbranch), 
		.i_instr_type	(branch_i),
        .o_result		(result[4]), 
		.o_result_jal	(result[3]), 
		.o_jump			(jump_int), 
		.o_wr_en		(we_branchUnit)
	);
		
    memoryUnit  
	u_memory (
		.i_clk			(i_clk), 
		.i_opA			(memoryA), 
		.i_opB			(memoryB), 
		.i_wr_data		(memoryC), 
		.i_instr_type	(memory_i), 
		.o_read_addr	(read_address), 
		.o_read			(read),
        .i_read_data	(DATA_in), 
		.o_wr_addr		(result[7]), 
		.o_wb_data		(result[6]),  
		.o_write		(write_int), 
		.o_size			(size_int), 
		.o_wr_en		(we_memoryUnit)
	);

    bypassUnit  
	u_bypassUnit (
		.i_clk			(i_clk), 
		.i_opA			(bypassB), 
		.o_result		(result[5])
	);
	
////////////////////////////////////////////////////////////////////////////////////////////////////////////
    always@(posedge i_clk) begin  // Generates a internal second stage to DEMUX operation
        alu_stage2 <= i_alu_sel;
        o_tag <= i_tag;
    end
////////////////////////////////////////////////////////////////////////////////////////////////////////////
    always @(*) begin
      ////////////////////////////////////// adder /////////////////////////////////////////////////////////
        if(i_alu_sel==`ADDER) begin
            adder_i <= i_instr_type;
            adderA <= i_opA;
            adderB <= i_opB;
        end else begin
            adder_i <= NOTOKEN;
            adderA <= Z;
            adderB <= Z;
        end
      ////////////////////////////////////// logic /////////////////////////////////////////////////////////
        if (i_alu_sel==`LOGICAL) begin
            logic_i <= i_instr_type;
            logicA <= i_opA;
            logicB <= i_opB;
        end else begin
            logic_i <= NOTOKEN;
            logicA <= Z;
            logicB <= Z;
        end
      ////////////////////////////////////// shift /////////////////////////////////////////////////////////
        if (i_alu_sel==`SHIFTER) begin
            shift_i <= i_instr_type;
            shiftA <= i_opA;
            shiftB <= i_opB[4:0];
        end else begin
            shift_i <= NOTOKEN;
            shiftA <= Z;
            shiftB <= Z;
        end
      ////////////////////////////////////// branch ////////////////////////////////////////////////////////
        if (i_alu_sel==`BRANCH) begin
            branch_i <= i_instr_type;
            branchA <= i_opA;
            branchB <= i_opB;
            branchC <= i_opC;
            NPCbranch <= NPC;
        end else begin
            branch_i <= NOTOKEN;
            branchA <= Z;
            branchB <= Z;
            branchC <= Z;
            NPCbranch <= Z;
        end
      ////////////////////////////////////// memory ////////////////////////////////////////////////////////
        if (i_alu_sel==`MEMORY) begin
            memory_i <= i_instr_type;
            memoryA <= i_opA;
            memoryB <= i_opB;
            memoryC <= i_opC;
        end else begin
            memory_i <= NOTOKEN;
            memoryA <= Z;
            memoryB <= Z;
            memoryC <= Z;
        end
      ////////////////////////////////////// bypass ////////////////////////////////////////////////////////
        if(i_alu_sel==`BYPASS)
            bypassB <= i_opB;
        else
            bypassB <= Z;
        end

///////////////////////////////////////////////// DEMUX ////////////////////////////////////////////////////
    always @(*) begin                    // RESULT[0]
        if(alu_stage2==`ADDER)
            result_out[0] <= result[0];
        else if(alu_stage2==`LOGICAL)
            result_out[0] <= result[1];
        else if(alu_stage2==`SHIFTER)
            result_out[0] <= result[2];
        else if(alu_stage2==`BRANCH)
            result_out[0] <= result[3];
        else if(alu_stage2==`MEMORY)
            result_out[0] <= result[6];
        else
            result_out[0] <= result[5];
   ////////////////////////////////////
        if(alu_stage2==`BRANCH)             // RESULT[1]
            result_out[1] <= result[4];
        else if(alu_stage2==`MEMORY)
            result_out[1] <= result[7];
        else
            result_out[1] <= 0;
   ////////////////////////////////////
        if(alu_stage2==`BRANCH)             // JUMP_OUT
            jump_out <= jump_int;
        else
            jump_out <= 0;
   ////////////////////////////////////
        if(alu_stage2==`MEMORY) begin       // SIZE & WRITE
            size <= size_int;
            write <= write_int;
        end else begin
            size <= 0;
            write <= 0;
        end
   ////////////////////////////////////
        if(alu_stage2==`BRANCH)             // WE_OUT
            we_out <= we_branchUnit;
        else if(alu_stage2==`MEMORY)
            we_out <= we_memoryUnit;
        else
            we_out <= 1;
    end
	endmodule
