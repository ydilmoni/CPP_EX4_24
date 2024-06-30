CXX=g++
CXXFLAGS=-std=c++14 -Werror 
VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all  --error-exitcode=99

SOURCES=main.cpp
OBJECTS=$(subst .cpp,.o,$(SOURCES))

.PHONI: cleen all valgrind run

all:main.cpp
	g++ -o main.exe main.cpp
	
run:
	./main.exe
	rm -f *.o main.exe

%.o: %.cpp
	$(CXX) $(CXXFLAGS) --compile $< -o $@

cleen:
	rm -f *.o main.exe

valgrind:$(SOURCES)
	valgrind $(VALGRIND_FLAGS) ./main.exe