#include <bits/stdc++.h>
using namespace std;
#define int long long
int gcd(int a, int b)
{
    if (!b)
        return a;
    return gcd(b, a % b);
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    sort(v.begin(), v.end());
    if (n == 1)
    {
        if (v[0] == 1)
            cout << "1\n";
        else
            cout << "0\n";
        return;
    }
    int g = 0;
    for (int i = 1; i < n; i++)
        g = gcd(g, v[i] - v[i - 1]);
    if (g == 1)
        cout << "-1\n";
    else if (g == 0)
    {
        if (v[0] == 1)
            cout << "1\n";
        else
            cout << "0\n";
    }
    else
    {
        vector<int> divs;
        divs.push_back(g);
        int lim = sqrt(g + .5);
        for (int i = 2; i <= lim; i++)
            if (g % i == 0)
            {
                divs.push_back(i);
                if (i != g / i)
                    divs.push_back(g / i);
            }
        int mn = 2000000000;
        for (auto i : v)
            mn = min(i, mn);
        int ans = 2000000000;
        for (auto d : divs)
            ans = min(ans, (((mn + d - 1) / d) * d - mn));
        cout << ans << "\n";
    }
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ": ";
        solve();
    }
    return 0;
}