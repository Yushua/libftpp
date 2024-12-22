# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17

# Library name and directory
LIB_NAME = libftpp.a
LIB_DIR = ./

# Include directories
INC_DIRS = -I./includes \
           -I./DataStructures \
           -I./DesignPatterns \
           -I./IOStream \
           -I./Thread \
           -I./Mathematics

# Source files for the library
LIB_SRCS = ./DataStructures/data_buffer.cpp \
           ./DesignPatterns/memento.cpp \
           ./IOStream/thread_safe_iostream.cpp \
           ./Mathematics/ivector2.cpp \
           ./Mathematics/ivector3.cpp \
           ./Mathematics/perlin_noise_2D.cpp \
           ./Mathematics/random_2D_coordinate_generator.cpp \
	    ./Mathematics/main_random_2D_coordinate_generator.cpp \
	    ./Mathematics/main_perlin_2D.cpp \
           ./Thread/thread.cpp \
           ./Thread/worker_pool.cpp \
           ./Thread/persistent_worker.cpp

LIB_OBJS = $(LIB_SRCS:%.cpp=%.o)

# Default target to build the library
all: $(LIB_NAME)

# Rule to create the static library
$(LIB_NAME): $(LIB_OBJS)
	$(AR) rcs $@ $^

# Rule to compile .cpp files into .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INC_DIRS) -c $< -o $@

# Clean up object files and the library
clean:
	rm -f $(LIB_OBJS) $(LIB_NAME) $(TEST_OBJS) $(OUT)

fclean: clean

re: fclean all

# Compile and run the specified test
TESTNAME ?= default
OUT = TestFolder/main_$(TESTNAME)

TEST_SRCS = TestFolder/main_$(TESTNAME).cpp
TEST_OBJS = $(TEST_SRCS:%.cpp=%.o)

$(OUT): $(TEST_OBJS) $(LIB_NAME)
	$(CXX) $(CXXFLAGS) -o $(OUT) $(TEST_OBJS) -L$(LIB_DIR) -lftpp $(INC_DIRS)

run_test: $(OUT)
	./$(OUT)

.PHONY: all clean fclean re run_test