#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vprelab.h" // Replace with your Verilated module header file

#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAX_SIM_TIME 100 // Adjust simulation time as needed

vluint64_t sim_time = 0;

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vprelab* dut = new Vprelab;

    Verilated::traceEverOn(true);
    VerilatedVcdC* vcd = new VerilatedVcdC;
    dut->trace(vcd, 10); // Trace every 10th time unit
    vcd->open("waveform.vcd");

    // Initialize inputs
    dut->clk = 0;
    dut->reset = 1;
    dut->light = 0; // Initialize outputs to 0

    // Start simulation
    while (sim_time < MAX_SIM_TIME && !Verilated::gotFinish()) {
        // Toggle clock
        dut->clk = !dut->clk;

        // Toggle reset (asynchronous reset)
        if (sim_time < 2) {
            dut->reset = 1;
        } else if (sim_time == 2) {
            dut->reset = 0;
        }

        // Evaluate DUT
        dut->eval();

        // Dump trace
        vcd->dump(sim_time);

        // Monitor outputs
        if (sim_time > 3) { // Start monitoring after a few cycles
            // Access state signals (example names, adjust as per Verilator's output)
            std::cout << "@" << sim_time << "ns - ";
            std::cout << "Current State: " << dut->prelab__DOT__current_state;
            std::cout << ", Next State: " << dut->prelab__DOT__next_state;
            std::cout << ", Light Output: " << dut->light << std::endl;
        }

        // Advance simulation time
        sim_time++;
    }

    // Finalize
    dut->final();
    vcd->close();
    delete dut;
    delete vcd;

    return 0;
}
