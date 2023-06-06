#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int n;
    vector<list<int>> adj;
    bool isInrange(vector<int> &src, vector<int> &des)
    {
        return pow(src[2], 2) >= pow(src[1] - des[1], 2) + pow(src[0] - des[0], 2);
    }

public:
    int maximumDetonation(vector<vector<int>> &bombs)
    {
        n = bombs.size();
        // cout << "size: " << n << endl;
        adj.resize(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (isInrange(bombs[i], bombs[j]))
                    adj[i].push_front(j);
                if (isInrange(bombs[j], bombs[i]))
                    adj[j].push_front(i);
            }
        }
        // for (auto lst : adj)
        // {
        //     cout << lst.size() << ": ";
        //     for (auto v : lst)
        //     {
        //         cout << v << " ";
        //     }
        //     cout << endl;
        // }

        priority_queue<int> pq;
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            vector<bool> visited(n, false);
            // for (auto i : visited)
            // {
            //     cout<<i<<" ";
            // }

            int count = 0;
            q.push(i);
            visited[i] = true;
            count++;

            while (!q.empty())
            {
                int pt = q.front();
                q.pop();
                for (auto nbr : adj[pt])
                {
                    // cout << "nbr: " << nbr << endl;
                    if (!visited[nbr])
                    {
                        q.push(nbr);
                        visited[nbr] = true;
                        count++;
                        // cout << "pt: " << pt << "count: " << count << endl;
                    }
                }
            }
            pq.push(count);
        }
        return pq.top();
    }
};
int main(int argc, char const *argv[])
{
    Solution s;

    vector<vector<int>> bombs = {{1, 2, 3}, {2, 3, 1}, {3, 4, 2}, {4, 5, 3}, {5, 6, 4}};
    cout << s.maximumDetonation(bombs) << endl;

    return 0;
}
