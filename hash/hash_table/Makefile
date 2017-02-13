CC = g++
CFLAGS = -std=c++11 -I..\..\linked_list

SRCS = ..\hash.h hash_table.cpp hash_node.cpp iterator.cpp const_iterator.cpp ..\driver\hash_table_driver.cpp

hash_table.o: $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o hash_table.o

clean:
	Del "C:\Users\Ethan Rivers\Documents\AdvCompProg-Work\hash\hash_table\hash_table.o"