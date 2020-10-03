SUFFIX   = .cpp
CC = g++
CFLAGS   = -Wall -O2

PROGRAM = exe.out

s_linked_list: test_s_linked_list.cpp
	$(CC) $(CFLAGS) -o $(PROGRAM) test_s_linked_list.cpp
expectation: test_expectation.cpp
	$(CC) $(CFLAGS) -o $(PROGRAM) test_expectation.cpp
.PHONY: clean
clean:;	rm -f *.o $(PROGRAM)
