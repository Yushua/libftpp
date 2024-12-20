# Root Makefile

CXX = g++
CXXFLAGS = -Wall -Wextra -Werror
LIB_NAME = libftpp.a

# Source files and object files
SRCS = \
    # DataStructures/data_buffer.cpp \
    # DataStructures/pool.cpp
OBJS = $(SRCS:%.cpp=%.o)

# Include directories
INC_DIRS = -I./includes -I./DataStructures

# Default target to build the static library
all: $(LIB_NAME)

# Rule to create the static library
$(LIB_NAME): $(OBJS)
	$(AR) rcs $@ $^

# Rule to compile .cpp files into .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INC_DIRS) -c $< -o $@

# Clean
clean:
	rm -f $(OBJS) $(LIB_NAME)

fclean: clean

# Rebuild
re: fclean all
