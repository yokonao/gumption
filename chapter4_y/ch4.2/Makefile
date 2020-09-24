CC = g++
PROGRAM = exe.out
MODULES = s_item.cpp s_linked_list.cpp s_free_list.cpp chaining_hash.cpp
INCLUDEPATH = ../../lib

main: main.cpp $(MODULES)
	$(CC) -o $(PROGRAM) main.cpp $(MODULES) -I $(INCLUDEPATH)
test: test.cpp $(MODULES)
	$(CC) -o $(PROGRAM) test.cpp $(MODULES) -I $(INCLUDEPATH)
random: test_random.cpp gen_random.cpp
	$(CC) -o $(PROGRAM) test_random.cpp gen_random.cpp -I $(INCLUDEPATH)
clean:;	rm -f *.o $(PROGRAM)
