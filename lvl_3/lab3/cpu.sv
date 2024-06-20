module cpu(
    input [15:0] run,
    input clk,
    input reset,
    input carry_in;

    output mux_sel [3:0],
    output done,

    output d_out,

    output [3:0] sel,
    output mode,
    output en_s,
    output en_c,
    output en_0,
    output en_1,
    output en_2,
    output en_3,
    output en_4,
    output en_5,
    output en_6,
    output en_7,
    output en_inst,
    //gonna be deleted after fixing alu
    output compare;
    output carry_out;
);

    logic [15:0] out_alu, out_mux, out_s, out_inst, out_0, out_1, out_2, out_3, out_4, out_5, out_6, out_7;
    mux(
    clk,
    mux_sel,
    en_0,
    en_1,
    en_2,
    en_3,
    en_4,
    en_5,
    en_6,
    en_7,
    d_in,
    out_mux
);
    dff reg_s (clk, en_s, out_mux, out_s);

    alu alu_instance(
    carry_in,
    out_s,
    out_mux,
    sel,
    mode,

    carry_out,
    compare,
    out_alu
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
                mux_sel <= {1'b0, run[15:13]} + 1;
            end
            S1: begin
                mux_sel <= {1'b0, run[12:10]} + 1;
                en_c <= 1;
                sel <= run[6:3];
                mode <= run[2];
            end
            S2: begin
                case(run[15:13])
                    
                endcase
            end
            
            default: 
        endcase
    end

    //Next state sequential logic
    always @(posedge clk)begin
        if(reset) begin
            cur_state <= S0;
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