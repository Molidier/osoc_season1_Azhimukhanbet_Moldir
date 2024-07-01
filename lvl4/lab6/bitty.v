/****** bitty.sv ******/

module bitty(
    input run,
    input clk,
    input reset, 
    input [15:0] d_instr,

    output [15:0] d_out
);

   // assign d_instr = Generate();

// MUX components 
    wire [3:0] mux_sel;
    wire [7:0] en;
    logic [15:0] out [7:0];
    wire [15:0] out_mux;
    
    // ALU components
    wire [15:0] alu_out;
    
    // CPU components
    wire en_s, en_c, en_inst, done, mode;
    wire [2:0] alu_sel;
    wire [15:0] instruction;
    
    // Additional components
    //wire [15:0] compare;
    logic [15:0] regs;
    logic [15:0] regc;

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
        .en_s(en_s),
        .en_c(en_c),
        .en(en),
        .en_inst(en_inst)
    );


    // ALU Connection
    alu alu_inst(
        .in_a(regs),
        .in_b(out_mux),
        .select(alu_sel),
        
        .alu_out(alu_out)  // Changed to alu_out
    );

    // MUX connection  
    genvar i;
    generate
        for (i = 0; i < 8; i++) begin
            /* verilator lint_off PINMISSING */
            dff reg_out (
                .clk(clk),
                .en(en[i]),
                .d_in(out[i]),  // Corrected input signal name
                .mux_out(out[i])      // Corrected output signal name
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
    logic reg_num;

    /*always @(*) begin
        if(done==1) begin
            Evaluate(d_instr);
        end

        case(en)
            8'b00000001: reg_num = 0;
            8'b00000010: reg_num = 1;
            8'b00000100: reg_num = 2;
            8'b00001000: reg_num = 3;
            8'b00010000: reg_num = 4;
            8'b00100000: reg_num = 5;
            8'b01000000: reg_num = 6;
            8'b10000000: reg_num = 7;
        endcase


    end*/
    // Assigning out array elements to module outputs


endmodule
