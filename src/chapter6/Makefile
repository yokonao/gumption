SUFFIX   = .cpp
CC = g++
CFLAGS   = -Wall -O2

MODULES = binary_heap.cpp
INCLUDEPATH = $(if $(filter $(origin GUMPTION),undefined),$(error GUMPTION is not set.),$(GUMPTION))/lib
BUILD = $(GUMPTION)/build/chapter6

test: binary_heap
binary_heap: test_binary_heap.cpp $(MODULES) mkdir
	$(CC) $(CFLAGS) -o $(BUILD)/$@.o test_binary_heap.cpp $(MODULES) -I $(INCLUDEPATH) && $(BUILD)/$@.o
mkdir:
	mkdir -p $(BUILD)
.PHONY: clean
clean:;	rm -f $(BUILD)/*.o
