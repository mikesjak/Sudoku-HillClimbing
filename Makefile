CXX=g++
CXXFLAGS = -Wall -pedantic -std=c++17 -g 

HEADERS = $(wildcard src/*.h)
SOURCES = $(wildcard src/*.cpp)
OBJECTS = $(SOURCES:src/%.cpp=build/%.o)
TESTS = $(wildcard tests/*.test.cpp)
PROGRAM = Sudoku

.PHONY: all
all: compile
	-rm -f build/*.o

.PHONY: run
run: $(PROGRAM)
	-rm -f build/*.o
	./app


.PHONY: compile
compile: $(PROGRAM)

Sudoku: build/main
	cp $< $@

build/main: $(OBJECTS)
	mkdir -p $(@D)
	$(CXX) $^ -o $@ 

build/%.o: src/%.cpp
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $< -c -o $@ 

.PHONY: clean
clean:
	-rm -rf build/ doc/ Sudoku debug/ .idea/

# Dependencies
CGrid.o: src/CGrid.cpp src/CGrid.h
CHillClimber.o: src/CHillClimber.cpp src/CHillClimber.h src/CGrid.h
CKeyHandler.o: src/CKeyHandler.cpp src/CKeyHandler.h
CSolver.o: src/CSolver.cpp src/CSolver.h src/CGrid.h src/CHillClimber.h src/CKeyHandler.h
main.o: src/main.cpp src/CSolver.h src/CGrid.h src/CHillClimber.h src/CKeyHandler.h
