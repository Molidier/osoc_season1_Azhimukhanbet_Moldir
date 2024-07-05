module bigger(
    input clk;
    input reset;
    input run;
);

    logic [15:0] mem_out;
    logic [15:0] done;
    logic [7:0] addr;
    logic [7:0] d_in;

    pc instance(
        .clk(clk),
        .en_pc(done),
        .reset(reset),
        .d_in(addr+1),
        .d_out(addr)
    );

    memory instance(
        .clk(clk),
        .addr(addr),
        .out(mem_out)
    )

    bitty instance(
        .clk(clk),
        .reset(reset),
        .run(run),
        .d_instr(mem_out)
        .done(done)
    );

    


endmodule

