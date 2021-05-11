#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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
using namespace sf;

class Game
{

private:
    int size = 56;
    
    Sprite f[32];
    int turn=0;
    int Board[8][8] = {
        16,17,18,19,20,21,22,23,
        24,25,26,27,28,29,30,31,
        50,50,50,50,50,50,50,50,
        50,50,50,50,50,50,50,50,
        50,50,50,50,50,50,50,50,
        50,50,50,50,50,50,50,50,
        8 ,9 ,10,11,12,13,14,15,
        0 ,1 ,2 , 3, 4, 5, 6, 7,
    };
    vector<Piece *> pieces;
    int p_moved=100;
    bool test;
    bool game_over = false;
public:
    Game();
    void loadTexture(int id);
    void loadPosition();
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
    bool castle(int i, int j);
    bool king_in_check(int, int);
    bool InBetween_pieces(int, int, int, int);
    bool verify_move(string);
    vector<int> translate_move(string);
    bool pawn_mouvement(int, int, int, int, int);
    vector<int> input_move();
    bool move (int,int,int,int);
    void setpmoved(int x)
    {
        p_moved = x;
    }
    void switchTurn();  
};

#endif
