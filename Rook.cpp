#include "Rook.h"
#include <cmath>
#include "Piece.h"
#include <iostream>
using namespace std;


Rook::Rook(int X, int Y, int C, int ID){
    x = X;
    y = Y;
    id = ID;
    color = C;
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
