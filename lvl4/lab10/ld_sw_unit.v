//states handled here -> for UART model
//

module ld_sw_unit(

    input [15:0] data_ld,
    input [15:0] addr_to_sw,
    input sw_en,
    input ld_en,
    output busy, //чтобы CPU не менял стейт, пока это происходит

    
    output [15:0] data_sw,
    output [7:0] addr_to_ld
);

    parameter S0 = 3'b



    //store
    always@ (*) begin
        
    end

endmodule