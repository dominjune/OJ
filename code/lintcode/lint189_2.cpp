// lintcode 189.First Missing Positive 另一种方法实现 
// Medium 
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**    
     * @param A: a vector of integers
     * @return: an integer
     */
    int firstMissingPositive(vector<int> A) {
        // write your code here
        int n = A.size();
        int i;
        for(i=1; i<=n; i++)
        {
        	int j;
        	for(j=0; j<n; j++)
        	{
        		if(i == A[j])
        			break;
        	}
        	if(j == n)
        		return i;
        }
        if(i > n)
        	return n+1;
    }
};

int main()
{
	int n = 4;
	int a[] = {1,2,3,4};
	vector <int> v;
	for(int i=0; i<n; i++)
		v.push_back(a[i]);
	Solution sol;
	cout << sol.firstMissingPositive(v) << endl;
	return 0;
}
