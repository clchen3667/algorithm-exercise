.PHONY:clean depen
	
depen=clean main.o LittleElephantAndBallsAgain.o

all:$(depen)
	g++ -o main main.o LittleElephantAndBallsAgain.o

main.o:main.cpp
	g++ -std=c++11 -c main.cpp

LittleElephantAndBallsAgain.o:LittleElephantAndBallsAgain.cpp
	g++ -std=c++11 -c LittleElephantAndBallsAgain.cpp

clean:
	-rm $(depen)
