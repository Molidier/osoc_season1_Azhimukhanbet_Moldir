`include "alu.sv"
`include "mux.sv"

module mux(
    input clk,
    input [3:0] mux_sel,
    input [7:0] en,
    input [15:0] d_in,
    
    output [15:0] d_out
);

    logic [15:0] out [7:0];

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


    always @(posedge clk) begin
        case(mux_sel)
            4'b0001: d_out<= out[0];
            4'b0010: d_out<= out[1];
            4'b0011: d_out<= out[2];
            4'b0100: d_out<= out[3];
            4'b0101: d_out<= out[4];
            4'b0110: d_out<= out[5];
            4'b0111: d_out<= out[6];
            4'b1000: d_out<= out[7];
        endcase

    end

endmodule

modele dff(
    input clk,
    input en,
    input [15:0] d_in,

    output [15:0] d_out

);
    always @(posedge clk) begin
        if(en) begin
            d_out <= d_in;
        end
        else begin
            d_out<=d_out;
        end
    end
endmodule;