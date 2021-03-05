#ifndef KING_H
#define KING_H

#include "Piece.h"

class King: public Piece {
    bool has_moved = false;
    public:
        King();
        King(int , int , int , int );

        bool legal_move(int i,int j);
        bool gethm();
};

#endif