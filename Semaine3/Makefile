SOURCES=$(wildcard *-correction.cpp)
PROG=$(SOURCES:%.cpp=%)

CXXFLAGS=-g -Wall -pedantic -Wno-sign-compare -Wno-unused-value -std=c++11 

test: $(PROG)
	for prog in $(PROG); do $$prog; done

clean:
	-rm $(PROG)
