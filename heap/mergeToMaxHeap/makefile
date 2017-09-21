#this is a heap_builder makefile
.PHONY:claen depen
	
depen=clean main.o heap_maker.o

all:$(depen)
	g++ -o main main.o heap_maker.o

main.o:main.cpp
	g++ -std=c++11 -c main.cpp

heap_maker.o:heap_maker.cpp
	G++ -std=c++11 -c heap_maker.cpp

clean:
	-rm $(depen)
