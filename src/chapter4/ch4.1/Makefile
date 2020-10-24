CC = g++
CFLAGS   = -Wall -O2

MODULES = chaining_hash.cpp
INCLUDEPATH = $(if $(filter $(origin GUMPTION),undefined),$(error GUMPTION is not set.),$(GUMPTION))/lib
BUILD = $(GUMPTION)/build/chapter4/ch4.1

test: test.cpp $(MODULES) mkdir
	$(CC) $(CFLAGS) -o $(BUILD)/$@ test.cpp $(MODULES) -I $(INCLUDEPATH) && $(BUILD)/$@
mkdir:
	mkdir -p $(BUILD)
.PHONY: clean
clean:;	rm -f $(BUILD)/*
