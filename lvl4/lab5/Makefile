# Define the compiler
CXX = g++

# Define the compiler flags
CXXFLAGS = -Wall -std=c++17 -g

# Define the source files and object files
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

# Define the target executable
TARGET = my_program

# Default target to build the executable
all: $(TARGET)

# Rule to link the object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to compile the source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean
