#include "Puzzle.hpp"
#include "aStarNode.hpp"
#include <unordered_map>
#include <queue>

vector<char> iterativeDeep(Puzzle p);
vector<char> depthLimited(Puzzle p, int depth, vector<char> moves, unordered_map<string, int>& visitedDepth);
vector<char> breadthFirst(Puzzle p);
vector<char> aStarBFS(Puzzle p, int heuristic);

enum HEURISTICS {ZERO, MISPLACED_TILES, MANHATTAN_DISTANCE, PURE_RANDOM, MADAMMIT, CONTROLLED_RANDOM, LINEAR_CONFLICT};
int getCost(Puzzle p, int heuristic);
int misplacedTiles(Puzzle p);
int manhattanDistance(Puzzle p);
int linearConflict(Puzzle p);

void printMoves(vector<char> moves);