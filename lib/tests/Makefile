SUFFIX   = .cpp
CC = g++
CFLAGS   = -Wall -O2
INCLUDEPATH = $(if $(filter $(origin GUMPTION),undefined),$(error GUMPTION is not set.),$(GUMPTION))/lib
PROGRAM = exe.out

test: s_linked_list expectation to_bit bit_string gen_mt uarray array binary_heap stack queue doubly_linked_list string_operation
s_linked_list: test_s_linked_list.cpp
	$(CC) $(CFLAGS) -o $(PROGRAM) test_s_linked_list.cpp && ./$(PROGRAM)
expectation: test_expectation.cpp
	$(CC) $(CFLAGS) -o $(PROGRAM) test_expectation.cpp && ./$(PROGRAM)
to_bit: test_to_bit.cpp
	$(CC) $(CFLAGS) -o $(PROGRAM) test_to_bit.cpp -I $(INCLUDEPATH) && ./$(PROGRAM)
bit_string: test_bit_string.cpp
	$(CC) $(CFLAGS) -o $(PROGRAM) test_bit_string.cpp -I $(INCLUDEPATH) && ./${PROGRAM}
gen_mt: test_gen_mt.cpp
	$(CC) $(CFLAGS) -o $(PROGRAM) test_gen_mt.cpp -I $(INCLUDEPATH) && ./${PROGRAM}
hash_family: test_hash_family.cpp
	$(CC) $(CFLAGS) -o $(PROGRAM) test_hash_family.cpp -I $(INCLUDEPATH) && ./${PROGRAM}
array: test_array.cpp
	$(CC) $(CFLAGS) -o $(PROGRAM) test_array.cpp -I $(INCLUDEPATH) && ./${PROGRAM}
uarray: test_uarray.cpp
	$(CC) $(CFLAGS) -o $(PROGRAM) test_uarray.cpp -I $(INCLUDEPATH) && ./${PROGRAM}
stack: test_stack.cpp
	$(CC) $(CFLAGS) -o $(PROGRAM) test_stack.cpp -I $(INCLUDEPATH) && ./${PROGRAM}
queue: test_queue.cpp
	$(CC) $(CFLAGS) -o $(PROGRAM) test_queue.cpp -I $(INCLUDEPATH) && ./${PROGRAM}
binary_heap: test_binary_heap.cpp
	$(CC) $(CFLAGS) -o $(PROGRAM) test_binary_heap.cpp -I $(INCLUDEPATH) && ./${PROGRAM}
doubly_linked_list: test_doubly_linked_list.cpp
	$(CC) $(CFLAGS) -o $(PROGRAM) test_doubly_linked_list.cpp -I $(INCLUDEPATH) && ./${PROGRAM}
string_operation: test_string_operation.cpp
	$(CC) $(CFLAGS) -o $(PROGRAM) test_string_operation.cpp -I $(INCLUDEPATH) && ./${PROGRAM}
chaining_hash: test_chaining_hash.cpp
	$(CC) $(CFLAGS) -o $(PROGRAM) test_chaining_hash.cpp -I $(INCLUDEPATH) && ./${PROGRAM}

.PHONY: clean
clean:;	rm -f *.o $(PROGRAM)
