#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook: protected Piece {
    bool has_moved = false;
    public:
        Rook(int X, int Y, int C, int ID);
        bool legal_move(int i,int j);
        bool gethm();
};

#endif