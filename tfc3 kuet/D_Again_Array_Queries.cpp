#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        if (r - l > 1000)
            cout << 0 << "\n";
        else
        {
            vector<int> v;
            for (int i = l; i <= r; i++)
                v.push_back(a[i]);
            sort(v.begin(), v.end());
            int dif = 100000;
            for (int i = 1; i < v.size(); i++)
                dif = min(dif, v[i] - v[i - 1]);
            cout << dif << "\n";
        }
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ":\n";
        solve();
    }
    return 0;
}