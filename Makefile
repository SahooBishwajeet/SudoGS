# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -I./headers

# Directories
SRC_DIR = src
INC_DIR = headers
BUILD_DIR = build

# Source and object files
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC_FILES))

# Target executable
TARGET = sudogs

# Build target
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(OBJ_FILES)
	@$(CXX) $(CXXFLAGS) $^ -o $@

# Rule to build object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	@rm -rf $(BUILD_DIR) $(TARGET)
