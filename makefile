all: binary

binary: make_build_dir GameMap.o Player.o Game.o
	mkdir -p bin
	g++ ./build/GameMap.o ./build/Player.o ./build/Game.o -lsfml-window -lsfml-graphics -lsfml-system -o ./bin/wolfray

GameMap.o: ./src/GameMap.cpp ./src/GameMap.h
	g++ -std=c++11 -c -g ./src/GameMap.cpp -o ./build/GameMap.o

Player.o: ./src/Player.cpp ./src/Player.h
	g++ -std=c++11 -c -g ./src/Player.cpp -o ./build/Player.o

Game.o: ./src/Game.cpp
	g++ -std=c++11 -c -g ./src/Game.cpp -o ./build/Game.o
make_build_dir:
	mkdir -p build

clean:
	rm -rf build
	rm -rf bin
