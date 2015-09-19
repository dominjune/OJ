// lintcode 395.Coins in a Line II
// Medium 

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // write your code here
        vector<int> dp(values.size());
        int sum = 0;
        for (int i = values.size() - 1; i >= 0; --i) 	//P[i] 表示第i个取到最后一个的最优取法 
		{
            sum += values[i];
            const int a = i + 1 < values.size() ? values[i + 1]: 0;
            const int b = i + 2 < values.size() ? dp[i + 2] : 0;
            const int c = i + 3 < values.size() ? dp[i + 3] : 0;
            const int d = i + 4 < values.size() ? dp[i + 4] : 0;
            dp[i] = max(values[i] + min(b, c),  values[i] + a + min(c, d));	// max(取一个，两个) 
        }
        return dp[0] > sum - dp[0];
    }
};


int main()
{
	int a[] = {1,3,2,7};
	int n = 4;
	vector <int> v;
	for(int i=0; i<n; i++)
		v.push_back(a[i]);
	Solution sol;
	cout << sol.firstWillWin(v) << endl;
	return 0;
}

