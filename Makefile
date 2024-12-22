# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror

# Library name
LIB_NAME = libftpp.a

# Source files

SRCS = \
		./DataStructures/data_buffer.cpp \
       ./DesignPatterns/memento.cpp \
       ./IOStream/thread_safe_iostream.cpp \
       ./Thread/thread.cpp \
       ./Thread/worker_pool.cpp \
       ./Thread/persistent_worker.cpp \

# Object files
OBJS = $(SRCS:%.cpp=%.o)

# Include directories
INC_DIRS = -I./includes \
           -I./DataStructures \
           -I./DesignPatterns \
           -I./IOStream \
           -I./Thread \
           -I./Mathematics

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