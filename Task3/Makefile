# Define directories
SRC_DIR := src
BIN_DIR := bin

# Define the compiler and flags
CXX := g++
CXXFLAGS := -Wall -std=c++17

# Find all cpp files in the src directory
SOURCES := $(wildcard $(SRC_DIR)/*.cpp)

# Define the output executables
EXECUTABLES := $(patsubst $(SRC_DIR)/%.cpp, $(BIN_DIR)/%, $(SOURCES))

# Default target
all: $(EXECUTABLES)
	@echo "Build finished. Switch to the bin directory to run the executables."

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

# Link each cpp file into its own executable
$(BIN_DIR)/%: $(SRC_DIR)/%.cpp | $(BIN_DIR)
	@$(CXX) $(CXXFLAGS) -o $@ $<
	@echo "Successfully compiled $<"

# Clean target to remove the executables
clean:
	@rm -f $(EXECUTABLES)
	@echo "Cleaned up."

.PHONY: all clean