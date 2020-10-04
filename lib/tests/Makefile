SUFFIX   = .cpp
CC = g++
CFLAGS   = -Wall -O2
INCLUDEPATH = ../

PROGRAM = exe.out

s_linked_list: test_s_linked_list.cpp
	$(CC) $(CFLAGS) -o $(PROGRAM) test_s_linked_list.cpp
expectation: test_expectation.cpp
	$(CC) $(CFLAGS) -o $(PROGRAM) test_expectation.cpp
to_bit: test_to_bit.cpp
	$(CC) $(CFLAGS) -o $(PROGRAM) test_to_bit.cpp -I $(INCLUDEPATH)
.PHONY: clean
clean:;	rm -f *.o $(PROGRAM)
