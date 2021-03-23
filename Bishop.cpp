#include "Bishop.h"
#include <cmath>



Bishop::Bishop(int X, int Y, int C, int ID){
    x = X;
    y = Y;
    color = C;
    id = ID;
}
bool Bishop::legal_move(int i,int j){
    bool ok = true;
    if (abs(i - x) != abs(j - y)){
        ok = false;
    }
    return ok;
}