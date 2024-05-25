/*
 * Primitive alu example for Verilator example
 *
 * File name: alu.sv
 * Author: Norbertas Kremeris 2021
 *
 */


module alu #(
        parameter WIDTH = 16
) (
        //input clk,
        //input rst,

        //input  operation_t  op_in, //instead of select ig -> could it be used?
        input  wire         carry_in;
        input  wire [WIDTH-1:0]  a_in,
        input  wire [WIDTH-1:0]  b_in,
        input  wire [3:0]        select,
        input  wire              mode,
        
        output wire              carry_out,
        output wire              compare;
        output wire [WIDTH-1:0]        alu_out
);
        logic [WIDTH-1:0] res;
        logic car_out;
        logic cmp;


        always_alu begin
            if(mode==0) begin
                logic o1(
                    .in_a(in_a),
                    .in_b(in_b),
                )

      /*   operation_t  op_in_r;
        logic  [WIDTH-1:0]  a_in_r;
        logic  [WIDTH-1:0]  b_in_r;
        logic               in_valid_r;
        logic  [WIDTH-1:0]  result; */

/*         // Register all inputs
        always_ff @ (posedge clk, posedge rst) begin
                if (rst) begin
                        op_in_r     <= '0;
                        a_in_r      <= '0;
                        b_in_r      <= '0;
                        in_valid_r  <= '0;
                end else begin
                        op_in_r    <= op_in;
                        a_in_r     <= a_in;
                        b_in_r     <= b_in;
                        in_valid_r <= in_valid;
                end
        end

        // Compute the result
        always_comb begin
                result = '0;
                if (in_valid_r) begin
                        case (op_in_r)
                                add: result = a_in_r + b_in_r;
                                sub: result = a_in_r + (~b_in_r+1'b1);
                                default: result = '0;
                        endcase
                end
        end */

/*         // Register outputs
        always_ff @ (posedge clk, posedge rst) begin
                if (rst) begin
                        out       <= '0;
                        out_valid <= '0;
                end else begin
                        out       <= result;
                        //out       <= 6'h5;//result;
                        out_valid <= in_valid_r;
                end
        end */

endmodule;

module logic #(
        parameter WIDTH = 16;
    )(
        input wire [WIDTH-1:0] in_a;
        input wire [WIDTH-1:0] in _b;
        input wire [3:0]       select;

        output wire [WIDTH-1:0] logic_out;
    )

       logic [WIDTH-1:0] res;

       always_log begin
            case (select):
                4'h0: res = ~A;
                4'h1: res = ~(A | B); 
                4'h2: res = ~A & B; 
                4'h3: res = 4'h0; 
                4'h4: res = ~(A & B); 
                4'h5: res = ~B; 
                4'h6: res = A ^ B; 
                4'h7: res = A & ~B ; 
                4'h8: res = ~A | B; 
                4'h9: res = ~(A ^ B); 
                4'hA: res = B; 
                4'hB: res = A&B; 
                4'hC: res = 4'h1; 
                4'hD: res = A | ~B; 
                4'hE: res = A | B; 
                4'hF: res = A; 
                default: res = 4h'0;
            endcase
       end

       assign logic_out = res;

endmodule;

module arithmetic #(
        parameter WIDTH = 16;
    )(
        input wire carry_in;
        input wire [WIDTH-1:0] in_a;
        input wire [WIDTH-1:0] in _b;
        input wire [3:0]       select;

        output wire cmp;
        output wire carry_out;
        output wire [WIDTH-1:0] logic_out;

    )

       logic [WIDTH-1:0] res;
       logic wire car_out;

       always_arith begin
            case (select):
                4'h0: res = A;
                4'h1: res = A | B; 
                4'h2: res = A | ~B; 
                4'h3: {car_out,res} = ~(4'h1)+1'b1; 
                4'h4: res = A | (A&~B); 
                4'h5: {car_out,res} = (A|B) + A&~B;
                4'h6: res = (A + (~(B)+1) + (~(4'h1)+1'b1));; 
                4'h7: res = A&~B + (~(4'h1)+1'b1); 
                4'h8: {car_out,res} = A + A&B; 
                4'h9: {car_out,res} = A + B; 
                4'hA: {car_out,res} = (A|~B) + A&B; 
                4'hB: res = A&B + (~(4'h1)+1'b1); 
                4'hC: {car_out,res} = A + A; 
                4'hD: {car_out,res} = (A|B) + A; 
                4'hE: {car_out,res} = (A|~B) + A; 
                4'hF: res = A + (~(4'h1)+1'b1); 
                default: res = 4h'0;
            endcase
       end

       assign logic_out = res;

endmodule;
