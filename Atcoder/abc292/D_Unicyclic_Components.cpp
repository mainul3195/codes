#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> nodes,vis;
void dfs(int u)
{
    vis[u] = 1;
    nodes.push_back(u);
    for(auto v: adj[u])
        if(!vis[v])
            dfs(v);
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    adj = vector<vector<int>>(n+1);
    vis = vector<int>(n+1, 0);
    nodes.clear();

    for(int i = 1; i<=m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool ok = 1;
    for(int i = 1; i<=n; i++)
    {
        if(!vis[i])
        {
            dfs(i);
            int tot_nod = nodes.size();
            int tot_edge = 0;
            for(auto u: nodes)
                tot_edge += adj[u].size();
            tot_edge/=2;
            if(tot_nod != tot_edge)
            {
                ok = 0;
                break;
            }
            nodes.clear();
        }
    }
    if(ok)
        cout <<"Yes\n";
    else cout << "No\n";
    return 0;

}