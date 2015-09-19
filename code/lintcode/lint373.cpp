// lintcode 373.Partition Array by Odd and Even
// Easy 
#include <bits/stdc++.h>

using namespace std;

bool cmp(int a, int b)
{
	if(a % 2 == 1)
	{
		if(b % 2 == 0)	return 1;
		else
		{
			return a < b;
		}
	}
	else
	{
		if(b % 2 == 1)	0;
		else	a < b;
	}
}

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
        sort(nums.begin(), nums.end(), cmp);
        for(int i=0; i<n; i++)
        	cout << nums[i] << endl;
    }
};

int main()
{
	int a[] = {1, 2, 3, 4};
	int n = 4;
	vector <int> v;
	for(int i=0; i<n; i++)
		v.push_back(a[i]);
	Solution sol;
	sol.partitionArray(v);
	return 0;
}
