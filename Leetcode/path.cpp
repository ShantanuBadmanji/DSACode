#include <bits/stdc++.h>
using namespace std;
class Solution
{
    vector<list<int>> adjlist;
    vector<bool> visited;
    bool dfs(int source, int destination)
    {
        if (source == destination)
        {
            return true;
        }

        for (int v : adjlist.at(source))
        {
            if (visited.at(v))
            {
                continue;
            }
            visited.at(v) = true;
            if (dfs(v, destination))
            {
                return true;
            }
        }
        return false;
    }

public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        adjlist.resize(n);
        visited.resize(n, false);
        for (vector<int> e : edges)
        {
            adjlist.at(e[0]).push_back(e[1]);
            adjlist.at(e[1]).push_back(e[0]);
        }
        // START
        visited.at(source) = true;
        return dfs(source, destination);
    }
};
int main()
{
    int source = 40;
    int destinaton = 3;
    int n = 50;
    vector<vector<int>> edges = {{41, 40}, {9, 32}, {48, 14}, {6, 44}, {18, 41}, {41, 1}, {7, 41}, {38, 41}, {19, 4}, {16, 41}, {41, 43}, {41, 22}, {41, 21}, {9, 0}, {41, 48}, {32, 36}, {24, 44}, {39, 41}, {48, 17}, {49, 15}, {47, 41}, {19, 31}, {11, 41}, {41, 23}, {41, 49}, {45, 44}, {2, 49}, {13, 41}, {35, 41}, {30, 0}, {5, 44}, {8, 0}, {41, 20}, {41, 28}, {12, 11}, {12, 41}, {49, 10}, {19, 0}, {0, 37}, {34, 41}, {42, 48}, {27, 41}, {0, 41}, {19, 44}, {41, 26}, {41, 29}, {33, 41}, {49, 46}, {41, 25}, {3, 41}};
    Solution s;
    s.validPath(n, edges, source, destinaton);
    return 0;
}
