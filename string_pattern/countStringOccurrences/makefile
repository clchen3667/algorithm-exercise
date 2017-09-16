#this is a KMP makefile

.PHONY:clean depen

depen=clean main.o kmp.o

all:$(depen)
	g++ -o main main.o kmp.o

main.o:main.cpp
	g++ -std=c++11 -c main.cpp

kmp.o:kmp.cpp
	g++ -std=c++11 -c kmp.cpp

clean:
	-rm $(depen)
