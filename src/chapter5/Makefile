SUFFIX   = .cpp
CC = g++
CFLAGS   = -Wall -O2

PROGRAM = exe.out
MODULES = sort.cpp initial_list.cpp
INCLUDEPATH = $(if $(filter $(origin GUMPTION),undefined),$(error GUMPTION is not set.),$(GUMPTION))/lib
BUILD = $(GUMPTION)/build/chapter5

test: initial sort
sort: test_sort.cpp $(MODULES) mkdir
	$(CC) $(CFLAGS) -o $(BUILD)/$(PROGRAM) test_sort.cpp $(MODULES) -I $(INCLUDEPATH) && $(BUILD)/$(PROGRAM)
initial: test_initial_list.cpp $(MODULES) mkdir
	$(CC) $(CFLAGS) -o $(BUILD)/$(PROGRAM) test_initial_list.cpp  $(MODULES) -I $(INCLUDEPATH) && $(BUILD)/$(PROGRAM)
mkdir:
	mkdir -p $(BUILD)
.PHONY: clean
clean:;	rm -f *.o $(PROGRAM)
