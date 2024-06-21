module cpu(
    input clk,
    input run,
    input reset,
    input [15:0] d_inst,

    output mux_sel [3:0],
    output done,

    output wire [3:0] sel,
    output wire mode,
    output wire en_s,
    output wire en_c,
    output wire [7:0] en,
    output en_inst,

);

    typedef enum reg[1:0] { 
        S0 = 2'b00;
        S1 = 2'b01;
        S2 = 2'b11;
    } states;

    states cur_state, next_state;

    always @(*) begin
        case (cur_state)
            S0: begin
                en_s <= 1;
                mux_sel <= {1'b0, d_inst[15:13]} + 1;
            end
            S1: begin
                mux_sel <= {1'b0, d_inst[12:10]} + 1;
                en_c <= 1;
                sel <= d_inst[6:3];
                mode <= d_inst[2];
            end
            S2: begin
                en = 8'b0;
                en[d_inst[15:13]] = 1;
                done = 1;
            end
            default: begin
                en_s = 0;
                en_c = 0;
                done = 0;
                mux_sel = 4'b0;
                sel = 4'b0;
                mode = 0;
                en = 8'b0;
            end
            
            default: 
        endcase
    end

    //Next state sequential logic
    always @(posedge clk)begin
        if(reset) begin
            cur_state <= S0;
            en_s = 0;
            en_c = 0;
            done = 0;
            mux_sel = 4'b0;
            sel = 4'b0;
            mode = 0;
            en = 8'b0;
        end
        else begin
            cur_state <= next_state;
        end
    end

    //Next state combinational logic
    always @(*) begin
        case (cur_state)
            S0: next_state = S1;
            S1: next_state = S2;
            S2: next_state = (done==1) ? S0 : S2;
            default: next_state = S0;
        endcase
    end
    

endmodule