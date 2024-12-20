module fifo #(
    parameter DATA_WIDTH = 8,  // Width of data (e.g., 8-bit for UART)
    parameter FIFO_DEPTH = 16  // Depth of FIFO (number of storage locations)
)(
    input wire clk,                // Clock input
    input wire rst,                // Reset signal (active high)
    input wire wr_en,              // Write enable signal
    input wire rd_en,              // Read enable signal
    input wire [DATA_WIDTH-1:0] din, // Data input
    output reg [DATA_WIDTH-1:0] dout, // Data output
    output reg full,               // FIFO full flag
    output reg empty               // FIFO empty flag
);

    // Memory array to store the data
    reg [DATA_WIDTH-1:0] fifo_mem [FIFO_DEPTH-1:0];

    // Read and write pointers
    reg [$clog2(FIFO_DEPTH)-1:0] wr_ptr, rd_ptr;

    // Counter to track the number of elements in the FIFO
    reg [$clog2(FIFO_DEPTH):0] fifo_count;

    // Sequential logic to handle FIFO operations
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            // Reset the FIFO
            wr_ptr <= 0;
            rd_ptr <= 0;
            fifo_count <= 0;
            full <= 0;
            empty <= 1;
        end else begin
            // Write operation
            if (wr_en && !full) begin
                fifo_mem[wr_ptr] <= din;
                wr_ptr <= wr_ptr + 1;
                fifo_count <= fifo_count + 1;
            end

            // Read operation
            if (rd_en && !empty) begin
                dout <= fifo_mem[rd_ptr];
                rd_ptr <= rd_ptr + 1;
                fifo_count <= fifo_count - 1;
            end

            // Update full and empty flags
            full <= (fifo_count == FIFO_DEPTH);
            empty <= (fifo_count == 0);
        end
    end
endmodule
