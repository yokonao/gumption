SUFFIX   = .cpp
CC = g++
CFLAGS   = -Wall -O2

MODULES = binary_search_tree.cpp
INCLUDEPATH = $(if $(filter $(origin GUMPTION),undefined),$(error GUMPTION is not set.),$(GUMPTION))/lib
BUILD = $(GUMPTION)/build/chapter7

test: binary_search_tree
binary_search_tree: test_binary_search_tree.cpp $(MODULES) mkdir
	$(CC) $(CFLAGS) -o $(BUILD)/$@.o test_binary_search_tree.cpp $(MODULES) -I $(INCLUDEPATH) && $(BUILD)/$@.o
watch: watch_tree.cpp $(MODULES) mkdir
	$(CC) $(CFLAGS) -o $(BUILD)/$@ watch_tree.cpp $(MODULES) -I $(INCLUDEPATH) && $(BUILD)/$@
mkdir:
	mkdir -p $(BUILD)
.PHONY: clean
clean:;	rm -f $(BUILD)/*.o
