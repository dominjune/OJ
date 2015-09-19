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
        map <int, int> m;
        int n = nums.size();
        vector <int> v;
        int sum = 0;
        for(int i=0; i<n; i++)
        {
        	sum += nums[i];
        	if(sum == 0)
        	{
        		v.push_back(0);
        		v.push_back(i);
        		break;
        	}
        	if(m.find(sum) != m.end())
        	{
        		v.push_back(m[sum] + 1);
        		v.push_back(i);
        		break;
        	}
        	m[sum] = i;
        }
        //for(int i=0; i<v.size(); i++)	cout << v[i] << endl;
        return v;
    }
};

int main()
{
	int a[] = {1, -3, 1, 2, -3, 4};
	int n = 6;
	vector <int> v;
	for(int i=0; i<n; i++)
		v.push_back(a[i]);
	Solution sol;
	sol.subarraySum(v);
	return 0;
}
