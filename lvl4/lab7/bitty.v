/****** bitty.sv ******/
/* verilator lint_off MODDUP */
module bitty(
    input run,
    input clk,
    input reset, 
    input [15:0] d_instr,

    /*output [15:0] d_out,
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

    output [15:0] reginst,*/




    output done
);
    genvar k;
    logic [15:0] d_out;
   // assign d_instr = Generate();

// MUX components 
    wire [2:0] mux_sel;
    wire [7:0] en;
    logic [15:0] out [7:0];


    wire [15:0] out_mux;
    
    // ALU components
    wire [15:0] alu_out;
    
    // CPU components
    wire en_s, en_c, en_inst;
    wire [2:0] alu_sel;
    wire [15:0] instruction;
    
    // Additional components
    //wire [15:0] compare;
    wire [15:0] regs;
    wire [15:0] regc;

    // Registers
    dff reg_inst(clk, en_inst, d_instr, 16'h0000, reset, instruction);
    dff reg_s(clk, en_s, out_mux, 16'h0000, reset,  regs);
    dff reg_c(clk, en_c, alu_out, 16'h0000, reset, regc);

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
                .d_in(regc), 
                .reset(reset),
                .starting(16'h000A), // Corrected input signal name
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


    // Assigning out array elements to module outputs
    assign d_out = regc;
    
    /*assign rega = regs;
    assign regb = out_mux;
    
    assign regcc = regc;
    assign regss = regs;
    assign reg0 = out[0];
    assign reg1 = out[1];
    assign reg2 = out[2];
    assign reg3 = out[3];
    assign reg4 = out[4];
    assign reg5 = out[5];
    assign reg6 = out[6];
    assign reg7 = out[7];
    assign reginst = instruction;*/

    import "DPI-C" function void   evaluate_values(int instr, int out);

    always @(posedge clk) begin
        if(done) begin
            evaluate_values({16'b0, instruction}, {16'b0, d_out});
        end
    end

endmodule
