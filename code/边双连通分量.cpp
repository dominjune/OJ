// poj 3352.Road Construction
// 边双连通分量 无向图 保证每两个点之间有两条边相连 
// references:
//
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int Max = 1005;
 
int n, m, rt, cnt;
int vis[Max], dfn[Max], low[Max];
vector<int> adj[Max];
 
void dfs(int u, int fa)
{
    vis[u] = 1;
    dfn[u] = low[u] = cnt ++;
    for(int i = 0; i < adj[u].size(); i ++){
        int v = adj[u][i];
        if(vis[v] == 1 && v != fa)
            low[u] = min(low[u], dfn[v]);
        if(vis[v] == 0)
		{
            dfs(v, u);
            low[u] = min(low[u], low[v]);
        }
    }
    vis[u] = 2;
}
 
int main()
{
    int u, v, i;
    while(cin >> n >> m){
        memset(vis, 0, sizeof(vis));
        for(i = 1; i <= n; i ++)
            adj[i].clear();
        while(m --){
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        rt = -1, cnt = 0;
        dfs(1, rt);
        int d[Max], leaf = 0;
        memset(d, 0, sizeof(d));
        for(u = 1; u <= n; u ++)
            for(i = 0; i < adj[u].size(); i ++)
                if(low[u] != low[adj[u][i]])
                    d[low[u]]++;   //  表示第low[u]个连通分量的度数+1。
        for(i = 0; i <= n; i++)
            if(d[i] == 1) leaf ++;
        cout << (leaf+1)/2 << endl;
    }
    return 0;
}
