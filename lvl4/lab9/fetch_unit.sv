/******* fetch_unit.sv ****/
module memory(
    input clk,
    input [7:0] addr,

    output reg [15:0] out
);
    reg [15:0] memory_array [0:255]; //256 instructions eash wtih 16 bits
    initial begin
        $readmemh("instructions.txt", memory_array);
    end

    always @(posedge clk) begin
        out <= memory_array[addr];
    end
endmodule

module pc(
    input clk,
    input en_pc,
    input reset,
    input [7:0] d_in,

    output reg [7:0] d_out
);
    
    always @(posedge clk) begin
        if (en_pc) begin
            d_out = d_in;
        end
        if(reset) begin
            d_out = 8'b0;
        end
    end

endmodule
