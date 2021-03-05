#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop: public Piece {

    public:
        Bishop();
        Bishop(int , int , int , int );

        bool legal_move(int i,int j);
        
            
};

#endif