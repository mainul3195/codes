#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> dis1, dis2;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    adj = vector<vector<int>>(n + 1);
    dis1 = dis2 = vector<int>(n + 1, 0);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int> q;
    q.push(1);
    dis1[1] = 1;
    int last;
    while (q.size())
    {
        int u = q.front();
        last = u;
        q.pop();
        for (auto v : adj[u])
            if (!dis1[v])
            {
                dis1[v] = dis1[u] + 1;
                q.push(v);
            }
    }
    q.push(last);
    dis1 = vector<int>(n + 1, 0);
    dis1[last] = 1;
    while (q.size())
    {
        int u = q.front();
        last = u;
        q.pop();
        for (auto v : adj[u])
            if (!dis1[v])
            {
                dis1[v] = dis1[u] + 1;
                q.push(v);
            }
    }
    q.push(last);
    dis2[last] = 1;
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (auto v : adj[u])
            if (!dis2[v])
            {
                dis2[v] = dis2[u] + 1;
                q.push(v);
            }
    }
    for (int i = 1; i <= n; i++)
        cout << max(dis1[i], dis2[i]) - 1 << " ";
    cout << "\n";
    return 0;
}
