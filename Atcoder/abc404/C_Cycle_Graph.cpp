#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> adj;
vector<int> vis;
int dfs(int u = 1, int p = -1, int tm = 1)
{
    vis[u] = tm;
    int cnt = 1;
    for(auto v: adj[u])
        if(v!=p)
        {
            if(!vis[v])
                cnt += dfs(v, u, tm+1);
            else 
            {
                if((v!=1 && u!=1) || (u==1 && vis[v]!=n))
                   return -100000000;
            }
        }
    return cnt;
}
void solve()
{
    cin >> n >> m;
    if(n!=m)
    {
        cout << "No\n";
        return;
    }
    adj = vector<vector<int>> (n+1, vector<int>());
    vis = vector<int>(n+1, 0);
    for(int i = 0; i<m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(dfs() == n)
        cout << "Yes\n";
    else cout << "No\n";


    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}