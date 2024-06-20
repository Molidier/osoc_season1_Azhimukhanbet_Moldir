/* verilator lint_off DECLFILENAME */
module logic_unit #(
/* verilator lint_on DECLFILENAME */
    parameter WIDTH = 16
) (
    input wire [WIDTH-1:0] in_a,
    input wire [WIDTH-1:0] in_b,
    input wire [3:0]       select,
    output wire [WIDTH-1:0] logic_out
    
);

    logic [WIDTH-1:0] res;

    always_comb begin
        case (select)
            4'h0: res = ~in_a;
            4'h1: res = ~(in_a | in_b); 
            4'h2: res = ~in_a & in_b; 
            4'h3: res = 16'h0; 
            4'h4: res = ~(in_a & in_b); 
            4'h5: res = ~in_b; 
            4'h6: res = in_a ^ in_b; 
            4'h7: res = in_a & ~in_b; 
            4'h8: res = ~in_a | in_b; 
            4'h9: res = ~(in_a ^ in_b); 
            4'hA: res = in_b; 
            4'hB: res = in_a & in_b; 
            4'hC: res = 16'h1; 
            4'hD: res = in_a | ~in_b; 
            4'hE: res = in_a | in_b; 
            4'hF: res = in_a; 
            default: res = 16'h0;
        endcase
    end
    /*
    0000 0000 0000 1000
    0000 0000 0000 1001
    
    0000 0000 0000 1001
    */

    assign logic_out = res;

endmodule

module arithmetic #(
    parameter WIDTH = 16
) (
    input wire carry_in,
    input wire [WIDTH-1:0] in_a,
    input wire [WIDTH-1:0] in_b,
    input wire [3:0]       select,
    output wire cmp,
    output wire carry_out,
    output wire [WIDTH-1:0] arithmetic_out
);

    logic [WIDTH:0] extended_res;
    assign carry_out = 0;

    
                /*
                0000 0000 0000 1010
                0000 0000 0000 1001

                01111 1111 1111 0110
            or  00000 0000 0000 1010
                01111 1111 1111 1110

                */

    always_comb begin
        case (select)
            4'h0: extended_res = {1'b0, in_a}; // Extend in_a to 17 bits
            4'h1: extended_res = {1'b0, in_a} | {1'b0, in_b}; // Extend both to 17 bits
            4'h2: extended_res = {1'b0, in_a} | {1'b0, ~in_b}; // Extend both to 17 bits
            4'h3: extended_res = ~{{WIDTH{1'b0}}, 1'b1} + 1; // 17-bit zero
            4'h4: extended_res = {1'b0, in_a} | ({1'b0, in_a} & {1'b0, ~in_b}); // Extend all to 17 bits
            4'h5: extended_res = {1'b0, (in_a | in_b) + (in_a & ~in_b)} + {{WIDTH{1'b0}}, carry_in};
            4'h6: extended_res = {1'b0, in_a} + {1'b0, ~in_b}; // Extend both to 17 bits
            4'h7: extended_res = {1'b0, in_a & ~in_b}; // Extend to 17 bits
            4'h8: extended_res = {1'b0, in_a} + {1'b0, in_a & in_b} + {{WIDTH{1'b0}}, carry_in}; // Extend to 17 bits
            4'h9: extended_res = {1'b0, in_a} + {1'b0, in_b} + {{WIDTH{1'b0}}, carry_in}; // Extend to 17 bits
            4'hA: extended_res = {1'b0, in_a | ~in_b} + {1'b0, in_a & in_b} + {{WIDTH{1'b0}}, carry_in}; // Extend to 17 bits
            4'hB: extended_res = {1'b0, in_a & in_b}; // Extend to 17 bits
            4'hC: extended_res = {1'b0, in_a} + {1'b0, in_a} + {{WIDTH{1'b0}}, carry_in}; // Extend to 17 bits
            4'hD: extended_res = {1'b0, in_a | in_b} + {1'b0, in_a} + {{WIDTH{1'b0}}, carry_in}; // Extend to 17 bits
            4'hE: extended_res = {1'b0, in_a | ~in_b} + {1'b0, in_a} + {{WIDTH{1'b0}}, carry_in}; // Extend to 17 bits
            4'hF: extended_res = {1'b0, in_a} + {{WIDTH{1'b0}}, carry_in}; // Extend to 17 bits
            default: extended_res = {WIDTH+1{1'b0}}; // 17-bit zero
        endcase
    end
    /*
    
    0000 0000 0000 0001

    1111 1111 1111 1110
    0000 0000 0000 0011
    1111 1111 1111 1111

    0001
    0111
    
    1000
    0001

    1001
    0001
    1010
    */

    assign arithmetic_out = extended_res[WIDTH-1:0];
    assign carry_out = extended_res[WIDTH];
    assign cmp = (in_a == in_b) ? 1 : 0;

endmodule

module alu #(
    parameter WIDTH = 16
) (
    //input clk,
    //input rst,

    //input  operation_t  op_in, //instead of select ig -> could it be used?
    input  wire         carry_in,
    input  wire [WIDTH-1:0]  a_in,
    input  wire [WIDTH-1:0]  b_in,
    input  wire [3:0]        select,
    input  wire              mode,
    
    output wire              carry_out,
    output wire              compare,
    output wire [WIDTH-1:0]  alu_out
);

    logic [WIDTH-1:0] res;
    logic [WIDTH-1:0] logic_res;
    logic [WIDTH-1:0] arithmetic_res;
    logic car_out, car_arith;
    logic cmp, cmp_ari;

    logic_unit u1 (
        .in_a(a_in),
        .in_b(b_in),
        .select(select),
        .logic_out(logic_res)
    );

    arithmetic u2 (
        .in_a(a_in),
        .in_b(b_in),
        .select(select),
        .carry_in(carry_in),
        .arithmetic_out(arithmetic_res),
        .cmp(cmp_ari),
        .carry_out(car_arith)
    );
    always begin
        if(a_in == b_in) begin
            cmp = 1;
        end
        else begin
            cmp = 0;
        end
    end


    always_comb begin
        if(mode == 1) begin
            res = logic_res;
            car_out = 0;
        end else begin
            res = arithmetic_res;
            cmp = cmp_ari;
            car_out = car_arith;
        end
    end

    assign carry_out = car_out;
    assign alu_out = res;
    assign compare = cmp;

endmodule
