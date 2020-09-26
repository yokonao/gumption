SUFFIX   = .cpp
CC = g++
CFLAGS   = -Wall -O2

PROGRAM = exe.out
MODULES = s_item.cpp s_linked_list.cpp s_free_list.cpp universal_hash.cpp uarray.cpp
INCLUDEPATH = ../../lib

univ: test_universalhash.cpp $(MODULES)
	$(CC) $(CFLAGS) -o $(PROGRAM) test_universalhash.cpp $(MODULES) -I $(INCLUDEPATH)

random: test_random.cpp gen_random.cpp
	$(CC) $(CFLAGS) -o $(PROGRAM) test_random.cpp gen_random.cpp -I $(INCLUDEPATH)
operation: test_operation.cpp operation.cpp uarray.cpp
	$(CC) $(CFLAGS) -o $(PROGRAM) test_operation.cpp operation.cpp uarray.cpp -I $(INCLUDEPATH)
uarray: test_uarray.cpp uarray.cpp
	$(CC) $(CFLAGS) -o $(PROGRAM) test_uarray.cpp uarray.cpp -I $(INCLUDEPATH)
.PHONY: clean
clean:;	rm -f *.o $(PROGRAM)
