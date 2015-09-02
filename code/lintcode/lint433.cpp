// lintcode 433.Number of Islands
// Easy
// dfs °ËÁ¬¿é 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int move_x[] = {-1,1,0,0};
int move_y[] = {0,0,1,-1};
bool vis[1001][1001];

class Solution {
public:
    /**
     * @param grid a boolean 2D matrix
     * @return an integer
     */    
    int n, m;   
    int numIslands(vector<vector<bool> >& grid) {
        // Write your code here    
        int ans = 0;
        n = grid.size();
        if(n == 0)	return 0;
        m = grid[0].size();
        if(m == 0)	return 0;
        memset(vis, 0, sizeof(vis));
        for(int i=0; i<n; i++)
        {
        	for(int j=0; j<m; j++)
        	{
        		if(!vis[i][j] && grid[i][j])
        		{
        			dfs(i, j, grid);
        			ans++;
        		}
        	}
        }
        return ans;
    }
    void dfs(int i, int j, vector<vector<bool> >& grid)
    {
    	vis[i][j] = 1;
    	for(int k=0; k<4; k++)
    	{
    		int x = i + move_x[k];
    		int y = j + move_y[k];
    		if(x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && grid[x][y])
    		{
    			//vis[x][y] = 1;
    			dfs(x, y, grid);
    		}
    	}
    }
};

int main()
{
	
	return 0;
}
