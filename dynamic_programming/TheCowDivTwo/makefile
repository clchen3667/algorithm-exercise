#this is a dp_subset problem makefile
.PHONY:clean depen

depen=clean main.o theCowDivTwo.o

all:$(depen)
	g++ -o main main.o

main.o:main.cpp
	g++ -std=c++11 -c main.cpp

theCowDivTwo.o:theCowDivTwo.cpp
	g++ -std=c++11 -c theCowDivTwo.cpp

clean:
	-rm $(depen)
