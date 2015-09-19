// lintcode 373.Partition Array by Odd and Even
// Easy 
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: nothing
     */
    // Two Pointers...
    void partitionArray(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        int left = 0, right = n - 1;
        while(left < right)
        {
        	while(nums[left] % 2 == 1)
        		left++;
        	while(nums[right] % 2 == 0)
        		right--;
        	if(left < right)
        		swap(nums[left], nums[right]);
        	left++;
        	right--;
        }
        //for(int i=0; i<n; i++)
        //	cout << nums[i] << endl;
    }
};

int main()
{
	int a[] = {2, 3, 4, 5};
	int n = 4;
	vector <int> v;
	for(int i=0; i<n; i++)
		v.push_back(a[i]);
	Solution sol;
	sol.partitionArray(v);
	return 0;
}
