// lintcode 397.Longest Increasing Continuous subsequence
// Easy 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param A an array of Integer
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int>& A) {
        // Write your code here
        int n = A.size();
        if(n == 0)  return 0;
        int ans1 = 1, ans2 = 1;
        int count = 1;
        for(int i=1; i<n; i++)
        {
        	if(A[i] >= A[i-1])
        		count++;
        	else
        		count = 1;
        	ans1 = max(ans1, count);
        }
        count = 1;
        for(int i=1; i<n; i++)
        {
        	if(A[i] < A[i-1])
        		count++;
        	else
        		count = 1;
        	ans2 = max(ans2, count);
        }
        return max(ans1, ans2);
    }
};


int main()
{
	int a[] = {5,4,2,1,3};
	vector <int> v;
	for(int i=0; i<5; i++)
		v.push_back(a[i]);
	Solution sol;
	cout << sol.longestIncreasingContinuousSubsequence(v) << endl;
	return 0;
}
