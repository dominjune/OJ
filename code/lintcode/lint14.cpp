// lintcode 14.Binary Search
// Easy 
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0. 
     */
    int binarySearch(vector<int> &array, int target) {
        // write your code here
        int n = array.size();
        int begin = 0, end = n - 1;
        while(begin <= end)
        {
        	int mid = begin + (end - begin) / 2;
        	if(array[mid] >= target)
        	{
        		end = mid - 1;
        	}
        	else
        		begin = mid + 1;
        }
        if(array[begin] == target)
        	return begin;
        return -1;
    }
};

int main()
{
	int n = 7;
	int a[] = {1, 2, 3, 3, 4, 5, 10};
	vector <int> v;
	for(int i=0; i<n; i++)
		v.push_back(a[i]);
	int target = 3;
	Solution sol;
	cout << sol.binarySearch(v, target) << endl;
	return 0;
}
