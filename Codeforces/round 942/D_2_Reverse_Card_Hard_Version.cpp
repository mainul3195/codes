#include <bits/stdc++.h>
using namespace std;

void solve()
{

    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int cnt = 0;
    vector<pair<int, int>> v;
    for (int a = 1; a <= 100; a++)
        for (int b = 1; b <= 1233; b++)
            if ((b * __gcd(a, b)) % (a + b) == 0)
            {
                cout << (++cnt) << " " << a << " " << b << "\n";
                v.push_back({b, a});
            }
    sort(v.begin(), v.end());
    set<pair<int, int>> st(v.begin(), v.end());
    for (auto [a, b] : st)
        if (st.find({b, a}) != st.end() && (a != b))
            st.erase(st.find({b, a}));
    for (auto [a, b] : st)
        cout << a << " " << b << "\n";
    cout << "-----------\n";
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}