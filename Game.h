#ifndef GAME_H
#define GAME_H

#include "Piece.h"
#include "Knight.h"
#include "Pawn.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Rook.h"
#include "List.h"

class Game{
    
private:
    int turn;
    int Board[8][8];
    List targets_list;
    void move(int,int,int,int);
    bool king_in_check();
    bool InBetween_pieces(Piece,int,int);	
    List scan_for_targets();
    
    


    /*
    Rook   wra(7,0,0,1);
    Knight wnb(7,1,0,2);
    Bishop wbc(7,2,0,3);
    Queen  wqd(7,3,0,4);
    King   wke(7,4,0,5);
    Bishop wbf(7,5,0,6);
    Knight wng(7,1,0,7);
    Rook   wrh(7,7,0,8);
    Pawn   wpa(6,0,0,9);
    Pawn   wpb(6,1,0,10);
    Pawn   wpc(6,2,0,11);
    Pawn   wpd(6,3,0,12);
    Pawn   wpe(6,4,0,13);
    Pawn   wpf(6,5,0,14);
    Pawn   wpg(6,6,0,15);
    Pawn   wph(6,7,0,16);
    Rook   bra(0,0,1,17);
    Knight bnb(0,1,1,18);
    Bishop bbc(0,2,1,19);
    Queen  bqd(0,3,1,20);
    King   bke(0,4,1,21);
    Bishop bbf(0,5,1,22);
    Knight bng(0,6,1,23);
    Rook   brh(0,7,1,24);
    Pawn   bpa(1,0,1,25);
    Pawn   bpb(1,1,1,26);
    Pawn   bpc(1,2,1,27);
    Pawn   bpd(1,3,1,28);
    Pawn   bpe(1,4,1,29);
    Pawn   bpf(1,5,1,30);
    Pawn   bpg(1,6,1,31);
    Pawn   bph(1,7,1,32);*/

public:
    Game(/* args */);
    ~Game();
};


    

#endif