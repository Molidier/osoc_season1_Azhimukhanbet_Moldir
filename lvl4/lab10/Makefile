# Makefile for Verilator example
# Adapted for your specific module and testbench

MODULE = bigger
TB = testbench
# Add fetch_unit.sv to the SOURCES list
SOURCES = $(MODULE).v $(TB).cpp BittyEmulator.cpp BittyInstructionGenerator.cpp fetch_unit.v

.PHONY: all
all: sim

.PHONY: sim
sim: waveform.vcd

.PHONY: verilate
verilate: .stamp.verilate

.PHONY: build
build: obj_dir/V$(MODULE)

.PHONY: waves
waves: waveform.vcd
	@echo
	@echo "### WAVES ###"
	gtkwave waveform.vcd

waveform.vcd: obj_dir/V$(MODULE)
	@echo
	@echo "### SIMULATING ###"
	./obj_dir/V$(MODULE)

obj_dir/V$(MODULE): .stamp.verilate
	@echo
	@echo "### BUILDING SIM ###"
	make -C obj_dir -f V$(MODULE).mk V$(MODULE)

.stamp.verilate: $(SOURCES)
	@echo
	@echo "### VERILATING ###"
	verilator --trace --x-assign unique --x-initial unique -Wall -cc $(MODULE).v --exe $(SOURCES)
	@touch .stamp.verilate

.PHONY: lint
lint: $(MODULE).v
	verilator --lint-only $(MODULE).v

.PHONY: clean
clean:
	rm -rf .stamp.verilate
	rm -rf obj_dir
	rm -rf waveform.vcd
	rm -rf waveform.vcd.old
