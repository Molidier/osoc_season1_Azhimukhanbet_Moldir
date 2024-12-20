//UART TX
module uart_tx 
#(
    parameter data_width   = 8,
              CLKS_PER_BIT = 5208, // 50 MHz / 9600 = 5208.
              IDLE         = 3'b000,
              START_BIT    = 3'b001,
              DATA_BITS    = 3'b010, 
              STOP_BIT     = 3'b011,
              DONE         = 3'b101
) 
(
    input [data_width - 1:0] data_bus,
    input                    clk,
    input                    rstn, 
	input                    run,
	/* output                   in_idle,
	 output                   transmitting,*/
    output                   done,
    output                   data_bit
);

    // FSM states.
    reg [2:0] PS;
    reg [2:0] NS;

    reg [12:0] clk_counter;
    reg [2:0]  bit_counter;
    reg        data_reg;
	 
	 assign in_idle      = PS == IDLE;
	 assign transmitting = PS != IDLE;
	 assign done         = PS == DONE;
    
    // FSM: PS syncronization.
    always @(posedge clk, negedge rstn) begin
        if (!rstn) begin
            PS <= IDLE;
        end
        else begin
            PS <= NS;
        end
    end

    // FSM: PS control logic.
    always @(negedge clk) begin
        case (PS)
            IDLE: begin
                bit_counter <= 0;
                clk_counter <= 0;
                if (!run) begin
                    NS <= START_BIT;
                end
                else begin
                    NS <= IDLE;
                end
            end

            START_BIT: begin
					 data_reg <= 1'b0;
                if (clk_counter < CLKS_PER_BIT - 1) begin
                    clk_counter <= clk_counter + 1;
                    NS <= START_BIT;
                end
                else begin
                    NS <= DATA_BITS;
                    clk_counter <= 0;
                end
            end

            DATA_BITS: begin
                data_reg <= data_bus[bit_counter];

                if (clk_counter < CLKS_PER_BIT - 1) begin
                    clk_counter <= clk_counter + 1;
                    NS <= DATA_BITS;
                end
                else begin
                    clk_counter <= 0;

                    if (bit_counter < 7) begin
                        bit_counter <= bit_counter + 1;
                        NS <= DATA_BITS;
                    end
                    else begin
                        NS <= STOP_BIT;
                    end
                end
            end

            STOP_BIT: begin
                data_reg <= 1'b1;
                if (clk_counter < CLKS_PER_BIT - 1) begin
                    clk_counter <= clk_counter + 1;
                    NS <= STOP_BIT;
                end
                else begin
                    NS <= DONE;
                    clk_counter <= 0;
                end
            end
				
				DONE: begin
					NS <= IDLE;
				end

            default: begin
                data_reg <= 1'b1;
                clk_counter <= 0;
                bit_counter <= 0;
            end
        endcase
    end



    assign data_bit = data_reg;

endmodule