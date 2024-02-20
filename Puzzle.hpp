#ifndef PUZZLE
#define PUZZLE

#include <iostream>
#include <array>
#include <vector>
using namespace std;

class Puzzle
{
    public:
    array< array<int,3>, 3> board;
    array< array<int,3>, 3> goal;
    
    Puzzle();
    Puzzle(array< array<int,3>, 3> b, array< array<int,3>, 3> g);
    Puzzle(string b, array< array<int,3>, 3> g);

    vector<char> possibleMoves();
    Puzzle result(char action);
    vector<Puzzle> expand();
    void printPuzzle();
    bool isSolved();
    string hash();
    bool isSolvable();
};

#endif