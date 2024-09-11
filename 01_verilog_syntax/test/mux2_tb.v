`timescale	1ns/1ps	
`define CLKFREQ     100     // Unit: MHz
`define SIMCYCLE    100

`include    "mux2.v"

module  mux2_tb;
// ------------------------------------------
//  DUT Signals & Instantiate
// ------------------------------------------
    wire        o_out;
    reg         i_sel;
    reg         i_in0;
    reg         i_in1;

    mux2
    u_mux2
    (   
        .o_out      (o_out      ),
        .i_sel      (i_sel      ),
        .i_in0      (i_in0      ),
        .i_in1      (i_in1      )
    );

// --------------------------------------------------
//  Test Stimulus
// --------------------------------------------------
    integer     i;
    initial begin
        for (i=0; i<`SIMCYCLE; i++) begin
            {i_sel, i_in0, i_in1} = $urandom_range(0,7);
            #(1000/`CLKFREQ);
        end
    end

    reg [8*32-1:0]  vcd_file;
    initial begin
        if ($value$plusargs("vcd_file=%s", vcd_file)) begin
            $dumpfile(vcd_file);
            $dumpvars;
        end
    end

endmodule

