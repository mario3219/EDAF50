# Define the compiler and the linker. The linker must be defined since
# the implicit rule for linking uses CC as the linker. g++ can be
# changed to clang++.
CXX = g++ 
CC  = g++

# Generate dependencies in *.d files
DEPFLAGS = -MT $@ -MMD -MP -MF $*.d

# Define preprocessor, compiler, and linker flags. Uncomment the # lines
# if you use clang++ and wish to use libc++ instead of GNU's libstdc++.
CPPFLAGS =  -std=c++11 -I.
CXXFLAGS =  -g -O2 -Wall -W -pedantic-errors
CXXFLAGS += -Wmissing-braces -Wparentheses -Wold-style-cast 
CXXFLAGS += -std=c++11 
CXXFLAGS += $(DEPFLAGS)
LDFLAGS =   -g 
#CPPFLAGS =  -stdlib=libc++
#CXXFLAGS += -stdlib=libc++
#LDFLAGS +=  -stdlib=libc++

# Targets
PROGS = sizetest datetest palindrometest pointtest include_test enumtest

all: $(PROGS)

# Targets rely on implicit rules for compiling and linking
sizetest: sizetest.o point.o
datetest: datetest.o date.o
palindrometest: palindrometest.o
pointtest: pointtest.o point.o
enumtest: enumtest.o eyes.o traffic_light.o
include_test: include_test.o


# Phony targets
.PHONY: all clean distclean

# Standard clean
clean:
	rm -f *.o $(PROGS)

distclean: clean
	rm *.d

# Include the *.d files
SRC = $(wildcard *.cc)
-include $(SRC:.cc=.d)
