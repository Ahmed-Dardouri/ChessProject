#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen: public Piece {
    public:
        Queen(int , int , int , int ,char);
        bool legal_move(int i,int j);
};

#endif