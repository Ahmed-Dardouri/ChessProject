#include "Bishop.h"
#include <cmath>
#include "Piece.h"

bool Bishop::legal_move(int i,int j){
    bool ok = true;
    if (abs(i - x) != abs(j - y)){
        ok = false;
    }
    return ok;
}