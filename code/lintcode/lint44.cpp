// lintcode 44.Minimum Subarray
// Easy 
#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: A integer denote the sum of minimum subarray
     */
    int minSubArray(vector<int> nums) {
        // write your code here
        int n = nums.size();
        int sum = 0, ans = INF;
        for(int i=0; i<n; i++)
        {
        	if(sum > 0)
        		sum = nums[i];
        	else
        		sum += nums[i];
        	ans = min(ans, sum);
        }
        return ans;
    }
};



int main()
{
	int a[] = {1, -1, -2, 1};
	int n = 4;
	vector <int> v;
	for(int i=0; i<n; i++)
		v.push_back(a[i]);
	Solution sol;
	cout << sol.minSubArray(v) << endl;
	return 0;
}
