CXX = g++

TARGET = game

OBJS = Bishop.o Game.o King.o Knight.o main.o Pawn.o Piece.o Queen.o Rook.o

$(TARGET): $(OBJS)
	$(CXX) $^ -o $@

%.o: %.cpp
	$(CXX) -c $<

%.o: %.cpp %.hpp 
	$(CXX) -c $<
clean:
	rm $(OBJS) $(TARGET)