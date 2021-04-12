#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook: public Piece {
    int a = 10;
    public:
        int geta();
        Rook(int , int , int , int ,char);
        bool legal_move(int i,int j);
};

#endif