CC = g++ -g -std=c++11

all: main.out

main.out: main.o TCPconnection.o BBR.o NewReno.o Reno.o
	$(CC) $^ -o $@

main.o: source/main.cpp include/TCPconnection.hpp
	$(CC) -c $< -o $@

TCPconnection.o: source/TCPconnection.cpp include/TCPconnection.hpp include/BBR.hpp include/NewReno.hpp include/Reno.hpp
	$(CC) -c $< -o $@

BBR.o: source/BBR.cpp include/BBR.hpp
	$(CC) -c $< -o $@

NewReno.o: source/NewReno.cpp include/NewReno.hpp
	$(CC) -c $< -o $@

Reno.o: source/Reno.cpp include/Reno.hpp
	$(CC) -c $< -o $@

.PHONY: clean

clean:
	rm *.o *.out
