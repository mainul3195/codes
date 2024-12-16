#include <bits/stdc++.h>
using namespace std;
struct nd
{
    int v, ind;
    bool operator<(const nd &a) const
    {
        return v < a.v || (v == a.v && ind < a.ind);
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<nd> a(n), b(n), c(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].v;
        a[i].ind = i;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i].v;
        b[i].ind = i;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> c[i].v;
        c[i].ind = i;
    }
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    sort(c.rbegin(), c.rend());
    int ans = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
            {
                set<int> st{a[i].ind, b[j].ind, c[k].ind};
                if (st.size() == 3)
                    ans = max(ans, a[i].v + b[j].v + c[k].v);
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