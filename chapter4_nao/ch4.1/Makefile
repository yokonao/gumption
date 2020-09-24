CC = g++
PROGRAM = exe.out
MODULES = s_item.cpp s_linked_list.cpp s_free_list.cpp chaining_hash.cpp

main: main.cpp $(MODULES)
	$(CC) -o $(PROGRAM) main.cpp $(MODULES)
test: test.cpp $(MODULES)
	$(CC) -o $(PROGRAM) test.cpp $(MODULES)
clean:;	rm -f *.o $(PROGRAM)
