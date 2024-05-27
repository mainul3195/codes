#include<bits/stdc++.h>
using namespace std;
int n, a, b;
vector<vector<int>> adj;
vector<int> vis, par;
void dfs1(int u, int l = 1, int p = -1)
{
    par[u] = p;
    int ans = 0;
    for(int v: adj[u])
        if(v!=par[u])
            dfs1(v, l+1, u);
    return;
}
int tot_found, jump;
void dfs2(int u)
{
    // cout << u << " ";
    vis[u] = 1;
    tot_found++;
    for(auto v: adj[u])
        if(!vis[v])
        {
            jump++;
            dfs2(v);
            jump++;
        }
    return;
}
int mx_dis;
int dfs3(int u, int l = 0)
{
    mx_dis = max(mx_dis, l);
    vis[u] = 1;
    for(int v: adj[u])
        if(!vis[v])
            dfs3(v, l+1);
    return mx_dis;
}
void solve()
{
    cin >> n >> a >> b;
    adj = vector<vector<int>>(n+1);
    vis = vector<int>(n+1, 0);
    par = vector<int>(n+1, -1);
    for(int i = 1; i<n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);    
    }
    // for(int i = 1; i<=n; i++)
    //     cout << i <<" -> " << par[i] << "\n";
    //     cout << "\n";
    dfs1(a);
    // for(int i = 1; i<=n; i++)
    //     cout << i << " -> " << par[i] << "\n";

    int cur = b;
    vector<int> path;
    do{
        path.push_back(cur);
        cur = par[cur];
    } while(cur != -1);
    int len = path.size();
    reverse(path.begin(), path.end());
    int ans = (len)/2;
    int start = path[(len-1)/2];
    vis = vector<int>(n+1, 0);
    tot_found = 0, jump = 0;
    dfs2(start);
    // cout << ans << " " << jump << "\n";
    vis = vector<int>(n+1, 0);
    mx_dis = 0;
    cout << ans+jump-dfs3(start) << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}