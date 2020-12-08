
SUFFIX   = .cpp
CC = g++
CFLAGS   = -Wall -O2

INCLUDEPATH = $(if $(filter $(origin GUMPTION),undefined),$(error GUMPTION is not set.),$(GUMPTION))/lib
BUILD = $(GUMPTION)/build/chapter3
RESULT = $(GUMPTION)/results/chapter3

test: linked_list uarray
linked_list: test_linked_list.cpp free_list.cpp item.cpp linked_list.cpp mkdir
	$(CC) $(CFLAGS) -o $(BUILD)/$@.o test_linked_list.cpp free_list.cpp item.cpp linked_list.cpp -I $(INCLUDEPATH) && $(BUILD)/$@.o
uarray: test_uarray.cpp uarray.cpp mkdir
	$(CC) $(CFLAGS) -o $(BUILD)/$@ test_uarray.cpp uarray.cpp -I $(INCLUDEPATH) && $(BUILD)/$@
keisoku: keisoku.cpp uarray.cpp mkdir
	$(CC) $(CFLAGS) -o $(BUILD)/$@ keisoku.cpp uarray.cpp -I $(INCLUDEPATH) && $(BUILD)/$@
mkdir:
	mkdir -p $(BUILD)
	mkdir -p $(RESULT)
.PHONY: clean
clean:;	rm -f $(BUILD)/*.o
