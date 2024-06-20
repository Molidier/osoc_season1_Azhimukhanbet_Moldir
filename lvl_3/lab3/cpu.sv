module cpu(
    input [15:0] run,
    input clk,
    input reset,
    input carry_in;

    output mux_sel [3:0],
    output done,

    output d_out,

    output wire [3:0] sel,
    output wire mode,
    output wire en_s,
    output wire en_c,
    output wire [7:0] en;
    output en_inst,
    //gonna be deleted after fixing alu
    output compare;
    output carry_out;
);

    logic [15:0] out_alu, out_mux, out_s, out_inst, out_0, out_1, out_2, out_3, out_4, out_5, out_6, out_7;
    mux(
    .clk(clk),
    .mu_sel(mux_sel),
    .en(en),
    .d_in(d_in),
    .d_out(out_mux)
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
                    en = 8'b00100000;
                endcase
            end
            
            default: 
        endcase
    end

    //Next state sequential logic
    always @(posedge clk)begin
        if(reset) begin
            cur_state <= S0;
            en = 8'b0;
            en_c = 0;
            en_s = 0;
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