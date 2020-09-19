#Makefile

UNAME := $(shell uname)

CPP_FILES = $(wildcard *.cpp)
OBJ = $(CPP_FILES:.cpp=.o)
CC_FLAGS = -std=c++11 -Wall -pedantic

ifeq ($(OS), Windows_NT)
	LD_FLAGS = -Dsrandom=srand -Drandom=rand
else
	LD_FLAGS = 
endif

all: program

program: $(OBJ)
	c++ $(CC_FLAGS) $(LD_FLAGS) $(OBJ) -o program.out

%.o: %.cpp %.hpp
	c++ $(CC_FLAGS) $(LD_FLAGS) -c $< -o $@

clean: clean_object
	rm -rfv mk.tmp
	rm -rfv *.out

clean_object:
	rm -rfv *.o
