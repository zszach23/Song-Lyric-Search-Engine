TEST ?= 0
MAIN ?= src/main.cpp

# Define the include directory
INCLUDE_DIR = -I./include

PREREQ = $(MAIN)

# Conditionally add source files to BASE_SRC
ifeq ($(TEST), 0)
    PREREQ += src/SearchEngineConfig.cpp
endif

# Conditionally add source files to BASE_SRC
ifeq ($(TEST), 01)
    PREREQ += src/SearchEngineConfig.cpp
endif

# Define the output executable
TARGET = engine

# Compile the target
$(TARGET): $(PREREQ)
	@g++ $(INCLUDE_DIR) -o $@ $^

# Clean target
clean:
	@rm -f $(TARGET)
