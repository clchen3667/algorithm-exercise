#this is a words typo makefile

.PHONY:clean depen

depen=clean main.o helper.o strDis.o

all:$(depen)
	g++ -o main main.o helper.o strDis.o

main.o:main.cpp
	g++ -std=c++11 -c main.cpp

helper.o:helper.cpp
	g++ -std=c++11 -c helper.cpp

strDis.o:strDis.cpp
	g++ -std=c++11 -c strDis.cpp

clean:
	-rm $(depen)
