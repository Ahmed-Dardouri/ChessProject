#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen: public Piece {

    public:
        Queen();
        Queen(int , int , int , int );

        bool legal_move(int i,int j);

};

#endif