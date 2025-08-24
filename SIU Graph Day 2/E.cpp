#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> child;
int dfs(int u = 1, int p = -1)
{
    int tot = 0;
    for (auto v : adj[u])
        if (v != p)
            tot += dfs(v, u);
    return child[u] = tot + 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    adj = vector<vector<int>>(n + 1);
    child = vector<int>(n + 1, 0);
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        adj[x].push_back(i);
    }
    dfs();
    for (int i = 1; i <= n; i++)
        cout << child[i] - 1 << " ";
    cout << "\n";
    return 0;
}