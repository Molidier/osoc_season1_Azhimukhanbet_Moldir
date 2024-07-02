module dff(
    input clk,
    input en,
    input wire [15:0] d_in,
    input reset,

    output reg [15:0] mux_out

);
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            mux_out <= 16'h000A;
        end
        else if(en) begin
            mux_out <= d_in;
        end
    end
endmodule