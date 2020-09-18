CC = g++
PROGRAM = exe.out

main: main.o u_array.o 
	$(CC) -o $(PROGRAM) main.o u_array.o
test: test.o u_array.o
	$(CC) -o $(PROGRAM) test.o u_array.o
main.o: main.cpp
	$(CC) -c main.cpp
test.o: test.cpp
	$(CC) -c test.cpp
u_array.o: u_array.cpp
	$(CC) -c u_array.cpp
clean:;	rm -f *.o $(PROGRAM)
