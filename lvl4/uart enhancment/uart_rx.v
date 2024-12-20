/* Copyright (c) 2023 Kabylkas Labs. All rights reserved. */

module uart_rx 
#(
    parameter data_width   = 8,
              CLKS_PER_BIT = 5208, // 50 MHz / 9600 = 5208.
              IDLE         = 3'b000,
              START_BIT    = 3'b001,
              DATA_BITS    = 3'b010, 
              STOP_BIT     = 3'b011,
              DONE         = 3'b101,
				  ERROR_ST     = 3'b110
) 
(
    input                     data_bit,
    input                     clk,
    input                     rst,
	/*output                    in_idle,
	 output                    error,
	 output                    receiving,*/
    output                    done,
    output [data_width - 1:0] data_bus
);

    // FSM states.
    reg [2:0] PS;
    reg [2:0] NS;

    // Internal nets.
    reg [2:0]  bit_counter;
    reg [12:0] clk_counter;
    reg [data_width - 1:0] data_bus_wire; 
	 
	 /*assign in_idle   = PS == IDLE;
	 assign error     = PS == ERROR_ST;*/
	 assign receiving = PS != IDLE;
	 assign done      = PS == DONE;


    // FSM: PS syncronization.
    always @(posedge clk, negedge rst) begin
        if (!rst) begin
            PS <= IDLE;
        end
        else begin
            PS <= NS;
        end
    end

    // FSM.
    always @(negedge clk) begin
        case (PS)
            IDLE: begin
              clk_counter <= 0;
              bit_counter <= 0;

              if (data_bit == 1'b0) begin
                NS <= START_BIT;
              end
              else begin
                NS <= IDLE;
              end
            end

            START_BIT: begin
                if (clk_counter == CLKS_PER_BIT / 2) begin
                    if (data_bit == 1'b0) begin
                        NS <= DATA_BITS;
                        clk_counter <= 0;
                    end
                    else begin
                        NS <= ERROR_ST;
                    end
                end
                else begin
                    clk_counter <= clk_counter + 1;
                    NS <= START_BIT;
                end
            end

            DATA_BITS: begin
                if (clk_counter < CLKS_PER_BIT - 1) begin
                    clk_counter <= clk_counter + 1;
                    NS <= DATA_BITS;
                end
                else begin
                    clk_counter <= 0;
                    data_bus_wire[bit_counter] <= data_bit;

                    if (bit_counter < 7) begin
                        NS <= DATA_BITS;
                        bit_counter <= bit_counter + 1;
                    end
                    else begin
                        NS <= STOP_BIT;
                    end
                end
            end

            STOP_BIT: begin
                if (clk_counter < CLKS_PER_BIT - 1) begin
                    clk_counter <= clk_counter + 1;
                    NS <= STOP_BIT;
                end
                else begin
                    clk_counter <= 0;
                    NS <= DONE;
                end
            end
				ERROR_ST: begin
					NS <= ERROR_ST;
				end
					
				DONE: begin
					NS <= IDLE;
				end


            default: begin
                bit_counter <= 0;
                clk_counter <= 0;
                data_bus_wire <= 0;
                NS <= IDLE;
            end
        endcase
    end

    assign data_bus = data_bus_wire;


endmodule