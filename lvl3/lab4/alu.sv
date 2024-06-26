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
    input [2:0] rx;
    input [2:0] ry;

    output reg [2:0] result;
);
    logic [2:0] res; 

    always @(*) begin
        case (select)
            add: res = rx + ry;
            sub: res = rx - ry;
            and: res = rx & ry;
            or:  res = rx | ry;
            xor: res = rx ^ ry;
            shl: res = rx << ry;
            shr: res = rx >> ry;
            cmp: begin
                if(rx==ry) begin
                    res = 0;
                end
                else if(rx>ry)begin
                    res = 1;
                end
                else begin
                    res = 2;
                end
            end
            default: res = 0;
        endcase
    end

endmodule


