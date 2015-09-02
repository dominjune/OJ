// lintcode 196.Find the Missing Number
class Solution {
public:
    /**    
     * @param nums: a vector of integers
     * @return: an integer
     */
    int findMissing(vector<int> &nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++)
            sum += nums[i];
        return n*(n+1)/2-sum;
    }
};

