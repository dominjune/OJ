// lintcode 434.Number of Islands II
// Hard 
// http://www.1point3acres.com/bbs/forum.php?mod=viewthread&action=printable&tid=137243
#include <bits/stdc++.h>

using namespace std;

// Definition for a point.
struct Point {
     int x;
     int y;
     Point() : x(0), y(0) {}
     Point(int a, int b) : x(a), y(b) {}
};

int move_x[] = {-1,1,0,0};
int move_y[] = {0,0,1,-1};

int find(vector <int> &p, int x)
{
	return p[x] == x ? x : p[x] = find(p, p[x]);
}

int union_set(vector <int> &p, int x, int y)
{
	int fx = find(p, x);
	int fy = find(p, y);
	if(fx != fy)
		p[fx] = fy;
}

class Solution {
public:
    /**
     * @param n an integer
     * @param m an integer
     * @param operators an array of point
     * @return an integer array
     */
    // Union Set
    vector<int> numIslands2(int n, int m, vector<Point>& operators) {
        // Write your code here
        int size = operators.size();
        vector <int> p(n * m, -1);
		vector <int> res(size);
        int cur = 0;
        for(int i=0; i<size; i++)
        {
        	int x = operators[i].x;
        	int y = operators[i].y;
        	int pos = x * m + y;
        	//if(p[pos] != -1)	continue;
        	p[pos] = pos;
        	//int t = find(p, pos);
        	set <int> hash;
        	for(int j=0; j<4; j++)
        	{
        		int tempx = x + move_x[j];
        		int tempy = y + move_y[j];
        		int pos_temp = tempx * m + tempy;
        		if(tempx >= 0 && tempx < n && tempy >=0 && tempy < m && p[pos_temp] != -1)
        		{
        			int t = find(p, pos_temp);
        			if(hash.find(t) == hash.end())
        				hash.insert(t);
        		}		
        	}
        	
        	for(int j=0; j<4; j++)
        	{
        		int tempx = x + move_x[j];
        		int tempy = y + move_y[j];
        		int pos_temp = tempx * m + tempy;
        		if(tempx >= 0 && tempx < n && tempy >=0 && tempy < m && p[pos_temp] != -1)
        		{
        			union_set(p, pos, pos_temp);
        		}	
        	}
        	cur += 1 - hash.size();
        	res[i] = cur;
        }
        return res;
    }
    /*
    Time Limited Exceeded
    void dfs(int i, int j, int n, int m, int graph[][1001])
    {
    	vis[i][j] = 1;
    	for(int k=0; k<4; k++)
    	{
    		int x = i + move_x[k];
    		int y = j + move_y[k];
    		if(x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && graph[x][y])
    		{
    			//vis[x][y] = 1;
    			dfs(x, y, n, m, graph);
    		}
    	}
    }*/
};

int main()
{
	Solution sol;
	vector <Point> v;
	v.push_back(Point(0,0));
	v.push_back(Point(0,1));
	v.push_back(Point(2,2));
	v.push_back(Point(2,1));
	sol.numIslands2(3,3,v);
	vector <int> p;
	p = sol.numIslands2(3,3,v);
	for(int i=0; i<p.size(); i++)
		cout << p[i] << endl;
	return 0;
}

