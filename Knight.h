#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

class Knight: private Piece {

    public:
        bool legal_move(int i,int j);
};

#endif