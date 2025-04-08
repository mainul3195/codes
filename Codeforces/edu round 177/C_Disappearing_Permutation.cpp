#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>>adj;
vector<int> vis;
int dfs(int u)
{
    vis[u] = 1;
    int tot = 1;
    for(auto v: adj[u])
        if(!vis[v])
            tot += dfs(v);
    return tot;
}
void solve()
{
    int n;
    cin >> n;
    adj = vector<vector<int>> (n+1);
    vis = vector<int> (n+1, 0);
    for(int i = 1; i<=n; i++)
    {
        int j;
        cin >> j;
        if(i!=j)
            adj[i].push_back(j);
    }
    int ans = 0;
    for(int i = 0; i<n; i++)
    {
        int x;
        cin >> x;
        if(!vis[x])
            ans += dfs(x);
        cout << ans << " ";
    }
    cout << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}