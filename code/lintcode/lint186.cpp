// lintcode 186.Max Points on a Line
// Medium 
#include <bits/stdc++.h>

using namespace std;

//Definition for a point.
struct Point {
     int x;
     int y;
     Point() : x(0), y(0) {}
     Point(int a, int b) : x(a), y(b) {}
};

const int INF = 0x3f3f3f3f;
class Solution {
public:
    /**
     * @param points an array of point
     * @return an integer
     */
    int maxPoints(vector<Point>& points) {
        // Write your code here
        int n = points.size();
        if(n == 0)  return 0;
        int ans = 0;
        for(int i=0; i<n; i++)
    	{
    		map <double, int> m;	//每次只对一个点
    		Point a = points[i];
    		for(int j=0; j<n; j++)
    		{
    			if(j != i)
    			{
    				Point b = points[j];
    				double k;
    				if(b.x != a.x)  k = (double)(b.y - a.y) / (double)(b.x - a.x);
    				else    k = INF;
    				m[k]++;
    			}
    		}
    		map <double, int>::iterator it = m.begin();
	    	for( ; it != m.end(); it++)     ans = max(ans, it->second);
    	}
    	return ans+1;
    }
};

int main()
{
	
	return 0;
}

