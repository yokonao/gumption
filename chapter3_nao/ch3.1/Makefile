CC = g++
PROGRAM = exe.out

main: main.o item.o linked_list.o free_list.o
	$(CC) -o $(PROGRAM) main.o item.o linked_list.o free_list.o
test: test.o item.o linked_list.o free_list.o
	$(CC) -o $(PROGRAM) test.o item.o linked_list.o free_list.o
main.o: main.cpp
	$(CC) -c main.cpp
test.o: test.cpp
	$(CC) -c test.cpp
item.o: item.cpp
	$(CC) -c item.cpp
linked_list.o: linked_list.cpp
	$(CC) -c linked_list.cpp
free_list.o: free_list.cpp
	$(CC) -c free_list.cpp
clean:;	rm -f *.o $(PROGRAM)
