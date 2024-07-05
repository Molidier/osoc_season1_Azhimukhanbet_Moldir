/* verilator lint_off MODDUP */
module bigger(
    input clk,
    input reset,
    input run,

    output done,
    output [15:0] d_out
);
    logic [15:0] mem_out;
    logic [7:0] addr;
    logic [7:0] d_in;

    pc instance1(
        .clk(clk),
        .en_pc(done),
        .reset(reset),
        .d_in(addr+1),
        .d_out(addr)
    );

    memory instance2(
        .clk(clk),
        .addr(addr),
        .out(mem_out)
    );

    bitty instance3(
        .clk(clk),
        .reset(reset),
        .run(run),
        .d_instr(mem_out),
        .done(done),
        .d_out(d_out)
    );

    


endmodule

