#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn: public Piece {
    bool has_moved = false;
    public:
        Pawn();
        Pawn(int , int , int , int );

        bool legal_move(int i,int j);
        bool gethm();
};

#endif