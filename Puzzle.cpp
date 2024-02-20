#include "Puzzle.hpp"

Puzzle::Puzzle()
{
    board = {{{0,0,0},{0,0,0},{0,0,0}}};
    goal = {{{0,0,0},{0,0,0},{0,0,0}}};
}

Puzzle::Puzzle(array<array<int, 3>, 3> b, array<array<int, 3>, 3> g)
{
    board = b;
    goal = g;
}

Puzzle::Puzzle(string b, array<array<int, 3>, 3> g)
{
    //board = {{{b[0]-'0',b[1]-'0',b[2]-'0'},{b[3]-'0',b[4]-'0',b[5]-'0'},{b[6]-'0',b[7]-'0',b[8]-'0'}}};
    board = {{{b[0],b[1],b[2]},{b[3],b[4],b[5]},{b[6],b[7],b[8]}}};
    goal = g;
}

vector<char> Puzzle::possibleMoves()
{
    vector<char> moves;
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            if (board[i][j] == 0)
            {
                if (i+1 < 3) moves.push_back('U');
                if (j+1 < 3) moves.push_back('L');
                if (i-1 > -1) moves.push_back('D');
                if (j-1 > -1) moves.push_back('R');
                return moves;
            }
        }
    }
    return {};
}

Puzzle Puzzle::result(char action)
{
    array< array<int,3>, 3> newBoard = board;
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            if (board[i][j] == 0)
            {
                switch (action)
                {
                    case 'U':
                        newBoard[i][j] = board[i+1][j];
                        newBoard[i+1][j] = 0;
                        break;
                    case 'L':
                        newBoard[i][j] = board[i][j+1];
                        newBoard[i][j+1] = 0;
                        break;
                    case 'D':
                        newBoard[i][j] = board[i-1][j];
                        newBoard[i-1][j] = 0;
                        break;
                    case 'R':
                        newBoard[i][j] = board[i][j-1];
                        newBoard[i][j-1] = 0;
                        break;
                    default:
                        return Puzzle();
                }
                return Puzzle(newBoard, goal);
            }
        }
    }
    return Puzzle();
}

vector<Puzzle> Puzzle::expand()
{
    vector<Puzzle> results;
    vector<char> moves = possibleMoves();
    for (char move: moves) results.push_back(result(move));
    return results;
}

void Puzzle::printPuzzle()
{
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

bool Puzzle::isSolved()
{
    return board == goal;
}

string Puzzle::hash()
{
    string r = "";
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            r+=board[i][j];
            //r += to_string(board[i][j]);  
        }
    }
    //cout << r << endl;
    return r;
}

bool Puzzle::isSolvable()
{
    return rand()%2;
}