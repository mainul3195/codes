#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> nodes,vis;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    adj = vector<vector<int>>(n+1);

    for(int i = 1; i<=m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    long long ans = 0;
    for(int i = 1; i<=n; i++)
    {
        vis = vector<int>(n+1, 0);
        vis[i] = 1;
        queue<int> q;
        for(auto v: adj[i])
            q.push(v), vis[v] = 1;
        while(q.size())
        {
            queue<int> tmp;
            while(q.size())
            {
                int u = q.front();
                q.pop();
                for(auto v: adj[u])
                    if(!vis[v])
                        vis[v] = 1, tmp.push(v);
            }
            ans+=tmp.size();
            q = tmp;
        }

    }
    cout << ans << "\n";
    return 0;
}