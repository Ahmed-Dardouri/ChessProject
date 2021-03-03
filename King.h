#ifndef KING_H
#define KING_H

#include "Piece.h"

class King: private Piece {
    bool has_moved = false;
    public:
        bool legal_move(int i,int j);
        bool gethm();
};

#endif