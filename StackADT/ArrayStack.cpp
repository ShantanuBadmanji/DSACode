#include<iostream>
// #include<exception>
// using namespace std;

template <typename T>
class ArrayStack
{
private:
    T *stk;
    int top;
    int capacity;
    static const int default_size = 10;

public:
    ArrayStack(int capacity  = default_size): stk(new T[capacity]), top(-1), capacity(capacity){}

    bool isempty(){
        return top==-1;
    }
    bool isfull(){
        return top ==capacity-1;
    }
    bool push(const T& item){
        if(isfull()){
            throw "stack is full.";
            return false; 
        }
        stk[++top] = item;
        return true;
    }
    T& pop(){
        if(isempty()){
            throw "stack is empty.";
        }
        return stk[top--];
    }
    const T& peek(){
        if(isempty()){
            throw "stack is empty.";
        }
        return stk[top];
    }

};