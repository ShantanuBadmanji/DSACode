#include<iostream>
#include<exception>
template<typename T>
struct Node{
    T data;
    Node *next;
    // Node *prev;
    Node(T data): data(data), next(NULL){}
    Node(T data, Node *next): data(data), next(next){}
    // Node(T data): data(data), prev(NULL), next(NULL){}
    // Node(T data,Node *next,Node *prev):data(data),prev(prev),next(next){}
};

template<typename T>
class LLStack{
private:
    Node<T> *head,*tail;
    int size;
public:
    LLStack():head(NULL),tail(NULL),size(0){}

    bool isempty(){
        return head ==NULL;
    }
    void push(const T& data){
        Node<T> *node = new Node<T>(data);
        if(head == NULL){
            tail = head = node;
            return;
        }
        node->next = head;
        head = node;
        size++;
    }
    T& pop(){
        if(isempty()){
            throw "Stack underflow.";
        }
        T& temp = head->data;
        head = head->next;
        size--;
        return temp;
    }
    const T& top(){
        if(isempty()){
            throw "Stack underflow.";
        }
        return head->data;
    }
    int getsize(){
        return size;
    }
};