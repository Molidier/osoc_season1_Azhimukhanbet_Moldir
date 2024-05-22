# Makefile
VERILATOR = verilator
VERILATOR_FLAGS = --cc --exe

TOP_MODULE = top
VERILOG_SOURCES = $(TOP_MODULE).v
CPP_SOURCES = tb_$(TOP_MODULE).cpp

all: sim

sim: $(VERILOG_SOURCES) $(CPP_SOURCES)
	$(VERILATOR) $(VERILATOR_FLAGS) $(VERILOG_SOURCES) $(CPP_SOURCES)
	make -C obj_dir -f V$(TOP_MODULE).mk
	./obj_dir/V$(TOP_MODULE)

clean:
	rm -rf obj_dir
