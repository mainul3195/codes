#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;
    set<long long> st;
    for (auto i : a)
        st.insert(i);
    for (auto i : b)
        st.insert(i);
    map<int, long long> mp;
    srand(time(0));
    for (auto i : st)
    {
        // cout << i << " ";
        mp[i] = (long long)rand() * rand();
    }
    // for (auto [a, b] : mp)
    //     cout << a << " -> " << b << "\n";
    long long mod1 = 1000000007LL, mod2 = 2947294732LL;
    long long sum1 = 0, sum2 = 0;
    vector<pair<long long, long long>> v1, v2;
    map<int, bool> found;
    for (auto i : a)
    {
        if (!found[i])
        {
            found[i] = 1;
            i = mp[i];
            sum1 = (unsigned long long)(sum1 + i) % mod1;
            sum2 = (unsigned long long)(sum2 + i) % mod2;
        }
        v1.push_back({sum1, sum2});
    }
    found.clear();
    sum1 = 0, sum2 = 0;
    for (auto i : b)
    {
        if (!found[i])
        {
            found[i] = 1;
            i = mp[i];
            sum1 = (unsigned long long)(sum1 + i) % mod1;
            sum2 = (unsigned long long)(sum2 + i) % mod2;
        }
        // cout << i << " -> " << sum1 << " " << sum2 << "\n";
        v2.push_back({sum1, sum2});
    }
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        if (v1[l] == v2[r])
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    // for (auto [a, b] : v1)
    //     cout << "( " << a << " , " << b << " )\n";
    // cout << "\n\n";
    // for (auto [a, b] : v2)
    //     cout << "( " << a << " , " << b << " )\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}