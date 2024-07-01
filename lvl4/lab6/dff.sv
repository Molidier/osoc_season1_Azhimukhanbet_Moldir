module dff(
    input clk,
    input en,
    input wire [15:0] d_in,

    output reg [15:0] mux_out

);
    always @(posedge clk) begin
        if(en) begin
            mux_out <= d_in;
        end
    end
endmodule