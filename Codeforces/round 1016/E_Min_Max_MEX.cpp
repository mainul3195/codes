#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> v, stck;
set<int> st;
bool possible(int m)
{
    int cut = 0;
    for (int i = 0; i < n; i++)
    {
        if (st.find(v[i]) != st.end())
        {
            stck.push_back(v[i]);
            st.erase(st.find(v[i]));
        }
        if (*(st.begin()) >= m)
        {
            cut++;
            while (stck.size())
            {
                st.insert(stck.back());
                stck.pop_back();
            }
        }
    }
    while (stck.size())
    {
        st.insert(stck.back());
        stck.pop_back();
    }
    return cut >= k;
}
void solve()
{
    cin >> n >> k;
    for (int i = 0; i <= n + 1; i++)
        st.insert(i);
    stck.clear();
    v = vector<int>(n);
    for (auto &i : v)
        cin >> i;
    int l = 0, r = n, m, ans = 0;
    // cout << possible(2) << "\n";
    while (l <= r)
    {
        m = (l + r) / 2;
        if (possible(m))
        {
            ans = m;
            l = m + 1;
        }
        else
            r = m - 1;
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