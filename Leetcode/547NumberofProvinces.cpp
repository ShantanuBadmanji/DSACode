#include <bits/stdc++.h>
using namespace std;
template <typename T>
void display(vector<T> mat)
{
    cout << endl;
    for (auto i : mat)
    {
        cout << ": ";
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        vector<list<int>> provinces(isConnected.size());
        vector<int> currPos(isConnected.size());
        // one vertex in each list representing independant province
        for (int i = 0; i < provinces.size(); i++)
        {
            provinces.at(i).push_front(i);
            currPos[i] = i;
        }
        // display<list<int>>(provinces);
        for (int i = 0; i < isConnected.size(); i++)
        {
            for (int j = 0; j < (i); j++)
            {
                if (isConnected[i][j] == 0)
                    continue;

                // provinces.at(i)
                // .insert(provinces.at(i).end(),
                //         provinces.at(j).begin(),
                //         provinces.at(j).end());
                int j1 = currPos[j];
                for (int v : provinces.at(j1))
                {
                    provinces.at(i).push_back(v);
                    currPos[v] = i;
                }
                provinces.at(j1).clear();
            }
        }
        // display<list<int>>(provinces);
        int count = 0;
        for (list<int> lst : provinces)
        {
            if (lst.size() != 0)
                count++;
        }
        return count;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> isConnected = {{1, 0, 0, 1}, {0, 1, 1, 0}, {0, 1, 1, 1}, {1, 0, 1, 1}};
    cout << s.findCircleNum(isConnected) << endl;
    return 0;
}
