CC = g++
PROGRAM = exe.out
MODULES = s_item.o s_linked_list.o s_free_list.o

main: main.o $(MODULES)
	$(CC) -o $(PROGRAM) main.o $(MODULES)
test: test.o $(MODULES)
	$(CC) -o $(PROGRAM) test.o $(MODULES)
main.o: main.cpp
	$(CC) -c main.cpp
test.o: test.cpp
	$(CC) -c test.cpp
s_item.o: s_item.cpp
	$(CC) -c s_item.cpp
s_linked_list.o: s_linked_list.cpp
	$(CC) -c s_linked_list.cpp
s_free_list.o: s_free_list.cpp
	$(CC) -c s_free_list.cpp
clean:;	rm -f *.o $(PROGRAM)
