#include<iostream>
#include<exception>
#include"ArrayStack.cpp"
#include"LLStack.cpp"

using namespace std;

int main(int argc, char const *argv[])
{
    ArrayStack<string> stk(5);
    cout<<stk.push("omg")<<endl;
    cout<<stk.push("ok")<<endl;
    cout<<stk.push("rajesh")<<endl;
    cout<<stk.push("mahesh")<<endl;
    cout<<stk.push("kedar")<<endl;
    // cout<<stk.push("mayur");

    cout<<stk.pop()<<endl;
    cout<<stk.pop()<<endl;
    cout<<stk.pop()<<endl;
    cout<<stk.pop()<<endl;
    cout<<stk.pop()<<endl;
    // cout<<stk.pop()<<endl;

    LLStack<string> lsk;
    lsk.push("1");
    lsk.push("2");
    lsk.push("3");
    lsk.push("4");
    cout<<lsk.pop()<<endl;
    cout<<lsk.pop()<<endl;
    cout<<lsk.pop()<<endl;
    cout<<lsk.pop()<<endl;
    // cout<<lsk.pop()<<endl;
    return 0;
}
