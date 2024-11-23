#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
vector<long long> h, pos;
bool possible(long long x)
{
    map<int, int> val;
    for (int i = 0; i < n; i++)
    {
        int per_attack = (h[i] + x - 1) / x;
        int shift = m - per_attack;
        if (shift < 0)
            continue;
        val[max(0LL, pos[i] - shift)]++;
        val[pos[i] + shift + 1]--;
    }
    int prev = 0;
    for (auto [i, j] : val)
    {
        prev += j;
        if (prev >= k)
            return true;
    }
    return false;
}
void solve()
{
    cin >> n >> m >> k;
    h = pos = vector<long long>(n);
    for (auto &i : h)
        cin >> i;
    for (auto &i : pos)
        cin >> i;
    long long l = 1, r = 1000000000, mid, ans = -1;
    int count = 50;
    while (l <= r)
    {
        // if (--count == 0)
        //     break;
        // cout << mid << endl;
        mid = (l + r) / 2;
        if (possible(mid))
            r = mid - 1, ans = mid;
        else
            l = mid + 1;
    }
    cout << ans << "\n";
    // cout << possible(14014013) << "\n";
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