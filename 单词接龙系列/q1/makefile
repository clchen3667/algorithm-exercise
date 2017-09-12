# this is a q1 makefile
.PHONY:clean depen

depen=clean main.o

all:$(depen)
	g++ -o main main.o

main.o:main.cpp
	g++ -std=c++11 -c main.cpp

clean:
	-rm $(depen)
