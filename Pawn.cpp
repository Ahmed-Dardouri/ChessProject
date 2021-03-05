#include "Piece.h"
#include "Pawn.h"


Pawn::Pawn(int X, int Y, int C, int ID){
    Piece(X,Y,C,ID);
}
Pawn::Pawn(){
    Piece();
}

bool Pawn::legal_move(int i,int j){
    bool ok = true;
    if ((i == x) && (j == y)){
        ok = false;
    }
    if (is_pinned){
        ok = false;
    }
    return ok;
}
bool Pawn::gethm(){
    return has_moved;
}