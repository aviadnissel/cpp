CXX = g++
OBJECTS = Complex.o
FLAGS = -Wextra -Wall -std=c++11 -pthread -O -g
TARFILES = TimeChecker.cpp Matrix.hpp README Makefile
TIMES_TO_RUN = 500

all: timeChecker
	./timeChecker $(TIMES_TO_RUN)

timeChecker: $(OBJECTS)
	$(CXX) $(FLAGS) -c TimeChecker.cpp -o TimeChecker.o
	$(CXX) $(FLAGS) $(OBJECTS) TimeChecker.o -o timeChecker

Matrix: Matrix.hpp.gch

Matrix.hpp.gch: Matrix.hpp
	$(CXX) $(FLAGS) Matrix.hpp -o Matrix.hpp.gch

TimeChecker.o: TimeChecker.cpp
	$(CXX) $(FLAGS) -c TimeChecker.cpp

Complex.o: Complex.cpp
	$(CXX) $(FLAGS) -c Complex.cpp

clean:
	rm -f *.o timeChecker Matrix Matrix.hpp.gch

tar:
	tar cvf ex3.tar $(TARFILES)
