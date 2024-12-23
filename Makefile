CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17

LIB_NAME = libftpp.a
LIB_DIR = ./

INC_DIRS = -I./includes \
           -I./DataStructures \
           -I./DesignPatterns \
           -I./IOStream \
           -I./Thread \
           -I./Mathematics

LIB_SRCS = ./DataStructures/data_buffer.cpp \
           ./DesignPatterns/memento.cpp \
           ./IOStream/thread_safe_iostream.cpp \
           ./Mathematics/ivector2.cpp \
           ./Mathematics/ivector3.cpp \
           ./Mathematics/perlin_noise_2D.cpp \
           ./Mathematics/random_2D_coordinate_generator.cpp \
           ./Thread/thread.cpp \
           ./Thread/worker_pool.cpp \
           ./Thread/persistent_worker.cpp

LIB_OBJS = $(LIB_SRCS:%.cpp=%.o)

all: $(LIB_NAME)

$(LIB_NAME): $(LIB_OBJS)
	$(AR) rcs $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INC_DIRS) -c $< -o $@

clean:
	rm -f $(LIB_OBJS) $(LIB_NAME) $(TEST_OBJS) $(OUT)

fclean: clean

re: fclean all

TESTNAME ?= default
OUT = TestFolder/main_$(TESTNAME)

TEST_SRCS = TestFolder/main_$(TESTNAME).cpp
TEST_OBJS = $(TEST_SRCS:%.cpp=%.o)

$(OUT): $(TEST_OBJS) $(LIB_NAME)
	$(CXX) $(CXXFLAGS) -o $(OUT) $(TEST_OBJS) -L$(LIB_DIR) -lftpp $(INC_DIRS)

run_test: $(OUT)
	./$(OUT)

.PHONY: all clean fclean re run_test