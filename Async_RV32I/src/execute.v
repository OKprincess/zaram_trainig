// ===================================================
//	=================[ VLSISYS Lab. ]=================
//	* Author		: oksj (oksj@sookmyung.ac.kr)
//	* Filename		: execute.v
//	* Description	: 
// ===================================================
`include	"pkg.v"

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
    //adder       adder1 (.clk(clk), .opA(adderA), .opB(adderB), .i(adder_i), .result_out(result[0]));
	reg	[31:0]	adder_result;
	always @(*) begin
		if(adder_i==`OP3) begin
			if($signed(adderA)<$signed(adderB))
				adder_result <= 32'b1;
			else
				adder_result <= 32'b0;
		end else if(adder_i==`OP1) begin
			if($unsigned(adderA)<$unsigned(adderB))
				adder_result <= 32'b1;
			else
				adder_result <= 32'b0;
		end else if(adder_i==`OP1) begin
			adder_result <= adderA - adderB;
		end else begin
			adder_result <= adderA + adderB;
		end
	end

	always @(posedge i_clk) begin
		result[0] <= adder_result;	
	end

    //logicUnit   logical1 (.clk(clk), .opA(logicA), .opB(logicB), .i(logic_i), .result_out(result[1]));
	reg	[31:0]	logic_result;
	always @(*) begin
		if(logic_i==`OP0)
			logic_result <= logicA ^ logicB;
		else if (logic_i==`OP1)
			logic_result <= logicA | logicB;
		else
			logic_result <= logicA & logicB;
	end

	always @(posedge i_clk) begin
		result[1] <= logic_result;	
	end
    
	//shiftUnit   shift1 (.clk(clk), .opA(shiftA), .opB(shiftB), .i(shift_i), .result_out(result[2]));
	reg	[31:0]	shift_result;
	always @(*) begin
		if(shift_i==`OP0)
			shift_result <= shiftA << shiftB;
		else if (shift_i==`OP1)
			shift_result <= shiftA >> shiftB;
		else
			shift_result <= $signed(shiftA) >>> shiftB;
	end

	always @(posedge i_clk) begin
		result[2] <= shift_result;
	end
    /*branchUnit  branch1 (.clk(clk), .opA(branchA), .opB(branchB), .offset(branchC), .NPC(NPCbranch), .i(branch_i),
                .result_out(result[4]), .result_jal(result[3]), .jump_out(jump_int), .we_out(we_branchUnit));*/
	reg	[31:0]	branch_result, branch_sum;
	reg			branch_jump, branch_wr_en;
	///////////////////////RESULT assign//////////////////////
	assign		branch_sum = branchA + branchB;
	always @(*) begin
		if(branch_i==`OP6)
			branch_result <= branch_sum;
		else if (branch_i==`OP7) begin
			branch_result[31:1] <= branch_sum[31:1];
			branch_result[0]	<= 0;
		end else
			branch_result <= NPCbranch + branchC;
	end
	////////////////////Generates branch signal////////////////////
	always @(*) begin
		if(branch_i==`OP0)
			branch_jump <= (branchA==branchB);
		else if (branch_i==`OP1)
			branch_jump <= (branchA!=branchB);
		else if (branch_i==`OP2)
			branch_jump <= ($signed(branchA)<$signed(branchB));
		else if (branch_i==`OP3)
			branch_jump <= ($unsigned(branchA)<$unsigned(branchB));
		else if (branch_i==`OP4)
			branch_jump <= ($signed(branchA)>=$signed(branchB));
		else if (branch_i==`OP5)
			branch_jump <= ($unsigned(branchA)>=$unsigned(branchB));
		else if ((branch_i==`OP6)||(branch_i==`OP7))
			branch_jump	<= 1;
		else
			branch_jump	<= 0;
	end
	
	////////////write en signal/////////////
	always @(*) begin
		if((branch_i==`OP6)||(branch_i==`OP7))
			branch_wr_en <= 1'b1;
		else
			branch_wr_en <= 1'b0;
	end

	///////////output//////////////
	always @(posedge i_clk) begin
		result[4] <= branch_result;
		result[3] <= NPCbranch+4;
		jump_int  <= branch_jump;
		we_branchUnit <= branch_wr_en;
	end
		
    /*memoryUnit  memory1 (.clk(clk), .opA(memoryA), .opB(memoryB), .data(memoryC), .i(memory_i), .read_address(read_address), .read(read),
                .DATA_in(DATA_in), .write_address(result[7]), .DATA_wb(result[6]),  .write(write_int), .size(size_int), .we_out(we_memoryUnit));*/
	reg	mem_write, mem_wr_en;
	reg [31:0] mem_DATA_write, mem_write_addr2;
	reg	[1:0]	size_mem;




    //bypassUnit  bypassUnit1 (.clk(clk), .opA(bypassB), .result_out(result[5]));
	
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
            adderA <= opA;
            adderB <= opB;
        end else begin
            adder_i <= NOTOKEN;
            adderA <= Z;
            adderB <= Z;
        end
      ////////////////////////////////////// logic /////////////////////////////////////////////////////////
        if (i_alu_sel==`LOGICAL) begin
            logic_i <= i;
            logicA <= opA;
            logicB <= opB;
        end else begin
            logic_i <= NOTOKEN;
            logicA <= Z;
            logicB <= Z;
        end
      ////////////////////////////////////// shift /////////////////////////////////////////////////////////
        if (i_alu_sel==`SHIFTER) begin
            shift_i <= i;
            shiftA <= opA;
            shiftB <= opB[4:0];
        end else begin
            shift_i <= NOTOKEN;
            shiftA <= Z;
            shiftB <= Z;
        end
      ////////////////////////////////////// branch ////////////////////////////////////////////////////////
        if (i_alu_sel==`BRANCH) begin
            branch_i <= i;
            branchA <= opA;
            branchB <= opB;
            branchC <= opC;
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
            memory_i <= i;
            memoryA <= opA;
            memoryB <= opB;
            memoryC <= opC;
        end else begin
            memory_i <= NOTOKEN;
            memoryA <= Z;
            memoryB <= Z;
            memoryC <= Z;
        end
      ////////////////////////////////////// bypass ////////////////////////////////////////////////////////
        if(i_alu_sel==`BYPASS)
            bypassB <= opB;
        else
            bypassB <= Z;
        end

///////////////////////////////////////////////// DEMUX ////////////////////////////////////////////////////
    always @(*) begin                    // RESULT[0]
        if(alu_stage2==adder)
            result_out[0] <= result[0];
        else if(xu_stage2==logical)
            result_out[0] <= result[1];
        else if(xu_stage2==shifter)
            result_out[0] <= result[2];
        else if(xu_stage2==branch)
            result_out[0] <= result[3];
        else if(xu_stage2==memory)
            result_out[0] <= result[6];
        else
            result_out[0] <= result[5];
   ////////////////////////////////////
        if(xu_stage2==branch)             // RESULT[1]
            result_out[1] <= result[4];
        else if(xu_stage2==memory)
            result_out[1] <= result[7];
        else
            result_out[1] <= '0;
   ////////////////////////////////////
        if(xu_stage2==branch)             // JUMP_OUT
            jump_out <= jump_int;
        else
            jump_out <= '0;
   ////////////////////////////////////
        if(xu_stage2==memory) begin       // SIZE & WRITE
            size <= size_int;
            write <= write_int;
        end else begin
            size <= '0;
            write <= '0;
        end
   ////////////////////////////////////
        if(xu_stage2==branch)             // WE_OUT
            we_out <= we_branchUnit;
        else if(xu_stage2==memory)
            we_out <= we_memoryUnit;
        else
            we_out <= 1;
    end
	endmodule
