parser.x: main.o
	g++ -o parser.x  main.o
main.o: main.cpp parser.h parser.hpp
	g++ -c -std=c++11 main.cpp
clean:
	rm *.o parser.x
