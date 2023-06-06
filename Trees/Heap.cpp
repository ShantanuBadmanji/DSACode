#include <iostream>
#define MAX 20
using namespace std;

class Heap
{
public:
    int heap[MAX];
    int nodes;
#define PARENT(n) (n - 1) / 2
#define LEFT(n) 2 * n + 1
#define RIGHT(n) 2 * n + 2

    Heap(int vertices = 0) : nodes(vertices){};
    void read_heap_array();
    void read_heap_array(int *arr, int n);
    void build_minHeap();
    void build_maxHeap();
    void min_heapify(int index);
    void max_heapify(int index);
    void heapdisplay();
    void push(int val);
    int pop();
};
void Heap::heapdisplay()
{
    for (int i = 0; i < nodes; i++)
    {
        cout << heap[i] << " ";
    }
    cout << endl;
}
void Heap::min_heapify(int index)
{
    int smallest = index;
    if (LEFT(index) < nodes && heap[smallest] > heap[LEFT(index)])
    {
        smallest = LEFT(index);
    }
    if (RIGHT(index) < nodes && heap[smallest] > heap[RIGHT(index)])
    {
        smallest = RIGHT(index);
    }
    if (smallest != index)
    {
        swap(heap[index], heap[smallest]);
        min_heapify(smallest);
    }
}
void Heap::max_heapify(int index)
{
    int largest = index;
    if (LEFT(index) < nodes && heap[largest] < heap[LEFT(index)])
    {
        largest = LEFT(index);
    }
    if (RIGHT(index) < nodes && heap[largest] < heap[RIGHT(index)])
    {
        largest = RIGHT(index);
    }
    if (largest != index)
    {
        swap(heap[index], heap[largest]);
        max_heapify(largest);
    }
}
void Heap::push(int val)
{
    heap[nodes++] = val;
}
void Heap::read_heap_array()
{
    cout << "Enter the number of nodes" << endl;
    cin >> nodes;
    cout << "Enter the elements" << endl;
    for (int i = 0; i < nodes; i++)
    {
        int v;
        cin >> v;
        heap[i] = v;
    }
}
void Heap::read_heap_array(int arr[], int n)
{
    nodes = n;
    // nodes =sizeof(arr)/sizeof(*arr);
    for (int i = 0; i < nodes; i++)
    {
        heap[i] = arr[i];
    }
}
void Heap::build_minHeap()
{
    cout << "min_heap: " << endl;
    for (int i = PARENT(nodes - 1); i >= 0; i--)
    {
        min_heapify(i);
        heapdisplay();
    }
}
void Heap::build_maxHeap()
{
    cout << "max_heap: " << endl;
    for (int i = PARENT(nodes - 1); i >= 0; i--)
    {
        max_heapify(i);
        heapdisplay();
    }
}
int Heap::pop()
{
    bool isminheap = heap[0] < heap[nodes - 1];
    heap[0] = heap[--nodes];
    if (isminheap)
        min_heapify(0);
    else
        max_heapify(0);
}
int main(int argc, char const *argv[])
{
    Heap h;
    int arr[] = {5, 7, 9, 1, 3, 10, 8, 4};
    h.read_heap_array(arr, 8);
    h.build_maxHeap();
    // h.heapdisplay();
    // h.push(100);
    h.build_minHeap();
    h.heapdisplay();
    // h.pop();
    // h.heapdisplay();
    cout << sizeof(h.heap) / sizeof(*h.heap);
    return 0;
}