module uart(
    input clk,            // System clock
    input tx_en,          // Enable transmission
    input [7:0] tx_data,  // Data to transmit
    output reg tx,        // UART transmit line
    output reg tx_done,   // Transmission done flag
    input rx,             // UART receive line
    output reg rx_done,   // Reception done flag
    output reg [7:0] rx_data // Data received
);
    reg [3:0] tx_bit_count = 0;
    reg [9:0] tx_shift_reg;
    reg sending = 0;
    
    reg [3:0] rx_bit_count = 0;
    reg [7:0] rx_shift_reg;
    reg receiving = 0;

    // Transmission logic
    always @(posedge clk) begin
        if (tx_en && !sending) begin
            // Start transmission (start bit = 0)
            tx_shift_reg <= {1'b1, tx_data, 1'b0}; // stop bit, data, start bit
            tx_bit_count <= 0;
            sending <= 1;
            tx_done <= 0;
        end else if (sending) begin
            tx <= tx_shift_reg[tx_bit_count];
            tx_bit_count <= tx_bit_count + 1;
            if (tx_bit_count == 9) begin
                sending <= 0;
                tx_done <= 1;
            end
        end
    end

    // Reception logic
    always @(posedge clk) begin

        if (!receiving && !rx) begin // Detect start bit (0)
            receiving <= 1;
            rx_bit_count <= 0;
            rx_done <= 0;
        end else if (receiving) begin
            rx_shift_reg[rx_bit_count] <= rx;
            rx_bit_count <= rx_bit_count + 1;
            if (rx_bit_count == 7) begin
                receiving <= 0;
                rx_done <= 1;
                rx_data <= rx_shift_reg;
            end
        end
    end
	 
endmodule