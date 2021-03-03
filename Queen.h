#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen: private Piece {

    public:
        bool legal_move(int i,int j);

};

#endif