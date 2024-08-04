# Variables
SRC_DIR := src
BIN_DIR := bin
EXECUTABLE := $(BIN_DIR)/langtonctl

# Go source files
SRC_FILES := $(wildcard $(SRC_DIR)/*.go)

# Default target
all: build

# Build target with optimization and stripping
build: $(EXECUTABLE)

# Create bin directory and compile the Go files with optimizations and strip flags
$(EXECUTABLE): $(SRC_FILES)
	@mkdir -p $(BIN_DIR)
	@go build -ldflags="-s -w" -buildmode=pie -trimpath -mod=readonly -o $(EXECUTABLE) $(SRC_FILES)
	@strip $(EXECUTABLE)
	@echo "Built $(EXECUTABLE) with optimizations"

# Clean target
clean:
	@rm -rf $(BIN_DIR)
	@echo "Cleaned up."

# PHONY targets to avoid conflicts with files of the same name
.PHONY: all build clean
