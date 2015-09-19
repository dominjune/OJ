// lintcode 402.Continuous Subarray Sum
// Medium 
// Example
// Give [-3, 1, 3, -3, 4], return [1,4].
#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

class Solution {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of 
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySum(vector<int>& A) {
        // Write your code here
        vector <int> res;
        int n = A.size();
        int sum = 0, ans = -INF;
        int l = 0, r = 0, left = 0, right = 0;
        for(int i=0; i<n; i++)
        {
        	sum += A[i];
        	if(ans < sum)	// 要先判断这个... 
        	{
        		ans = sum;
        		right = i;
        		left = l;	// 记录左边下标时比较特殊 
        	}
        	if(sum < 0)
        	{  	
        		if(i + 1 < n)
        		{
        			sum = 0;
        			l = i + 1;		
        		}
        		//continue;
        	}
        
        }
        //cout << left << " " << right << endl;
        res.push_back(left);
        res.push_back(right);
        //cout << ans << endl;
        return res;
    }
};

int main()
{
	vector <int> v;
	int a[] = {1,2,-2,-100,1,2,-2};
	int n = 7;
	for(int i=0; i<n; i++)
		v.push_back(a[i]);
	Solution sol;
	sol.continuousSubarraySum(v);
	return 0;
}
