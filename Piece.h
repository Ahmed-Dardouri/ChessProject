#ifndef PIECE_H
#define PIECE_H

class Piece{
    protected:
        int color;
        bool is_pinned = false;
        int id;
        int x;
        int y;
    public:
        Piece();
        Piece(int X, int Y, int C, int ID);
        void setx(int X);
        void sety(int Y);
        void setpin(bool pin);
        int getx();
        int gety();
        bool getpin();
        int getid();
        int getcolor();
};

#endif