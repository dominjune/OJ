// lintcode 436.Maximal Square
// Medium 
#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001];

class Solution {
public:
    /**
     * @param matrix: a matrix of 0 and 1
     * @return: an integer
     */
    int maxSquare(vector<vector<int> > &matrix) {
        // write your code here
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
		for(int i=0; i<n; i++)
		{
			if(matrix[i][0])
			{
				dp[i][0] = 1;
				ans = 1;
			}
				
		}
		for(int i=0; i<m; i++)
		{
			if(matrix[0][i])
			{
				dp[0][i] = 1; 
				ans = 1;
			}			
		}
		for(int i=1; i<n; i++)
		{
			for(int j=1; j<m; j++)
			{
				if(matrix[i][j])
					dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;	//取三者最小 
				else
					dp[i][j] = 0;
				//cout << dp[i][j] << endl;
				ans = max(ans, dp[i][j]);
			}
		}
		return ans * ans;
	}
};

int main()
{
	
	return 0;
}
