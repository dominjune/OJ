// lintcode 138.Subarray Sum
// Easy 
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        // write your code here
        int n = nums.size();
        vector <int> v;
        for(int i=0; i<n; i++)
        {
        	int sum = nums[i];
        	bool flag = 0;
        	if(sum == 0)
        	{
        		v.push_back(i);
        		v.push_back(i);
        		break;
        	}
        	for(int j=i+1; j<n; j++)
        	{
        		sum += nums[j];
        		if(sum == 0)
	        	{
	        		v.push_back(i);
	        		v.push_back(j);
	        		flag = 1;
	        		break;
	        	}
        	}
        	if(flag)
        		break;
        }
        //for(int i=0; i<v.size(); i++)	cout << v[i] << endl;
        return v;
    }
};

int main()
{
	int a[] = {-3, 1, 2, -3, 4};
	int n = 5;
	vector <int> v;
	for(int i=0; i<n; i++)
		v.push_back(a[i]);
	Solution sol;
	sol.subarraySum(v);
	return 0;
}
