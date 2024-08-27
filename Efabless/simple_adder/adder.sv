module adder (
    input [15:0] in_a,
    input [15:0] in_b,
    input clk,
    input reset,

    output [15:0] result
);

    always @(posedge clk) begin
        if(reset) begin
            reult<=0;
        end
        else begin
            result <= in_a + in_b;
        end
    end


endmodule