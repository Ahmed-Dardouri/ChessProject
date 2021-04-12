#ifndef GAME_H
#define GAME_H

#include <cctype>
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
#include <iomanip>
#include <typeinfo>
#include <string>
#include <algorithm>
using namespace std;

<<<<<<< HEAD
class Game{
    
    private:
        int turn;
        int Board[8][8];
        vector <Piece *> pieces;
    public:
        Game();
        vector <vector<int>> target_Squares(int, int);
        vector <vector<int>> white_Targets_Squares();
        vector <vector<int>> black_Targets_Squares();
        void putPiece(int ID);
        void initiateBoard();
        void abstractMove(int,int,int,int);
        void showBoard();
        void Promotion (int i, int j);
        void move(int,int,int,int);
        void castle (int i,int j);
        bool king_in_check(int,int);
        bool InBetween_pieces(int,int,int,int);
        
};
=======
class Game
{
>>>>>>> cc

private:
    int turn=0;
    int Board[8][8];
    vector<Piece *> pieces;
    int p_moved=100;

public:
    Game();
    vector<vector<int>> target_Squares(int, int);
    vector<vector<int>> target_Pieces(int, int);
    vector<vector<int>> global_Targets_List();
    vector<vector<int>> white_Targets_Squares();
    vector<vector<int>> black_Targets_Squares();
    void putPiece(int ID);
    void initiateBoard();
    void abstractMove(int, int, int, int);
    void showBoard();
    void Promotion(int i, int j);
    void castle(int i, int j);
    bool king_in_check(int, int);
    bool InBetween_pieces(int, int, int, int);
    bool verify_move(string);
    vector<int> translate_move(string);
    void move();
    void pawn_mouvement(int, int, int, int, int);
    void setpmoved(int x)
    {
        p_moved = x;
    }
};

#endif