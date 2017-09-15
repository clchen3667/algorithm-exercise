#this is a Count number's factors' makefile

.PHONY:clean depen

depen=clean main.o all_prime_factors.o count_numbers_factors.o

all:$(depen)
	g++ -o main main.o all_prime_factors.o

main.o:main.cpp
	g++ -std=c++11 -c main.cpp

all_prime_factors.o:
	g++ -std=c++11 -c all_prime_factors.cpp count_numbers_factors.cpp

clean:
	-rm $(depen)
