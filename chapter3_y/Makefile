CC = g++
PROGRAM = exe.out

test : test.o DLLinkedlist.o FreeList.o
	$(CC) -o $(PROGRAM) test.o DLLinkedlist.o FreeList.o
test.o : test.cpp
	$(CC) -c  test.cpp
DLLinkedlist.o : DLLinkedlist.cpp
	$(CC) -c  DLLinkedlist.cpp
FreeList.o : FreeList.cpp
	$(CC) -c  DLLinkedlist.cpp
clean:	rm -f *.o $(PROGRAM)


