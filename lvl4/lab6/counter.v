import "DPI-C" function void notify_counter_nine();

module counter(input logic clk, input logic reset, output [3:0] out);
    logic [3:0] count;

    always @(posedge clk or posedge reset) begin
        if(reset) begin
            count <= 0;
        end else begin
            count <= count +1;
            if(count == 4'd9) begin
                notify_counter_nine();
            end
        end
    end

    assign out = count;
endmodule