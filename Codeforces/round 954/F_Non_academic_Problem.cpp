#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> adj;
void solve()
{
    cin >> n >> m;
    adj = vector<vector<int>> (n+1, vector<int> ());
    for(int i = 1; i<=m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
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