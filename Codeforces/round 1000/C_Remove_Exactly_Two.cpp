#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
void solve()
{
    int n;
    cin >> n;
    set<pair<int, int>> st;
    vector<int> degree(n + 1, 0);
    adj = vector<vector<int>>(n + 1, vector<int>());
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        degree[u]++, degree[v]++;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        st.insert({degree[i], i});
    vector<pair<int, int>> All(st.begin(), st.end());
    int ans = 0;
    for (auto [d, u] : All)
    {
        auto it = st.find({d, u});
        st.erase(it);
        for (auto v : adj[u])
        {
            auto it1 = st.find({degree[v], v});
            auto [d1, _] = *it1;
            st.erase(it1);
            st.insert({d1 - 1, v});
            degree[v]--;
        }
        auto it2 = st.end();
        it2--;
        ans = max(degree[u] + degree[(*it2).second] - 1, ans);
        st.insert({d, u});
        for (auto v : adj[u])
        {
            auto it1 = st.find({degree[v], v});
            auto [d1, _] = *it1;
            st.erase(it1);
            st.insert({d1 + 1, v});
            degree[v]++;
        }
    }
    cout << ans << "\n";
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