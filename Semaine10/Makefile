GRAPHIC_PROGS=$(wildcard exemple-graphisme*.cpp segment*.cpp cercle*.cpp premier-dessin*.cpp disque*.cpp souris*.cpp)
OTHER_PROGS=$(wildcard factorielle-*.cpp)
PROGS=$(GRAPHIC_PROGS) $(OTHER_PROGS)
TARGET=$(PROGS:%.cpp=%)

# -NDEBUG pour tester comme dans l'environnement conda où elle est définie
CXXFLAGS+=-std=c++11 -Wall -Wno-narrowing -pedantic -DNDEBUG

all: $(TARGET)

# filter-out factorielle factorielle-test factorielle-exemple fibonacci-correction fibonacci-exemple-correction fibonacci-test-correction affiche-ppm mlv-test/11_turtle, $(TARGET))

factorielle-exemple: factorielle.o factorielle-exemple.o
	g++ $^ -o $@

factorielle-test: factorielle.o factorielle-test.o
	g++ $^ -o $@

fibonacci-exemple-correction: fibonacci-correction.o fibonacci-exemple-correction.o
	g++ $^ -o $@

fibonacci-test-correction: fibonacci-correction.o factorielle-test-correction.o
	g++ $^ -o $@

%.o: %.cpp
	g++ $(CXXFLAGS) -c $^ -o $@

$(GRAPHIC_PROGS:%.cpp=%): %: %.o primitives.o
	g++ $(CXXFLAGS) $(LDFLAGS) $^ -o $@ -lsfml-window -lsfml-graphics -lsfml-system

clean:
	-rm $(TARGET) *.o
