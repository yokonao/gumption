CC = g++
PROGRAM = exe.out
MODULES = s_item.o s_linked_list.o s_free_list.o chaining_hash.o

main: main.o $(MODULES)
	$(CC) -o $(PROGRAM) main.o $(MODULES)
test: test.o $(MODULES)
	$(CC) -o $(PROGRAM) test.o $(MODULES)
random: test_random.o gen_random.o
	$(CC) -o $(PROGRAM) test_random.o gen_random.o
test_random.o: test_random.cpp
	$(CC) -c test_random.cpp
gen_random.o: gen_random.cpp
	$(CC) -c gen_random.cpp
main.o: main.cpp
	$(CC) -c main.cpp
test.o: test.cpp
	$(CC) -c test.cpp
s_item.o: s_item.cpp
	$(CC) -c s_item.cpp
s_linked_list.o: s_linked_list.cpp
	$(CC) -c s_linked_list.cpp
s_free_list.o: s_free_list.cpp
	$(CC) -c s_free_list.cpp
chaining_hash.o: chaining_hash.cpp
	$(CC) -c chaining_hash.cpp
clean:;	rm -f *.o $(PROGRAM)
