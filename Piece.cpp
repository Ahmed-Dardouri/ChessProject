#include <cmath>
#include "Piece.h"


Piece::Piece(){
    int x,y,color,id ,name;
}

void Piece::setx(int X){
    x = X;
}
void Piece::sety(int Y){
    y = Y;
}
void Piece::setpin(bool pin){
    is_pinned = pin;
}
int Piece::getx(){
    return x;
}
int Piece::gety(){
    return y;
}
bool Piece::getpin(){
    return is_pinned;
}
int Piece::getid(){
    return id;
}
int Piece::getcolor(){
    return color;
}
char Piece::getname(){
    return name ;
}
bool Piece::legal_move(int X,int Y){
    return false;
}