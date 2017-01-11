
CC = g++
CFLAGS = -std=c++11 -g -Wall
CL /I\template_library\hash\ /I\template_library\circular_list\

default: all

all: directed_graph.o
	$(CC) $(CFLAGS) -o all directed_graph.o

directed_graph.o: directed_graph\directed_graph.cpp\ directed_graph\directed_graph.h\
	$(CC) $(CFLAGS) -c directed_graph\directed_graph.cpp\

clean:
	$(RM) all *.o *~

