//Top level UART module

module uart_module #(
    parameter data_width = 8
)
(
	input        rx_data_bit,
	input  [data_width-1:0] data_tx,
	input        CLOCK_50, 
	input        rst,
	input        run,

	/*output       rx_in_idle,
	output       rx_error,
	output       tx_in_idle,*/

	output       rx_receiving,
	output       tx_transmitting,
	
	output       rx_done,
	output [data_width-1:0] data_bus;
	output       tx_done,
	output       tx_data_bit,
	output [6:0] HEX0,
	output [6:0] HEX1,
	output [6:0] HEX2
);

	
	

	uart_rx			R0(rx_data_bit, CLOCK_50, rst, /*rx_in_idle, rx_error,*/ rx_receiving, rx_done, data_bus);
	
	uart_tx        T0(data_tx, CLOCK_50, rst, run, /*tx_in_idle, */ tx_transmitting, tx_done, tx_data_bit);

	decoder_hex    D0(data_bus, HEX0, HEX1, HEX2);
				

endmodule