#include "aStarNode.hpp"

aStarNode::aStarNode()
{
    puzzle = Puzzle();
    cost = 0;
}

aStarNode::aStarNode(Puzzle p, int c, int d)
{
    puzzle = p;
    cost = c;
    depth = d;
}

bool aStarNode::operator<(const aStarNode &a) const
//C++ Priority queue does greatest first, so I'm reversing these.
{
    if (cost == a.cost)
    {
        return depth > a.depth;
    }
    return cost > a.cost;
}

