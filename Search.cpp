#include "Search.hpp"

vector<char> iterativeDeep(Puzzle p)
{
    cout << "Iterative Deepening\n";
    unordered_map<string, int> visited;
    vector<char> optimal = {};
    int depth = 0;
    while (depth<31)
    {
        optimal = depthLimited(p,++depth,{}, visited);
        if (!optimal.empty())
        {
            return optimal;
        }
    }
    return {};
}

vector<char> depthLimited(Puzzle p, int depth, vector<char> moves, unordered_map<string, int>& visited)
{
    visited[p.hash()] = depth;
    if (depth == 0)
    {
        if (p.isSolved())
        {
            return moves;
        }
        return {};
    }
    for (char m: p.possibleMoves())
    {
        Puzzle r = p.result(m);
        if (visited[r.hash()] < depth)
        {
            vector<char> currMoves = moves;
            currMoves.push_back(m);
            vector<char> results = depthLimited(r,depth-1,currMoves, visited);
            if (!results.empty())
            {
                return results;
            }
        }
    }
    return {};
}

vector<char> breadthFirst(Puzzle p)
{
    cout << "Breadth First Search\n";
    unordered_map<string, vector<char>> visited;
    queue<string> q;
    q.push(p.hash());
    while (!q.empty())
    {
        Puzzle curr = Puzzle(q.front(),p.goal);
        string currHash = curr.hash();
        if (curr.isSolved())
        {
            return visited[currHash];
        }
        q.pop();
        for (char m: curr.possibleMoves())
        {
            Puzzle r = curr.result(m);
            string resultHash = r.hash();
            if (visited.find(resultHash) == visited.end())
            {
                visited[resultHash] = visited[currHash];
                visited[resultHash].push_back(m);
                q.push(resultHash);
            }
        }
    }
    return {};
}

vector<char> aStarBFS(Puzzle p, int heuristic)
{
    cout << "A* Search with heuristic " << heuristic << endl;
    unordered_map<string, vector<char>> visited;
    priority_queue<aStarNode> q;
    q.push(aStarNode(p, getCost(p, heuristic), 0));
    while (!q.empty())
    {
        aStarNode currNode = q.top();
        Puzzle currPuzzle = currNode.puzzle;
        string currHash = currPuzzle.hash();
        if (currPuzzle.isSolved())
        {
            return visited[currHash];
        }
        q.pop();
        for (char m: currPuzzle.possibleMoves())
        {
            Puzzle r = currPuzzle.result(m);
            string resultHash = r.hash();
            Puzzle rPuzzle = Puzzle(resultHash,p.goal);
            aStarNode rNode = aStarNode(rPuzzle, getCost(rPuzzle, heuristic)+currNode.depth+1, currNode.depth+1);
            if (visited.find(resultHash) == visited.end() || rNode.depth < visited[resultHash].size())
            {
                visited[resultHash] = visited[currHash];
                visited[resultHash].push_back(m);
                q.push(rNode);
            }
        }
    }
    return {};
}

int getCost(Puzzle p, int heuristic)
{
    switch (heuristic)
    {
        case MISPLACED_TILES:
            return misplacedTiles(p);
        case MANHATTAN_DISTANCE:
            return manhattanDistance(p);
        case PURE_RANDOM:
            return rand();
        case MADAMMIT:
            return manhattanDistance(p)-misplacedTiles(p);
        case CONTROLLED_RANDOM:
            return rand() % (misplacedTiles(p)+1);
        case LINEAR_CONFLICT:
            return linearConflict(p);
        default:
            return 0;
    }
}

int misplacedTiles(Puzzle p)
// The amount of tiles that are not in their respective goal states.
{
    int cost = 0;
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            if (p.board[i][j] != p.goal[i][j])
            {
                cost++;
            }
        }
    }
    // cout << cost << endl;
    return cost;
}

int manhattanDistance(Puzzle p)
// The amount of moves it would take for each tile to get to the respective goal, added.
{
    unordered_map<int, array<int,2>> positions;
    int cost = 0;
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            positions[p.board[i][j]] = {i,j};
        }
    }
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            if (p.goal[i][j])
            {
                cost += abs(positions[p.goal[i][j]][0] - i) + abs(positions[p.goal[i][j]][1] - j);
            }
        }
    }
    return cost;
}

int linearConflict(Puzzle p)
//lol i have no clue what linear conflict is
{
    int cost = 0;
    return cost;
}

void printMoves(vector<char> moves)
{
    cout << "Number of moves: " << moves.size() << "\n";
    for (char m: moves)
    {
        switch(m)
        {
            case 'U':
                cout << "Up\n";
                break;
            case 'L':
                cout << "Left\n";
                break;
            case 'D':
                cout << "Down\n";
                break;
            case 'R':
                cout << "Right\n";
                break;
            default:
                cout << "\n";
        }
    }
}