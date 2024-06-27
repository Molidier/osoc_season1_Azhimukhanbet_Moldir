module cpu(
    input clk,
    input run,
    input reset,
    input [15:0] d_inst,

    output reg [3:0] mux_sel,
    output reg done,

    output reg [3:0] sel,
    output reg en_s,
    output reg en_c,
    output reg [7:0] en,
    output reg en_inst
);

    typedef enum reg [1:0] { 
        S0 = 2'b00,
        S1 = 2'b01,
        S2 = 2'b11
    } states;

    states cur_state, next_state;

    always @(*) begin
        // Default values to avoid latches
        if(reset == 1) begin
            en_s = 0;
            en_c = 0;
            done = 0;
            mux_sel = 4'b0;
            sel = 4'b0;
            en = 8'b0;
            en_inst = 0;
        end

        if(run == 1) begin
            case (cur_state)
                S0: begin
                    en_s = 1;
                    mux_sel = {1'b0, d_inst[15:13]};
                end
                S1: begin
                    mux_sel = {1'b0, d_inst[12:10]};
                    en_c = 1;
                    sel = d_inst[4:2];
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
                    en = 8'b0;
                end
            endcase
        end
    end

    // Next state sequential logic
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            cur_state <= S0;
        end else begin
            cur_state <= next_state;
        end
    end

    // Next state combinational logic
    always @(*) begin
        case (cur_state)
            S0: next_state = S1;
            S1: next_state = S2;
            S2: next_state = (done == 1) ? S0 : S2;
            default: next_state = S0;
        endcase
    end

endmodule
