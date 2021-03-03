#include "Piece.h"
#include "Pawn.h"

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