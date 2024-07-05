/******* fetch_unit.sv ****/
module memory(
    input clk;
    input [7:0] addr;

    output reg [15:0] out;
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
    input clk;
    input en_pc;
    input reset;
    input [7:0] d_in;

    output [7:0] d_out;
);
    
    always @(posedge clk){
        if(en_pc){
            d_out = d_in;
        }
        if(reset){
            d_in = 0;
        }
    }

endmodule
