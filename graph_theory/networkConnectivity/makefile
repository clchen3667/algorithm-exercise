#this is a Network connectivity makefile
.PHONY:clean depen

depen=clean main.o bfs_graph.o

all:$(depen)
	g++ -o main main.o bfs_graph.o

main.o:main.cpp
	g++ -std=c++11 -c main.cpp

bfs_graph.o:bfs_graph.cpp
	g++ -std=c++11 -c bfs_graph.cpp

clean:
	-rm $(depen)
