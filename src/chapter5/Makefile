SUFFIX   = .cpp
CC = g++
CFLAGS   = -Wall -O2

PROGRAM = exe.out
MODULES = sort.cpp initial_list.cpp  gen_random.cpp
INCLUDEPATH = $(if $(filter $(origin GUMPTION),undefined),$(error GUMPTION is not set.),$(GUMPTION))/lib


sort: test_sort.cpp $(MODULES)
	$(CC) $(CFLAGS) -o $(PROGRAM) test_sort.cpp $(MODULES) -I $(INCLUDEPATH) && ./$(PROGRAM)
initial: test_initial_list.cpp $(MODULES)
	$(CC) $(CFLAGS) -o $(PROGRAM) test_initial_list.cpp  $(MODULES) -I $(INCLUDEPATH) && ./$(PROGRAM)
.PHONY: clean
clean:;	rm -f *.o $(PROGRAM)
