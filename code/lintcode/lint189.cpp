// lintcode 189.First Missing Positive
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
        // e.g. 112 -> 121, 第三个不是3，返回3
		// e.g. 123 -> 123，返回n+1 
        int n = A.size();
        for(int i=0; i<n; i++)
        {
        	while(A[i] > 0 && A[i] <= n && A[A[i]-1] != A[i])
        		swap(A[A[i]-1], A[i]);
        }
        for(int i=0; i<n; i++)
        	if(A[i] != i + 1)
        		return i + 1;
        return n + 1;
    }
};

int main()
{
	int n = 1;
	int a[] = {1};
	vector <int> v;
	for(int i=0; i<n; i++)
		v.push_back(a[i]);
	Solution sol;
	cout << sol.firstMissingPositive(v) << endl;
	return 0;
}

