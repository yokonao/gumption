CC = g++
PROGRAM = exe.out

main: main.o s_item.o
	$(CC) -o $(PROGRAM) main.o s_item.o
test: test.o s_item.o
	$(CC) -o $(PROGRAM) test.o s_item.o
main.o: main.cpp
	$(CC) -c main.cpp
test.o: test.cpp
	$(CC) -c test.cpp
s_item.o: s_item.cpp
	$(CC) -c s_item.cpp
clean:;	rm -f *.o $(PROGRAM)
