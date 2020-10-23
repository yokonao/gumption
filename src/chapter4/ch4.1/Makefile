CC = g++
PROGRAM = exe.out
MODULES = chaining_hash.cpp
INCLUDEPATH = $(if $(filter $(origin GUMPTION),undefined),$(error GUMPTION is not set.),$(GUMPTION))/lib

test: test.cpp $(MODULES)
	$(CC) -o $(PROGRAM) test.cpp $(MODULES) -I $(INCLUDEPATH)
clean:;	rm -f *.o $(PROGRAM)
