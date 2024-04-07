#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> child;
vector<long long> sub_ans, main_ans;
int n;
int calc_child(int u = 1, int p = -1)
{
    int tot = 0;
    for (auto v : adj[u])
        if (v != p)
            tot += calc_child(v, u);
    return child[u] = tot + 1;
}
long long calc_sub_ans(int u = 1, int p = -1)
{
    long long tot = 0;
    for (auto v : adj[u])
        if (v != p)
            tot += calc_sub_ans(v, u) + child[v];
    return sub_ans[u] = tot;
}
void calc_main_ans(int u = 1, int p = -1)
{
    for (auto v : adj[u])
        if (v != p)
        {
            main_ans[v] += sub_ans[v] + main_ans[u] - (sub_ans[v] + child[v]) + n - child[v];
            calc_main_ans(v, u);
        }
    return;
}
void solve()
{
    cin >> n;
    adj = vector<vector<int>>(n + 1);
    child = vector<int>(n + 1, 0);
    sub_ans = vector<long long>(n + 1, 0);
    main_ans = vector<long long>(n + 1, 0);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    calc_child();
    calc_sub_ans();
    main_ans[1] = sub_ans[1];
    calc_main_ans();
    for (int i = 1; i <= n; i++)
        cout << main_ans[i] << " ";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}