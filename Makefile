CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17 

LIB_NAME = libftpp.a

SRCS = \
		./DataStructures/data_buffer.cpp \
       ./DesignPatterns/memento.cpp \
       ./IOStream/thread_safe_iostream.cpp \
       ./Thread/thread.cpp \
       ./Thread/worker_pool.cpp \
       ./Thread/persistent_worker.cpp \

OBJS = $(SRCS:%.cpp=%.o)

INC_DIRS = -I./includes \
           -I./DataStructures \
           -I./DesignPatterns \
           -I./IOStream \
           -I./Thread \
           -I./Mathematics

all: $(LIB_NAME)

$(LIB_NAME): $(OBJS)
	$(AR) rcs $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INC_DIRS) -c $< -o $@

clean:
	rm -f $(OBJS) $(LIB_NAME)

fclean: clean

re: fclean all