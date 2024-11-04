CXX := g++
CXXFLAGS := -g -Wall -Wextra -Iinc
SRC_DIR := src
BUILD_DIR := build
OUTPUT_DIR := .
EXEC_NAME := main

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)
TARGET := $(OUTPUT_DIR)/$(EXEC_NAME)

all: $(TARGET)
	@echo "Build finished. Run with $(TARGET)"

$(TARGET): $(OBJS) | $(OUTPUT_DIR)
	@$(CXX) $(CXXFLAGS) $^ -o $@ || { \
		echo "Error compiling $(EXEC_NAME). Check $^ for syntax errors."; \
		exit 1; \
	}
	@echo "Successfully compiled $(EXEC_NAME)"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	@$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@ || { \
		echo "Error compiling $<. Check $< for syntax errors."; \
		exit 1; \
	}
	@echo "Compiled $< successfully."

-include $(DEPS)

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

$(OUTPUT_DIR):
	@mkdir -p $(OUTPUT_DIR)

clean:
	@rm -rf $(BUILD_DIR)/*.o $(TARGET)
	@rm -rf $(BUILD_DIR)/*.d $(TARGET)
	@echo "Cleaned up."

.PHONY: all clean