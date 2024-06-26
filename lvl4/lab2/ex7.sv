module top_module(
    input d,
    input done_counting,
    input ack,
    input [9:0] state,    // 10-bit one-hot current state
    output B3_next,
    output S_next,
    output S1_next,
    output Count_next,
    output Wait_next,
    output done,
    output counting,
    output shift_ena
); 
    // State parameters
    parameter S=0, S1=1, S11=2, S110=3, B0=4, B1=5, B2=6, B3=7, Count=8, Wait=9;

    // Next state logic
    assign S_next = (state[Wait] && ack || state[S] && !d || state[S110] && !d || state[S1] && !d );
    assign S1_next = (state[S] && d);
    assign B3_next = (state[B2]);
    assign Count_next = (state[B3] && shift_ena || !(done_counting) && state[Count]);
    assign Wait_next = (state[Count] && done_counting || state[Wait] && !ack);
    
    // Output logic
    assign done = state[Wait];
    assign counting = state[Count];
    assign shift_ena = state[B0] || state[B1] || state[B2] || state[B3];

endmodule
