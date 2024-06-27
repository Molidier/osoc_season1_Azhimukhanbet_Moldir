/****** bitty.sv ******/

module bitty(
    input run,
    input clk,
    input reset, 
    input [15:0] d_instr,
    input carry_in,
    
    output logic [15:0] reg0,
    output logic [15:0] reg1,
    output logic [15:0] reg2,
    output logic [15:0] reg3,
    output logic [15:0] reg4,
    output logic [15:0] reg5,
    output logic [15:0] reg6,
    output logic [15:0] reg7,

    output logic [15:0] regs,
    output logic [15:0] regc,
    output [15:0] d_out,
    output carry_out,
    output done
);

// MUX components 
    wire [3:0] mux_sel;
    logic [7:0] en;
    logic [15:0] out [7:0];
    wire [15:0] out_mux;
    
    // ALU components
    wire [15:0] alu_out;
    
    // CPU components
    wire en_s, en_c, en_inst, mode;
    wire [3:0] alu_sel;
    wire [15:0] instruction;
    
    // Registers
    dff reg_inst(clk, en_inst, d_instr, instruction);
    dff reg_s(clk, en_s, out_mux, regs);
    dff reg_c(clk, en_c, alu_out, regc);

    // CPU connection
    cpu cpu_inst(
        .clk(clk),
        .run(run),
        .reset(reset),
        .d_inst(instruction),
        .mux_sel(mux_sel),
        .done(done),
        .sel(alu_sel),
        .mode(mode),
        .en_s(en_s),
        .en_c(en_c),
        .en(en),
        .en_inst(en_inst)
    );

    // ALU Connection
    alu alu_inst(
        .carry_in(carry_in),
        .a_in(regs),
        .b_in(out_mux),
        .select(alu_sel),
        .mode(mode),
        .carry_out(carry_out),
        .alu_out(alu_out)
    );

    // MUX connection  
    genvar i;
    generate
        for (i = 0; i < 8; i++) begin
            /* verilator lint_off PINMISSING */
            dff reg_out (
                .clk(clk),
                .en(en[i]),
                .d_in(regc),
                .mux_out(out[i])  // Corrected output signal name to 'q'
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
    );

    always @(posedge clk or posedge reset) begin
        if (reset || done) begin
            out[0] <= 16'b0;
            out[1] <= 16'b0;
            out[2] <= 16'b0;
            out[3] <= 16'b0;
            out[4] <= 16'b0;
            out[5] <= 16'b0;
            out[6] <= 16'b0;
            out[7] <= 16'b0;

            en = 8'b0;
        end
    end

    // Reset registers on run
    /*always @(posedge run) begin
        if (run) begin
            reg0 <= 16'b0;
            reg1 <= 16'b0;
            reg2 <= 16'b0;
            reg3 <= 16'b0;
            reg4 <= 16'b0;
            reg5 <= 16'b0;
            reg6 <= 16'b0;
            reg7 <= 16'b0;
        end
    end*/

    // Assigning out array elements to module outputs
    assign reg0 = out[0];
    assign reg1 = out[1];
    assign reg2 = out[2];
    assign reg3 = out[3];
    assign reg4 = out[4];
    assign reg5 = out[5];
    assign reg6 = out[6];
    assign reg7 = out[7];
    assign d_out = alu_out;

endmodule
