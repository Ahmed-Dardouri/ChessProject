#include "Knight.h"
#include <cmath>
#include "Piece.h"

Knight::Knight(int X, int Y, int C, int ID){
    x = X;
    y = Y;
    color = C;
    id = ID;
}

bool Knight::legal_move(int i,int j){
    bool ok = true;
    if ((i == x) || (j == y)){
        ok = false;
    }
    if (is_pinned){
        ok = false;
    }
    if (abs(x - i) == 2){
        if(abs(y - j) != 1){
            ok = false;
        }
    }
    else if (abs(y - j) == 2){
        if(abs(x - i) != 1){
            ok = false;
        }
    }
    else{
        ok = false;
    }

    return ok;
    
}