module top_module (
    input clk,
    input reset,      // Synchronous reset
    input data,
    output [3:0] count,
    output counting,
    output done,
    input ack );
    
typedef enum reg[2:0]{
    	S0 = 3'b000,
        S1 = 3'b001,
        S2 = 3'b010,
        S3 = 3'b011,
        S4 = 3'b100,
        S5 = 3'b101,
        S6 = 3'b110,
    	S7 = 3'b111
    } states;
    
    logic [3:0] shift_counter;
    states cur_state, next_state;
    logic signed [3:0] delay;
    logic [9:0] q;
    logic stop;
    logic [13:0] temp;
    logic lol;
    
    /*
    0000 1
    0000 2
    0000 3
    0001 4
    */
    /*always @(posedge clk) begin
        if(next_state==S4) begin
    		delay <= {delay[2:0], data};
            shift_counter <= shift_counter + 3'b001;
        end
    end*/
    
    always @(posedge clk) begin
        if(reset) begin
            cur_state = S0;
            counting = 0;
            done = 0;
            shift_counter <=0;
            stop = 0;
            q<=10'b0000000000;
            //delay <= 4'b0000;
        end
        else begin
            cur_state = next_state;
            if(cur_state==S4) begin
               count = {count[2:0], data};
               shift_counter <= shift_counter + 3'b001;
            end
            else begin
                shift_counter <= 3'b0;
                delay = 4'b0;
            end

            if(cur_state==S5) begin
               count = {count[2:0],data};
               counting = 1;
               done = 0;
               temp <=(count + 1)*1000 - 1;
            end

            if(cur_state==S6) begin
                temp <= temp - 1;

                if (q==10'b1111100111) begin
                   q<= 10'b0;
                   	   count=count - 4'b0001;
                       stop = 0;
               end
               else begin
                   q<= q + 10'b0000000001;
               end

                counting = 1;
                done = 0;
            end

            if(cur_state==S7) begin
                counting = 0;
                done = 1;
                q<= 10'b0;
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
                S5: next_state = S6;
                S6: next_state = (temp==0) ? S7:S6;
                S7: next_state = (ack==1) ? S0:S7;
              
                default: next_state = S0;
            endcase
    end
    

    

endmodule
