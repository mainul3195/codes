#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> v;
bool ok(int x)
{
    return v[x].second > v[x + 1].second;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    v = vector<pair<int, int>>(n);
    vector<int> org;
    org.push_back(0);
    int count = 1;
    for (auto &[a, b] : v)
    {
        cin >> a;
        org.push_back(a);
        b = count++;
    }
    v.push_back({0, 0});
    v.push_back({n + 1, n + 1});
    sort(v.begin(), v.end());
    // for (auto [a, b] : v)
    //     cout << a << " " << b << "\n";
    int ans = 1;
    for (int i = 0; i < v.size() - 1; i++)
        if (ok(i))
            ans++;
    set<int> st;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        x = org[x];
        y = org[y];
        st.insert(x - 1);
        st.insert(x);
        st.insert(y - 1);
        st.insert(y);
        for (auto i : st)
            if (ok(i))
                ans--;
        swap(v[x].second, v[y].second);
        org[v[x].second] = v[x].first;
        org[v[y].second] = v[y].first;
        // for (auto [a, b] : v)
        //     cout << setw(2) << a << " ";
        // cout << '\n';
        // for (auto [a, b] : v)
        //     cout << setw(2) << b << " ";
        // cout << "\n";
        for (auto i : st)
            if (ok(i))
                ans++;
        cout << ans << "\n";
        st.clear();
    }
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}