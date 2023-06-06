#include <bits/stdc++.h>
using namespace std;
bool validPalindrome(string s)
{
    int start = 0, end = s.length() - 1;
    for (; start <= end; start++, end--)
    {
        if (s[start] != s[end])
        {
            int ns = start + 1, ne = end;
            for (; ns <= ne; ns++, ne--)
            {
                if (s[ns] != s[ne])
                {
                    ns = start;
                    ne = end - 1;
                    for (; ns <= ne; ns++, ne--)
                    {
                        if (s[ns] != s[ne])
                        {
                            return false;
                        }
                    }
                    return true;
                }
            }
            return true;
        }
    }
    return true;
}
int main()
{
    char s[] = "ebcbbececabbacecbbcbe";
    if (validPalindrome(s))
        printf("true\n");
    else
        printf("false\n");
    return 0;
}