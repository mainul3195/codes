#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<long long> c, ans, sum;
void find_one(int u = 1, int par = -1)
{
    for (auto v : adj[u])
        if (v != par)
        {
            find_one(v, u);
            sum[u] += sum[v];
            ans[u] += 2 * ans[v] + c[v];
        }
}
void find_others(int u, int p)
{
    ans[u] += 2 * (ans[p] - 2 * ans[u] - c[u]) + c[p];
    for (auto v : adj[u])
        if (v != p)
            find_others(v, u);
}
void solve()
{
    int n;
    cin >> n;
    adj = vector<vector<int>>(n + 1, vector<int>());
    c = ans = sum = vector<long long>(n + 1, 0);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    sum = c;
    find_one();
    for (int i = 1; i <= n; i++)
        cout << i << " -> " << ans[i] << "\n";
    for (auto v : adj[1])
        find_others(v, 1);
    cout << "\n";
    for (int i = 1; i <= n; i++)
        cout << i << " -> " << ans[i] << "\n";
    long long mn = 100000000000000000LL;
    for (int i = 1; i <= n; i++)
        mn = min(mn, ans[i]);
    cout << mn << "\n";

    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}