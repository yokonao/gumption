CC = g++
PROGRAM = exe.out

test : test.o DLLinkedlist.o
	$(CC) -o $(PROGRAM) test.o DLLinkedlist.o
test.o : test.cpp
	$(CC) -c  test.cpp
DLLinkedlist.o : DLLinkedlist.cpp
	$(CC) -c  DLLinkedlist.cpp

