SUFFIX   = .cpp
CC = g++
CFLAGS   = -Wall -O2

PROGRAM = exe.out
MODULES = selection_sort.cpp rand_list.cpp gen_random.cpp
INCLUDEPATH = $(if $(filter $(origin GUMPTION),undefined),$(error GUMPTION is not set.),$(GUMPTION))/lib


univ: test_selection_sort.cpp $(MODULES)
	$(CC) $(CFLAGS) -o $(PROGRAM) test_selection_sort.cpp $(MODULES) -I $(INCLUDEPATH)

random: test_random.cpp $(MODULES)
	$(CC) $(CFLAGS) -o $(PROGRAM) test_random.cpp  $(MODULES) -I $(INCLUDEPATH)
.PHONY: clean
clean:;	rm -f *.o $(PROGRAM)
