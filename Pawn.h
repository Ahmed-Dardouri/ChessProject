#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn: private Piece {
    bool has_moved = false;
    public:
        bool legal_move(int i,int j);
        bool gethm();
};

#endif