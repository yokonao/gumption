SUFFIX   = .cpp
CC = g++
CFLAGS   = -Wall -O2

INCLUDEPATH = $(if $(filter $(origin GUMPTION),undefined),$(error GUMPTION is not set.),$(GUMPTION))/lib
BUILD = $(GUMPTION)/build/chapter3
RESULT = $(GUMPTION)/results/chapter3
MODULES = universal_hash.cpp operation.cpp rand_list.cpp

test: univ operation
univ: test_universalhash.cpp $(MODULES)
	$(CC) $(CFLAGS) -o $(BUILD)/$@.o test_universalhash.cpp $(MODULES) -I $(INCLUDEPATH) && $(BUILD)/$@.o
operation: test_operation.cpp operation.cpp 
	$(CC) $(CFLAGS) -o $(BUILD)/$@.o test_operation.cpp $(MODULES) -I $(INCLUDEPATH) && $(BUILD)/$@.o
watch: watch_hash.cpp
	$(CC) $(CFLAGS) -o $(PROGRAM) watch_hash.cpp $(MODULES) -I $(INCLUDEPATH)
.PHONY: clean
clean:;	rm -f *.o $(PROGRAM)
