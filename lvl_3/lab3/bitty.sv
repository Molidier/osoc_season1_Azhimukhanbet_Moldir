module bitty(
    input run,
    input clk,
    input reset, 
    input d_instr,
    input carry_in,

    output [15:0] d_out,
    output carry_out,
    output compare
);
//MUX components 
    wire [3:0] mux_sel;
    wire [7:0] en;
    logic [15:0] out [7:0];
    wire [15:0] out_mux;
    //ALU components
    wire [15:0] alu_out;
    //CPU components
    wire en_s, en_c, en_inst, done, mode;
    wire [3:0] mux_sel, alu_sel;
    wire [7:0] en;
    wire [15:0] instruction;
    //Additional components
    wire [15:0] out_s, out_c, ;

    //Registers
    dff reg_inst(clk, en_inst,d_instr, instruction);
    dff reg_s(clk, en_s, out_mux, out_s);
    dff reg_c(clk, en_c, alu_out, out_c);

    //CPU connection
    cpu cpu_inst(
    .clk(clk),
    .run(run),
    .reset(reset),
    .d_inst(d_instr),

    .mux_sel(mux_sel),
    .done(done),

    .sel(alu_sel),
    .mode(mode),
    .en_s(en_s),
    .en_c(en_c),
    .en(en),
    .en_inst(en_inst),
    )

    //ALU Connection
    alu alu_inst(
        .carry_in(carry_in),
        .a_in(out_s),
        .b_in(out_mux),
        .select(alu_sel),
        .mode(mode),

        .carry_out(carry_out),
        .compare(compare),
        .alu_out(d_out)
    )

  //MUX connection  
    genvar i;

    generate
        for (i = 0; i<8; i++ ) begin
            dff reg_inst (
                .clk(clk),
                .en(en[i]),
                .d_in(d_in),
                .d_out(out[i])
            );
        end
    endgenerate

    mux mux_inst(
        .reg0(out[0]),
        .reg1(out[1]),
        .reg2(out[2]),
        .reg3(out[3]),
        .reg4(out[4]),
        .reg5(out[5]),
        .reg6(out[6]),
        .reg7(out[7]),
        .mux_sel(mux_sel),
        .mux_out(out_mux)
    )

endmodule;