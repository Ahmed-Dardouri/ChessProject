#ifndef PIECE_H
#define PIECE_H
#include <iostream>

using namespace std;

class Piece{
    protected:
        int color;
        bool is_pinned = false;
        int id;
        int x;
        int y;
    public:
        
        Piece();
        void setx(int X);
        void sety(int Y);
        void setpin(bool pin);
        int getx();
        int gety();
        bool getpin();
        int getid();
        int getcolor();

        virtual int geta(){
            return 100000;
        }
        virtual bool legal_move(int ,int );
        

};

#endif