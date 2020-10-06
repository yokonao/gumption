SUFFIX   = .cpp
CC = g++
CFLAGS   = -Wall -O2
INCLUDEPATH = ../

PROGRAM = exe.out

test: s_linked_list expectation to_bit bit_string hash_family_one_universal
s_linked_list: test_s_linked_list.cpp
	$(CC) $(CFLAGS) -o $(PROGRAM) test_s_linked_list.cpp && ./$(PROGRAM)
expectation: test_expectation.cpp
	$(CC) $(CFLAGS) -o $(PROGRAM) test_expectation.cpp && ./$(PROGRAM)
to_bit: test_to_bit.cpp
	$(CC) $(CFLAGS) -o $(PROGRAM) test_to_bit.cpp -I $(INCLUDEPATH) && ./$(PROGRAM)
bit_string: test_bit_string.cpp
	$(CC) $(CFLAGS) -o $(PROGRAM) test_bit_string.cpp -I $(INCLUDEPATH) && ./${PROGRAM}
hash_family_one_universal: test_hash_family_one_universal.cpp
	$(CC) $(CFLAGS) -o $(PROGRAM) test_hash_family_one_universal.cpp -I $(INCLUDEPATH) && ./${PROGRAM}
.PHONY: clean
clean:;	rm -f *.o $(PROGRAM)
