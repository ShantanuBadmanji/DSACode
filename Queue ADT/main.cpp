#include<iostream>
#include"ArrayQueue.cpp"
using namespace std;
int main(int argc, char const *argv[])
{
    // StaticArrayQueue<int,5> que;
    // cout<<que.isempty()<<endl;
    // que.push(5);
    // que.push(15);
    // que.push(25);
    // que.push(35);
    // que.push(45);
    // cout<<que.pop()<<endl;
    // que.push(55);
    // que.display();
    // que.displayQueArr();
    // cout<<que.pop()<<endl;
    // cout<<que.pop()<<endl;
    // cout<<que.pop()<<endl;
    // // cout<<que.pop()<<endl;
    // // cout<<que.pop()<<endl;
    // cout<<que.infront()<<endl;
    // cout<<que.atrear()<<endl;
    // // cout<<que.size()<<endl;  
    // const int& size = que.size();
    // // size++;
    // int newsize = que.size();
    // newsize++;
    // cout<<que.size()<<endl;

    // ArrayQueue<int> *arq = new ArrayQueue<int>(3);
    // arq->push(0);
    // arq->push(1);
    // arq->push(2);
    // cout<<arq->pop()<<endl;
    // cout<<arq->size()<<endl;
    // arq->push(3);
    // arq->display();
    // arq->displayQueArr();

    DyamicQueue<int> dque(4);
    dque.push(2);    
    dque.push(7);    
    dque.push(4);    
    dque.push(23); 
    cout<<dque.size()<<endl;
    dque.push(32); 
    cout<<dque.size()<<endl;
    dque.displayQueArr();  
    cout<<dque.pop()<<endl;
    cout<<dque.pop()<<endl;
    cout<<dque.pop()<<endl; 
    dque.display();  
    dque.displayQueArr();  
    return 0;

}

