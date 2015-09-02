// lintcode 413.Reverse Integer
// Easy 
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param n the integer to be reversed
     * @return the reversed integer
     */
    int reverseInteger(int n) {
        // Write your code here
        long long ans = 0;
        int m = n;
        while(m)
        {
        	ans = ans * 10 + m % 10;
        	m /= 10;
        }
        if(ans > INT_MAX)	return 0;
        return ans;
    }
};

int main()
{
	Solution sol;
	int n;
	while(cin >> n)
		cout << sol.reverseInteger(n) << endl;
	return 0;
}
