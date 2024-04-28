#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, k;
    cin >> n >> k;
    vector<long long> v(n);
    for (auto &i : v)
        cin >> i;
    long long frst = (k + 1) / 2;
    long long lst = k / 2;
    while (v.size() && lst)
    {
        long long last = v.back();
        v.pop_back();
        long long lw = min(last, lst);
        last -= lw;
        lst -= lw;
        if (last)
            v.push_back(last);
    }
    reverse(v.begin(), v.end());
    while (v.size() && frst)
    {
        long long last = v.back();
        v.pop_back();
        long long lw = min(last, frst);
        last -= lw;
        frst -= lw;
        if (last)
            v.push_back(last);
    }
    cout << n - v.size() << "\n";

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