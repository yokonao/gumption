
SUFFIX   = .cpp
CC = g++
CFLAGS   = -Wall -O2

MODULES = free_list.cpp item.cpp linked_list.cpp
INCLUDEPATH = $(if $(filter $(origin GUMPTION),undefined),$(error GUMPTION is not set.),$(GUMPTION))/lib
BUILD = $(GUMPTION)/build/chapter3

test: linked_list
linked_list: test_linked_list.cpp $(MODULES) mkdir
	$(CC) $(CFLAGS) -o $(BUILD)/$@.o test_linked_list.cpp $(MODULES) -I $(INCLUDEPATH) && $(BUILD)/$@.o
mkdir:
	mkdir -p $(BUILD)
.PHONY: clean
clean:;	rm -f $(BUILD)/*.o
