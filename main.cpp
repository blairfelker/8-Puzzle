#include "Search.hpp"

int main() 
{
    srand(time(NULL));
    array< array<int,3>, 3> cringe = {{{0,1,2},{3,4,5},{6,7,8}}}; 
    array< array<int,3>, 3> goal = {{{1,2,3},{4,5,6},{7,8,0}}};
    Puzzle p = Puzzle(cringe,goal); //22 optimal
    Puzzle p0 = Puzzle({{{7,8,6},{1,3,5},{0,2,4}}},goal); //26 optimal
    // printMoves(iterativeDeep(p));
    // cout << endl;
    // printMoves(breadthFirst(p));
    // cout << endl;
    
    printMoves(aStarBFS(p, ZERO));
    cout << endl;
    printMoves(aStarBFS(p, MISPLACED_TILES));
    cout << endl;
    printMoves(aStarBFS(p, MANHATTAN_DISTANCE)); 
    cout << endl;
    printMoves(aStarBFS(p, PURE_RANDOM));
    cout << endl;
    printMoves(aStarBFS(p, MADAMMIT));
    cout << endl;
    printMoves(aStarBFS(p, CONTROLLED_RANDOM));
    cout << endl;
    // printMoves(aStarBFS(p, LINEAR_CONFLICT));
    // cout << endl;

    printMoves(aStarBFS(p0, MISPLACED_TILES));
    cout << endl;
    printMoves(aStarBFS(p0, MANHATTAN_DISTANCE)); 
    cout << endl;
    printMoves(aStarBFS(p0, PURE_RANDOM));
    cout << endl;
    printMoves(aStarBFS(p0, MADAMMIT));
    cout << endl;
    printMoves(aStarBFS(p0, CONTROLLED_RANDOM));
    cout << endl;
    // printMoves(aStarBFS(p0, LINEAR_CONFLICT));
    // cout << endl;


    return 0;
}