// lintcode 190.Next Permutation II
// Medium 
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: return nothing (void), do not return anything, modify nums in-place instead
     */
    void nextPermutation(vector<int> &nums) {
        // write your code here
        // next_permutation
        /*int n = nums.size();
        int *a = new int[n];
        for(int i=0; i<n; i++)
        	a[i] = nums[i];
        next_permutation(a, a + n);
        for(int i=0; i<n; i++)
        	nums[i] = a[i];*/
        // 1,2,5,4,3
        int i = nums.size() - 1;
        for(; i > 0; i--){
            if(nums[i] > nums[i - 1]) break;	// nums[i] = 5
        }
       
        if(i == 0){
            sort(nums.begin(), nums.end());
            return;
        }
        int tmp = nums[i-1];	// tmp = 2
        int min = INT_MAX, minIndex = i;
        for(int j = i+1; j <= nums.size() - 1; j++)
		{
            if(nums[j] > tmp && nums[j] < min)
			{
                minIndex = j;
                min = nums[j];
            }
        }
        swap(nums[i-1], nums[minIndex]);	// nums[i-1] = 2, nums[minIndex] = 3
        sort(nums.begin() + i, nums.end());
    }
};

int main()
{
	vector <int> v;
	int n = 5;
	int a[] = {1,2,5,4,3};
	for(int i=0; i<n; i++)
		v.push_back(a[i]);
	Solution sol;
	sol.nextPermutation(v); 
	for(int i=0; i<v.size(); i++)
		cout << v[i] << endl;
	return 0;
}
