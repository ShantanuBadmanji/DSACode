#include <iostream>
#define INFINITY 99
#define MAX 20
using namespace std;

typedef struct adjListNode
{
    int val;
    adjListNode *next;
    adjListNode(int _val = 0) : val(_val), next(NULL) {}
} ADJNODE;

class stack
{
    int arr[MAX];
    int top;

public:
    stack() : top(-1) {}

    bool empty()
    {
        return (top == -1);
    }
    bool full()
    {
        return (top == MAX - 1);
    }
    void push(int node)
    {
        arr[++top] = node;
    }
    int pop()
    {
        int temp = arr[top--];
        return temp;
    }
    int peek()
    {
        int temp = arr[top];
        return temp;
    }
};

class queue
{
    int front;
    int rear;
    int arr[MAX];

public:
    queue() : front(-1), rear(-1) {}

    bool isempty()
    {
        return rear == -1;
    }
    void reset()
    {
        front = rear = -1;
    }
    bool isfull()
    {
        return front == (rear + 1) % MAX;
    }
    bool enque(int node)
    {
        if (isfull())
            return false;
        if (front == -1)
            front++;
        rear = (rear + 1) % MAX;
        arr[rear] = node;
        return true;
    }
    int infront() const
    {
        return arr[front];
    }
    int deque()
    {
        if (isempty())
            return -1;

        int temp = arr[front];
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (++front) % MAX;
        }
        return temp;
    }
};

class Graph
{
    struct Edge
    {
        int v1, v2;
        int weight;
    };

private:
    ADJNODE *adj_list[MAX];
    Edge allEdges[MAX];
    int num_edges;
    int nodes;
    // int counter[MAX];
    void addnode(ADJNODE *&head, int data);

public:
    Graph() : nodes(0){};
    void readGraph();
    void printGraph();
    void breathFirstSearch(int source);
    void depththFirstSearch(int source);
};
void Graph::addnode(ADJNODE *&head, int data)
{
    if (head == NULL)
    {
        head = new ADJNODE(data);
        return;
    }
    ADJNODE *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new ADJNODE(data);
}
void Graph::readGraph()
{
    cout << "Enter the number of nodes:" << endl;
    cin >> nodes;

    // EDGES INPUT
    cout << "Enter the number of edges:" << endl;
    cin >> num_edges;
    for (int i = 0; i < num_edges; i++)
    {
        cout << "Enter the weight of edge with its nodes in (node1, node2, weight):" << endl;
        cin >> allEdges[i].v1 >> allEdges[i].v2 >> allEdges[i].weight;
    }
    //INITIALIZE ADJ_LIST
    for (int i = 0; i < nodes; i++)
    {
        // counter[i] = 0;
        adj_list[i] = NULL;
    }

    for (int i = 0; i < num_edges; i++)
    {
        int u = allEdges[i].v1;
        int v = allEdges[i].v2;
        addnode(adj_list[u], v);
        // counter[u]++;
        addnode(adj_list[v], u);
        // counter[v]++;
    }
}

void Graph::printGraph()
{
    cout << "\nThe adjcency list:" << endl;
    for (int i = 0; i < nodes; i++)
    {
        ADJNODE *temp = adj_list[i];
        cout << i << ": ";
        while (temp != NULL)
        {
            cout << temp->val << "->";
            temp = temp->next;
        }
        cout << "END" << endl;
    }
}

void Graph::breathFirstSearch(int source)
{
    bool visited[MAX];
    for (int i = 0; i < nodes; i++)
    {
        visited[i] = false;
    }

    queue que;
    que.enque(source);
    visited[source] = true;
    cout << "\nthe BFS of this graph starting from " << source << " is: " << endl;
    while (!que.isempty())
    {
        int vertex = que.deque();
        cout << vertex << "  ";
        ADJNODE *tmp = adj_list[vertex];
        while (tmp != NULL)
        {
            if (visited[tmp->val] == false)
            {
                que.enque(tmp->val);
                visited[tmp->val] = true;
            }
            tmp = tmp->next;
        }
    }
    cout << endl;
}

void Graph::depththFirstSearch(int source)
{
    bool visited[MAX];
    for (int i = 0; i < nodes; i++)
    {
        visited[i] = false;
    }
    cout << "\nthe DFS of this graph starting from " << source << " is: " << endl;
    stack stk;
    stk.push(source);
    visited[source] = true;
    cout << source << "  ";

    // ALGO START !!!
    ADJNODE *tmp = adj_list[source];
    while (tmp != NULL)
    {
        if (visited[tmp->val] == false)
        {
            cout << tmp->val << "  ";
            stk.push(tmp->val);
            visited[tmp->val] = true;
            tmp = adj_list[tmp->val];
        }
        else
        {
            tmp = tmp->next;
        }
    }
    while (!stk.empty())
    {
        int vertex = stk.pop();
        ADJNODE *tmp = adj_list[vertex];
        while (tmp != NULL)
        {
            if (visited[tmp->val] == false)
            {
                cout << tmp->val << "  ";
                stk.push(tmp->val);
                visited[tmp->val] = true;
                tmp = adj_list[tmp->val];
            }
            else
            {
                tmp = tmp->next;
            }
        }
        // FOR REVERSE OUTPUT
        // cout << vertex << "  ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    Graph g;
    g.readGraph();
    g.printGraph();
    cout << "\nBFS SOURCE:";
    int src;
    cin >> src;
    g.breathFirstSearch(src);
    cout << "\nDFS SOURCE:";
    cin >> src;
    g.depththFirstSearch(src);
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
0 1 15  1 2 12  0 3 10  2 3 10  2 5 15  3 5 4   3 4 9   4 5 8
Enter the weight of edge with its nodes in (node1, node2, weight):
Enter the weight of edge with its nodes in (node1, node2, weight):
Enter the weight of edge with its nodes in (node1, node2, weight):
Enter the weight of edge with its nodes in (node1, node2, weight):
Enter the weight of edge with its nodes in (node1, node2, weight):
Enter the weight of edge with its nodes in (node1, node2, weight):
Enter the weight of edge with its nodes in (node1, node2, weight):

The adjcency list:
0: 1->3->END
1: 0->2->END
2: 1->3->5->END
3: 0->2->5->4->END
4: 3->5->END
5: 2->3->4->END

BFS SOURCE:5

the BFS of this graph starting from 5 is:
5  2  3  4  1  0

DFS SOURCE:4

the DFS of this graph starting from 4 is:
4  3  0  1  2  5
PS F:\SHANTANU_WORKSPACE\viit sy prac\dsa_prac\Trees> */