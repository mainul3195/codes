#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<long long> v(n);
    set<long long> st;
    for (auto &i : v)
    {
        cin >> i;
        st.insert(i);
    }
    map<int, long long> mp;
    for (auto &i : st)
        mp[i] = (long long)rand() * rand();
    for (auto &i : v)
        i = mp[i];
    vector<long long> cum_xor(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cum_xor[i] = cum_xor[i - 1] ^ v[i - 1];
    map<long long, int> cnt;
    cnt[0] = 1;
    long long ans = 0;
    for (int i = 1; i <= n; i++)
        ans += i - cnt[cum_xor[i]]++;
    cout << ans << endl;
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    srand(time(0));
    cin >> t;
    while (t--)
        solve();
    return 0;
}