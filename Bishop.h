#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop: private Piece {

    public:
        bool legal_move(int i,int j);
        
            
};

#endif