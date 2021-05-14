CXX = g++

LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lpthread

TARGET = game

OBJS = Bishop.o Game.o King.o Knight.o main.o Pawn.o Piece.o Queen.o Rook.o

CXXFLAGS = -L

INC = /usr/include/SFML/lib

$(TARGET): $(OBJS)
	$(CXX) $^ -o $@ $(CXXFLAGS) $(INC) $(LIBS)

%.o: %.cpp
	$(CXX) -c $<

%.o: %.cpp %.hpp 
	$(CXX) -c $<
clean:
	rm $(OBJS) $(TARGET)