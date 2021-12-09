################
### Settings ###
################
# Compiler
CC = g++
CFLAGS = -O0 --std=c++11 -g -Wall -lm
# Program settings
APPNAME = midi-parser
EXT = .cpp
DIRSRC = src
# Build settings
CLEAN = true
DIRINT = intermediate
DIROBJ = $(DIRINT)/obj
DIRDEP = $(DIRINT)/dep


#####################
### Seach sources ###
#####################
SRC = $(shell find $(DIRSRC) -name *$(EXT))
OBJ = $(SRC:$(DIRSRC)/%$(EXT)=$(DIROBJ)/%.o)
DEP = $(OBJ:$(DIROBJ)/%.o=$(DIRDEP)/%.d)

all: $(APPNAME)

# Build the app
$(APPNAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Create dependency rules
DIRDEP/%.d: $(SRCDIR)/%$(EXT)
	mkdir -p "$(shell dirname $@)"
	@$(CC) $(CFLAGS) $< -MM -MT $(@:$(DIRDEP)/%.d=$(DIROBJ)/%.o) >$@
-include $(DEP)

# Build object files
$(DIROBJ)/%.o: $(DIRSRC)/%$(EXT)
	mkdir -p "$(shell dirname $@)"
	$(CC) $(CFLAGS) -o $@ -c $<