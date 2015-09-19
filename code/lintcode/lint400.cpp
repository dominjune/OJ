// lintcode 400.Maximum Gap
// Hard 
// Õ∞≈≈–Ú Œ¥ µœ÷ 
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: the maximum difference
     */
    int maximumGap(vector<int> nums) {
        // write your code here
        int n = nums.size();
        if(n < 2)   return 0;
        sort(nums.begin(), nums.end());
        int res = 0;
        for(int i=0; i<n-1; i++)
        {
            res = max(res, nums[i+1] - nums[i]);
        }
        return res;
    }
};

int main()
{
	
	return 0;
}
