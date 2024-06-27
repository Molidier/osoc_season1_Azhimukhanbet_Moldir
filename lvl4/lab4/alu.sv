/****** alu.sv ******/
typedef enum logic [2:0]{
    add = 3'b000; 
    sub = 3'b001;
    and = 3'b010;
    or =  3'b011;
    xor = 3'b100;
    shl = 3'b101;
    shr = 3'b110;
    cmp = 3'b111;

} sel_type

module alu(
    input sel_type select;
    input [15:0] in_a;
    input [15:0] in_b;

    output reg [16:0] alu_out;
);
    logic [16:0] res; 

    always @(*) begin
        case (select)
            add: res = in_a + in_b;
            sub: res = in_a - in_b;
            and: res = in_a & in_b;
            or:  res = in_a | in_b;
            xor: res = in_a ^ in_b;
            shl: res = in_a << in_b;
            shr: res = in_a >> in_b;
            cmp: begin
                if(in_a==in_b) begin
                    res = 0;
                end
                else if(in_a>in_b)begin
                    res = 1;
                end
                else begin
                    res = 2;
                end
            end
            default: res = 0;
        endcase
    end

    assign alu_out = res;

endmodule


