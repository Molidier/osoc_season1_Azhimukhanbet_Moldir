module uart_state(
    input clk,
    input [7:0] address,
    input rx,
    input done,

    output reg tx,
    output reg [7:0] d_out

);

    parameter S0 = 4'b0000;
    parameter S1 = 4'b0001;
    parameter S2 = 4'b0010;
    parameter S3 = 4'b0011;
    parameter S4 = 4'b0100;
    parameter S5 = 4'b0101;
    parameter S6 = 4'b0110;
    parameter S7 = 4'b0111;
    parameter S8 = 4'b1000;
    parameter S9 = 4'b1001;


    wire  tx_done, rx_done;
    reg tx_en, tx_stop, rx_stop;
    genvar tx_count = 0;
    genvar rx_count = 0;

    
    uart u_inst(
        .clk(clk),
        .tx_en(tx_en),
        .tx_data(address),
        .tx(tx),
        .tx_done(tx_done),
        .rx(rx),
        .rx_done(rx_done),
        .rx_data(d_out)
    )

    reg [3:0] cur_state, next_state;

    always @(*) begin
        tx_stop = 1'b0;
        rx_stop = 1'b0;

        case (cur_state)
            S0: begin
                tx_en = 1;
            end
            S1: begin
                if (tx_done & done = 0) begin
                    tx_stop = 1'b1;
                end
                else if (tx_done & done = 1)begin
                    tx_stop = 1'b0;
                    tx_count++;
                end
            end 
            S2: begin
                if (tx_done & done = 1)begin
                    tx_stop = 1'b0;
                    tx_count++;
                end
                if(tx_count==2) begin
                    tx_stop = 1'b1;
                end
            end
            S3: begin
                if (rx_done==1) begin
                    rx_count++;
                end
            end
            S4: begin
                if (rx_count==2) begin
                    rx_stop = 1'b1;
                end
            end

            default: 
        endcase
    end

    always @(posedge clk) begin
        case (cur_state)
            S0: next_state = S1;
            S1: next_state = (tx_stop==1) ? S3:S2;
            S2: next_state = (tx_stop==1) ? S3:S2;
            S3: next_state = (rx_done==1) ? S4:S3;
            S4: next_state = (rx_stop==1) ? S0:S4;
            default: next_state = S0;
        endcase
    end

endmodule