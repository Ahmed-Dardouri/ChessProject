#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn: public Piece {
    bool tsm = false;
    public:
        Pawn(int , int , int , int ,char );
        bool legal_move(int i,int j);
        bool gettsm(){
            return tsm;
        }
        void settsm(bool b){
            tsm = b;
        }
};

#endif