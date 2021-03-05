#ifndef GAME_H
#define GAME_H

#include "Piece.h"
#include "Knight.h"
#include "Pawn.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Rook.h"
#include "List.h"

class Game{
    
private:
    int turn;
    int Board[8][8];
    List targets_list;
    void move(int,int,int,int);
    bool king_in_check();
    bool InBetween_pieces(Piece,int,int);	
    List scan_for_targets();
    
    
    

public:
    Game(/* arg s*/);
    ~Game();
};


    

#endif