/* verilator lint_off MODDUP */
module bigger(
    input clk,
    input reset,
    input run,

    input rx_data_bit,
    output tx_data_bit,

    output [6:0] HEX0,
	output [6:0] HEX1,
	output [6:0] HEX2,

    output done,
    output [15:0] instr,
    output [15:0] d_out
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

    reg [1:0] cur_state, next_state;

    reg run_bitty;
    reg [15:0] mem_out; //instruction
    reg [7:0] addr;
    reg [7:0] new_pc;

    wire rx_done, tx_done;
    reg tx_en, rx_stop, tx_stop;
    reg [7:0] instr_hb, instr_lb;
    wire [7:0] recieved_data;
    genvar tx_count = 0;
    genvar rx_count = 0;

    branch_logic instance4(
        .address(addr),
        .instruction(mem_out),
        .last_alu_result(d_out),
        .new_pc(new_pc)
    );

    pc instance_pc(
        .clk(clk),
        .en_pc(done),
        .reset(reset),
        .d_in(new_pc),
        .d_out(addr)
    );

    uart_module uart_instance(
        .rx_data_bit(rx_data_bit), 
        .data_tx(addr), //memory address -> should be transmitted
        .CLOCK_50(clk),
        .rst(reset),
        .run(tx_en), //active-low

        .rx_done(rx_done),
        .data_bus(recieved_data) //recieved data -> 8bits
        .tx_done(tx_done),
        .tx_data_bit(tx_data_bit), //data to external device
        .HEX0(HEX0),
        .HEX1(HEX1),
        .HEX2(HEX2)
    );


    always @(*) begin
        run_bitty = 1'b0;
        tx_en = 1'b1; //en = 0
        tx_stop = 1'b0;
        rx_stop = 1'b0;
    
        case (cur_state)
            S0: begin
                tx_en = 1'b0; //en active
            end 
            S1: begin
                tx_en = 1'b1; //en inactive

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
                if (rx_done==1) begin
                    rx_count++;
                end
                if (rx_count==2) begin
                    rx_stop = 1'b1;
                end
            end
            S6:  run_bitty = 1;
            defaul: run_bitty = 0;
        endcase
    end


    always @(posedge clk) begin
        if(run) begin
            cur_state <= next_state;
          //$display("cur_state: ", cur_state);
          //$display("instr: ", instr);
        end
        if(reset || done) begin
            cur_state<= S0;
        end
    end

    always @(*) begin
        case(cur_state)
            S0: next_state = S1;
            S1: next_state = (tx_stop==1) ? S3:S2;
            S2: next_state = (tx_stop==1) ? S3:S2;
            S3: next_state = (rx_done==1) ? S4:S3;
            S4: next_state = (rx_stop==1) ? S5:S4;
            S5: next_state = S6;
            S6: next_state = S0;
            default: next_state = S0;
        endcase
    end

    bitty instance_bitty(
        .clk(clk),
        .reset(reset),
        .run(run_bitty),
        .d_instr(mem_out),
        .done(done),
        .d_out(d_out)
    );

    assign instr = mem_out;

  

endmodule
