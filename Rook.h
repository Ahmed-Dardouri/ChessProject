#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook: public Piece {
    bool has_moved = false;
    public:
        Rook();
        Rook(int , int , int , int );
        bool legal_move(int i,int j);
        bool gethm();
};

#endif