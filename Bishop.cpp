#include "Bishop.h"
#include <cmath>
#include "Piece.h"


Bishop::Bishop(int X, int Y, int C, int ID){
    Piece(X,Y,C,ID);
}
Bishop::Bishop(){
    Piece();
}

bool Bishop::legal_move(int i,int j){
    bool ok = true;
    if (abs(i - x) != abs(j - y)){
        ok = false;
    }
    return ok;
}