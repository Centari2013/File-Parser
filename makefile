proj7.x: driver.o
	g++ -o proj7.x  driver.o
driver.o: driver.cpp parser.h parser.hpp
	g++ -c -std=c++11 driver.cpp
clean:
	rm *.o proj7.x
