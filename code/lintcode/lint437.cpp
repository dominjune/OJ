// lintcode 437 copy books
// references:
// http://sidbai.github.io/2015/07/25/Copy-Books/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param pages: a vector of integers
     * @param k: an integer
     * @return: an integer
    **/
    
    int copyBooks(vector <int> &pages, int k) {
        int n = pages.size();
        int r = 0, l = 0;
        for(int i=0; i<n; i++)
        	r += pages[i];
        //¶þ·Ö°¡ºÃ¿Ó 
        while(l <= r)
        {
        	int m = l + (r - l) / 2;
        	if(check(pages, m, k))
        	{
        		//ans = m;
        		r = m-1;
        	}
        	else
        		l = m+1;
        }
        return l;
    }  
    bool check(vector<int> &pages, int m, int k)
    {
    	int i = 0, sum = 0, count = 0;
    	while(i < pages.size())
    	{
    		if(sum + pages[i] <= m)
    		{
    			sum += pages[i];
    			i++;
    		}
    		else if(pages[i] <= m)
			{
    			count++;
				sum = 0;	
    		}
    		else
    			return false;
    	}
    	//if(sum)	count++;
    	return count <= k-1;
    }
};

int main()
{
	vector <int> pages;
	pages.push_back(3);
	pages.push_back(2);
	pages.push_back(4);
	int k = 2;
	Solution sol;
	cout << sol.copyBooks(pages, k) << endl;
	return 0;
}


