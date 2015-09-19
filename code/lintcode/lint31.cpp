// lintcode 31.Partition Array
// Medium 
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	
	// Two Pointers, Sort
    int partitionArray(vector<int> &nums, int k) {
        // write your code here
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        while(left <= right)
        {
        	if(nums[left] < k)	left++;
        	else	swap(nums[left], nums[right--]);
        }
        return left;
    }
};


int main()
{
	int a[] = {7,7,9,8,6,6,8,7,9,8,6,6};
	vector <int> v;
	int n = 12;
	for(int i=0; i<n; i++)
		v.push_back(a[i]);
	Solution sol;
	int k = 10;
	cout << sol.partitionArray(v, k) << endl;
	return 0;
}
