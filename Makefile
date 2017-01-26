
all: main

main: main.o Game.o TextureManager.o
	g++ main.o Game.o TextureManager.o -o main -I/usr/local/include -L/usr/local/lib -lSDL2 -lSDL2_image

main.o: main.cpp Game.h
	g++ main.cpp -c -I/usr/local/include 

Game.o: Game.cpp Game.h
	g++ Game.cpp -c -I/usr/local/include 


TextureManager.o: TextureManager.cpp TextureManager.h
	g++ TextureManager.cpp -c -I/usr/local/include 

clean:
	rm *.o main
