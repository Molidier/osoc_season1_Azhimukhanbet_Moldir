module top_module (
    input clk,
    input reset,      // Synchronous reset
    output shift_ena);
    
    logic [3:0] a;
    
    
    always @(posedge clk) begin
        if(reset) begin
            shift_ena <= 1;
            a <= 1;
            $display(a);
        end
        else begin
            if(a==4) begin
                shift_ena <= 0;
            end
            a<=a+1'b1;
        end
    end
    
endmodule
