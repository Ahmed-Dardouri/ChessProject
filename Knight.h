#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

class Knight: public Piece {

    public:
        Knight(int , int , int , int ,char);

        bool legal_move(int i,int j);
};

#endif