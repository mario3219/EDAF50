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
CXXFLAGS += -Wmissing-braces -Wparentheses -Wold-style-cast -Wconversion
CXXFLAGS += -std=c++11 
CXXFLAGS += $(DEPFLAGS)
LDFLAGS =   -g 
#CPPFLAGS =  -stdlib=libc++
#CXXFLAGS += -stdlib=libc++
#LDFLAGS +=  -stdlib=libc++

# Targets
PROGS = memerrortest morsetest editortest count_objs integer_conversion

all: $(PROGS)

# Targets rely on implicit rules for compiling and linking
memerrortest: memerrortest.o
morsetest: morsetest.o morsecode.o
editortest: editortest.o editor.o
count_objs: count_objs.o
integer_conversion: integer_conversion.o


# Phony targets
.PHONY: all clean distclean macclean

# Standard clean
clean:
	-rm -f *.o $(PROGS)

distclean: clean
	-rm *.d

macclean: distclean
	-rm -r $(addsuffix .dSYM, $(PROGS)) 

# Include the *.d files
SRC = $(wildcard *.cc)
-include $(SRC:.cc=.d)
