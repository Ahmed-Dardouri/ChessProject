LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lpthread

game: Bishop.o Game.o King.o Knight.o main.o Pawn.o Piece.o Queen.o Rook.o
	g++ *.o -o game -L /usr/include/SFML/lib $(LIBS)

main.o: main.cpp
	g++ -c main.cpp

Game.o: Game.cpp Game.hpp 
	g++ -c Game.cpp

Bishop.o: Bishop.cpp Bishop.hpp
	g++ -c Bishop.cpp

King.o: King.cpp King.hpp
	g++ -c King.cpp

Knight.o: Knight.cpp Knight.hpp
	g++ -c Knight.cpp

Pawn.o: Pawn.cpp Pawn.hpp
	g++ -c Pawn.cpp

Piece.o: Piece.cpp Piece.hpp
	g++ -c Piece.cpp

Queen.o: Queen.cpp Queen.hpp
	g++ -c Queen.cpp

Rook.o: Rook.cpp Rook.hpp
	g++ -c Rook.cpp

clean:
	rm *.o game