#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution
{
public:
    string isValid(string s)
    {
        stack<char> *sk = new stack<char>;
        string new_s = "";
        for (int i = 0; i < s.length(); i++)
        {
            if ( s.at(i) != ')' ) //&& s.at(i) != '}' && s.at(i) != ']')
            {
                new_s.push_back(s.at(i));
                if ( s.at(i) == '(' )//|| s.at(i) == '{' || s.at(i) == '[')
                {
                    sk->push(s.at(i));
                }
            }
            else
            {
                char close_p = s.at(i);
                if (sk->empty())
                {
                    continue;
                }
                else{
                    sk->pop();
                    new_s.push_back(close_p);
                }
            }
        }
        if (!sk->empty())
        {
            while(!sk->empty()){
                char left = sk->top();sk->pop();
                int index = new_s.find_last_of(left);
                new_s.erase(index);
            }
        }
        return new_s;
    }
    vector<string> removeInvalidParentheses(string s)
    {
    }
};