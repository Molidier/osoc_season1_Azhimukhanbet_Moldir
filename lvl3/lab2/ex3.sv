module top_module (
    input clk,
    input reset,      // Synchronous reset
    input data,
    output start_shifting);
    
    typedef enum reg[2:0] {
    	S0 = 3'b000,
        S1 = 3'b001,
        S2 = 3'b010,
        S3 = 3'b011,
        S4 = 3'b100
    } state_t;
    
    state_t cur_state, next_state;
    logic res;

    
    always @(posedge clk) begin : SEQ_LOGIC
        if(reset==1) begin
            cur_state = S0;
            res = 1'b0;
        end
        else begin
            cur_state = next_state;
            if(cur_state == S4) begin
                res = 1'b1;
            end
        end
    end
   
        
    always @(*) begin
        if(res==0) begin
            case(cur_state) 
                S0: next_state = (data==1) ? S1:S0;
                S1: next_state = (data==1) ? S2:S0;
                S2: next_state = (data==0) ? S3:S2;
                S3: next_state = (data==1) ? S4:S0;
                S4: next_state = S4;
                default: next_state = S0;
            endcase
        end
        else begin
            next_state = S0;
        end
    end
    
    assign start_shifting = res;
    

        

    


endmodule
