#  Author : Indresh Kumar Gupta
#  Purpose : To compile all the cpp files
#  Version : 1.1

all: obj/undirected_driver.o obj/directed_driver.o
	g++ -w -o bin/undirected_driver obj/undirected_driver.o -Wno-deprecated
	g++ -w -o bin/directed_driver obj/directed_driver.o -Wno-deprecated

obj/directed_driver.o: src/directed_driver.cpp
	g++ -c -o obj/directed_driver.o src/directed_driver.cpp -Wno-deprecated

obj/undirected_driver.o: src/undirected_driver.cpp
	g++ -c -o obj/undirected_driver.o src/undirected_driver.cpp -Wno-deprecated

clean:
	rm -f obj/*
	rm -f bin/*
