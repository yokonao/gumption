CC = g++
PROGRAM = exe.out

main: main.o 
	$(CC) -o $(PROGRAM) main.o 
test: test.o 
	$(CC) -o $(PROGRAM) test.o 
main.o: main.cpp
	$(CC) -c main.cpp
test.o: test.cpp
	$(CC) -c test.cpp
clean:;	rm -f *.o $(PROGRAM)
