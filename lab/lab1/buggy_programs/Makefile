# Define the compiler and the linker. The linker must be defined since
# the implicit rule for linking uses CC as the linker. g++ can be
# changed to clang++.
CXX = g++
CC  = $(CXX)

# Define preprocessor, compiler, and linker flags. Uncomment the # lines
# if you use clang++ and wish to use libc++ instead of GNU's libstdc++.
# -g is for debugging.
CPPFLAGS =  -std=c++11 -I.
CXXFLAGS =  -O0 -Wall -Wextra -pedantic-errors -Wold-style-cast
CXXFLAGS += -std=c++11
CXXFLAGS += -g
LDFLAGS =   -g
# CPPFLAGS += -stdlib=libc++
# CXXFLAGS += -stdlib=libc++
# LDFLAGS +=  -stdlib=libc++

PROGS=ub leak bounds bounds-heap dangling sum

ALL: $(PROGS)

leak: leak.o
	$(CC) -o leak leak.cc

dangling: dangling.o
	$(CC) -o dangling dangling.cc

bounds: bounds.o
	$(CC) -o bounds bounds.cc

bounds-heap: bounds-heap.o
	$(CC) -o bounds-heap bounds-heap.cc

ub: ub.o
	$(CC) -o ub ub.cc

sum: sum.o
	$(CC) -o sum sum.cc

# Targets
# Phony targets
.PHONY: all clean test

# Standard clean
clean:
	-rm  $(PROGS)
	-rm  $(PROGS:=.o)
	-rm -r $(addsuffix .dSYM, $(PROGS))
