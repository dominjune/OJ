// lintcode 41.Maximum Subarray
// Easy 
#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

class Solution {
public:    
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
     //最大子数组求和 
    int maxSubArray(vector<int> nums) {
        // write your code here
        int n = nums.size();
        int sum = 0, ans = -INF;
        for(int i=0; i<n; i++)
        {
        	if(sum < 0)
        		sum = nums[i];
        	else
        		sum += nums[i];
        	ans = max(ans, sum);
        }
        return ans;
    }
};


int main()
{
	int a[] = {-2,2,-3,4,-1,2,1,-5,3};
	int n = 9;
	vector <int> v;
	for(int i=0; i<n; i++)
		v.push_back(a[i]);
	Solution sol;
	cout << sol.maxSubArray(v) << endl;
	return 0;
}
