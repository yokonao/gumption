CC = g++
PROGRAM = exe.out
keisoku :keisoku.o uarray.o
	$(CC) -o $(PROGRAM) keisoku.o uarray.o 
test : test.o uarray.o
	$(CC) -o $(PROGRAM) test.o uarray.o 
keisoku.o : test.cpp
	$(CC) -c  keisoku.cpp
test.o : test.cpp
	$(CC) -c  test.cpp
uarray.o : uarray.cpp
	$(CC) -c  uarray.cpp
clean:
	rm -f *.o $(PROGRAM)


