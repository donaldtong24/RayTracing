# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -Iinclude

# Directory paths
BUILD_DIR = build
SRC_DIR = src
INCLUDE_DIR = include

RENDER_DIR = renders
# Directory where the .ppm will be saved

# Source files and target executable
SRCS = $(SRC_DIR)/main.cc
TARGET = $(BUILD_DIR)/main.exe

# Output ppm file location
OUTPUT_PPM = $(RENDER_DIR)/image.ppm

# Build rule for the executable
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Rule to create the renders folder, run the program, and output to image.ppm
run: $(TARGET)
	# Ensure the renders directory exists
	mkdir -p $(RENDER_DIR)
	# Run the program and pipe the output to the renders/image.ppm
	./$(TARGET) > $(OUTPUT_PPM)

# Clean up the build and renders directories
clean:
	rm -f $(TARGET)
	rm -f $(OUTPUT_PPM)  # Removes the generated .ppm file from the renders folder
