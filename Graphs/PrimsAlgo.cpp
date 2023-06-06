#include <iostream>
#define INFINITY 99
#define MAX 20
using namespace std;

class Graph
{
private:
    int adj_matrix[MAX][MAX];
    int nodes;
    int get_nearest_node(int distance[], bool visited[])
    {
        int next = -1;
        int min = INFINITY;
        for (int i = 0; i < nodes; i++)
        {
            if (visited[i] == false && distance[i] < min)
            {
                min = distance[i];
                next = i;
            }
        }
        return next;
    }
    void display_lower_tri_matrix(int matrix[][MAX])
    {
        for (int i = 0; i < nodes; i++)
        {
            bool present = false;
            for (int j = 0; j <= i; j++)
            {
                if (matrix == adj_matrix && adj_matrix[i][j] == 0)
                {
                    continue;
                }
                present = true;
                printf("< %d %d >: %d   ", i, j, matrix[i][j]);
            }
            if (present)
                cout << endl;
        }
    }
    void displayArr(int val, int distance[], bool visited[], int from[])
    {
        for (int i = 0; i < nodes; i++)
        {
            if (val == 1)
            {
                cout << distance[i] << "  ";
            }
            else if (val == 3)
            {
                if (from[i] == -1)
                {
                    cout << from[i] << "  ";
                }
                else
                {
                    cout << from[i] << "   ";
                }
            }
            else
            {
                cout << visited[i] << "   ";
            }
        }
        cout << endl;
    }

public:
    Graph() : nodes(0){};
    void readGraph();
    void printGraph();
    void primsAlgo(Graph &span, int source);
};
void Graph::readGraph()
{
    cout << "Enter the number of nodes:" << endl;
    cin >> nodes;

    for (int i = 0; i < nodes; i++)
    {
        for (int j = 0; j < nodes; j++)
        {
            adj_matrix[i][j] = 0;
        }
    }
    int edges, vi, vj;
    cout << "Enter the number of edges:" << endl;
    cin >> edges;
    int wt;
    for (int i = 0; i < edges; i++)
    {
        cout << "Enter the weight of edge with its nodes in (node1, node2, weight):" << endl;
        cin >> vi >> vj >> wt;
        adj_matrix[vj][vi] = adj_matrix[vi][vj] = wt;
    }
}

void Graph::printGraph()
{
    cout << "\nThe weight of edge with its nodes:\n";
    display_lower_tri_matrix(adj_matrix);
}
void Graph::primsAlgo(Graph &span, int source = 0)
{
    int cost[MAX][MAX];
    
    span.nodes = nodes;
    // CREATE COST MATRIX AND INITIALIZE THE SPAN'S ADJ_MATRIX WITH ZEROS
    for (int i = 0; i < nodes; i++)
    {
        for (int j = 0; j < nodes; j++)
        {
            if (adj_matrix[i][j] == 0)
            {
                cost[i][j] = INFINITY;
            }
            else
            {
                cost[i][j] = adj_matrix[i][j];
            }
            span.adj_matrix[i][j] = 0;
        }
    }

    // PRINT THE COST MATRIX
    cout << "\nThe cost of edge with its nodes:" << endl;
    display_lower_tri_matrix(cost);
    // cout << "\ninitial span matrix" << endl;
    // display_lower_tri_matrix(span.adj_matrix);

    // INITIALIZING THE 3 ARRAYS
    int distance[MAX], from[MAX];
    bool visited[MAX];

    for (int i = 0; i < nodes; i++)
    {
        distance[i] = INFINITY;
        visited[i] = false;
        from[i] = source;
    }

    int reached = 0;
    int mst_cost = 0;
    int curr = source, prev = -1;
    from[curr] = -1;
    distance[curr] = 0;
    // visited[source] = true;
    while (reached <= nodes)
    {
        cout << "\nStep " << reached << ":" << endl;
        for (int i = 0; i < nodes; i++)
        {
            cout << i << "   ";
        }
        cout << endl;

        for (int i = 0; i < nodes; i++)
        {
            if (visited[i] == false && cost[curr][i] < distance[i])
            {
                distance[i] = cost[curr][i];
                from[i] = curr;
            }
        }

        // DISPLAY THE 3 ARRAYS(DISTANCE, FROM, VISITED)
        displayArr(1, distance, visited, from);
        displayArr(2, distance, visited, from);
        displayArr(3, distance, visited, from);
        int next = get_nearest_node(distance, visited);
        cout << "next: " << next << endl;
        reached++;
        if (next == -1)
        {
            continue;
        }
        visited[next] = true;
        mst_cost += distance[next];
        span.adj_matrix[curr][next] = distance[next];
        span.adj_matrix[next][curr] = distance[next];
        curr = next;
    }
    cout << "The cost of minimum spanning tree is: " << mst_cost << endl;
    for (int i = 0; i < nodes; i++)
    {
        cout << distance[i] << ": ";
        int node = i;
        while (true)
        {
            cout << node << " -> ";
            node = from[node];
            if (node != -1 || node != -source)
            {
                break;
            }
        }
        cout << "END" << endl;
    }
}

int main(int argc, char const *argv[])
{
    Graph g, span;
    g.readGraph();
    g.printGraph();
    g.primsAlgo(span, 4);
    span.printGraph();
    return 0;
}
/*
INPUT:
7 9
5 0 10  2 3 12  1 6 14  1 2 16  6 3 18  4 3 22  6 4 24  5 4 25  0 1 28


OUTPUT:
Enter the number of nodes:
7 9
Enter the number of edges:
Enter the weight of edge with its nodes in (node1, node2, weight):
5 0 10  2 3 12  1 6 14  1 2 16  6 3 18  4 3 22  6 4 24  5 4 25  0 1 28
Enter the weight of edge with its nodes in (node1, node2, weight):
Enter the weight of edge with its nodes in (node1, node2, weight):
Enter the weight of edge with its nodes in (node1, node2, weight):
Enter the weight of edge with its nodes in (node1, node2, weight):
Enter the weight of edge with its nodes in (node1, node2, weight):
Enter the weight of edge with its nodes in (node1, node2, weight):
Enter the weight of edge with its nodes in (node1, node2, weight):
Enter the weight of edge with its nodes in (node1, node2, weight):

The weight of edge with its nodes:
< 1 0 >: 28
< 2 1 >: 16
< 3 2 >: 12
< 4 3 >: 22
< 5 0 >: 10   < 5 4 >: 25
< 6 1 >: 14   < 6 3 >: 18   < 6 4 >: 24

The cost of edge with its nodes:
< 0 0 >: 99
< 1 0 >: 28   < 1 1 >: 99
< 2 0 >: 99   < 2 1 >: 16   < 2 2 >: 99
< 3 0 >: 99   < 3 1 >: 99   < 3 2 >: 12   < 3 3 >: 99
< 4 0 >: 99   < 4 1 >: 99   < 4 2 >: 99   < 4 3 >: 22   < 4 4 >: 99
< 5 0 >: 10   < 5 1 >: 99   < 5 2 >: 99   < 5 3 >: 99   < 5 4 >: 25   < 5 5 >: 99
< 6 0 >: 99   < 6 1 >: 14   < 6 2 >: 99   < 6 3 >: 18   < 6 4 >: 24   < 6 5 >: 99   < 6 6 >: 99

Step 0:
0   1   2   3   4   5   6
99  99  99  22  0  25  24
0   0   0   0   0   0   0
4   4   4   4   -1  4   4
next: 4

Step 1:
0   1   2   3   4   5   6
99  99  99  22  0  25  24
0   0   0   0   1   0   0
4   4   4   4   -1  4   4
next: 3

Step 2:
0   1   2   3   4   5   6
99  99  12  22  0  25  18
0   0   0   1   1   0   0
4   4   3   4   -1  4   3
next: 2

Step 3:
0   1   2   3   4   5   6
99  16  12  22  0  25  18
0   0   1   1   1   0   0
4   2   3   4   -1  4   3
next: 1

Step 4:
0   1   2   3   4   5   6
28  16  12  22  0  25  14
0   1   1   1   1   0   0
1   2   3   4   -1  4   1
next: 6

Step 5:
0   1   2   3   4   5   6
28  16  12  22  0  25  14
0   1   1   1   1   0   1
1   2   3   4   -1  4   1
next: 5

Step 6:
0   1   2   3   4   5   6
10  16  12  22  0  25  14
0   1   1   1   1   1   1
5   2   3   4   -1  4   1
next: 0

Step 7:
0   1   2   3   4   5   6
10  16  12  22  0  25  14
1   1   1   1   1   1   1
5   2   3   4   -1  4   1
next: -1
The cost of minimum spanning tree is: 99
10: 0 -> END
16: 1 -> END
12: 2 -> END
22: 3 -> END
0: 4 -> END
25: 5 -> END
14: 6 -> END

The weight of edge with its nodes:
< 2 1 >: 16
< 3 2 >: 12
< 4 3 >: 22
< 5 0 >: 10
< 6 1 >: 14   < 6 5 >: 25

*/