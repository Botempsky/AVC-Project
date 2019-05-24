# Specify the final target name
EXE := main

# Specify the source files
# Effectively list all source files in the current directory
SRC := $(wildcard *.cpp)

# Specify where to put the build temporary files
BLD := obj

# From the source file list, get the corresponding object file list
# This is a clearer syntax for $(patsubst %.cpp,$(BLD)/%.o,$(SRC))
OBJ := $(SRC:%.cpp=$(BLD)/%.o)

# From the object file list, get the dependency file list to handle automatic
# recompilation when a header file is modified
DEP := $(OBJ:.o=.d)

# Specify preprocessor flags (this is a built-in variable)
CPPFLAGS := -I../include
# Required flags to enable the automatic dependency generation by the compiler
CPPFLAGS += -MMD -MP

# Specify compiler flags (this is a built-in variable)
# Here some basic warning flags
CXXFLAGS := -Wall -W -pedantic

# Specify linker flags (this is a built-in variable)
LDFLAGS := -L../lib -le101

# Specify linker libraries (this is a built-in variable)
# m is the maths library
LDLIBS := -lm

# Tell make that these target are not real files
.PHONY: all clean

# Now the standard primary rule
all: $(EXE)

# How do we make $(EXE) ? Remember the recipe describe the linking phase
$(EXE): $(OBJ)
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@
	
# The build directory is custom so we need to tell make how to do it
# The build directory must exist before trying to compile
$(BLD)/%.o: %.cpp | $(BLD)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ -c $<

# Simple rule to create the build directory if needed
$(BLD):
	mkdir $@

# Let's clean up the mess, we can just remove the build directory alonside the executable
clean:
	$(RM) -r $(BLD) $(EXE)

# Don't forget to include the dependency files to let make know when to recompile
-include $(DEP)