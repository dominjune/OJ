// lintcode 411.Gray Code
// Medium 
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param n a number
     * @return Gray code
     */
    vector<int> grayCode(int n) {
        // Write your code here
        vector <int> v;
        for(int i=0; i<(1<<n); i++)
        	v.push_back((i ^ (i >> 1)));
        return v;
    }
};

int main()
{
	vector <int> v;
	Solution sol;
	int n = 2;
	sol.grayCode(n);
	return 0;
}
