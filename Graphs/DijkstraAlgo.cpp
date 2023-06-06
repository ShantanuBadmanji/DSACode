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
        int next;
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
            for (int j = 0; j <= i; j++)
            {
                if (matrix == adj_matrix && adj_matrix[i][j] == 0)
                {
                    continue;
                }
                printf("< %d %d >: %d   ", i, j, matrix[i][j]);
            }
            cout << endl;
        }
    }

public:
    Graph() : nodes(0){};
    void readGraph();
    void printGraph();
    void dijkstraAlgo(int source);
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
    cout << "\nThe weight of edge with its nodes:";
    display_lower_tri_matrix(adj_matrix);
}

void Graph::dijkstraAlgo(int source)
{
    int cost[MAX][MAX];
    // CREATE COST MATRIX
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
        }
    }

    // PRINT THE COST MATRIX
    cout << "\nThe cost of edge with its nodes:" << endl;
    display_lower_tri_matrix(cost);

    // INITIALIZING THE 3 ARRAYS
    int distance[MAX], from[MAX];
    bool visited[MAX];
    for (int i = 0; i < nodes; i++)
    {
        distance[i] = cost[source][i];
        visited[i] = false;
        from[i] = source;
    }

    // SETTING VISITED OF SRC TO -1 AND DISTANCE TO ZERO
    visited[source] = true;
    distance[source] = 0;
    from[source] = -1;

    // INITIALY ONLY SRC IS REACHED
    int reached = 1;
    int curr = source;
    int totalcost = 0;
    while (reached < nodes)
    {
        // DISPLAY THE 3 ARRAYS(DISTANCE, FROM, VISITED)
        cout << "Step " << reached << ":" << endl;
        for (int i = 0; i < nodes; i++)
        {
            cout << i << "   ";
        }
        cout << endl;
        for (int i = 0; i < nodes; i++)
        {
            cout << distance[i] << "  ";
        }
        cout << endl;
        for (int i = 0; i < nodes; i++)
        {
            cout << visited[i] << "   ";
        }
        cout << endl;
        for (int i = 0; i < nodes; i++)
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
        cout << endl
             << endl;

        // FIND THE NEXT NODE WITH THE MIN VALUE
        int next = get_nearest_node(distance, visited);
        visited[next] = true;
        totalcost += distance[next];

        // UPDATE THE DISTANCES
        for (int i = 0; i < nodes; i++)
        {
            if (visited[i] == false && distance[next] + cost[next][i] < distance[i])
            {
                distance[i] = distance[next] + cost[next][i];
                from[i] = next;
            }
        }
        curr = next;
        reached++;
    }

    //  PRINT THE TOTAL. COST, SHORTEST DISTANCE TO EACH NODE WITH PATH
    cout << "The total cost is: " << totalcost << endl;
    cout << "The shortest distance to each node with path:" << endl;
    for (int i = 0; i < nodes; i++)
    {
        cout << distance[i] << ": ";
        int node = i;
        while (true)
        {
            cout << node << " -> ";
            node = from[node];
            if (node != -1 && node != -1)
            {
                break;
            }
        }
        cout << "END" << endl;
    }
}

int main(int argc, char const *argv[])
{
    Graph g;
    g.readGraph();
    g.printGraph();
    g.dijkstraAlgo(1);
    return 0;
}
/*
INPUT:
6 8
0 1 15  1 2 12  0 3 10  2 3 10  2 5 15  3 5 4   3 4 9   4 5 8


OUTPUT:
Enter the number of nodes:
6 8
Enter the number of edges:
Enter the weight of edge with its nodes in (node1, node2, weight):
0 1 15  1 2 12  0 3 10  2 3 10  2 5 15  3 5 4  3 4 9   4 5 8
Enter the weight of edge with its nodes in (node1, node2, weight):
Enter the weight of edge with its nodes in (node1, node2, weight):
Enter the weight of edge with its nodes in (node1, node2, weight):
Enter the weight of edge with its nodes in (node1, node2, weight):
Enter the weight of edge with its nodes in (node1, node2, weight):
Enter the weight of edge with its nodes in (node1, node2, weight):
Enter the weight of edge with its nodes in (node1, node2, weight):

The weight of edge with its nodes:
< 1 0 >: 15
< 2 1 >: 12
< 3 0 >: 10   < 3 2 >: 10
< 4 3 >: 9
< 5 2 >: 15   < 5 3 >: 4   < 5 4 >: 8

The cost of edge with its nodes:
< 0 0 >: 99
< 1 0 >: 15   < 1 1 >: 99
< 2 0 >: 99   < 2 1 >: 12   < 2 2 >: 99
< 3 0 >: 10   < 3 1 >: 99   < 3 2 >: 10   < 3 3 >: 99
< 4 0 >: 99   < 4 1 >: 99   < 4 2 >: 99   < 4 3 >: 9   < 4 4 >: 99
< 5 0 >: 99   < 5 1 >: 99   < 5 2 >: 15   < 5 3 >: 4   < 5 4 >: 8   < 5 5 >: 99
Step 1:
0   1   2   3   4   5
15  0  12  99  99  99
0   1   0   0   0   0
1   -1  1   1   1   1

Step 2:
0   1   2   3   4   5
15  0  12  22  99  27
0   1   1   0   0   0
1   -1  1   2   1   2

Step 3:
0   1   2   3   4   5
15  0  12  22  99  27
1   1   1   0   0   0
1   -1  1   2   1   2

Step 4:
0   1   2   3   4   5
15  0  12  22  31  26
1   1   1   1   0   0
1   -1  1   2   3   3

Step 5:
0   1   2   3   4   5
15  0  12  22  31  26
1   -1  1   2   3   3

The total cost is: 106
The shortest distance to each node with path:
15: 0 -> END
0: 1 -> -1 -> END
12: 2 -> END
22: 3 -> END
31: 4 -> END
26: 5 -> END
*/