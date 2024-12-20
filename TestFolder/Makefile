CXX = g++
CXXFLAGS = -Wall -Wextra -Werror

# Path to the libftpp.a static library
LIB_DIR = ../
LIB_NAME = libftpp.a

# Include directories
INC_DIRS = -I../includes -I../DataStructures

# TESTNAME is set dynamically or defaults to 'pool'
TESTNAME ?= pool

MAINADD = main_
TESTADDITION = _test

OUT = $(MAINADD)$(TESTNAME)$(TESTADDITION)

# Source and object files depend on TESTNAME
SRCS = $(MAINADD)$(TESTNAME).cpp
OBJS = $(SRCS:%.cpp=%.o)

# Default target
all: $(OUT)

# Rule to create the executable by linking with libftpp.a
$(OUT): $(OBJS) $(LIB_DIR)$(LIB_NAME)
	$(CXX) $(CXXFLAGS) -o $(OUT) $(OBJS) -L$(LIB_DIR) -lftpp $(INC_DIRS)

# Rule to compile .cpp files into .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INC_DIRS) -c $< -o $@

# Clean
clean:
	rm -f $(OBJS) $(OUT)

fclean: clean

# Rebuild
re: fclean all

# Run the dynamically created executable
run: $(OUT)
	./$(OUT)
	rm -f $(OBJS) $(OUT)
