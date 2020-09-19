CC = g++
PROGRAM = exe.out

main: main.o s_item.o s_linked_list.o
	$(CC) -o $(PROGRAM) main.o s_item.o s_linked_list.o
test: test.o s_item.o s_linked_list.o
	$(CC) -o $(PROGRAM) test.o s_item.o s_linked_list.o
main.o: main.cpp
	$(CC) -c main.cpp
test.o: test.cpp
	$(CC) -c test.cpp
s_item.o: s_item.cpp
	$(CC) -c s_item.cpp
s_linked_list.o: s_linked_list.cpp
	$(CC) -c s_linked_list.cpp
clean:;	rm -f *.o $(PROGRAM)
