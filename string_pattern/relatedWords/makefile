#this a related words makefile

.PHONY:clean depen

depen=clean main.o helper.o related_words.o

all:$(depen)
	g++ -o main main.o helper.o related_words.o

main.o:main.cpp
	g++ -std=c++11 -c main.cpp

helper.o:helper.cpp
	g++ -std=c++11 -c helper.cpp

related_words.o:related_words.cpp
	g++ -std=c++11 -c related_words.cpp

clean:
	-rm $(depen)
