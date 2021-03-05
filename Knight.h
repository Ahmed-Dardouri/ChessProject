#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

class Knight: public Piece {

    public:
        Knight();
        Knight(int , int , int , int );

        bool legal_move(int i,int j);
};

#endif