SUFFIX   = .cpp
CC = g++
CFLAGS   = -Wall -O2

MODULES = node_array.cpp
INCLUDEPATH = $(if $(filter $(origin GUMPTION),undefined),$(error GUMPTION is not set.),$(GUMPTION))/lib
BUILD = $(GUMPTION)/build/chapter9
RESULT = $(GUMPTION)/results/chapter9

test: node_array 
graph: test_graph.cpp $(MODULES) mkdir
	$(CC) $(CFLAGS) -o $(BUILD)/$@.o test_graph.cpp $(MODULES) -I $(INCLUDEPATH) && $(BUILD)/$@.o
mkdir:
	mkdir -p $(BUILD)
	mkdir -p $(RESULT)

.PHONY: clean
clean:;	rm -f $(BUILD)/*.o
