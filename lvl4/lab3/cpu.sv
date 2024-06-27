module cpu(
    input clk,
    input run,
    input reset,
    input [15:0] d_inst,

    output reg [3:0] mux_sel,
    output reg done,

    output reg [3:0] sel,
    output reg mode,
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

    // Next state combinational logic
    always @(*) begin
        case (cur_state)
            S0: next_state = (run==1) ? S1 : S0;
            S1: next_state = (run==1) ? S2 : S0;
            S2: next_state = (run == 1) ? S0 : S2;
            default: next_state = S0;
        endcase
    end

    // State update sequential logic
    always @(posedge clk) begin
        if (reset) begin
            cur_state <= S0;
        end else begin
            cur_state <= next_state;
        end
    end

    // Output combinational logic
    always @(*) begin
        // Default values to avoid latches
        en_s = 0;
        en_c = 0;
        done = 0;
        mux_sel = 4'b0;
        sel = 4'b0;
        mode = 0;
        en = 8'b0;
        en_inst = 0;

        if (reset) begin
            // Reset values
            en_s = 0;
            en_c = 0;
            done = 0;
            mux_sel = 4'b0;
            sel = 4'b0;
            mode = 0;
            en = 8'b0;
            en_inst = 0;
        end
        if (run == 1) begin
            en_inst = 1;
            case (cur_state)
                S0: begin
                    done = 0;
                    en_s = 1;
                    en = 8'b0;
                    en_c = 0;
                    mux_sel = {1'b0, d_inst[15:13]};
                    en_inst = 0;
                end
                S1: begin
                    mux_sel = {1'b0, d_inst[12:10]};
                    en_c = 1;
                    en_s = 0;
                    en = 8'b0;
                    sel = d_inst[6:3];
                    mode = d_inst[2];
                    done = 0;
                    en_inst = 0;
                end
                S2: begin
                    en = 8'b0;
                    en[d_inst[15:13]] = 1;
                    done = 1;
                    en_inst = 0;
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
            endcase
        end
    end

endmodule
