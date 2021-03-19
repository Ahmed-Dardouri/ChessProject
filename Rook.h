#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook: public Piece {
    bool has_moved = false;
    int a = 10;
    public:
        int geta();
        Rook(int , int , int , int );
        bool legal_move(int i,int j);
        bool gethm();
};

#endif