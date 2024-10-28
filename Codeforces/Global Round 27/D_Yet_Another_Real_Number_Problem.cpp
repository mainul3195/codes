#include <bits/stdc++.h>
using namespace std;
#define Mod 1000000007
long long bigMod(long long b, long long p)
{
    if (!p)
        return 1;
    if (p & 1)
        return (b * bigMod(b, p - 1)) % Mod;
    long long T = bigMod(b, p / 2);
    return (T * T) % Mod;
}
long long modInverse(long long n)
{
    return bigMod(n, Mod - 2);
}
int cmpare(long long v1, long long two1, long long v2, long long two2)
{
    long long mn = min(two1, two2);
    two1 -= mn;
    two2 -= mn;
    if (two1 > 29)
        return 1;
    if (two2 > 29)
        return 2;
    if (v1 * bigMod(2, two1) > v2 * bigMod(2, two2))
        return 1;
    return 2;
}
void solve()
{
    vector<pair<long long, long long>> stck;
    long long sum = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        long long v;
        cin >> v;
        long long two = 0;
        while (v % 2 == 0)
        {
            two++;
            v /= 2;
        }
        while (stck.size() && cmpare(stck.back().first, 0, v, two) == 2)
        {
            two += stck.back().second;
            long long pre = stck.back().first * bigMod(2, stck.back().second) % Mod;
            long long nw = stck.back().first;
            sum = (sum - pre + nw + Mod) % Mod;
            stck.pop_back();
        }
        if (two)
            stck.push_back({v, two});
        sum = (sum + v * bigMod(2, two) % Mod) % Mod;
        cout << sum << " ";
    }
    cout << "\n";
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