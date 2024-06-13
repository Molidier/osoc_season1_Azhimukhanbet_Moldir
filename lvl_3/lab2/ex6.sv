module top_module (
    input clk,
    input reset,      // Synchronous reset
    input data,
    output [3:0] count,
    output counting,
    output done,
    input ack );
    
    typedef enum reg [2:0]{
    	S0 = 3'b000,
        S1 = 3'b001,
        S2 = 3'b010,
        S3 = 3'b011,
        S4 = 3'b100,
        S5 = 3'b101,
        S6 = 3'b110,
        S7 = 3'b111
    } states;
    
    states cur_state, next_state;
    
    logic [3:0] shift_counter;
    logic [3:0] delay;
    logic [13:0] timer;
    
    always @(posedge clk) begin
        if(reset) begin
            cur_state = S0;
            //del_const = 1000;
            shift_counter = 0;
            done = 0;
            counting = 0;
            delay = 4'b1101;
        end
        else begin
            cur_state = next_state;
            case(cur_state)
                S4: begin
                    delay = {delay[2:0], data};
                    shift_counter++;
                    timer = (delay)*1000;
                end
                S5: begin
                    timer--;
                    count = (timer/1000);
                    counting = 1;
                    done = 0;
                end
                S6: done = 1;
            endcase
        end
            
    end
    
    always @(*) begin
        case(cur_state)
            S0: next_state = (data==1) ? S1:S0;
            S1: next_state = (data==1) ? S2:S0;
            S2: next_state = (data==0) ? S3:S2;
            S3: next_state = (data==1) ? S4:S0;
            S4: next_state = (shift_counter==3'b100) ? S5:S4;
            S5: next_state = (timer==0) ? S6:S5;
            S6: next_state = (ack==1) ? S0:S6;
            default: next_state = S0;
        endcase
    end
    
    

endmodule
