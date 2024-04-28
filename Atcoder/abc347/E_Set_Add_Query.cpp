#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<long long> v(q + 1, 0), c_sum(q + 1, 0), prev_ind(n + 1, -1), ans(n + 1, 0);
    for (int i = 1; i <= q; i++)
        cin >> v[i];
    set<int> st;
    for (int i = 1; i <= q; i++)
    {
        if (st.find(v[i]) == st.end())
            st.insert(v[i]);
        else
            st.erase(v[i]);
        c_sum[i] = st.size();
        c_sum[i] += c_sum[i - 1];
    }
    for (int i = 1; i <= q; i++)
    {
        if (prev_ind[v[i]] == -1)
        {
            prev_ind[v[i]] = i;
            continue;
        }
        ans[v[i]] += c_sum[i - 1] - c_sum[prev_ind[v[i]] - 1];
        prev_ind[v[i]] = -1;
    }
    for (int i = 1; i <= n; i++)
        if (prev_ind[i] != -1)
            ans[i] += c_sum[q] - c_sum[prev_ind[i] - 1];
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}