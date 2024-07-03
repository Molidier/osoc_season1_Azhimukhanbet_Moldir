import "DPI-C" function void notify_counter_nine_1();
import "DPI-C" function void notify_counter_nine_2();
import "DPI-C" function void notify_counter_nine_3();




module cpu(
    input clk,
    input run,
    input reset,
    input [15:0] d_inst,

    output reg [2:0] mux_sel,
    output reg done,

    output reg [2:0] sel,
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
            mux_sel = 3'b0;
            sel = 3'b0;
            en = 8'b0;
            en_inst = 0;
            
        end

        else if(run == 1) begin
            en_inst = 1;
            en_s = 0;
            en_c = 0;
            done = 0;
            mux_sel = 3'b0;
            sel = 3'b0;
            en = 8'b0;
            case (cur_state)
                S0: begin
                    en_s = 1;
                    mux_sel = d_inst[15:13];
                    done = 0;
                    en_inst = 1;

                   // notify_counter_nine_1();
                end
                S1: begin
                    mux_sel = d_inst[12:10];
                    en_c = 1;
                    sel = d_inst[4:2];
                    en_inst = 0;

                    //notify_counter_nine_2();

                end
                S2: begin
                    //en = 8'b0;
                    en[d_inst[15:13]] = 1;
                    done = 1;

                   //  notify_counter_nine_3();
                end
                default: begin
                    en_s = 0;
                    en_c = 0;
                    done = 0;
                    mux_sel = 3'b0;
                    sel = 3'b0;
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
       // notify_counter_nine_here();
        //cur_state <= next_state;
    end

    // Next state combinational logic
    always @(*) begin
        case (cur_state)
            S0: next_state = (en_s==1) ? S1:S0;
            S1: next_state = (en_c==1) ? S2:S1;
            S2: next_state = (done == 1) ? S0 : S2;
            default: next_state = S0;
        endcase
    end

endmodule
