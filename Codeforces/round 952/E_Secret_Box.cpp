#include <bits/stdc++.h>
using namespace std;
struct nd
{
    long long a, b, c;
};
void solve()
{
    long long x, y, z, k;
    cin >> x >> y >> z >> k;
    vector<pair<long long, long long>> v;
    for (long long i = 1; i * i <= k; i++)
        if (k % i == 0)
        {
            v.push_back({i, k / i});
            v.push_back({k / i, i});
        }
    vector<nd> fin;
    for (auto [x, y] : v)
    {
        for (long long i = 1; i * i <= y; i++)
            if (y % i == 0)
            {
                fin.push_back({x, i, y / i});
                fin.push_back({x, y / i, i});
            }
    }
    long long mx = 0;
    for (auto [a, b, c] : fin)
    {
        if (a <= x && b <= y && c <= z)
            mx = max(mx, (x - a + 1) * (y - b + 1) * (z - c + 1));
    }
    cout << mx << "\n";
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