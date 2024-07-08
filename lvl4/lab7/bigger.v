/* verilator lint_off MODDUP */
module bigger(
    input clk,
    input reset,
    input run,

    output done,
    output [15:0] instr,
    output [15:0] rega,
    output [15:0] regb,
    output [15:0] regcc,
    output [15:0] regss,

    output [15:0] reg0,
    output [15:0] reg1,
    output [15:0] reg2,
    output [15:0] reg3,
    output [15:0] reg4,
    output [15:0] reg5,
    output [15:0] reg6,
    output [15:0] reg7,

    output [15:0] reginst,
    output [15:0] d_out
);
    logic run_bitty;
    logic [15:0] mem_out;
    logic [7:0] addr;
    logic [7:0] d_in;

    pc instance1(
        .clk(clk),
        .en_pc(done),
        .reset(reset),
        .d_in(addr + 1),
        .d_out(addr)
    );

    memory instance2(
        .clk(clk),
        .addr(addr),
        .out(mem_out)
    );

    logic [15:0] instruction;
    logic [15:0] fetched_instruction;
    logic en_instr;
    logic instr_valid;
    logic valid_bitty;
    
    always @(posedge clk) begin
        if(instr_valid) begin
            instruction = fetched_instruction;
            valid_bitty <= 1;
        end
        else if(valid_bitty) begin
            run_bitty = 1;
        end
        if(run) begin
            instr_valid <= 1;
            en_instr <=1;
        end
        else if(done) begin
            run_bitty = 0;
            instr_valid <= 0;
            valid_bitty <= 0;
        end
        else if(reset) begin
            instr_valid <= 0;
            en_instr <= 0;
            run_bitty = 0;
        end

    end


    dff instr_reg(
        .clk(clk),
        .en(en_instr),
        .d_in(mem_out),
        .starting(16'h0),
        .reset(reset),
        .mux_out(instruction)
    );

    bitty instance3(
        .clk(clk),
        .reset(reset),
        .run(run_bitty),
        .d_instr(instruction),
        .done(done),
        .d_out(d_out),
        .rega(rega),
        .regb(regb),
        .regcc(regcc),
        .regss(regss),

        .reg0(reg0),
        .reg1(reg1),
        .reg2(reg2),
        .reg3(reg3),
        .reg4(reg4),
        .reg5(reg5),
        .reg6(reg6),
        .reg7(reg7),

        .reginst(reginst)
    );

    assign instr = instruction;

  

endmodule
