module mux(
    input clk,
    input [3:0] mux_sel,

    input en_0,
    input en_1,
    input en_2,
    input en_3,
    input en_4,
    input en_5,
    input en_6,
    input en_7,

    input [15:0] d_in,
    
    output [15:0] d_out
);
    typedef enum reg[3:0] {
        R0 = 4'b0001;
        R1 = 4'b0010;
        R2 = 4'b0011;
        R3 = 4'b0100;
        R4 = 4'b0101;
        R5 = 4'b0110;
        R6 = 4'b0111;
        R7 = 4'b1000;
    } sel;
    logic [15:0] out_0, out_1, out_2, out_3, out_4, out_5, out_6, out_7;

    dff reg0 (clk, en_0, d_in, out_0);
    dff reg1 (clk, en_1, d_in, out_1);
    dff reg2 (clk, en_2, d_in, out_2);
    dff reg3 (clk, en_3, d_in, out_3);
    dff reg4 (clk, en_4, d_in, out_4);
    dff reg5 (clk, en_5, d_in, out_5);
    dff reg6 (clk, en_6, d_in, out_6);
    dff reg7 (clk, en_7, d_in, out_7);

    always @(posedge clk) begin
        case(mux_sel)
            4'b0001: d_out<= out_0;
            4'b0010: d_out<= out_1;
            4'b0011: d_out<= out_2;
            4'b0100: d_out<= out_3;
            4'b0101: d_out<= out_4;
            4'b0110: d_out<= out_5;
            4'b0111: d_out<= out_6;
            4'b1000: d_out<= out_7;
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