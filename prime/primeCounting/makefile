#this is a prime_counting makefile

.PHONY:clean depen

depen=clean main.o prime_counting.o

all:$(depen)
	g++ -o main main.o prime_counting.o

main.o:main.cpp
	g++ -std=c++11 -c main.cpp

prime_counting.o:prime_counting.cpp
	g++ -std=c++11 -c prime_counting.cpp

clean:
	-rm $(depen)
