
game: Bishop.o Game.o King.o Knight.o main.o Pawn.o Piece.o Queen.o Rook.o
	g++ *.o -o game -L /usr/include/SFML/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lpthread

main.o: main.cpp
	g++ -c main.cpp
Game.o: Game.cpp Game.h 
	g++ -c Game.cpp

Bishop.o: Bishop.cpp Bishop.h
	g++ -c Bishop.cpp

King.o: King.cpp King.h
	g++ -c King.cpp

Knight.o: Knight.cpp Knight.h
	g++ -c Knight.cpp

Pawn.o: Pawn.cpp Pawn.h
	g++ -c Pawn.cpp

Piece.o: Piece.cpp Piece.h
	g++ -c Piece.cpp

Queen.o: Queen.cpp Queen.h
	g++ -c Queen.cpp

Rook.o: Rook.cpp Rook.h
	g++ -c Rook.cpp

clean:
	rm *.o game