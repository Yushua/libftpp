CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17 

LIB_DIR = ../
LIB_NAME = libftpp.a

INC_DIRS = -I../includes \
           -I../DataStructures \
           -I../DesignPatterns \
           -I../IOStream \
           -I../Thread \
           -I../Mathematics

TESTNAME ?= pool

OUT = main_$(TESTNAME)_test

SRCS = main_$(TESTNAME).cpp
OBJS = $(SRCS:%.cpp=%.o)

all: $(OUT)

$(OUT): $(OBJS) $(LIB_DIR)$(LIB_NAME)
	$(CXX) $(CXXFLAGS) -o $(OUT) $(OBJS) -L$(LIB_DIR) -lftpp $(INC_DIRS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INC_DIRS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OUT)

fclean: clean

re: fclean all

run: $(OUT)
	./$(OUT)
	rm -f $(OBJS) $(OUT)