/******* fetch_unit.sv ****/
module memory(
    input clk,
    input [7:0] addr,
    output reg [15:0] out
);
    reg [15:0] memory_array [0:255]; // 256 instructions each with 16 bits
    initial begin
        $readmemh("instructions.txt", memory_array);
    end

    always @(posedge clk) begin
        out <= memory_array[addr];
    end
endmodule

module pc(
    input clk,
    input en_pc,
    input reset,
    input [7:0] d_in,
    output reg [7:0] d_out
);

    always @(posedge clk) begin
        if (reset) begin
            d_out <= 8'b0;
        end else if (en_pc) begin
            d_out <= d_in;
        end
    end

endmodule

module branch_logic (
    input [7:0] address,
    input [15:0] instruction,
    input [15:0] last_alu_result,
    input done,
    output reg [7:0] new_pc
);
    typedef enum logic { 
        S0 = 0,
        S1 = 1
    } states;

    states cur_state, next_state;

    logic [1:0] branch_cond;
    logic [7:0] immediate;
    assign branch_cond = instruction[3:2];
    assign immediate = instruction[11:4];

    always @(*) begin
        case(branch_cond)
        2'b00: begin
            if (last_alu_result == 0) begin
                new_pc = immediate;
            end else begin
                new_pc = address + 1;
            end
        end
        2'b01: begin
            if (last_alu_result == 1) begin
                new_pc = immediate;
            end else begin
                new_pc = address + 1;
            end  
        end
        2'b10: begin
            if (last_alu_result == 2) begin
                new_pc = immediate;
            end else begin
                new_pc = address + 1;
            end  
        end
        default: begin
            new_pc = address + 1;
        end
        endcase
    end

    always @(posedge done) begin
        cur_state <= next_state;
    end

    always @(*) begin
        case(cur_state)
            S0: next_state = (done == 1) ? S1 : S0;
            S1: next_state = S0;
            default: next_state = S0;
        endcase
    end
endmodule
