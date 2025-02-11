# Define the compiler and the linker. The linker must be defined since
# the implicit rule for linking uses CC as the linker. g++ can be
# changed to clang++.
CXX = g++
CC = $(CXX)

# Generate dependencies in *.d files
DEPFLAGS = -MT $@ -MMD -MP -MF $*.d

# Define preprocessor, compiler, and linker flags. Uncomment the # lines
# if you use clang++ and wish to use libc++ instead of GNU’s libstdc++.
# -g is for debugging.
CPPFLAGS = -std=c++11 -I.
CXXFLAGS = -O2 -Wall -Wextra -pedantic-errors -Wold-style-cast
CXXFLAGS += -std=c++11
CXXFLAGS += -g
CXXFLAGS += $(DEPFLAGS)
LDFLAGS = -g

# Targets
PROGS = build words test_dictionary
all: $(PROGS)

# Targets rely on implicit rules for compiling and linking
#build:
# /usr/share/dict

build: build.o trigrams.o
	$(CC) -o build build.o trigrams.o

words:
	./build < /usr/share/dict/words > words.txt

test_dictionary: test_dictionary.o dictionary.o
	$(CC) -o test_dictionary test_dictionary.o dictionary.o

debug_dictionary:
	g++ -g -c dictionary.cc
	g++ -g -c test_dictionary.cc
	g++ -g -o debug_dictionary dictionary.o test_dictionary.o
	gdb debug_dictionary

# Phony targets
.PHONY: all clean distclean

# Standard clean
clean:
	rm -f *.o $(PROGS)
	rm -f words.txt

distclean: clean
	rm *.d

# Include the *.d files
SRC = $(wildcard *.cc)
-include $(SRC:.cc=.d)
