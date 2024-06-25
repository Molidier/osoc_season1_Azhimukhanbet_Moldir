module dff(
    input clk,
    input en,
    input wire [15:0] d_in,

    output wire [15:0] mux_out

);
    always @(posedge clk) begin
        if(en) begin
            mux_out <= d_in;
        end
        else begin
            mux_out <= mux_out;
        end
    end
endmodule