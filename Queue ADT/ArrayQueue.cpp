#include <iostream>
#define DEFAULT_SIZE 10
using namespace std;

template <typename T, int N = DEFAULT_SIZE>
class StaticArrayQueue
{
    int front;
    int rear;
    const int MAX_SIZE = N;
    int current_size;
    T que[N];

public:
    StaticArrayQueue() : rear(-1), front(-1), current_size(0) {}

    bool isempty()
    {
        return rear == -1 && front == -1;
    }
    bool isFull()
    {
        return front == (rear + 1) % MAX_SIZE;
    }
    void push(const T &data)
    {
        if (isFull())
        {
            throw "Queue is full.";
        }
        if (front == -1)
        {
            front++;
        }
        rear = (++rear) % MAX_SIZE;
        que[rear] = data;
        current_size++;
    }
    const T &pop()
    {
        if (isempty())
        {
            throw "Queue is empty.";
        }
        T &temp = que[front];
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (++front) % MAX_SIZE;
        }
        current_size--;
        return temp;
    }
    const T &infront()
    {
        if (isempty())
        {
            throw "Queue is empty.";
        }
        return que[front];
    }
    const T &atrear()
    {
        if (isempty())
        {
            throw "Queue is empty.";
        }
        return que[rear];
    }
    const int &size()
    {
        return MAX_SIZE;
    }
    void displayQueArr()
    {
        for (T ele : que)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
    void display()
    {
        for (auto i = 0; i < current_size; i++)
        {
            cout << que[(front + i) % MAX_SIZE] << " ";
        }
        cout << endl;
    }
};

template <typename T>
class ArrayQueue
{
protected:
    int front;
    int rear;
    int MAX_SIZE;
    int current_size;
    T *que;

public:
    ArrayQueue(int size = DEFAULT_SIZE) : rear(-1), front(-1), current_size(0), que(new T[size]), MAX_SIZE(size) {}

    bool isempty()
    {
        return rear == -1 && front == -1;
    }
    bool isFull()
    {
        return front == (rear + 1) % MAX_SIZE;
    }
    void virtual push(const T &data)
    {
        if (isFull())
        {
            throw "Queue is full.";
        }
        if (front == -1)
        {
            front++;
        }
        rear = (++rear) % MAX_SIZE;
        que[rear] = data;
        current_size++;
    }
    const T &pop()
    {
        if (isempty())
        {
            throw "Queue is empty.";
        }
        T &temp = que[front];
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (++front) % MAX_SIZE;
        }
        current_size--;
        return temp;
    }
    T &infront()
    {
        if (isempty())
        {
            throw "Queue is empty.";
        }
        return que[front];
    }
    const T &atrear()
    {
        if (isempty())
        {
            throw "Queue is empty.";
        }
        return que[rear];
    }
    const int &size()
    {
        return MAX_SIZE;
    }
    void displayQueArr()
    {
        for (int i = 0; i < MAX_SIZE; i++)
        {
            cout << que[i] << " ";
        }
        cout << endl;
    }
    void display()
    {
        for (auto i = 0; i < current_size; i++)
        {
            cout << que[(front + i) % MAX_SIZE] << " ";
        }
        cout << endl;
    }
};

template <typename T>
class DyamicQueue : public ArrayQueue<T>
{
public:
    DyamicQueue(int size = DEFAULT_SIZE) : ArrayQueue<T>(size) {}
    using ArrayQueue<T>::isFull;
    using ArrayQueue<T>::push;
    using ArrayQueue<T>::current_size;
    using ArrayQueue<T>::que;
    using ArrayQueue<T>::front;
    using ArrayQueue<T>::rear;
    using ArrayQueue<T>::MAX_SIZE;
    void push(const T &data) override
    {
        if (isFull())
        {
            MAX_SIZE *= 2;
            T *newque = new T[MAX_SIZE];
            for (auto i = 0; i < current_size; i++)
            {
                newque[i] = que[(front + i) % MAX_SIZE];
            }
            que = newque;
        }

        ArrayQueue<T>::push(data);
    }
};