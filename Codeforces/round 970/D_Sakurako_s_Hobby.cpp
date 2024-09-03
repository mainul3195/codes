#include <bits/stdc++.h>
using namespace std;
vector<int> vis, ans, v;
int n, tot;
string s;
void dfs(int u)
{
    if (s[u - 1] == '0')
        tot++;
    vis[u] = 1;
    if (!vis[v[u]])
        dfs(v[u]);
    ans[u] = tot;
}
void solve()
{
    cin >> n;
    v = vector<int>(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    cin >> s;
    vis = ans = vector<int>(n + 1, 0);
    for (int i = 1; i <= n; i++)
        if (!vis[i])
        {
            tot = 0;
            dfs(i);
        }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}