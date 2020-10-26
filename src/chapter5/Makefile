SUFFIX   = .cpp
CC = g++
CFLAGS   = -Wall -O2

MODULES = sort.cpp initial_list.cpp
INCLUDEPATH = $(if $(filter $(origin GUMPTION),undefined),$(error GUMPTION is not set.),$(GUMPTION))/lib
BUILD = $(GUMPTION)/build/chapter5
RESULT = $(GUMPTION)/src/chapter5/results

test: initial sort
sort: test_sort.cpp $(MODULES) mkdir
	$(CC) $(CFLAGS) -o $(BUILD)/$@ test_sort.cpp $(MODULES) -I $(INCLUDEPATH) && $(BUILD)/$@
initial: test_initial_list.cpp $(MODULES) mkdir
	$(CC) $(CFLAGS) -o $(BUILD)/$@ test_initial_list.cpp  $(MODULES) -I $(INCLUDEPATH) && $(BUILD)/$@
watch: watch_sort.cpp $(MODULES) mkdir
	$(CC) $(CFLAGS) -o $(BUILD)/$@ watch_sort.cpp $(MODULES) -I $(INCLUDEPATH) && $(BUILD)/$@
mkdir:
	mkdir -p $(BUILD)
	mkdir -p $(RESULT)
.PHONY: clean
clean:;	rm -f $(BUILD)/*
