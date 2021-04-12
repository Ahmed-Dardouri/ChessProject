#include "Queen.h"
#include <cmath>
#include "Piece.h"


Queen::Queen(int X, int Y, int C, int ID,char N){
    x = X;
    y = Y;
    color = C;
    id = ID;
    name = N;
}
bool Queen::legal_move(int i,int j){
    bool ok = true;
    //cout<<"Queen"<<endl;
    if ((i != x) && (j != y)){ 
        if (abs(i - x) != abs(j - y)){
            ok = false;
        }
    }   
    return ok;
    
}