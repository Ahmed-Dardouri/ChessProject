#include "Game.h"


Game::Game(){
    
    Rook *  wra  = new Rook(7,0,0,0);
    Knight * wnb = new Knight(7,1,0,1);
    Bishop * wbc = new Bishop(7,2,0,2);
    Queen * wqd  = new Queen(7,3,0,3);
    King * wke   = new King(7,4,0,4);
    Bishop * wbf = new Bishop(7,5,0,5);
    Knight * wng = new Knight(7,6,0,6);
    Rook * wrh   = new Rook(7,7,0,7);
    Pawn * wpa   = new Pawn(6,0,0,8);
    Pawn * wpb   = new Pawn(6,1,0,9);
    Pawn * wpc   = new Pawn(6,2,0,10);
    Pawn * wpd   = new Pawn(6,3,0,11);
    Pawn * wpe   = new Pawn(6,4,0,12);
    Pawn * wpf   = new Pawn(6,5,0,13);
    Pawn * wpg   = new Pawn(6,6,0,14);
    Pawn * wph   = new Pawn(6,7,0,15);
    Rook * bra   = new Rook(0,0,1,16);
    Knight * bnb = new Knight(0,1,1,17);
    Bishop * bbc = new Bishop(0,2,1,18);
    Queen * bqd  = new Queen(0,3,1,19);
    King * bke   = new King(0,4,1,20);
    Bishop * bbf = new Bishop(0,5,1,21);
    Knight * bng = new Knight(0,6,1,22);
    Rook * brh   = new Rook(0,7,1,23);
    Pawn * bpa   = new Pawn(1,0,1,24);
    Pawn * bpb   = new Pawn(1,1,1,25);
    Pawn * bpc   = new Pawn(1,2,1,26);
    Pawn * bpd   = new Pawn(1,3,1,27);
    Pawn * bpe   = new Pawn(1,4,1,28);
    Pawn * bpf   = new Pawn(1,5,1,29);
    Pawn * bpg   = new Pawn(1,6,1,30);
    Pawn * bph   = new Pawn(1,7,1,31);

    pieces.push_back(wra);
    pieces.push_back(wnb);
    pieces.push_back(wbc);
    pieces.push_back(wqd);
    pieces.push_back(wke);
    pieces.push_back(wbf);
    pieces.push_back(wng);
    pieces.push_back(wrh);
    pieces.push_back(wpa);
    pieces.push_back(wpb);
    pieces.push_back(wpc);
    pieces.push_back(wpd);
    pieces.push_back(wpe);
    pieces.push_back(wpf);
    pieces.push_back(wpg);
    pieces.push_back(wph);
    pieces.push_back(bra);
    pieces.push_back(bnb);
    pieces.push_back(bbc);
    pieces.push_back(bqd);
    pieces.push_back(bke);
    pieces.push_back(bbf);
    pieces.push_back(bng);
    pieces.push_back(brh);
    pieces.push_back(bpa);
    pieces.push_back(bpb);
    pieces.push_back(bpc);
    pieces.push_back(bpd);
    pieces.push_back(bpe);
    pieces.push_back(bpf);
    pieces.push_back(bpg);
    pieces.push_back(bph);
    
    cout<<pieces[0]->geta()<<endl;


/*
    for (int i = 0; i < 8;i++){
        for (int j = 0; j < 8;j++){
            Board[i][j] = 50;
        }
    }
    for (int i = 0; i < 32;i++){
        putPiece(i);
    };
    for (int i = 0; i < 8;i++){
        for (int j = 0; j < 8;j++){
            cout<<Board[i][j]<<" ";
        }
        cout<<endl;
    }
    abstractMove(7,1,5,2);
    
}
*/
/*void Game::putPiece(int ID){
    Piece p = pieces[ID];
    Board[p.getx()][p.gety()] = p.getid();
}
Piece Game::getPiece(int X,int Y){
    int pid = Board[X][Y];
    return pieces[pid];
}
void Game::abstractMove(int x1,int y1,int x2,int y2){
    int pid = Board[x1][y1];
    if (pid < 32){
        Board[x1][y1] = 50;
        Board[x2][y2] = pid;
        pieces[pid].setx(x2);
        pieces[pid].sety(y2);
    }
}
/*void Game::showBoard(){
    for (int i = 0; i < 8;i++){
        for (int j = 0; j < 8;j++){

            cout<<Board[i][j]<<setw(4)<<" ";
        }
        cout<<endl;
    }
*/
}