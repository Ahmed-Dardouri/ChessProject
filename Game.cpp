#include "Game.h"
#include <iostream>
Game::Game()
{

    Rook *wra = new Rook(7, 0, 0, 0, 'r');
    Knight *wnb = new Knight(7, 1, 0, 1, 'n');
    Bishop *wbc = new Bishop(7, 2, 0, 2, 'b');
    Queen *wqd = new Queen(7, 3, 0, 3, 'q');
    King *wke = new King(7, 4, 0, 4, 'k');
    Bishop *wbf = new Bishop(7, 5, 0, 5, 'b');
    Knight *wng = new Knight(7, 6, 0, 6, 'n');
    Rook *wrh = new Rook(7, 7, 0, 7, 'r');
    Pawn *wpa = new Pawn(6, 0, 0, 8, 'p');
    Pawn *wpb = new Pawn(6, 1, 0, 9, 'p');
    Pawn *wpc = new Pawn(6, 2, 0, 10, 'p');
    Pawn *wpd = new Pawn(6, 3, 0, 11, 'p');
    Pawn *wpe = new Pawn(6, 4, 0, 12, 'p');
    Pawn *wpf = new Pawn(6, 5, 0, 13, 'p');
    Pawn *wpg = new Pawn(6, 6, 0, 14, 'p');
    Pawn *wph = new Pawn(6, 7, 0, 15, 'p');
    Rook *bra = new Rook(0, 0, 1, 16, 'R');
    Knight *bnb = new Knight(0, 1, 1, 17, 'N');
    Bishop *bbc = new Bishop(0, 2, 1, 18, 'B');
    Queen *bqd = new Queen(0, 3, 1, 19, 'Q');
    King *bke = new King(0, 4, 1, 20, 'K');
    Bishop *bbf = new Bishop(0, 5, 1, 21, 'B');
    Knight *bng = new Knight(0, 6, 1, 22, 'N');
    Rook *brh = new Rook(0, 7, 1, 23, 'R');
    Pawn *bpa = new Pawn(1, 0, 1, 24, 'W');
    Pawn *bpb = new Pawn(1, 1, 1, 25, 'W');
    Pawn *bpc = new Pawn(1, 2, 1, 26, 'W');
    Pawn *bpd = new Pawn(1, 3, 1, 27, 'W');
    Pawn *bpe = new Pawn(1, 4, 1, 28, 'W');
    Pawn *bpf = new Pawn(1, 5, 1, 29, 'W');
    Pawn *bpg = new Pawn(1, 6, 1, 30, 'W');
    Pawn *bph = new Pawn(1, 7, 1, 31, 'W');

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
    while (1)
    {
        move();
    }
}

void Game::putPiece(int ID)
{
    Board[pieces[ID]->getx()][pieces[ID]->gety()] = pieces[ID]->getid();
}

void Game::initiateBoard()
{
    for (int i = 2; i < 6; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            Board[i][j] = 50;
        }
    }
    for (int i = 0; i < 32; i++)
    {
        putPiece(i);
    }
}

void Game::abstractMove(int x1, int y1, int x2, int y2)
{
    int pid = Board[x1][y1];
    if (pid < 32)
    {
        Board[x1][y1] = 50;
        Board[x2][y2] = pid;
        pieces[pid]->setx(x2);
        pieces[pid]->sety(y2);
    }
}

void Game::showBoard()
{
    cout << endl;

    for (int i = 0; i < 8; i++)
    {
        cout << setw(4) << 8 - i << setw(20);
        for (int j = 0; j < 8; j++)
        {
            if (Board[i][j] != 50)
            {
                cout << setw(4);
                cout << pieces[Board[i][j]]->getname();
            }
            else
            {
                cout << setw(4);
                cout << ".";
            }
        }
        cout << endl;
    }
    cout << setw(8);
    cout << endl
         << 'a' << setw(4) << 'b' << setw(4) << 'c' << setw(4) << 'd' << setw(4) << 'e' << setw(4) << 'f' << setw(4) << 'g' << setw(4) << 'h';
    cout << endl;
}

bool Game::InBetween_pieces(int x1, int y1, int x2, int y2)
{
    int pid = Board[x1][y1];
    if (pid < 32)
    {
        int c = pieces[pid]->getcolor();
        int c1 = 2;
        if (x1 == x2 && y1 == y2)
        {
            return false;
        }
        if (Board[x2][y2] < 32)
        {
            c1 = pieces[Board[x2][y2]]->getcolor();
        }
        if (c == c1)
        {
            return true;
        }
        if (x1 == x2)
        {
            int j = (y2 - y1) / abs(y1 - y2);
            for (int i = y1 + j; abs(i - y2) > 0; i += j)
            {
                if (Board[x1][i] < 32)
                {
                    return true;
                }
            }
        }
        else if (y1 == y2)
        {
            int j = (x2 - x1) / abs(x1 - x2);
            for (int i = x1 + j; abs(i - x2) > 0; i += j)
            {
                if (Board[i][y1] < 32)
                {
                    return true;
                }
            }
        }
        else if (abs(x1 - x2) == abs(y1 - y2))
        {
            int k = (x2 - x1) / abs(x1 - x2);
            int l = (y2 - y1) / abs(y1 - y2);
            int j = y1 + l;
            for (int i = x1 + k; abs(i - x2) > 0; i += k)
            {
                if (Board[i][j] < 32)
                {
                    return true;
                }
                j += l;
            }
        }
    }
    return false;
}

vector<vector<int>> Game::target_Squares(int X1, int Y1)
{
    vector<vector<int>> squaresList;
    vector<int> square;
    int pid = Board[X1][Y1];
    if (pid < 32)
    {
        if (typeid(*pieces[pid]) != typeid(*pieces[8]))
        {
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    if (i != X1 || j != Y1)
                    {
                        if (InBetween_pieces(X1, Y1, i, j) == 0)
                        {
                            if (pieces[pid]->legal_move(i, j))
                            {
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
        else
        {
            if (pieces[pid]->getcolor() == 0)
            {
                if (Y1 < 7)
                {
                    int rid = Board[X1 - 1][Y1 + 1];
                    if (!(rid < 32 && pieces[rid]->getcolor() == pieces[pid]->getcolor()))
                    {
                        square.push_back(X1 - 1);
                        square.push_back(Y1 + 1);
                        squaresList.push_back(square);
                        square.clear();
                    }
                }
                if (Y1 > 0)
                {
                    int lid = Board[X1 - 1][Y1 - 1];
                    if (!(lid < 32 && pieces[lid]->getcolor() == pieces[pid]->getcolor()))
                    {
                        square.push_back(X1 - 1);
                        square.push_back(Y1 - 1);
                        squaresList.push_back(square);
                        square.clear();
                    }
                }
            }
            else
            {
                if (Y1 < 7)
                {
                    int rid = Board[X1 + 1][Y1 + 1];
                    if (!(rid < 32 && pieces[rid]->getcolor() == pieces[pid]->getcolor()))
                    {
                        square.push_back(X1 + 1);
                        square.push_back(Y1 + 1);
                        squaresList.push_back(square);
                        square.clear();
                    }
                }
                if (Y1 > 0)
                {
                    int lid = Board[X1 + 1][Y1 - 1];
                    if (!(lid < 32 && pieces[lid]->getcolor() == pieces[pid]->getcolor()))
                    {
                        square.push_back(X1 + 1);
                        square.push_back(Y1 - 1);
                        squaresList.push_back(square);
                        square.clear();
                    }
                }
            }
        }
    }
    return squaresList;
}

vector<vector<int>> Game::white_Targets_Squares()
{
    vector<vector<int>> wts;
    vector<vector<int>> s;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (Board[i][j] < 16)
            {
                s = target_Squares(i, j);
                for (int k = 0; k < s.size(); k++)
                {
                    wts.push_back(s[k]);
                }
                s.clear();
            }
        }
    }
    return wts;
}

vector<vector<int>> Game::black_Targets_Squares()
{
    vector<vector<int>> bts;
    vector<vector<int>> s;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (Board[i][j] > 15 && Board[i][j] != 50)
            {
                s = target_Squares(i, j);
                for (int k = 0; k < s.size(); k++)
                {
                    bts.push_back(s[k]);
                }
                s.clear();
            }
        }
    }
    return bts;
}

bool Game::king_in_check(int X, int Y)
{
    vector<vector<int>> ts;
    if (turn == 1)
    {
        ts = white_Targets_Squares();
    }
    else
    {
        ts = black_Targets_Squares();
    }
    vector<int> kingPos = {X, Y};

    for (int i = 0; i < ts.size(); i++)
        if (ts[i] == kingPos)
        {
            return true;
        }
    return false;
}

void Game::Promotion(int i, int j)
{
    int pid = Board[i][j];
    int X = pieces[pid]->getx();
    int Y = pieces[pid]->gety();
    int C = pieces[pid]->getcolor();
    cout << " you can promote your pawn to Bishop, Knight, Rook or Queen" << endl;
    char choice;
    cin >> choice;
    if (turn == 0)
    {
        choice = tolower(choice);
    }
    else
    {
        choice = toupper(choice);
    }
    do
    {
        switch (tolower(choice))
        {
        case 'b':
            pieces[pid] = new Bishop(X, Y, C, pid, choice);
            putPiece(pid);
            break;
        case 'n':
            pieces[pid] = new Knight(X, Y, C, pid, choice);
            putPiece(pid);
            break;
        case 'r':
            pieces[pid] = new Rook(X, Y, C, pid, choice);
            putPiece(pid);
            break;
        case 'q':
            pieces[pid] = new Queen(X, Y, C, pid, choice);
            putPiece(pid);
            break;
        default:
            cout << "you picked the wrong piece!";
            break;
        }
    } while (tolower(choice) != 'b' && tolower(choice) != 'n' && tolower(choice) != 'r' && tolower(choice) != 'q');
}

void Game::castle(int i, int j)
{
    if (turn == 0)
    {
        vector<vector<int>> bts;
        bts = black_Targets_Squares();
        int x1 = pieces[4]->getx();
        int y1 = pieces[4]->gety();
        if (Board[i][j] == 0)
        {
            if ((InBetween_pieces(x1, y1, x1, y1 - 3) == false) && (Board[7][1] = 50) && (pieces[4]->gethm() == false) && (pieces[0]->gethm() == false))
            {
                bool trouve = false;
                for (int k = 0; k < bts.size(); k++)
                {
                    if (bts[k][0] == 7 && (bts[k][1] == 2 || bts[k][1] == 3 || bts[k][1] == 4))
                    {
                        trouve = true;
                        break;
                    }
                }
                if (trouve == false)
                {
                    abstractMove(7, 4, 7, 2);
                    abstractMove(7, 0, 7, 3);
                    pieces[4]->sethm();
                    pieces[0]->sethm();
                    turn = 1;
                }
            }
        }
        else if (Board[i][j] == 7)
        {
            if ((InBetween_pieces(x1, y1, x1, y1 + 2) == false) && (Board[7][6] = 50) && (pieces[4]->gethm() == false) && (pieces[7]->gethm() == false))
            {
                bool trouve = false;
                for (int k = 0; k < bts.size(); k++)
                {
                    if (bts[k][0] == 7 && (bts[k][1] == 5 || bts[k][1] == 6 || bts[k][1] == 4))
                    {
                        trouve = true;
                        break;
                    }
                }
                if (trouve == false)
                {
                    abstractMove(7, 4, 7, 6);
                    abstractMove(7, 7, 7, 5);
                    pieces[4]->sethm();
                    pieces[7]->sethm();
                    turn = 0;
                }
                else
                {
                    cout << "Illegal move";
                }
            }
        }
    }
    else if (turn == 1)
    {
        vector<vector<int>> wts;
        wts = white_Targets_Squares();
        int x1 = pieces[20]->getx();
        int y1 = pieces[20]->gety();
        if (Board[i][j] == 16)
        {
            if ((InBetween_pieces(x1, y1, x1, y1 - 3) == false) && (Board[0][1] = 50) && (pieces[20]->gethm() == false) && (pieces[16]->gethm() == false))
            {
                bool trouve = false;
                for (int k = 0; k < wts.size(); k++)
                {
                    if (wts[k][0] == 0 && (wts[k][1] == 2 || wts[k][1] == 3 || wts[k][1] == 4))
                    {
                        trouve = true;
                        break;
                    }
                }
                if (trouve == false)
                {
                    abstractMove(0, 4, 0, 2);
                    abstractMove(0, 0, 0, 3);
                    pieces[20]->sethm();
                    pieces[16]->sethm();
                }
                else
                {
                    cout << "Illegal move";
                }
            }
        }
        else if (Board[i][j] == 23)
        {
            if ((InBetween_pieces(x1, y1, x1, y1 + 2) == false) && (Board[0][6] = 50) && (pieces[20]->gethm() == false) && (pieces[23]->gethm() == false))
            {
                bool trouve = false;
                for (int k = 0; k < wts.size(); k++)
                {
                    if (wts[k][0] == 0 && (wts[k][1] == 5 || wts[k][1] == 6 || wts[k][1] == 4))
                    {
                        trouve = true;
                        break;
                    }
                }
                if (trouve == false)
                {
                    abstractMove(0, 4, 0, 6);
                    abstractMove(0, 7, 0, 5);
                    pieces[20]->sethm();
                    pieces[23]->sethm();
                }
                else
                {
                    cout << "Illegal move";
                }
            }
        }
    }
}

bool Game ::verify_move(string move)
{
    vector<char> squares_c = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    vector<char> squares_n = {'1', '2', '3', '4', '5', '6', '7', '8'};
    vector<char>::iterator it;
    if (move.size() == 2)
    {
        it = find(squares_c.begin(), squares_c.end(), move[0]);
        if (it != squares_c.end())
        {
            it = find(squares_n.begin(), squares_n.end(), move[1]);
            if (it != squares_n.end())
            {
                return true;
            }

            else
            {
                cout << "verify line entrence" << endl
                     << move[1] << "th line doesn't exist" << endl;
                return false;
            }
        }
        else
        {
            cout << "verify column entrence " << endl
                 << move[0] << ": column doesn't exsist" << endl;
            return false;
        }
    }

    else
    {
        cout << "enter the correct position" << endl;
        return false;
    }
}

vector<int> Game::translate_move(string move)
{
    vector<char> squares_c = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    vector<char> squares_n = {'1', '2', '3', '4', '5', '6', '7', '8'};

    int j;
    for (j = 0; j != 8; j++)
        if (move[0] == squares_c[j])
            break;
    int i;
    for (i = 0; i != 8; i++)
        if (move[1] == squares_n[i])
            break;
    i = 7 - i;
    vector<int> square = {i, j};
    return square;
}

void Game::pawn_mouvement(int x1, int y1, int i, int j, int id1)
{
    bool I_moved = false;
    if (turn == 1)
    {
        int bkx = pieces[20]->getx();
        int bky = pieces[20]->gety();
        if (pieces[id1]->getcolor() == turn)
        {
            if (y1 == j && (x1 + 1 == i || x1 + 2 == i && x1 == 1))
            {
                if (Board[i][j] == 50)
                {
                    if (x1 + 2 == i && x1 == 1)
                    {
                        setpmoved(id1);
                    }
                    else
                    {
                        setpmoved(100);
                    }
                    int p = Board[i][j];
                    abstractMove(x1, y1, i, j);

                    if (king_in_check(bkx, bky))
                    {
                        cout << "Black king is in check" << endl;
                        abstractMove(i, j, x1, y1);
                        Board[i][j]=p;
                    }
                    else
                    {
                        //cout << "Black plays the move " << move_i << " to " << move_f << endl;
                        turn = 0;
                        I_moved = true;
                        showBoard();
                    }
                }
                else
                    cout << "Illegal move" << endl;
            }
            else if (abs(j - y1) == 1 && abs(i - x1) == 1)
            {
                if (Board[i][j] == 50)
                {
                    int id2 = Board[i - 1][j];
                    if (id2 == p_moved)
                    {
                        int p = Board[i][j];
                        abstractMove(x1, y1, i, j);
                        if (king_in_check(bkx, bky))
                        {
                            cout << "Black's king is under check" << endl;
                            abstractMove(i, j, x1, y1);
                            Board[i][j] = p;
                        }
                        else
                        {
                            I_moved = true;
                            Board[i - 1][j] = 50;
                            setpmoved(100);
                            showBoard();
                            cout << "en passsssssssant" << endl;
                        }
                    }
                    else
                    {
                        cout << "Illegal move" << endl;
                    }
                }
                else if (Board[i][j] < 16)
                {
                    cout << "nope";
                    int p = Board[i][j];
                    abstractMove(x1, y1, i, j);
                    if (king_in_check(bkx, bky))
                    {
                        cout << "Black's king is under check" << endl;
                        abstractMove(i, j, x1, y1);
                        Board[i][j] = p;
                    }
                    else
                    {
                        setpmoved(100);
                        showBoard();
                        turn = 0;
                    }
                }
            }
            else
                cout << "wrong move !" << endl;
            if (I_moved && i == 7)
                Promotion(i, j);
        }
    }
    else //white
    {
        int wkx = pieces[4]->getx();
        int wky = pieces[4]->gety();
        if (pieces[id1]->getcolor() == turn)
        {
            if (y1 == j && (x1 - 1 == i || x1 - 2 == i && x1 == 6))
            {
                if (Board[i][j] == 50)
                {
                    if (x1 - 2 == i && x1 == 6)
                    {
                        setpmoved(id1);
                    }
                    else
                    {
                        p_moved = 100;
                    }

                    abstractMove(x1, y1, i, j);

                    if (king_in_check(wkx, wky))
                    {
                        cout << "White's king is under check" << endl;
                        abstractMove(i, j, x1, y1);
                    }
                    else
                    {
                        I_moved = true;
                        showBoard();
                        //cout << "white plays the move " << move_i << " to " << move_f << endl;
                        turn = 1;
                    }
                }
                else
                    cout << "Illegal move !" << endl;
            }
            else if (abs(j - y1) == 1 && x1 - i == 1)
            {
                if (Board[i][j] == 50)
                {
                    int id2 = Board[i + 1][j];
                    cout << id2 << endl;
                    cout << p_moved;
                    if (id2 == p_moved)
                    {
                        int p = Board[i][j];
                        abstractMove(x1, y1, i, j);
                        if (king_in_check(wkx, wky))
                        {
                            cout << "white's king is under check" << endl;
                            abstractMove(i, j, x1, y1);
                            Board[i][j] = p;
                        }
                        else
                        {
                            I_moved = true;
                            Board[i + 1][j] = 50;
                            showBoard();
                            setpmoved(100);
                            cout << "en passsssssssant" << endl;
                            turn = 1;
                        }
                    }
                    else
                    {
                        cout << "Illegal move" << endl;
                    }
                }
                else if (Board[i][j] > 15 && Board[i][j] < 32)
                {
                    int p = Board[i][j];
                    abstractMove(x1, y1, i, j);
                    if (king_in_check(wkx, wky))
                    {
                        cout << "White's king is under check" << endl;
                        abstractMove(i, j, x1, y1);
                        Board[i][j] = p;
                    }
                    else
                    {
                        setpmoved(100);
                        I_moved = true;
                        turn = 1;
                        showBoard();
                    }
                }
            }
            else
                cout << "wrong move !" << endl;
        }
        else
            cout << "wrong move !" << endl;
        if (I_moved && i == 0)
            Promotion(i, j);
    }
}

void Game ::move()
{
    string move_i, move_f;
    vector<int> square_i;
    vector<int> square_f;
    int wkx = pieces[4]->getx();
    int wky = pieces[4]->gety();
    int bkx = pieces[20]->getx();
    int bky = pieces[20]->gety();
    if (turn == 0)
    {
        cout << "White's turn to play" << endl;
    }
    else
        cout << "black's Turn to play" << endl;
    do
    {
        cout << "enter piece's initial square" << endl;
        cin >> move_i;
    } while (verify_move(move_i) == false);
    do
    {
        cout << "enter piece's direction square" << endl;
        cin >> move_f;
    } while (verify_move(move_f) == false);
    //read the piece initial and togo squares
    square_i = translate_move(move_i);
    square_f = translate_move(move_f);
    int x1 = square_i[0];
    int y1 = square_i[1];
    int i = square_f[0];
    int j = square_f[1];
    int id1 = Board[x1][y1];
    //(x1,y1) piece's initial square ; (i,j) piece's final square according to the Board notations
    if (id1 == 50)
    {
        cout << "The initial square is empty" << endl;
    }
    else
    {
        if (typeid(*pieces[id1]) == typeid(*pieces[8]))
        {
            pawn_mouvement(x1, y1, i, j, id1);
        }
        else if (typeid(*pieces[id1]) == typeid(*pieces[4]) && (abs(y1 - j) == 2 || abs(y1 - j) == 3))
        {
            castle(i, j);
            showBoard();
        }
        else
        {
            if (pieces[id1]->getcolor() == turn)
            {
                vector<vector<int>> c = target_Squares(x1, y1);
                vector<vector<int>>::iterator it1;
                it1 = find(c.begin(), c.end(), square_f);
                if (it1 != c.end())
                {
                    int p = Board[i][j];
                    abstractMove(x1, y1, i, j);
                    if (turn == 1)
                    {
                        if (id1 == 20)
                        {
                            bkx = i;
                            bky = j;
                        }
                        if (king_in_check(bkx, bky))
                        {
                            cout << "Black king is in check" << endl;
                            abstractMove(i, j, x1, y1);
                            Board[i][j] = p;
                        }
                        else
                        {
                            setpmoved(100);
                            showBoard();
                            cout << "Black plays the move " << move_i << " to " << move_f << endl;
                            turn = 0;
                        }
                    }
                    else
                    {
                        if (id1 == 4)
                        {
                            wkx = i;
                            wky = j;
                        }
                        if (king_in_check(wkx, wky))
                        {
                            cout << "White king is in check" << endl;
                            abstractMove(i, j, x1, y1);
                            Board[i][j] = p;
                        }
                        else
                        {
                            setpmoved(100);
                            showBoard();
                            cout << "white plays the move " << move_i << " to " << move_f << endl;
                            turn = 1;
                        }
                    }
                }
                else
                {
                    cout << "Illegal Move !" << endl;
                }
            }
            else
            {
                cout << "you picked the enemey piece as the initial square" << endl;
            }
        }
    }
}
//hi