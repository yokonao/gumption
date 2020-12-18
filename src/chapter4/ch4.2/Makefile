SUFFIX   = .cpp
CC = g++
CFLAGS   = -Wall -O2

PROGRAM = exe.out
MODULES = s_item.cpp s_linked_list.cpp s_free_list.cpp universal_hash.cpp operation.cpp rand_list.cpp
INCLUDEPATH = $(if $(filter $(origin GUMPTION),undefined),$(error GUMPTION is not set.),$(GUMPTION))/lib


univ: test_universalhash.cpp $(MODULES)
	$(CC) $(CFLAGS) -o $(PROGRAM) test_universalhash.cpp $(MODULES) -I $(INCLUDEPATH)

random: test_random.cpp gen_random.cpp
	$(CC) $(CFLAGS) -o $(PROGRAM) test_random.cpp  $(MODULES) -I $(INCLUDEPATH)
operation: test_operation.cpp operation.cpp 
	$(CC) $(CFLAGS) -o $(PROGRAM) test_operation.cpp $(MODULES) -I $(INCLUDEPATH)
watch: watch_hash.cpp
	$(CC) $(CFLAGS) -o $(PROGRAM) watch_hash.cpp $(MODULES) -I $(INCLUDEPATH)
watchrandom: watch_random.cpp
	$(CC) $(CFLAGS) -o $(PROGRAM) watch_random.cpp $(MODULES) -I $(INCLUDEPATH)
.PHONY: clean
clean:;	rm -f *.o $(PROGRAM)
