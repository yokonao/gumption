SUFFIX   = .cpp
CC = g++
CFLAGS   = -Wall -O2

INCLUDEPATH = $(if $(filter $(origin GUMPTION),undefined),$(error GUMPTION is not set.),$(GUMPTION))/lib
BUILD = $(GUMPTION)/build/chapter3
RESULT = $(GUMPTION)/results/chapter3

test: univ
univ: test_universalhash.cpp $(MODULES)
	$(CC) $(CFLAGS) -o $(BUILD)/$@.o test_universalhash.cpp universal_hash.cpp -I $(INCLUDEPATH) && $(BUILD)/$@.o
.PHONY: clean
clean:;	rm -f *.o $(PROGRAM)
