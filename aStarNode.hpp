#ifndef ASTARNODE
#define ASTARNODE

#include "Puzzle.hpp"

class aStarNode
{
    public:
    Puzzle puzzle;
    int cost;
    int depth;

    aStarNode();
    aStarNode(Puzzle p, int c, int d);
    bool operator<(const aStarNode &a) const;
};

#endif