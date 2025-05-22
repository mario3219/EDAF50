# Define the compiler and the linker. The linker must be defined since
# the implicit rule for linking uses CC as the linker. g++ can be
# changed to clang++.
CXX = g++
CC  = $(CXX)

# Generate dependencies in *.d files
DEPFLAGS = -MT $@ -MMD -MP -MF $*.d

# Define preprocessor, compiler, and linker flags. Uncomment the # lines
# if you use clang++ and wish to use libc++ instead of GNU's libstdc++.
# -g is for debugging.
CPPFLAGS =  -Iinclude
CXXFLAGS =  -O2 -Wall -Wextra -pedantic-errors -Wold-style-cast 

# NOTE: changed from std=c++11 -> std=c++20
CXXFLAGS += -std=c++20 
CXXFLAGS += -g
CXXFLAGS += $(DEPFLAGS)
LDFLAGS =   -g -Llib
#CPPFLAGS += -stdlib=libc++
#CXXFLAGS += -stdlib=libc++
#LDFLAGS +=  -stdlib=libc++

# Targets

all: lib/libclientserver.a
	make -C main

run:
	./main/main
	
#insert execute scripts here

# Create the library; ranlib is for Darwin (OS X) and maybe other systems.
# Doesn't seem to do any damage on other systems.

SRC_COMMON = $(wildcard src/common/*.cc)

# Create library from src/common folder, move content to /lib
lib/libclientserver.a: $(SRC_COMMON:.cc=.o) 
	mkdir -p lib
	ar rv lib/libclientserver.a $(SRC_COMMON:.cc=.o)
	ranlib lib/libclientserver.a

# Phony targets
.PHONY: all clean distclean

# Standard clean
clean:
	-rm $(SRC_COMMON:.cc=.o)
	
distclean: clean
	-rm lib/libclientserver.a
	-rmdir lib
	-rm $(SRC_COMMON:.cc=.d)
	make -C main distclean


# Include the *.d files
-include $(SRC_COMMON:.cc=.d)
