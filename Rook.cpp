#include "Rook.h"
#include <cmath>
#include "Piece.h"



Rook::Rook(int X, int Y, int C, int ID){
    x = X;
    y = Y;
    color = C;
    id = ID;
}
bool Rook::legal_move(int i,int j){
    bool ok = true;
    if ((i != x) && (j != y)){
        ok = false;
    }
    return ok;
}
bool Rook::gethm(){
    return has_moved;
}
