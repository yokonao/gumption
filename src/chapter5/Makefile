SUFFIX   = .cpp
CC = g++
CFLAGS   = -Wall -O2

MODULES = sort.cpp initial_list.cpp
INCLUDEPATH = $(if $(filter $(origin GUMPTION),undefined),$(error GUMPTION is not set.),$(GUMPTION))/lib
BUILD = $(GUMPTION)/build/chapter5

test: initial sort
sort: test_sort.cpp $(MODULES) mkdir
	$(CC) $(CFLAGS) -o $(BUILD)/$@.o test_sort.cpp $(MODULES) -I $(INCLUDEPATH) && $(BUILD)/$@.o
initial: test_initial_list.cpp $(MODULES) mkdir
	$(CC) $(CFLAGS) -o $(BUILD)/$@.o test_initial_list.cpp  $(MODULES) -I $(INCLUDEPATH) && $(BUILD)/$@.o
mkdir:
	mkdir -p $(BUILD)
.PHONY: clean
clean:;	rm -f $(BUILD)/*.o
