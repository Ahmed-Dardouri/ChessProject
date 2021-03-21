#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <cmath>
#include "Piece.h"
#include "Knight.h"
#include "Pawn.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Rook.h"
#include "List.h"
#include <iomanip>
using namespace std;

class Game{
    
    private:
        int turn;
        int Board[8][8];
        vector <Piece *> pieces;
    public:
        Game();
        vector <vector<int>> target_Squares(int, int);
        vector <vector<int>> target_Pieces(int, int);
        void putPiece(int ID);
        void initiateBoard();
        void abstractMove(int,int,int,int);
        void showBoard();

        void move(int,int,int,int);

        bool king_in_check(int,int);
        bool InBetween_pieces(int,int,int,int);
        List scan_for_targets();
        
};


    

#endif