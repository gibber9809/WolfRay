all: binary

binary: Map Player
	g++ ./build/Map.o ./build/Player.o -o ./bin/wolfray

Map: ./src/Map.cpp ./src/Map.h
	g++ -std=c++11 -c ./src/Map.cpp -o ./build/Map.o

Player: ./src/Player.cpp ./src/Player.h
	g++ -std=c++11 -c ./src/Player.cpp -o ./build/Player.o

clean:
	rm -rf ./build
	rm -rf ./bin
