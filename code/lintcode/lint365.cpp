// lintcode 365. Count 1 in Binary
// Easy
#include <cstdio>

using namespace std;

class Solution {
public:
    /**
     * @param num: an integer
     * @return: an integer, the number of ones in num
     */
    int countOnes(int num) {
        // write your code here
        int ans = 0;
        while(num)
        {
        	if(num % 2)	
        		ans++;
        	num /= 2;
        }
        return ans;
    }
};

int main()
{
	
	return 0;
}
