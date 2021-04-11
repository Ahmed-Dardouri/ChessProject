#include "Game.h"


Game::Game(){
    
    Rook *  wra  = new Rook(7,0,0,0,'r');
    Knight * wnb = new Knight(7,1,0,1,'n');
    Bishop * wbc = new Bishop(7,2,0,2,'b');
    Queen * wqd  = new Queen(7,3,0,3,'q');
    King * wke   = new King(7,4,0,4,'k');
    Bishop * wbf = new Bishop(7,5,0,5,'b');
    Knight * wng = new Knight(7,6,0,6,'n');
    Rook * wrh   = new Rook(7,7,0,7,'r');
    Pawn * wpa   = new Pawn(6,0,0,8,'p');
    Pawn * wpb   = new Pawn(6,1,0,9,'p');
    Pawn * wpc   = new Pawn(6,2,0,10,'p');
    Pawn * wpd   = new Pawn(6,3,0,11,'p');
    Pawn * wpe   = new Pawn(6,4,0,12,'p');
    Pawn * wpf   = new Pawn(6,5,0,13,'p');
    Pawn * wpg   = new Pawn(6,6,0,14,'p');
    Pawn * wph   = new Pawn(6,7,0,15,'p');
    Rook * bra   = new Rook(0,0,1,16,'R');
    Knight * bnb = new Knight(0,1,1,17,'N');
    Bishop * bbc = new Bishop(0,2,1,18,'B');
    Queen * bqd  = new Queen(0,3,1,19,'Q');
    King * bke   = new King(0,4,1,20,'K');
    Bishop * bbf = new Bishop(0,5,1,21,'B');
    Knight * bng = new Knight(0,6,1,22,'N');
    Rook * brh   = new Rook(0,7,1,23,'R');
    Pawn * bpa   = new Pawn(1,0,1,24,'P');
    Pawn * bpb   = new Pawn(1,1,1,25,'P');
    Pawn * bpc   = new Pawn(1,2,1,26,'P');
    Pawn * bpd   = new Pawn(1,3,1,27,'P');
    Pawn * bpe   = new Pawn(1,4,1,28,'P');
    Pawn * bpf   = new Pawn(1,5,1,29,'P');
    Pawn * bpg   = new Pawn(1,6,1,30,'P');
    Pawn * bph   = new Pawn(1,7,1,31,'P');

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

    initiateBoard();
    showBoard();

    
}

void Game::putPiece(int ID){
    Board[pieces[ID]->getx()][pieces[ID]->gety()] = pieces[ID]->getid();
}
void Game::initiateBoard(){
    for (int i = 2; i < 6;i++){
        for (int j = 0; j < 8;j++){
            Board[i][j] = 50;
        }
    }
    for (int i = 0; i < 32;i++){  
        putPiece(i);
    }
}

void Game::abstractMove(int x1,int y1,int x2,int y2){
    int pid = Board[x1][y1];
    if (pid < 32){
        Board[x1][y1] = 50;
        Board[x2][y2] = pid;
        pieces[pid]->setx(x2);
        pieces[pid]->sety(y2);
    }
}

void Game::showBoard(){
    cout<<endl;
    for (int i = 0; i < 8;i++){
        for (int j = 0; j < 8;j++){
            if (Board [i][j] != 50) {
              cout<<setw(4);
              cout<< pieces[Board[i][j]]->getname();
            }
            else{
                cout<<setw(4);
                cout<< ".";
            }
        }
        cout<<endl;
    }
    cout<<endl;
}
bool Game::InBetween_pieces(int x1,int y1,int x2,int y2){
    int pid = Board[x1][y1];
    if (pid < 32){
        int c = pieces[pid]->getcolor();
        int c1 = 2;
        if (x1 == x2 && y1 == y2){
            return false;
        }
        if(Board[x2][y2] < 32){
            c1 = pieces[Board[x2][y2]]->getcolor();
        }
        if (c == c1){
            return true;
        }
        if (x1 == x2){
            int j = (y2-y1)/abs(y1-y2);
            for (int i = y1 + j; abs(i-y2) > 0; i += j){
                if (Board[x1][i] < 32){
                    return true;
                }
            }
        }
        else if (y1 == y2){
            int j = (x2-x1)/abs(x1-x2);
            for (int i = x1 + j ; abs(i-x2) > 0; i += j){
                if (Board[i][y1] < 32){
                    return true;
                }
            }
        }
        else if (abs(x1 - x2) == abs(y1 - y2)){
            int k = (x2-x1)/abs(x1-x2);
            int l = (y2-y1)/abs(y1-y2);
            int j = y1 + l;
            for (int i = x1 + k; abs(i-x2) > 0; i += k){
                if (Board[i][j] < 32){
                    return true;
                }
                j += l;
            }
        }
    }
    return false;
}
vector <vector<int>> Game::target_Squares(int X1, int Y1){
    vector <vector<int>> squaresList;
    vector<int> square;
    int pid = Board[X1][Y1];
    if (pid < 32){
        if (typeid(*pieces[pid]) != typeid(*pieces[8])){
            for (int i = 0; i < 8; i++){
                for (int j = 0; j < 8; j++){
                    if (i != X1 || j != Y1){
                        if (InBetween_pieces(X1,Y1,i,j) == 0){
                            if (pieces[pid]->legal_move(i,j)){
                                square.push_back(i);
                                square.push_back(j);
                                squaresList.push_back(square);
                                square.clear();
                            }
                        }
                    }
                }
            }
        }
        else{
            cout<<"check1"<<endl;
            if (pieces[pid]->getcolor() == 0){
                cout<<"check2"<<endl;
                if (Y1<7){
                    cout<<"check3"<<endl;
                    int rid = Board[X1-1][Y1+1];
                    if (!(rid < 32 && pieces[rid]->getcolor() == pieces[pid]->getcolor())){
                        cout<<"check4"<<endl;
                        square.push_back(X1-1);
                        square.push_back(Y1+1);
                        squaresList.push_back(square);
                        square.clear();                  
                    }
                }
                if (Y1>0){
                    int lid = Board[X1-1][Y1-1];
                    if (!(lid < 32 && pieces[lid]->getcolor() == pieces[pid]->getcolor())){
                        square.push_back(X1-1);
                        square.push_back(Y1-1);
                        squaresList.push_back(square);
                        square.clear();                  
                    }
                }
            }
            else{
                if (Y1<7){
                    int rid = Board[X1+1][Y1+1];
                    if (!(rid < 32 && pieces[rid]->getcolor() == pieces[pid]->getcolor())){
                        square.push_back(X1+1);
                        square.push_back(Y1+1);
                        squaresList.push_back(square);
                        square.clear();                  
                    }
                }
                if (Y1>0){
                    int lid = Board[X1+1][Y1-1];
                    if (!(lid < 32 && pieces[lid]->getcolor() == pieces[pid]->getcolor())){
                        square.push_back(X1+1);
                        square.push_back(Y1-1);
                        squaresList.push_back(square);
                        square.clear();                  
                    }
                }
            }
        }
    }
    return squaresList;
}
vector <vector<int>> Game::target_Pieces(int X, int Y){
    vector <vector<int>> s;
    vector <vector<int>> p;
    s = target_Squares(X,Y);
    for(int i=0; i < s.size(); i++){
        if (Board[s[i][0]][s[i][1]] < 32){
            p.push_back(s[i]);
        }
    }
    return p;
}
vector <vector<int>> Game::global_Targets_List(){
    vector <vector <int>> gtl;
    vector <vector <int>> s;
    for (int i = 0;i < 8;i++){
        for(int j = 0; j < 8; j++){
            if (Board[i][j]<32){
                s = target_Pieces(i,j);
                gtl.insert(gtl.end(), s.begin(), s.end());
            }
        }
    }
    return gtl;
}
bool Game::king_in_check(int X,int Y){
    vector <vector <int>> gtl;
    gtl = global_Targets_List();
    
    vector<int> kingPos = {X,Y};

    for (int i = 0; i < gtl.size(); i++)
        if (gtl[i] == kingPos) {
            return true;
        }
    return false;
 
}
vector <vector<int>> Game::global_Targets_Squares(){
    vector <vector<int>> gts;
    vector <vector<int>> s;
    for (int i=0; i<8 ,i++){
        for (int j=0 , j<8 , j++ ){
            if ( Board[i][j]<32) {
                s =target_Squares(i,j);
                gts.insert(gts.end(),s.begin(),s.end());
            }
        }
    }
    return gts;
}
void function Promotion (){
    if ( turn==0 &&  ...... ){
        if (i==0) {
            cout<< " you can promote your pawn  to Bishop, Knight,Rook or Queen"
            cin>> choice;
            switch (choice)
            {
            case B:
                 Bishop *wb2 = new Bishop(i,j,0,id1,b);
                 pieces.push_back(wb2);
                 delete Pawn(i,j,0,id1,p);
                 putPiece(id1);
                 break;
            case K:
                 Knight *wn2 = new Knight(i,j,0,id1,n);
                 pieces.push_back(wn2);
                 delete Pawn(i,j,0,id1,p);
                 putPiece(id1);
                 break;
            case R:
                 Rook *wr2 = new Rook(i,j,0,id1,r);
                 pieces.push_back(wr2);
                 delete Pawn(i,j,0,id1,p);
                 putPiece(id1);
                 break;
            case Q:
                 Queen *wq2 = new Queen(i,j,0,id1,q);
                 pieces.push_back(wq2);
                 delete Pawn(i,j,0,id1,p);
                 putPiece(id1) ;
                 break;
            default:
                 cout << "you picked the wrong piece!"
                break;
            }
        }
    }
    else if ( turn == 1 && ......){
        if (i==7) {
            cout<< " you can promote your pawn  to Bishop, Knight,Rook or Queen"
            cin>> choice;
            switch (choice)
            {
            case B:
                 Bishop *bb2 = new Bishop(i,j,1,id1,B);
                 pieces.push_back(nb2);
                 delete Pawn(i,j,1,id1,P);
                 putPiece(id1);
                 break;
            case N:
                 Knight *bn2 = new Knight(i,j,1,id1,N);
                 pieces.push_back(bn2);
                 delete Pawn(i,j,1,id1,P);
                 putPiece(id1);
                 break;
            case R:
                 Rook *br2 = new Rook(i,j,1,id1,R);
                 pieces.push_back(br2);
                 delete Pawn(i,j,1,id1,P);
                putPiece(id1);
                 break;
            case Q:
                 Queen *bq2 = new Queen(i,j,1,id1,Q);
                 pieces.push_back(bq2);
                 delete Pawn(i,j,1,id1,P);
                 putPiece(id1);
                 break;
            default:
                 cout << "you picked the wrong piece!"
                break;
            }
        }
    }
}
void function castle (){ 
    if (turn ==0){
        if ((id1==4) && (Board[i][j]]==0 || Board[i][j]]==7)
        {
            if (id1==4 && Board[i][j]]==0)
            {
                if (InBetween_pieces(x1,y1,i,j)==false) && (pieces[4]->gethm()==false)&& (pieces[0]->gethm()==false)
                {
                    gts=global_Targets_Squares();
                    bool trouve=false;
                    for (int i=0, i<gts.size(),i++)
                    {
                        for (int j=0,j<gts[i].size(),j++)
                        {
                            if ((gts[i][j][0]==7)&& (gts[i][j][1]==2)||(gts[i][j][0]==7)&& (gts[i][j][1]==3)||(gts[i][j][0]==7)&& (gts[i][j][1]==4)) 
                            {
                                trouve =true;
                                break;
                            }
                        }
                    }
                    if(trouve==false) {
                        abstractMove(7,4,7,2);
                        abstractMove(7,0,7,3);
                    }
                    else{
                        cout<<"you picked the wrong piece";
                    }
                }
            }
            else if (id1==4 && Board[i][j]]==7)
            {
                if (InBetween_pieces(x1,y1,i,j)==false) && (pieces[4]->gethm()==false)&& (pieces[7]->gethm()==false)
                {
                    gts=global_Targets_Squares();
                    bool trouve=false;
                    for (int i=0, i<gts.size(),i++)
                    {
                        for (int j=0,j<gts[i]..size(),j++)
                        {
                            if ((gts[i][j][0]==7)&& (gts[i][j][1]==5) 
                            {
                                trouve =true;
                                break;
                              
                            }
                            else if ((gts[i][j][0]==7)&& (gts[i][j][1]==6) {
                                trouve =true;
                                break;
                            }
                            else if ((gts[i][j][0]==7)&& (gts[i][j][1]==4) {
                                trouve =true;
                                break;
                            }
                         
                        
                        }

                    }
                    if(trouve==false;) {
                        abstractMove(7,4,7,6);
                        abstractMove(7,7,7,5);
                    }
                    else{
                        cout<<"you picked the wrong piece"
                    }
                }
            }
        }
    }
    else if (turn==1)
    {
        if ((id1==20) && (Board[i][j]]==16 || Board[i][j]]==23)
        {
            if (id1==20 && Board[i][j]]==16)
            {
                if (InBetween_pieces(x1,y1,i,j)==false) && (pieces[20]->gethm()==false)&& (pieces[16]->gethm()==false)
                {
                    gts=global_Targets_Squares();
                    bool trouve=false;
                    for (int i=0, i<gts.size(),i++)
                    {
                        for (int j=0,j<gts[i]..size(),j++)
                        {
                            if ((gts[i][j][0]==0)&& (gts[i][j][1]==2) 
                            {
                                trouve =true;
                                break;
                              
                            }
                            else if ((gts[i][j][0]==0)&& (gts[i][j][1]==3) {
                                trouve =true;
                                break;
                            }
                            else if ((gts[i][j][0]==0)&& (gts[i][j][1]==4) {
                                trouve =true;
                                break;
                            }
                         
                        
                        }

                    }
                    if(trouve==false;) {
                        abstractMove(0,4,0,2);
                        abstractMove(0,0,0,3);
                    }
                    else{
                        cout<<"you picked the wrong piece"
                    }
                }
            }
            else if (id1==20 && Board[i][j]]==23)
            {
                if (InBetween_pieces(x1,y1,i,j)==false) && (pieces[20]->gethm()==false)&& (pieces[23]->gethm()==false)
                {
                    gts=global_Targets_Squares();
                    bool trouve=false;
                    for (int i=0, i<gts.size(),i++)
                    {
                        for (int j=0,j<gts[i]..size(),j++)
                        {
                            if ((gts[i][j][0]==0)&& (gts[i][j][1]==5) 
                            {
                                trouve =true;
                                break;
                              
                            }
                            else if ((gts[i][j][0]==0)&& (gts[i][j][1]==6) {
                                trouve =true;
                                break;
                            }
                            else if ((gts[i][j][0]==0)&& (gts[i][j][1]==4) {
                                trouve =true;
                                break;
                            }
                         
                        
                        }

                    }
                    if(trouve==false;) {
                        abstractMove(0,4,0,6);
                        abstractMove(0,7,0,5);
                    }
                    else{
                        cout<<"you picked the wrong piece"
                    }
                }
            }
        }
    }
}
