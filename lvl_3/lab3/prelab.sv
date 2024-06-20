module prelab (
    input clk, 
    input reset, // Asynchronous reset
    output reg [2:0] light // Traffic light output : 3'b001 (RED), 3'b010 (GREEN), 3'b100 (YELLOW)
);

    parameter RED = 2'b00;
    parameter GREEN = 2'b01;
    parameter YELLOW = 2'b10;
    parameter CLOCK_FREQ = 50;
    parameter DURATION = 5;
/* verilator lint_off UNOPTFLAT */
    reg [31:0] counter; // Adjusted to 32 bits
    reg [1:0] current_state, next_state;

    // Model state register (sequential logic)
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            current_state <= RED;
            /* verilator lint_off BLKSEQ */
            counter =  0;
        end else begin
            current_state <= next_state;
            counter =  counter + 1;
        end
    end

    // Model next state decode logic (combinational logic)
    always @(*) begin
        case (current_state)
            RED: begin
                if (counter == CLOCK_FREQ * DURATION * 10) begin
                    next_state = GREEN;
                    counter =  0; // Reset counter
                end else begin
                    next_state = RED;
                end
            end
            GREEN: begin
                if (counter == CLOCK_FREQ * DURATION * 10) begin
                    next_state = YELLOW;
                    counter =  0; // Reset counter
                end else begin
                    next_state = GREEN;
                end
            end
            YELLOW: begin
                if (counter == CLOCK_FREQ * DURATION) begin
                    next_state = RED;
                    counter =  0; // Reset counter
                end else begin
                    next_state = YELLOW;
                end
            end
            default: begin
                next_state = RED;
                counter =  0; // Reset counter
            end
        endcase
    end

    // Model output logic (combinational logic)
    always @(*) begin
        case (current_state)
            RED: begin
                light = 3'b001; // RED light
            end
            GREEN: begin
                light = 3'b010; // GREEN light
            end
            YELLOW: begin
                light = 3'b100; // YELLOW light
            end
            default: begin
                light = 3'b001; // default to RED light
            end
        endcase
    end

endmodule
