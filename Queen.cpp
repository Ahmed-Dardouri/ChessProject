#include "Queen.h"
#include <cmath>
#include "Piece.h"


Queen::Queen(int X, int Y, int C, int ID){
    x = X;
    y = Y;
    color = C;
    id = ID;
}


bool Queen::legal_move(int i,int j){
    bool ok = true;
    if ((i != x) && (j != y)){ 
        if (abs(i - x) != abs(j - y)){
            ok = false;
        }
    }else if (abs(i - x) != abs(j - y)){
        if ((i != x) && (j != y)){
            ok = false;
        }              
    }    
    if (is_pinned){
        ok = false;
    }
    return ok;
    
}