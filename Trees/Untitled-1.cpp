#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	// int num;
	// 	int helper(int A, int B) {
	//     if(A%num==0&&B%num==0)
	// 	    {
	// 	        return num;
	// 	    }
	// 	   num--;
	// 	   return helper(A,B);
	// 	}

	// 	int gcd(int A, int B)
	// 	{
	// 	    num=min(A,B);
	// 	    return helper(A,B);
	// 	}
	int gcd(int A, int B)
	{
		// code here

		for (int i = min(A, B); i > 0; i--)
		{
			if (A % i == 0 && B % i == 0)
			{
				return i;
			}
		}
		static int num = min(A, B);
		if (A % num == 0 && B % num == 0)
		{
			return num;
		}
		num--;
		return gcd(A, B);
	}
};
int main(int argc, char const *argv[])
{
	Solution s;
	cout << s.gcd(14, 12);
	return 0;
}
