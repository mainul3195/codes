#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    sort(v.begin(), v.end());
    map<int, vector<int>> mp;
    for (auto i : v)
        mp[i % k].push_back(i);
    int odd_count = 0;
    for (auto [i, vec] : mp)
        if (vec.size() % 2)
            odd_count++;
    if ((n % 2 == 0 && odd_count) || (n % 2 && odd_count > 1))
    {
        cout << "-1\n";
        return;
    }
    long long ans = 0;
    for (auto [_, vec] : mp)
    {
        if (vec.size() % 2 == 0)
        {
            for (int i = 1; i < vec.size(); i += 2)
                ans += (vec[i] - vec[i - 1]) / k;
        }
        else
        {
            vector<long long> pref(vec.size() + 5, 0), suf(vec.size() + 5, 0);
            for (int i = 1; i < vec.size(); i++)
            {
                if (i & 1)
                    pref[i] = (vec[i] - vec[i - 1]) / k;
                pref[i] += pref[i - 1];
            }
            for (int i = vec.size() - 2; i >= 0; i--)
            {
                if (i & 1)
                    suf[i] = (vec[i + 1] - vec[i]) / k;
                suf[i] += suf[i + 1];
            }
            long long mn = 1000000000000LL;
            for (int i = 0; i < vec.size(); i += 2)
                mn = min(mn, suf[i] + pref[i]);
            ans += mn;
        }
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