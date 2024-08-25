#include <bits/stdc++.h>
using namespace std;
int n, q;
void solve()
{
    cin >> n >> q;
    vector<long long> a(n + 1, 0), b(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    srand(time(0));
    map<int, long long> mp;
    mp[0] = 0;
    for (auto i : a)
        if (mp.find(i) == mp.end())
            mp[i] = ((long long)rand()) * rand();
    for (auto i : b)
        if (mp.find(i) == mp.end())
            mp[i] = ((long long)rand()) * rand();
    for (auto &i : a)
        i = mp[i];
    for (auto &i : b)
        i = mp[i];
    long long mod = (1LL << 61) - 1;
    for (int i = 1; i <= n; i++)
    {
        (a[i] += a[i - 1]) %= mod;
        (b[i] += b[i - 1]) %= mod;
    }
    while (q--)
    {
        int l, r, L, R;
        cin >> l >> r >> L >> R;
        if ((a[r] - a[l - 1] + mod) % mod == (b[R] - b[L - 1] + mod) % mod)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}