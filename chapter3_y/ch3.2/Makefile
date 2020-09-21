CC = g++
PROGRAM = exe.out

test : test.o dllinkedlist.o freelist.o
	$(CC) -o $(PROGRAM) test.o dllinkedlist.o freelist.o
test.o : test.cpp
	$(CC) -c  test.cpp
dllinkedlist.o : dllinkedlist.cpp
	$(CC) -c  dllinkedlist.cpp
freelist.o : freelist.cpp
	$(CC) -c  freelist.cpp
clean:
	rm -f *.o $(PROGRAM)


