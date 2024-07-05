module mux(

    input [15:0] reg0,
    input [15:0] reg1,
    input [15:0] reg2,
    input [15:0] reg3,
    input [15:0] reg4,
    input [15:0] reg5,
    input [15:0] reg6,
    input [15:0] reg7,

    input [2:0] mux_sel,
    output reg [15:0] mux_out
);

    always @(*) begin
        case(mux_sel)
            3'b000: mux_out= reg0;
            3'b001: mux_out= reg1;
            3'b010: mux_out= reg2;
            3'b011: mux_out= reg3;
            3'b100: mux_out= reg4;
            3'b101: mux_out= reg5;
            3'b110: begin 
                mux_out= reg6;
            end
            3'b111: mux_out= reg7;
            default: mux_out= 16'b0;
        endcase

    end

endmodule