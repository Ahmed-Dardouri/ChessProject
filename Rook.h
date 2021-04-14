#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook: public Piece {
    public:
        Rook(int , int , int , int ,char);
        bool legal_move(int i,int j);
};

#endif