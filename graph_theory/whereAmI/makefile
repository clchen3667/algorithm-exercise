#this is a bfs-for-shortest_path makefile

.PHONY:clean depen

depen=clean main.o find_start.o bfs.o

all:$(depen)
	g++ -o main main.o find_start.o bfs.o

main.o:main.cpp
	g++ -std=c++11 -c main.cpp

find_start.o:find_start.cpp
	g++ -std=c++11 -c find_start.cpp

bfs.o:bfs.cpp
	g++ -std=c++11 -c bfs.cpp

clean:
	-rm $(depen)
