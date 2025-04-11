# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

# Target executable name
TARGET = main.exe

# Source files
SRCS = main.cc

# Build rule
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Clean rule (optional)
clean:
	rm -f $(TARGET)
