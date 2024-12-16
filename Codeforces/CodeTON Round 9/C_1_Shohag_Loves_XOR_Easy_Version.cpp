#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long x, m;
    cin >> x >> m;
    set<int> st;
    int lim = min(m, 2 * x);
    for (int i = 1; i <= lim; i++)
        if (i != x)
        {
            if (x % i == 0)
            {
                if ((x ^ i) <= m)
                    st.insert(x ^ i);
            }
            int xr = x ^ i;
            if ((xr != x) && (xr % i == 0) && xr <= m)
                st.insert(xr);
        }
    cout << st.size() << "\n";
    // for (auto i : st)
    //     cout << i << " ";
    // cout << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}