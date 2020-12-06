all: Graf-FB.o 
	c++ -std=c++11 -g main.o -o main
main.o: Graf-FB.cpp floid.cpp floid.h
	c++ -std=c++11 -c -g main.cpp
clean:
	rm *.o main