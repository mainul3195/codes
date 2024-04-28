#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        d %= (a + b);
        if (d == 0)
            d = a + b;
        st.insert(d);
    }
    vector<int> v(st.begin(), st.end());
    int mn = 2000000000;
    for (int i = 0; i < v.size(); i++)
    {
        int prev = v[(i - 1 + v.size()) % v.size()];
        prev = (prev - (v[i] - 1) + a + b) % (a + b);
        if (prev == 0)
            prev = a + b;
        mn = min(mn, prev);
    }
    if (mn <= a)
        cout << "Yes\n";
    else
        cout << "No\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}