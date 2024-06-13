module top_module (
    input clk,
    input reset,      // Synchronous reset
    input data,
    output shift_ena,
    output counting,
    input done_counting,
    output done,
    input ack );
    
    typedef enum reg[2:0]{
    	S0 = 3'b000,
        S1 = 3'b001,
        S2 = 3'b010,
        S3 = 3'b011,
        S4 = 3'b100,
        S5 = 3'b101,
        S6 = 3'b110
    } states;
    
    logic [3:0] shift_counter;
    states cur_state, next_state;
    logic start;
    
    always @(posedge clk) begin
        if(reset) begin
            cur_state = S0;
            shift_ena = 0;
            counting = 0;
            done = 0;
        end
        else begin
            cur_state = next_state;
            if(cur_state==S4) begin
                shift_ena = 1;
                shift_counter++;
            end
            else begin
                shift_counter = 0;
            end
            if(cur_state==S5) begin
                counting = 1;
                shift_ena =  0;
                done = 0;
            end
            if(cur_state==S6) begin
                counting = 0;
                shift_ena =  0;
                done = 1;
            end
            else begin
                done=0;
            end
                
        end
                
    end
    
    
    
    always @(*) begin
            case(cur_state)
                S0: next_state = (data==1) ? S1:S0;
                S1: next_state = (data==1) ? S2:S0;
                S2: next_state = (data==0) ? S3:S2;
                S3: next_state = (data==1) ? S4:S0;
                S4: next_state = (shift_counter==3'b100) ? S5:S4;
                S5: next_state = (done_counting==1) ? S6:S5;
                S6: next_state = (ack==1) ? S0:S6;
                default: next_state = S0;
            endcase
    end
    
    
    

endmodule
