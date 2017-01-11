CC = g++
INC_DIR = Util
SRC_DIR = directed_graph
BLD_DIR = Build
CFLAGS = -std=c++14 -Wall -I$(INC_DIR)

SRCS = $(directed_graph.h) $(directed_graph.cpp) $(directed_graph_driver.cpp)
OBJS = $(BLD_DIR)\directed_graph.o

DEPS = $(INC_DIR)\circular_list.h $(INC_DIR)\hash.h

all: $(OBJS)

$(BLD_DIR)\%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(BLD_DIR)\directed_graph.o: $(DEPS)