// lintcode 387.The Smallest Difference
// Medium 
#include <bits/stdc++.h>

using namespace std;

const int INF = INT_MAX;

class Solution {
public:
    /**
     * @param A, B: Two integer arrays.
     * @return: Their smallest difference.
     */
    int smallestDifference(vector<int> &A, vector<int> &B) {
        // write your code here
        int na = A.size();
        int nb = B.size();
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        int i = 0, j = 0;
        int minn = INF;
        while(i < na && j < nb)
        {
        	minn = min(minn, abs(A[i] - B[j]));
        	if(A[i] < B[j])	
				i++;
			else
				j++;
        }
        //cout << minn << endl;
        return minn;
    }
};


int main()
{
	int n = 4;
	int a[] = {4,3,6,7};
	int b[] = {3,2,8,9};
	vector <int> A;
	vector <int> B;
	for(int i=0; i<n; i++)
		A.push_back(a[i]);
	for(int j=0; j<n; j++)
		B.push_back(b[j]);
	Solution sol;
	sol.smallestDifference(A, B);
	return 0;
}
