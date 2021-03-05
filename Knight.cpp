#include "Knight.h"
#include <cmath>
#include "Piece.h"

Knight::Knight(int X, int Y, int C, int ID){
    Piece(X,Y,C,ID);
}
Knight::Knight(){
    Piece();
}

bool Knight::legal_move(int i,int j){
    bool ok = true;
    if ((i == x) || (j == y)){
        ok = false;
    }
    if (is_pinned){
        ok = false;
    }
    
    switch (abs(x - i)){
        case 2:
            switch (abs(y - j)){
                case 1:
                    break;
                default:
                    ok = false;
                    break;
            }
        case 1:
            switch (abs(y - j)){
                case 2:
                    break;
                default:
                    ok = false;
                    break;
                }
        default:
        break;
    }
    return ok;
    
}