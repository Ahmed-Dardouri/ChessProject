#include "King.h"
#include <cmath>
#include "Piece.h"


King::King(int X, int Y, int C, int ID , char N){
    x = X;
    y = Y;
    color = C;
    id = ID;
    name = N;
}

bool King::legal_move(int i,int j){
    bool ok = true;
    if ((i == x) && (j == y)){
        ok = false;
    }else if (abs(i - x) > 1 || abs(j - y) > 1){              
        ok = false;
    }
    return ok;   
}
bool King::gethm(){
    return has_moved;
}